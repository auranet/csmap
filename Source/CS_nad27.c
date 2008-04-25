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

			 File Name: $RCSfile: CS_nad27.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #4 $
		 Check In Date:	$Date: 2006/11/16 $

		Last Revision:	$Log: CS_nad27.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:15  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:14  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:11  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:20  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:27  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:15  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:55  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:30  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:58  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:24  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:19  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:46  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1502  2002/11/21 00:41:43  nto
		Last Revision:	Added the log/source functions for reporting which file got used in datum conversions.
		Last Revision:	Revision 10.1501  2002/11/13 23:05:35  nto
		Last Revision:	Added grid data file logging for Nad27ToNad83.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:22  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1401  2002/09/17 23:26:05  nto
		Last Revision:	Added the Nad27<->Ats77 stuff.
		Last Revision:	Revision 10.1400  2002/08/09 18:14:24  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:19  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:39  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:28  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:12  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:52  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:46  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.501  2000/12/11 05:16:12  nto
		Last Revision:	Fixed the wrong catalog file name problem.  Can't leave the name in cs_Dir as it gets used in lower modules.
		Last Revision:	Revision 10.500  2000/10/27 07:38:24  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.401  2000/10/27 03:41:17  nto
		Last Revision:	Added the datum fallback feature to all datums which
		Last Revision:	rely on grid data files
		Last Revision:	Revision 10.400  2000/09/13 01:16:58  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:29  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:20  nto
		Last Revision:	Revision 10.4  2000/02/11 06:12:05  nto
		Last Revision:	Added some robustness code.
		Last Revision:	Revision 10.3  2000/01/30 23:55:11  nto
		Last Revision:	Adjusted so that this module does not modify the 3rd element of coordinates. Also, some PCLint clean up.
		Last Revision:	Revision 10.2  1999/11/03 23:41:06  nto
		Last Revision:	Results of datum conversion rewrite.
		Last Revision:	Revision 10.1  1999/10/16 18:54:42  nto
		Last Revision:	Some modifications suggested by Gimpel PC-Lint. No functionality changes.
		Last Revision:	Revision 10.0  1999/10/05 18:27:16  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:27  nto
		Last Revision:	Revision 1.2  1999/09/04 21:23:00  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_nad27.c#4 $"};
#endif

#include "cs_map.h"

/******************************************************************************
	These are static global variables, represent a possible  multi-threading
	problem.
*/
struct csNad27ToNad83_* csNad27ToNad83 = NULL;
int csNad27ToNad83Cnt = 0;

