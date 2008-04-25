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

			 File Name: $RCSfile: CS_defaults.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #3 $
		 Check In Date:	$Date: 2005/07/26 $

		Last Revision:	$Log: CS_defaults.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:08  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:09  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:07  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:15  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:22  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:11  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:51  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:26  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:54  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:20  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:15  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:42  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1500  2002/09/22 00:01:18  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:21  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:13  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:36  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:25  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:09  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:46  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:40  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:18  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:16:52  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:23  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:14  nto
		Last Revision:	Revision 10.0  1999/10/05 18:27:12  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:24  nto
		Last Revision:	Revision 1.2  1999/09/06 18:50:18  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_defaults.c#3 $"};
#endif

#include "cs_map.h"

/**********************************************************************
**	previous = CS_dtdflt  (dflt_dt);
**	previous = CS_eldflt  (dflt_el);
**	previous = CS_undflt  (dflt_un);
**
**	char *dflt_dt;				the name of the datum which is to become the
**								current default datum.
**	char *dflt_el;				the name of the ellipsoid which is to become the
**								current default ellipsoid.
**	char *dflt_un;				the name of the unit which is to become the
**								current default unit.
**	char *previous;				returns a pointer to a static memory array
**								which contains the previous default value.
**								NULL is returned if the provided argument
**								was invalid.
**
**
**	All functions return the NULL pointer if the provided
**	argument was invalid.
**
**	The static memory array to which a pointer is returned is
**	shared by all of these functions.  Thus, value contained
**	in the array pointed to by the return value remains valid
**	until the next call to one of these functions.
**
**	Calling the appropriate function with a NULL pointer, simply
**	returns the current value.  Calling the appropriate function
**	with a pointer to a null string disables the specific default
**	feature.
**********************************************************************/

static char previous [24];

char * EXP_LVL1 CS_dtdflt (Const char *dflt_dt)
{
	extern char csDtDflt [];

	struct cs_Dtdef_ *dtp;

	CS_stncp (previous,csDtDflt,sizeof (previous));

	if (dflt_dt == NULL)
	{
		return (previous);
	}
	if (*dflt_dt == '\0')
	{
		csDtDflt [0] = '\0';
		return (previous);
	}

	/* Verify the value provided is a valid datum name. */

	dtp = CS_dtdef (dflt_dt);
	if (dtp == NULL)
	{
		return (NULL);
	}
	CS_free (dtp);
	CS_stncp (csDtDflt,dflt_dt,cs_KEYNM_DEF);
	return (previous);
}

char * EXP_LVL1 CS_eldflt (Const char *dflt_el)

{
	extern char csElDflt [];

	struct cs_Eldef_ *elp;

	CS_stncp (previous,csElDflt,sizeof (previous));

	if (dflt_el == NULL)
	{
		return (previous);
	}
	if (*dflt_el == '\0')
	{
		csElDflt [0] = '\0';
		return (previous);
	}
	elp = CS_eldef (dflt_el);
	if (elp == NULL)
	{
		return (NULL);
	}
	CS_free (elp);
	CS_stncp (csElDflt,dflt_el,cs_KEYNM_DEF);
	return (previous);
}

char * EXP_LVL1 CS_ludflt (Const char *dflt_lu)

{
	extern char csLuDflt [];

	double unit_scl;

	CS_stncp (previous,csLuDflt,sizeof (previous));

	if (dflt_lu == NULL)
	{
		return (previous);
	}
	if (*dflt_lu == '\0')
	{
		csLuDflt [0] = '\0';
		return (previous);
	}

	unit_scl = CS_unitlu (cs_UTYP_LEN,dflt_lu);
	if (unit_scl == 0.0)
	{
		return (NULL);
	}
	CS_stncp (csLuDflt,dflt_lu,cs_KEYNM_DEF);
	return (previous);
}

char * EXP_LVL1 CS_audflt (Const char *dflt_au)

{
	extern char csAuDflt [];

	double unit_scl;

	CS_stncp (previous,csAuDflt,sizeof (previous));

	if (dflt_au == NULL)
	{
		return (previous);
	}
	if (*dflt_au == '\0')
	{
		csAuDflt [0] = '\0';
		return (previous);
	}

	unit_scl = CS_unitlu (cs_UTYP_ANG,dflt_au);
	if (unit_scl == 0.0)
	{
		return (NULL);
	}
	CS_stncp (csAuDflt,dflt_au,cs_KEYNM_DEF);
	return (previous);
}

int EXP_LVL9 CSdfltpro (int type,char *name,int size)
{
	extern char csDtDflt [];
	extern char csElDflt [];
	extern char csLuDflt [];
	extern char csAuDflt [];

	int status;

	char *cp;
	char *dflt;

	char ctemp [cs_KEYNM_DEF];

	status = FALSE;

	/* Trim leading ans trailing spaces from the name. */

	cp = name;
	while (*cp == ' ') cp += 1;
	if (*cp == '\0') return (status);

	cp = CS_stncp (ctemp,cp,sizeof (ctemp));
	while (*(cp - 1) == ' ') cp -= 1;
	*cp = '\0';
	cp -= 1;

	/* Is the name a defaultable reference. */

	if (ctemp [0] != cs_DFLT_IDNTBEG || *cp != cs_DFLT_IDNTEND)
	{
		return (status);
	}

	/* Select the appropriate default pointer. */

	switch (type) {

	case cs_DFLTSW_DT:  dflt = csDtDflt; break;
	case cs_DFLTSW_EL:  dflt = csElDflt; break;
	case cs_DFLTSW_LU:  dflt = csLuDflt; break;
	case cs_DFLTSW_AU:  dflt = csAuDflt; break;
	default:	    dflt = NULL;
	}

	if (dflt == NULL) return (status);
	if (*dflt == '\0') return (status);

	/* Here if the specific default feature is active.
	   Isolate the base name, without any default wrapping
	   characters, and replace with the replaced
	   delimiters. */

	*cp = '\0';
	CS_stncp (ctemp,(ctemp + 1),sizeof (ctemp));
	status = TRUE;
	*name = cs_DFLT_REPLBEG;
	cp = CS_stncp ((name + 1),dflt,(size - 2));
	*cp++ = cs_DFLT_REPLEND;
	*cp = '\0';
	return (status);
}
