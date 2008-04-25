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

			 File Name: $Source: C:/Development/NewCsMap/rcs/cs_GeoidHeight.c $
			 Full Name:	Geoid Height Calculator object
		   Description:
			   Purpose:	Combines various types of geoid height
						calculation techniques into a common object
						for calculating geoid heights.

		Revision Level:	$Revision: #1 $
				  Date:	$Date: 2006/11/21 $

		 Last Revision:	$Log: cs_GeoidHeight.c $
		 Last Revision:	Revision 11.1300  2005/05/25 23:27:12  nto
		 Last Revision:	Official Release 11.13
		 Last Revision:	Revision 11.1200  2005/01/15 18:27:12  nto
		 Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		 Last Revision:	Revision 11.1100  2004/11/01 18:53:09  nto
		 Last Revision:	Official release 11.11
		 Last Revision:	Revision 11.1001  2004/10/07 19:25:18  nto
		 Last Revision:	Revision 11.900  2004/03/26 17:02:25  nto
		 Last Revision:	Official release: 11.09 - 3/25/2003
		 Last Revision:	Revision 11.800  2004/01/13 23:29:13  nto
		 Last Revision:	Revision 11.700  2003/12/19 01:49:53  nto
		 Last Revision:	Official release 11.07
		 Last Revision:	Revision 11.600  2003/12/04 02:46:28  nto
		 Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		 Last Revision:	Revision 11.501  2003/08/22 21:12:56  nto
		 Last Revision:	Official Release: 11.05
		 Last Revision:	Revision 11.401  2003/05/01 23:06:22  nto
		 Last Revision:	Revision 11.301  2003/04/04 00:37:55  nto
		 Last Revision:	Added the CS_geoidHgt () function, so as to be compatible with previous releases.
		 Last Revision:	Revision 11.300  2003/02/25 04:29:17  nto
		 Last Revision:	Official Release 11.03
		 Last Revision:	Revision 11.100  2002/11/22 19:38:44  nto
		 Last Revision:	Official release: 11.01
		 Last Revision:	Revision 10.1500  2002/09/22 00:01:20  nto
		 Last Revision:	Official Release:= 10.15
		 Last Revision:	Revision 10.1400  2002/08/09 18:14:22  nto
		 Last Revision:	Revision 10.1201  2002/07/23 04:09:57  nto
		 Last Revision:	Added support for the .byn file format.
		 Last Revision:	Revision 10.1200  2002/07/14 03:26:16  nto
		 Last Revision:	Revision 10.1100  2002/06/13 14:18:37  nto
		 Last Revision:	Release 10.11 Official
		 Last Revision:	Revision 10.1000  2002/02/23 21:18:27  nto
		 Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		 Last Revision:	Revision 10.902  2002/02/19 05:19:57  nto
		 Last Revision:	Added Geoid99 and OSGM91.
		 Last Revision:	Revision 10.901  2002/01/30 00:56:06  nto
		 Last Revision:	Geoid 96 and 99 now work, and have been superficially tested.
		 Last Revision:	Revision 10.900  2001/09/24 04:31:11  nto
		 Last Revision:	Revision 10.700  2001/01/25 04:13:49  nto
		 Last Revision:	Revision 10.600  2000/12/11 06:39:43  nto
		 Last Revision:	Release 10.06
		 Last Revision:	Revision 10.500  2000/10/27 07:38:20  nto
		 Last Revision:	Official Release 10.05
		 Last Revision:	Revision 10.400  2000/09/13 01:16:55  nto
		 Last Revision:	Release 10.04
		 Last Revision:	Revision 10.300  2000/04/04 23:18:26  nto
		 Last Revision:	Revision 10.201  2000/04/03 21:37:52  nto
		 Last Revision:	Modified to keep the entries in the same order as the files appear in the geodetic data catalog file.
		 Last Revision:	Revision 10.200  2000/03/02 18:51:17  nto
		 Last Revision:	Revision 1.4  2000/02/14 07:01:21  nto
		 Last Revision:	Preserve order of entries so that they always match the order in the catalog file.
		 Last Revision:	Revision 1.3  2000/01/30 23:41:12  nto
		 Last Revision:	Replaced stricmp with CS_stricmp.
		 Last Revision:	Revision 1.2  1999/11/03 23:41:05  nto
		 Last Revision:	Results of datum conversion rewrite.

		       * * * * R E M A R K S * * * *

	This object is designed to support access to, and use of, various
	geoid height calculation techniques.  Upon initial writing, only
	one technique is supported; the US GEOID 96 technique and data files.
	This, of course, limits coverage to the 48 conterminous states of
	the US.  However, it is expected that additional techniques and
	data source will be supported by this object in the future.

	Due to similarity with the datum problem, much of the code generated
	for datum calculations is used to develop this object.

