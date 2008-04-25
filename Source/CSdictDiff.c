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

			 File Name: $Source: C:/Development/NewCsMap/rcs/CSdictDiff.c $
			 Full Name:
		   Description:
			   Purpose:

		Revision Level:	$Revision: #6 $
				  Date:	$Date: 2007/01/08 $

		 Last Revision:	$Log: CSdictDiff.c $
		 Last Revision:	Revision 11.1300  2005/05/25 23:27:04  nto
		 Last Revision:	Official Release 11.13
		 Last Revision:	Revision 11.1200  2005/01/15 18:27:07  nto
		 Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		 Last Revision:	Revision 11.1100  2004/11/01 18:53:04  nto
		 Last Revision:	Official release 11.11
		 Last Revision:	Revision 11.1001  2004/10/07 19:25:13  nto
		 Last Revision:	Revision 11.900  2004/03/26 17:02:20  nto
		 Last Revision:	Official release: 11.09 - 3/25/2003
		 Last Revision:	Revision 11.800  2004/01/13 23:29:08  nto
		 Last Revision:	Revision 11.700  2003/12/19 01:49:49  nto
		 Last Revision:	Official release 11.07
		 Last Revision:	Revision 11.600  2003/12/04 02:46:24  nto
		 Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		 Last Revision:	Revision 11.501  2003/08/22 21:12:52  nto
		 Last Revision:	Official Release: 11.05
		 Last Revision:	Revision 11.401  2003/05/01 23:06:18  nto
		 Last Revision:	Revision 11.300  2003/02/25 04:29:13  nto
		 Last Revision:	Official Release 11.03
		 Last Revision:	Revision 11.100  2002/11/22 19:38:40  nto
		 Last Revision:	Official release: 11.01
		 Last Revision:	Revision 10.1500  2002/09/22 00:01:16  nto
		 Last Revision:	Official Release:= 10.15
		 Last Revision:	Revision 10.1400  2002/08/09 18:14:19  nto
		 Last Revision:	Revision 10.1200  2002/07/14 03:26:11  nto
		 Last Revision:	Revision 10.1100  2002/06/13 14:18:32  nto
		 Last Revision:	Release 10.11 Official
		 Last Revision:	Revision 10.1000  2002/02/23 21:18:23  nto
		 Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		 Last Revision:	Revision 10.900  2001/09/24 04:31:08  nto
		 Last Revision:	Revision 10.700  2001/01/25 04:13:42  nto
		 Last Revision:	Revision 10.600  2000/12/11 06:39:36  nto
		 Last Revision:	Release 10.06
		 Last Revision:	Revision 10.500  2000/10/27 07:38:13  nto
		 Last Revision:	Official Release 10.05
		 Last Revision:	Revision 10.400  2000/09/13 01:16:48  nto
		 Last Revision:	Release 10.04
		 Last Revision:	Revision 10.301  2000/09/12 21:24:42  nto
		 Last Revision:	Added code to check Affine Coefficient parameters.
		 Last Revision:	Revision 10.300  2000/04/04 23:18:18  nto
		 Last Revision:	Revision 10.200  2000/03/02 18:51:11  nto
		 Last Revision:	Revision 1.3  2000/01/31 00:19:55  nto
		 Last Revision:	Replaced stricmp with CS_stricmp, plus some PCLint clean up.
		 Last Revision:	Revision 1.2  1999/10/09 00:17:04  nto
		 Last Revision:	Releaseable version of these functions.
		 Last Revision:	Revision 1.1  1999/10/08 04:38:58  nto
		 Last Revision:	Initial Revision
		 Last Revision:	Revision 1.1  1999/10/08 03:48:00  nto
		 Last Revision:	Initial Revision

		       * * * * R E M A R K S * * * *

******************************************************************************/

#include "cs_map.h"

static int CScmpPrjParm (FILE* rptStrm,char* key_nm,struct cs_Prjtab_* pp,
									   int prmNbr,
									   double wasValue,
									   double isValue);

