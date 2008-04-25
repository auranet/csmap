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

			 File Name: $Source: C:/Development/NewCsMap/rcs/CS_dtNad83ToHarn.c $
			 Full Name:	Nad83 To HARN Compound Object
		   Description:
			   Purpose:	Combines multiple US Datum objects into a
						single object capable of calculating the
						NAD83 to HARN datum shift.

		Revision Level:	$Revision: #3 $
				  Date:	$Date: 2005/07/26 $

		 Last Revision:	$Log: CS_dtNad83ToHarn.c $
		 Last Revision:	Revision 11.1300  2005/05/25 23:27:09  nto
		 Last Revision:	Official Release 11.13
		 Last Revision:	Revision 11.1200  2005/01/15 18:27:10  nto
		 Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		 Last Revision:	Revision 11.1100  2004/11/01 18:53:08  nto
		 Last Revision:	Official release 11.11
		 Last Revision:	Revision 11.1001  2004/10/07 19:25:16  nto
		 Last Revision:	Revision 11.900  2004/03/26 17:02:23  nto
		 Last Revision:	Official release: 11.09 - 3/25/2003
		 Last Revision:	Revision 11.800  2004/01/13 23:29:12  nto
		 Last Revision:	Revision 11.700  2003/12/19 01:49:52  nto
		 Last Revision:	Official release 11.07
		 Last Revision:	Revision 11.600  2003/12/04 02:46:27  nto
		 Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		 Last Revision:	Revision 11.502  2003/11/24 01:12:06  nto
		 Last Revision:	Correct very remote possibility of addressing fault when errors occur.
		 Last Revision:	Revision 11.501  2003/08/22 21:12:54  nto
		 Last Revision:	Official Release: 11.05
		 Last Revision:	Revision 11.401  2003/05/01 23:06:21  nto
		 Last Revision:	Revision 11.300  2003/02/25 04:29:15  nto
		 Last Revision:	Official Release 11.03
		 Last Revision:	Revision 11.100  2002/11/22 19:38:43  nto
		 Last Revision:	Official release: 11.01
		 Last Revision:	Revision 10.1501  2002/11/21 00:41:42  nto
		 Last Revision:	Added the log/source functions for reporting which file got used in datum conversions.
		 Last Revision:	Revision 10.1500  2002/09/22 00:01:19  nto
		 Last Revision:	Official Release:= 10.15
		 Last Revision:	Revision 10.1400  2002/08/09 18:14:21  nto
		 Last Revision:	Revision 10.1200  2002/07/14 03:26:14  nto
		 Last Revision:	Revision 10.1100  2002/06/13 14:18:36  nto
		 Last Revision:	Release 10.11 Official
		 Last Revision:	Revision 10.1000  2002/02/23 21:18:25  nto
		 Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		 Last Revision:	Revision 10.900  2001/09/24 04:31:10  nto
		 Last Revision:	Revision 10.701  2001/09/18 19:18:26  nto
		 Last Revision:	Changed the dimensions of coordinate arrays in the iterative inverse
		 Last Revision:	function from 2 to 3.
		 Last Revision:	Revision 10.700  2001/01/25 04:13:47  nto
		 Last Revision:	Revision 10.600  2000/12/11 06:39:41  nto
		 Last Revision:	Release 10.06
		 Last Revision:	Revision 10.500  2000/10/27 07:38:18  nto
		 Last Revision:	Official Release 10.05
		 Last Revision:	Revision 10.401  2000/10/27 03:41:17  nto
		 Last Revision:	Added the datum fallback feature to all datums which
		 Last Revision:	rely on grid data files
		 Last Revision:	Revision 10.400  2000/09/13 01:16:53  nto
		 Last Revision:	Release 10.04
		 Last Revision:	Revision 10.300  2000/04/04 23:18:24  nto
		 Last Revision:	Revision 10.201  2000/04/03 21:36:03  nto
		 Last Revision:	Modified to keep the order of entries the same as the order in which the files appear in the geodetic catalog data file.
		 Last Revision:	Revision 10.200  2000/03/02 18:51:15  nto
		 Last Revision:	Revision 1.4  2000/02/14 07:01:20  nto
		 Last Revision:	Preserve order of entries so that they always match the order in the catalog file.
		 Last Revision:	Revision 1.3  2000/01/30 23:32:28  nto
		 Last Revision:	Replace stricmp with CS_stricmp.
		 Last Revision:	Revision 1.2  1999/11/03 23:41:05  nto
		 Last Revision:	Results of datum conversion rewrite.

		       * * * * R E M A R K S * * * *

	This object maintains a list of US datum shift objects
	enabling the conversion of geographic coordinates from NAD83
	to HARN (and vice versa).  Thus, NAD83/HARN can be considered
	a single object.

