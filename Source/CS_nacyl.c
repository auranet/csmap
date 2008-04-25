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

			 File Name: $RCSfile: CS_nacyl.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #3 $
		 Check In Date:	$Date: 2005/07/26 $

		Last Revision:	$Log: CS_nacyl.c $
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
		Last Revision:	Revision 11.501  2003/08/22 21:12:58  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:24  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:19  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:46  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1501  2002/11/12 04:22:27  nto
		Last Revision:	Use the new high precision beta inverse.
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
		Last Revision:	Revision 10.500  2000/10/27 07:38:24  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:16:58  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:29  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:20  nto
		Last Revision:	Revision 10.1  2000/01/30 23:54:00  nto
		Last Revision:	PCLint clean up.
		Last Revision:	Revision 10.0  1999/10/05 18:27:16  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:27  nto
		Last Revision:	Revision 1.2  1999/09/04 20:26:06  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_nacyl.c#3 $"};
#endif

#include "cs_map.h"

/*lint -esym(613,err_list) */
/*lint -esym(715,prj_code) */

/**********************************************************************
**	err_cnt = CSnacylQ (cs_def,prj_code,err_list,list_sz);
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

int EXP_LVL9 CSnacylQ (	Const struct cs_Csdef_ *cs_def,unsigned short prj_code,int err_list [],int list_sz)
{
	extern double cs_MinLng;		/* -180.0 */
	extern double cs_MaxLng;		/* +180.0 */

	int err_cnt;

	/* We will return (err_cnt + 1) below. */
	
	err_cnt = -1;
	if (err_list == NULL) list_sz = 0;

	/* Check the Normal Aspect, Equal Area Cylindrical specific stuff. */
	
	if (cs_def->org_lng <= cs_MinLng || cs_def->org_lng > cs_MaxLng)
	{
		if (++err_cnt < list_sz) err_list [err_cnt] = cs_CSQ_ORGLNG;
	}
	
	/* We use the cosine of the standard parallel quite a lot.  It
	   should not be zero.  The value 80 is an arbitrary value which
	   should several times larger than any normal value.  Theoreticaly,
	   this value could be 89. */
	   
	if (cs_def->prj_prm1 <= -80.0 || cs_def->prj_prm1 >= 80.0)
	{
		if (++err_cnt < list_sz) err_list [err_cnt] = cs_CSQ_STDLAT;
	}

	/* That's it for Normal Aspect, Equal Area Cylindrical. */
	
	return (err_cnt + 1);
}

/**********************************************************************
**	(void) CSnacylS (csprm);
**
**	struct cs_Csprm_ *csprm;	structure containing all coordinate
**								system parameters.
**********************************************************************/

