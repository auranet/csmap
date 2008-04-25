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

			 File Name: $Source: C:/Development/NewCsMap/rcs/cs_dtTokyoToJgd2k.c $
			 Full Name:	
		   Description:
			   Purpose:	Provides for a common access point to all
						Japan Geodetic Datum of 2000 grid shift
						files.

		Revision Level:	$Revision: #1 $
				  Date:	$Date: 2006/11/21 $

		 Last Revision:	$Log: cs_dtTokyoToJgd2k.c $
		 Last Revision:	Revision 11.1300  2005/05/25 23:27:10  nto
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
		 Last Revision:	Revision 11.501  2003/08/22 21:12:55  nto
		 Last Revision:	Official Release: 11.05
		 Last Revision:	Revision 11.401  2003/05/01 23:06:21  nto
		 Last Revision:	Revision 11.300  2003/02/25 04:29:15  nto
		 Last Revision:	Official Release 11.03
		 Last Revision:	Revision 11.100  2002/11/22 19:38:43  nto
		 Last Revision:	Official release: 11.01
		 Last Revision:	Revision 10.1501  2002/11/21 20:23:00  nto
		 Last Revision:	Lint cleanup, added Japanese to dt type enumerator.
		 Last Revision:	Revision 10.1500  2002/09/22 00:01:19  nto
		 Last Revision:	Official Release:= 10.15
		 Last Revision:	Revision 10.1400  2002/08/09 18:14:21  nto
		 Last Revision:	Revision 10.1200  2002/07/14 03:26:14  nto
		 Last Revision:	Revision 10.1100  2002/06/13 14:18:36  nto
		 Last Revision:	Release 10.11 Official
		 Last Revision:	Revision 10.1000  2002/02/23 21:18:25  nto
		 Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		 Last Revision:	Revision 1.1  2002/02/19 05:18:08  nto
		 Last Revision:	Initial Revision

		       * * * * R E M A R K S * * * *

*****************************************************************************/

#include "cs_map.h"

#ifdef LABEL_MODULE
static char revlvl [] = {"%W"};
#endif

/******************************************************************************
	Constructor
*/
struct csTokyoToJgd2k_ *CSnewTokyoToJgd2k (Const char *catalog)
{
	int index;
	Const char *cp;
	struct csTokyoToJgd2k_ *__This;
	struct csDatumCatalog_ *catPtr;
	struct csDatumCatalogEntry_ *catEntryPtr;
	struct csTokyoToJgd2kEntry_* dtEntryPtr;
	struct csTokyoToJgd2kEntry_* findPtr;

	/* Prepare for an error. */
	__This = NULL;
	catPtr = NULL;
	catEntryPtr = NULL;
	dtEntryPtr = NULL;

	__This = (struct csTokyoToJgd2k_*) CS_malc (sizeof (struct csTokyoToJgd2k_));
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

