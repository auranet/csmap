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

			 File Name: $RCSfile: CS_groups.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #4 $
		 Check In Date:	$Date: 2006/11/16 $

		Last Revision:	$Log: CS_groups.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:12  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:12  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:10  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:18  nto
		Last Revision:	Revision 11.901  2004/08/07 20:53:47  nto
		Last Revision:	Added the dictionary deferred close feature.
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
		Last Revision:	Revision 11.300  2003/02/25 04:29:17  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:44  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1501  2002/10/03 00:00:09  nto
		Last Revision:	Removed UNIX I/O in favor of ANSI stream I/O.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:20  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:23  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:17  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:38  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:27  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:11  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:49  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:43  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:21  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:16:55  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:26  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:18  nto
		Last Revision:	Revision 10.1  2000/01/30 23:43:32  nto
		Last Revision:	PCLint cleanup.
		Last Revision:	Revision 10.0  1999/10/05 18:27:14  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:26  nto
		Last Revision:	Revision 1.2  1999/09/07 14:35:10  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_groups.c#4 $"};
#endif

#include "cs_map.h"

/**********************************************************************
**	count = CS_csgrp (grp_key,grp_list);
**
**	char *grp_key;				the specific group key for which a list is to be
**								returned.
**	struct cs_Csgrplst_ *grp_list;
**								a pointer to a linked list of malloc'ed cs_Csgrplst_
**								structures is returned here.
**	int count;					the number of coordinate systems in the returned list
**								is returned.  -1 is returned for an invalid group key.
**********************************************************************/

int EXP_LVL3 CS_csgrp (Const char *grp_key,struct cs_Csgrplst_ **grp_list)
{
	extern struct cs_Prjtab_ cs_Prjtab [];
	extern struct cs_Grptbl_ cs_CsGrptbl [];
	extern char csErrnam [];

	int st;
	int count;
	int crypt;

	csFILE *strm;
	struct cs_Csgrplst_ *lp;
	struct cs_Grptbl_ *tp;
	struct cs_Prjtab_ *pp;

	struct cs_Csdef_ cs_def;

	strm = NULL;
	lp = NULL;					/* initialization to keep gcc happy */
	*grp_list = NULL;
	count = 0;

	/* Verify that the group name is one that we know about. */
	for (tp = cs_CsGrptbl;tp->group [0] != '\0';tp += 1)
	{
		if (!CS_stricmp (tp->group,grp_key)) break;
	}
	if (tp->group [0] == '\0')
	{
		CS_stncp (csErrnam,grp_key,MAXPATH);
	    	CS_erpt (cs_CSGRP_INVKEY);
		goto error;
	}

	/* Generate the list. */
	strm = CS_csopn (_STRM_BINRD);
	if (strm == NULL) goto error;
	while ((st = CS_csrd (strm,&cs_def,&crypt)) == 1)
	{
		if (CS_stricmp (cs_def.group,grp_key)) continue;

		/* Add the new coodinate system to the list. */
		if (*grp_list == NULL)
		{
			*grp_list = CS_malc (sizeof (struct cs_Csgrplst_));
			lp = *grp_list;
		}
		else
		{
			lp->next = CS_malc (sizeof (struct cs_Csgrplst_));	/*lint !e644 */
			lp = lp->next;
		}
		if (lp == NULL)
		{
			CS_erpt (cs_NO_MEM);
			goto error;
		}
		lp->next = NULL;

		/* Locate in the projection table. */
		for (pp = cs_Prjtab;*pp->key_nm != '\0';pp++)
		{
			if (!CS_stricmp (pp->key_nm,cs_def.prj_knm)) break;
		}
		if (*pp->key_nm == '\0' || pp->setup == NULL)
		{
			CS_stncp (csErrnam,cs_def.prj_knm,MAXPATH);
			CS_erpt (cs_UNKWN_PROJ);
			goto error;
		}

		CS_stncp (lp->key_nm,cs_def.key_nm,sizeof (lp->key_nm));
		CS_stncp (lp->descr,cs_def.desc_nm,sizeof (lp->descr));
		CS_stncp (lp->source,cs_def.source,sizeof (lp->source));
		CS_stncp (lp->unit,cs_def.unit,sizeof (lp->unit));

		/* Units are defaultable. This is why we needed the projection
		   table look up. */
		if ((pp->flags & cs_PRJFLG_GEOGR) != 0)
		{
			CSdfltpro (cs_DFLTSW_AU,lp->unit,sizeof (lp->unit));
		}
		else
		{
			CSdfltpro (cs_DFLTSW_LU,lp->unit,sizeof (lp->unit));
		}

		/* Datums and ellipsoids are defaultable as well. */
		if (cs_def.dat_knm [0] != '\0')
		{
			CS_stcpy (lp->ref_typ,"Datum");
			CS_stncp (lp->ref_to,cs_def.dat_knm,sizeof (lp->ref_to));
			CSdfltpro (cs_DFLTSW_DT,lp->ref_to,sizeof (lp->ref_to));
		} 
		else
		{
			CS_stcpy (lp->ref_typ,"Ellipsoid");
			CS_stncp (lp->ref_to,cs_def.elp_knm,sizeof (lp->ref_to));
			CSdfltpro (cs_DFLTSW_EL,lp->ref_to,sizeof (lp->ref_to));
		}
		count += 1;
	}
	if (st != 0) goto error;
	CS_csDictCls (strm);
	return (count);

error:
	if (*grp_list != NULL)
	{
		CS_csgrpf (*grp_list);
		*grp_list = NULL;
	}
	if (strm != NULL) CS_csDictCls (strm);
	return (-1);
}

void EXP_LVL3 CS_csgrpf (struct cs_Csgrplst_ *grp_list)
{
	struct cs_Csgrplst_ *lp;

	while (grp_list != NULL)
	{
		lp = grp_list;
		grp_list = lp->next;
		CS_free (lp);
	}
	return;
}
