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

			 File Name: $RCSfile: CS_defCmp.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #6 $
		 Check In Date:	$Date: 2007/01/12 $

		Last Revision:	$Log: CS_defCmp.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:08  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:10  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:07  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:15  nto
		Last Revision:	Revision 11.901  2004/10/07 02:36:15  nto
		Last Revision:	Remove case sensitive compares.
		Last Revision:	Revision 11.900  2004/03/26 17:02:23  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:11  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:51  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.601  2003/12/19 01:03:59  nto
		Last Revision:	Added datum and ellipsoid comparison, changed parameters to const.
		Last Revision:	Revision 11.600  2003/12/04 02:46:26  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 1.1  2003/11/24 01:19:04  nto
		Last Revision:	Initial Revision

		       * * * * R E M A R K S * * * *

	Provides comparison functions for checking the veracity of things like
	WKT export/import.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_defCmp.c#6 $"};
#endif

#include "cs_map.h"

/* The following function compares only those portions of a Coordinate System
   definition which affect numeric results.  The number of differences found
   is returned.  Zero return indcates a match.  If the message argument is
   not NULL, and the messageSize argument is greater than one, a description
   of the first difference located is returned. */
int EXP_LVL3 CS_csDefCmp (Const struct cs_Csdef_ *original,Const struct cs_Csdef_ *revised,char* message,size_t messageSize)
{
	extern struct cs_Prjtab_ cs_Prjtab [];		/* Projection Table */
	extern double cs_Six;
	extern double cs_Zero;

	int errCnt = 0;

	struct cs_Prjtab_ *pp;

	double unitsFactor;

	char errMsg [512];

	const struct cs_Csdef_ *lclOrgPtr;
	struct cs_Csdef_ lclOriginal;

	/* Before we get onto this to heavy; we check the projection code of the
	   original and the revised.  If the original is UTM, and the revised is
	   TM, we convert the original from UTM form to TM form.  This eliminates
	   a big headache. */
	lclOrgPtr = original;
	if (!CS_stricmp (original->prj_knm,"UTM") && !CS_stricmp (revised->prj_knm,"TM"))
	{
		/* Convert original to the TM form. */
		memcpy (&lclOriginal,original,sizeof (lclOriginal));
		strcpy (lclOriginal.prj_knm,"TM");
		lclOriginal.prj_prm1 = cs_Six * lclOriginal.prj_prm1 - 183.0;
		lclOriginal.org_lat = cs_Zero;
		unitsFactor = CS_unitlu (cs_UTYP_LEN,lclOriginal.unit);
		lclOriginal.x_off = 500000.0 / unitsFactor;
		lclOriginal.y_off = (lclOrgPtr->prj_prm2 >= 0.0) ? cs_Zero : 10000000.0 / unitsFactor;
		lclOriginal.scl_red = 0.9996;
		lclOriginal.quad = 1;
		lclOrgPtr = &lclOriginal;
	}

	if (lclOrgPtr->dat_knm [0] != '\0')
	{
		if (CS_stricmp (lclOrgPtr->dat_knm,revised->dat_knm))
		{
			if (errCnt == 0)
			{
				sprintf (errMsg,"Datum key name was %s, is now %s",lclOrgPtr->dat_knm,revised->dat_knm);
			}
			errCnt += 1;
		}
	}
	else
	{
		if (CS_stricmp (lclOrgPtr->elp_knm,revised->elp_knm))
		{
			if (errCnt == 0)
			{
				sprintf (errMsg,"Ellipsoid key name was %s, is now %s",lclOrgPtr->elp_knm,revised->elp_knm);
			}
			errCnt += 1;
		}
	}
	if (CS_stricmp (lclOrgPtr->prj_knm,revised->prj_knm))
	{
		if (errCnt == 0)
		{
			sprintf (errMsg,"Projection key name was %s, is now %s",lclOrgPtr->prj_knm,revised->prj_knm);
		}
		errCnt += 1;
	}
	if (CS_stricmp (lclOrgPtr->unit,revised->unit))
	{
		if (errCnt == 0)
		{
			sprintf (errMsg,"Unit name was %s, is now %s",lclOrgPtr->unit,revised->unit);
		}
		errCnt += 1;
	}

	/* If the projection codes don't match, we're in deep do-do.  So, we bag it now
	   if we haven't got a match so far. */
	if (errCnt != 0)
	{
		if (message != 0 && messageSize > 1)
		{
			CS_stncp (message,errMsg,(int)messageSize);
		}
		return errCnt;
	}

	/* Look this projection up in the projection table, we need to pass the
	   projection code to the parameter check function. */
	for (pp = cs_Prjtab;pp->key_nm [0] != '\0';pp += 1)
	{
		if (!CS_stricmp (lclOrgPtr->prj_knm,pp->key_nm))
		{
			break;
		}
	}
	if (pp->check == NULL)
	{
		if (errCnt == 0)
		{
			sprintf (errMsg,"Projection key name is now %s which is invalid.",revised->prj_knm);
		}
		errCnt += 1;
	}
	else
	{
		if (message != NULL && messageSize > 1)
		{
			if (errCnt == 0) *message = '\0';
		}
		else
		{
			CS_stncp (message,errMsg,(int)messageSize);
		}

		/* Check all of the parameters. */
		if (errCnt == 0) errMsg[0] = '\0';
		if (pp->code != cs_PRJCOD_UNITY)
		{
			/* We skip checking the first two parameters for the Unity projection as WKT
			   does not support the longitude range feature. */
			errCnt += CS_defCmpPrjPrm (pp, 1,lclOrgPtr->prj_prm1 ,revised->prj_prm1,errMsg,sizeof (errMsg));
			errCnt += CS_defCmpPrjPrm (pp, 2,lclOrgPtr->prj_prm2 ,revised->prj_prm2,errMsg,sizeof (errMsg));
		}
		errCnt += CS_defCmpPrjPrm (pp, 3,lclOrgPtr->prj_prm3 ,revised->prj_prm3,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp, 4,lclOrgPtr->prj_prm4 ,revised->prj_prm4,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp, 5,lclOrgPtr->prj_prm5 ,revised->prj_prm5,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp, 6,lclOrgPtr->prj_prm6 ,revised->prj_prm6,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp, 7,lclOrgPtr->prj_prm7 ,revised->prj_prm7,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp, 8,lclOrgPtr->prj_prm8 ,revised->prj_prm8,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp, 9,lclOrgPtr->prj_prm9 ,revised->prj_prm9,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp,10,lclOrgPtr->prj_prm10,revised->prj_prm10,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp,11,lclOrgPtr->prj_prm11,revised->prj_prm11,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp,12,lclOrgPtr->prj_prm12,revised->prj_prm12,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp,13,lclOrgPtr->prj_prm13,revised->prj_prm13,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp,14,lclOrgPtr->prj_prm14,revised->prj_prm14,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp,15,lclOrgPtr->prj_prm15,revised->prj_prm15,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp,16,lclOrgPtr->prj_prm16,revised->prj_prm16,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp,17,lclOrgPtr->prj_prm17,revised->prj_prm17,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp,18,lclOrgPtr->prj_prm18,revised->prj_prm18,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp,19,lclOrgPtr->prj_prm19,revised->prj_prm19,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp,20,lclOrgPtr->prj_prm20,revised->prj_prm20,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp,21,lclOrgPtr->prj_prm21,revised->prj_prm21,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp,22,lclOrgPtr->prj_prm22,revised->prj_prm22,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp,23,lclOrgPtr->prj_prm23,revised->prj_prm23,errMsg,sizeof (errMsg));
		errCnt += CS_defCmpPrjPrm (pp,24,lclOrgPtr->prj_prm24,revised->prj_prm24,errMsg,sizeof (errMsg));
	}

	if ((pp->flags & cs_PRJFLG_ORGLAT) == 0)
	{
		if (CS_cmpDbls (lclOrgPtr->org_lat,revised->org_lat) == 0)
		{
			if (errCnt == 0)
			{
				sprintf (errMsg,"Origin Latitude was %14.8f, is now %14.8f",lclOrgPtr->org_lat,revised->org_lat);
			}
			errCnt += 1;
		}
	}
	if ((pp->flags & cs_PRJFLG_ORGLNG) == 0)
	{
		if (CS_cmpDbls (lclOrgPtr->org_lng,revised->org_lng) == 0)
		{
			if (errCnt == 0)
			{
				sprintf (errMsg,"Origin Longitude was %14.8f, is now %14.8f",lclOrgPtr->org_lng,revised->org_lng);
			}
			errCnt += 1;
		}
	}
	if ((pp->flags & cs_PRJFLG_ORGFLS) == 0)
	{
		if (fabs (lclOrgPtr->x_off - revised->x_off) > 0.01)
		{
			if (errCnt == 0)
			{
				sprintf (errMsg,"False easting was %14.3f, is now %14.3f",lclOrgPtr->x_off,revised->x_off);
			}
			errCnt += 1;
		}
		if (fabs (lclOrgPtr->y_off - revised->y_off) > 0.01)
		{
			if (errCnt == 0)
			{
				sprintf (errMsg,"False northing was %14.3f, is now %14.3f",lclOrgPtr->y_off,revised->y_off);
			}
			errCnt += 1;
		}
	}
	if ((pp->flags & cs_PRJFLG_SCLRED) != 0)
	{
		if (CS_cmpDbls (lclOrgPtr->scl_red,revised->scl_red) == 0)
		{
			if (errCnt == 0)
			{
				sprintf (errMsg,"Scale reduction was %12.10f, is now %12.10f",lclOrgPtr->scl_red,revised->scl_red);
			}
			errCnt += 1;
		}
	}
	if (lclOrgPtr->quad != revised->quad)
	{
		if (errCnt == 0)
		{
			sprintf (errMsg,"Quad was %d, is now %d",lclOrgPtr->quad,revised->quad);
		}
		errCnt += 1;
	}

	if (errCnt != 0)
	{
		if (message != 0 && messageSize > 1)
		{
			CS_stncp (message,errMsg,(int)messageSize);
		}
	}

	return errCnt;
}
int EXP_LVL3 CS_defCmpPrjPrm (struct cs_Prjtab_* pp,int prmNbr,double orgValue,double revValue,char *message,size_t messageSize)
{
	extern struct cs_PrjprmMap_ cs_PrjprmMap [];
	extern struct cs_Prjprm_ csPrjprm [];

	int errCnt;
	unsigned char parmType;
	struct cs_PrjprmMap_ *mapPtr;
	struct cs_Prjprm_ *prmPtr;

	char errMsg [512];
	errCnt = 0;

	/* Get the type of parameter. */
	for (mapPtr = cs_PrjprmMap;mapPtr->prj_code != cs_PRJCOD_END;mapPtr += 1)
	{
		if (mapPtr->prj_code == pp->code) break;
	}
	if (mapPtr->prj_code == cs_PRJCOD_END)
	{
		sprintf (errMsg,"Projection code did not map.");
		errCnt += 1;
	}
	else
	{
		/* Locate the parameter type. */
		parmType = mapPtr->prm_types [prmNbr - 1];

		/* See if this parameter is used. */
		if (parmType == 0)
		{
			return 0;
		}
		prmPtr = &csPrjprm [parmType];
		
		/* Do a generic compare of the values and then report any problem. */
		if (CS_cmpDbls (orgValue,revValue) == 0)
		{
			/* they didn't match. */
			sprintf (errMsg,"%s was %16.8f, in now %18.8f",prmPtr->label,orgValue,revValue);
			errCnt += 1;
		}
	}
	if (message != NULL && messageSize > 1 && *message == '\0')
	{
		if (errCnt > 0)
		{
			CS_stncp (message,errMsg,(int)messageSize);
		}
		else
		{
			*message = '\0';
		}
	}
	return errCnt;
}
int EXP_LVL3 CS_dtDefCmp (Const struct cs_Dtdef_ *original,Const struct cs_Dtdef_ *revised,char* message,size_t messageSize)
{
	int errCnt = 0;
	int deltaZeroCount;

	char errMsg [512];

	/* COmpare the ellipsoid reference by name.  There are several ellipsoids that
	   have different names, and are essentially the same, but we don't deal with
	   that issue yet. */
	if (CS_stricmp (original->ell_knm,revised->ell_knm))
	{
		if (errCnt == 0)
		{
			sprintf (errMsg,"Ellipsoid reference on datum named %s do not match.  Ellipsoid was %s, is now %s",original->key_nm,
																											   original->ell_knm,
																											   revised->ell_knm);
		}
		errCnt += 1;
	}

	/* The revised will often get converted to a type cs_DTCTYP_3PARM with zero
	   deltas if it was one of those types that is generally considered to be
	   equivalent with WGS84. */
	deltaZeroCount  = (revised->delta_X == 0.0);
	deltaZeroCount += (revised->delta_Y == 0.0);
	deltaZeroCount += (revised->delta_Z == 0.0);
	if (revised->to84_via == cs_DTCTYP_3PARM && deltaZeroCount == 3)
	{
		/* Essentially, these definitions are the null transformation. */
		if (!(original->to84_via == cs_DTCTYP_WGS84  ||
			  original->to84_via == cs_DTCTYP_NAD83  ||
			  original->to84_via == cs_DTCTYP_WGS84  ||
			  original->to84_via == cs_DTCTYP_GDA94  ||
			  original->to84_via == cs_DTCTYP_NZGD2K ||
			  original->to84_via == cs_DTCTYP_ETRF89 ||
			  original->to84_via == cs_DTCTYP_RGF93)
		   )
		{
			if (errCnt == 0)
			{
				sprintf (errMsg,"Datum transformation method on datum named %s does not match.  Method was %d, is now %d",
																											original->key_nm,
																											original->to84_via,
																											revised->to84_via);
			}
			errCnt += 1;
		}
	}
	else if (original->to84_via == cs_DTCTYP_NAD27 ||
			 original->to84_via == cs_DTCTYP_MREG ||
			 original->to84_via == cs_DTCTYP_WGS72 ||
			 original->to84_via == cs_DTCTYP_HPGN ||
			 original->to84_via == cs_DTCTYP_AGD66 ||
			 original->to84_via == cs_DTCTYP_6PARM ||
			 original->to84_via == cs_DTCTYP_4PARM ||
			 original->to84_via == cs_DTCTYP_AGD84 ||
			 original->to84_via == cs_DTCTYP_NZGD49 ||
			 original->to84_via == cs_DTCTYP_CSRS ||  
			 original->to84_via == cs_DTCTYP_ATS77 ||
			 original->to84_via == cs_DTCTYP_TOKYO ||
			 original->to84_via == cs_DTCTYP_ED50  ||
			 original->to84_via == cs_DTCTYP_DHDN )
	{
		/* The transformations are not really support in WKT.  As long as the
		   datum names match, we consider them to be OK. */
		if (CS_stricmp (original->key_nm,revised->key_nm))
		{
			if (errCnt == 0)
			{
				sprintf (errMsg,"Datum definition key names do not match. Original was %s, is now %s",original->key_nm,revised->key_nm);
			}
			errCnt += 1;
		}
	}
	else if ((original->to84_via ==  cs_DTCTYP_MOLO  && revised->to84_via ==  cs_DTCTYP_MOLO)  ||
			 (original->to84_via ==  cs_DTCTYP_3PARM && revised->to84_via ==  cs_DTCTYP_3PARM) ||
			 (original->to84_via ==  cs_DTCTYP_BURS  && revised->to84_via ==  cs_DTCTYP_BURS)  ||
			 (original->to84_via ==  cs_DTCTYP_7PARM && revised->to84_via ==  cs_DTCTYP_7PARM)
			)
	{
		/* These represent the bulk of the WKT stuff; i.e. the Molodensky and the Seven Parameter.
		   This where the import work happens here.  All definitions of this typ have the 3
		   delta values. */
		if (fabs (original->delta_X - revised->delta_X) > 6.0E-04)
		{
			if (errCnt == 0)
			{
				sprintf (errMsg,"%s: Delta X was %12.3f, is now %12.3f",original->key_nm,original->delta_X,revised->delta_X);
			}
			errCnt += 1;
		}
		if (fabs (original->delta_Y - revised->delta_Y) > 6.0E-04)
		{
			if (errCnt == 0)
			{
				sprintf (errMsg,"%s: Delta Y was %12.3f, is now %12.3f",original->key_nm,original->delta_Y,revised->delta_Y);
			}
			errCnt += 1;
		}
		if (fabs (original->delta_Z - revised->delta_Z) > 6.0E-04)
		{
			if (errCnt == 0)
			{
				sprintf (errMsg,"%s: Delta Z was %12.3f, is now %12.3f",original->key_nm,original->delta_Z,revised->delta_Z);
			}
			errCnt += 1;
		}
		if ((original->to84_via ==  cs_DTCTYP_BURS  && revised->to84_via ==  cs_DTCTYP_BURS)  ||
			(original->to84_via ==  cs_DTCTYP_7PARM && revised->to84_via ==  cs_DTCTYP_7PARM)
		   )
		{
			/* Only the Bursa and Seven Parameter transformations have the rotation and scale
			   values. */
			if (fabs (original->rot_X - revised->rot_X)> 5.0E-04)
			{
				if (errCnt == 0)
				{
					sprintf (errMsg,"%s: X Rotation was %12.3f, is now %12.3f",original->key_nm,original->rot_X,revised->rot_X);
				}
				errCnt += 1;
			}
			if (fabs (original->rot_Y - revised->rot_Y) > 5.0E-04)
			{
				if (errCnt == 0)
				{
					sprintf (errMsg,"%s: Y Rotation was %12.3f, is now %12.3f",original->key_nm,original->rot_Y,revised->rot_Y);
				}
				errCnt += 1;
			}
			if (fabs (original->rot_Z - revised->rot_Z) > 5.0E-04)
			{
				if (errCnt == 0)
				{
					sprintf (errMsg,"%s: Z Rotation was %12.3f, is now %12.3f",original->key_nm,original->rot_Z,revised->rot_Z);
				}
				errCnt += 1;
			}
			if (fabs (original->bwscale - revised->bwscale) > 5.0E-06)
			{
				if (errCnt == 0)
				{
					sprintf (errMsg,"%s: Scale was %12.8f, is now %12.8f",original->key_nm,original->bwscale,revised->bwscale);
				}
				errCnt += 1;
			}
		}
	}
	if (errCnt != 0)
	{
		if (message != 0 && messageSize > 1)
		{
			CS_stncp (message,errMsg,(int)messageSize);
		}
	}
	return errCnt;
}
int EXP_LVL3 CS_elDefCmp (Const struct cs_Eldef_ *original,Const struct cs_Eldef_ *revised,char* message,size_t messageSize)
{
	int errCnt = 0;

	char errMsg [512];

	/* Pretty simple for an ellipsoid. */
	if (fabs (original->e_rad - revised->e_rad) > 6.0E-04)
	{
		if (errCnt == 0)
		{
			sprintf (errMsg,"%s: Equatorial radius was %14.3f, is now %14.3f",original->key_nm,original->e_rad,revised->e_rad);
		}
		errCnt += 1;
	}
	if (fabs (original->p_rad - revised->p_rad) > 6.0E-04)
	{
		if (errCnt == 0)
		{
			sprintf (errMsg,"%s: Polar radius was %14.3f, is now %14.3f",original->key_nm,original->p_rad,revised->p_rad);
		}
		errCnt += 1;
	}
	if (fabs (original->flat - revised->flat) > 5.0E-10)
	{
		if (errCnt == 0)
		{
			sprintf (errMsg,"%s: Flattening was %14.8f, is now %14.8f",original->key_nm,original->flat,revised->flat);
		}
		errCnt += 1;
	}
	if (fabs (original->ecent - revised->ecent) > 5.0E-10)
	{
		if (errCnt == 0)
		{
			sprintf (errMsg,"%s: Eccentricity was %14.8f, is now %14.8f",original->key_nm,original->ecent,revised->ecent);
		}
		errCnt += 1;
	}
	if (errCnt != 0)
	{
		if (message != 0 && messageSize > 1)
		{
			CS_stncp (message,errMsg,(int)messageSize);
		}
	}
	return errCnt;
}