int CS_csDiff (FILE *rptStrm,struct cs_Csdef_ *was,struct cs_Csdef_ *is)
{
	extern struct cs_Prjtab_ cs_Prjtab [];		/* Projection Table */

	int flag = TRUE;
	int errCnt = 0;
	double okValue;

	struct cs_Prjtab_ *pp;

	char key_name [64];

	if (strcmp (was->dat_knm,is->dat_knm))
	{
		fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Datum Key Name (dat_knm):\n       was: %s\n    is now: %s\n",was->dat_knm,is->dat_knm);
	}
	if (strcmp (was->elp_knm,is->elp_knm))
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Ellipsoid Key Name (elp_knm):\n       was: %s\n    is now: %s\n",was->elp_knm,is->elp_knm);
	}
	if (strcmp (was->prj_knm,is->prj_knm))
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Projection Key Name (prj_knm):\n       was: %s\n    is now: %s\n",was->prj_knm,is->prj_knm);
	}
	if (strcmp (was->group,is->group))
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Group (group):\n       was: %s\n    is now: %s\n",was->group,is->group);
	}
	if (strcmp (was->locatn,is->locatn))
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Group (group):\n       was: %s\n    is now: %s\n",was->locatn,is->locatn);
	}
	if (strcmp (was->cntry_st,is->cntry_st))
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Political Location (cntry_st):\n       was: %s\n    is now: %s\n",was->cntry_st,is->cntry_st);
	}
	if (strcmp (was->unit,is->unit))
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Unit (unit):\n       was: %s\n    is now: %s\n",was->unit,is->unit);
	}

	/* Look this projection up in the projection table, we need to pass the
	   projection code to the parameter check function. */

	for (pp = cs_Prjtab;pp->key_nm [0] != '\0';pp += 1)
	{
		if (!CS_stricmp (was->prj_knm,pp->key_nm))
		{
			break;
		}
	}

	if (pp->check == NULL)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;

		fprintf (rptStrm,"  %s has an invalid projection code name.",was->prj_knm);
	}
	else
	{
		/* Check all of the parameters. */

		if (flag) CS_stcpy (key_name,was->key_nm);
		else      key_name [0] = '\0';

		errCnt += CScmpPrjParm (rptStrm,key_name,pp, 1,was->prj_prm1 ,is->prj_prm1);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp, 2,was->prj_prm2 ,is->prj_prm2);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp, 3,was->prj_prm3 ,is->prj_prm3);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp, 4,was->prj_prm4 ,is->prj_prm4);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp, 5,was->prj_prm5 ,is->prj_prm5);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp, 6,was->prj_prm6 ,is->prj_prm6);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp, 7,was->prj_prm7 ,is->prj_prm7);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp, 8,was->prj_prm8 ,is->prj_prm8);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp, 9,was->prj_prm9 ,is->prj_prm9);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp,10,was->prj_prm10,is->prj_prm10);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp,11,was->prj_prm11,is->prj_prm11);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp,12,was->prj_prm12,is->prj_prm12);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp,13,was->prj_prm13,is->prj_prm13);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp,14,was->prj_prm14,is->prj_prm14);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp,15,was->prj_prm15,is->prj_prm15);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp,16,was->prj_prm16,is->prj_prm16);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp,17,was->prj_prm17,is->prj_prm17);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp,18,was->prj_prm18,is->prj_prm18);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp,19,was->prj_prm19,is->prj_prm19);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp,20,was->prj_prm20,is->prj_prm20);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp,21,was->prj_prm21,is->prj_prm21);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp,22,was->prj_prm22,is->prj_prm22);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp,23,was->prj_prm23,is->prj_prm23);
		errCnt += CScmpPrjParm (rptStrm,key_name,pp,24,was->prj_prm24,is->prj_prm24);
	}

	okValue = 1.0E-09;
	if (fabs (was->org_lng - is->org_lng) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Origin Longitude (org_lng):\n       was: %18.12f\n    is now: %18.12f\n",was->org_lng,is->org_lng);
	}
	if (fabs (was->org_lat - is->org_lat) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Origin Latitude (org_lat):\n       was: %18.12f\n    is now: %18.12f\n",was->org_lat,is->org_lat);
	}

	okValue = 1.0E-03;
	if (fabs (was->x_off - is->x_off) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  FALSE Easting (x_off):\n       was: %16.6f\n    is now: %16.6f\n",was->x_off,is->x_off);
	}
	if (fabs (was->y_off - is->y_off) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  FALSE Northing (y_off):\n       was: %16.6f\n    is now: %16.6f\n",was->y_off,is->y_off);
	}

	okValue = 1.0E-09;
	if (fabs (was->scl_red - is->scl_red) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Scale Reduction (scl_red):\n       was: %18.12f\n    is now: %18.12f\n",was->scl_red,is->scl_red);
	}

	if (!CS_stricmp (was->prj_knm,"LL"))
	{
		okValue = 1.0E-09;
		if (fabs (was->zero [0] - is->zero [0]) > okValue || fabs (was->zero [1] - is->zero [1]) > okValue)
		{
			if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
			flag = FALSE;
			errCnt += 1;
			fprintf (rptStrm,"  Miinimum Non Zero (zero):\n       was: %14.12f:%14.12f\n    is now: %14.12f:%14.12f\n",was->zero [0],was->zero[1],is->zero [0],is->zero [1]);
		}
	}
	else
	{
		okValue = 1.0E-03;
		if (fabs (was->zero [0] - is->zero [0]) > okValue || fabs (was->zero [1] - is->zero [1]) > okValue)
		{
			if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
			flag = FALSE;
			errCnt += 1;
			fprintf (rptStrm,"  Miinimum Non Zero (zero):\n       was: %8.6f:%8.6f\n    is now: %8.6f:%8.6f\n",was->zero [0],was->zero[1],is->zero [0],is->zero [1]);
		}
	}

	okValue = 1.0E-09;
	if (fabs (was->hgt_lng - is->hgt_lng) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Height Longitude (hgt_lng):\n       was: %18.12f\n    is now: %18.12f\n",was->hgt_lng,is->hgt_lng);
	}
	if (fabs (was->hgt_lat - is->hgt_lat) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Height Latitude (hgt_lat):\n       was: %18.12f\n    is now: %18.12f\n",was->hgt_lat,is->hgt_lat);
	}
	if (fabs (was->hgt_zz - is->hgt_zz) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Height Elevation (hgt_zz):\n       was: %12.6f\n    is now: %12.6f\n",was->hgt_zz,is->hgt_zz);
	}
	if (fabs (was->geoid_sep - is->geoid_sep) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Geoid Separation (geoid_sep):\n       was: %12.6f\n    is now: %12.6f\n",was->geoid_sep,is->geoid_sep);
	}

	okValue = 1.0E-08;
	if (fabs (was->ll_min [0] - is->ll_min [0]) > okValue || fabs (was->ll_min [1] - is->ll_min [1]) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Min Lat/Lng (ll_min):\n       was: %14.8f:%14.8f\n    is now: %14.8f:%14.8f\n",was->ll_min [0],was->ll_min[1],is->ll_min [0],is->ll_min [1]);
	}
	if (fabs (was->ll_max [0] - is->ll_max [0]) > okValue || fabs (was->ll_max [1] - is->ll_max [1]) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Max Lat/Lng (ll_max):\n       was: %14.8f:%14.8f\n    is now: %14.8f:%14.8f\n",was->ll_max [0],was->ll_max[1],is->ll_max [0],is->ll_max [1]);
	}

	okValue = 1.0E-03;
	if (fabs (was->xy_min [0] - is->xy_min [0]) > okValue || fabs (was->xy_min [1] - is->xy_min [1]) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Min X/Y (xy_min):\n       was: %14.4f:%14.4f\n    is now: %14.4f:%14.4f\n",was->xy_min [0],was->xy_min[1],is->xy_min [0],is->xy_min [1]);
	}
	if (fabs (was->xy_max [0] - is->xy_max [0]) > okValue || fabs (was->xy_max [1] - is->xy_max [1]) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Max X/Y (xy_max):\n       was: %14.4f:%14.4f\n    is now: %14.4f:%14.4f\n",was->xy_max [0],was->xy_max[1],is->xy_max [0],is->xy_max [1]);
	}

	if (strcmp (was->desc_nm,is->desc_nm))
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Descriptive Name (desc_nm):\n       was: %s\n    is now: %s\n",was->desc_nm,is->desc_nm);
	}
	if (strcmp (was->source,is->source))
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Source description (source):\n       was: %s\n    is now: %s\n",was->source,is->source);
	}

	if (was->quad != is->quad)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Quadrant (quad):\n       was: %d\n    is now: %d\n",was->quad,is->quad);
	}
	if (was->order != is->order)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Polynomial Order (order):\n       was: %d\n    is now: %d\n",was->order,is->order);
	}
	if (was->zones != is->zones)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Zone Count (zones):\n       was: %d\n    is now: %d\n",was->zones,is->zones);
	}
	if (was->protect != is->protect)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Protection Flag (protect):\n       was: %d\n    is now: %d\n",was->protect,is->protect);
	}
	if (was->auto_geoid != is->auto_geoid)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Automatic Geoid Flag (auto_geoid):\n       was: %d\n    is now: %d\n",was->auto_geoid,is->auto_geoid);
	}
	if (was->elev_tech != is->elev_tech)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Elevation Technique (elev_tech):\n       was: %d\n    is now: %d\n",was->elev_tech,is->elev_tech);
	}
	if (was->epsgNbr != is->epsgNbr)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  EPSG (epsgNbr):\n       was: %d\n    is now: %d\n",was->epsgNbr,is->epsgNbr);
	}
	if (was->wktFlvr != is->wktFlvr)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  WKT Flavor (wktFlvr):\n       was: %d\n    is now: %d\n",was->wktFlvr,is->wktFlvr);
	}
	return errCnt;
}

