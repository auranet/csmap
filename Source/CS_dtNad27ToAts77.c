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

			 File Name: $Source: C:/Development/NewCsMap/rcs/CS_dtNad27ToAts77.c $
			 Full Name:	NAD27 to ATS77 Compund Object
		   Description:
			   Purpose:	Combines multiple ATS77 TRANSFORM
						data files into a single object.

		Revision Level:	$Revision: #3 $
				  Date:	$Date: 2005/07/26 $

		 Last Revision:	$Log: CS_dtNad27ToAts77.c $
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
		 Last Revision:	Revision 11.502  2003/11/24 01:12:05  nto
		 Last Revision:	Correct very remote possibility of addressing fault when errors occur.
		 Last Revision:	Revision 11.501  2003/08/22 21:12:54  nto
		 Last Revision:	Official Release: 11.05
		 Last Revision:	Revision 11.401  2003/05/01 23:06:21  nto
		 Last Revision:	Revision 11.301  2003/04/28 22:46:13  nto
		 Last Revision:	Modified so that the'test' function can survive a NULL pointer without crashing.
		 Last Revision:	Revision 11.300  2003/02/25 04:29:15  nto
		 Last Revision:	Official Release 11.03
		 Last Revision:	Revision 11.100  2002/11/22 19:38:42  nto
		 Last Revision:	Official release: 11.01
		 Last Revision:	Revision 10.1501  2002/11/21 00:41:42  nto
		 Last Revision:	Added the log/source functions for reporting which file got used in datum conversions.
		 Last Revision:	Revision 10.1500  2002/09/22 00:01:19  nto
		 Last Revision:	Official Release:= 10.15
		 Last Revision:	Revision 1.1  2002/09/17 23:21:31  nto
		 Last Revision:	Initial Revision

		       * * * * R E M A R K S * * * *

	This object maintains a list of various TRANSFORM data files,
	enabling the conversion of geographic coordinates from NAD27
	to ATS77 (and vice versa).  Thus, NAD27<-->ATS77 can be
	considered a single object rather than one for each province.

	There are six files, and it is unlikely that any more will
	ever be developed.  The .gdc concept enables users to determine
	which file takes precedence in the case of a conversion point
	which happens to be covered by more than one file.

*****************************************************************************/

#include "cs_map.h"

#ifdef LABEL_MODULE
static char revlvl [] = {"%Id%"};
#endif

/******************************************************************************
	Constructor
*/
struct csNad27ToAts77_* CSnewNad27ToAts77 (Const char *catalog)
{
	int index;
	Const char *cp;
	struct csNad27ToAts77_ *__This;
	struct csDatumCatalog_ *catPtr;
	struct csDatumCatalogEntry_ *catEntryPtr;
	struct csNad27ToAts77Entry_* dtEntryPtr;
	struct csNad27ToAts77Entry_* findPtr;

	/* Prepare for an error. */
	__This = NULL;
	catPtr = NULL;
	catEntryPtr = NULL;
	dtEntryPtr = NULL;