void EXP_LVL9 CSnacylS (struct cs_Csprm_ *csprm)
{
	extern short cs_QuadMin;			/* -4 */
	extern short cs_QuadMap [];
	extern double cs_Radian;			/*   57.29577... */
	extern double cs_Degree;			/*    1.0 / 57.29577... */
	extern double cs_Pi;				/*    3.14159... */
	extern double cs_Pi_o_2;			/*   Pi over 2 */
	extern double cs_One;				/*    1.0 */
	extern double cs_Two;				/*    2.0 */
	extern double cs_K180;				/*  180.0 */
	extern double cs_Km180;				/* -180.0 */
	extern double cs_K90;				/*   90.0 */
	extern double cs_Km90;				/*  -90.0 */

	struct cs_Nacyl_ *nacyl;

	double qp;
	double tmp1;
	double tmp2;

	nacyl = &csprm->proj_prms.nacyl;

	nacyl->org_lng = csprm->csdef.org_lng * cs_Degree;
	nacyl->std_lat = csprm->csdef.prj_prm1 * cs_Degree;
	nacyl->x_off = csprm->csdef.x_off;
	nacyl->y_off = csprm->csdef.y_off;
	nacyl->e_rad = csprm->datum.e_rad;
	nacyl->ecent = csprm->datum.ecent;
	nacyl->e_sq = nacyl->ecent * nacyl->ecent;
	nacyl->k = csprm->csdef.scale;
	nacyl->ka = csprm->csdef.scale * nacyl->e_rad;
	nacyl->one_m_esq = cs_One - nacyl->e_sq;
	nacyl->quad = cs_QuadMap [csprm->csdef.quad - cs_QuadMin];

	/* The following is a valid result for the spherical case, and
	   is a neccessary calculation for the elliipsoidal case. */

	nacyl->cos_std_lat = cos (nacyl->std_lat);

	/* We need to do a little extra for the ellipsoidal case. */

	if (nacyl->ecent == 0.0)
	{
		/* Here for the sphere. */

		nacyl->ka_cosst = nacyl->ka * nacyl->cos_std_lat;
		nacyl->ka_o_cosst = nacyl->ka / nacyl->cos_std_lat;
		nacyl->cosst_o_ka = nacyl->cos_std_lat / nacyl->ka;

		nacyl->max_xx = cs_Pi * nacyl->ka_cosst;
		nacyl->max_yy = cs_Pi_o_2 * nacyl->ka_o_cosst;
	}
	else
	{
		/* For the ellipsoid. */

		tmp1 = sin (nacyl->std_lat);
		tmp2 = cs_One - nacyl->e_sq * tmp1 * tmp1;
		nacyl->k0 = nacyl->cos_std_lat / sqrt (tmp2);
		nacyl->kak0 = nacyl->ka * nacyl->k0;
		nacyl->one_o_kak0 = cs_One / (nacyl->kak0);
		nacyl->ka_o_2k0 = nacyl->ka / (nacyl->k0 + nacyl->k0);

		nacyl->one_o_2e = cs_One / (cs_Two * nacyl->ecent);

		tmp1 = (cs_One - nacyl->ecent) / (cs_One + nacyl->ecent);
		tmp2 = cs_One - nacyl->e_sq;
		qp = tmp2 * ((cs_One / tmp2) - (nacyl->one_o_2e * log (tmp1)));
		nacyl->beta_term = (cs_Two * nacyl->k0) / (nacyl->ka * qp);

		CSbtIsu (&nacyl->btcoefI,nacyl->e_sq);

		nacyl->max_xx = cs_Pi * nacyl->k0;
		nacyl->max_yy = nacyl->ka_o_2k0;
	}

	/* Set up the coordinate checking information.  If the user has
	   specified a useful range, we use it without checking it.
	   Otherwise, we compute what I, the programmer, consider to
	   be the useful range of the projection.  Note, values are in
	   degrees and longitude values are relative to the central
	   meridian. */

	csprm->cent_mer = nacyl->org_lng * cs_Radian;
	if (csprm->csdef.ll_min [LNG] == 0.0 &&
	    csprm->csdef.ll_max [LNG] == 0.0)
	{
		/* User hasn't specified any values.  We're to establish
		   the useful range.  We'll establish some pretty liberal
		   values. */

		csprm->min_ll [LNG] = cs_Km180;
		csprm->max_ll [LNG] = cs_K180;
		csprm->min_ll [LAT] = cs_Km90;
		csprm->max_ll [LAT] = cs_K90;
	}
	else
	{
		/* The definition includes a useful range specification.
		   We use these values without checking.  We expect the
		   user to give us absolute values, and we convert
		   to values relative to the central meridian. */

		csprm->min_ll [LNG] = CS_adj180 (csprm->csdef.ll_min [LNG] - csprm->cent_mer);
		csprm->min_ll [LAT] = csprm->csdef.ll_min [LAT];
		csprm->max_ll [LNG] = CS_adj180 (csprm->csdef.ll_max [LNG] - csprm->cent_mer);
		csprm->max_ll [LAT] = csprm->csdef.ll_max [LAT];
	}

	/* Similarly with the X's and Y's.  If the coordinate system
	   definition carries some values, we use them.  If not, we
	   calculate some appropriate values. */

	if (csprm->csdef.xy_min [XX] == 0.0 &&
	    csprm->csdef.xy_max [XX] == 0.0)
	{
		/* No specification in the coordinate system definition. */

		csprm->min_xy [XX] = -nacyl->max_xx;
		csprm->max_xy [XX] =  nacyl->max_xx;
		csprm->min_xy [YY] = -nacyl->max_yy;
		csprm->max_xy [YY] =  nacyl->max_yy;

		CS_quadMM (csprm->min_xy,csprm->max_xy,nacyl->x_off,
											   nacyl->y_off,
											   nacyl->quad);
	}
	else
	{
		/* Use what ever the user has given us.  No adjustment
		   necessary.  Note: we don't check anything. */

		csprm->min_xy [XX] = csprm->csdef.xy_min [XX];
		csprm->min_xy [YY] = csprm->csdef.xy_min [YY];
		csprm->max_xy [XX] = csprm->csdef.xy_max [XX];
		csprm->max_xy [YY] = csprm->csdef.xy_max [YY];
	}

	/* That's all the calculations we can do at this time.
	   The projection is conformal, so ha nd k scale
	   factors are the same. */

	csprm->ll2cs    = (cs_LL2CS_CAST)CSnacylF;
	csprm->cs2ll    = (cs_CS2LL_CAST)CSnacylI;
	csprm->cs_scale = (cs_SCALE_CAST)CSnacylK;
	csprm->cs_sclk  = (cs_SCALK_CAST)CSnacylK;
	csprm->cs_sclh  = (cs_SCALH_CAST)CSnacylH;
	csprm->cs_cnvrg = (cs_CNVRG_CAST)CSnacylC;
	csprm->llchk    = (cs_LLCHK_CAST)CSnacylL;
	csprm->xychk    = (cs_XYCHK_CAST)CSnacylX;

	return;
}

