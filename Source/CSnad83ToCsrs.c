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

			 File Name: $Source: C:/Development/NewCsMap/rcs/CSnad83ToCsrs.c $
			 Full Name:	NAD83 to CSRS Compund Object
		   Description:
			   Purpose:	

		Revision Level:	$Revision: #3 $
				  Date:	$Date: 2005/07/26 $

		 Last Revision:	$Log: CSnad83ToCsrs.c $
		 Last Revision:	Revision 11.1300  2005/05/25 23:27:05  nto
		 Last Revision:	Official Release 11.13
		 Last Revision:	Revision 11.1200  2005/01/15 18:27:08  nto
		 Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		 Last Revision:	Revision 11.1100  2004/11/01 18:53:05  nto
		 Last Revision:	Official release 11.11
		 Last Revision:	Revision 11.1001  2004/10/07 19:25:14  nto
		 Last Revision:	Revision 11.900  2004/03/26 17:02:21  nto
		 Last Revision:	Official release: 11.09 - 3/25/2003
		 Last Revision:	Revision 11.800  2004/01/13 23:29:09  nto
		 Last Revision:	Revision 11.700  2003/12/19 01:49:49  nto
		 Last Revision:	Official release 11.07
		 Last Revision:	Revision 11.600  2003/12/04 02:46:25  nto
		 Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		 Last Revision:	Revision 11.502  2003/11/24 01:12:10  nto
		 Last Revision:	Correct very remote possibility of addressing fault when errors occur.
		 Last Revision:	Revision 11.501  2003/08/22 21:12:52  nto
		 Last Revision:	Official Release: 11.05
		 Last Revision:	Revision 11.401  2003/05/01 23:06:19  nto
		 Last Revision:	Revision 11.300  2003/02/25 04:29:13  nto
		 Last Revision:	Official Release 11.03
		 Last Revision:	Revision 11.100  2002/11/22 19:38:40  nto
		 Last Revision:	Official release: 11.01
		 Last Revision:	Revision 10.1501  2002/11/21 00:41:44  nto
		 Last Revision:	Added the log/source functions for reporting which file got used in datum conversions.
		 Last Revision:	Revision 10.1500  2002/09/22 00:01:16  nto
		 Last Revision:	Official Release:= 10.15
		 Last Revision:	Revision 10.1400  2002/08/09 18:14:19  nto
		 Last Revision:	Revision 10.1200  2002/07/14 03:26:11  nto
		 Last Revision:	Revision 10.1100  2002/06/13 14:18:33  nto
		 Last Revision:	Release 10.11 Official
		 Last Revision:	Revision 10.1000  2002/02/23 21:18:24  nto
		 Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		 Last Revision:	Revision 10.900  2001/09/24 04:31:08  nto
		 Last Revision:	Revision 10.701  2001/09/18 19:10:18  nto
		 Last Revision:	Changed dimension of coordinate array to 3 on iterative inverse.
		 Last Revision:	Revision 10.700  2001/01/25 04:13:43  nto
		 Last Revision:	Revision 10.601  2001/01/25 04:06:54  nto
		 Last Revision:	Fixed the error processing when initialization fails.
		 Last Revision:	Revision 10.600  2000/12/11 06:39:37  nto
		 Last Revision:	Release 10.06
		 Last Revision:	Revision 10.500  2000/10/27 07:38:15  nto
		 Last Revision:	Official Release 10.05
		 Last Revision:	Revision 10.401  2000/10/27 03:41:15  nto
		 Last Revision:	Added the datum fallback feature to all datums which
		 Last Revision:	rely on grid data files
		 Last Revision:	Revision 10.400  2000/09/13 01:16:49  nto
		 Last Revision:	Release 10.04
		 Last Revision:	Revision 1.1  2000/07/25 16:45:31  nto
		 Last Revision:	Initial Revision
		       * * * * R E M A R K S * * * *

*****************************************************************************/

#include "cs_map.h"

#ifdef LABEL_MODULE
static char revlvl [] = {"%Id%"};
#endif

/******************************************************************************
	Constructor
*/

struct csNad83ToCsrs_* CSnewNad83ToCsrs (Const char *catalog)
{
	int index;
	Const char *cp;
	struct csNad83ToCsrs_ *__This;
	struct csDatumCatalog_ *catPtr;
	struct csDatumCatalogEntry_ *catEntryPtr;
	struct csNad83ToCsrsEntry_* dtEntryPtr;
	struct csNad83ToCsrsEntry_* findPtr;

	/* Prepare for an error. */
	__This = NULL;
	catPtr = NULL;
	catEntryPtr = NULL;
	dtEntryPtr = NULL;

	__This = (struct csNad83ToCsrs_*) CS_malc (sizeof (struct csNad83ToCsrs_));
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

