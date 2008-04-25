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

			 File Name: $RCSfile: CS_hpgn.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #4 $
		 Check In Date:	$Date: 2006/11/16 $

		Last Revision:	$Log: CS_hpgn.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:13  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:13  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:10  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:18  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:25  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:14  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:54  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:29  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:56  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:23  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:17  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:45  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1501  2002/11/21 00:41:43  nto
		Last Revision:	Added the log/source functions for reporting which file got used in datum conversions.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:21  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:23  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:17  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:38  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:27  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:11  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:50  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:44  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.501  2000/12/11 05:16:11  nto
		Last Revision:	Fixed the wrong catalog file name problem.  Can't leave the name in cs_Dir as it gets used in lower modules.
		Last Revision:	Revision 10.500  2000/10/27 07:38:22  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.401  2000/10/27 03:41:17  nto
		Last Revision:	Added the datum fallback feature to all datums which
		Last Revision:	rely on grid data files
		Last Revision:	Revision 10.400  2000/09/13 01:16:56  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:27  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:18  nto
		Last Revision:	Revision 10.3  2000/02/11 06:10:24  nto
		Last Revision:	Changed the name of the functions to be consistent, and preserve my sanity.
		Last Revision:	Revision 10.2  1999/11/03 23:41:06  nto
		Last Revision:	Results of datum conversion rewrite.
		Last Revision:	Revision 10.1  1999/10/16 18:53:21  nto
		Last Revision:	Modifications usggested by Gimpel PC-Lint.  No functionality
		Last Revision:	changes.
		Last Revision:	Revision 10.0  1999/10/05 18:27:15  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:26  nto
		Last Revision:	Revision 1.2  1999/09/07 13:55:02  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_hpgn.c#4 $"};
#endif

#include "cs_map.h"

/******************************************************************************
	These are static global variables, represent a possible  multi-threading
	problem.
*/
struct csNad83ToHarn_* csNad83ToHarn = NULL;
int csNad83ToHarnCnt = 0;

