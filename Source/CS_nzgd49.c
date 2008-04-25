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

			 File Name: $RCSfile: CS_nzgd49.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #3 $
		 Check In Date:	$Date: 2005/07/26 $

		Last Revision:	$Log: CS_nzgd49.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:16  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:14  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:12  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:20  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:27  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:16  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:55  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:30  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.502  2003/11/24 01:12:08  nto
		Last Revision:	Correct very remote possibility of addressing fault when errors occur.
		Last Revision:	Revision 11.501  2003/08/22 21:12:58  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:24  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:19  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:46  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1500  2002/09/22 00:01:22  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:24  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:19  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:39  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:28  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:13  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:52  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:46  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.501  2000/12/11 05:16:12  nto
		Last Revision:	Fixed the wrong catalog file name problem.  Can't leave the name in cs_Dir as it gets used in lower modules.
		Last Revision:	Revision 10.500  2000/10/27 07:38:24  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:16:58  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:29  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:20  nto
		Last Revision:	Revision 1.2  2000/02/11 06:12:50  nto
		Last Revision:	Replaced the whole thing, original file had the wrong file name.

		       * * * * R E M A R K S * * * *

	Provides conversion of NZGD49 geodetic coordinates to NZGD2K
	coordinates.  Handles multiple files in the Canadian National
	Transformation, Version 2, Australian variation, format.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_nzgd49.c#3 $"};
#endif

#include "cs_map.h"

/******************************************************************************
	The following is used to maintain the status of the NZGD49<-->NZGD2K
	conversion system.  Namely, if its already opened, we don't have to
	open it again.  Upon close, we release resources, but don't actually
	destruct.  The counter keeps track of the number of opens.
*/
struct csNzgd49ToNzgd2K_* csNzgd49ToNzgd2K = NULL;
int csNzgd49ToNzgd2KCnt = 0;

/******************************************************************************
	Initialize the NZGD49 <--> NZGD2K conversion system.  The catalog file is
	expected to	reside in the basic data directory.  The name of the file is
	taken from the cs_Nzgd49Name global variable.
*/
int EXP_LVL7 CSnzgd49Init (void)
{
	extern char cs_Dir [];
	extern char* cs_DirP;
	extern char cs_Nzgd49Name [];

	char catalog [MAXPATH];

	if (csNzgd49ToNzgd2K == NULL)
	{
		/* Set up the catalog file name. */
		CS_stcpy (cs_DirP,cs_Nzgd49Name);
		CS_stncp (catalog,cs_Dir,sizeof (catalog));

		/* Use it to build the Nzgd49ToNzgd2K object. */
		csNzgd49ToNzgd2K = CSnewNzgd49ToNzgd2K (catalog);
		if (csNzgd49ToNzgd2K == NULL) goto error;
	}
	csNzgd49ToNzgd2KCnt += 1;
	return 0;

error:
	if (csNzgd49ToNzgd2K != NULL)
	{
		CSdeleteNzgd49ToNzgd2K (csNzgd49ToNzgd2K);
		csNzgd49ToNzgd2K = NULL;
		csNzgd49ToNzgd2KCnt = 0;
	}
	return -1;
}

/******************************************************************************
	Close the NZGD49 <--> NZGD2K conversion system.  Note, this only does a
	release, not a full delete.  This is for performance reasons.  During
	test, you may get a "memory leak message" because of this.  If this is
	undeirable, then change the 'release' function to the 'delete' function.
*/
void EXP_LVL7 CSnzgd49Cls (void)
{
	csNzgd49ToNzgd2KCnt -= 1;
	if (csNzgd49ToNzgd2KCnt <= 0)
	{
		if (csNzgd49ToNzgd2K != NULL)
		{
			CSreleaseNzgd49ToNzgd2K (csNzgd49ToNzgd2K);
			csNzgd49ToNzgd2K = NULL;
		}
		csNzgd49ToNzgd2KCnt = 0;
	}
	return;
}

/******************************************************************************
	Convert an NZGD49 coordinate to NZGD2K coordinate.
*/
int EXP_LVL7 CSnzgd49ToNzgd2K (double ll_nzgd2K [3],Const double ll_nzgd49 [3])
{
	int status;
	double my_ll2K [3];

	/* We always do the null conversion. */
	my_ll2K [LNG] = ll_nzgd49 [LNG];
	my_ll2K [LAT] = ll_nzgd49 [LAT];
	my_ll2K [HGT] = ll_nzgd49 [HGT];

	/* Do the real conversion, if possible. */
	if (csNzgd49ToNzgd2K == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
		status = -1;
	}
	else
	{
		status = CScalcNzgd49ToNzgd2K (csNzgd49ToNzgd2K,my_ll2K,ll_nzgd49);
	}
	ll_nzgd2K [LNG] = my_ll2K [LNG];
	ll_nzgd2K [LAT] = my_ll2K [LAT];
	ll_nzgd2K [HGT] = my_ll2K [HGT];
	return status;
}

/******************************************************************************
	Convert an NZGD2K coordinate to NZGD49 coordinate. Computationally, the
	inverse of the above.
*/
int EXP_LVL7 CSnzgd2KToNzgd49 (double ll_nzgd49 [3],Const double ll_nzgd2K [3])
{
	int status;

	double my_ll49 [3];

	/* We always do the null conversion. */
	my_ll49 [LNG] = ll_nzgd2K [LNG];
	my_ll49 [LAT] = ll_nzgd2K [LAT];
	my_ll49 [HGT] = ll_nzgd2K [HGT];

	/* Do the real conversion, if possible. */
	if (csNzgd49ToNzgd2K == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
		status = -1;
	}
	else
	{
		status = CSinverseNzgd49ToNzgd2K (csNzgd49ToNzgd2K,my_ll49,ll_nzgd2K);
	}

	if (status >= 0)
	{
		ll_nzgd49 [LNG] = my_ll49 [LNG];
		ll_nzgd49 [LAT] = my_ll49 [LAT];
		ll_nzgd49 [HGT] = my_ll49 [HGT];
	}
	return status;
}
/**********************************************************************
**	CS_nzgd49Name (new_name);
**
**	char *new_name;				the name of the Nzgd49ToNzgd2K catalog
**								file.
**
**	This function specifies the name only.  The directory,
**	and possibly drive, are specified using CS_altdr.
**********************************************************************/
void EXP_LVL1 CS_nzgd49Name (Const char *newName)
{
	extern char cs_Nzgd49Name [];

	CS_stncp (cs_Nzgd49Name,newName,cs_FNM_MAXLEN);
	return;
}
