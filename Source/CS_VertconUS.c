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

			 File Name: $Source: C:/Development/NewCsMap/rcs/CS_VertconUS.c $
			 Full Name:	Vertcon US Compund Object
		   Description:
			   Purpose:	Combines multiple US Grid Files into a
						single object capable of calculating the
						elevation shift from NADV29 to NADV88.

		Revision Level:	$Revision: #1 $
				  Date:	$Date: 2006/11/21 $

		 Last Revision:	$Log: CS_VertconUS.c $
		 Last Revision:	Revision 11.1300  2005/05/25 23:27:20  nto
		 Last Revision:	Official Release 11.13
		 Last Revision:	Revision 11.1200  2005/01/15 18:27:17  nto
		 Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		 Last Revision:	Revision 11.1100  2004/11/01 18:53:15  nto
		 Last Revision:	Official release 11.11
		 Last Revision:	Revision 11.1001  2004/10/07 19:25:22  nto
		 Last Revision:	Revision 11.900  2004/03/26 17:02:29  nto
		 Last Revision:	Official release: 11.09 - 3/25/2003
		 Last Revision:	Revision 11.800  2004/01/13 23:29:18  nto
		 Last Revision:	Revision 11.700  2003/12/19 01:49:58  nto
		 Last Revision:	Official release 11.07
		 Last Revision:	Revision 11.600  2003/12/04 02:46:33  nto
		 Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		 Last Revision:	Revision 11.502  2003/11/24 01:12:09  nto
		 Last Revision:	Correct very remote possibility of addressing fault when errors occur.
		 Last Revision:	Revision 11.501  2003/08/22 21:13:00  nto
		 Last Revision:	Official Release: 11.05
		 Last Revision:	Revision 11.401  2003/05/01 23:06:26  nto
		 Last Revision:	Revision 11.300  2003/02/25 04:29:21  nto
		 Last Revision:	Official Release 11.03
		 Last Revision:	Revision 11.100  2002/11/22 19:38:48  nto
		 Last Revision:	Official release: 11.01
		 Last Revision:	Revision 10.1500  2002/09/22 00:01:25  nto
		 Last Revision:	Official Release:= 10.15
		 Last Revision:	Revision 10.1400  2002/08/09 18:14:26  nto
		 Last Revision:	Revision 10.1200  2002/06/20 18:00:32  nto
		 Last Revision:	Official release: 10.12
		 Last Revision:	Revision 10.1100  2002/06/13 14:18:45  nto
		 Last Revision:	Release 10.11 Official
		 Last Revision:	Revision 10.1000  2002/02/23 21:18:30  nto
		 Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		 Last Revision:	Revision 10.900  2001/09/24 04:31:14  nto
		 Last Revision:	Revision 10.700  2001/01/25 04:13:56  nto
		 Last Revision:	Revision 10.600  2000/12/11 06:39:50  nto
		 Last Revision:	Release 10.06
		 Last Revision:	Revision 10.500  2000/10/27 07:38:32  nto
		 Last Revision:	Official Release 10.05
		 Last Revision:	Revision 10.400  2000/09/13 01:17:02  nto
		 Last Revision:	Release 10.04
		 Last Revision:	Revision 10.300  2000/04/04 23:18:33  nto
		 Last Revision:	Revision 10.201  2000/04/03 21:43:17  nto
		 Last Revision:	Modified to maintain the order of entries to be the same as the files appear in the geodetic data catalog file.
		 Last Revision:	Revision 10.200  2000/03/02 18:51:24  nto
		 Last Revision:	Revision 1.4  2000/02/14 07:04:53  nto
		 Last Revision:	Modified to preserve the order of entries as they appear in the catalog file.
		 Last Revision:	Revision 1.3  2000/01/31 00:10:46  nto
		 Last Revision:	FIxed many problems, added the cell cache, moved the millimeter adjustement, and some PCLint clean up.
		 Last Revision:	Revision 1.2  1999/11/03 23:41:08  nto
		 Last Revision:	Results of datum conversion rewrite.

		       * * * * R E M A R K S * * * *

	This object maintains a list of csGridFileUS objects which
	contain the difference in orthometric height in the form of
	NADV88 - NADV29, in meters.  Thus, the conversion of the
	Z coordinate from one to the other consists of a single
	object.

******************************************************************************/

#include "cs_map.h"

#ifdef LABEL_MODULE
static char revlvl [] = {"%W"};
#endif

/******************************************************************************
        Constructor
*/
struct csVertconUS_* CSnewVertconUS (Const char *catalog)
{
	int index;
	struct csVertconUS_ *__This;
	struct csDatumCatalog_ *catPtr;
	struct csDatumCatalogEntry_ *catEntryPtr;
	struct csVertconUSEntry_* vcEntryPtr;
	struct csVertconUSEntry_* findPtr;

