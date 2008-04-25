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

			 File Name: $Source: C:/Development/NewCsMap/rcs/CS_dtAts77ToNad83.c $
			 Full Name:	ATS77 to NAD83 Compund Object
		   Description:
			   Purpose:	Combines multiple Autralian datum shift
						data files into a single object so that the
						ATS77 to NAD83 conversion looks like a single
						object.

		Revision Level:	$Revision: #3 $
				  Date:	$Date: 2005/07/26 $

		 Last Revision:	$Log: CS_dtAts77ToNad83.c $
		 Last Revision:	Revision 11.1300  2005/05/25 23:27:09  nto
		 Last Revision:	Official Release 11.13
		 Last Revision:	Revision 11.1200  2005/01/15 18:27:10  nto
		 Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		 Last Revision:	Revision 11.1100  2004/11/01 18:53:07  nto
		 Last Revision:	Official release 11.11
		 Last Revision:	Revision 11.1001  2004/10/07 19:25:16  nto
		 Last Revision:	Revision 11.900  2004/03/26 17:02:23  nto
		 Last Revision:	Official release: 11.09 - 3/25/2003
		 Last Revision:	Revision 11.800  2004/01/13 23:29:11  nto
		 Last Revision:	Revision 11.700  2003/12/19 01:49:51  nto
		 Last Revision:	Official release 11.07
		 Last Revision:	Revision 11.600  2003/12/04 02:46:26  nto
		 Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		 Last Revision:	Revision 11.501  2003/08/22 21:12:54  nto
		 Last Revision:	Official Release: 11.05
		 Last Revision:	Revision 11.401  2003/05/01 23:06:20  nto
		 Last Revision:	Revision 11.301  2003/04/28 22:45:09  nto
		 Last Revision:	Modified to handle Release of  a NULL pointer without crashing.
		 Last Revision:	Revision 11.300  2003/02/25 04:29:15  nto
		 Last Revision:	Official Release 11.03
		 Last Revision:	Revision 11.100  2002/11/22 19:38:42  nto
		 Last Revision:	Official release: 11.01
		 Last Revision:	Revision 10.1501  2002/11/21 00:41:41  nto
		 Last Revision:	Added the log/source functions for reporting which file got used in datum conversions.
		 Last Revision:	Revision 10.1500  2002/09/22 00:01:18  nto
		 Last Revision:	Official Release:= 10.15
		 Last Revision:	Revision 10.1400  2002/08/09 18:14:21  nto
		 Last Revision:	Revision 10.1200  2002/07/14 03:26:14  nto
		 Last Revision:	Revision 10.1100  2002/06/13 14:18:36  nto
		 Last Revision:	Release 10.11 Official
		 Last Revision:	Revision 10.1000  2002/02/23 21:18:25  nto
		 Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		 Last Revision:	Revision 10.900  2001/09/24 04:31:09  nto
		 Last Revision:	Revision 10.701  2001/09/18 19:14:45  nto
		 Last Revision:	Changed the dimensions of coordinate arrays in the iterative inverse
		 Last Revision:	function from 2 to 3.
		 Last Revision:	Revision 10.700  2001/01/25 04:13:46  nto
		 Last Revision:	Revision 10.600  2000/12/11 06:39:40  nto
		 Last Revision:	Release 10.06
		 Last Revision:	Revision 10.500  2000/10/27 07:38:18  nto
		 Last Revision:	Official Release 10.05
		 Last Revision:	Revision 10.401  2000/10/27 03:41:16  nto
		 Last Revision:	Added the datum fallback feature to all datums which
		 Last Revision:	rely on grid data files
		 Last Revision:	Revision 10.400  2000/09/13 01:16:52  nto
		 Last Revision:	Release 10.04
		 Last Revision:	Revision 10.300  2000/04/04 23:18:23  nto
		 Last Revision:	Revision 10.201  2000/04/03 21:35:18  nto
		 Last Revision:	Modifed to be Ats77ToCsrs.  Note, the name of the source module should be changed.  We'll do that on next release.
		 Last Revision:	Revision 10.200  2000/03/02 18:51:15  nto
		 Last Revision:	Revision 1.3  2000/02/14 07:01:20  nto
		 Last Revision:	Preserve order of entries so that they always match the order in the catalog file.
		 Last Revision:	Revision 1.2  2000/02/11 06:01:32  nto
		 Last Revision:	Untested as yet.  It compils properly.
		 Last Revision:	Revision 1.1  2000/02/09 03:07:31  nto
		 Last Revision:	Initial Revision
		 Last Revision:	Revision 1.1  2000/02/09 03:05:59  nto
		 Last Revision:	Initial Revision

		       * * * * R E M A R K S * * * *

	The source module is misnamed, and might change in future releases.
	The module should be named "CS_dtAts77ToCsrs.c".

	This object maintains a list of various datum shift objects
	enabling the conversion of geographic coordinates from ATS77
	to CSRS (and vice versa).  Thus, ATS77 can be considered a
	single object.

	There is only one file, at the current time, but for consistency
	we use the "multi-file" technique.  This also provides for maximum
	user control of the conversion.

