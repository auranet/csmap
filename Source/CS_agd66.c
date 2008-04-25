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

			 File Name: $RCSfile: CS_agd66.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #4 $
		 Check In Date:	$Date: 2006/11/16 $

		Last Revision:	$Log: CS_agd66.c $
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
		Last Revision:	Revision 11.700  2003/12/19 01:49:50  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:25  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.502  2003/11/24 01:12:01  nto
		Last Revision:	Correct very remote possibility of addressing fault when errors occur.
		Last Revision:	Revision 11.501  2003/08/22 21:12:52  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:19  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:13  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:40  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1501  2002/11/21 00:41:39  nto
		Last Revision:	Added the log/source functions for reporting which file got used in datum conversions.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:17  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:19  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:11  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:34  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:24  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:08  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:43  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:37  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.501  2000/12/11 05:15:57  nto
		Last Revision:	Fixed the wrong catalog file name problem.  Can't leave the name in cs_Dir as it gets used in lower modules.
		Last Revision:	Revision 10.500  2000/10/27 07:38:15  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.401  2000/10/27 03:41:15  nto
		Last Revision:	Added the datum fallback feature to all datums which
		Last Revision:	rely on grid data files
		Last Revision:	Revision 10.400  2000/09/13 01:16:49  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:20  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:12  nto
		Last Revision:	Revision 1.2  2000/02/11 05:22:59  nto
		Last Revision:	Tested, appears to work.
		Last Revision:	Revision 1.1  2000/02/08 19:17:14  nto
		Last Revision:	Initial Revision

		       * * * * R E M A R K S * * * *

	Provides conversion of AGD66 geodetic coordinates to GDA94 coordinates.
	Handles multiple files in the Canadian National Transformation, Version 2,
	Australian variation, format.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_agd66.c#4 $"};
#endif

#include "cs_map.h"

/******************************************************************************
	The following is used to maintain the status of the AGD66<-->GDA94
	conversion system.  Namely, if its already opened, we don't have to
	open it again.  Upon close, we release resources, but don't actually
	destruct.  The counter keeps track of the number of opens.
*/
struct csAgd66ToGda94_* csAgd66ToGda94 = NULL;
int csAgd66ToGda94Cnt = 0;

/******************************************************************************
	Initialize the AGD66 <--> GDA94 conversion system.  The catalog file is
	expected to	reside in the basic data directory.  The name of the file is
	taken from the cs_Agd66Name global variable.
*/
int EXP_LVL7 CSagd66Init (void)
{
	extern char cs_Dir [];
	extern char* cs_DirP;
	extern char cs_Agd66Name [];

	char catalog [MAXPATH];

	if (csAgd66ToGda94 == NULL)
	{
		/* Set up the catalog file name.  Need a copy of it as the
		   new function will access CS_dtloc. */
		CS_stcpy (cs_DirP,cs_Agd66Name);
		CS_stncp (catalog,cs_Dir,sizeof (catalog));

		/* Use it to build the Agd66ToGda94 object. */
		csAgd66ToGda94 = CSnewAgd66ToGda94 (catalog);
		if (csAgd66ToGda94 == NULL) goto error;
	}
	csAgd66ToGda94Cnt += 1;
	return 0;

error:
	if (csAgd66ToGda94 != NULL)
	{
		CSdeleteAgd66ToGda94 (csAgd66ToGda94);
		csAgd66ToGda94 = NULL;
		csAgd66ToGda94Cnt = 0;
	}
	return -1;
}

/******************************************************************************
	Close the AGD66 <--> GDA94 conversion system.  Note, this only does a
	release, not a full delete.  This is for performance reasons.  During
	test, you may get a "memory leak message" because of this.  If this is
	undeirable, then change the 'release' function to the 'delete' function.
*/
void EXP_LVL7 CSagd66Cls (void)
{
	csAgd66ToGda94Cnt -= 1;
	if (csAgd66ToGda94Cnt <= 0)
	{
		if (csAgd66ToGda94 != NULL)
		{
			CSreleaseAgd66ToGda94 (csAgd66ToGda94);
			csAgd66ToGda94 = NULL;
		}
		csAgd66ToGda94Cnt = 0;
	}
	return;
}

/******************************************************************************
	Convert an AGD66 coordinate to GDA94 coordinate.

	Returns  0 for expected result
	        -1 for hard/fatal failure
			+1 for no data coverage, unshifted result returned
			+2 for no data coverage, fallback used successfully
*/
int EXP_LVL7 CSagd66ToGda94 (double ll_gda94 [3],Const double ll_agd66 [3])
{
	int status;
	double my_ll94 [3];

	/* We always do the null conversion. */
	my_ll94 [LNG] = ll_agd66 [LNG];
	my_ll94 [LAT] = ll_agd66 [LAT];
	my_ll94 [HGT] = ll_agd66 [HGT];

	/* Do the real conversion, if possible. */
	if (csAgd66ToGda94 == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
		status = -1;
	}
	else
	{
		status = CScalcAgd66ToGda94 (csAgd66ToGda94,my_ll94,ll_agd66);
	}
	ll_gda94 [LNG] = my_ll94 [LNG];
	ll_gda94 [LAT] = my_ll94 [LAT];
	ll_gda94 [HGT] = my_ll94 [HGT];
	return status;
}

/******************************************************************************
	Convert an GDA94 coordinate to AGD66 coordinate. Computationally, the
	inverse of the above.

	Returns  0 for expected result
	        -1 for hard/fatal failure
			+1 for no data coverage, unshifted result returned
			+2 for no data coverage, fallback used successfully
*/
int EXP_LVL7 CSgda94ToAgd66 (double ll_agd66 [3],Const double ll_gda94 [3])
{
	int status;

	double my_ll66 [3];

	/* We always do the null conversion. */
	my_ll66 [LNG] = ll_gda94 [LNG];
	my_ll66 [LAT] = ll_gda94 [LAT];
	my_ll66 [HGT] = ll_gda94 [HGT];

	/* Do the real conversion, if possible. */
	if (csAgd66ToGda94 == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
		status = -1;
	}
	else
	{
		status = CSinverseAgd66ToGda94 (csAgd66ToGda94,my_ll66,ll_gda94);
	}

	if (status >= 0)
	{
		ll_agd66 [LNG] = my_ll66 [LNG];
		ll_agd66 [LAT] = my_ll66 [LAT];
		ll_agd66 [HGT] = my_ll66 [HGT];
	}
	return status;
}
Const char * EXP_LVL7 CSagd66ToGda94Log (Const double ll_66 [2])
{
	Const char *cp;

	cp = NULL;
	/* Make sure we have been initialized. */
	if (csAgd66ToGda94 == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
	}
	else
	{
		cp = CSsourceAgd66ToGda94 (csAgd66ToGda94,ll_66);
	}
	return (cp == NULL || *cp == '\0') ? "<unavailable>" : cp;
}
/**********************************************************************
**	CS_agd66Name (new_name);
**
**	char *new_name;				the name of the Agd66ToGda94 catalog
**								file.
**
**	This function specifies the name only.  The directory,
**	and possibly drive, are specified using CS_altdr.
**********************************************************************/
void EXP_LVL1 CS_agd66Name (Const char *newName)
{
	extern char cs_Agd66Name [];

	CS_stncp (cs_Agd66Name,newName,cs_FNM_MAXLEN);
	return;
}
