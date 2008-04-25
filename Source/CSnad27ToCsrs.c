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

			 File Name: $Source: C:/Development/NewCsMap/rcs/CSnad27ToCsrs.c $
			 Full Name:	NAD83 to CSRS Compund Object
		   Description:
			   Purpose:	

		Revision Level:	$Revision: #4 $
				  Date:	$Date: 2006/11/16 $

		 Last Revision:	$Log: CSnad27ToCsrs.c $
		 Last Revision:	Revision 11.1300  2005/05/25 23:27:05  nto
		 Last Revision:	Official Release 11.13
		 Last Revision:	Revision 11.1200  2005/01/15 18:27:08  nto
		 Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		 Last Revision:	Revision 11.1100  2004/11/01 18:53:05  nto
		 Last Revision:	Official release 11.11
		 Last Revision:	Revision 11.1001  2004/10/07 19:25:14  nto
		 Last Revision:	Revision 11.900  2004/03/26 17:02:21  nto
		 Last Revision:	Official release: 11.09 - 3/25/2003
		 Last Revision:	Revision 11.801  2004/03/25 22:05:43  nto
		 Last Revision:	Fixed a reference to strnicmp, no such thing in WinCE.
		 Last Revision:	Revision 11.800  2004/01/13 23:29:09  nto
		 Last Revision:	Revision 11.700  2003/12/19 01:49:49  nto
		 Last Revision:	Official release 11.07
		 Last Revision:	Revision 11.600  2003/12/04 02:46:24  nto
		 Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		 Last Revision:	Revision 11.502  2003/11/24 01:12:10  nto
		 Last Revision:	Correct very remote possibility of addressing fault when errors occur.
		 Last Revision:	Revision 11.501  2003/08/22 21:12:52  nto
		 Last Revision:	Official Release: 11.05
		 Last Revision:	Revision 11.401  2003/05/01 23:06:18  nto
		 Last Revision:	Revision 11.301  2003/04/28 22:43:29  nto
		 Last Revision:	Added the ability to convert NAD27<-->ATS77<-->CSRS ala NbGeoCalc.
		 Last Revision:	Revision 11.300  2003/02/25 04:29:13  nto
		 Last Revision:	Official Release 11.03
		 Last Revision:	Revision 11.100  2002/11/22 19:38:40  nto
		 Last Revision:	Official release: 11.01
		 Last Revision:	Revision 10.1501  2002/11/21 00:41:44  nto
		 Last Revision:	Added the log/source functions for reporting which file got used in datum conversions.
		 Last Revision:	Revision 10.1500  2002/09/22 00:01:16  nto
		 Last Revision:	Official Release:= 10.15
		 Last Revision:	Revision 1.1  2002/09/15 21:24:39  nto
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

struct csNad27ToCsrs_* CSnewNad27ToCsrs (Const char *catalog)
{
	int index;
	Const char *cp;
	struct csNad27ToCsrs_ *__This;
	struct csDatumCatalog_ *catPtr;
	struct csDatumCatalogEntry_ *catEntryPtr;
	struct csNad27ToCsrsEntry_* dtEntryPtr;
	struct csNad27ToCsrsEntry_* findPtr;

	/* Prepare for an error. */
	__This = NULL;
	catPtr = NULL;
	catEntryPtr = NULL;
	dtEntryPtr = NULL;

	__This = (struct csNad27ToCsrs_*) CS_malc (sizeof (struct csNad27ToCsrs_));
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

	/* For each entry in the catalog, we build an appropriate datum
	   shift entry.  Catalog entries must carry path names to each
	   individual file.  We do not play any games with extensions
	   here. */

	index = 0;
	while (TRUE)												/*lint !e716 */
	{
		catEntryPtr = CSgetDatumCatalogEntry (catPtr,index++);
		if (catEntryPtr == NULL) break;
		dtEntryPtr = CSnewNad27ToCsrsEntry (catEntryPtr);
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
	CSdeleteNad27ToCsrs (__This);
	return NULL;
}

/******************************************************************************
	Destructor
*/
void CSdeleteNad27ToCsrs (struct csNad27ToCsrs_* __This)
{
	struct csNad27ToCsrsEntry_ *dtEntryPtr;

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
			CSdeleteNad27ToCsrsEntry (dtEntryPtr);
		}
		CS_free (__This);
	}
	return;
}

