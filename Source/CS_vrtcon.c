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

			 File Name: $RCSfile: CS_vrtcon.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #3 $
		 Check In Date:	$Date: 2005/07/26 $

		Last Revision:	$Log: CS_vrtcon.c $
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
		Last Revision:	Revision 10.200  2000/03/02 18:51:24  nto
		Last Revision:	Revision 1.3  2000/02/11 06:17:29  nto
		Last Revision:	Cosmetic
		Last Revision:	Revision 1.2  2000/01/31 00:11:42  nto
		Last Revision:	COrrected so it works now, removed the 88 to 29 function since it is simply a change in sign.
		Last Revision:	Revision 1.1  2000/01/25 09:10:06  nto
		Last Revision:	Initial Revision

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_vrtcon.c#3 $"};
#endif

#include "cs_map.h"

/******************************************************************************
	These are static global variables, represent a possible  multi-threading
	problem.
*/
struct csVertconUS_* csVertconUS = NULL;
int csVertconUSCnt = 0;

/**********************************************************************
**	st = CSvrtconInit ();
**
**	int st;						returns 0 if the initialization proceeded to
**								completion successfully.  Otherwise,
**								returns -1.
**********************************************************************/
int EXP_LVL7 CSvrtconInit (void)
{
	extern char *cs_DirP;
	extern char cs_Dir [];
	extern char cs_VertconName [];

	/* See if we already have a csVertconUS object.
	   Note, we can have such even if the count is zero. */
	if (csVertconUS == NULL)
	{
		/* Nope, we best create one. */
		CS_stcpy (cs_DirP,cs_VertconName);
		csVertconUS = CSnewVertconUS (cs_Dir);
		if (csVertconUS == NULL)
		{
			goto error;
		}
		csVertconUSCnt = 0;
	}
	csVertconUSCnt += 1;
	return 0;

error:
	if (csVertconUS != NULL)
	{
		CSdeleteVertconUS (csVertconUS);
		csVertconUS = NULL;
	}
	csVertconUSCnt = 0;
	return -1;
}
/**********************************************************************
**	CSvertconCls (void);
**
**	NOTE:  This function simply releases the resources, it doesn't
**	delete them.  This is for performance reasons.  This will cause a
**	memory leak message on some debuggers.  If this is undesirable,
**	replace CSreleaseNad27ToNad83 with CSdeleteNad27ToNad83 below, and
**	set the csNad27ToNad83 pointer to NULL.
**********************************************************************/
void EXP_LVL9 CSvrtconCls (void)
{
	csVertconUSCnt -= 1;
	if (csVertconUSCnt <= 0)
	{
		if (csVertconUS != NULL)
		{
			CSreleaseVertconUS (csVertconUS);
		}
		csVertconUSCnt = 0;

		/**************************************************************
		  Alternative code, commented out.
		CSdeleteVertconUS (csVertconUS);
		csVertconUS = NULL;
		csVertconUSCnt = 0;
		**************************************************************/
	}
	return;
}
/**********************************************************************
**	status = CSvrtcon29To88 (deltaHgt,ll_83);
**
**	double *deltaHgt;			the calculated change in orthometric height
**								is returned here. 
**	double ll_83 [3];			the longitude ([0]) and the latitude ([1]) of
**								the point at which the change in orthometric
**								height is to be determined.
**	int status;					returns zero if conversion took place as expected,
**								+1 if conversion failed due to out of range
**								error, -1 for all other errors.
**
**	In the event of a +1 return value, deltaHgt is set to zero.
**********************************************************************/
int EXP_LVL7 CSvrtcon29To88 (double* deltaHgt,Const double ll_83 [3])
{
	extern double cs_Zero;

	int status;
	double result;

	result = cs_Zero;
	/* Make sure we have been initialized. */
	if (csVertconUS == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
		status = -1;
	}
	else
	{
		/* Note, this function returns the shift in millimeters. */
		status = CScalcVertconUS (csVertconUS,&result,ll_83);
		if (status == 0) result *= 0.001;
	}
	*deltaHgt = result;
	return status;
}