/**********************************************************************
**	rtn_val = CSnacylF (nacyl,xy,ll);
**
**	struct cs_Nacyl_ *nacyl;	structure containing all parameters necessary
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

int EXP_LVL9 CSnacylF (Const struct cs_Nacyl_ *nacyl,double xy [2],Const double ll [2])
{
	extern double cs_One;				/*  1.0 */
	extern double cs_Degree;			/*  1.0 / 57.29577... */
	extern double cs_Two_pi;			/*  2 Pi */
	extern double cs_3Pi_o_2;			/*  3 Pi over 2 */
	extern double cs_Pi_o_2;			/*  Pi over 2 */

	int rtn_val;

	double lng;
	double lat;
	double del_lng;

	double sin_lat;
	double esin_lat;

	double qq;
	double tmp1;
	double tmp2;

	rtn_val = cs_CNVRT_NRML;

	/* The following is required by both the sperical and
	   ellipsoidal forms. */

	lat = ll [LAT] * cs_Degree;
	if (fabs (lat) > cs_Pi_o_2)
	{
		rtn_val = cs_CNVRT_RNG;
		lat = CS_adj1pi (lat);
	}

	lng = ll [LNG] * cs_Degree;
	del_lng = lng - nacyl->org_lng;
	if      (del_lng >  cs_3Pi_o_2 && nacyl->org_lng < 0.0) del_lng -= cs_Two_pi;
	else if (del_lng < -cs_3Pi_o_2 && nacyl->org_lng > 0.0) del_lng += cs_Two_pi;
	if (fabs (del_lng) >= cs_3Pi_o_2)
	{
		rtn_val = cs_CNVRT_RNG;
		del_lng = CS_adj2pi (del_lng);
	}

	sin_lat = sin (lat);
	if (nacyl->ecent == 0.0)
	{
		/* Here for the sphere. */
		
		xy [XX] = del_lng * nacyl->ka_cosst;
		xy [YY] = sin_lat * nacyl->ka_o_cosst;
	}
	else
	{
		/* Here for the ellipsoid. */

		xy [XX] = nacyl->kak0 * del_lng;

		esin_lat = nacyl->ecent * sin_lat;
		tmp1 = (cs_One - esin_lat) / (cs_One + esin_lat);
		tmp2 = sin_lat / (cs_One - esin_lat * esin_lat);
		qq = nacyl->one_m_esq * (tmp2 - nacyl->one_o_2e * log (tmp1));
		xy [YY] = nacyl->ka_o_2k0 * qq;
	}

	if (nacyl->quad == 0)
	{
		xy [XX] += nacyl->x_off;
		xy [YY] += nacyl->y_off;
	}
	else
	{
		CS_quadF (xy,xy [XX],xy [YY],nacyl->x_off,nacyl->y_off,
												  nacyl->quad);
	}
	return (rtn_val);
}

