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

			 File Name: $RCSfile: CS_mrcat.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #5 $
		 Check In Date:	$Date: 2006/11/16 $

		Last Revision:	$Log: CS_mrcat.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:15  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:14  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:11  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:20  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:26  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:15  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:55  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:30  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:57  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:24  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:18  nto
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
		Last Revision:	Revision 10.900  2001/09/24 04:31:12  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:52  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:46  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:23  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:16:58  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.301  2000/09/12 21:01:13  nto
		Last Revision:	Adjusted the manner in which extents are computed.
		Last Revision:	Revision 10.300  2000/04/04 23:18:28  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:20  nto
		Last Revision:	Revision 10.1  2000/01/30 23:52:42  nto
		Last Revision:	PCLint clean up.
		Last Revision:	Revision 10.0  1999/10/05 18:27:16  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:27  nto
		Last Revision:	Revision 1.2  1999/09/04 20:02:26  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_mrcat.c#5 $"};
#endif

#include "cs_map.h"

/*lint -esym(613,err_list) */
/*lint -esym(715,prj_code) */

/**********************************************************************
**	err_cnt = CSmrcatQ (cs_def,prj_code,err_list,list_sz);
**
**	struct cs_Csdef_ *cs_def;	the coordinate system to be checked.
**	unsigned short prj_code;	currently unused.
**	int err_list [];			an array of integers in which error codes are
**								returned if not NULL.
**	int list_sz;				the size of the array pointed to be err_list,
**								may be zero.
**	int err_cnt;				returns the number of errors detected.
**
**	Set err_list to NULL, and/or list_sz to zero, to simply get
**	a yea or nay status of the definition (i.e. err_cnt != 0).
**
**	All lat/longs in definitions must be referenced to Greennwich,
**	and in the range of greater than -180/-90, and less than or
**	equal to +180/+90.
**********************************************************************/

int EXP_LVL9 CSmrcatQ (	Const struct cs_Csdef_ *cs_def,unsigned short prj_code,int err_list [],int list_sz)
{
	extern double cs_MinLng;		/* -180.0 */
	extern double cs_MaxLng;		/* +180.0 */

	int err_cnt;

	/* We will return (err_cnt + 1) below. */

	err_cnt = -1;
	if (err_list == NULL) list_sz = 0;

	/* Check the Mercator specific stuff. */

	if (cs_def->prj_prm1 <= cs_MinLng || cs_def->prj_prm1 > cs_MaxLng)
	{
		if (++err_cnt < list_sz) err_list [err_cnt] = cs_CSQ_ORGLNG;
	}

	/* We use the cosine of the standard parallel quite a lot.  It
	   should not be zero.  The value 80 is an arbitrary value which
	   should several times larger than any normal value.  Theoreticaly,
	   this value could be 89. */
   
	if (cs_def->prj_prm2 <= -80.0 || cs_def->prj_prm2 >= 80.0)
	{
		if (++err_cnt < list_sz) err_list [err_cnt] = cs_CSQ_STDLAT;
	}

	/* That's it for Mercator. */

	return (err_cnt + 1);
}

/**********************************************************************
**	(void) CSmrcatS (csprm);
**
**	struct cs_Csprm_ *csprm;	structure containing all coordinate
**								system parameters.
**
**	Normal conventions and Mentor standards have NOT
**	been followed in codng this function so that the
**	variable nomenclature could adhere as closely
**	as possible to that used in the reference.
**********************************************************************/