*****************************************************************************/

#include "cs_map.h"

#ifdef LABEL_MODULE
static char revlvl [] = {"%Id%"};
#endif

/******************************************************************************
	Constructor
*/
struct csAts77ToCsrs_* CSnewAts77ToCsrs (Const char *catalog)
{
	int index;
	Const char *cp;
	struct csAts77ToCsrs_ *__This;
	struct csDatumCatalog_ *catPtr;
	struct csDatumCatalogEntry_ *catEntryPtr;
	struct csAts77ToCsrsEntry_* dtEntryPtr;
	struct csAts77ToCsrsEntry_* findPtr;

	/* Prepare for an error. */
	__This = NULL;
	catPtr = NULL;
	catEntryPtr = NULL;
	dtEntryPtr = NULL;

	__This = (struct csAts77ToCsrs_*) CS_malc (sizeof (struct csAts77ToCsrs_));
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

	/* If a fallback was specified, activate it. */
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
		dtEntryPtr = CSnewAts77ToCsrsEntry (catEntryPtr);
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
	CSdeleteAts77ToCsrs (__This);
	return NULL;
}

/******************************************************************************
	Destructor
*/
void CSdeleteAts77ToCsrs (struct csAts77ToCsrs_* __This)
{
	struct csAts77ToCsrsEntry_ *dtEntryPtr;

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
			CSdeleteAts77ToCsrsEntry (dtEntryPtr);
		}
		CS_free (__This);
	}
	return;
}

/******************************************************************************
	Coverage Locator: Selects the specific grid shift object to use for the
		provided point.  Selection is based on grid denity value.
*/
struct csAts77ToCsrsEntry_* CSselectAts77ToCsrs (struct csAts77ToCsrs_* __This,Const double *ll_ats77)
{
	double testValue;
	double bestSoFar;
	struct csAts77ToCsrsEntry_* dtEntryPtr;
	struct csAts77ToCsrsEntry_* rtnValue;