	__This = (struct csNad27ToAts77_*) CS_malc (sizeof (struct csNad27ToAts77_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	__This->fallback = NULL;
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
		dtEntryPtr = CSnewNad27ToAts77Entry (catEntryPtr);
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

	/* OK, it's ready to go. */
	return __This;

error:
	if (catPtr != NULL) CSdeleteDatumCatalog (catPtr);
	CSdeleteNad27ToAts77 (__This);
	return NULL;
}
/******************************************************************************
	Destructor
*/
void CSdeleteNad27ToAts77 (struct csNad27ToAts77_* __This)
{
	struct csNad27ToAts77Entry_ *dtEntryPtr;

	if (__This != NULL)
	{
		if (__This->fallback != NULL)
		{
			CSdeleteFallback (__This->fallback);
			__This->fallback = NULL;
		}
		while (__This->listHead != NULL)
		{
			dtEntryPtr = __This->listHead;
			__This->listHead = __This->listHead->next;
			CSdeleteNad27ToAts77Entry (dtEntryPtr);
		}
		CS_free (__This);
	}
	return;
}
/******************************************************************************
	Coverage Locator: Selects the specific grid shift object to use for the
		provided point.  Selection is based on grid density value.
*/
struct csNad27ToAts77Entry_* CSselectNad27ToAts77 (struct csNad27ToAts77_* __This,enum cs_Ats77Dir_ direction,Const double *ll_test)
{
	double testValue;
	double bestSoFar;
	struct csNad27ToAts77Entry_* dtEntryPtr;
	struct csNad27ToAts77Entry_* rtnValue;

	rtnValue = NULL;
	bestSoFar = 3600000.00;
	dtEntryPtr = __This->listHead;
	while (dtEntryPtr != NULL)
	{
		testValue = CStestNad27ToAts77Entry (dtEntryPtr,direction,ll_test);
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
	Calculate datum shift, the main man.
	Returns  0 for expected result
	        -1 for hard/fatal failure
			+1 for no data coverage, unshifted result returned
			+2 for no data coverage, fallback used successfully
*/
int CScalcNad27ToAts77 (struct csNad27ToAts77_* __This,double* ll_ats77,Const double *ll_nad27)
{
	int status;
	struct csNad27ToAts77Entry_* dtEntryPtr;

	status = 0;

	dtEntryPtr = CSselectNad27ToAts77 (__This,ats77DirToAts77,ll_nad27);
	if (dtEntryPtr != NULL)
	{
		status = CScalcNad27ToAts77Entry (dtEntryPtr,ll_ats77,ll_nad27);
	}
	else if (__This->fallback != NULL)
	{
		/* Use the fallback definition if there is no coverage. */
		status = CScalcFallbackForward (__This->fallback,ll_ats77,ll_nad27);
	}
	else
	{
		/* We didn't find any coverage.  A positive value is used to indicate
		   an error, but not internally within this code. */
		status = 1;
	}
	return status;
}
int CScalcAts77ToNad27 (struct csNad27ToAts77_* __This,double* ll_nad27,Const double *ll_ats77)
{
	int status;
	struct csNad27ToAts77Entry_* dtEntryPtr;

	status = 0;

	dtEntryPtr = CSselectNad27ToAts77 (__This,ats77DirToNad27,ll_ats77);
	if (dtEntryPtr != NULL)
	{
		status = CScalcNad27ToAts77Entry (dtEntryPtr,ll_nad27,ll_ats77);
	}
	else if (__This->fallback != NULL)
	{
		/* Use the fallback definition if there is no coverage. */
		status = CScalcFallbackInverse (__This->fallback,ll_nad27,ll_ats77);
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
	Release -- Release resources, but maintain the directory status.
*/
void CSreleaseNad27ToAts77 (struct csNad27ToAts77_* __This)
{
	struct csNad27ToAts77Entry_* dtEntryPtr;

	if (__This != NULL)
	{
		for (dtEntryPtr = __This->listHead;dtEntryPtr != NULL;dtEntryPtr = dtEntryPtr->next)
		{
			CSreleaseNad27ToAts77Entry (dtEntryPtr);
		}
	}
	return;
}
Const char *CSsourceNad27ToAts77 (struct csNad27ToAts77_* __This,Const double ll_27 [2])
{
	const char *cp;
	struct csNad27ToAts77Entry_* dtEntryPtr;

	cp = NULL;
	dtEntryPtr = CSselectNad27ToAts77 (__This,ats77DirToAts77,ll_27);
	if (dtEntryPtr != NULL)
	{
		cp = CSsourceNad27ToAts77Entry (dtEntryPtr,ll_27);
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
struct csNad27ToAts77Entry_* CSnewNad27ToAts77Entry (struct csDatumCatalogEntry_* catPtr)
{
	struct csNad27ToAts77Entry_* __This;

	/* Prepare for an error. */
	__This = NULL;

	/* Allocate some storage. */
	__This = (struct csNad27ToAts77Entry_*) CS_malc (sizeof (struct csNad27ToAts77Entry_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	__This->next = NULL;
	__This->type = dtNad27ToAts77NoneYet;
	__This->pointers.ats77XfrmPtr = NULL;

	/* Set up the file; construct a Canadian National Transformation,
	   Version 2 object.  It's smart enough to deal with the differences
	   between the Canadian format and the Australian variation. */
	__This->pointers.ats77XfrmPtr = CSnewAts77Xfrm (catPtr->pathName,catPtr->flags,catPtr->density);
	if (__This->pointers.ats77XfrmPtr == NULL)
	{
		goto error;
	}
	__This->type = dtAts77Xfrm;
	return __This;

error:
	CSdeleteNad27ToAts77Entry (__This);
	return NULL;
}

/******************************************************************************
	Destructor, for an "Entry" object.
*/
void CSdeleteNad27ToAts77Entry (struct csNad27ToAts77Entry_* __This)
{
	if (__This != NULL)
	{
		switch (__This->type){
		case dtAts77Xfrm:
			CSdeleteAts77Xfrm (__This->pointers.ats77XfrmPtr);
			break;
		case dtNad27ToAts77NoneYet:
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
void CSreleaseNad27ToAts77Entry (struct csNad27ToAts77Entry_* __This)
{
	if (__This != NULL)
	{
		switch (__This->type){
		case dtAts77Xfrm:
			CSreleaseAts77Xfrm (__This->pointers.ats77XfrmPtr);
			break;
		case dtNad27ToAts77NoneYet:
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
double CStestNad27ToAts77Entry (struct csNad27ToAts77Entry_* __This,enum cs_Ats77Dir_ direction,Const double* ll_test)
{
	extern double cs_Zero;

	double rtnValue = cs_Zero;

	if (__This != NULL)
	{
		switch (__This->type) {
		case dtAts77Xfrm:
			rtnValue = CStestAts77Xfrm (__This->pointers.ats77XfrmPtr,direction,ll_test);
			break;
		case dtNad27ToAts77NoneYet:
		default:
			break;
		}
	}
	return rtnValue;
}
/******************************************************************************
	Calculation function.  Calculates the conversion from Ats77 to NAD83.
*/
int CScalcNad27ToAts77Entry (struct csNad27ToAts77Entry_* __This,double* ll_out,Const double *ll_in)
{
	extern char csErrnam [];

	int status;

	switch (__This->type){
	case dtAts77Xfrm:
		status = CScalcAts77Xfrm (__This->pointers.ats77XfrmPtr,ll_out,ll_in);
		break;
	case dtNad27ToAts77NoneYet:
	default:
		CS_stncp (csErrnam,"CS_dtNad27ToAts77:1",MAXPATH);
		CS_erpt (cs_ISER);
		status = -1;
		break;
	}
	return status;
}
/******************************************************************************
	Data source function.  Returns the data source file name.
*/
Const char *CSsourceNad27ToAts77Entry (struct csNad27ToAts77Entry_* __This,Const double *ll27)
{
	Const char *cp;

	switch (__This->type) {
	case dtAts77Xfrm:
		cp = CSsourceAts77Xfrm (__This->pointers.ats77XfrmPtr);
		break;
	case dtNad27ToAts77NoneYet:
	default:
		cp = NULL;
		break;
	}
	return cp;
}