******************************************************************************/

#include "cs_map.h"

#ifdef LABEL_MODULE
static char revlvl [] = {"%W"};
#endif

/******************************************************************************
	Constructor
*/
struct csNad83ToHarn_* CSnewNad83ToHarn (Const char *catalog)
{
	int index;
	Const char *cp;
	struct csNad83ToHarn_ *__This;
	struct csDatumCatalog_ *catPtr;
	struct csDatumCatalogEntry_ *catEntryPtr;
	struct csNad83ToHarnEntry_* dtEntryPtr;
	struct csNad83ToHarnEntry_* findPtr;

	/* Prepare for an error. */
	__This = NULL;
	catPtr = NULL;
	catEntryPtr = NULL;
	dtEntryPtr = NULL;

	__This = (struct csNad83ToHarn_*) CS_malc (sizeof (struct csNad83ToHarn_));
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

	/* Activate the fallback if one was specified. */
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
	   shift entry.  Right now, this is based on file names and
	   file extensions.  Not very good, but that's life. */

	index = 0;
	while (TRUE)												/*lint !e716 */
	{
		catEntryPtr = CSgetDatumCatalogEntry (catPtr,index++);
		if (catEntryPtr == NULL) break;
		dtEntryPtr = CSnewNad83ToHarnEntry (catEntryPtr);
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

	/* It's ready to go. */
	return __This;

error:
	if (catPtr != NULL) CSdeleteDatumCatalog (catPtr);
	CSdeleteNad83ToHarn (__This);
	return NULL;
}

/******************************************************************************
	Destructor
*/
void CSdeleteNad83ToHarn (struct csNad83ToHarn_* __This)
{
	struct csNad83ToHarnEntry_ *dtEntryPtr;

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
			CSdeleteNad83ToHarnEntry (dtEntryPtr);
		}
		CS_free (__This);
	}
	return;
}

/******************************************************************************
	Coverage Locator -- Some of this is overkill in the HARN case as all
	HARN files, currently, have the same density of 15 minutes per cell.
	Also, all HARN files overlap, but the results in all overlap areas
	are, by design, supposed to be the same.  Anyway, we maintain the
	design which enables selecting the specific HARN file with the
	lowest density.
*/
struct csNad83ToHarnEntry_* CSselectNad83ToHarn (struct csNad83ToHarn_* __This,Const double *ll83)
{
	double testValue;
	double bestSoFar;
	struct csNad83ToHarnEntry_* dtEntryPtr;
	struct csNad83ToHarnEntry_* rtnValue;