/**********************************************************************
**	st = CSnadInit ();
**
**	int st;						returns 0 if the initialization proceeded to
**								completion successfully.  Otherwise,
**								returns -1.
**********************************************************************/
int EXP_LVL7 CSnadInit (void)
{
	extern char *cs_DirP;
	extern char cs_Dir [];
	extern char cs_NadName [];

	char catalog [MAXPATH];

	/* See if we already have a csNad27ToNad83 object.
	   Note, we can have such even if the count is zero. */
	if (csNad27ToNad83 == NULL)
	{
		/* Nope, we best create one. */
		CS_stcpy (cs_DirP,cs_NadName);
		CS_stncp (catalog,cs_Dir,sizeof (catalog));

		csNad27ToNad83 = CSnewNad27ToNad83 (catalog);
		if (csNad27ToNad83 == NULL)
		{
			goto error;
		}
		csNad27ToNad83Cnt = 0;
	}
	csNad27ToNad83Cnt += 1;
	return 0;

error:
	if (csNad27ToNad83 != NULL)
	{
		CSdeleteNad27ToNad83 (csNad27ToNad83);
		csNad27ToNad83 = NULL;
	}
	csNad27ToNad83Cnt = 0;
	return -1;
}
/**********************************************************************
**	CSnadCls (void);
**
**	NOTE:  This function simply releases the resources, it doesn't
**	delete them.  This is for performance reasons.  This will cause a
**	memory leak message on some debuggers.  If this is undesirable,
**	replace CSreleaseNad27ToNad83 with CSdeleteNad27ToNad83 below, and
**	set the csNad27ToNad83 pointer to NULL.
**********************************************************************/
void EXP_LVL9 CSnadCls (void)
{
	/* If csNad27ToNad83 is null, we should never be called.  However,
	   rather than crash: */
	if (csNad27ToNad83 == NULL)
	{
		csNad27ToNad83Cnt = 0;
		return;
	}

	csNad27ToNad83Cnt -= 1;
	if (csNad27ToNad83Cnt <= 0)
	{
		CSreleaseNad27ToNad83 (csNad27ToNad83);
		csNad27ToNad83Cnt = 0;

		/**************************************************************
		  Alternative code, commented out.
		CSdeleteNad27ToNad83 (csNad27ToNad83);
		csNad27ToNad83 = NULL;
		csNad27ToNad83Cnt = 0;
		**************************************************************/
	}
	return;
}
/**********************************************************************
**	status = CSnad27ToNad83 (ll_83,ll_27);
**
**	double ll_83 [3];			the converted longitude ([0]) and latitude ([1]) 
**								are returned here.
**	double ll_27 [3];			the longitude ([0]) and the latitude ([1]) to
**								be converted.
**	int status;					returns zero if conversion took place as expected,
**								+1 if conversion failed due to out of range
**								error, +2 if the fallback was used successfully,]
**								-1 for all other errors.
**
**	ll_83 and ll_27 may point at the same array.
**
**	In the event of a +1 return value, ll_27 will have been copied
**	to ll_83
**********************************************************************/
int EXP_LVL7 CSnad27ToNad83 (double ll_83 [3],Const double ll_27 [3])
{
	int status;
	double lcl_83 [3];

	/* Set the default return values.  We need this to allow both input
	   arrays to be the same physical memory. */
	lcl_83 [LNG] = ll_27 [LNG];
	lcl_83 [LAT] = ll_27 [LAT];

	/* Make sure we have been initialized. */
	if (csNad27ToNad83 == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
		status = -1;
	}
	else
	{
		status = CScalcNad27ToNad83 (csNad27ToNad83,lcl_83,ll_27);
	}

	/* Return the results. */
	if (status >= 0)
	{
		ll_83 [LNG] = lcl_83 [LNG];
		ll_83 [LAT] = lcl_83 [LAT];
	}
	return status;
}
/**********************************************************************
**	status = CSnad83ToNad27 (ll_27,ll_83,err_flg);
**
**	double ll_27 [3];			the converted longitude ([0]) and latitude ([1]) 
**								are returned here.
**	double ll_83 [3];			the longitude ([0]) and the latitude ([1]) to
**								be converted.
**	int status;					returns zero on a successful conversion, a
**								positive one if a range problem (i.e.
**								outside the range of coverage), +2 if the
**								fallback was used successfully, or -1 for
**								any other type of error.
**
**	ll_27 and ll_83 may point at the same array.
**
**	In the event of a +1 return value, ll_83 will have been copied to
**	ll_27.
**********************************************************************/
int EXP_LVL7 CSnad83ToNad27 (double ll_27 [3],Const double ll_83 [3])
{
	int status;
	double lcl_27 [3];

	/* Set the default return values.  We need this to allow both input
	   arrays to be the same physical memory. */
	lcl_27 [LNG] = ll_83 [LNG];
	lcl_27 [LAT] = ll_83 [LAT];

	/* Make sure we have been initialized. */
	if (csNad27ToNad83 == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
		status = -1;
	}
	else
	{
		status = CSinverseNad27ToNad83 (csNad27ToNad83,lcl_27,ll_83);
	}

	/* Return the results. */
	if (status >= 0)
	{
		ll_27 [LNG] = lcl_27 [LNG];
		ll_27 [LAT] = lcl_27 [LAT];
	}
	return status;
}
Const char * EXP_LVL7 CSnad27ToNad83Log (Const double ll_27 [2])
{
	Const char *cp;

	cp = NULL;
	/* Make sure we have been initialized. */
	if (csNad27ToNad83 == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
	}
	else
	{
		cp = CSsourceNad27ToNad83 (csNad27ToNad83,ll_27);
	}
	return (cp == NULL || *cp == '\0') ? "<unavailable>" : cp;
}
/******************************************************************************
*******************************************************************************
*******************************************************************************
*******************************************************************************
*******************************************************************************
*******************************************************************************
******************************************************************************/
/******************************************************************************
	These are static global variables, represent a possible  multi-threading
	problem.
*/
struct csNad27ToAts77_* csNad27ToAts77 = NULL;
int csNad27ToAts77Cnt = 0;

