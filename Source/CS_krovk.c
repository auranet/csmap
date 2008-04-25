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

			 File Name: $RCSfile: CS_krovk.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #5 $
		 Check In Date:	$Date: 2006/11/16 $

		Last Revision:	$Log: CS_krovk.c $
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
		Last Revision:	Revision 10.1501  2002/11/21 21:08:22  nto
		Last Revision:	Lint cleanup.
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
		Last Revision:	Revision 10.500  2000/10/27 07:38:22  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:16:56  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.301  2000/09/12 20:42:40  nto
		Last Revision:	Major overhaul.  The projection is now completely parameterized, includes the JTSK/95 variation, and has been tested.
		Last Revision:	Revision 10.300  2000/04/04 23:18:27  nto
		Last Revision:	Revision 10.201  2000/04/03 23:05:48  nto
		Last Revision:	Got the signs of everything adjusted.  We now match the test points within 10 mm.
		Last Revision:	Revision 10.200  2000/03/02 18:51:18  nto
		Last Revision:	Revision 10.3  2000/02/11 06:11:21  nto
		Last Revision:	Added the new 95 adjustment variation.  Untested as yet, we don't have any test data.
		Last Revision:	Revision 10.2  2000/01/30 23:48:06  nto
		Last Revision:	PCLint clean up.
		Last Revision:	Revision 10.1  1999/10/16 18:53:26  nto
		Last Revision:	Modifications usggested by Gimpel PC-Lint.  No functionality
		Last Revision:	changes.
		Last Revision:	Revision 10.0  1999/10/05 18:27:15  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:26  nto
		Last Revision:	Revision 1.2  1999/09/04 18:44:56  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_krovk.c#5 $"};
#endif

#include "cs_map.h"

/* Prototype for the function which makes 95 different. */
void EXP_LVL9 CSkrovk95 (double deltaXY [2],Const double xy [2]);

/* We'll have need of the following in at least two places.  Given an
   ellipsoidal latitude, it returns the gausian spherical latitude. */
double EXP_LVL9 CSkrovkB1 (Const struct cs_Krovk_ *krovk,double latE)
{
	extern double cs_Half;			/* 0.5 */
	extern double cs_One;			/* 1.0 */
	extern double cs_Two;
	extern double cs_Pi_o_4;		/* pi over 4 */
	extern double cs_Pi_o_2;		/* pi over 2 */

	double tmp1, tmp2, tmp3;
	double latS;

	tmp1 = krovk->ecent * sin (latE);
	tmp1 = (cs_One + tmp1) / (cs_One - tmp1);
	tmp2 = tan (cs_Pi_o_4 + latE * cs_Half);
	tmp3 = krovk->alpha * log (tmp2) - krovk->alpha_eo2 * log (tmp1) + krovk->logK;
	latS = cs_Two * atan (exp (tmp3)) - cs_Pi_o_2;
	return latS;
}

/* We'll have need of the following function in several places.  It is,
   basically, the forward function, but its results are also required
   for the grid scale factor and the convergence angle.  Thus, to
   eliminate duplicate code, we suffer this little hit on performance. */