	/* Prepare for an error. */
	__This = NULL;
	catPtr = NULL;
	catEntryPtr = NULL;
	vcEntryPtr = NULL;

	__This = (struct csVertconUS_*) CS_malc (sizeof (struct csVertconUS_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	__This->cachePtr = NULL;
	__This->listHead = NULL;

	/* Open the catalog file. */
	catPtr = CSnewDatumCatalog (catalog);
	if (catPtr == NULL) goto error;

	/* For each entry in the catalog, we build an appropriate geoid height
	   grid file entry.  Right now, this is based on file names and file
	   extensions.  Not very good, but that's life. */

	index = 0;
	while (TRUE)												/*lint !e716 */
	{
		catEntryPtr = CSgetDatumCatalogEntry (catPtr,index++);
		if (catEntryPtr == NULL) break;
		vcEntryPtr = CSnewVertconUSEntry (catEntryPtr);
		if (vcEntryPtr == NULL)
		{
			goto error;
		}
		/* Keep the list in the same order as they appear in the file. */
		if (__This->listHead == NULL)
		{
			__This->listHead = vcEntryPtr;
		}
		else
		{
			for (findPtr = __This->listHead;findPtr->next != NULL;findPtr = findPtr->next);
			findPtr->next = vcEntryPtr;
		}
	}
	CSdeleteDatumCatalog (catPtr);
	catPtr = NULL;

	/* Having done that successfully, allocate a grid cell cache.  If
	   this fails, we can either report it as an error, or just leave it
	   alone.  Lets report it as an error. */
	__This->cachePtr = CSnewZGridCellCache (32);
	if (__This->cachePtr == NULL)
	{
		goto error;
	}

	/* OK, we ;re done. */
	return __This;
error:
	if (catPtr != NULL) CSdeleteDatumCatalog (catPtr);
	if (__This != NULL) CS_free (__This);
	return NULL;
}

/******************************************************************************
	Destructor
*/
void CSdeleteVertconUS (struct csVertconUS_* __This)
{
	struct csVertconUSEntry_ *vcEntryPtr;

	if (__This != NULL)
	{
		if (__This->cachePtr != NULL)
		{
			CSdeleteZGridCellCache (__This->cachePtr);
			__This->cachePtr = NULL;
		}
		while (__This->listHead != NULL)
		{
			vcEntryPtr = __This->listHead;
			__This->listHead = __This->listHead->next;
			CSdeleteVertconUSEntry (vcEntryPtr);
		}
		CS_free (__This);
	}
	return;
}

/******************************************************************************
	Coverage Locator -- All files have the same density (so far) so a little of
	this is unecessary.
*/
struct csVertconUSEntry_* CSselectVertconUS (struct csVertconUS_* __This,Const double *ll83)
{
	double testValue;
	double bestSoFar;
	struct csVertconUSEntry_* vcEntryPtr;
	struct csVertconUSEntry_* rtnValue;

	rtnValue = NULL;
	bestSoFar = 3600000.00;
	vcEntryPtr = __This->listHead;
	while (vcEntryPtr != NULL)
	{
		testValue = CStestVertconUSEntry (vcEntryPtr,ll83);
		if (testValue != 0.0 && testValue < bestSoFar)
		{
			bestSoFar = testValue;
			rtnValue = vcEntryPtr;
		}
		vcEntryPtr = vcEntryPtr->next;
	}
	return rtnValue;
}

/******************************************************************************
	Make First -- Used for performance.  Well used to use it for performance.
	    This has been replaced with the GridCellCache business.  We now want
		to keep the order of these things the same as they appear in the
		catalog file.
*/
void CSfirstVertconUS (struct csVertconUS_* __This,struct csVertconUSEntry_* vcEntryPtr)
{
	struct csVertconUSEntry_* curPtr;
	struct csVertconUSEntry_* prvPtr;

	/* Take care of the already first situation very quickly. */
	if (vcEntryPtr == __This->listHead) return;

	/* Locate this guy on the list. */
	for (curPtr = __This->listHead,prvPtr = NULL;
		 curPtr != NULL;
		 prvPtr = curPtr,curPtr = curPtr->next)
	{
		if (curPtr == vcEntryPtr)
		{
			prvPtr->next = curPtr->next;						/*lint !e613 */
			curPtr->next = __This->listHead;
			__This->listHead = curPtr;
			break;
		}
	}
}

/******************************************************************************
	Calculate the elevation shift, the main man.  Note, result of this
	calculation is in millimeters.
*/
int CScalcVertconUS (struct csVertconUS_* __This,double* v88Mv29,Const double *ll83)
{
	int status;
	struct csVertconUSEntry_* vcEntryPtr;

	/* First see if using the cache works.  This works frequently. */
	if (__This->cachePtr != NULL)
	{
		status = CScalcZGridCellCache (__This->cachePtr,v88Mv29,ll83);
		if (status == 0)
		{
			return status;
		}
	}

	/* Guess we'll have to do it the hard way. */
	status = 0;
	vcEntryPtr = CSselectVertconUS (__This,ll83);
	if (vcEntryPtr != NULL)
	{
		status = CScalcVertconUSEntry (vcEntryPtr,v88Mv29,ll83,__This->cachePtr);
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
	Release -- Release resources, but maintain the directory status.
*/
void CSreleaseVertconUS (struct csVertconUS_* __This)
{
	struct csVertconUSEntry_* vcEntryPtr;

	if (__This != NULL)
	{
		for (vcEntryPtr = __This->listHead;vcEntryPtr != NULL;vcEntryPtr = vcEntryPtr->next)
		{
			CSreleaseVertconUSEntry (vcEntryPtr);
		}
	}
	return;
}

/******************************************************************************
	Constructor  (for an 'Entry' sub object)
*/
struct csVertconUSEntry_* CSnewVertconUSEntry (struct csDatumCatalogEntry_* catPtr)
{
	extern char cs_DirsepC;
	extern char cs_ExtsepC;
	extern char csErrnam [];

	char *cp;
	struct csVertconUSEntry_* __This;

	/* Prepare for an error. */
	__This = NULL;

	/* Allocate some storage. */
	__This = (struct csVertconUSEntry_*) CS_malc (sizeof (struct csVertconUSEntry_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	__This->next = NULL;
	__This->usGridPtr = NULL;

	/* Isolate the file name from the path, and the extension from the file name. */
	cp = strrchr (catPtr->pathName,cs_DirsepC);
	if (cp == NULL)
	{
		/* Is not supposed to happen, but we can't allow a bomb. */
		CS_stncp (csErrnam,catPtr->pathName,MAXPATH);
		CS_erpt (cs_DTC_PATH);
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

	/* Report special errors concerning the extensions.  Again, specific
	   error messages will reduce frustration. */
	if (CS_stricmp (cp,"94"))
	{
		CS_erpt (cs_VCON_94);
		goto error;
	}
	/* Do what's appropriate for this extension. */
	if (!CS_stricmp (cp,"94"))
	{
		__This->usGridPtr = CSnewGridFileUS (catPtr->pathName,catPtr->bufferSize,catPtr->flags,catPtr->density);
		if (__This->usGridPtr == NULL)
		{
			goto error;
		}
	}
	/* When we know how to do the others, we add that stuff here. */
	else
	{
		CS_erpt (cs_VCON_EXT);
		goto error;
	}
	return __This;
error:
	CSdeleteVertconUSEntry (__This);
	return NULL;
}

/******************************************************************************
	Destructor  (for an 'Entry' sub object)
*/
void CSdeleteVertconUSEntry (struct csVertconUSEntry_* __This)
{
	if (__This != NULL)
	{
		if (__This->usGridPtr != NULL)
		{
			CSdeleteGridFileUS (__This->usGridPtr);
		}
		CS_free (__This);
	}
	return;
}

/******************************************************************************
	Release resources  (for an 'Entry' sub object)
*/
void CSreleaseVertconUSEntry (struct csVertconUSEntry_* __This)
{
	if (__This != NULL)
	{
		if (__This->usGridPtr != NULL)
		{
			CSreleaseGridFileUS (__This->usGridPtr);
		}
	}
	return;
}

/******************************************************************************
	Locate appropriate "entry' sub object  (for an 'Entry' sub object)
*/
double CStestVertconUSEntry (struct csVertconUSEntry_* __This,Const double* ll83)
{
	double rtnValue;

	rtnValue = 0.0;
	if (__This != NULL)
	{
		if (__This->usGridPtr != NULL)
		{
			rtnValue = CStestGridFileUS (__This->usGridPtr,ll83);
		}
	}
	return rtnValue;
}

/******************************************************************************
	Calculate vertical datum shift, given a specific 'Entry' sub object.
	Note, result of this calculation is in millimeters.
*/
int CScalcVertconUSEntry (struct csVertconUSEntry_* __This,double* v88Mv29,Const double *ll83,struct csZGridCellCache_* cachePtr)
{
	extern double cs_Zero;

	int status;

	*v88Mv29 = cs_Zero;
	status = -1;
	if (__This != NULL && __This->usGridPtr != NULL)
	{
		status = CScalcGridFileUS (__This->usGridPtr,v88Mv29,ll83);

		/* If cachePtr is not NULL, we add the current cell to the
		   cache.  If we find situations where cacheing a cell is
		   inappropriate, add that code here. */
		if (cachePtr != NULL)
		{
			CSaddZGridCellCache (cachePtr,dtcTypeUSVertcon,&__This->usGridPtr->currentCell);	/*lint !e534 */
		}
	}
	return status;
}