void EXP_LVL9 CSmrcatS (struct cs_Csprm_ *csprm)
{
	extern short cs_QuadMin;			/* -4 */
	extern short cs_QuadMap [];
	extern double cs_Zero;
	extern double cs_Half;				/* 0.5 */
	extern double cs_One;				/* 1.0 */
	extern double cs_Degree;			/* 1.0 / 57.29577... */
	extern double cs_Radian;			/* 57.29577... */
	extern double cs_NPTest;			/* .001 seconds of arc
										   short of the north pole,
										   in radians. */
	extern double cs_Km180;				/* -180.0 */
	extern double cs_K180;				/*  180.0 */
	extern double cs_Km90;				/* -90.0  */
	extern double cs_K90;				/*  90.0  */

	struct cs_Mrcat_ *mrcat;

	double sin_sp;
	double tmp1;

	double ll_test [3];
	double xy_test [3];

	mrcat = &csprm->proj_prms.mrcat;

	mrcat->cent_lng = csprm->csdef.prj_prm1 * cs_Degree;
	mrcat->x_off = csprm->csdef.x_off;
	mrcat->y_off = csprm->csdef.y_off;
	mrcat->k = csprm->csdef.scale;
	mrcat->ecent = csprm->datum.ecent;
	mrcat->e_sq = mrcat->ecent * mrcat->ecent;
	mrcat->quad = cs_QuadMap [csprm->csdef.quad - cs_QuadMin];

	/* Handle the two (currently) variations to this projection. */

	switch (csprm->prj_code) {

	default:
	case cs_PRJCOD_MRCAT:
		/* Here for the normal case, a standard parallel, usually zero. */
		mrcat->std_lat = csprm->csdef.prj_prm2 * cs_Degree;
		mrcat->cos_sp = cos (mrcat->std_lat);
		if (mrcat->ecent != 0.0)
		{
			sin_sp = sin (mrcat->std_lat);
			tmp1 = cs_One - (mrcat->e_sq * sin_sp * sin_sp);
			mrcat->cos_sp /= sqrt (tmp1);
		}
		break;

	case cs_PRJCOD_MRCATK:
		/* Here for the scale reduction case. */
		mrcat->cos_sp = csprm->csdef.scl_red;
		break;
	}

	/* Compute the maximum Y value, i.e. the value we will use
	   for the poles rather than the technically correct
	   infinite value. */

	/* We need to do a little extra for the ellipsoidal case. */

	if (mrcat->ecent != 0.0)
	{
		/* Set up the latitude power series coefficients. */
		CSchiIsu (&mrcat->chicofI,mrcat->e_sq);
	}

	/* The following apply for either form. */

	mrcat->Rk = csprm->datum.e_rad * mrcat->k;
	mrcat->Rk_ovr_2 = mrcat->Rk * cs_Half;
	mrcat->Rfact = mrcat->Rk * mrcat->cos_sp;
	mrcat->Rfact_2 = mrcat->Rfact * cs_Half;

	/* Compute the maximum Y value, i.e. the value we will use
	   for the poles rather than the technically correct
	   infinite value.  Since the setup is just about complete,
	   we can use the CSmrcatF function to do this. */

	ll_test [LNG] = mrcat->cent_lng;
	ll_test [LAT] = cs_NPTest * cs_Radian;
	CSmrcatF (mrcat,xy_test,ll_test);			/*lint !e534 */
	mrcat->yy_max = xy_test [YY];

	/* Setup the range checking.  Note, these values are considered
	   to be useful range values. */

	csprm->cent_mer = mrcat->cent_lng * cs_Radian;
	if (csprm->csdef.ll_min [LNG] == 0.0 &&
	    csprm->csdef.ll_min [LNG] == 0.0)
	{
		/* Here if the definition does not specify; we calculate
		   some reasonable values. */
		csprm->cent_mer = cs_Zero;
		csprm->min_ll [LNG] = cs_Km180;
		csprm->max_ll [LNG] = cs_K180;
		csprm->min_ll [LAT] = cs_Km90;
		csprm->max_ll [LAT] = cs_K90;
	}
	else
	{
		/* Use whatever the user provides, without checking.
		   The user specifies values in absolute terms. */
		csprm->min_ll [LNG] = CS_adj180 (csprm->csdef.ll_min [LNG] - csprm->cent_mer);
		csprm->min_ll [LAT] = csprm->csdef.ll_min [LAT];
		csprm->max_ll [LNG] = CS_adj180 (csprm->csdef.ll_max [LNG] - csprm->cent_mer);
		csprm->max_ll [LAT] = csprm->csdef.ll_max [LAT];
	}

	/* Similarly with the X's and Y's */

	if (csprm->csdef.xy_min [XX] == 0.0 &&
	    csprm->csdef.xy_max [YY] == 0.0)
	{
		/* Here if the definition does not specify; we calculate
		   some reasonable values.  This is one of the few
		   projections where the following works; i.e. both
		   meridians and parallels ae straight lines. */

		ll_test [LNG] = csprm->min_ll [LNG];
		ll_test [LAT] = csprm->min_ll [LAT];
		CSmrcatF (mrcat,xy_test,ll_test);			/*lint !e534 */
		csprm->min_xy [XX] = xy_test [XX] - mrcat->x_off;
		csprm->min_xy [YY] = xy_test [YY] - mrcat->y_off;

		ll_test [LNG] = csprm->max_ll [LNG];
		ll_test [LAT] = csprm->max_ll [LAT];
		CSmrcatF (mrcat,xy_test,ll_test);			/*lint !e534 */
		csprm->max_xy [XX] = xy_test [XX] - mrcat->x_off;
		csprm->max_xy [YY] = xy_test [YY] - mrcat->y_off;

		CS_quadMM (csprm->min_xy,csprm->max_xy,mrcat->x_off,
											   mrcat->y_off,
											   mrcat->quad);
	}
	else
	{
		/* Use whatever the user provides, without checking. */

		csprm->min_xy [XX] = csprm->csdef.xy_min [XX];
		csprm->min_xy [YY] = csprm->csdef.xy_min [YY];
		csprm->max_xy [XX] = csprm->csdef.xy_max [XX];
		csprm->max_xy [YY] = csprm->csdef.xy_max [YY];
	}

	/* That's all the calculations we can do at this time.
	   The projection is conformal, so ha nd k scale
	   factors are the same. */

	csprm->ll2cs    = (cs_LL2CS_CAST)CSmrcatF;
	csprm->cs2ll    = (cs_CS2LL_CAST)CSmrcatI;
	csprm->cs_scale = (cs_SCALE_CAST)CSmrcatK;
	csprm->cs_sclk  = (cs_SCALK_CAST)CSmrcatK;
	csprm->cs_sclh  = (cs_SCALH_CAST)CSmrcatK;
	csprm->cs_cnvrg = (cs_CNVRG_CAST)CSmrcatC;
	csprm->llchk    = (cs_LLCHK_CAST)CSmrcatL;
	csprm->xychk    = (cs_XYCHK_CAST)CSmrcatX;

	return;
}