int EXP_LVL9 CSkrovkB2 (Const struct cs_Krovk_ *krovk,Const double lnglat [2],
													  double llS [2],
													  double llO [2],
													  double *theta,
													  double *rho)
{
	/* read llS as latlng on the gaussian surface (i.e. conformal sphere) and
	   llO and latlng on the oblique sphere. */
	extern double cs_Degree;		/* 1.0 / RADIAN  */
	extern double cs_Pi_o_4;		/* Pi over 4 */
	extern double cs_Half;			/* 0.5 */
	extern double cs_One;			/* 1.0 */
	extern double cs_Mone;			/* -1.0 */
	extern double cs_NPTest;		/* 0.001 seconds of arc
									   short of the north pole,
									   in radians. */
	extern double cs_SPTest;		/* 0.001 seconds of arc
									   short of the south pole,
									   in radians. */
	int rtn_val;

	double lngE;				/* The given longitude, after conversion
								   to radians. */
	double latE;				/* The given latitude after conversion
								   to radians. */

	double sinLatS, cosLatS;
	double sinLatO, cosLatO;
	double sinLngO;
	double tmp1;

	rtn_val = cs_CNVRT_NRML;

	lngE = (lnglat [LNG] * cs_Degree) - krovk->orgLng;
	latE = lnglat [LAT] * cs_Degree;

	/* Assure that eLat is rational.  This we need to assure we don't
	   take the log of zero or a negative number.  We just truncate
	   to the appropriate pole. */
	if (fabs (latE) > cs_NPTest)
	{
		rtn_val = cs_CNVRT_RNG;
		latE = CS_adj1pi (latE);
		if (latE > cs_NPTest) latE = cs_NPTest;
		else if (latE < cs_SPTest) latE = cs_SPTest;
	}
	/* We don't really have a problem with longitude, as we only
	   take sin and cos of the longitude. */

	/* Map the resulting lat/long to the gaussian surface. */
	if (krovk->ecent == 0.0)
	{
		llS [LNG] = lngE;
		llS [LAT] = latE;
	}
	else
	{
		llS [LNG] = krovk->alpha * lngE;
		llS [LAT] = CSkrovkB1 (krovk,latE);
	}

	/* We're now on the conformal sphere. */
	sinLatS = sin (llS [LAT]);
	cosLatS = cos (llS [LAT]);

	/* Convert the spherical geographic lat/long to the equivalent
	   lat/long on the oblique sphere. */
	sinLatO = krovk->sinLatQ * sinLatS + krovk->cosLatQ * cosLatS * cos (krovk->lngQ - llS [LNG]);
	cosLatO = sqrt (cs_One - sinLatO * sinLatO);
	llO [LAT] = atan (sinLatO / cosLatO);
	sinLngO = (cosLatS / cosLatO)  * sin (krovk->lngQ - llS [LNG]);

	/* The asin should be OK here, but just to be sure. */
	if (sinLngO > cs_One) sinLngO = cs_One;
	else if (sinLngO < cs_Mone) sinLngO = cs_Mone;
	llO [LNG] = asin (sinLngO);
	/* From the Czech document test case:
		 lngO =? 21.8191895277777; latO =? 77.7249551388888 */

	/* Convert to polar coordinates. */
	*theta = krovk->nn * llO [LNG];
	tmp1 = krovk->tanTermF / tan (cs_Pi_o_4 + llO [LAT] * cs_Half);
	*rho = krovk->rho0 * pow (tmp1,krovk->nn);

	return (rtn_val);
}

/* Now for the regular stuff.
   CSkrovkS -- The setup function (constructor). */
