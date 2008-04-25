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

			 File Name: $RCSfile: CS_ats77.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #4 $
		 Check In Date:	$Date: 2006/11/16 $

		Last Revision:	$Log: CS_ats77.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:06  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:08  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:05  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:14  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:21  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:10  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:50  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:25  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.502  2003/11/24 01:12:02  nto
		Last Revision:	Correct very remote possibility of addressing fault when errors occur.
		Last Revision:	Revision 11.501  2003/08/22 21:12:53  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:19  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:14  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:41  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1501  2002/11/21 00:41:39  nto
		Last Revision:	Added the log/source functions for reporting which file got used in datum conversions.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:17  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:20  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:12  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:34  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:24  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:08  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:44  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:38  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.501  2000/12/11 05:16:11  nto
		Last Revision:	Fixed the wrong catalog file name problem.  Can't leave the name in cs_Dir as it gets used in lower modules.
		Last Revision:	Revision 10.500  2000/10/27 07:38:16  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.401  2000/10/27 03:41:15  nto
		Last Revision:	Added the datum fallback feature to all datums which
		Last Revision:	rely on grid data files
		Last Revision:	Revision 10.400  2000/09/13 01:16:50  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:20  nto
		Last Revision:	Revision 10.201  2000/04/03 21:24:34  nto
		Last Revision:	Changed this datum conversion to be known as Ats77ToCsrs.  (used to be Ats77ToNad83).
		Last Revision:	Revision 10.200  2000/03/02 18:51:13  nto
		Last Revision:	Revision 1.2  2000/02/11 05:46:33  nto
		Last Revision:	Untsted, as yet.  Don't have a real data file.

		       * * * * R E M A R K S * * * *

	Provides conversion of ATS77 geodetic coordinates to NAD83 coordinates.
	Handles multiple files in the Canadian National Transformation, Version 2,
	Australian variation, format.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_ats77.c#4 $"};
#endif

#include "cs_map.h"

/******************************************************************************
	The following is used to maintain the status of the ATS77<-->NAD83
	conversion system.  Namely, if its already opened, we don't have to
	open it again.  Upon close, we release resources, but don't actually
	destruct.  The counter keeps track of the number of opens.
*/
struct csAts77ToCsrs_* csAts77ToCsrs = NULL;
int csAts77ToCsrsCnt = 0;

/******************************************************************************
	Initialize the ATS77 <--> CSRS conversion system.  The catalog file is
	expected to	reside in the basic data directory.  The name of the file is
	taken from the cs_Ats77Name global variable.
*/
int EXP_LVL7 CSats77Init (void)
{
	extern char cs_Dir [];
	extern char* cs_DirP;
	extern char cs_Ats77Name [];

	char catalog [MAXPATH];

	if (csAts77ToCsrs == NULL)
	{
		/* Set up the catalog file name. */
		CS_stcpy (cs_DirP,cs_Ats77Name);
		CS_stncp (catalog,cs_Dir,sizeof (catalog));

		/* Use it to build the Ats77ToCsrs object. */
		csAts77ToCsrs = CSnewAts77ToCsrs (catalog);
		if (csAts77ToCsrs == NULL) goto error;
	}
	csAts77ToCsrsCnt += 1;
	return 0;

error:
	if (csAts77ToCsrs != NULL)
	{
		CSdeleteAts77ToCsrs (csAts77ToCsrs);
		csAts77ToCsrs = NULL;
		csAts77ToCsrsCnt = 0;
	}
	return -1;
}

/******************************************************************************
	Close the ATS77 <--> CSRS conversion system.  Note, this only does a
	release, not a full delete.  This is for performance reasons.  During
	test, you may get a "memory leak message" because of this.  If this is
	undesirable, then change the 'release' function to the 'delete' function.
*/
void EXP_LVL7 CSats77Cls (void)
{
	csAts77ToCsrsCnt -= 1;
	if (csAts77ToCsrsCnt <= 0)
	{
		if (csAts77ToCsrs != NULL)
		{
			CSreleaseAts77ToCsrs (csAts77ToCsrs);
			csAts77ToCsrs = NULL;
		}
		csAts77ToCsrsCnt = 0;
	}
	return;
}

/******************************************************************************
	Convert an ATS77 coordinate to CSRS coordinate.
	Returns  0 for expected result
	        -1 for hard/fatal failure
			+1 for no data coverage, unshifted result returned
			+2 for no data coverage, fallback used successfully
*/
int EXP_LVL7 CSats77ToCsrs (double ll_csrs [3],Const double ll_ats77 [3])
{
	int status;
	double my_csrs [3];

	/* We always do the null conversion. */
	my_csrs [LNG] = ll_ats77 [LNG];
	my_csrs [LAT] = ll_ats77 [LAT];
	my_csrs [HGT] = ll_ats77 [HGT];

	/* Do the real conversion, if possible. */
	if (csAts77ToCsrs == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
		status = -1;
	}
	else
	{
		status = CScalcAts77ToCsrs (csAts77ToCsrs,my_csrs,ll_ats77);
	}
	ll_csrs [LNG] = my_csrs [LNG];
	ll_csrs [LAT] = my_csrs [LAT];
	ll_csrs [HGT] = my_csrs [HGT];
	return status;
}

/******************************************************************************
	Convert an CSRS coordinate to ATS77 coordinate. Computationally, the
	inverse of the above.
	Returns  0 for expected result
	        -1 for hard/fatal failure
			+1 for no data coverage, unshifted result returned
			+2 for no data coverage, fallback used successfully
*/
int EXP_LVL7 CScsrsToAts77 (double ll_ats77 [3],Const double ll_csrs [3])
{
	int status;

	double my_ats77 [3];

	/* We always do the null conversion. */
	my_ats77 [LNG] = ll_csrs [LNG];
	my_ats77 [LAT] = ll_csrs [LAT];
	my_ats77 [HGT] = ll_csrs [HGT];

	/* Do the real conversion, if possible. */
	if (csAts77ToCsrs == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
		status = -1;
	}
	else
	{
		status = CSinverseAts77ToCsrs (csAts77ToCsrs,my_ats77,ll_csrs);
	}

	if (status >= 0)
	{
		ll_ats77 [LNG] = my_ats77 [LNG];
		ll_ats77 [LAT] = my_ats77 [LAT];
		ll_ats77 [HGT] = my_ats77 [HGT];
	}
	return status;
}
Const char * EXP_LVL7 CSats77ToCsrsLog (Const double ll_77 [2])
{
	Const char *cp;

	cp = NULL;
	/* Make sure we have been initialized. */
	if (csAts77ToCsrs == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
	}
	else
	{
		cp = CSsourceAts77ToCsrs (csAts77ToCsrs,ll_77);
	}
	return (cp == NULL || *cp == '\0') ? "<unavailable>" : cp;
}
/**********************************************************************
**	CS_ats77Name (new_name);
**
**	char *new_name;				the name of the Ats77ToCsrs catalog
**								file.
**
**	This function specifies the name only.  The directory,
**	and possibly drive, are specified using CS_altdr.
**********************************************************************/
void EXP_LVL1 CS_ats77Name (Const char *newName)
{
	extern char cs_Ats77Name [];

	CS_stncp (cs_Ats77Name,newName,cs_FNM_MAXLEN);
	return;
}