/**********************************************************************
**	rtn_val = CSmrcatF (mrcat,xy,ll);
**
**	struct cs_Mrcat_ *mrcat;	structure containing all parameters necessary
**								for the transformation.
**	double xy [2];				converted values are returned here, X ([0])
**								and Y ([1]).
**	double ll [2];				the longitude ([0]) and latitude ([1]) values
**								to be converted, in degrees.
**	int rtn_val;				returns cs_CNVRT_NRML if result is normal;
**								cs_CNVRT_RNG if value to be converted is
**								outside of mathematical scope of the
**								projection.
**
**	The ll and the xy arrays may share the same memory
**	with no adverse affects.
**********************************************************************/

int EXP_LVL9 CSmrcatF (Const struct cs_Mrcat_ *mrcat,double xy [2],Const double ll [2])
{
	extern double cs_One;				/* 1.0 */
	extern double cs_Degree;			/* 1.0 / 57.29577... */
	extern double cs_Two_pi;			/* 2 pi */
	extern double cs_Pi;				/*  Pi, i.e. 3.14159 */
	extern double cs_NPTest;			/* 0.001 arc seconds
										   short of the north
										   pole in radians. */
	extern double cs_SPTest;			/* 0.001 arc seconds
										   short of the south
										   pole in radians. */

	int rtn_val;

	double lng;
	double lat;
	double del_lng;

	double sin_lat;
	double esin_lat;

	double tmp1;
	double tmp2;

	rtn_val = cs_CNVRT_NRML;
	lng = ll [0] * cs_Degree;
	lat = ll [1] * cs_Degree;

	/* Deal with X, it's easy. */

	lng = cs_Degree * ll [LNG];
	del_lng = lng - mrcat->cent_lng;
	if      (del_lng >  cs_Pi) del_lng -= cs_Two_pi;
	else if (del_lng < -cs_Pi) del_lng += cs_Two_pi;
	if (fabs (del_lng) >= cs_Pi)
	{
		rtn_val = cs_CNVRT_RNG;
		del_lng = CS_adj2pi (del_lng);
	}
	xy [XX] = mrcat->Rfact * del_lng;

	/* Bogus values of latitude can cause big problems. */

	if (fabs (lat) > cs_NPTest)
	{
		rtn_val = cs_CNVRT_RNG;
		lat = CS_adj1pi (lat);
		if (lat > cs_NPTest)
		{
			lat = cs_NPTest;
		}
		if (lat < cs_SPTest)
		{
			lat = cs_SPTest;
		}
	}

	/* We should be OK now. */

	sin_lat = sin (lat);
	tmp1 = (cs_One + sin_lat) / (cs_One - sin_lat);

	if (mrcat->ecent == 0.0)
	{
		/* Here for a sphere. */
		
		xy [YY] = mrcat->Rfact_2 * log (tmp1);
	}
	else
	{
		/* Here for an ellipsoid. */

		esin_lat = mrcat->ecent * sin_lat;
		tmp2 = (cs_One - esin_lat) / (cs_One + esin_lat);
		tmp2 = tmp1 * pow (tmp2,mrcat->ecent);
		xy [YY] = mrcat->Rfact_2 * log (tmp2);
	}

	if (mrcat->quad == 0)
	{
		xy [XX] += mrcat->x_off;
		xy [YY] += mrcat->y_off;
	}
	else
	{
		CS_quadF (xy,xy [XX],xy [YY],mrcat->x_off,mrcat->y_off,mrcat->quad);
	}

	return (rtn_val);
}