/******************************************************************************
	Coverage Locator: Selects the specific grid shift object to use for the
		provided point.  Selection is based on grid denity value.
*/
struct csNad27ToCsrsEntry_* CSselectNad27ToCsrs (struct csNad27ToCsrs_* __This,Const double *ll_nad27)
{
	double testValue;
	double bestSoFar;
	struct csNad27ToCsrsEntry_* dtEntryPtr;
	struct csNad27ToCsrsEntry_* rtnValue;

	rtnValue = NULL;
	bestSoFar = 3600000.00;
	dtEntryPtr = __This->listHead;
	while (dtEntryPtr != NULL)
	{
		testValue = CStestNad27ToCsrsEntry (dtEntryPtr,ll_nad27);
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
void CSfirstNad27ToCsrs (struct csNad27ToCsrs_* __This,struct csNad27ToCsrsEntry_* dtEntryPtr)
{
	struct csNad27ToCsrsEntry_* curPtr;
	struct csNad27ToCsrsEntry_* prvPtr;

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
int CScalcNad27ToCsrs (struct csNad27ToCsrs_* __This,double* ll_csrs,Const double *ll_nad27)
{
	int status;
	struct csNad27ToCsrsEntry_* dtEntryPtr;

	status = 0;

	/* First see if using the cache works.  This works more often than not. */
	if (__This->cachePtr != NULL)
	{
		status = CScalcLLGridCellCache (__This->cachePtr,ll_csrs,ll_nad27);
		if (status == 0)
		{
			return status;
		}
	}

	/* I guess we'll have to do it the hard way. */
	dtEntryPtr = CSselectNad27ToCsrs (__This,ll_nad27);
	if (dtEntryPtr != NULL)
	{
		status = CScalcNad27ToCsrsEntry (dtEntryPtr,ll_csrs,ll_nad27,__This->cachePtr);
	}
	else if (__This->fallback != NULL)
	{
		status = CScalcFallbackForward (__This->fallback,ll_csrs,ll_nad27);
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
int CSinverseNad27ToCsrs (struct csNad27ToCsrs_* __This,double* ll_csrs,Const double *ll_nad27)
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

	guess [LNG] = ll_nad27 [LNG];
	guess [LAT] = ll_nad27 [LAT];
	guess [HGT] = ll_nad27 [HGT];

	/* Start a loop which will iterate up to 10 times. The Canadians and
	   the Aussies max out at 4.  We would duplicate theirs, but since
	   this is an inverse, we'll do a little better than they do. */
	for (ii = 1;ii < itmax;ii++)
	{
		/* Assume we are done until we know different. */
		lng_ok = lat_ok = TRUE;

		/* Compute the NAD83 lat/long for our current guess. */
		status = CScalcNad27ToCsrs (__This,newResult,guess);

		/* If there is no data for this lat/long, we use the fallback
		   in one is available. */
		if (status != 0)
		{
			if (status > 0 && __This->fallback != NULL)
			{
				status = CScalcFallbackInverse (__This->fallback,ll_csrs,ll_nad27);
			}
			return (status);
		}

		/* See how far we are off. */
		epsilon [LNG] = ll_nad27 [LNG] - newResult [LNG];
		epsilon [LAT] = ll_nad27 [LAT] - newResult [LAT];

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
void CSreleaseNad27ToCsrs (struct csNad27ToCsrs_* __This)
{
	struct csNad27ToCsrsEntry_* dtEntryPtr;

	if (__This != NULL)
	{
		if (__This->cachePtr != NULL)
		{
			CSreleaseLLGridCellCache (__This->cachePtr);
		}
		for (dtEntryPtr = __This->listHead;dtEntryPtr != NULL;dtEntryPtr = dtEntryPtr->next)
		{
			CSreleaseNad27ToCsrsEntry (dtEntryPtr);
		}
	}
	return;
}
Const char *CSsourceNad27ToCsrs (struct csNad27ToCsrs_* __This,Const double ll_27 [2])
{
	const char *cp;
	struct csNad27ToCsrsEntry_* dtEntryPtr;

	cp = NULL;
	if (__This->cachePtr != NULL)
	{
		cp = CSsourceLLGridCellCache (__This->cachePtr,ll_27);
	}
	if (cp == NULL)
	{
		dtEntryPtr = CSselectNad27ToCsrs (__This,ll_27);
		if (dtEntryPtr != NULL)
		{
			cp = CSsourceNad27ToCsrsEntry (dtEntryPtr,ll_27);
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
struct csNad27ToCsrsEntry_* CSnewNad27ToCsrsEntry (struct csDatumCatalogEntry_* catPtr)
{
	extern char cs_DirsepC;
	extern struct csNad27ToAts77_* csNad27ToAts77;
	extern struct csAts77ToCsrs_* csAts77ToCsrs;

	int st;
	char *cp;
	struct csNad27ToCsrsEntry_* __This;

	/* Prepare for an error. */
	__This = NULL;

	/* Allocate some storage. */
	__This = (struct csNad27ToCsrsEntry_*) CS_malc (sizeof (struct csNad27ToCsrsEntry_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	__This->next = NULL;
	__This->type = dtNad27ToCsrsNoneYet;
	__This->density = catPtr->density;
	__This->pointers.c2DatumPtr = NULL;

	/* See if this is the special case where conversion required is through the
	   ATS77 facility. */
	cp = strrchr (catPtr->pathName,cs_DirsepC);
	if (cp != NULL) cp += 1;
	else cp = catPtr->pathName;
	if (!CS_strnicmp (cp,"Ats77ToCsrs",11))
	{
		/* Here if we have a Maritime Province reference. */
		__This->pointers.nad27ToCsrsViaXfrm = (struct csNad27ToCsrsXfrm_ *)CS_malc (sizeof (struct csNad27ToCsrsXfrm_));
		if (__This->pointers.nad27ToCsrsViaXfrm == NULL)
		{
			CS_erpt (cs_NO_MEM);
			goto error;
		}
		__This->pointers.nad27ToCsrsViaXfrm->nad27ToAts77 = NULL;
		__This->pointers.nad27ToCsrsViaXfrm->ats77ToCsrs = NULL;
		__This->type = dtNad27ToCsrsXfrm;
		st = CSn27a77Init ();
		if (st == 0)
		{
			__This->pointers.nad27ToCsrsViaXfrm->nad27ToAts77 = csNad27ToAts77;
			if (__This->density == 0.0)
			{
				__This->density = 0.100000;
			}
		}
		else
		{
			 goto error;
		}
		st = CSats77Init ();
		if (st == 0)
		{
			__This->pointers.nad27ToCsrsViaXfrm->ats77ToCsrs = csAts77ToCsrs;
			if (__This->density < 0.00833333333)
			{
				__This->density = 0.098333333333;
			}
		}
		else
		{
			goto error;
		}
	}
	else
	{
		/* Set up the file; construct a Canadian National Transformation,
		   Version 2 object.  It's smart enough to deal with the differences
		   between the Canadian format and the Australian variation. */
		__This->pointers.c2DatumPtr = CSnewDatumShiftCa2 (dtcTypeAustralian,catPtr->pathName,catPtr->bufferSize,catPtr->flags,catPtr->density);
		if (__This->pointers.c2DatumPtr == NULL)
		{
			goto error;
		}
		__This->type = dtNad27ToCsrsC2;
	}
	return __This;

error:
	CSdeleteNad27ToCsrsEntry (__This);
	return NULL;
}
/******************************************************************************
	Destructor, for an "Entry" object.
*/
void CSdeleteNad27ToCsrsEntry (struct csNad27ToCsrsEntry_* __This)
{
	if (__This != NULL)
	{
		switch (__This->type){
		case dtNad27ToCsrsC2:
			CSdeleteDatumShiftCa2 (__This->pointers.c2DatumPtr);
			break;
		case dtNad27ToCsrsXfrm:
			if (__This->pointers.nad27ToCsrsViaXfrm != NULL)
			{
				if (__This->pointers.nad27ToCsrsViaXfrm->nad27ToAts77 != NULL)
				{
					CSn27a77Cls ();
					__This->pointers.nad27ToCsrsViaXfrm->nad27ToAts77 = NULL;
				}
				if (__This->pointers.nad27ToCsrsViaXfrm->ats77ToCsrs != NULL)
				{
					CSats77Cls ();
					__This->pointers.nad27ToCsrsViaXfrm->ats77ToCsrs = NULL;
				}
				CS_free (__This->pointers.nad27ToCsrsViaXfrm);
				__This->pointers.nad27ToCsrsViaXfrm = NULL;
			}
			break;
		case dtNad27ToCsrsNoneYet:
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
void CSreleaseNad27ToCsrsEntry (struct csNad27ToCsrsEntry_* __This)
{
	if (__This != NULL)
	{
		switch (__This->type){
		case dtNad27ToCsrsC2:
			CSreleaseDatumShiftCa2 (__This->pointers.c2DatumPtr);
			break;
		case dtNad27ToCsrsXfrm:
			CSreleaseNad27ToAts77 (__This->pointers.nad27ToCsrsViaXfrm->nad27ToAts77);
			CSreleaseAts77ToCsrs (__This->pointers.nad27ToCsrsViaXfrm->ats77ToCsrs);
			break;
		case dtNad27ToCsrsNoneYet:
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
double CStestNad27ToCsrsEntry (struct csNad27ToCsrsEntry_* __This,Const double* ll_csrs)
{
	extern double cs_Zero;
	
	struct csNad27ToAts77Entry_ *nad27ToAts77Ptr; 
	struct csAts77ToCsrsEntry_ *ats77ToCsrsPtr; 
	double rtnValue = cs_Zero;

	rtnValue = cs_Zero;
	switch (__This->type){
	case dtNad27ToCsrsC2:
		rtnValue = CStestDatumShiftCa2 (__This->pointers.c2DatumPtr,ll_csrs);
		break;
	case dtNad27ToCsrsXfrm:
		nad27ToAts77Ptr = CSselectNad27ToAts77 (__This->pointers.nad27ToCsrsViaXfrm->nad27ToAts77,ats77DirToAts77,ll_csrs);
		if (nad27ToAts77Ptr != NULL)
		{
			ats77ToCsrsPtr = CSselectAts77ToCsrs (__This->pointers.nad27ToCsrsViaXfrm->ats77ToCsrs,ll_csrs);
			if (ats77ToCsrsPtr != NULL)
			{
				rtnValue = __This->density; 
			}
		}
		break;
	case dtNad27ToCsrsNoneYet:
	default:
		rtnValue = cs_Zero;
		break;
	}
	return rtnValue;
}

/******************************************************************************
	Calculation function.  Calculates the conversion from Ats77 to NAD83.
*/
int CScalcNad27ToCsrsEntry (struct csNad27ToCsrsEntry_* __This,double* ll_nad27,Const double *ll_csrs,struct csLLGridCellCache_ *cachePtr)
{
	extern char csErrnam [];

	int status;
	double ll_ats77 [3];

	switch (__This->type) {
	case dtNad27ToCsrsC2:
		status = CScalcDatumShiftCa2 (__This->pointers.c2DatumPtr,ll_nad27,ll_csrs,cachePtr);
		break;
	case dtNad27ToCsrsXfrm:
		status = CScalcNad27ToAts77 (__This->pointers.nad27ToCsrsViaXfrm->nad27ToAts77,ll_ats77,ll_csrs);
		if (status == 0)
		{
			status = CScalcAts77ToCsrs (__This->pointers.nad27ToCsrsViaXfrm->ats77ToCsrs,ll_nad27,ll_ats77);
		}
		break;
	case dtNad27ToCsrsNoneYet:
	default:
		/* Minus one indicates a fatal error.  In this case, it is an internal
		   software error. */
		CS_stncp (csErrnam,"CS_dtNad27ToCsrs:1",MAXPATH);
		CS_erpt (cs_ISER);
		status = -1;
		break;
	}
	return status;
}
/******************************************************************************
	Data source function.  Returns the data source file name.
*/
Const char *CSsourceNad27ToCsrsEntry (struct csNad27ToCsrsEntry_* __This,Const double *ll27)
{
	Const char *cp;

	switch (__This->type) {
	case dtNad27ToCsrsC2:
		cp = CSsourceDatumShiftCa2 (__This->pointers.c2DatumPtr,ll27);
		break;
	case dtNad27ToCsrsXfrm:
		cp = CSsourceNad27ToAts77 (__This->pointers.nad27ToCsrsViaXfrm->nad27ToAts77,ll27);
		break;
	case dtNad27ToCsrsNoneYet:
	default:
		cp = NULL;
		break;
	}
	return cp;
}