void EXP_LVL9 CSkrovkS (struct cs_Csprm_ *csprm)
{
	extern short cs_QuadMin;		/* -4 */
	extern short cs_QuadMap [];
	extern double cs_Degree;		/*  1.0 / RADIAN  */
	extern double cs_Radian;		/*  57.27....  */
	extern double cs_Pi;			/*  Pi (3.14159....) */
	extern double cs_Pi_o_4;		/*  Pi over 4 */
	extern double cs_Zero;			/*  0.0 */
	extern double cs_Half;			/*  0.5 */
	extern double cs_One;			/*  1.0 */
	extern double cs_Four;			/*  4.0 */
	extern double cs_AnglTest;		/* 0.001 seconds of arc in
									   radians. */

	struct cs_Krovk_ *krovk;

	double lat0;
	double sinLat0;
	double sinOrgLat, cosOrgLat;
	double one_esq;
	double tmp1, tmp2, tmp3, tmp4;

	double test_ll [3];
	double test_xy [3];

	krovk = &csprm->proj_prms.krovk;
	krovk->apply95 = (csprm->prj_code == cs_PRJCOD_KRVK95) ? 1 : 0;

	/* Extract the parameters from the definition. */
	krovk->orgLng  = csprm->csdef.org_lng * cs_Degree;
	krovk->orgLat  = csprm->csdef.org_lat * cs_Degree;
	krovk->poleLng = csprm->csdef.prj_prm1 * cs_Degree;
	krovk->poleLat = csprm->csdef.prj_prm2 * cs_Degree;
	krovk->stdLat  = csprm->csdef.prj_prm3 * cs_Degree;
	krovk->x_off = csprm->csdef.x_off;
	krovk->y_off = csprm->csdef.y_off;
	krovk->k0 = csprm->csdef.scl_red;
	krovk->k = csprm->csdef.scale * krovk->k0;

	/* Some basics calculated from the parameters. */
	sinOrgLat = sin (krovk->orgLat);
	cosOrgLat = cos (krovk->orgLat);
	krovk->kR = csprm->datum.e_rad * krovk->k;
	krovk->ecent = csprm->datum.ecent;
	krovk->e_sq = krovk->ecent * krovk->ecent;
	krovk->e_ovr_2 = krovk->ecent * cs_Half;
	one_esq = cs_One - krovk->e_sq;

	krovk->resolve = cs_AnglTest;
	krovk->one_mm = 0.001 * krovk->k;
	krovk->quad = cs_QuadMap [csprm->csdef.quad - cs_QuadMin];

	/* Don't really know what N0 is.  Some sort of radius, but
	   I've never seen this particular formulation before.  Anyway,
	   it is this particular caluclation that forced us to
	   hard code the parameters into the original version.
	   
	   Kind of interesting that an ellipsoidal radius was chosen,
	   even though the radius is used as the base radius of a
	   conic projection of a Guassian sphere. */
	tmp1 = cs_One - krovk->e_sq * sinOrgLat * sinOrgLat;
	krovk->N0 = krovk->kR * sqrt (one_esq) / tmp1;
	krovk->rho0 = krovk->N0 / tan (krovk->stdLat); 

	/* Handle the specific variations here. */
	if (krovk->ecent == 0.0)
	{
		/* Here for the spherical form of the Krovak variation.
		   Calculate the gaussian surface equivalent of some of
		   the ellipsoidal based parameters.  Since in this case,
		   we are starting with a sphere, this is pretty
		   superficial. */
		krovk->alpha = cs_One;
		krovk->alpha_eo2 = cs_One;
		krovk->K = cs_Zero;
		krovk->lngQ = krovk->poleLng;
		krovk->latQ = krovk->poleLat;
	}
	else
	{
		/* Here for the ellipsoid version of the projection.  Here we have
		   to compute aplha and K, which are used to convert ellipsoidal
		   lat/longs to Gaussian Surface (i.e. approximating sphere)
		   lat/longs.  Then, we use alpha and K to compute the location
		   of the oblique pole in terms of Gaussian Surface lat/longs. */
		tmp1 = cosOrgLat * cosOrgLat;
		tmp1 = tmp1 * tmp1;
		tmp1 = (krovk->e_sq * tmp1) / (one_esq);
		krovk->alpha = sqrt (cs_One + tmp1);
		krovk->alpha_eo2 = krovk->alpha * krovk->ecent * cs_Half;

		sinLat0 = sinOrgLat / krovk->alpha;
		/* This asin is OK.  alpha is always >= 1.0 and sinOrgLat should
		   always be a legimate sine, thus sinLat0 should always be
		   legitimate. */
		lat0 = asin (sinLat0);

		/* What we really want is log K.  Since this is a setup function,
		   we'll complute K per the documentation, then compute logK. */
		tmp1 = krovk->ecent * sinOrgLat;
		tmp2 = tan (cs_Pi_o_4 + lat0 * cs_Half);
		tmp3 = tan (cs_Pi_o_4 + krovk->orgLat  * cs_Half);
		tmp4 = (cs_One + tmp1) / (cs_One - tmp1);
		krovk->logK = log (tmp2) - krovk->alpha * log (tmp3) + krovk->alpha_eo2 * log (tmp4);
		krovk->K = exp (krovk->logK);

		krovk->alpha_eo2 = krovk->alpha * (krovk->ecent * cs_Half);
		krovk->lngQ = krovk->alpha * krovk->poleLng;
		krovk->latQ = CSkrovkB1 (krovk,krovk->poleLat);
	}

	/* The remainder is the same for all variations. */
	krovk->nn = sin (krovk->stdLat);
	krovk->one_o_nn = cs_One / krovk->nn;
	krovk->tanTermF = tan (cs_Pi_o_4 + krovk->stdLat * cs_Half);
	krovk->tanTermI = pow (krovk->tanTermF,krovk->nn) * krovk->rho0;
	krovk->theta_max = cs_Pi * fabs (krovk->nn);
	krovk->pole_test = krovk->rho0 * cs_AnglTest;
	krovk->infinity = krovk->rho0 * cs_Four;

	/* Compute the terms used to calculate lat/longs on the oblique
	   gaussian surface (i.e. conformal sphere). */
	krovk->sinLatQ = sin (krovk->latQ);
	krovk->cosLatQ = cos (krovk->latQ);

	/* Set up the coordinate checking information.  If the user has
	   specified a useful range, we use it without checking it.
	   Otherwise, since this is currently a parameter-less projection,
	   we just set some rather arbitrary, but reasonable, values.
	   Note, org_Lng is relative to Ferro, so the min/max longitude
	   is also relative to Ferro.  This is a strange beast. */
	csprm->cent_mer = krovk->orgLng * cs_Radian;
	if (csprm->csdef.ll_min [LNG] == 0.0 &&
		csprm->csdef.ll_max [LNG] == 0.0)
	{
		csprm->min_ll [LNG] = 17.0;
		csprm->max_ll [LNG] = 47.0;
		csprm->min_ll [LAT] = 42.0;
		csprm->max_ll [LAT] = 55.0;
	}
	else
	{
		/* User specified value will be relative to Greenwich. */
		csprm->min_ll [LNG] = CS_adj180 (csprm->csdef.ll_min [LNG] - csprm->cent_mer);
		csprm->min_ll [LAT] = csprm->csdef.ll_min [LAT];
		csprm->max_ll [LNG] = CS_adj180 (csprm->csdef.ll_max [LNG] - csprm->cent_mer);
		csprm->max_ll [LAT] = csprm->csdef.ll_max [LAT];
	}

	/* Similarly with the X's and Y's. */
	if (csprm->csdef.xy_min [XX] == 0.0 &&
		csprm->csdef.xy_max [XX] == 0.0)
	{
		/* Use the forward function to compute the X/Y's that collerate
		   with the min/max lat/lng. */
		test_ll [LNG] = csprm->min_ll [LNG];
		test_ll [LAT] = csprm->min_ll [LAT];
		CSkrovkF (krovk,test_xy,test_ll);						/*lint !e534 */
		csprm->min_xy [XX] = test_xy [XX];
		csprm->min_xy [YY] = test_xy [YY];

		test_ll [LNG] = csprm->max_ll [LNG];
		test_ll [LAT] = csprm->max_ll [LAT];
		CSkrovkF (krovk,test_xy,test_ll);						/*lint !e534 */
		csprm->max_xy [XX] = test_xy [XX];
		csprm->max_xy [YY] = test_xy [YY];
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

	/* That's all the calculations.  Stuff some function
	   addresses and we are done. */
	csprm->ll2cs    = (cs_LL2CS_CAST)CSkrovkF;
	csprm->cs2ll    = (cs_CS2LL_CAST)CSkrovkI;
	csprm->cs_scale = (cs_SCALE_CAST)CSkrovkK;
	csprm->cs_sclk  = (cs_SCALK_CAST)CSkrovkK;
	csprm->cs_sclh  = (cs_SCALH_CAST)CSkrovkK;
	csprm->cs_cnvrg = (cs_CNVRG_CAST)CSkrovkC;
	csprm->llchk    = (cs_LLCHK_CAST)CSkrovkL;
	csprm->xychk    = (cs_XYCHK_CAST)CSkrovkX;
	return;
}

int EXP_LVL9 CSkrovkF (Const struct cs_Krovk_ *krovk,double xy [2],Const double lnglat [2])
{
	int rtn_val;

	double theta;
	double rho;
	double tmp;
	double llO [2];
	double llS [2];
	double deltaXY [2];

	/* Do the forward calculation. */
	rtn_val = CSkrovkB2 (krovk,lnglat,llS,llO,&theta,&rho);

	/* Now to cartesian coordnates. */
	xy [XX] = rho * cos (theta);
	xy [YY] = rho * sin (theta);

	/* Apply the 95 adjustment if appropriate. */
	if (krovk->apply95)
	{
		CSkrovk95 (deltaXY,xy);
		xy [XX] -= deltaXY [XX];
		xy [YY] -= deltaXY [YY];
	}

	/* We do some strange stuff here to get a normal coordinate system out of
	   this.  That is, a coordinate system which works well in a traditional
	   graphic system such as AutoCAD.  For the 95 variation, the false origin
	   values are negative to help achieve the desired result.
	   
	   The actual definition of the Krovak requires that Y increases to the
	   west and that X increases to the south.  This would produce a very
	   strange image in AutoCAD, i.e. mirrored about the origin.  The desired
	   result is, therefore, a coordinate system which produces negative
	   values, such that when treated algebraically, X increases to the east
	   and Y increases to the north.  The absolute values, however, adhere
	   to the definition of Krovak (excepting the swap of the axes). */
	CS_quadF (xy,xy [XX],xy [YY],krovk->x_off,krovk->y_off,krovk->quad);
	tmp = xy [XX];
	xy [XX] = -xy [YY];
	xy [YY] = -tmp;

	return (rtn_val);
}
int EXP_LVL9 CSkrovkI (Const struct cs_Krovk_ *krovk,double lnglat [2],Const double xy [2])
{
	extern double cs_Radian;		/*  57.29577..... */
	extern double cs_Pi;			/*  Pi */
	extern double cs_Pi_o_2;		/*  Pi over 2 */
	extern double cs_Pi_o_4;		/*  Pi over 4 */
	extern double cs_Half;			/*  0.5 */
	extern double cs_One;			/*  1.0 */
	extern double cs_Two;			/*  2.0 */

	int rtn_val;
	int itrMax;

	double xx, yy;
	double rho, theta;
	double lngO, latO;
	double lngS, latS;
	double lngE, latE;
	double lastLatE;

	double sinLatO, cosLatO;
	double sinLngS;
	double sinLatS, cosLatS;
	double tmp1, tmp2, Q;

	double tmp_xy [2];
	double deltaXY [2];

	rtn_val = cs_CNVRT_NRML;

	/* We use tmpxy as we don't want to change the provided parameters
	   on the user, that just isn't very nice. */
	tmp_xy [XX] = -xy [YY];
	tmp_xy [YY] = -xy [XX];

	/* Undo the strange stuff we did to get the desired result as far as
	   the axis numbers.  See the tail end of the forward function for
	   a description of what's going on here. */
	CS_quadI (&xx,&yy,tmp_xy,krovk->x_off,krovk->y_off,krovk->quad);

	/* Undo the 95 adjustment if appropriate. */
	if (krovk->apply95)
	{
		/* Note that this does not actually produce a real inverse.
		   The result is close, but not true.  A true mathematical
		   inverse does not exist (perhaps why the source doesn't
		   provide one).  We'll have to come up with a numerical
		   approximation to the inverse if the creep factor is too
		   large. */
		tmp_xy [XX] = xx;
		tmp_xy [YY] = yy;
		CSkrovk95 (deltaXY,tmp_xy);
		xx += deltaXY [XX];
		yy += deltaXY [YY];
	}

	/* Convert the X and Y to polar coordinates. */
	theta = atan2 (yy,xx);
	rho = sqrt (yy * yy + xx * xx);

	/* Check the results for bogus values. */
	if (rho < krovk->pole_test)
	{
		/* If rho is very small, the point is on the pole and we can
		   simply return that value now. */
		lnglat [LNG] = krovk->poleLng * cs_Radian;
		lnglat [LAT] = krovk->poleLat * cs_Radian;
		return rtn_val;
	}
	if (rho > krovk->infinity)
	{
		/* If rho is huge, we respond with a point at the opposite pole. */
		lnglat [LNG] = CS_adj2pi (krovk->poleLng - cs_Pi) * cs_Radian;
		lnglat [LAT] = -krovk->poleLat * cs_Radian;
		return rtn_val;
	}
	if (fabs (theta) >= krovk->theta_max)
	{
		/* Opps, the point is in the conic crack.  Adjust. */
		theta = theta > 0.0 ? krovk->theta_max : -krovk->theta_max;
	}

	/* Convert the polar coordinates to lat/long on the oblique sphere.  This
	   uses the Lambert Conformal technique, not necessarily the same
	   formulas. */
	lngO = theta / krovk->nn;
	tmp1 = pow (krovk->tanTermI / rho,krovk->one_o_nn);
	latO = cs_Two * atan (tmp1) - cs_Pi_o_2;
	/* From the Czech document test case:
		 lngO =? 21.8191895277777; latO =? 77.7249551388888 */

	/* Convert from the oblique sphere to the gausian surface. */
	sinLatO = sin (latO);
	cosLatO = cos (latO);
	sinLatS = krovk->sinLatQ * sinLatO - krovk->cosLatQ * cosLatO * cos (lngO);
	cosLatS = sqrt (cs_One - sinLatS * sinLatS);
	latS = atan (sinLatS / cosLatS);
	sinLngS = (cosLatO / cosLatS) * sin (lngO);
	lngS = krovk->lngQ - asin (sinLngS);

	/* Convert from the gausian surface to the ellipsoid. If the
	   reference is a sphere, don't really need to do anything. */
	if (krovk->ecent == 0.0)
	{
		lngE = lngS;
		latE = latS;
	}
	else
	{
		lngE = lngS / krovk->alpha;

		tmp1 = tan (cs_Pi_o_4 + latS * cs_Half);
		tmp1 = (log (tmp1) - krovk->logK) / krovk->alpha;
		latE = krovk->orgLat;
		itrMax = 10;			/* usually 4 or 5 does it */
		do
		{
			lastLatE = latE;
			tmp2 = krovk->ecent * sin (lastLatE);
			tmp2 = (cs_One + tmp2) / (cs_One - tmp2);
			Q = tmp1 + krovk->e_ovr_2 * log (tmp2);
			latE = cs_Two * atan (exp (Q)) - cs_Pi_o_2;
		} while (--itrMax >= 0 && fabs (latE - lastLatE) > krovk->resolve);
	}

	/* Convert the results to degrees. */
	lnglat [LNG] = (lngE + krovk->orgLng) * cs_Radian;
	lnglat [LAT] = latE * cs_Radian;
	return (rtn_val);
}

/* This is the grid scale function as provided by the Czech document.
   It produces reasonable numbers.  Since we have no idea where the
   "maler" constant comes from, we have no idea exactly what this
   thing is measuring. */
double EXP_LVL9 CSkrovkK (Const struct cs_Krovk_ *krovk,Const double ll [2])
{
	extern double cs_NPTest;	/* skosh less than 90 degrees,
								   but its in radians. */
	extern double cs_SclInf;	/* 9999.0, our standard return value
								   to indicate infinite scale. */

	double kk;
	double theta, rho;
	double llS [2];
	double llO [2];

	/* Do the forward calculation to obtain latO and theta. */
	CSkrovkB2 (krovk,ll,llS,llO,&theta,&rho);						/*lint !e534 */
	
	/* Now we can compute the scale.  Scale is infinite at the
	   oblique pole; could also cause a divide by zero. */
	if (fabs (llO [LAT]) < cs_NPTest)
	{
		kk = (krovk->nn * rho) / (krovk->N0 / krovk->k0 * cos (llO [LAT]));
	}
	else
	{
		kk = cs_SclInf;
	}
	return kk;
}

/* Note that the convergence calculation here is a traditional measurement
   of the convergence angle.  In the Czech documentation, they calculate
   the convergence relative to a specific meridian (30 17' 17.30311").
   When I get this stuff to work, we'll try to figure out what this
   number is and we may come up with an alternative to the traditional
   result computed below. */

double EXP_LVL9 CSkrovkC (Const struct cs_Krovk_ *krovk,Const double ll [2])
{
	extern double cs_Radian;		/*  57.29577..... */
	extern double cs_NPTest;		/* skosh less than 90 degrees,
									   but its in radians. */
	extern double cs_Km360;			/* -360.0, our standard return value
									   to indicate a bogus position for
									   convergence. */
	extern double cs_One;			/*  1.0 */
	extern double cs_Mone;			/* -1.0 */

	/* The following constant comes from the Czech document.  We presume this
	   is a longitude value. */
	static double A = 30.288139752777 * ONE_DEGREE;

	int st;
	double gamma;
	double theta, rho;
	double llS [2];
	double llO [2];
	double tmp1;

	/* Do the forward calculation to get lngO, latS, and theta. */
	st = CSkrovkB2 (krovk,ll,llS,llO,&theta,&rho);
	if (st != cs_CNVRT_NRML)
	{
		return cs_Km360;
	}

	/* Compute the convergence ala the Czech document.  Not sure exactly
	   what all this does, but it produces reasonable numbers. */
	if (fabs (llS [LAT]) < cs_NPTest)
	{
		tmp1 = sin (A) * sin (llO [LNG]) / cos (llS [LAT]);
		if (tmp1 > cs_One) tmp1 = cs_One;
		else if (tmp1 < cs_Mone) tmp1 = cs_Mone;

		/* Note sign reversal here. */
		gamma = (asin (tmp1) - theta) * cs_Radian;
	}
	else
	{
		gamma = cs_Km360;
	}
	return gamma;
}
int EXP_LVL9 CSkrovkQ (	Const struct cs_Csdef_ *cs_def,unsigned short prj_code,int err_list [],int list_sz)
{
	int err_cnt;
	
	/* We will return (err_cnt + 1) below. */
	err_cnt = -1;
	if (err_list == NULL) list_sz = 0;

	/* Since all parameters are hard coded, there isn't anything to check. */
	return (err_cnt + 1);
}																 /*lint !e550 */
int EXP_LVL9 CSkrovkL (Const struct cs_Krovk_ *krovk,int cnt,Const double pnts [][3])
{
	int ii;
	int status;

	double test_xy [3];

	/* NOTE: WE DO NOT, as yet, CHECK LINES AND REGIONS. In future,
	   we need to add some spherical trigonometry to see if any
	   great circle arc, or region includes either of the oblique
	   poles or traverse the infamous conic crack. */
	status = cs_CNVRT_OK;
	for (ii = 0;ii < cnt;ii++)
	{
		status = CSkrovkF (krovk,test_xy,pnts [ii]);
		if (status != cs_CNVRT_NRML)
		{
			status = cs_CNVRT_DOMN;
			break;
		}
	}
	return (status);
}
int EXP_LVL9 CSkrovkX (Const struct cs_Krovk_ *krovk,int cnt,Const double pnts [][3])
{
	int rtn_val;

	rtn_val = cs_CNVRT_OK;

	/* Assuming that atan will return a rational result, i.e.
	   pi over 2, for even the most astronomical number, there
	   are no singularity points for X and Y.
	   
	   We leave the code necessary to handle the list, COMMENTED
	   OUT, just in case we learn different in the future. */

/******************
	for (ii = 0;ii < cnt;ii++)
	{
		status = CSkrovkI (krovk,test_ll,pnts [ii]);
		if (status != cs_CNVRT_NRML)
		{
			rtn_val = cs_CNVRT_DOMN;
			break;
		}
	}
*******************/
	return (rtn_val);
}

/**********************************************************************
**	Computes the DeltaX and DeltaY associated with S-JTSK/95 
***********************************************************************/
void EXP_LVL9 CSkrovk95 (double deltaXY [2],Const double xy [2])
{
	extern double cs_Two;			/* 2.0 */

	/* The following define which element is X and which is Y.  This
	   is somewhat of an issue in this projection. */
	static const int krvkXX = 0;
	static const int krvkYY = 1;

	/* Given the above to appropriately map the elements of the point
	   arrays, the following is an implementation which matches the
	   nomenclature of the source document. */
	static const double yOffset =  654000.0; 
	static const double xOffset = 1089000.0;
	static const double A1 =  0.5839284707E-01; 
	static const double A2 =  0.4718658410E-01; 
	static const double A3 =  0.8227606925E-07; 
	static const double A4 = -0.3337763709E-06; 
	static const double A5 =  0.8850984442E-11; 
	static const double A6 =  0.1444547818E-11; 

	double tmp1, tmp2;
	double xRed, yRed;
	double deltaX, deltaY;

	xRed = xy [krvkXX] - xOffset;
	yRed = xy [krvkYY] - yOffset;

	tmp1 = xRed * xRed - yRed * yRed;
	tmp2 = cs_Two * xRed * yRed;

	deltaX  = A5 * tmp1;
	deltaX -= A6 * tmp2;
	deltaX -= A4 * yRed;
	deltaX += A3 * xRed;
	deltaX += A1;

	deltaY  = A6 * tmp1;
	deltaY += A5 * tmp2;
	deltaY += A4 * xRed;
	deltaY += A3 * yRed;
	deltaY += A2;

	deltaXY [krvkXX] = deltaX;
	deltaXY [krvkYY] = deltaY;

	return;
}