/**********************************************************************
**	st = CSn27a77Init ();
**********************************************************************/
int EXP_LVL7 CSn27a77Init (void)
{
	extern char *cs_DirP;
	extern char cs_Dir [];
	extern char cs_N27A77Name [];

	char catalog [MAXPATH];

	/* See if we already have a csNad27ToNad83 object.
	   Note, we can have such even if the count is zero. */
	if (csNad27ToAts77 == NULL)
	{
		/* Nope, we best create one. */
		CS_stcpy (cs_DirP,cs_N27A77Name);
		CS_stncp (catalog,cs_Dir,sizeof (catalog));

		csNad27ToAts77 = CSnewNad27ToAts77 (catalog);
		if (csNad27ToAts77 == NULL)
		{
			goto error;
		}
		csNad27ToAts77Cnt = 0;
	}
	csNad27ToAts77Cnt += 1;
	return 0;

error:
	if (csNad27ToAts77 != NULL)
	{
		CSdeleteNad27ToAts77 (csNad27ToAts77);
		csNad27ToAts77 = NULL;
	}
	csNad27ToAts77Cnt = 0;
	return -1;
}
/**********************************************************************
**	CSn27a77Cls (void);
**********************************************************************/
void EXP_LVL9 CSn27a77Cls (void)
{
	/* If csNad27ToAts77 is null, we should never be called.  However,
	   rather than crash: */
	if (csNad27ToAts77 == NULL)
	{
		csNad27ToAts77Cnt = 0;
		return;
	}

	csNad27ToNad83Cnt -= 1;
	if (csNad27ToAts77Cnt <= 0)
	{
		CSreleaseNad27ToAts77 (csNad27ToAts77);
		csNad27ToAts77Cnt = 0;

		/**************************************************************
		  Alternative code, commented out.
		CSdeleteNad27ToNad83 (csNad27ToNad83);
		csNad27ToNad83 = NULL;
		csNad27ToNad83Cnt = 0;
		**************************************************************/
	}
	return;
}
/**********************************************************************
**	status = CSnad27ToAts77 (ll_ats77,ll_nad27);
**********************************************************************/
int EXP_LVL7 CSnad27ToAts77 (double ll_ats77 [3],Const double ll_nad27 [3])
{
	int status;
	double lcl_77 [3];

	/* Set the default return values.  We need this to allow both input
	   arrays to be the same physical memory. */
	lcl_77 [LNG] = ll_nad27 [LNG];
	lcl_77 [LAT] = ll_nad27 [LAT];

	/* Make sure we have been initialized. */
	if (csNad27ToAts77 == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
		status = -1;
	}
	else
	{
		status = CScalcNad27ToAts77 (csNad27ToAts77,lcl_77,ll_nad27);
	}

	/* Return the results. */
	if (status >= 0)
	{
		ll_ats77 [LNG] = lcl_77 [LNG];
		ll_ats77 [LAT] = lcl_77 [LAT];
	}
	return status;
}
/**********************************************************************
**	status = CSats77ToNad27 (ll_nad27,ll_ats77,err_flg);
**********************************************************************/
int EXP_LVL7 CSats77ToNad27 (double ll_nad27 [3],Const double ll_ats77 [3])
{
	int status;
	double lcl_27 [3];

	/* Set the default return values.  We need this to allow both input
	   arrays to be the same physical memory. */
	lcl_27 [LNG] = ll_ats77 [LNG];
	lcl_27 [LAT] = ll_ats77 [LAT];

	/* Make sure we have been initialized. */
	if (csNad27ToAts77 == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
		status = -1;
	}
	else
	{
		status = CScalcAts77ToNad27 (csNad27ToAts77,lcl_27,ll_ats77);
	}

	/* Return the results. */
	if (status >= 0)
	{
		ll_nad27 [LNG] = lcl_27 [LNG];
		ll_nad27 [LAT] = lcl_27 [LAT];
	}
	return status;
}
Const char * EXP_LVL7 CSnad27ToAts77Log (Const double ll_27 [2])
{
	Const char *cp;

	cp = NULL;
	/* Make sure we have been initialized. */
	if (csNad27ToAts77 == NULL)
	{
		CS_erpt (cs_DTC_NO_SETUP);
	}
	else
	{
		cp = CSsourceNad27ToAts77 (csNad27ToAts77,ll_27);
	}
	return (cp == NULL || *cp == '\0') ? "<unavailable>" : cp;
}