	/* Activate the fallback is such was specified. */
	cp = CSgetFallbackName (catPtr);
	if (cp != NULL && *cp != '\0')
	{
		/* Set name of catalog file in case of error. */
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
		dtEntryPtr = CSnewTokyoToJgd2kEntry (catEntryPtr);
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

	/* Having done that successfully, allocate a grid cell cache.  If this
	   fails, we can either report it as an error, or just leave it alone.
	   Lets report it as an error. */
	__This->cachePtr = CSnewLLGridCellCache (32);
	if (__This->cachePtr == NULL)
	{
		goto error;
	}

	/* It's ready to go. */
	return __This;
error:
	if (catPtr != NULL) CSdeleteDatumCatalog (catPtr);
	CSdeleteTokyoToJgd2k (__This);
	return NULL;
}
/******************************************************************************
	Destructor
*/
void CSdeleteTokyoToJgd2k (struct csTokyoToJgd2k_* __This)
{
	struct csTokyoToJgd2kEntry_ *dtEntryPtr;

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
			CSdeleteTokyoToJgd2kEntry (dtEntryPtr);
		}
		CS_free (__This);
	}
	return;
}
/******************************************************************************
	Release -- Release resources, but maintain the 'catalog' status.  Leave
	the fallback alone, as the only way to get that back is to open up the
	catalog file again.
*/
void CSreleaseTokyoToJgd2k (struct csTokyoToJgd2k_* __This)
{
	struct csTokyoToJgd2kEntry_* dtEntryPtr;

	if (__This != NULL)
	{
		if (__This->cachePtr != NULL)
		{
			CSreleaseLLGridCellCache (__This->cachePtr);
		}
		for (dtEntryPtr = __This->listHead;dtEntryPtr != NULL;dtEntryPtr = dtEntryPtr->next)
		{
			CSreleaseTokyoToJgd2kEntry (dtEntryPtr);
		}
	}
	return;
}
/******************************************************************************
	Calculate datum shift, the main man.
	Returns  0 for expected result
	        -1 for hard/fatal failure
			+1 for no data coverage, unshifted result returned
			+2 for no data coverage, fallback used successfully
*/
int CScalcTokyoToJgd2k (struct csTokyoToJgd2k_* __This,double* llJgd2k,Const double *llTokyo)
{
	int status, st;
	struct csTokyoToJgd2kEntry_* dtEntryPtr;

	/* First see if using the cache works.  This works frequently. */
	if (__This->cachePtr != NULL)
	{
		status = CScalcLLGridCellCache (__This->cachePtr,llJgd2k,llTokyo);
		if (status == 0)
		{
			return status;
		}
	}

	/* Do the default in case none of the stuff below works. */
	llJgd2k [LNG] = llTokyo [LNG];
	llJgd2k [LAT] = llTokyo [LAT];
	status = 1;

	/* OK, we have to do it the hard way. */
	dtEntryPtr = __This->listHead;
	while (dtEntryPtr != NULL)
	{	
		st = CScalcTokyoToJgd2kEntry (dtEntryPtr,llJgd2k,llTokyo,__This->cachePtr);
		if (st < 0) status = st;
		else if (st == 0)
		{
			/* We found an entry which can effectively convert this point.
			   Save the new status value and terminate the loop.
			   CScalcTokyoToJgd2kEntry will have added this cell to the cache. */
			status = st;
			break;
		}

		/* Try the next entry listed in the catalog. */
		dtEntryPtr = dtEntryPtr->next;
	}
	if (status == 1)
	{
		/* We didn't any coverage.  Do the fallback if one has been specified. */
		if (__This->fallback != NULL)
		{
			status = CScalcFallbackForward (__This->fallback,llJgd2k,llTokyo);
		}
	}
	return status;
}
/******************************************************************************
	Calculate inverse datum shift, the second main man.  Note that this is a
		deviation from using the exact code used by the governmental products.
		The different government supplied programs use the same algorithm, but
		with slightly different implementation details.  Here we use the same
		details for all objects.

	Returns  0 for expected result
	        -1 for hard/fatal failure
			+1 for no data coverage, unshifted result returned
			+2 for no data coverage, fallback used successfully
*/
int CSinverseTokyoToJgd2k (struct csTokyoToJgd2k_* __This,double* llTokyo,Const double *llJgd2k)
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

	guess [LNG] = llJgd2k [LNG];
	guess [LAT] = llJgd2k [LAT];
	guess [HGT] = llJgd2k [HGT];

	/* Start a loop which will iterate up to 10 times. The Canadians and
	   the Aussies max out at 4.  We would duplicate theirs, but since
	   this is an inverse, we'll do a little better than they do. */
	for (ii = 1;ii < itmax;ii++)
	{
		/* Assume we are done until we know different. */
		lng_ok = lat_ok = TRUE;

		/* Compute the NAD83 lat/long for our current guess. */
		status = CScalcTokyoToJgd2k (__This,newResult,guess);

		/* If there is no data for this lat/long, we use the fallback
		   if one is available. */
		if (status != 0)
		{
			if (status > 0 && __This->fallback != NULL)
			{
				status = CScalcFallbackInverse (__This->fallback,llTokyo,llJgd2k);
			}
			return status;
		}

		/* See how far we are off. */
		epsilon [LNG] = llJgd2k [LNG] - newResult [LNG];
		epsilon [LAT] = llJgd2k [LAT] - newResult [LAT];

		/* If our guess at the longitude is off by more than 'small', we adjust
		 our guess by the amount we are off. */
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

	if (ii >= itmax)
	{
		CS_erpt (cs_TOKYO_ICNT);
		return (-1);
	}

	/* Adjust the ll_27 value to the computed value, now that we
	   know that it should be correct. */
	llTokyo [LNG] = guess [LNG];
	llTokyo [LAT] = guess [LAT];
	return status;												/*lint !e771 */
}
/******************************************************************************
	Constructor: This is a constructor for the "Entry" object.  A linked list
	of these "Entry" objects is underlying structure of the main object.

	NOTE: the specific of handling different file types are handled here.
*/
struct csTokyoToJgd2kEntry_* CSnewTokyoToJgd2kEntry (struct csDatumCatalogEntry_* catPtr)
{
	extern char cs_ExtsepC;
	extern char csErrnam [];

	char *cp;
	struct csTokyoToJgd2kEntry_* __This;

	/* Prepare for an error. */
	__This = NULL;

	/* ALlocate some storage. */
	__This = (struct csTokyoToJgd2kEntry_*) CS_malc (sizeof (struct csTokyoToJgd2kEntry_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	__This->next = NULL;
	__This->jgd2kPtr = NULL;

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

	/* Do what's appropriate for this extension. */
	if (!CS_stricmp (cp,"par"))
	{
		__This->jgd2kPtr = CSnewJgd2kGridFile (catPtr->pathName,catPtr->bufferSize,catPtr->flags,catPtr->density);
		if (__This->jgd2kPtr == NULL)
		{
			goto error;
		}
	}
	else
	{
		CS_erpt (cs_TOKYO_EXT);
		goto error;
	}
	return __This;
error:
	CSdeleteTokyoToJgd2kEntry (__This);
	return NULL;
}
/******************************************************************************
	Destructor, for an "Entry" object.
*/
void CSdeleteTokyoToJgd2kEntry (struct csTokyoToJgd2kEntry_* __This)
{
	if (__This != NULL)
	{
		CSdeleteJgd2kGridFile (__This->jgd2kPtr);
		CS_free (__This);
	}
	return;
}
/******************************************************************************
	Release resources, for an "Entry" object.
*/
void CSreleaseTokyoToJgd2kEntry (struct csTokyoToJgd2kEntry_* __This)
{
	if (__This != NULL)
	{
		CSreleaseJgd2kGridFile (__This->jgd2kPtr);
	}
	return;
}
/******************************************************************************
	Calculation function.  Calculates the conversion from NAD27 to NAD83.
*/
int CScalcTokyoToJgd2kEntry (struct csTokyoToJgd2kEntry_* __This,double* llJgd2k,Const double *llTokyo,struct csLLGridCellCache_ *cachePtr)
{
	int status;

	status = CScalcJgd2kGridFile (__This->jgd2kPtr,llJgd2k,llTokyo);
	if (status == 0 && cachePtr != NULL)
	{
		CSaddLLGridCellCache (cachePtr,dtcTypeJapanese,&__This->jgd2kPtr->lngCell,&__This->jgd2kPtr->latCell);
	}
	else if (status > 0)
	{
		llJgd2k [LNG] = llTokyo [LNG];
		llJgd2k [LAT] = llTokyo [LAT];
	}
	return status;
}