******************************************************************************/

#include "cs_map.h"

#ifdef LABEL_MODULE
static char revlvl [] = {"%W"};
#endif

struct csGeoidHeight_ *csGeoidHeight = NULL;

/******************************************************************************
	High Level Interface access functions.
*/
int EXP_LVL1 CS_geoidHgt (Const double ll84 [2],double *height)
{
	extern double cs_Mhuge;				/* -1.0E+32  */
	extern char cs_Dir [];
	extern char *cs_DirP;
	extern struct csGeoidHeight_ *csGeoidHeight;

	int status = -1;


	*height = cs_Mhuge;
	if (csGeoidHeight == NULL)
	{
		CS_stcpy (cs_DirP,cs_GEOID_NAME);
		csGeoidHeight = CSnewGeoidHeight (cs_Dir);
	}
	if (csGeoidHeight != NULL)
	{
		status = CScalcGeoidHeight (csGeoidHeight,height,ll84);
	}
	return status;
}
void EXP_LVL1 CS_geoidCls (void)
{
	extern struct csGeoidHeight_ *csGeoidHeight;

	if (csGeoidHeight != NULL)
	{
		CSdeleteGeoidHeight (csGeoidHeight);
		csGeoidHeight = NULL;
	}
	return;
}
/******************************************************************************
        Constructor
*/
struct csGeoidHeight_* CSnewGeoidHeight (Const char *catalog)
{
	int index;
	struct csGeoidHeight_ *__This;
	struct csDatumCatalog_ *catPtr;
	struct csDatumCatalogEntry_ *catEntryPtr;
	struct csGeoidHeightEntry_* ghEntryPtr;
	struct csGeoidHeightEntry_* findPtr;

	/* Prepare for an error. */
	__This = NULL;
	catPtr = NULL;
	catEntryPtr = NULL;
	ghEntryPtr = NULL;

	__This = (struct csGeoidHeight_*) CS_malc (sizeof (struct csGeoidHeight_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
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
		ghEntryPtr = CSnewGeoidHeightEntry (catEntryPtr);
		if (ghEntryPtr == NULL)
		{
			goto error;
		}
		/* Keep the list in the same order as they appear in the file. */
		if (__This->listHead == NULL)
		{
			__This->listHead = ghEntryPtr;
		}
		else
		{
			for (findPtr = __This->listHead;findPtr->next != NULL;findPtr = findPtr->next);
			findPtr->next = ghEntryPtr;
		}
	}
	CSdeleteDatumCatalog (catPtr);
	catPtr = NULL;
	return __This;
error:
	if (catPtr != NULL) CSdeleteDatumCatalog (catPtr);
	if (__This != NULL) CS_free (__This);
	return NULL;
}

/******************************************************************************
	Destructor
*/
void CSdeleteGeoidHeight (struct csGeoidHeight_* __This)
{
	struct csGeoidHeightEntry_ *ghEntryPtr;

	if (__This != NULL)
	{
		while (__This->listHead != NULL)
		{
			ghEntryPtr = __This->listHead;
			__This->listHead = __This->listHead->next;
			CSdeleteGeoidHeightEntry (ghEntryPtr);
		}
		CS_free (__This);
	}
	return;
}

/******************************************************************************
	Coverage Locator
*/
struct csGeoidHeightEntry_* CSselectGeoidHeight (struct csGeoidHeight_* __This,Const double *ll84)
{
	double testValue;
	double bestSoFar;
	struct csGeoidHeightEntry_* ghEntryPtr;
	struct csGeoidHeightEntry_* rtnValue;