	rtnValue = NULL;
	bestSoFar = 3600000.00;
	dtEntryPtr = __This->listHead;
	while (dtEntryPtr != NULL)
	{
		testValue = CStestAts77ToCsrsEntry (dtEntryPtr,ll_ats77);
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
void CSfirstAts77ToCsrs (struct csAts77ToCsrs_* __This,struct csAts77ToCsrsEntry_* dtEntryPtr)
{
	struct csAts77ToCsrsEntry_* curPtr;
	struct csAts77ToCsrsEntry_* prvPtr;

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
int CScalcAts77ToCsrs (struct csAts77ToCsrs_* __This,double* ll_csrs,Const double *ll_ats77)
{
	int status;
	struct csAts77ToCsrsEntry_* dtEntryPtr;

	status = 0;

	/* First see if using the cache works.  This works more often than not. */
	if (__This->cachePtr != NULL)
	{
		status = CScalcLLGridCellCache (__This->cachePtr,ll_csrs,ll_ats77);
		if (status == 0)
		{
			return status;
		}
	}

	/* I guess we'll have to do it the hard way. */
	dtEntryPtr = CSselectAts77ToCsrs (__This,ll_ats77);
	if (dtEntryPtr != NULL)
	{
		status = CScalcAts77ToCsrsEntry (dtEntryPtr,ll_csrs,ll_ats77,__This->cachePtr);
	}
	else if (__This->fallback != NULL)
	{
		/* Use the fallback definition if there is no coverage. */
		status = CScalcFallbackForward (__This->fallback,ll_csrs,ll_ats77);
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
int CSinverseAts77ToCsrs (struct csAts77ToCsrs_* __This,double* ll_ats77,Const double *ll_csrs)
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

	guess [LNG] = ll_csrs [LNG];
	guess [LAT] = ll_csrs [LAT];
	guess [HGT] = ll_csrs [HGT];

	/* Start a loop which will iterate up to 10 times. The Canadians and
	   the Aussies max out at 4.  We would duplicate theirs, but since
	   this is an inverse, we'll do a little better than they do. */
	for (ii = 1;ii < itmax;ii++)
	{
		/* Assume we are done until we know different. */
		lng_ok = lat_ok = TRUE;

		/* Compute the NAD83 lat/long for our current guess. */
		status = CScalcAts77ToCsrs (__This,newResult,guess);

		/* If there is no data for this lat/long, we use the fallback
		   in one is available. */
		if (status != 0)
		{
			if (status > 0 && __This->fallback != NULL)
			{
				status = CScalcFallbackInverse (__This->fallback,ll_ats77,ll_csrs);
			}
			return (status);
		}

		/* See how far we are off. */
		epsilon [LNG] = ll_csrs [LNG] - newResult [LNG];
		epsilon [LAT] = ll_csrs [LAT] - newResult [LAT];

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
	ll_ats77 [LNG] = guess [LNG];
	ll_ats77 [LAT] = guess [LAT];
	return status;												/*lint !e771 */
}

/******************************************************************************
	Release -- Release resources, but maintain the directory status.
*/
void CSreleaseAts77ToCsrs (struct csAts77ToCsrs_* __This)
{
	struct csAts77ToCsrsEntry_* dtEntryPtr;

	if (__This != NULL)
	{
		if (__This->cachePtr != NULL)
		{
			CSreleaseLLGridCellCache (__This->cachePtr);
		}
		for (dtEntryPtr = __This->listHead;dtEntryPtr != NULL;dtEntryPtr = dtEntryPtr->next)
		{
			CSreleaseAts77ToCsrsEntry (dtEntryPtr);
		}
	}
	return;
}
Const char *CSsourceAts77ToCsrs (struct csAts77ToCsrs_* __This,Const double ll_77 [2])
{
	const char *cp;
	struct csAts77ToCsrsEntry_* dtEntryPtr;

	cp = NULL;
	if (__This->cachePtr != NULL)
	{
		cp = CSsourceLLGridCellCache (__This->cachePtr,ll_77);
	}
	if (cp == NULL)
	{
		dtEntryPtr = CSselectAts77ToCsrs (__This,ll_77);
		if (dtEntryPtr != NULL)
		{
			cp = CSsourceAts77ToCsrsEntry (dtEntryPtr,ll_77);
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
struct csAts77ToCsrsEntry_* CSnewAts77ToCsrsEntry (struct csDatumCatalogEntry_* catPtr)
{
	struct csAts77ToCsrsEntry_* __This;

	/* Prepare for an error. */
	__This = NULL;

	/* Allocate some storage. */
	__This = (struct csAts77ToCsrsEntry_*) CS_malc (sizeof (struct csAts77ToCsrsEntry_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	__This->next = NULL;
	__This->type = dtAts77ToCsrsNoneYet;
	__This->pointers.c2DatumPtr = NULL;

	/* Set up the file; construct a Canadian National Transformation,
	   Version 2 object.  It's smart enough to deal with the differences
	   between the Canadian format and the Australian variation. */
	__This->pointers.c2DatumPtr = CSnewDatumShiftCa2 (dtcTypeAustralian,catPtr->pathName,catPtr->bufferSize,catPtr->flags,catPtr->density);
	if (__This->pointers.c2DatumPtr == NULL)
	{
		goto error;
	}
	__This->type = dtAts77ToCsrsC2;
	return __This;

error:
	CSdeleteAts77ToCsrsEntry (__This);
	return NULL;
}

/******************************************************************************
	Destructor, for an "Entry" object.
*/
void CSdeleteAts77ToCsrsEntry (struct csAts77ToCsrsEntry_* __This)
{
	if (__This != NULL)
	{
		switch (__This->type){
		case dtAts77ToCsrsC2:
			CSdeleteDatumShiftCa2 (__This->pointers.c2DatumPtr);
			break;
		case dtAts77ToCsrsNoneYet:
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
void CSreleaseAts77ToCsrsEntry (struct csAts77ToCsrsEntry_* __This)
{
	if (__This != NULL)
	{
		switch (__This->type){
		case dtAts77ToCsrsC2:
			CSreleaseDatumShiftCa2 (__This->pointers.c2DatumPtr);
			break;
		case dtAts77ToCsrsNoneYet:
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
double CStestAts77ToCsrsEntry (struct csAts77ToCsrsEntry_* __This,Const double* ll_ats77)
{
	double rtnValue;

	switch (__This->type){
	case dtAts77ToCsrsC2:
		rtnValue = CStestDatumShiftCa2 (__This->pointers.c2DatumPtr,ll_ats77);
		break;
	case dtAts77ToCsrsNoneYet:
	default:
		rtnValue = 0.0;
		break;
	}
	return rtnValue;
}

/******************************************************************************
	Calculation function.  Calculates the conversion from Ats77 to NAD83.
*/
int CScalcAts77ToCsrsEntry (struct csAts77ToCsrsEntry_* __This,double* ll_csrs,Const double *ll_ats77,struct csLLGridCellCache_ *cachePtr)
{
	extern char csErrnam [];

	int status;

	switch (__This->type){
	case dtAts77ToCsrsC2:
		status = CScalcDatumShiftCa2 (__This->pointers.c2DatumPtr,ll_csrs,ll_ats77,cachePtr);
		break;
	case dtAts77ToCsrsNoneYet:
	default:
		/* Minus one indicates a fatal error.  In this case, it is an internal
		   software error. */
		CS_stncp (csErrnam,"CS_dtAts77ToCsrs:1",MAXPATH);
		CS_erpt (cs_ISER);
		status = -1;
		break;
	}
	return status;
}
/******************************************************************************
	Data source function.  Returns the data source file name.
*/
Const char *CSsourceAts77ToCsrsEntry (struct csAts77ToCsrsEntry_* __This,Const double *ll77)
{
	Const char *cp;

	switch (__This->type) {
	case dtAts77ToCsrsC2:
		cp = CSsourceDatumShiftCa2 (__This->pointers.c2DatumPtr,ll77);
		break;
	case  dtAts77ToCsrsNoneYet:
	default:
		cp = NULL;
		break;
	}
	return cp;
}