/**********************************************************************
**	rtn_val = CSmrcatI (mrcat,ll,xy);
**
**	struct cs_Mrcat_ *mrcat;	structure detailing the Mercator coordinate
**								system in use.
**	double ll [2];				converted results returned here, longitude ([0])
**								and latitude ([1]), in degrees.
**	double xy [2];				coordinates to be converted are obtained from
**								this array, X ([0]) and Y ([1]).
**	int rtn_val;				returns cs_CNVRT_NRML if result is normal;
**								cs_CNVRT_RNG if value to be converted is
**								outside of mathematical scope of the
**								projection.
**
**	The xy and ll arrays may share the same memory.
**********************************************************************/

int EXP_LVL9 CSmrcatI (Const struct cs_Mrcat_ *mrcat,double ll [2],Const double xy [2])
{
	extern double cs_Radian;			/* 57.29577... */
	extern double cs_Pi_o_2;			/* Pi / 2.0 */
	extern double cs_3Pi_o_2;			/* 3 Pi / 2.0 */
	extern double cs_Two;				/* 2.0 */

	int rtn_val;

	double xx;
	double yy;

	double chi;
	double lat;
	double del_lng;
	double tmp1;

	rtn_val = cs_CNVRT_NRML;

	/* Remove whatever offsets are active. */

	if (mrcat->quad == 0)
	{
		xx = xy [XX] - mrcat->x_off;
		yy = xy [YY] - mrcat->y_off;
	}
	else
	{
		CS_quadI (&xx,&yy,xy,mrcat->x_off,mrcat->y_off,mrcat->quad);
	}

	/* Check the Y value for range. */

	if (fabs (yy) > mrcat->yy_max)
	{
		rtn_val = cs_CNVRT_RNG;
		yy = (yy >= 0.0) ? mrcat->yy_max : -mrcat->yy_max;
	}

	/* The longitude calculation is the same for both the
	   spherical and ellipsoidal cases.  There may be a
	   slight difference if the standard parallel is not
	   the equator, but tis is taken care of during set up
	   and shows up in the Rfact variable. */

	del_lng = xx / mrcat->Rfact;
	if (fabs (del_lng) >= cs_3Pi_o_2)
	{
	    	rtn_val = cs_CNVRT_RNG;
		del_lng = CS_adj2pi (del_lng);
	}

	/* The following is used for sphere and ellipsoid. */

	tmp1 = exp (-yy / mrcat->Rfact);
	chi = cs_Pi_o_2 - cs_Two * atan (tmp1);

	/* Finish off the latitude as appropriate. */

	if (mrcat->ecent == 0.0)
	{
		/* Here for a sphere. */

		lat = chi;
	}
	else
	{
		/* Here for an ellipsoid.  This is a series
		   expansion used in other projections, so we
		   have a function to do this for us. */

		lat = CSchiIcal (&mrcat->chicofI,chi);
	}

	ll [LNG] = (del_lng + mrcat->cent_lng) * cs_Radian;
	ll [LAT] = lat * cs_Radian;
	return (rtn_val);
}