	rtnValue = NULL;
	bestSoFar = 3600000.00;
	ghEntryPtr = __This->listHead;
	while (ghEntryPtr != NULL)
	{
		testValue = CStestGeoidHeightEntry (ghEntryPtr,ll84);
		if (testValue != 0.0 && testValue < bestSoFar)
		{
			bestSoFar = testValue;
			rtnValue = ghEntryPtr;
		}
		ghEntryPtr = ghEntryPtr->next;
	}
	return rtnValue;
}

/******************************************************************************
	Make First -- Used for performance.  Well used to use it for performance.
		This has been replaced with the GridCellCache business.  We now want
		to keep the order of these things the same as they appear in the
		catalog file.
*/
void CSfirstGeoidHeight (struct csGeoidHeight_* __This,struct csGeoidHeightEntry_* ghEntryPtr)
{
	struct csGeoidHeightEntry_* curPtr;
	struct csGeoidHeightEntry_* prvPtr;

	/* Take care of the already first situation very quickly. */
	if (ghEntryPtr == __This->listHead) return;

	/* Locate this guy on the list. */
	for (curPtr = __This->listHead,prvPtr = NULL;
		 curPtr != NULL;
		 prvPtr = curPtr,curPtr = curPtr->next)
	{
		if (curPtr == ghEntryPtr)
		{
			prvPtr->next = curPtr->next;						/*lint !e613 */
			curPtr->next = __This->listHead;
			__This->listHead = curPtr;
			break;
		}
	}
}

/******************************************************************************
	Calculate the Geoid height, the main man.
*/
int CScalcGeoidHeight (struct csGeoidHeight_* __This,double* geoidHgt,Const double *ll84)
{
	int status;
	struct csGeoidHeightEntry_* ghEntryPtr;

	if (__This == NULL)
	{
		CS_erpt (cs_GEOID_INIT);
		status = -1;
	}
	else
	{
		status = 0;
		ghEntryPtr = CSselectGeoidHeight (__This,ll84);
		if (ghEntryPtr != NULL)
		{
			status = CScalcGeoidHeightEntry (ghEntryPtr,geoidHgt,ll84);
		}
		else
		{
			/* We didn't find any coverage.  Use the fall back position.
			   Return a +1 to indicate an approximation. */
			status = 1;
		}
	}
	return status;
}

/******************************************************************************
	Release -- Release resources, but maintain the directory status.
*/
void CSreleaseGeoidHeight (struct csGeoidHeight_* __This)
{
	struct csGeoidHeightEntry_* ghEntryPtr;

	if (__This != NULL)
	{
		for (ghEntryPtr = __This->listHead;ghEntryPtr != NULL;ghEntryPtr = ghEntryPtr->next)
		{
			CSreleaseGeoidHeightEntry (ghEntryPtr);
		}
	}
	return;
}

/******************************************************************************
	Constructor: for the "Entry" sub-object.  A linked list of these "Entry"
	objects is the basic structure of the main object.
*/
struct csGeoidHeightEntry_* CSnewGeoidHeightEntry (struct csDatumCatalogEntry_* catPtr)
{
	extern char cs_DirsepC;
	extern char cs_ExtsepC;
	extern char csErrnam [];

	char *cp;
	struct csGeoidHeightEntry_* __This;

	/* Prepare for an error. */
	__This = NULL;