	rtnValue = NULL;
	bestSoFar = 3600000.00;
	dtEntryPtr = __This->listHead;
	while (dtEntryPtr != NULL)
	{
		testValue = CStestNad83ToHarnEntry (dtEntryPtr,ll83);
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
	Make First -- Used for performance.  Well, used to use it for performance.
	Replaced with the GridCellCache business.  We now want to keep these in
	the same order as they appeared in the data catalog file.
*/
void CSfirstNad83ToHarn (struct csNad83ToHarn_* __This,struct csNad83ToHarnEntry_* dtEntryPtr)
{
	struct csNad83ToHarnEntry_* curPtr;
	struct csNad83ToHarnEntry_* prvPtr;

	/* Take care of the already first situation very quickly. */
	if (dtEntryPtr == __This->listHead) return;

	/* Locate this guy on the list. */
	for (curPtr = __This->listHead,prvPtr = NULL;
		 curPtr != NULL;
		 prvPtr = curPtr,curPtr = curPtr->next)
	{
		if (curPtr == dtEntryPtr)
		{
			/* Make this guy the first one. */
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
int CScalcNad83ToHarn (struct csNad83ToHarn_* __This,double* llHarn,Const double *ll83)
{
	int status;
	struct csNad83ToHarnEntry_* dtEntryPtr;

	status = 0;

	/* First see if using the cache works.  This works frequently. */
	if (__This->cachePtr != NULL)
	{
		status = CScalcLLGridCellCache (__This->cachePtr,llHarn,ll83);
		if (status == 0)
		{
			return status;
		}
	}

	/* Otherwise, we have to do it the hard way. */
	dtEntryPtr = CSselectNad83ToHarn (__This,ll83);
	if (dtEntryPtr != NULL)
	{
		status = CScalcNad83ToHarnEntry (dtEntryPtr,llHarn,ll83,__This->cachePtr);
	}
	else if (__This->fallback != NULL)
	{
		/* No coverage?  Use the fallback alternative is active. */
		status = CScalcFallbackForward (__This->fallback,llHarn,ll83);
	}
	else
	{
		/* We didn't find any coverage.  Use the fall back position.
		   Return a +1 to indicate an approximation. */
		status = 1;
	}
	return status;
}

/******************************************************************************
	Calculate inverse datum shift, the second main man.
	Returns  0 for expected result
	        -1 for hard/fatal failure
			+1 for no data coverage, unshifted result returned
			+2 for no data coverage, fallback used successfully
*/
int CSinverseNad83ToHarn (struct csNad83ToHarn_* __This,double* ll83,Const double *llHarn)
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

	guess [LNG] = llHarn [LNG];
	guess [LAT] = llHarn [LAT];
	guess [HGT] = llHarn [HGT];

	/* Start a loop which will iterate up to 10 times. The Canadians and
	   the Aussies max out at 4.  We would duplicate theirs, but since
	   this is an inverse, we'll do a little better than they do. */
	for (ii = 1;ii < itmax;ii++)
	{
		/* Assume we are done until we know different. */
		lng_ok = lat_ok = TRUE;

		/* Compute the NAD83 lat/long for our current guess. */
		status = CScalcNad83ToHarn (__This,newResult,guess);

		/* If there is no data for this lat/long, we use the fallback
		   in one is available. */
		if (status != 0)
		{
			if (status > 0 && __This->fallback != NULL)
			{
				status = CScalcFallbackInverse (__This->fallback,ll83,llHarn);
			}
			return (status);
		}

		/* See how far we are off. */
		epsilon [LNG] = llHarn [LNG] - newResult [LNG];
		epsilon [LAT] = llHarn [LAT] - newResult [LAT];

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

	/* Adjust the ll83 value to the computed value, now that we
	   know that it should be correct. */
	ll83 [LNG] = guess [LNG];
	ll83 [LAT] = guess [LAT];
	return status;												/*lint !e771 */
}

/******************************************************************************
	Release -- Release resources, but maintain the directory status.
*/
void CSreleaseNad83ToHarn (struct csNad83ToHarn_* __This)
{
	struct csNad83ToHarnEntry_* dtEntryPtr;

	if (__This)
	{
		for (dtEntryPtr = __This->listHead;dtEntryPtr != NULL;dtEntryPtr = dtEntryPtr->next)
		{
			CSreleaseNad83ToHarnEntry (dtEntryPtr);
		}
	}
	return;
}
Const char *CSsourceNad83ToHarn (struct csNad83ToHarn_* __This,Const double ll_83 [2])
{
	const char *cp;
	struct csNad83ToHarnEntry_* dtEntryPtr;

	cp = NULL;
	if (__This->cachePtr != NULL)
	{
		cp = CSsourceLLGridCellCache (__This->cachePtr,ll_83);
	}
	if (cp == NULL)
	{
		dtEntryPtr = CSselectNad83ToHarn (__This,ll_83);
		if (dtEntryPtr != NULL)
		{
			cp = CSsourceNad83ToHarnEntry (dtEntryPtr,ll_83);
		}
	}
	if (cp == NULL && __This->fallback != NULL)
	{
		cp = CSsourceFallback (__This->fallback);
	}
	return cp;
}
/******************************************************************************
	Constructor for a Nad83ToHarnEntry object
*/
struct csNad83ToHarnEntry_* CSnewNad83ToHarnEntry (struct csDatumCatalogEntry_* catPtr)
{
	extern char cs_DirsepC;
	extern char cs_ExtsepC;
	extern char csErrnam [];

	char *cp;
	struct csNad83ToHarnEntry_* __This;

	/* Prepare for an error. */
	__This = NULL;

	/* Allocate some storage. */
	__This = (struct csNad83ToHarnEntry_*) CS_malc (sizeof (struct csNad83ToHarnEntry_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	__This->next = NULL;
	__This->harnDatumPtr = NULL;

	/* Issue an error if this is not an HPGN guy. This will eliminate a lot
	   of frustration. */
	cp = strrchr (catPtr->pathName,cs_DirsepC);
	if (cp == NULL)
	{
		/* Is not supposed to happen, but we can't allow a bomb. */
		CS_stncp (csErrnam,catPtr->pathName,MAXPATH);
		CS_erpt (cs_DTC_PATH);
		goto error;
	}
	if (CS_stristr (cp,"HPGN") == NULL)
	{
		/* Report an NAD2787 in the HARN catalog. */
		CS_erpt (cs_HPGN_NAD);
		goto error;
	}

	/* Isolate the extension on the file. */
	cp = strrchr (catPtr->pathName,cs_ExtsepC);
	if (cp == NULL)
	{
		/* Is not supposed to happen. */
		CS_stncp (csErrnam,catPtr->pathName,MAXPATH);
		CS_erpt (cs_NAD_EXT);
		goto error;
	}
	cp += 1;

	/* Report special erros concerning the extensions.  Again, specific
	   error messages will reduce frustration. */
	if (!CS_stricmp (cp,"LAS"))
	{
		CS_erpt (cs_HPGN_EXTA);
		goto error;
	}
	if (!CS_stricmp (cp,"LOS"))
	{
		CS_erpt (cs_HPGN_EXTO);
		goto error;
	}
	if (CS_stricmp (cp,"L?S"))
	{
		CS_erpt (cs_HPGN_EXTX);
		goto error;
	}

	/* OK, the file name stuff appears OK.  We use the csDatumShiftUS object, as
	   all of the rest of this stuff is the same as NAD27 <--> NAD83. */
	__This->harnDatumPtr = CSnewDatumShiftUS (dtcTypeHarn,catPtr->pathName,catPtr->bufferSize,catPtr->flags,catPtr->density);
	if (__This->harnDatumPtr == NULL)
	{
		goto error;
	}
	return __This;
error:
	CSdeleteNad83ToHarnEntry (__This);
	return NULL;
}

/******************************************************************************
	Destructor for a Nad83ToHarnEntry object
*/
void CSdeleteNad83ToHarnEntry (struct csNad83ToHarnEntry_* __This)
{
	if (__This != NULL)
	{
		CSdeleteDatumShiftUS (__This->harnDatumPtr);
		CS_free (__This);
	}
	return;
}

/******************************************************************************
	Release resources for a Nad83ToHarnEntry object
*/
void CSreleaseNad83ToHarnEntry (struct csNad83ToHarnEntry_* __This)
{
	if (__This != NULL)
	{
		CSreleaseDatumShiftUS (__This->harnDatumPtr);
	}
	return;
}

/******************************************************************************
	Using grid density, locate the specific entry which is to be used for a
	specific point.
*/
double CStestNad83ToHarnEntry (struct csNad83ToHarnEntry_* __This,Const double* ll83)
{
	double rtnValue;

	rtnValue = CStestDatumShiftUS (__This->harnDatumPtr,ll83);
	return rtnValue;
}

/******************************************************************************
	Perform the actual calculation, once the specific "Entry" has been
	selected.  (Inverse is calculated at the main object level).
*/
int CScalcNad83ToHarnEntry (struct csNad83ToHarnEntry_* __This,double* llHarn,Const double *ll83,struct csLLGridCellCache_ *cachePtr)
{
	int status;

	status = CScalcDatumShiftUS (__This->harnDatumPtr,llHarn,ll83,cachePtr);
	return status;
}
/******************************************************************************
	Data source function.  Returns the data source file name.
*/
Const char *CSsourceNad83ToHarnEntry (struct csNad83ToHarnEntry_* __This,Const double *ll83)
{
	Const char *cp;

	cp = NULL;
	if (__This->harnDatumPtr != NULL)
	{
		cp = CSsourceDatumShiftUS (__This->harnDatumPtr,ll83);
	}
	return cp;
}