/**********************************************************************
**	cnvrg = CSmrcatK (mrcat,ll);
**
**	struct cs_Mrcat_ *mrcat;	structure containing all parameters necessary
**								for the transformation.
**	double ll [2];				location of the point to be computed is given
**								here; longitude ([0]) and latitude ([1]) in
**			degrees.
**	double cnvrg;				the convergence angle of the projection at the
**								specified point.
**
**	I wish they they we all this easy.
**********************************************************************/

double EXP_LVL9 CSmrcatC (Const struct cs_Mrcat_ *mrcat,Const double ll [2])
{
	extern double cs_Zero;			/* 0.0 */

	/* Since all meridians are parallel with the central
	   meridian and the Y axis, the convergence angle is
	   zero for all locations. */

	return (cs_Zero);
}							/*lint !e715 */

/**********************************************************************
**	kk = CSmrcatK (mrcat,ll);
**
**	struct cs_Mrcat_ *mrcat;	structure containing all parameters necessary
**								for the transformation.
**	double ll [2];				location of the point to be computed is given
**								here; longitude ([0]) and latitude ([1]) in
**			degrees.
**	double kk;				the true map scale factor at the specified point.
**								Should be compared with the mrcat->k.
**********************************************************************/

double EXP_LVL9 CSmrcatK (Const struct cs_Mrcat_ *mrcat,Const double ll [2])
{
	extern double cs_Degree;			/* 1.0 / 57.29577... */
	extern double cs_One;				/* 1.0 */
	extern double cs_SclInf;			/* 9.9E+04, the value we
										   return for infinite
										   scale. */
	extern double cs_NPTest;			/* .001 arc second short
										   of the north pole in
										   radians. */

	double kk;
	double lat;

	double cos_lat;
	double sin_lat;
	double tmp1;

	lat = ll [LAT] * cs_Degree;

	if (fabs (lat) > cs_NPTest)
	{
		kk = cs_SclInf;
	}
	else
	{
		cos_lat = cos (lat);

		/* cos_lat should never be zero here. */

		if (mrcat->ecent == 0.0)
		{
			/* A sphere. */

			kk = mrcat->cos_sp / cos_lat;
		}
		else
		{
			/* An ellipsoid. */

			sin_lat = sin (lat);
			tmp1 = cs_One - (mrcat->e_sq * sin_lat * sin_lat);
			kk = mrcat->cos_sp * sqrt (tmp1) / cos_lat;
		}
		if (kk > cs_SclInf) kk = cs_SclInf;
	}
	return (kk);
}