	/* Allocate some storage. */
	__This = (struct csGeoidHeightEntry_*) CS_malc (sizeof (struct csGeoidHeightEntry_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	__This->next = NULL;
	__This->type = csGeoidHgtTypeNone;
	__This->pointers.geoid96Ptr = NULL;

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

	/* Do what's appropriate for this extension. */
	if (!CS_stricmp (cp,"GEO"))
	{
		/* Must not set the type until allocated for correct error handling. */
		__This->pointers.geoid96Ptr = CSnewGeoid96GridFile (catPtr->pathName,catPtr->bufferSize,catPtr->flags,catPtr->density);
		if (__This->pointers.geoid96Ptr == NULL)
		{
			goto error;
		}
		__This->type = csGeoidHgtTypeGeoid96;
	}
	else if (!CS_stricmp (cp,"bin"))
	{
		/* These are supposed to be Geoid99 type files. */
		/* Must not set the type until allocated for correct error handling. */
		__This->pointers.geoid99Ptr = CSnewGeoid99GridFile (catPtr->pathName,catPtr->bufferSize,catPtr->flags,catPtr->density);
		if (__This->pointers.geoid99Ptr == NULL)
		{
			goto error;
		}
		__This->type = csGeoidHgtTypeGeoid99;
	}
	else if (!CS_stricmp (cp,"osg"))
	{
		/* These are supposed to be OSGM91 type files. */
		/* Must not set the type until allocated for correct error handling. */
		__This->pointers.osgm91Ptr = CSnewOsgm91 (catPtr->pathName,catPtr->bufferSize,catPtr->flags,catPtr->density);
		if (__This->pointers.osgm91Ptr == NULL)
		{
			goto error;
		}
		__This->type = csGeoidHgtTypeOsgm91;
	}	/* When we know how to do the others, we add that stuff here. */
	else if (!CS_stricmp (cp,"byn"))
	{
		/* Must not set the type until allocated for correct error handling. */
		__This->pointers.bynGridFilePtr = CSnewBynGridFile (catPtr->pathName,catPtr->bufferSize,catPtr->flags,catPtr->density);
		if (__This->pointers.bynGridFilePtr == NULL)
		{
			goto error;
		}
		__This->type = csGeoidHgtTypeBynGridFile;
	}
	else
	{
		CS_erpt (cs_GHGT_EXT);
		goto error;
	}
	return __This;
error:
	CSdeleteGeoidHeightEntry (__This);
	return NULL;
}

/******************************************************************************
	Destructor: for the "Entry" sub-object.
*/
void CSdeleteGeoidHeightEntry (struct csGeoidHeightEntry_* __This)
{
	if (__This != NULL)
	{
		switch (__This->type){
		case csGeoidHgtTypeGeoid96:
			CSdeleteGeoid96GridFile (__This->pointers.geoid96Ptr);
			break;
		case csGeoidHgtTypeGeoid99:
			CSdeleteGeoid99GridFile (__This->pointers.geoid99Ptr);
			break;
		case csGeoidHgtTypeOsgm91:
			CSdeleteOsgm91 (__This->pointers.osgm91Ptr);
			break;
		case csGeoidHgtTypeBynGridFile:
			CSdeleteBynGridFile (__This->pointers.bynGridFilePtr);
			break;
		case csGeoidHgtTypeWorld:
		case csGeoidHgtTypeAustralia:
		case csGeoidHgtTypeNone:
		default:
			break;
		}
		CS_free (__This);
	}
	return;
}

/******************************************************************************
	Release resources: for the "Entry" sub-object.
*/
void CSreleaseGeoidHeightEntry (struct csGeoidHeightEntry_* __This)
{
	if (__This != NULL)
	{
		switch (__This->type){
		case csGeoidHgtTypeGeoid96:
			CSreleaseGeoid96GridFile (__This->pointers.geoid96Ptr);
			break;
		case csGeoidHgtTypeGeoid99:
			CSreleaseGeoid99GridFile (__This->pointers.geoid99Ptr);
			break;
		case csGeoidHgtTypeOsgm91:
			CSreleaseOsgm91 (__This->pointers.osgm91Ptr);
			break;
		case csGeoidHgtTypeBynGridFile:
			CSreleaseBynGridFile (__This->pointers.bynGridFilePtr);
			break;
		case csGeoidHgtTypeWorld:
		case csGeoidHgtTypeAustralia:
		case csGeoidHgtTypeNone:
		default:
			break;
		}
	}
	return;
}

/******************************************************************************
	coverage Test: for the "Entry" sub-object.
*/
double CStestGeoidHeightEntry (struct csGeoidHeightEntry_* __This,Const double* ll84)
{
	double rtnValue;

	rtnValue = 0.0;
	if (__This != NULL)
	{
		switch (__This->type){
		case csGeoidHgtTypeGeoid96:
			rtnValue = CStestGeoid96GridFile (__This->pointers.geoid96Ptr,ll84);
			break;
		case csGeoidHgtTypeGeoid99:
			rtnValue = CStestGeoid99GridFile (__This->pointers.geoid99Ptr,ll84);
			break;
		case csGeoidHgtTypeOsgm91:
			rtnValue = CStestOsgm91 (__This->pointers.osgm91Ptr,ll84);
			break;
		case csGeoidHgtTypeBynGridFile:
			rtnValue = CStestBynGridFile (__This->pointers.bynGridFilePtr,ll84);
			break;
		case csGeoidHgtTypeWorld:
		case csGeoidHgtTypeAustralia:
		case csGeoidHgtTypeNone:
		default:
			break;
		}
	}
	return rtnValue;
}

/******************************************************************************
	Calculate the geoid height, given the specific "Entry" item which is to
	be used.
*/
int CScalcGeoidHeightEntry (struct csGeoidHeightEntry_* __This,double* geoidHgt,Const double *ll84)
{
	extern char csErrnam [];

	int status;

	status = -1;
	if (__This != NULL)
	{
		switch (__This->type) {
		case csGeoidHgtTypeGeoid96:
			status = CScalcGeoid96GridFile (__This->pointers.geoid96Ptr,geoidHgt,ll84);
			break;
		case csGeoidHgtTypeGeoid99:
			status = CScalcGeoid99GridFile (__This->pointers.geoid99Ptr,geoidHgt,ll84);
			break;
		case csGeoidHgtTypeOsgm91:
			status = CScalcOsgm91 (__This->pointers.osgm91Ptr,geoidHgt,ll84);
			break;
		case csGeoidHgtTypeBynGridFile:
			status = CScalcBynGridFile (__This->pointers.bynGridFilePtr,geoidHgt,ll84);
			break;
		case csGeoidHgtTypeWorld:
		case csGeoidHgtTypeAustralia:
		case csGeoidHgtTypeNone:
		default:
			CS_stncp (csErrnam,"CS_usGridFile:3",MAXPATH);
			CS_erpt (cs_ISER);
			break;
		}
	}
	return status;
}