int CScmpPrjParm (FILE* rptStrm,char* key_nm,struct cs_Prjtab_* pp,int prmNbr,double wasValue,double isValue)
{
	extern struct cs_PrjprmMap_ cs_PrjprmMap [];
	extern struct cs_Prjprm_ csPrjprm [];

	unsigned char parmType;
	int errCnt;
	struct cs_PrjprmMap_ *mapPtr;
	struct cs_Prjprm_ *prmPtr;

	double okValue;

	errCnt = 0;

	/* Get the type of parameter. */

	for (mapPtr = cs_PrjprmMap;mapPtr->prj_code != cs_PRJCOD_END;mapPtr += 1)
	{
		if (mapPtr->prj_code == pp->code) break;
	}
	if (mapPtr->prj_code == cs_PRJCOD_END)
	{
		if (*key_nm != '\0')
		{
			fprintf (rptStrm,"\n%s has changed:\n",key_nm);
			*key_nm = '\0';
		}
		fprintf (rptStrm,"  Projection code did not map.\n");
		errCnt += 1;
		return errCnt;
	}

	/* Locate the parameter type. */

	parmType = mapPtr->prm_types [prmNbr - 1];

	/* See if this parameter is used. */

	if (parmType == 0)
	{
		/* May want to put a test for zero in here. */
		return 0;
	}
	prmPtr = &csPrjprm [parmType];
	
	/* Test the value. */

	switch (prmPtr->log_type) {
	case cs_PRMLTYP_LNG:
	case cs_PRMLTYP_LAT:
		okValue = 1.0E-09;
		if (fabs (wasValue - isValue) > okValue)
		{
			if (*key_nm != '\0')
			{
				fprintf (rptStrm,"\n%s has changed:\n",key_nm);
				*key_nm = '\0';
			}
			fprintf (rptStrm,"  %s (prj_prm%d):\n       was: %18.12f\n    is now: %18.12f\n",
										prmPtr->label,prmNbr,wasValue,isValue);
			errCnt += 1;
		}
		break;

	case cs_PRMLTYP_AZM:
	case cs_PRMLTYP_ANGD:
		okValue = 1.0E-07;
		if (fabs (wasValue - isValue) > okValue)
		{
			if (*key_nm != '\0')
			{
				fprintf (rptStrm,"\n%s has changed:\n",key_nm);
				*key_nm = '\0';
			}
			fprintf (rptStrm,"  %s (prj_prm%d):\n       was: %18.12f\n    is now: %18.12f\n",
										prmPtr->label,prmNbr,wasValue,isValue);
			errCnt += 1;
		}
		break;

	case cs_PRMLTYP_CMPLXC:
		okValue = 1.0E-07;
		if (fabs (wasValue - isValue) > okValue)
		{
			if (*key_nm != '\0')
			{
				fprintf (rptStrm,"\n%s has changed:\n",key_nm);
				*key_nm = '\0';
			}
			fprintf (rptStrm,"  %s (prj_prm%d):\n       was: %18.12f\n    is now: %18.12f\n",
										prmPtr->label,prmNbr,wasValue,isValue);
			errCnt += 1;
		}
		break;

	case cs_PRMLTYP_ZNBR:
		okValue = 0.1;
		if (fabs (wasValue - isValue) > okValue)
		{
			if (*key_nm != '\0')
			{
				fprintf (rptStrm,"\n%s has changed:\n",key_nm);
				*key_nm = '\0';
			}
			fprintf (rptStrm,"  %s (prj_prm%d):\n       was: %4.1f\n    is now: %4.1f\n",
										prmPtr->label,prmNbr,wasValue,isValue);
			errCnt += 1;
		}
		break;

	case cs_PRMLTYP_HSNS:
		okValue = 0.1;
		if (fabs (wasValue - isValue) > okValue)
		{
			if (*key_nm != '\0')
			{
				fprintf (rptStrm,"\n%s has changed:\n",key_nm);
				*key_nm = '\0';
			}
			fprintf (rptStrm,"  %s (prj_prm%d):\n       was: %4.1f\n    is now: %4.1f\n",
										prmPtr->label,prmNbr,wasValue,isValue);
			errCnt += 1;
		}
		break;

	case cs_PRMLTYP_GHGT:
	case cs_PRMLTYP_ELEV:
		okValue = 1.0E-03;
		if (fabs (wasValue - isValue) > okValue)
		{
			if (*key_nm != '\0')
			{
				fprintf (rptStrm,"\n%s has changed:\n",key_nm);
				*key_nm = '\0';
			}
			fprintf (rptStrm,"  %s (prj_prm%d):\n       was: %10.4f\n    is now: %10.4f\n",
										prmPtr->label,prmNbr,wasValue,isValue);
			errCnt += 1;
		}
		break;

	case cs_PRMLTYP_AFCOEF:
		okValue = 1.0E-10;
		if (fabs (wasValue - isValue) > okValue)
		{
			if (*key_nm != '\0')
			{
				fprintf (rptStrm,"\n%s has changed:\n",key_nm);
				*key_nm = '\0';
			}
			fprintf (rptStrm,"  %s (prj_prm%d):\n       was: %.8f\n    is now: %.8f\n",
										prmPtr->label,prmNbr,wasValue,isValue);
			errCnt += 1;
		}
		break;

	case cs_PRMLTYP_XYCRD:
		okValue = 0.001;
		if (fabs (wasValue - isValue) >= okValue)
		{
			if (*key_nm != '\0')
			{
				fprintf (rptStrm,"\n%s has changed:\n",key_nm);
				*key_nm = '\0';
			}
			fprintf (rptStrm,"  %s (prj_prm%d):\n       was: %.3f\n    is now: %.3f\n",
										prmPtr->label,prmNbr,wasValue,isValue);
			errCnt += 1;
		}
		break;

	case cs_PRMLTYP_SCALE:
		okValue = 1.0E-10;
		if (fabs (wasValue - isValue) > okValue)
		{
			if (*key_nm != '\0')
			{
				fprintf (rptStrm,"\n%s has changed:\n",key_nm);
				*key_nm = '\0';
			}
			fprintf (rptStrm,"  %s (prj_prm%d):\n       was: %.8f\n    is now: %.8f\n",
										prmPtr->label,prmNbr,wasValue,isValue);
			errCnt += 1;
		}
		break;
		
	default:
		if (*key_nm != '\0')
		{
			fprintf (rptStrm,"\n%s has a problem:\n",key_nm);
			*key_nm = '\0';
		}
		fprintf (rptStrm,"  Parameter number %d did not map.\n",prmNbr);
		errCnt += 1;
		break;
	}
	return errCnt;
}
int CS_dtDiff (FILE *rptStrm,struct cs_Dtdef_ *was,struct cs_Dtdef_ *is)
{
	int flag = TRUE;
	int errCnt = 0;
	double okValue;

	if (CS_stricmp (was->ell_knm,is->ell_knm))
	{
		fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Ellipsoid Key Name (ell_knm):\n       was: %s\n    is now: %s\n",was->ell_knm,is->ell_knm);
	}
	if (CS_stricmp (was->group,is->group))
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Group (group):\n       was: %s\n    is now: %s\n",was->group,is->group);
	}
	if (CS_stricmp (was->locatn,is->locatn))
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Location (locatn):\n       was: %s\n    is now: %s\n",was->locatn,is->locatn);
	}
	if (CS_stricmp (was->cntry_st,is->cntry_st))
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Political Location (cntry_st):\n       was: %s\n    is now: %s\n",was->cntry_st,is->cntry_st);
	}

	okValue = 1.0E-03;
	if (fabs (was->delta_X - is->delta_X) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Delta X (delta_X):\n       was: %9.3f\n    is now: %9.3f\n",was->delta_X,is->delta_X);
	}
	if (fabs (was->delta_Y - is->delta_Y) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Delta Y (delta_Y):\n       was: %9.3f\n    is now: %9.3f\n",was->delta_Y,is->delta_Y);
	}
	if (fabs (was->delta_Z - is->delta_Z) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Delta Z (delta_Z):\n       was: %9.3f\n    is now: %9.3f\n",was->delta_Z,is->delta_Z);
	}

	okValue = 1.0E-03;
	if (fabs (was->rot_X - is->rot_X) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  X Rotation (rot_X):\n       was: %9.3f\n    is now: %9.3f\n",was->rot_X,is->rot_X);
	}
	if (fabs (was->rot_Y - is->rot_Y) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Y Rotation (rot_Y):\n       was: %9.3f\n    is now: %9.3f\n",was->rot_Y,is->rot_Y);
	}
	if (fabs (was->rot_Z - is->rot_Z) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Z Rotation (rot_Z):\n       was: %9.3f\n    is now: %9.3f\n",was->rot_Z,is->rot_Z);
	}

	okValue = 1.0E-06;
	if (fabs (was->bwscale - is->bwscale) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Scale (bwscale):\n       was: %10.6f\n    is now: %10.6f\n",was->bwscale,is->bwscale);
	}

	if (CS_stricmp (was->name,is->name))
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Descriptive Name (name):\n       was: %s\n    is now: %s\n",was->name,is->name);
	}
	if (CS_stricmp (was->source,is->source))
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Information Source (source):\n       was: %s\n    is now: %s\n",was->source,is->source);
	}

	if (was->protect != is->protect)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Protection (protect):\n       was: %d\n    is now: %d\n",was->protect,is->protect);
	}
	if (was->to84_via != is->to84_via)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Calculation Technique (to84_via):\n       was: %d\n    is now: %d\n",was->to84_via,is->to84_via);
	}
	if (was->epsgNbr != is->epsgNbr)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Epsg Number (epsgNbr):\n       was: %d\n    is now: %d\n",was->epsgNbr,is->epsgNbr);
	}
	return errCnt;
}