/**********************************************************************
**	status = CSmrcatL (mrcat,cnt,pnts);
**
**	struct cs_Mrcat_ *mrcat;	the coordinate system against which the check is
**								to be performed.
**	int cnt;					the number of points in the region to be
**								checked.
**	double pnts [][2];			the list of coordinates to be checked.
**	int status;					returns cs_CNVRT_OK if the point, line, or region
**								is completely within the domain of the
**								coordinate system.  Otherwise, cs_CNVRT_DOMN
**								is returned.
**
**	This function simply checks the mathematical viability of
**	a coordinate conversion.  It has nothing to do with the
**	useful limits of the coordinate system.
**
**	This function expects that the input lat/longs are normalized
**	if appropriate.
**********************************************************************/

int EXP_LVL9 CSmrcatL (Const struct cs_Mrcat_ *mrcat,int cnt,Const double pnts [][3])

{
	extern double cs_Degree;
	extern double cs_NPTest;			/* .001 seconds of arc less
										   than the North pole in
										   radians. */
	int ii;
	int status;

	double lat;

	/* Check all the points.  As long as none have a latitude
	   beyond either pole, we're OK. */

	status = cs_CNVRT_OK;
	for (ii = 0;ii < cnt && status == cs_CNVRT_OK;ii++)
	{
		lat = pnts [ii][LAT] * cs_Degree;
		if (fabs (lat) > cs_NPTest)
		{
			status = cs_CNVRT_DOMN;
			break;
		}
	}
	return (status);

	/* No special test are required for lines and or regions. */
}							/*lint !e715 */

/**********************************************************************
**	status = CSmrcatX (mrcat,cnt,pnts);
**
**	struct cs_Mrcat_ *mrcat;	coordinate system definition
**	int cnt;					number of points in the pnts array.
**	double pnts [][3];			an array of three dimensional points which
**								define a point, line, or region to be checked.
**	int status;					returns the status of the check; see remarks
**								below.
**
**	The values provided in the pnts array are required to be
**	cartesian coordinates.  Use CSmrcatL to check lat/long
**	values.
**
**	What gets checked depends upon the cnt argument.  A value
**	of zero (or less than that) checks nothing successfully.
**	A value of 1 indicates that a single point is to be checked.
**	a value of 2 indicates that a line is to be checked.  The
**	entire line must reside within the domain of the coordinate
**	system to pass.
**
**	A value of 4 or more for cnt indicates that a region is to
**	be checked.  The pnts array must contain the indicated
**	number of points which defines a region.  The last point
**	in the array must duplicate the first point.  The resulting
**	polygon must be simply connected (no bow ties).  The region
**	passes if the entire region is within the domain of the
**	coordinate system.
**
**	The return value refers to either the point, or the line
**	segment, provided. Return values are as follows:
**
**	cs_CNVRT_OK	the point, entire line segment, or entire region,
**			is within the catresian domain of the coordinate
**			system.
**	cs_CNVRT_DOMN	the point, all or a portion of the line segment,
**			or all or a portion of the region, is not within
**			the cartesian domain of the coordinate system.
**********************************************************************/

int EXP_LVL9 CSmrcatX (Const struct cs_Mrcat_ *mrcat,int cnt,Const double pnts [][3])
{
	int ii;
	int rtn_val;

	double test_val;
	double dummy;

	rtn_val = cs_CNVRT_OK;

	/* All X values are within the domain of the function.  However,
	   in the cartesian frame of reference, an absolute value of
	   Y greater than yy_max is outside of the domain. */

	for (ii = 0;ii < cnt && rtn_val == cs_CNVRT_OK;ii++)
	{
		if (mrcat->quad == 0)
		{
			test_val = pnts [ii][YY] - mrcat->y_off;
		}
		else
		{
			CS_quadI (&test_val,&dummy,pnts [ii],mrcat->x_off,
												 mrcat->y_off,
												 mrcat->quad);
		}

		if (fabs (test_val) > mrcat->yy_max)
		{
			rtn_val = cs_CNVRT_DOMN;
			break;
		}
	}
	return (rtn_val);
}