/**********************************************************************
**	st = CShpginit ();
**
**	int st;						returns 0 if the initialization proceeded to
**								completion successfully.  Otherwise returns
**								-1.
**********************************************************************/
int EXP_LVL7 CSharnInit (void)
{
	extern char *cs_DirP;
	extern char cs_Dir [];
	extern char cs_HarnName [];

	char catalog [MAXPATH];

	/* See if we already have a csNad83ToHarn object.
	   Note, we can have such even if the count is zero. */
	if (csNad83ToHarn == NULL)
	{
		/* Nope, we best create one. */
		CS_stcpy (cs_DirP,cs_HarnName);
		CS_stncp (catalog,cs_Dir,sizeof (catalog));

		csNad83ToHarn = CSnewNad83ToHarn (catalog);
		if (csNad83ToHarn == NULL)
		{
			goto error;
		}
		csNad83ToHarnCnt = 0;
	}
	csNad83ToHarnCnt += 1;
	return 0;

error:
	if (csNad83ToHarn != NULL)
	{
		CSdeleteNad83ToHarn (csNad83ToHarn);
		csNad83ToHarn = NULL;
	}
	csNad83ToHarnCnt = 0;
	return -1;
}
/**********************************************************************
**	CSharnCls (void);
**
**	NOTE:  This function simply releases the resources, it doesn't
**	delete them.  This is for performance reasons.  This will cause a
**	memory leak message on some debuggers.  If this is undesirable,
**	replace CSreleaseNad83ToHarn with CSdeleteNad83ToHarn below, and
**	set the csNad83ToHarn pointer to NULL.
**********************************************************************/
void EXP_LVL9 CSharnCls (void)
{
	csNad83ToHarnCnt -= 1;
	if (csNad83ToHarnCnt <= 0)
	{
		CSreleaseNad83ToHarn (csNad83ToHarn);
		csNad83ToHarnCnt = 0;

		/**************************************************************
		  Alternative code, commented out.
		CSdeleteNad83ToHarn (csNad83ToHarn);
		csNad83ToHarn = NULL;
		csNad83ToHarnCnt = 0;
		**************************************************************/
	}
	return;
}
/**********************************************************************
**	status = CSnad83ToHarn (ll_harn,ll_83);
**
**	double ll_harn [3];			the converted longitude ([0]) and latitude ([1]) 
**								are returned here.
**	double ll_83 [3];			the longitude ([0]) and the latitude ([1]) to
**								be converted.
**	int status;					returns zero if conversion took place as expected,
**								+1 if conversion did not take place due to a
**								data block error, +2 if the fallback was used
**								successfully, -1 if conversion failed and
**								for any other reason.
**
**	ll_harn and ll_83 may point at the same array.
**
**	In the event of a +1 status return, ll_83 will have been copied
**	to ll_harn.
**
**	There is no way to determine a HGT change.  HGT element is
**	simply copied in all cases.
**********************************************************************/
int EXP_LVL7 CSnad83ToHarn (double ll_harn [3],Const double ll_83 [3])
{
	int status;
	double lcl_harn [3];

	/* Set the default return values.  We need this to allow both input
	   arrays to be the same physical memory. */
	lcl_harn [LNG] = ll_83 [LNG];
	lcl_harn [LAT] = ll_83 [LAT];
	lcl_harn [HGT] = ll_83 [HGT];

	/* Make sure we have been initialized. */
	if (csNad83ToHarn == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
		status = -1;
	}
	else
	{
		status = CScalcNad83ToHarn (csNad83ToHarn,lcl_harn,ll_83);
	}

	/* Return the results. */
	if (status >= 0)
	{
		ll_harn [LNG] = lcl_harn [LNG];
		ll_harn [LAT] = lcl_harn [LAT];
		ll_harn [HGT] = lcl_harn [HGT];
	}
	return status;
}
/**********************************************************************
**	status = CSharnToNad83 (ll_83,ll_harn,err_flg);
**
**	double ll_83 [3];			the converted longitude ([0]) and latitude ([1]) 
**								are returned here.
**	double ll_harn [3];			the longitude ([0]) and the latitude ([1]) to
**								be converted.
**	int err_flg;				indicates what CSharn283 is to do in the event of an
**								error.  See remarks below.
**	int status;					returns zero on a successful conversion, +1
**								in the event of an out of range error, +2 if the
**								fallback was used successfully, -1 for a hard error.
**
**	ll_harn and ll_83 may point at the same array.
**
**	In the event of a +1 status return, ll_harn will have been copied
**	to ll_83.
**********************************************************************/
int EXP_LVL7 CSharnToNad83 (double ll_83 [3],Const double ll_harn [3])
{
	int status;
	double lcl_83 [3];

	/* Set the default return values.  We need this to allow both input
	   arrays to be the same physical memory. */
	lcl_83 [LNG] = ll_harn [LNG];
	lcl_83 [LAT] = ll_harn [LAT];
	lcl_83 [HGT] = ll_harn [HGT];

	/* Make sure we have been initialized. */
	if (csNad83ToHarn == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
		status = -1;
	}
	else
	{
		status = CSinverseNad83ToHarn (csNad83ToHarn,lcl_83,ll_harn);
	}

	/* Return the results. */
	if (status >= 0)
	{
		ll_83 [LNG] = lcl_83 [LNG];
		ll_83 [LAT] = lcl_83 [LAT];
		ll_83 [HGT] = lcl_83 [HGT];
	}
	return status;
}
Const char *EXP_LVL7 CSnad83ToHarnLog (Const double ll_83 [3])
{
	Const char *cp;

	cp = NULL;
	/* Make sure we have been initialized. */
	if (csNad83ToHarn == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
	}
	else
	{
		cp = CSsourceNad83ToHarn (csNad83ToHarn,ll_83);
	}
	return (cp == NULL || *cp == '\0') ? "<unavailable>" : cp;
}
