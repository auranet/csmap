/******************************************************************************

	*********************************************************************
	*********************************************************************
	**                                                                 **
	**          Copyright (c) 1997 Mentor Software, Inc.               **
	**                    All Rights Reserved                          **
	**                                                                 **
	** The software and information contained herein are proprietary   **
	** to, and comprise valuable trade secrets of, Mentor Software,    **
	** Inc., which intends to preserve as trade secrets such software  **
	** and information.  This software is furnished pursuant to a      **
	** written license agreement and may be used, copied, transmitted, **
	** and stored only in accordance with the terms of such license    **
	** and with the inclusion of the above copyright notice.  This     **
	** software and information or any other copies thereof may not    **
	** be provided or otherwise made available to any other person.    **
	** Failure to honor the terms of the written license agreement     **
	** could be cause for legal action against you and/or your         **
	** company.                                                        **
	**                                                                 **
	** Notwithstanding any other lease or license that may pertain to, **
	** or accompany the delivery of, this computer software and        **
	** information, the rights of the Government regarding its use,    **
	** reproduction and disclosure are as set forth in Section         **
	** 52.227-19 of the FARS Computer Software-Restricted Rights       **
	** clause.                                                         **
	**                                                                 **
	** Use, duplication, or disclosure by the Government is subject    **
	** to restrictions as set forth in subparagraph (c)(1)(ii) of the  **
	** Rights in Technical Data and Computer Software clause at DFARS  **
	** 252.227-7013. Contractor/Manufacturer is Mentor Software, Inc., **
	** 3907 East 120th Avenue, Suite 200, Thornton, CO  80233.         **
	**                                                                 **
	*********************************************************************  
	*********************************************************************  

			 File Name: $Source$
			 Full Name:	DHDN to ETRF89 Compound Object
		   Description:
			   Purpose:	Combines multiple grid shift files so that an
						DHDN to ETRF89 conversion looks like a single
						object.

		Revision Level:	$Revision$
				  Date:	$Date$

		 Last Revision:	$Log$

		       * * * * R E M A R K S * * * *

*****************************************************************************/

#include "cs_map.h"

#ifdef LABEL_MODULE
static char revlvl [] = {"%W"};
#endif

/******************************************************************************
	Constructor
*/
struct csDhdnToEtrf89_* CSnewDhdnToEtrf89 (Const char *catalog)
{
	int index;
	Const char *cp;
	struct csDhdnToEtrf89_ *__This;
	struct csDatumCatalog_ *catPtr;
	struct csDatumCatalogEntry_ *catEntryPtr;
	struct csDhdnToEtrf89Entry_* dtEntryPtr;
	struct csDhdnToEtrf89Entry_* findPtr;

	/* Prepare for an error. */
	__This = NULL;
	catPtr = NULL;
	catEntryPtr = NULL;
	dtEntryPtr = NULL;

