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

			 File Name: $RCSfile: CS_ed50.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #4 $
		 Check In Date:	$Date: 2006/11/16 $

		Last Revision:	$Log: CS_ed50.c $
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
		Last Revision:	Revision 11.502  2003/11/24 01:12:07  nto
		Last Revision:	Correct very remote possibility of addressing fault when errors occur.
		Last Revision:	Revision 11.501  2003/08/22 21:12:55  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:21  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:15  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:43  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1501  2002/11/21 00:41:43  nto
		Last Revision:	Added the log/source functions for reporting which file got used in datum conversions.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:19  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 1.1  2002/09/15 21:16:00  nto
		Last Revision:	Initial Revision

		       * * * * R E M A R K S * * * *

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_ed50.c#4 $"};
#endif

#include "cs_map.h"

/******************************************************************************
	The following is used to maintain the status of the AGD66<-->GDA94
	conversion system.  Namely, if its already opened, we don't have to
	open it again.  Upon close, we release resources, but don't actually
	destruct.  The counter keeps track of the number of opens.
*/
struct csEd50ToEtrf89_* csEd50ToEtrf89 = NULL;
int csEd50ToEtrf89Cnt = 0;

/******************************************************************************
	Initialize the AGD66 <--> GDA94 conversion system.  The catalog file is
	expected to	reside in the basic data directory.  The name of the file is
	taken from the cs_Agd66Name global variable.
*/
int EXP_LVL7 CSed50Init (void)
{
	extern char cs_Dir [];
	extern char* cs_DirP;
	extern char cs_Ed50Name [];

	char catalog [MAXPATH];

	if (csEd50ToEtrf89 == NULL)
	{
		/* Set up the catalog file name.  Need a copy of it as the
		   new function will access CS_dtloc. */
		CS_stcpy (cs_DirP,cs_Ed50Name);
		CS_stncp (catalog,cs_Dir,sizeof (catalog));

		/* Use it to build the Ed50ToEtrf89 object. */
		csEd50ToEtrf89 = CSnewEd50ToEtrf89 (catalog);
		if (csEd50ToEtrf89 == NULL) goto error;
	}
	csEd50ToEtrf89Cnt += 1;
	return 0;

error:
	if (csEd50ToEtrf89 != NULL)
	{
		CSdeleteEd50ToEtrf89 (csEd50ToEtrf89);
		csEd50ToEtrf89 = NULL;
		csEd50ToEtrf89Cnt = 0;
	}
	return -1;
}

/******************************************************************************
	Close the AGD66 <--> GDA94 conversion system.  Note, this only does a
	release, not a full delete.  This is for performance reasons.  During
	test, you may get a "memory leak message" because of this.  If this is
	undeirable, then change the 'release' function to the 'delete' function.
*/
void EXP_LVL7 CSed50Cls (void)
{
	csEd50ToEtrf89Cnt -= 1;
	if (csEd50ToEtrf89Cnt <= 0)
	{
		if (csEd50ToEtrf89 != NULL)
		{
			CSreleaseEd50ToEtrf89 (csEd50ToEtrf89);
			csEd50ToEtrf89 = NULL;
		}
		csEd50ToEtrf89Cnt = 0;
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
int EXP_LVL7 CSed50ToEtrf89 (double ll_etrf89 [3],Const double ll_ed50 [3])
{
	int status;
	double my_ll89 [3];

	/* We always do the null conversion. */
	my_ll89 [LNG] = ll_ed50 [LNG];
	my_ll89 [LAT] = ll_ed50 [LAT];
	my_ll89 [HGT] = ll_ed50 [HGT];

	/* Do the real conversion, if possible. */
	if (csEd50ToEtrf89 == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
		status = -1;
	}
	else
	{
		status = CScalcEd50ToEtrf89 (csEd50ToEtrf89,my_ll89,ll_ed50);
	}
	ll_etrf89 [LNG] = my_ll89 [LNG];
	ll_etrf89 [LAT] = my_ll89 [LAT];
	ll_etrf89 [HGT] = my_ll89 [HGT];
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
int EXP_LVL7 CSetrf89ToEd50 (double ll_ed50 [3],Const double ll_etrf89 [3])
{
	int status;

	double my_ll50 [3];

	/* We always do the null conversion. */
	my_ll50 [LNG] = ll_etrf89 [LNG];
	my_ll50 [LAT] = ll_etrf89 [LAT];
	my_ll50 [HGT] = ll_etrf89 [HGT];

	/* Do the real conversion, if possible. */
	if (csEd50ToEtrf89 == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
		status = -1;
	}
	else
	{
		status = CSinverseEd50ToEtrf89 (csEd50ToEtrf89,my_ll50,ll_etrf89);
	}

	if (status >= 0)
	{
		ll_ed50 [LNG] = my_ll50 [LNG];
		ll_ed50 [LAT] = my_ll50 [LAT];
		ll_ed50 [HGT] = my_ll50 [HGT];
	}
	return status;
}
Const char * EXP_LVL7 CSed50ToEtrf89Log (Const double ll_50 [2])
{
	Const char *cp;

	cp = NULL;
	/* Make sure we have been initialized. */
	if (csEd50ToEtrf89 == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
	}
	else
	{
		cp = CSsourceEd50ToEtrf89 (csEd50ToEtrf89,ll_50);
	}
	return (cp == NULL || *cp == '\0') ? "<unavailable>" : cp;
}
/**********************************************************************
**	CS_ed50Name (new_name);
**
**	char *new_name;				the name of the Ed50ToEtrf89 catalog
**								file.
**
**	This function specifies the name only.  The directory,
**	and possibly drive, are specified using CS_altdr.
**********************************************************************/
void EXP_LVL1 CS_ed50Name (Const char *newName)
{
	extern char cs_Ed50Name [];

	CS_stncp (cs_Ed50Name,newName,cs_FNM_MAXLEN);
	return;
}