int CS_elDiff (FILE *rptStrm,struct cs_Eldef_ *was,struct cs_Eldef_ *is)
{
	int flag = TRUE;
	int errCnt = 0;
	double okValue;

	if (CS_stricmp (was->group,is->group))
	{
		fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Group (group):\n       was: %s\n    is now: %s\n",was->group,is->group);
	}

	okValue = 1.0E-04;
	if (fabs (was->e_rad - is->e_rad) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Equatorial Radius (e_rad):\n       was: %12.3f\n    is now: %12.3f\n",was->e_rad,is->e_rad);
	}
	if (fabs (was->p_rad - is->p_rad) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Polar radius (p_rad):\n       was: %12.3f\n    is now: %12.3f\n",was->p_rad,is->p_rad);
	}

	okValue = 1.0E-12;
	if (fabs (was->flat - is->flat) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Flattening (flat):\n       was: %14.11f\n    is now: %14.11f\n",was->flat,is->flat);
	}
	if (fabs (was->ecent - is->ecent) > okValue)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Eccentricity (ecent):\n       was: %14.11f\n    is now: %14.11f\n",was->ecent,is->ecent);
	}

	if (CS_stricmp (was->name,is->name))
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Descriptive Name (name):\n       was: %s\n    is now: %s\n",was->name,is->name);
	}

	if (CS_stricmp (was->source,is->source))
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Information Source (source):\n       was: %s\n    is now: %s\n",was->source,is->source);
	}

	if (was->protect != is->protect)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Protection (protect):\n       was: %d\n    is now: %d\n",was->protect,is->protect);
	}

	if (was->epsgNbr != is->epsgNbr)
	{
		if (flag) fprintf (rptStrm,"\n%s has changed:\n",is->key_nm);
		flag = FALSE;
		errCnt += 1;
		fprintf (rptStrm,"  Epsg Number (epsgNbr):\n       was: %d\n    is now: %d\n",was->epsgNbr,is->epsgNbr);
	}

	return errCnt;
}