/**********************************************************************
**	rtn_val = CSnacylI (nacyl,ll,xy);
**
**	struct cs_Nacyl_ *nacyl;	structure detailing the Equal Area Cylindrical
**								coordinate system in use.
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

int EXP_LVL9 CSnacylI (Const struct cs_Nacyl_ *nacyl,double ll [2],Const double xy [2])
{
	extern double cs_Radian;			/*  57.29577... */
	extern double cs_3Pi_o_2;			/*  3 Pi / 2.0 */
	extern double cs_One;				/*  1.0 */
	extern double cs_Mone;				/* -1.0 */

	int rtn_val;

	double xx;
	double yy;

	double lat;
	double beta;
	double del_lng;
	double sin_beta;

	rtn_val = cs_CNVRT_NRML;

	/* Remove whatever offsets are active. */

	if (nacyl->quad == 0)
	{
		xx = xy [XX] - nacyl->x_off;
		yy = xy [YY] - nacyl->y_off;
	}
	else
	{
		CS_quadI (&xx,&yy,xy,nacyl->x_off,nacyl->y_off,nacyl->quad);
	}

	if (nacyl->ecent == 0.0)
	{
		/* Here for the sphere. */

		del_lng = xx / nacyl->ka_cosst;
		if (fabs (del_lng) > cs_3Pi_o_2)
		{
			rtn_val = cs_CNVRT_RNG;
			del_lng = (del_lng >= 0.0) ? cs_3Pi_o_2 : -cs_3Pi_o_2;
		}
		if (fabs (yy) > nacyl->ka_o_cosst)
		{
			rtn_val = cs_CNVRT_RNG;
			yy = (yy >= 0.0) ? nacyl->cosst_o_ka : -nacyl->cosst_o_ka;
		}
		lat = asin (yy * nacyl->cosst_o_ka);
	}
	else
	{
		/* Here for the ellipsoid. */

		del_lng = xx * nacyl->one_o_kak0;
		if (fabs (del_lng) >= cs_3Pi_o_2)
		{
			rtn_val = cs_CNVRT_RNG;
			del_lng = (del_lng >= 0.0) ? cs_3Pi_o_2 : -cs_3Pi_o_2;
		}
		sin_beta = yy * nacyl->beta_term;
		if (fabs (sin_beta) > cs_One)
		{
			rtn_val = cs_CNVRT_RNG;
			sin_beta = (sin_beta >= 0.0) ? cs_One : cs_Mone;
		}
		beta = asin (sin_beta);
		lat = CSbtIcalPrec (&nacyl->btcoefI,beta);
	}

	ll [LNG] = (del_lng + nacyl->org_lng) * cs_Radian;
	ll [LAT] = lat * cs_Radian;
	return (rtn_val);
}

/**********************************************************************
**	cnvrg = CSnacylK (nacyl,ll);
**
**	struct cs_Nacyl_ *nacyl;	structure containing all parameters necessary
**								for the transformation.
**	double ll [2];				location of the point to be computed is given
**								here; longitude ([0]) and latitude ([1]) in
**								degrees.
**	double cnvrg;			the convergence angle of the projection at the
**								specified point.
**
**	If they were all this easy; I'd be out of a job.
**********************************************************************/

double EXP_LVL9 CSnacylC (Const struct cs_Nacyl_ *nacyl,Const double ll [2])
{
	extern double cs_Zero;			/* 0.0 */

	/* Since all meridians are parallel with the central
	   meridian and the Y axis, the convergence angle is
	   zero at all locations. */

	return (cs_Zero);
}									/*lint !e715 */

/**********************************************************************
**	kk = CSnacylK (nacyl,ll);
**
**	struct cs_Nacyl_ *nacyl;	structure containing all parameters necessary
**								for the transformation.
**	double ll [2];				location of the point to be computed is given
**								here; longitude ([0]) and latitude ([1]) in
**								degrees.
**	double kk;					the true map scale factor at the specified point.
**								Should be compared with the nacyl->k.
**********************************************************************/