	/* Activate the fallback method if one is specified. */
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
		dtEntryPtr = CSnewNad83ToCsrsEntry (catEntryPtr);
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
	CSdeleteNad83ToCsrs (__This);
	return NULL;
}

/******************************************************************************
	Destructor
*/
void CSdeleteNad83ToCsrs (struct csNad83ToCsrs_* __This)
{
	struct csNad83ToCsrsEntry_ *dtEntryPtr;

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
			CSdeleteNad83ToCsrsEntry (dtEntryPtr);
		}
		CS_free (__This);
	}
	return;
}

/******************************************************************************
	Coverage Locator: Selects the specific grid shift object to use for the
		provided point.  Selection is based on grid denity value.
*/
struct csNad83ToCsrsEntry_* CSselectNad83ToCsrs (struct csNad83ToCsrs_* __This,Const double *ll_nad83)
{
	double testValue;
	double bestSoFar;
	struct csNad83ToCsrsEntry_* dtEntryPtr;
	struct csNad83ToCsrsEntry_* rtnValue;

	rtnValue = NULL;
	bestSoFar = 3600000.00;
	dtEntryPtr = __This->listHead;
	while (dtEntryPtr != NULL)
	{
		testValue = CStestNad83ToCsrsEntry (dtEntryPtr,ll_nad83);
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
		order of these things the same as they appear in the catalog file.
*/
void CSfirstNad83ToCsrs (struct csNad83ToCsrs_* __This,struct csNad83ToCsrsEntry_* dtEntryPtr)
{
	struct csNad83ToCsrsEntry_* curPtr;
	struct csNad83ToCsrsEntry_* prvPtr;

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
int CScalcNad83ToCsrs (struct csNad83ToCsrs_* __This,double* ll_csrs,Const double *ll_nad83)
{
	int status;
	struct csNad83ToCsrsEntry_* dtEntryPtr;

	status = 0;

	/* First see if using the cache works.  This works more often than not. */
	if (__This->cachePtr != NULL)
	{
		status = CScalcLLGridCellCache (__This->cachePtr,ll_csrs,ll_nad83);
		if (status == 0)
		{
			return status;
		}
	}

	/* I guess we'll have to do it the hard way. */
	dtEntryPtr = CSselectNad83ToCsrs (__This,ll_nad83);
	if (dtEntryPtr != NULL)
	{
		status = CScalcNad83ToCsrsEntry (dtEntryPtr,ll_csrs,ll_nad83,__This->cachePtr);
	}
	else if (__This->fallback != NULL)
	{
		status = CScalcFallbackForward (__This->fallback,ll_csrs,ll_nad83);
	}
	else
	{
		/* We didn't find any coverage.  A positive value is used to indicate
		   an error, but not internally within this code. */
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
int CSinverseNad83ToCsrs (struct csNad83ToCsrs_* __This,double* ll_csrs,Const double *ll_nad83)
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

	guess [LNG] = ll_nad83 [LNG];
	guess [LAT] = ll_nad83 [LAT];
	guess [HGT] = ll_nad83 [HGT];

	/* Start a loop which will iterate up to 10 times. The Canadians and
	   the Aussies max out at 4.  We would duplicate theirs, but since
	   this is an inverse, we'll do a little better than they do. */
	for (ii = 1;ii < itmax;ii++)
	{
		/* Assume we are done until we know different. */
		lng_ok = lat_ok = TRUE;

		/* Compute the NAD83 lat/long for our current guess. */
		status = CScalcNad83ToCsrs (__This,newResult,guess);

		/* If there is no data for this lat/long, we use the fallback
		   in one is available. */
		if (status != 0)
		{
			if (status > 0 && __This->fallback != NULL)
			{
				status = CScalcFallbackInverse (__This->fallback,ll_csrs,ll_nad83);
			}
			return (status);
		}

		/* See how far we are off. */
		epsilon [LNG] = ll_nad83 [LNG] - newResult [LNG];
		epsilon [LAT] = ll_nad83 [LAT] - newResult [LAT];

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

	/* Adjust the ll66 value to the computed value, now that we
	   know that it should be correct. */
	ll_csrs [LNG] = guess [LNG];
	ll_csrs [LAT] = guess [LAT];
	return status;												/*lint !e771 */
}

/******************************************************************************
	Release -- Release resources, but maintain the directory status.
*/
void CSreleaseNad83ToCsrs (struct csNad83ToCsrs_* __This)
{
	struct csNad83ToCsrsEntry_* dtEntryPtr;

	if (__This)
	{
		if (__This->cachePtr != NULL)
		{
			CSreleaseLLGridCellCache (__This->cachePtr);
		}
		for (dtEntryPtr = __This->listHead;dtEntryPtr != NULL;dtEntryPtr = dtEntryPtr->next)
		{
			CSreleaseNad83ToCsrsEntry (dtEntryPtr);
		}
	}
	return;
}
Const char *CSsourceNad83ToCsrs (struct csNad83ToCsrs_* __This,Const double ll_83 [2])
{
	const char *cp;
	struct csNad83ToCsrsEntry_* dtEntryPtr;

	cp = NULL;
	if (__This->cachePtr != NULL)
	{
		cp = CSsourceLLGridCellCache (__This->cachePtr,ll_83);
	}
	if (cp == NULL)
	{
		dtEntryPtr = CSselectNad83ToCsrs (__This,ll_83);
		if (dtEntryPtr != NULL)
		{
			cp = CSsourceNad83ToCsrsEntry (dtEntryPtr,ll_83);
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
struct csNad83ToCsrsEntry_* CSnewNad83ToCsrsEntry (struct csDatumCatalogEntry_* catPtr)
{
	struct csNad83ToCsrsEntry_* __This;

	/* Prepare for an error. */
	__This = NULL;

	/* Allocate some storage. */
	__This = (struct csNad83ToCsrsEntry_*) CS_malc (sizeof (struct csNad83ToCsrsEntry_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	__This->next = NULL;
	__This->type = dtNad83ToCsrsNoneYet;
	__This->pointers.c2DatumPtr = NULL;

	/* Set up the file; construct a Canadian National Transformation,
	   Version 2 object.  It's smart enough to deal with the differences
	   between the Canadian format and the Australian variation. */
	__This->pointers.c2DatumPtr = CSnewDatumShiftCa2 (dtcTypeAustralian,catPtr->pathName,catPtr->bufferSize,catPtr->flags,catPtr->density);
	if (__This->pointers.c2DatumPtr == NULL)
	{
		goto error;
	}
	__This->type = dtNad83ToCsrsC2;
	return __This;

error:
	CSdeleteNad83ToCsrsEntry (__This);
	return NULL;
}

/******************************************************************************
	Destructor, for an "Entry" object.
*/
void CSdeleteNad83ToCsrsEntry (struct csNad83ToCsrsEntry_* __This)
{
	if (__This != NULL)
	{
		switch (__This->type){
		case dtNad83ToCsrsC2:
			CSdeleteDatumShiftCa2 (__This->pointers.c2DatumPtr);
			break;
		case dtNad83ToCsrsNoneYet:
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
void CSreleaseNad83ToCsrsEntry (struct csNad83ToCsrsEntry_* __This)
{
	if (__This != NULL)
	{
		switch (__This->type){
		case dtNad83ToCsrsC2:
			CSreleaseDatumShiftCa2 (__This->pointers.c2DatumPtr);
			break;
		case dtNad83ToCsrsNoneYet:
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
double CStestNad83ToCsrsEntry (struct csNad83ToCsrsEntry_* __This,Const double* ll_csrs)
{
	double rtnValue;

	switch (__This->type){
	case dtNad83ToCsrsC2:
		rtnValue = CStestDatumShiftCa2 (__This->pointers.c2DatumPtr,ll_csrs);
		break;
	case dtNad83ToCsrsNoneYet:
	default:
		rtnValue = 0.0;
		break;
	}
	return rtnValue;
}

/******************************************************************************
	Calculation function.  Calculates the conversion from Ats77 to NAD83.
*/
int CScalcNad83ToCsrsEntry (struct csNad83ToCsrsEntry_* __This,double* ll_nad83,Const double *ll_csrs,struct csLLGridCellCache_ *cachePtr)
{
	extern char csErrnam [];

	int status;

	switch (__This->type){
	case dtNad83ToCsrsC2:
		status = CScalcDatumShiftCa2 (__This->pointers.c2DatumPtr,ll_nad83,ll_csrs,cachePtr);
		break;
	case dtNad83ToCsrsNoneYet:
	default:
		/* Minus one indicates a fatal error.  In this case, it is an internal
		   software error. */
		CS_stncp (csErrnam,"CS_dtNad83ToCsrs:1",MAXPATH);
		CS_erpt (cs_ISER);
		status = -1;
		break;
	}
	return status;
}
/******************************************************************************
	Data source function.  Returns the data source file name.
*/
Const char *CSsourceNad83ToCsrsEntry (struct csNad83ToCsrsEntry_* __This,Const double *ll83)
{
	Const char *cp;

	switch (__This->type) {
	case dtNad83ToCsrsC2:
		cp = CSsourceDatumShiftCa2 (__This->pointers.c2DatumPtr,ll83);
		break;
	case dtNad83ToCsrsNoneYet:
	default:
		cp = NULL;
		break;
	}
	return cp;
}