	__This = (struct csDhdnToEtrf89_*) CS_malc (sizeof (struct csDhdnToEtrf89_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	__This->fallback = NULL;
	__This->cachePtr = NULL;
	__This->listHead = NULL;

	/* Open the catalog file. */
	catPtr = CSnewDatumCatalog (catalog);
	if (catPtr == NULL) goto error;

	/* Get a pointer to the fallback definition.  This will be NULL if there
	   is none. */
	cp = CSgetFallbackName (catPtr);
	if (cp != NULL && *cp != '\0')
	{
		__This->fallback = CSnewFallback (cp,catalog);
		if (__This->fallback == NULL)
		{
			goto error;
		}
	}

	/* For each entry in the catalong, we build an appropriate datum
	   shift entry.  Catalog entries must carry path names to each individual
	   file.  We do not play any games with extensions here. */

	index = 0;
	while (TRUE)												/*lint !e716 */
	{
		catEntryPtr = CSgetDatumCatalogEntry (catPtr,index++);
		if (catEntryPtr == NULL) break;
		dtEntryPtr = CSnewDhdnToEtrf89Entry (catEntryPtr);
		if (dtEntryPtr == NULL)
		{
			goto error;
		}
		/* Keep the list in the same order as they appear in the file. */
		if (__This->listHead == NULL)
		{
			__This->listHead = dtEntryPtr;
		}
		else
		{
			for (findPtr = __This->listHead;findPtr->next != NULL;findPtr = findPtr->next);
			findPtr->next = dtEntryPtr;
		}
	}
	CSdeleteDatumCatalog (catPtr);
	catPtr = NULL;

	/* Having done that successfully, allocate a grid cell cache.  If
	   this fails, we can either report it as an error, or just leave it
	   alone.  Lets report it as an error. */
	__This->cachePtr = CSnewLLGridCellCache (32);
	if (__This->cachePtr == NULL)
	{
		goto error;
	}

	/* OK, it's ready to go. */
	return __This;

error:
	if (catPtr != NULL) CSdeleteDatumCatalog (catPtr);
	CSdeleteDhdnToEtrf89 (__This);
	return NULL;
}

/******************************************************************************
	Destructor
*/
void CSdeleteDhdnToEtrf89 (struct csDhdnToEtrf89_* __This)
{
	struct csDhdnToEtrf89Entry_ *dtEntryPtr;

	if (__This != NULL)
	{
		if (__This->fallback != NULL)
		{
			CSdeleteFallback (__This->fallback);
			__This->fallback = NULL;
		}
		if (__This->cachePtr != NULL)
		{
			CSdeleteLLGridCellCache (__This->cachePtr);
			__This->cachePtr = NULL;
		}
		while (__This->listHead != NULL)
		{
			dtEntryPtr = __This->listHead;
			__This->listHead = __This->listHead->next;
			CSdeleteDhdnToEtrf89Entry (dtEntryPtr);
		}
		CS_free (__This);
	}
	return;
}

/******************************************************************************
	Coverage Locator: Selects the specific grid shift object to use for the
		provided point.  Selection is based on grid denity value.
*/
struct csDhdnToEtrf89Entry_* CSselectDhdnToEtrf89 (struct csDhdnToEtrf89_* __This,Const double *ll50)
{
	double testValue;
	double bestSoFar;
	struct csDhdnToEtrf89Entry_* dtEntryPtr;
	struct csDhdnToEtrf89Entry_* rtnValue;

	rtnValue = NULL;
	bestSoFar = 3600000.00;
	dtEntryPtr = __This->listHead;
	while (dtEntryPtr != NULL)
	{
		testValue = CStestDhdnToEtrf89Entry (dtEntryPtr,ll50);
		if (testValue != 0.0 && testValue < bestSoFar)
		{
			bestSoFar = testValue;
			rtnValue = dtEntryPtr;
		}
		dtEntryPtr = dtEntryPtr->next;
	}
	return rtnValue;
}

/******************************************************************************
	Make First: Makes provided entry first on the linked list. Used for
		performance.  Well used to use it for performance.  This has been
		replaced with the GridCellCache business.  We now want to keep the
		order of these things the same as they appear in the catalog file,
		so this is never used, should not be used.  Probably should be
		deleted.
*/
void CSfirstDhdnToEtrf89 (struct csDhdnToEtrf89_* __This,struct csDhdnToEtrf89Entry_* dtEntryPtr)
{
	struct csDhdnToEtrf89Entry_* curPtr;
	struct csDhdnToEtrf89Entry_* prvPtr;

	/* Take care of the already first situation very quickly. */
	if (dtEntryPtr == __This->listHead) return;

	/* Locate this guy on the list. */
	for (curPtr = __This->listHead,prvPtr = NULL;
		 curPtr != NULL;
		 prvPtr = curPtr,curPtr = curPtr->next)
	{
		if (curPtr == dtEntryPtr)
		{
			prvPtr->next = curPtr->next;						/*lint !e613 */
			curPtr->next = __This->listHead;
			__This->listHead = curPtr;
			break;
		}
	}
}

/******************************************************************************
	Calculate datum shift, the main man.
	Returns  0 for expected result
	        -1 for hard/fatal failure
			+1 for no data coverage, unshifted result returned
			+2 for no data coverage, fallback used successfully
*/
int CScalcDhdnToEtrf89 (struct csDhdnToEtrf89_* __This,double* ll89,Const double *ll50)
{
	int status;
	struct csDhdnToEtrf89Entry_* dtEntryPtr;

	status = 0;

	/* First see if using the cache works.  This works more often than not. */
	if (__This->cachePtr != NULL)
	{
		status = CScalcLLGridCellCache (__This->cachePtr,ll89,ll50);
		if (status == 0)
		{
			return status;
		}
	}

	/* I guess we'll have to do it the hard way. */
	dtEntryPtr = CSselectDhdnToEtrf89 (__This,ll50);
	if (dtEntryPtr != NULL)
	{
		status = CScalcDhdnToEtrf89Entry (dtEntryPtr,ll89,ll50,__This->cachePtr);
	}
	else if (__This->fallback != NULL)
	{
		/* We didn't find any coverage.  A positive value is used to indicate
		   that we're using the fallback to do this calculation. */
		status = CScalcFallbackForward (__This->fallback,ll89,ll50);
	}
	else
	{
		status = 1;
	}
	return status;
}
/******************************************************************************
	Calculate inverse datum shift, the second main man.  Note that this is a
		deviation from using the exact code used by the governmental products.
		The different government supplied programs use the same algorothm, but
		with slightly different implementation details.  Here we use the same
		details for all objects.

	Returns  0 for expected result
	        -1 for hard/fatal failure
			+1 for no data coverage, unshifted result returned
			+2 for no data coverage, fallback used successfully
*/
int CSinverseDhdnToEtrf89 (struct csDhdnToEtrf89_* __This,double* ll50,Const double *ll89)
{
	static int itmax = 10;
	static double small = 1.0E-9;		/* this is degrees */

	short lng_ok;
	short lat_ok;
	int ii;
	int status;

	double guess [3];
	double epsilon [2];
	double newResult [3];

	guess [LNG] = ll89 [LNG];
	guess [LAT] = ll89 [LAT];
	guess [HGT] = ll89 [HGT];

	/* Start a loop which will iterate up to 10 times. The Canadians and
	   the Aussies max out at 4.  We would duplicate theirs, but since
	   this is an inverse, we'll do a little better than they do. */
	for (ii = 1;ii < itmax;ii++)
	{
		/* Assume we are done until we know different. */
		lng_ok = lat_ok = TRUE;

		/* Compute the GDA94 lat/long for our current guess. */
		status = CScalcDhdnToEtrf89 (__This,newResult,guess);

		/* If there is no data for this lat/long, we use the fallback
		   in one is available. */
		if (status != 0)
		{
			if (status > 0 && __This->fallback != NULL)
			{
				status = CScalcFallbackInverse (__This->fallback,ll50,ll89);
			}
			return (status);
		}

		/* See how far we are off. */
		epsilon [LNG] = ll89 [LNG] - newResult [LNG];
		epsilon [LAT] = ll89 [LAT] - newResult [LAT];

		/* If our guess at the longitude is off by more than
		   small, we adjust our guess by the amount we are off. */
		if (fabs (epsilon [LNG]) > small)
		{
			lng_ok = FALSE;
			guess [LNG] += epsilon [LNG];
		}
		if (fabs (epsilon [LAT]) > small)
		{
			lat_ok = FALSE;
			guess [LAT] += epsilon [LAT];
		}

		/* If our current guess produces a newResult that is within
		   small of original, we are done. */
		if (lng_ok && lat_ok) break;
	}

	/* If we didn't resolve in four tries, we issue a warning
	   message.  Casual reading of the NADCON code would lead one
	   to believe that they do five iterations, but four is all
	   they really do. */
	if (ii >= itmax)
	{
		CS_erpt (cs_NADCON_ICNT);
		return (1);
	}

	/* Adjust the ll50 value to the computed value, now that we
	   know that it should be correct. */
	ll50 [LNG] = guess [LNG];
	ll50 [LAT] = guess [LAT];
	return status;												/*lint !e771 */
}

/******************************************************************************
	Release -- Release resources, but maintain the directory status.
*/
void CSreleaseDhdnToEtrf89 (struct csDhdnToEtrf89_* __This)
{
	struct csDhdnToEtrf89Entry_* dtEntryPtr;

	if (__This != NULL)
	{
		if (__This->cachePtr != NULL)
		{
			CSreleaseLLGridCellCache (__This->cachePtr);
		}
		for (dtEntryPtr = __This->listHead;dtEntryPtr != NULL;dtEntryPtr = dtEntryPtr->next)
		{
			CSreleaseDhdnToEtrf89Entry (dtEntryPtr);
		}
	}
	return;
}
Const char *CSsourceDhdnToEtrf89 (struct csDhdnToEtrf89_* __This,Const double ll_50 [2])
{
	const char *cp;
	struct csDhdnToEtrf89Entry_* dtEntryPtr;

	cp = NULL;
	if (__This->cachePtr != NULL)
	{
		cp = CSsourceLLGridCellCache (__This->cachePtr,ll_50);
	}
	if (cp == NULL)
	{
		dtEntryPtr = CSselectDhdnToEtrf89 (__This,ll_50);
		if (dtEntryPtr != NULL)
		{
			cp = CSsourceDhdnToEtrf89Entry (dtEntryPtr,ll_50);
		}
	}
	if (cp == NULL && __This->fallback != NULL)
	{
		cp = CSsourceFallback (__This->fallback);
	}
	return cp;
}
/******************************************************************************
	Constructor: This is a constructor for the "Entry" object.  A linked list
	of these "Entry" objects is underlying structure of the main object.

	NOTE: the specific of handling different file types are handled here.
*/
struct csDhdnToEtrf89Entry_* CSnewDhdnToEtrf89Entry (struct csDatumCatalogEntry_* catPtr)
{
	struct csDhdnToEtrf89Entry_* __This;

	/* Prepare for an error. */
	__This = NULL;

	/* Allocate some storage. */
	__This = (struct csDhdnToEtrf89Entry_*) CS_malc (sizeof (struct csDhdnToEtrf89Entry_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	__This->next = NULL;
	__This->type = dtDhdnToEtrf89NoneYet;
	__This->pointers.c2DatumPtr = NULL;

	/* Set up the file; construct a Canadian National Transformation,
	   Version 2 object.  It's smart enough to deal with the differences
	   between the Canadian format and the Australian variation. */
	__This->pointers.c2DatumPtr = CSnewDatumShiftCa2 (dtcTypeAustralian,catPtr->pathName,catPtr->bufferSize,catPtr->flags,catPtr->density);
	if (__This->pointers.c2DatumPtr == NULL)
	{
		goto error;
	}
	__This->type = dtDhdnToEtrf89C2;
	return __This;

error:
	CSdeleteDhdnToEtrf89Entry (__This);
	return NULL;
}

/******************************************************************************
	Destructor, for an "Entry" object.
*/
void CSdeleteDhdnToEtrf89Entry (struct csDhdnToEtrf89Entry_* __This)
{
	if (__This != NULL)
	{
		switch (__This->type){
		case dtDhdnToEtrf89C2:
			CSdeleteDatumShiftCa2 (__This->pointers.c2DatumPtr);
			break;
		case dtDhdnToEtrf89NoneYet:
		default:
			break;
		}
		CS_free (__This);
	}
	return;
}

/******************************************************************************
	Release resources, for an "Entry" object.
*/
void CSreleaseDhdnToEtrf89Entry (struct csDhdnToEtrf89Entry_* __This)
{
	if (__This != NULL)
	{
		switch (__This->type){
		case dtDhdnToEtrf89C2:
			CSreleaseDatumShiftCa2 (__This->pointers.c2DatumPtr);
			break;
		case dtDhdnToEtrf89NoneYet:
		default:
			break;
		}
	}
	return;
}

/******************************************************************************
	Test function.  Used to locate the specific "Entry" item in the main object
	linked list which is the best entry to use for converting the supplied
	point.
*/
double CStestDhdnToEtrf89Entry (struct csDhdnToEtrf89Entry_* __This,Const double* ll50)
{
	double rtnValue;

	switch (__This->type){
	case dtDhdnToEtrf89C2:
		rtnValue = CStestDatumShiftCa2 (__This->pointers.c2DatumPtr,ll50);
		break;
	case dtDhdnToEtrf89NoneYet:
	default:
		rtnValue = 0.0;
		break;
	}
	return rtnValue;
}

/******************************************************************************
	Calculation function.  Calculates the conversion from AGD66 to GDA94.
*/
int CScalcDhdnToEtrf89Entry (struct csDhdnToEtrf89Entry_* __This,double* ll89,Const double *ll50,struct csLLGridCellCache_ *cachePtr)
{
	extern char csErrnam [];

	int status;

	switch (__This->type){
	case dtDhdnToEtrf89C2:
		status = CScalcDatumShiftCa2 (__This->pointers.c2DatumPtr,ll89,ll50,cachePtr);
		break;
	case dtDhdnToEtrf89NoneYet:
	default:
		/* Minus one indicates a fatal error.  In this case, it is an internal
		   software error. */
		CS_stncp (csErrnam,"CS_dtDhdnToEtrf89:1",MAXPATH);
		CS_erpt (cs_ISER);
		status = -1;
		break;
	}
	return status;
}
/******************************************************************************
	Data source function.  Returns the data source file name.
*/
Const char *CSsourceDhdnToEtrf89Entry (struct csDhdnToEtrf89Entry_* __This,Const double *ll27)
{
	Const char *cp;

	switch (__This->type) {
	case dtDhdnToEtrf89C2:
		cp = CSsourceDatumShiftCa2 (__This->pointers.c2DatumPtr,ll27);
		break;
	case dtDhdnToEtrf89NoneYet:
	default:
		cp = NULL;
		break;
	}
	return cp;
}