double EXP_LVL9 CSnacylK (Const struct cs_Nacyl_ *nacyl,Const double ll [2])
{
	extern double cs_Degree;			/*  1.0 / 57.29577... */
	extern double cs_Pi_o_2;			/*  Pi over 2 */
	extern double cs_One;				/*  1.0 */
	extern double cs_Mone;				/* -1.0, the value returned
										   if we're provided with a
										   bogus latitude. */
	extern double cs_NPTest;			/* 0.001 seconds of arc short
										   of the north pole in
										   radians. */
	extern double cs_SclInf;			/* 9.9E+09, the value
										   returned for infinite
										   scale. */

	double kk;
	double lat;

	double cos_lat;
	double sin_lat;
	double tmp1;

	lat = fabs (ll [LAT] * cs_Degree);

	if (lat > cs_NPTest)
	{
		if (lat > cs_Pi_o_2)
		{
			return (cs_Mone);
		}
		return (cs_SclInf);
	}

	cos_lat = cos (lat);
	if (nacyl->ecent == 0.0)
	{
		/* Here for a spherical datum. */

		kk = nacyl->cos_std_lat / cos_lat;
	}
	else
	{
		sin_lat = sin (lat);
		tmp1 = cs_One - (nacyl->e_sq * sin_lat * sin_lat);
		kk = sqrt (tmp1) * nacyl->k0 / cos_lat;
	}
	return (kk);
}

/**********************************************************************
**	kk = CSnacylH (nacyl,ll);
**
**	struct cs_Nacyl_ *nacyl;	structure containing all parameters necessary
**								for the transformation.
**	double ll [2];				location of the point to be computed is given
**								here; longitude ([0]) and latitude ([1]) in
**								degrees.
**	double kk;					the true map scale factor at the specified point.
**								Should be compared with the nacyl->k.
**********************************************************************/

double EXP_LVL9 CSnacylH (Const struct cs_Nacyl_ *nacyl,Const double ll [2])
{
	extern double cs_One;			/*  1.0 */
	extern double cs_Mone;			/* -1.0 */
	extern double cs_SclInf;		/* 9.9E+04, the value we return
									   for infinite scale factor. */

	double kk;
	double hh;

	/* This is an equal area projection, so hh == 1 / kk. */

	kk = CSnacylK (nacyl,ll);

	if      (kk <= 0.0)   hh = cs_Mone;
	else if (kk > 0.0001) hh = cs_One / kk;
	else 				  hh = cs_SclInf;

	return (hh);
}

/**********************************************************************
**	status = CSnacylL (nacyl,cnt,pnts);
**
**	struct cs_Nacyl_ *nacyl;	the coordinate system against which the check is
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

int EXP_LVL9 CSnacylL (Const struct cs_Nacyl_ *nacyl,int cnt,Const double pnts [][3])
{
	extern double cs_Degree;		/* 1.0 / 57.29...... */
	extern double cs_Pi_o_2;		/* PI over 2 */

	int ii;
	int rtn_val;

	double lat;

	/* Check all the points.  */

	rtn_val = cs_CNVRT_OK;
	for (ii = 0;ii < cnt;ii++)
	{
		lat = pnts [ii][LAT] * cs_Degree;
		if (fabs (lat) > cs_Pi_o_2)
		{
			rtn_val = cs_CNVRT_DOMN;
			break;
		}
	}
	return (rtn_val);
}								/*lint !e715 */

/**********************************************************************
**	status = CSnacylX (nacyl,cnt,pnts);
**
**	struct cs_Nacyl_ *nacyl;	coordinate system definition
**	int cnt;					number of points in the pnts array.
**	double pnts [][3];			an array of three dimensional points which
**								define a point, line, or region to be checked.
**	int status;					returns the status of the check; see REMARKS
**								below.
**
**	The values provided in the pnts array are required to be
**	cartesian coordinates.  Use CSnacylL to check lat/long
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

int EXP_LVL9 CSnacylX (Const struct cs_Nacyl_ *nacyl,int cnt,Const double pnts [][3])
{
	int ii;
	int status;
	int rtn_val;

	double test_ll [3];

	rtn_val = cs_CNVRT_OK;

	/* Check that all X's and Y's are within the basic range.
	   No special checks are required for lines and/or regions. */

	for (ii = 0;ii < cnt;ii++)
	{
		status = CSnacylI (nacyl,test_ll,pnts [ii]);
		if (status != cs_CNVRT_NRML)
		{
			rtn_val = cs_CNVRT_DOMN;
			break;
		}
	}
	return (rtn_val);
}
