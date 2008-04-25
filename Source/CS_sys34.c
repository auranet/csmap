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

			 File Name: $RCSfile: CS_sys34.c $
		   Description: Danish System 34 conversion.
			   Purpose: Converts European 50 LL to Danish and Vice Versa

		Revision Level:	$Revision: #4 $
		 Check In Date:	$Date: 2006/11/16 $

		Last Revision:	$Log: CS_sys34.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:18  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:16  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:14  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:21  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:28  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:17  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:57  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:32  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:59  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:25  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:20  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:47  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1501  2002/11/21 21:08:25  nto
		Last Revision:	Lint cleanup.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:24  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1403  2002/09/21 23:19:56  nto
		Last Revision:	Fixed some problem with the 1999 vintage of Bornholm. 
		Last Revision:	Revision 10.1402  2002/09/20 04:28:11  nto
		Last Revision:	Adjusted the default min/max ranges.
		Last Revision:	Revision 10.1401  2002/09/17 23:26:45  nto
		Last Revision:	Added the Nov 1999 Variation.
		Last Revision:	Revision 10.1400  2002/08/09 18:14:25  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:22  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:40  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:29  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 1.1  2002/02/19 05:44:32  nto
		Last Revision:	Initial Revision

						R E M A R K S

	This "projection" is quite unusual in that it models the Danish
	System 34 technique.  This technique converts directly from UTM
	to Danish cartesian coordinates, rather than from geographic
	coordinates.

	Therefore, to implement this in the framework of CS-MAP, we
	first perform a geographic to UTM conversion, and then use
	the System 34 polynomial algorithm to convert the resulting
	UTM's to the desired Danish cartesians.

	The inverse converts from the Danish to UTM's using the
	polynomial algorithms.  We then convert the UTM's to
	geographic in the standard manner.

	The cs_Sys34_ structure closely resembles a cs_Trmer_ structure,
	somewhat tailored for UTM calculations.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id"};
#endif

#include "cs_map.h"

static int EXP_LVL9 TransformS34J_UTM32 (double x1, double y1,double* x2, double* y2,short vintage); 
static int EXP_LVL9 TransformS34S_UTM32 (double x1, double y1,double* x2, double* y2,short vintage);
static int EXP_LVL9 TransformS45B_UTM33 (double x1,double y1,double* x2,double* y2,short vintage);
static int EXP_LVL9 TransformUTM32_S34J (double x1, double y1,double* x2,double* y2,short vintage);
static int EXP_LVL9 TransformUTM32_S34S (double x1,double y1,double *x2, double *y2,short vintage);
static int EXP_LVL9 TransformUTM33_S45B (double x1,double y1,double *x2,double *y2,short vintage);
static int EXP_LVL9 uts34 (double Ein,double Nin,double *xout,double *yout,int landsdel,int direct,short vintage);

/*lint -esym(613,err_list) */
/*lint -esym(715,prj_code) */
/*lint -esym(578,y1) */
/*lint -esym(644,utmNmin,utmNmax,utmEmin,utmEmax) */
/*lint -esym(644,s34ymin,s34ymax,s34xmin,s34xmax) */
/*lint -esym(644,ins,cb,cw,cbu,cbs) */

/**********************************************************************
**	err_cnt = CSsys34Q (cs_def,prj_code,err_list,list_sz);
**
**	struct cs_Csdef_ *cs_def;	the coordinate system to be checked.
**	unsigned short prj_code;	specifies the specific variation of the projection.
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

int EXP_LVL9 CSsys34Q (	Const struct cs_Csdef_ *cs_def,unsigned short prj_code,int err_list [],int list_sz)
{
	extern double cs_One;			/*    1.0 */
	extern double cs_Three;			/*    3.0 */

	int err_cnt;

	/* We will return (err_cnt + 1) below. */
	
	err_cnt = -1;
	if (err_list == NULL) list_sz = 0;

	if (cs_def->prj_prm1 < cs_One || cs_def->prj_prm1 > cs_Three)
	{
		if (++err_cnt < list_sz) err_list [err_cnt] = cs_CSQ_DENRGN;
	}

	return (err_cnt + 1);
}

/**********************************************************************
**	(void) CSsys34S (csprm);
**
**	struct cs_Csprm_ *csprm;	structure containing all coordinate
**									system parameters.
**
**	This function sets up a cs_Sys34_ structure for use by the
**	remaining mosules in this section.  In C++ jargon, this would
**	be called a constructor.
**
**********************************************************************/
void EXP_LVL9 CSsys34S (struct cs_Csprm_ *csprm)
{
	extern short cs_QuadMin;			/* -4 */
	extern short cs_QuadMap [];
	extern double cs_Radian;			/*  57.29577... */
	extern double cs_Degree;			/*   1.0 / 57.29577... */
	extern double cs_Zero;				/*   0.0 */
	extern double cs_Half;				/*   0.5 */
	extern double cs_One;				/*   1.0 */
	extern double cs_Nine;				/*   9.0 */
	extern double cs_K15;				/*  15.0 */
	extern double cs_EETest;			/* .001 seconds of arc
										   short of 90 degrees
										   in radians; used to
										   test for excessive
										   eastern longitude. */

	struct cs_Sys34_ *sys34;

	double test_ll [2];

	sys34 = &csprm->proj_prms.sys34;

	/* We have two varaiations.  The original variation uses
	   a set of polynomials which were devides prior to 1999.  The
	   'A' variation usues a set of polynomials devised in 1999. */
	sys34->vintage = (csprm->prj_code == cs_PRJCOD_SYS34_99) ? 1999 : 0;
	
	/* The single parameter to this whole mess is the specific zone involved.
	   Since paramteres need to be numeric (actually doubles), we arbitrarily
	   have chosen:

	   prj_prm1 == 1.0  ==> jylland
	   prj_prm1 == 2.0  ==> sjælland
	   prj_prm1 == 3.0  ==> bornholm

	   For each of these zones, there are some basic UTM type parameters
	   involved.
	*/

	sys34->k0 = 0.9996;					/* Standard UTM value. */
	sys34->region = (short)csprm->csdef.prj_prm1;
	sys34->e_rad = csprm->datum.e_rad;
	sys34->ecent = csprm->datum.ecent;
	sys34->e_sq = sys34->ecent * sys34->ecent;
	sys34->quad = cs_QuadMap [csprm->csdef.quad - cs_QuadMin];

	switch (sys34->region) {
	default:
		/* Should never happen as the Q function verifies a appropriate value. */
	case 1: 
		sys34->cent_lng = cs_Nine * cs_Degree; 
		sys34->org_lat = cs_Zero;
		break;
	case 2:	 
		sys34->cent_lng = cs_Nine * cs_Degree; 
		sys34->org_lat = cs_Zero;
		break; 
	case 3:
		/* They didn't tell me about this, but this is the way it has to be if
		   you want to match the provided test results. */
		if (csprm->prj_code == cs_PRJCOD_SYS34_99)
		{
			sys34->cent_lng = cs_Nine * cs_Degree; 
		}
		else
		{
			sys34->cent_lng = cs_K15 * cs_Degree; 
		}
		sys34->org_lat = cs_Zero;
		break;
	}
	sys34->k = csprm->csdef.scale * sys34->k0;
	sys34->Rk = sys34->e_rad * sys34->k;

	if (sys34->ecent == 0.0)
	{
		/* Here for a sphere. */
		sys34->Rk_ovr_2 = sys34->Rk * cs_Half;
	}
	else
	{
		/* Here for an ellipsoid. */
		sys34->eprim_sq = sys34->e_sq / (cs_One - sys34->e_sq);

		/* The coefficients for the M calculations. */
		CSmmFsu (&sys34->mmcofF,sys34->e_rad,sys34->e_sq);
		CSmmIsu (&sys34->mmcofI,sys34->e_rad,sys34->e_sq);
	}

	/* Need to compute the maximum value of X which can be
	   supported mathematically.  This is, essentially, the
	   value generated by a del_lng of a skosh less than
	   90 degrees at the equator.  Since most all the setup
	   is complete, we can use the CSsys34F function to
	   compute this for us. */

	test_ll [LNG] = CS_adj2pi (sys34->cent_lng + cs_EETest) * cs_Radian;
	test_ll [LAT] = cs_Zero;
	CSsys34F (sys34,test_ll,test_ll);							   //lint !e534
	sys34->xx_max = fabs (test_ll [XX]);

	/* Set up the coordinate checking information.  If the user has
	   specified a useful range, we use it without checking it.
	   Otherwise, we compute what I, the programmer, consider to
	   be the useful range of the projection.  Note, values are in
	   degrees and longitude values are relative to the central
	   meridian. */
	csprm->cent_mer = sys34->cent_lng * cs_Radian;
	if (csprm->csdef.ll_min [LNG] == 0.0 && csprm->csdef.ll_min [LAT] == 0.0 &&
	    csprm->csdef.ll_max [LNG] == 0.0 && csprm->csdef.ll_max [LAT] == 0.0)
	{
		/* We use values used by the source of the code which we use.  We
		   presume these values are good numbers.  Note, the source limits
		   were originally in UTM.  In converting them to geographic form
		   we liberalized a bit more. */
		switch (sys34->region) {
		default:
		case 1:
			csprm->min_ll [LNG] =  6.00 - csprm->cent_mer;
			csprm->min_ll [LAT] = 53.00;
			csprm->max_ll [LNG] = 16.00 - csprm->cent_mer;
			csprm->max_ll [LAT] = 58.50;
			break;
		case 2:
			csprm->min_ll [LNG] =  7.25 - csprm->cent_mer;
			csprm->min_ll [LAT] = 53.00;
			csprm->max_ll [LNG] = 17.30 - csprm->cent_mer;
			csprm->max_ll [LAT] = 57.50;
			break;
		case 3:
			csprm->min_ll [LNG] = 13.25 - csprm->cent_mer;
			csprm->min_ll [LAT] = 54.00;
			csprm->max_ll [LNG] = 17.00 - csprm->cent_mer;
			csprm->max_ll [LAT] = 56.25;
			break;
		}
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
	if (csprm->csdef.xy_min [XX] == 0.0 && csprm->csdef.xy_min [YY] == 0.0 &&
		csprm->csdef.xy_max [XX] == 0.0 && csprm->csdef.xy_max [YY] == 0.0)
	{
		/* Again, these values are from the source of information on the Danish
		   system. */
		switch (sys34->region) {
		default:
		case 1:
			csprm->min_xy [XX] =  100000.0;
			csprm->min_xy [YY] = -500000.0;
			csprm->max_xy [XX] =  100000.0;
			csprm->max_xy [YY] =  500000.0;
			break;
		case 2:
			csprm->min_xy [XX] = -400000.0;
			csprm->min_xy [YY] = -100000.0;
			csprm->max_xy [XX] =  100000.0;
			csprm->max_xy [YY] =  400000.0;
			break;
		case 3:
			csprm->min_xy [XX] = -150000.0;
			csprm->min_xy [YY] =  -50000.0;
			csprm->max_xy [XX] =  150000.0;
			csprm->max_xy [YY] =   50000.0;
			break;
		}
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
	   Set up the internal function calls.  Note, since the
	   Transverse Mercator is a conformal projection, the
	   H and K scale factors are the same.  Therefore, we
	   set all three scale function pointers to the same
	   function. */
	csprm->ll2cs    = (cs_LL2CS_CAST)CSsys34F;
	csprm->cs2ll    = (cs_CS2LL_CAST)CSsys34I;
	csprm->cs_scale = (cs_SCALE_CAST)CSsys34K;
	csprm->cs_sclk  = (cs_SCALK_CAST)CSsys34K;
	csprm->cs_sclh  = (cs_SCALH_CAST)CSsys34K;
	csprm->cs_cnvrg = (cs_CNVRG_CAST)CSsys34C;
	csprm->llchk    = (cs_LLCHK_CAST)CSsys34L;
	csprm->xychk    = (cs_XYCHK_CAST)CSsys34X;

	return;
}

/**********************************************************************
**	rtn_val = CSsys34F (sys34,xy,ll);
**
**	struct cs_Trmer_ *sys34;	structure containing all parameters necessary
**								for the transformation.
**	double xy [2];				converted values are returned here, x ([0])
**								and y ([1]).
**	double ll [2];				the longitude ([0]) and latitude ([1]) values
**								to be converted, in degrees.
**	int rtn_val;				returns cs_CNVRT_NRML if result is normal;
**								cs_CNVRT_RNG if value to be converted is
**								outside of mathematical scope of the
**								projection.
**
**	The ll and the xy arrays may share the same memory with no
**	adverse affects.  Yes, much of this code duplicates the
**	standard transverse mercator code, but we do this to avoid
**  a ton of spaghetti.
**
**********************************************************************/
int EXP_LVL9 CSsys34F (Const struct cs_Sys34_ *sys34,double xy [2],Const double ll [2])
{
	extern double cs_Degree;			/* 1.0 / 57.29577... */
	extern double cs_Pi;				/* 3.14159... */
	extern double cs_Pi_o_2;			/* Pi over two */
	extern double cs_Mpi_o_2;			/* minus Pi over two */
	extern double cs_Zero;				/* 0.0 */
	extern double cs_Half;				/* 0.5 */
	extern double cs_One;				/* 1.0 */
	extern double cs_Mone;				/* -1.0 */
	extern double cs_Four;				/* 4.0 */
	extern double cs_Five;				/* 5.0 */
	extern double cs_Nine;				/* 9.0 */
	extern double cs_AnglTest;			/* .001 seconds of arc in
										   radians. */
	extern double cs_AnglTest1;			/* 1.0 minus .001 seconds of
										   arc radians. */
	extern double cs_NPTest;			/* .001 seconds of arc
										   short of the north pole,
										   in radians. */
	extern double cs_SPTest;			/* .001 seconds of arc
										   short of the south pole,
										   in radians. */
	extern double cs_EETest;			/* .001 seconds of arc
										   short of 90 degrees,
										   in radians. */
	extern double cs_WETest;			/* .001 seconds of arc
										   short of -90 degrees,
										   in radians. */
	extern double cs_Huge;				/* An approximation of
										   infinity, 1.0E+37,
										   but not so large as
										   we can't use it in
										   calculations. */
	extern double cs_Mhuge;				/* Negative infinity. */

	int rtn_val;
	int status;

	double lng, lat;
	double xx, yy;
	double del_lng;

	double sin_lat;
	double cos_lat;
	double tan_lat;
	double tan_lat_sq;

	double nu;
	double eta_sq;

	double A1;
	double A2;
	double A3;
	double A4;
	double A5;
	double A6;
	double A7;
	double B;
	double L;
	double L_sq;
	double M;

	double tmp1;

	rtn_val = cs_CNVRT_NRML;
	lng = ll [LNG] * cs_Degree;
	lat = ll [LAT] * cs_Degree;

	/* Adjust the input values, if necessary, to prevent a domain error. */
	if (fabs (lat) > cs_NPTest)
	{
		/* Latitude is on, or beyond, a pole. */
		rtn_val = cs_CNVRT_INDF;
		if (fabs (lat) > cs_Pi_o_2)
		{
			rtn_val = cs_CNVRT_RNG;
			lat = CS_adj1pi (lat);
		}
		if (lat >= cs_NPTest)
		{
			/* North Pole */
			sin_lat = cs_One;
			cos_lat = cs_Zero;
			tan_lat = cs_Huge;
			lat = cs_Pi_o_2;
		}
		else if (lat <= cs_SPTest)
		{
			/* South Pole */
			sin_lat = cs_Mone;
			cos_lat = cs_Zero;
			tan_lat = cs_Mhuge;
			lat = cs_Mpi_o_2;
		}
		else
		{
			sin_lat = sin (lat);
			cos_lat = cos (lat);
			tan_lat = sin_lat / cos_lat;
		}
	}
	else
	{
		/* Otherwise.  Since we have handled the poles,
		   cos (lat) should never be zero here. */
		sin_lat = sin (lat);
		cos_lat = cos (lat);
		tan_lat = sin_lat / cos_lat;
	}

	/* We used cs_Huge above as it isn't so huge as to make the following fail. */
	tan_lat_sq = tan_lat * tan_lat;

	/* That's the latitude, deal with the longitude now. */
	del_lng = lng - sys34->cent_lng;

	/* The following statement deals with the issue of the -180 crack.
	   For example, if the central meridian is -179, and the provided
	   longitude is +179, we want a del_lng of -2. */
	if (fabs (del_lng) > cs_Pi) del_lng = CS_adj2pi (del_lng);

	/* We can't allow a del_lng value to get too close to PI over 2
	   (i.e. 90 degrees) if the cosine of the latitude is one
	   (i.e. the equator).  Otherwise, all longitude values can be
	   handled.  Note, that we allow delta longitude values greater
	   than 90, it's the specific value of 90 that causes trouble.
	   When delta longitude exceeds 90, the projection just wraps
	   back on itself, thus providing the "rational" results which
	   we must return. */
	if (del_lng > cs_EETest || del_lng < cs_WETest)
	{
		rtn_val = cs_CNVRT_RNG;
		if (fabs (fabs (del_lng) - cs_Pi_o_2) < cs_AnglTest &&
		    fabs (cos_lat) > cs_AnglTest1)
		{
			/* Opps!!! We're in never never land. */
			if (del_lng < 0.0)
			{
				del_lng = cs_Mpi_o_2 + cs_AnglTest;
			}
			else
			{
				del_lng = cs_Pi_o_2 - cs_AnglTest;
			}
		}
	}

	/* OK, we can do our thing pretty safely now. */
	if (sys34->ecent == 0.0)
	{
		/* Here for a sphere.  If the above was written
		   correctly, B will never be precisely +- 1. */
		B = cos_lat * sin (del_lng);
		tmp1 = (cs_One + B) / (cs_One - B);
		xy [XX] = sys34->Rk_ovr_2 * log (tmp1);

		tmp1 = tan_lat / cos (del_lng);
		xy [YY] = sys34->Rk * (atan (tmp1) - sys34->org_lat);
	}
	else
	{
		/* Here for the ellipsoid, using Meade's nested solution.
		   A bit more precise, and significantly faster than
		   Snyder's adaptation of Redfearn's equation which was
		   used previously. */
		eta_sq = sys34->eprim_sq * cos_lat * cos_lat;
		M = CSmmFcal (&sys34->mmcofF,lat,sin_lat,cos_lat);

		tmp1 = sys34->e_sq * sin_lat * sin_lat;
		nu = sys34->e_rad / sqrt (cs_One - tmp1);
		A1 = sys34->k * nu;
		A2 = cs_Half * sys34->k * nu * tan_lat;
		A3 = (1.0 / 6.0) * (cs_One - tan_lat_sq + eta_sq);
		A4 = (1.0 / 12.0) * (cs_Five - tan_lat_sq + eta_sq * (cs_Nine + cs_Four * eta_sq));
		tmp1  = cs_Five - tan_lat_sq * (18.0 - tan_lat_sq);
		tmp1 += eta_sq * (14.0 - 58.0 * tan_lat_sq);
		A5 = (1.0 / 120.0) * tmp1;
		tmp1 = 61.0 - tan_lat_sq * (58.0 - tan_lat_sq);
		tmp1 += eta_sq * (270.0 - 330.0 * tan_lat_sq);
		A6 = (1.0 / 360.0) * tmp1;
		A7 = (1.0 / 5040.0) * (61.0 - tan_lat_sq * (479.0 -
													179.0 * tan_lat_sq +
													tan_lat_sq * tan_lat_sq));
		L = del_lng * cos_lat;
		L_sq = L * L;

		xy [XX] = ((((A7 * L_sq) + A5) * L_sq + A3) * L_sq + cs_One) * A1 * L;
		xy [YY] = ((((A6 * L_sq) + A4) * L_sq + cs_One) * A2 * L_sq) + sys34->k * M;
	}
	xy [XX] += 500000.0;

	/* OK, we have UTM (northern zone) coordinates now.  We apply the appropriate
	   Danish polynomial expansion to produce Danish Cartesian coordinates. */
	switch (sys34->region) {
	default:
		rtn_val = cs_CNVRT_RNG;
	case 1:														  //lint !e616 
		status = TransformUTM32_S34J (xy [XX],xy [YY],&xx,&yy,sys34->vintage);
		break;
	case 2:	 
		status = TransformUTM32_S34S (xy [XX],xy [YY],&xx,&yy,sys34->vintage);
		break; 
	case 3:
		status = TransformUTM33_S45B (xy [XX],xy [YY],&xx,&yy,sys34->vintage);
		break;
	}
	xy [XX] = xx;
	xy [YY] = yy;
	if (status != 0) rtn_val = cs_CNVRT_RNG;

	CS_quadF (xy,xy [XX],xy [YY],cs_Zero,cs_Zero,sys34->quad);
	return rtn_val;
}
/**********************************************************************
**	rtn_val = CSsys34I (sys34,ll,xy);
**
**	struct cs_Trmer_ *sys34;	structure detailing the Transverse Mercator
**								coordinate system in use.
**	double ll [2];				converted results returned here, longitude ([0])
**								and latitude ([1]), in degrees.
**	double xy [2];				coordinates to be converted are obtained from
**								here, x ([0]) and y ([1]).
**	int rtn_val;				returns cs_CNVRT_NRML if result is normal;
**								cs_CNVRT_RNG if value to be converted is
**								outside of mathematical scope of the
**								projection.
**
**	The xy and ll arrays may share the same memory.
**********************************************************************/
int EXP_LVL9 CSsys34I (Const struct cs_Sys34_ *sys34,double ll [2],Const double xy [2])
{
	extern double cs_Pi;				/* Pi = 3.14159... */
	extern double cs_Pi_o_2;			/* PI / 2.0 */
	extern double cs_Radian;			/* 57.29577... */
	extern double cs_Zero;				/* 0.0 */
	extern double cs_One;				/* 1.0 */
	extern double cs_Two;				/* 2.0 */
	extern double cs_Three;				/* 3.0 */
	extern double cs_Four;				/* 4.0 */
	extern double cs_Five;				/* 5.0 */
	extern double cs_Six;				/* 6.0 */
	extern double cs_Eight;				/* 8.0 */
	extern double cs_Nine;				/* 9.0 */
	extern double cs_AnglTest;			/* 0.001 seconds of arc,
										   in radians. */

	int rtn_val;
	int status;

	double xx;
	double yy;

	double lat;
	double del_lng;

	double phi1;
	double sin_phi1;
	double cos_phi1;
	double tan_phi1;
	double tan_phi1_sq;

	double eta1_sq;
	double nu1;
	double B2;
	double B3;
	double B4;
	double B5;
	double B6;
	double B7;
	double D;
	double L;
	double M;
	double Q;
	double Q_sq;

	double tmp1;
	double tmp2;

	double myXY [3];

	rtn_val = cs_CNVRT_NRML;

	/* Undo whatever quad stuff may be in place. */
	CS_quadI (&xx,&yy,xy,cs_Zero,cs_Zero,sys34->quad);
	myXY [XX] = xx;
	myXY [YY] = yy;
	myXY [ZZ] = cs_Zero;

	/* Apply the Danish polynomial to give us UTM's. */
	switch (sys34->region) {
	default:
		rtn_val = cs_CNVRT_RNG;
	case 1:														  //lint !e616 
		status = TransformS34J_UTM32 (myXY [XX],myXY [YY],&xx,&yy,sys34->vintage);
		break;
	case 2: 
		status = TransformS34S_UTM32 (myXY [XX],myXY [YY],&xx,&yy,sys34->vintage);
		break; 
	case 3:
		status = TransformS45B_UTM33 (myXY [XX],myXY [YY],&xx,&yy,sys34->vintage);
		break;
	}
	if (status != 0) rtn_val = cs_CNVRT_RNG;
	xx -= 500000.0;

	/* Convert the UTM's to geographic coordinates.  Your right!!!
	   lots of duplicated code here.  We prefer duplicated code to
	   spaghetti code.

	   Deal with the limiting xx case.  Xx_max is the value which
	   the forward function returns for a latitude of zero and
	   a delta longitude of +-90.0 degrees.  This is the limit
	   of the map.  In any case, it is about 10 times the
	   scaled radius of the earth (Rk).

	   Since latitude is determined primarily by the sin (yy/R),
	   it wraps around automatically.  Therefore, there is no
	   mathematical limit on Y. */
	if (fabs (xx) > sys34->xx_max)
	{
		rtn_val = cs_CNVRT_RNG;
		xx = (xx >= 0.0) ? sys34->xx_max : -sys34->xx_max;
	}

	if (sys34->ecent == 0.0)
	{
		/* Here for a sphere.  From Snyder. */
		D = yy / sys34->Rk + sys34->org_lat;
		tmp1 = xx / sys34->Rk;

		tmp2 = sin (D) / cosh (tmp1);	/* cosh is never < 1 */
		lat = asin (tmp2);

		/* Careful, cos (D) is zero at the poles. */
		tmp2 = cos (D);
		if (fabs (tmp2) > cs_AnglTest)
		{
			del_lng = atan2 (sinh (tmp1),tmp2);
		}
		else
		{
			/* Longitude is undefined at the poles, so
			   we return a cs_CNVRT_INDF. */
			del_lng = cs_Zero;
			rtn_val = cs_CNVRT_INDF;
		}
	}
	else
	{
		/* Here for an ellipsoid.  Phi1 is the footprint
		   latitide, which may (unlikely but possible) be
		   a pole.  We use Synder, page 63 for the footprint
		   latitude. */
		M = yy / sys34->k;
		phi1 = CSmmIcal (&sys34->mmcofI,M);
		cos_phi1 = cos (phi1);
		if (fabs (cos_phi1) < cs_AnglTest)
		{
			/* Here for a pole.  The longitude is not
			   defined at wither pole, so we return
			   cs_CNVRT_INDF to indicate this. */
			del_lng = cs_Zero;
			lat = (phi1 < 0.0) ? -cs_Pi_o_2 : cs_Pi_o_2;
			rtn_val = cs_CNVRT_INDF;
		}
		else
		{
			sin_phi1 = sin (phi1);
			tan_phi1 = sin_phi1 / cos_phi1;
			tan_phi1_sq = tan_phi1 * tan_phi1;

			/* Using Meade's nested solution.  From
			   Maling, page 447. */
			tmp1 = cs_One - sys34->e_sq * sin_phi1 * sin_phi1;
			nu1 = sys34->e_rad / sqrt (tmp1);

			eta1_sq = sys34->eprim_sq * cos_phi1 * cos_phi1;

			Q = xx / (sys34->k * nu1);
			Q_sq = Q * Q;

			B2 = (-1.0 / 2.0) * tan_phi1 * (cs_One + eta1_sq);

			B3 = (-1.0 / 6.0) * (cs_One + cs_Two * tan_phi1_sq + eta1_sq);

			tmp1 = cs_One - cs_Nine * tan_phi1_sq - cs_Four * eta1_sq;
			tmp1 = cs_Five + cs_Three * tan_phi1_sq + eta1_sq * tmp1;
			B4   = (-1.0 / 12.0) * tmp1;

			tmp1  = eta1_sq * (cs_Six + cs_Eight * tan_phi1_sq);
			tmp1 += tan_phi1_sq * (28.0 + 24.0 * tan_phi1_sq);
			B5 = (1.0 / 120.0) * (cs_Five + tmp1);

			/* Some programs use 60 in place of 90 in the following.
			   I believe the 90 is correct.  The difference this
			   makes is very small.  Perhaps why the bug in those
			   programs has never been found.  I've never had bugs
			   like that, of course :-). */
			tmp1 = 46.0 - 252.0 * tan_phi1_sq - 90.0 * (tan_phi1_sq * tan_phi1_sq);
			tmp1 = tan_phi1_sq * (90.0 + 45.0 * tan_phi1_sq) + eta1_sq * tmp1;
			B6   = (61.0 + tmp1) * (1.0 / 360.0);

			tmp1 = 662.0 + 1320.0 * tan_phi1_sq + 720.0 * (tan_phi1_sq * tan_phi1_sq);
			B7   = (-1.0 / 5040.0) * (61.0 + tan_phi1_sq * tmp1);

			L = Q * (cs_One + Q_sq * (B3 + Q_sq * (B5 + B7 * Q_sq)));
			del_lng = L / cos_phi1;

			lat = phi1 + B2 * Q_sq * (cs_One + Q_sq * (B4 + B6 * Q_sq));
		}
	}

	if (fabs (del_lng) > cs_Pi)
	{
		rtn_val = cs_CNVRT_RNG;
		del_lng = CS_adj2pi (del_lng);
	}
	ll [LNG] = (del_lng + sys34->cent_lng) * cs_Radian;
	ll [LAT] = lat * cs_Radian;
	return (rtn_val);
}
/**********************************************************************
**	alpha = CSsys34C (sys34,ll);
**
**	struct m_Trmer_ *sys34;		structure containing all parameters
**									necessary for the transformation.
**	double ll [2];				location of the point to be computed
**								is given here; longitude ([0]) and
**								latitude ([1]) in degrees.
**	double alpha;				the convergence angle, in degrees;
**								i.e. the deviation btewteen true
**								north and grid north.
**
**	We calculate this empirically, no known analytical formula.
**********************************************************************/
double EXP_LVL9 CSsys34C (Const struct cs_Sys34_ *sys34,Const double ll [2])
{
	extern double cs_Radian;			/* 57.2957... */
	extern double cs_Km360;				/* -360.0, the value which
										   we return if provided
										   with a bogus point. */
	int status;

	double del_xx;
	double del_yy;
	double gamma;				/* some folks call this alpha */

	double xy1 [3];
	double xy2 [3];
	double my_ll [3];

	/* We have no analytical formulas for any of the aspects/variations
	   supported. Therefore, we can handle all cases with the simple
	   empirical algorithm below. */
	my_ll [LNG] = ll [LNG];
	my_ll [LAT] = ll [LAT];

	/* Compute the cartesian coordinates of the end points of a
	   linear line segment whose end points are on the same meridian,
	   but separated by a small amount of latitude.  The degree of
	   latitude separation is rather arbitrary.  Technically, the
	   smaller the better, but if its too small, we end up with
	   noise problems in the trig functions.  0.00005 gives us a
	   line of about 10 meters on the surface of the earth.  We
	   use literal constants as this may need to be adjusted to
	   the mathemagics of the specific projection involved. */
	my_ll [LAT] -= 0.00005;
	status = CSsys34F (sys34,xy1,my_ll);
	if (status != cs_CNVRT_NRML)
	{
		return (cs_Km360);
	}
	my_ll [LAT] += 0.0001;		/* 2 * 0.00005 */
	status = CSsys34F (sys34,xy2,my_ll);
	if (status != cs_CNVRT_NRML)
	{
		return (cs_Km360);
	}
	
	/* Some atan2's (not all) don't like it when both arguments are
	   zero. Normally, it is safe to assume that del_yy is never
	   zero given the above. However, testing has shown that when
	   provided with unrealistic locations, both del_xx and del_yy
	   can be zero (exactly on the pole where the pole is
	   the origin). */
	del_xx = xy2 [XX] - xy1 [XX];
	del_yy = xy2 [YY] - xy1 [YY];
	if ((fabs (del_xx) + fabs (del_yy)) >= sys34->one_mm)
	{
		gamma = -atan2 (del_xx,del_yy) * cs_Radian;
	}
	else
	{
		gamma = cs_Km360;
	}
	return (gamma);
}
/**********************************************************************
**	k = CSsys34K (sys34,ll);
**
**	struct m_Trmer_ *sys34;		structure containing all parameters
**								necessary for the transformation.
**	double ll [2];				location of the point to be computed
**								is given here; longitude ([0]) and
**								latitude ([1]) in degrees.
**	double k;					the true map scale factor at the
**								specified point.  Should be
**								compared with the sys34->k.
**********************************************************************/
double EXP_LVL9 CSsys34K (Const struct cs_Sys34_ *sys34,Const double ll [2])
{
	extern double cs_SclInf;		/* 9.9E+04, the value we return
									   for an infinite scale
									   factor. */
	extern double cs_HlfSecDeg;		/* One half arc second in
									   degrees. */

	double kk;
	double ll_dd;
	double xy_dd;
	double del_xx, del_yy;

	double xy1 [2];
	double xy2 [2];
	double ll1 [2];
	double ll2 [2];

	/* Establish two points along the parallel which are
	   about 1 second (about 30 meters) apart from each
	   other, with the point in question in the middle.
	   Then convert each point to the equivalent grid
	   coordinates. */

	ll1 [LNG] = ll [LNG];
	ll1 [LAT] = ll [LAT] - cs_HlfSecDeg;
	CSsys34F (sys34,xy1,ll1);					/*lint !e534 */

	ll2 [LNG] = ll [LNG];
	ll2 [LAT] = ll [LAT] + cs_HlfSecDeg;
	CSsys34F (sys34,xy2,ll2);					/*lint !e534 */

	/* Calculate the geodetic distance between the two lat/long
	   points.  Note, we provide the geodetic calculator with
	   the scaled radius of the earth so that the distance
	   it computes will be in the same units as the X and
	   Y coordinates. */

	CS_llazdd (sys34->Rk,sys34->e_sq,ll1,ll2,&ll_dd);

	/* Calculate the grid distance between the two points. */

	del_xx = xy1 [XX] - xy2 [XX];
	del_yy = xy1 [YY] - xy2 [YY];
	xy_dd = sqrt (del_xx * del_xx + del_yy * del_yy);

	/* Return the ratio of the two distances as the parallel
	   scale factor at the indicated point.  I don't think
	   ll_dd can be zero since we know that ll1 id not the
	   same as ll0.  However, just to be safe: */

	if (fabs (ll_dd) > sys34->one_mm)
	{
		kk = xy_dd / ll_dd;
	}
	else
	{
		kk = cs_SclInf;
	}
	return (kk);
}
/**********************************************************************
**	status = CSsys34L (sys34,cnt,pnts);
**
**	struct cs_Trmer_ *sys34;	the coordinate system against which the check is
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
int EXP_LVL9 CSsys34L (Const struct cs_Sys34_ *sys34,int cnt,Const double pnts [][3])
{
	int status;

	/* Check all the points. */

	status = cs_CNVRT_OK;
	return (status);
}
/**********************************************************************
**	status = CSsys34X (sys34,cnt,pnts);
**
**	struct cs_Trmer_ *sys34;	coordinate system definition
**	int cnt;					number of points in the pnts array.
**	double pnts [][3];			an array of three dimensional points which
**								define a point, line, or region to be checked.
**	int status;					returns the status of the check; see remarks
**								below.
**
**	The values provided in the pnts array are required to be
**	cartesian coordinates.  Use CSsys34L to check lat/long
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
int EXP_LVL9 CSsys34X (Const struct cs_Sys34_ *sys34,int cnt,Const double pnts [][3])
{
	int rtn_val;

	rtn_val = cs_CNVRT_OK;

	/* All Y values are within the domain of the function.  However,
	   in the cartesian frame of reference, an absolute value of
	   X greater than xx_max is outside of the domain. */
	return (rtn_val);
}

/******************************************************************************
 ******************************************************************************
 Start of the 6 polynomial transformations used for Danish coordinate systems.
 These were supplied by Lars Neilson of KAMPSAX to do the conversion between
 the Danish coordinate systems and the UTM zone they are in.

 Dec 18 '98 -- there is a new version of these methods supplied by
 KampSax. We will use this new version.

 Here's the function we will be calling:

int uts34 (	double Nin, 
			double Ein,
			double *yout,
			double *xout,
			int lansdel,
			int direct
		  );

	Mentor has removed other parameters
	dealing with error reporting.

Function and parameters

Dual autochecking transformation (prediction) function for

		UTM zone 32, ED50 <-> System 1934 Jylland
		UTM zone 32, ED50 <-> System 1934 Sjælland
		UTM zone 33, ED50 <-> System 1934/45 Bornholm

The function gives the result of the transformation as

		uts34 = 0        => ok, 
		uts34 = -1       => Hard error.
		uts34 = +1       => Range error.

The physical precision of the transformation is generally
1-2 cm, but the numerical precision is generally some few
mm, increasing to some cm far from the central parts. 

Nin
Ein		-->	UTM or s34 coordinates input for transformation in
			metres.  See note below concerning the orientation
			of axes.

*yout
*xout	-->	s34 or UTM coordinates output after transformation
			in metres.  see note below concerning the orientation
			of the axes.

landsdel-->	Control of the used coordinate systems.
				landsdel = 'j' (or 1) => UTM 32 <-> S34 Jylland
				landsdel = 's' (or 2) => UTM 32 <-> S34 Sjælland
				landsdel = 'b' (or 3) => UTM 33 <-> S34 (= S45) Bornholm

direct	-->	Control of the direction of transformation.
				direct >= 0 =>  UTM -> s34
				direct <  0 =>  s34 -> UTM

The tolerance is set by a define statement to 6 cm, and may
be redefined. The chosen value is comparable to the precision
of the polynomial approximation.

Prog: Knud Poder, APR 1991

	 And these further notes:

Ah! Sorry about that. It has to do with the definition of the damn projections.
You might not have gotten that info the last time, so here goes:

	The System 1934/45 projections all have an X axis towards west (!) and a
	Y axis toward north. Normally the coordinates are given as (Y,X). And the
	rotation in these systems (as in the DSFL format) is clockwise from X toward
	Y, giving e.g. north = 100 grads, east=200 grads etc. (400 degree system!).

	One way of dealing with this problem (that MicroStation and AutoCAD
	sometimes use) is to rotate the view 90 degrees clockwise, so X->Y and
	Y->X. And suddenly you have a mathematical system (except for the
	rotation off course)

	However, we instead use the schema that all X values are negative, giving
	a (-X , +Y), mathematical system. So the solution is just to switch the
	signs on all System 1934/45 X values going into and coming out of the
	routine.

*******************************************************************************


********************************************************************************
********************************************************************************
** Mentor has now added the "vintage" parameter to all this.   This parameter **
** selects between the two (currently) different sets of polynomials used     **
** for the calculation.  A value of 1999 specifies the set of polynomials     **
** devised in November 1999.  Any other value (currently) indicates the       **
** original set of polynomials (which we also refer to as pre-1999).          **  
********************************************************************************
********************************************************************************


******************************************************************************/

/* Inverse for three zones, three functions. */
int TransformS34J_UTM32 (double x1, double y1,double* x2, double* y2,short vintage)
{ 	/*lint !e578 */ 
    return uts34 (-x1,y1,x2,y2,'j',-1,vintage);
}
int TransformS34S_UTM32 (double x1, double y1,double* x2, double* y2,short vintage) 	/*lint !e578 */ 
{
    return uts34 (-x1,y1,x2,y2,'s',-1,vintage);
}
int TransformS45B_UTM33 (double x1,double y1,double* x2,double* y2,short vintage) 	/*lint !e578 */ 
{
    return uts34 (-x1,y1,x2,y2,'b',-1,vintage);
}

/* Forward for three zones, three functions. */
int TransformUTM32_S34J (double x1, double y1,double* x2,double* y2,short vintage) 	/*lint !e578 */ 
{
    int err;
	
	err = uts34 (x1,y1,x2,y2,'j',1,vintage);
    *x2 = -*x2;
	return err;
}
int TransformUTM32_S34S (double x1,double y1,double *x2, double *y2,short vintage) 	/*lint !e578 */ 
{
    int err;
	
	err = uts34 (x1,y1,x2,y2,'s',1,vintage);
    *x2 = -*x2;
	return err;
}
int TransformUTM33_S45B (double x1,double y1,double *x2,double *y2,short vintage) 	/*lint !e578 */ 
{
    int err;
	
	err = uts34 (x1,y1,x2,y2,'b',1,vintage);
    *x2 = -*x2;
	return err;
}

/******************************************************************************
This is code supplied by Lars Nielson of Denmark -- it does the "new" Danish
transformation and is called from the stub functions above.

uts34.c  version 2.0             # page 1   01 Jul 1994 11 40
******************************************************************************/

#define  TOL    0.060   /* 6 cm */
#define  TRFSTOP   -1

#define  S34JYMAX    +500000.0
#define  S34JYMIN    -100000.0
#define  S34JXMAX    +500000.0
#define  S34JXMIN    -100000.0

#define  S34SYMAX    +400000.0
#define  S34SYMIN    -100000.0
#define  S34SXMAX    +400000.0
#define  S34SXMIN    -100000.0

#define  S45BYMAX    +150000.0
#define  S45BYMIN     -50000.0
#define  S45BXMAX    +150000.0
#define  S45BXMIN     -50000.0

#define  U32JNMAX   +6500000.0
#define  U32JNMIN   +5900000.0
#define  U32JEMAX    +900000.0
#define  U32JEMIN    +300000.0

#define  U32SNMAX   +6400000.0
#define  U32SNMIN   +5900000.0
#define  U32SEMAX   +1000000.0
#define  U32SEMIN    +400000.0

#define  U33BNMAX   +6200000.0
#define  U33BNMIN   +6000000.0
#define  U33BEMAX    +600000.0
#define  U33BEMIN    +400000.0

#define  U32BNMAX   +6200000.0			/* These are used in 1999 vintage */
#define  U32BNMIN   +6000000.0
#define  U32BEMAX   +1100000.0
#define  U32BEMIN    +650000.0

/******************************************************************************

	Function: Coordinate predictions  UTM <-> System 1934/45.

	See uts34.h for function and parameter descriptions.

	Prog: Knud Poder, APR 1991
*******************************************************************************/

int uts34 (double Ein,double Nin,double *xout,double *yout,int landsdel,int direct,short vintage)
{
	extern char csErrnam [];

	int    r;
	int    c;
	int    i;
	int    g, sz;
	int    ins;
	int    rtnValue;
	int    loopLimit;

	double N, E, n, e, u, v;
	double tol = TOL;
	double *tcy, *tcx;
	double *cb, *cw, *cbu, *cbs;
	double utmNmax, utmNmin, utmEmax, utmEmin;
	double s34ymax, s34ymin, s34xmax, s34xmin;

	/* The following arrays contain the coeficients of the polynomial expansion
	   used to convert directly from UTM's to the Danish systems directly, and
	   vice-versa. */

	static double C_utj[] = 
	{
		/*deg*/   11.0,

		/*  0*/   1.7960842195e+05,   1.0001331975e+00,  -7.0305752009e-11,
		/*  3*/  -1.5599420745e-17,   1.5445877248e-20,   4.3890319833e-27,
		/*  6*/  -1.6183338075e-30,  -5.5641640524e-37,   7.3168052174e-41,
		/*  9*/  -5.5681331488e-48,  -1.1898800529e-51,   9.3729805349e-58,

		/* 12*/  -1.9983146896e-02,  -7.1626220918e-10,   8.7005607599e-16,
		/* 15*/   1.2803413015e-20,  -1.4192641776e-25,  -1.8600522253e-30,
		/* 18*/   1.9254375816e-35,   9.7422133101e-41,  -1.0624197027e-45,
		/* 21*/  -1.8966913523e-51,   1.9980063231e-56,

		/* 23*/  -1.7603869211e-12,   2.5245131678e-16,   1.3597334098e-20,
		/* 26*/  -7.5221602147e-26,  -2.7274916388e-30,   1.7704978387e-35,
		/* 29*/   1.8929469769e-40,  -1.0042146080e-45,  -4.1023552391e-51,
		/* 32*/   1.8978875611e-56,

		/* 33*/   5.7374729469e-16,   2.3204950467e-20,   8.7584452002e-27,
		/* 36*/  -4.8904451142e-30,  -1.1337223340e-35,   4.1563308436e-40,
		/* 39*/   1.5263628169e-46,  -1.0101062278e-50,   9.0844218534e-57,

		/* 42*/  -1.7132615557e-21,  -6.2105384175e-26,  -1.6823635928e-30,
		/* 45*/   1.6338290176e-36,   2.1158815380e-40,  -1.6702393830e-45,
		/* 48*/  -7.7415150086e-51,   6.9013410030e-56,

		/* 50*/  -2.3212292992e-25,  -5.7098757419e-30,   1.5740531826e-35,
		/* 53*/   2.6141821121e-40,  -1.0605463305e-47,  -1.2050013481e-50,
		/* 56*/   2.8385992577e-56,

		/* 57*/   7.9684988821e-31,   2.7211973029e-35,   8.0324755310e-41,
		/* 60*/  -3.6485695942e-46,  -4.8480161004e-51,   4.0649973635e-56,

		/* 63*/   2.7115342914e-35,   7.8845858899e-40,  -2.0021883419e-45,
		/* 66*/  -6.1709534864e-51,   3.8404725036e-57,

		/* 68*/  -1.0306208435e-40,  -4.0856355905e-45,  -1.1672995447e-51,
		/* 71*/   2.7626939792e-56,

		/* 72*/  -1.0278262874e-45,  -3.7985179164e-50,   6.3788054699e-56,

		/* 75*/   4.7752796291e-51,   2.2043753586e-55,

		/* 77*/  -4.0961492683e-58,

		/* Y0*/   6211357.565339,

		/*  0*/   2.5988574773e+05,  -1.0001338073e+00,   3.9172295418e-10,
		/*  3*/  -3.4230073667e-16,  -2.2818377692e-20,   2.1440199329e-25,
		/*  6*/   5.0019389048e-30,  -4.2830573831e-35,  -4.9751246757e-40,
		/*  9*/   3.7732561187e-45,   1.8115194532e-50,  -1.2659446185e-55,

		/* 12*/  -1.9981958478e-02,   5.2102757590e-11,  -7.2308108818e-16,
		/* 15*/  -1.5870040358e-20,   3.7855942153e-26,   4.7234232696e-30,
		/* 18*/  -1.2547212518e-35,  -5.6120363216e-40,   2.4802558487e-45,
		/* 21*/   2.4254823739e-50,  -1.3399659168e-55,

		/* 23*/  -2.9832623581e-10,   7.9794592713e-16,  -8.2061470916e-21,
		/* 26*/  -2.1412572954e-25,   2.2549092808e-30,   1.9760544576e-35,
		/* 29*/  -1.9648841365e-40,  -3.5791956901e-46,   8.3762565587e-51,
		/* 32*/  -4.4779684691e-56,

		/* 33*/   2.8705133213e-16,  -1.0202379712e-20,   1.0004204096e-25,
		/* 36*/   1.5892199642e-30,  -7.9348236615e-36,  -2.4206841313e-40,
		/* 39*/   7.3271996448e-46,   1.2265781762e-50,  -7.9885986352e-56,

		/* 42*/  -9.4293323888e-21,  -6.7854867401e-26,   9.9314808084e-31,
		/* 45*/   1.3740841353e-35,  -1.9398881618e-40,  -5.2827833902e-46,
		/* 48*/   7.4555864194e-51,   1.6454728774e-56,

		/* 50*/  -2.9275805707e-26,   1.6912863842e-30,  -1.2123373007e-35,
		/* 53*/  -8.2283656974e-41,   6.7747175215e-46,   8.9516881385e-52,
		/* 56*/   2.6709952284e-56,

		/* 57*/   8.2179431990e-31,   1.7941344576e-36,  -4.8498850776e-41,
		/* 60*/  -1.7705494231e-46,   5.9031266038e-51,  -3.5754574387e-56,

		/* 63*/   1.2785554676e-36,  -1.1303931405e-40,   7.2978424008e-46,
		/* 66*/   3.4247246166e-51,  -3.3863757700e-56,

		/* 68*/  -3.5127503061e-41,   6.7692928991e-47,   5.5353232299e-52,
		/* 71*/   4.1057957366e-57,

		/* 72*/   2.0236690107e-47,   2.4864726958e-51,  -1.6699135261e-56,

		/* 75*/   5.9706206647e-52,  -3.8670366463e-57,

		/* 77*/  -1.5348009612e-57,

		/* X0*/   535887.734971
	};

	static double C_jtu[] =
	{
		/*deg*/   11.0,

		/*  0*/   6.2113575431e+06,   9.9946783805e-01,   4.9938687647e-11,
		/*  3*/   3.7990966203e-17,  -1.5339193581e-20,  -7.7323064231e-27,
		/*  6*/   1.5921130660e-30,   9.5529708059e-37,  -7.1611634315e-41,
		/*  9*/  -1.4830976794e-47,   1.1577689086e-51,  -5.7055636656e-58,

		/* 12*/  -1.9969840572e-02,  -7.1805559621e-10,   8.4045330539e-16,
		/* 15*/   1.3682436042e-20,  -1.3631677906e-25,  -1.9747750527e-30,
		/* 18*/   1.8282909188e-35,   1.0360374884e-40,  -1.0151462821e-45,
		/* 21*/  -2.0151906004e-51,   1.9305008524e-56,

		/* 23*/   2.3900420211e-11,  -2.6486221183e-16,  -1.3109796722e-20,
		/* 26*/   8.8930037465e-26,   2.6367452630e-30,  -2.0788069675e-35,
		/* 29*/  -1.7881694137e-40,   1.1903122385e-45,   3.8471591094e-51,
		/* 32*/  -2.2681491134e-56,

		/* 33*/   5.8496451149e-16,   2.4094520047e-20,   1.2069686697e-26,
		/* 36*/  -4.9977313546e-30,  -9.6921660473e-36,   4.2026524388e-40,
		/* 39*/   1.3405876318e-46,  -1.0131754273e-50,   7.2740018900e-57,

		/* 42*/   7.8465984626e-22,   3.8634193994e-26,   1.4338062213e-30,
		/* 45*/   4.3638213090e-37,  -2.2938670833e-40,   1.6535643482e-45,
		/* 48*/   8.0263261110e-51,  -6.7548306357e-56,

		/* 50*/  -2.3686862535e-25,  -5.9285339942e-30,   1.2257380281e-35,
		/* 53*/   2.7868104605e-40,  -1.3509809193e-46,  -1.2352581563e-50,
		/* 56*/   3.3545921272e-56,

		/* 57*/  -5.7946172707e-31,  -2.4002504495e-35,   1.2383768529e-41,
		/* 60*/   1.4988400999e-46,   5.2572256175e-51,  -4.3211999874e-56,

		/* 63*/   2.8395578205e-35,   8.1206547484e-40,  -1.3556738040e-45,
		/* 66*/  -7.1034554654e-51,   3.6760430426e-57,

		/* 68*/   7.6932686862e-41,   3.9826299606e-45,  -5.2280161357e-51,
		/* 71*/  -2.1625606715e-56,

		/* 72*/  -1.1790660973e-45,  -3.9043014229e-50,   2.1421469282e-56,

		/* 75*/  -3.6328809430e-51,  -2.2294273001e-55,

		/* 77*/   6.4954545832e-57,

		/* Y0*/   179608.367287,

		/*  0*/   5.3588935583e+05,  -9.9946722875e-01,   3.9169429886e-10,
		/*  3*/   3.4406219619e-16,  -2.3100209513e-20,  -2.0980875706e-25,
		/*  6*/   5.0916401948e-30,   4.2352645285e-35,  -5.0814423882e-40,
		/*  9*/  -3.7815509102e-45,   1.8578734513e-50,   1.2844016085e-55,

		/* 12*/  -1.9968652797e-02,  -1.0130504008e-11,  -6.6347235578e-16,
		/* 15*/   1.3855144500e-20,   7.2141514059e-27,  -4.0737530727e-30,
		/* 18*/  -5.2561571812e-36,   4.6984096369e-40,   1.6930479011e-45,
		/* 21*/  -2.0002012019e-50,  -1.0245050164e-55,

		/* 23*/  -2.9984932370e-10,  -8.5765805237e-16,  -7.6496969563e-21,
		/* 26*/   2.0909103390e-25,   1.8677723038e-30,  -2.0546587110e-35,
		/* 29*/  -1.3700082509e-40,   6.7985231879e-46,   5.1001963923e-51,
		/* 32*/   2.4562931015e-56,

		/* 33*/   2.6953902564e-16,   1.0335098510e-20,   1.0512237646e-25,
		/* 36*/  -1.4032065963e-30,  -8.8653883615e-36,   2.3077430247e-40,
		/* 39*/   7.5592438487e-46,  -1.1543418844e-50,  -7.1008824555e-56,

		/* 42*/  -8.9014771332e-21,   7.7463136654e-26,   1.0174620943e-30,
		/* 45*/  -1.2942295250e-35,  -1.7285851072e-40,   5.4866318479e-46,
		/* 48*/   5.7374154072e-51,  -3.0826966859e-56,

		/* 50*/  -2.7633717530e-26,  -1.7031103658e-30,  -1.2230749083e-35,
		/* 53*/   6.5347121093e-41,   6.7871460868e-46,  -5.8126135877e-52,
		/* 56*/   1.9440416443e-56,

		/* 57*/   7.5394910385e-31,  -2.8282134462e-36,  -5.6124165669e-41,
		/* 60*/   1.2596878394e-46,   6.0931461255e-51,   4.2123264690e-56,

		/* 63*/   1.2127899226e-36,   1.1389363448e-40,   7.2153811444e-46,
		/* 66*/  -2.8345320964e-51,  -2.7877471524e-56,

		/* 68*/  -3.1312337444e-41,  -2.1103067283e-47,   7.3409941617e-52,
		/* 71*/  -3.6764625883e-57,

		/* 72*/   1.9424498990e-47,  -2.5238035439e-51,  -1.7142319035e-56,

		/* 75*/   5.2147178289e-52,   3.1067417960e-57,

		/* 77*/  -1.4447927077e-57,

		/* X0*/   259884.127100
	};

	static double C_uts[] =
	{
		/*deg*/   11.0,

		/*  0*/   1.0858018640e+05,   9.9979577051e-01,  -1.7628943162e-11,
		/*  3*/   1.0427534895e-15,   1.1752660013e-20,  -4.1725951789e-25,
		/*  6*/  -2.0886013352e-30,   5.0159910521e-35,   8.1544720099e-41,
		/*  9*/  -1.9858454477e-45,   1.0287586664e-51,   1.5240493624e-56,

		/* 12*/  -1.9606882974e-02,  -4.3334445849e-09,  -8.3389760421e-16,
		/* 15*/   1.0973370628e-20,   4.1679714200e-25,  -7.6223106762e-30,
		/* 18*/  -2.6974169389e-35,   1.0559766833e-39,  -7.9105362819e-46,
		/* 21*/  -4.3221579077e-50,   1.7386643471e-55,

		/* 23*/   1.2383447417e-11,   2.4562547942e-15,   6.8925282176e-21,
		/* 26*/  -1.7152848763e-24,  -7.9695044091e-30,   3.3130334355e-34,
		/* 29*/   7.2753870864e-40,  -2.6300617494e-44,   1.8761736758e-50,
		/* 32*/   4.9342284156e-55,

		/* 33*/  -1.1883316360e-15,   3.0432347639e-20,   8.7215487883e-25,
		/* 36*/  -1.2504430260e-29,  -1.2227674272e-34,   2.9081999906e-39,
		/* 39*/  -3.1952240217e-44,  -1.4743224736e-49,   1.2568548821e-54,

		/* 42*/  -2.5071180419e-20,  -5.9524296653e-25,   9.2424060664e-31,
		/* 45*/   4.9573493239e-34,   2.2448369232e-39,  -7.0754967066e-45,
		/* 48*/  -5.6354749924e-49,   2.1781478699e-54,

		/* 50*/   2.2253781457e-26,  -6.2890039241e-30,  -2.0008683312e-34,
		/* 53*/  -1.7020460684e-39,   3.2555843309e-44,   9.8134258366e-49,
		/* 56*/  -2.4483421139e-54,

		/* 57*/   1.8839740115e-29,  -2.3538560402e-34,   2.2376842442e-39,
		/* 60*/  -9.7171211402e-44,  -1.2247888683e-48,   9.6987753510e-54,

		/* 63*/   1.7284820253e-34,  -1.1091432215e-39,   2.7533441703e-44,
		/* 66*/   7.8319181256e-49,  -1.4799366349e-53,

		/* 68*/  -3.0018484236e-39,   6.9348411599e-44,  -4.1616647911e-49,
		/* 71*/   1.3152283302e-53,

		/* 72*/  -3.3804637596e-44,   1.9935807263e-49,  -2.6561161114e-54,

		/* 75*/   1.4397002066e-49,  -4.7171346500e-54,

		/* 77*/   1.7956467135e-54,

		/* Y0*/   6143171.658806,

		/*  0*/   1.1803275921e+05,  -9.9979562993e-01,   2.2096993755e-09,
		/*  3*/  -7.0235014619e-16,  -2.5468665317e-20,   2.3721380190e-25,
		/*  6*/   4.7914394273e-30,  -2.9235335621e-35,  -3.1752558266e-40,
		/*  9*/   1.4296733762e-45,   5.6318539715e-51,  -2.1372653209e-56,

		/* 12*/  -1.9608396525e-02,   2.6930076840e-11,  -1.2459885445e-15,
		/* 15*/  -5.4286069171e-20,   2.9240791919e-26,   3.9538770772e-29,
		/* 18*/   2.7013028627e-34,  -7.5406070323e-39,  -5.9856746590e-44,
		/* 21*/   4.5446492893e-49,   3.4522256300e-54,

		/* 23*/  -2.1613106297e-09,  -1.0284937475e-15,  -4.7524868020e-21,
		/* 26*/   6.3011943756e-25,  -2.1972028767e-29,  -5.0003754225e-34,
		/* 29*/   9.9050910142e-39,   1.3059721524e-43,  -8.7855986019e-49,
		/* 32*/  -9.5972480432e-54,

		/* 33*/   6.5442913745e-16,  -3.5437986694e-21,   9.6702070364e-25,
		/* 36*/   2.6540324328e-29,  -2.7203478976e-34,  -1.3876118299e-38,
		/* 39*/  -6.8405079980e-44,   1.3551063996e-48,   1.2134346241e-53,

		/* 42*/   3.6698571394e-21,   3.5038598575e-25,   2.5366408419e-30,
		/* 45*/   1.7484199561e-34,   6.0455102679e-39,   4.0847580091e-44,
		/* 48*/  -1.1488873067e-48,  -1.1846835071e-53,

		/* 50*/  -2.0809106978e-25,  -1.0226779365e-31,  -2.9096633166e-34,
		/* 53*/  -4.6363312354e-39,   5.9140904027e-44,   1.2923519124e-48,
		/* 56*/   3.8990462602e-54,

		/* 57*/  -1.7976932688e-30,  -3.5615208413e-35,   6.5231103343e-40,
		/* 60*/  -3.1233789979e-44,  -7.9467366298e-49,  -4.5651670959e-54,

		/* 63*/   2.9008640902e-35,   1.1442713527e-40,   2.5264390889e-44,
		/* 66*/   4.3770693863e-49,   2.3499600661e-54,

		/* 68*/   1.3323328179e-40,   1.4929558770e-45,  -1.1292325082e-49,
		/* 71*/  -1.2081269452e-54,

		/* 72*/  -1.5429064621e-45,  -5.2570211474e-51,  -2.0928319154e-55,

		/* 75*/  -3.8450652804e-52,  -1.8046153053e-56,

		/* 77*/   1.3843491805e-56,

		/* X0*/   679082.320128
	};

	static double C_stu[] =
	{
		/*deg*/   11.0,

		/*  0*/   6.1431695373e+06,   9.9981973699e-01,  -1.0964736421e-10,
		/*  3*/  -1.0559048632e-15,  -1.1478094008e-20,   4.2172459636e-25,
		/*  6*/   1.9084615741e-30,  -5.0227991843e-35,  -5.8508147485e-41,
		/*  9*/   1.9497558465e-45,  -1.9030604163e-51,  -1.1674992376e-56,

		/* 12*/  -1.9607346629e-02,  -4.3277818384e-09,  -8.4535742476e-16,
		/* 15*/   1.1669207355e-20,   4.3588334490e-25,  -7.5235775082e-30,
		/* 18*/  -3.2448901159e-35,   1.0341823305e-39,  -1.6467088951e-46,
		/* 21*/  -4.3465306092e-50,   1.5800702291e-55,

		/* 23*/   1.1590764287e-10,  -2.4877495594e-15,  -5.8449369708e-21,
		/* 26*/   1.7495080863e-24,   8.0567279658e-30,  -3.4119954537e-34,
		/* 29*/  -7.0441405933e-40,   2.5040727605e-44,  -1.9753554317e-50,
		/* 32*/  -4.6623953673e-55,

		/* 33*/  -1.1284237816e-15,   3.3726309410e-20,   8.0048550624e-25,
		/* 36*/  -1.3724675347e-29,  -1.3146204233e-34,   2.8769060513e-39,
		/* 39*/  -3.3903070242e-44,  -1.0381481775e-49,   1.1739253553e-54,

		/* 42*/   2.3954304515e-20,   5.6451650666e-25,  -1.3680967238e-30,
		/* 45*/  -5.0629522861e-34,  -2.5787791044e-39,   1.5749534013e-44,
		/* 48*/   6.6588168655e-49,  -2.6117602308e-54,

		/* 50*/   8.2266769560e-27,  -9.2964661316e-30,  -1.2939153428e-34,
		/* 53*/  -1.4844961079e-39,   4.1637777164e-44,   1.0303914205e-48,
		/* 56*/  -3.2921479391e-54,

		/* 57*/  -1.8613629122e-29,   2.7083908133e-34,  -2.0389539621e-39,
		/* 60*/   9.4913410692e-44,   1.2105180969e-48,  -1.1393091754e-53,

		/* 63*/   1.6802827184e-34,  -3.8788506077e-40,   7.4546018646e-45,
		/* 66*/   7.2426610590e-49,  -1.5499544059e-53,

		/* 68*/   3.0151957680e-39,  -7.7126572795e-44,   3.8393508564e-49,
		/* 71*/  -1.1997717651e-53,

		/* 72*/  -3.2368554928e-44,   1.4494519184e-49,  -7.2998087473e-55,

		/* 75*/  -1.4754965320e-49,   5.2320585872e-54,

		/* 77*/   1.6983633886e-54,

		/* Y0*/   108578.008582,

		/*  0*/   6.7908521383e+05,  -9.9981987793e-01,   2.2067947668e-09,
		/*  3*/   7.4080643569e-16,  -2.7024780096e-20,  -2.3860242186e-25,
		/*  6*/   5.9362108595e-30,   2.0903490479e-35,  -5.2324223549e-40,
		/*  9*/   3.2546718002e-46,   1.7246428336e-50,  -7.6058409579e-56,

		/* 12*/  -1.9608860322e-02,   2.2939412486e-10,  -1.1975947428e-15,
		/* 15*/   5.1738651841e-20,   2.1974690460e-26,  -3.7854430635e-29,
		/* 18*/   2.4792584222e-34,   7.0960293800e-39,  -5.3320738562e-44,
		/* 21*/  -4.2095102312e-49,   2.9767318072e-54,

		/* 23*/  -2.1585027913e-09,   9.8525890561e-16,  -1.7197758382e-21,
		/* 26*/  -6.9990147248e-25,  -2.4134130168e-29,   5.4768040973e-34,
		/* 29*/   1.0114168023e-38,  -1.3537852094e-43,  -8.8213877335e-49,
		/* 32*/   9.5271786410e-54,

		/* 33*/   6.9534612921e-16,   2.8580028058e-21,   9.2085175117e-25,
		/* 36*/  -2.8226680106e-29,  -1.9847960021e-34,   1.4579803275e-38,
		/* 39*/  -8.4649708831e-44,  -1.4155222651e-48,   1.3068571653e-53,

		/* 42*/   3.9667018491e-21,  -3.0022877227e-25,   7.6155105970e-31,
		/* 45*/  -1.6251982395e-34,   7.0189181438e-39,  -5.5846585229e-44,
		/* 48*/  -1.2341266183e-48,   1.3669455963e-53,

		/* 50*/  -2.2275960734e-25,   5.4974771911e-31,  -2.9807621033e-34,
		/* 53*/   4.9962627827e-39,   5.0563831711e-44,  -1.3546107308e-48,
		/* 56*/   5.2970036586e-54,

		/* 57*/  -1.8327143317e-30,   2.0490556946e-35,   9.5949163898e-40,
		/* 60*/   3.2682015932e-44,  -8.7328117126e-49,   4.8115902425e-54,

		/* 63*/   3.0563195217e-35,  -1.2820482439e-40,   2.6835215111e-44,
		/* 66*/  -4.8061624868e-49,   2.6458006730e-54,

		/* 68*/   1.3244590931e-40,  -1.7216547600e-46,  -1.3967859793e-49,
		/* 71*/   1.4083931110e-54,

		/* 72*/  -1.5999084278e-45,   1.4643697408e-51,  -1.2856212972e-55,

		/* 75*/  -2.9347838078e-52,   3.9852449357e-57,

		/* 77*/   1.4360336479e-56,

		/* X0*/   118029.907698
	};

	static double C_utb[] =
	{
		/*deg*/  4.0,

		/*  0*/   5.2222355954e+04,   1.0003999918e+00,  -1.9543132669e-10,
		/*  3*/   1.9214004196e-15,  -1.2249813217e-19,

		/*  5*/   1.4741055574e-03,   7.9465429957e-10,  -2.5561175816e-14,
		/*  8*/  -1.5415582961e-20,

		/*  9*/   2.2187819566e-10,  -2.2425885615e-14,   1.8415412000e-18,

		/* 12*/  -1.0926417356e-14,   6.5851285007e-19,

		/* 14*/  -1.2766025333e-18,

		/*tcy*/    6109645.680680,

		/*  0*/   4.7875457674e+04,  -1.0004002847e+00,  -5.5739930409e-10,
		/*  3*/  -3.7954137372e-15,  -8.5294692035e-19,

		/*  5*/   1.4721003307e-03,   3.7033019410e-10,  -4.3773324580e-15,
		/*  8*/  -4.8011997156e-18,

		/*  9*/   5.7044426679e-10,   9.4892208043e-15,   1.1706710507e-18,

		/* 12*/   4.2324194994e-15,   1.6689060255e-18,

		/* 14*/  -1.1260303216e-19,

		/*tcx*/     495134.215516
	};

	static double C_btu[] =
	{
		/*deg*/  4.0,

		/*  0*/   6.1096456608e+06,   9.9959800064e-01,   1.9318586062e-10,
		/*  3*/  -1.8870172378e-15,   1.2245658657e-19,

		/*  5*/   1.4729233533e-03,   7.9546531725e-10,  -2.5580188922e-14,
		/*  8*/  -6.8693684196e-21,

		/*  9*/  -2.1962553713e-10,   2.2369816885e-14,  -1.8424778852e-18,

		/* 12*/  -1.0881273228e-14,   6.3729275085e-19,

		/* 14*/   1.2762267341e-18,

		/*tcy*/   52222.336107,

		/*  0*/   4.9513423016e+05,  -9.9959770795e-01,  -5.5758168530e-10,
		/*  3*/   3.7654916286e-15,  -8.4235346472e-19,

		/*  5*/   1.4709197601e-03,  -3.6540821608e-10,  -4.3805371470e-15,
		/*  8*/   4.8008973854e-18,

		/*  9*/   5.7059554739e-10,  -9.4793524523e-15,   1.1370338222e-18,

		/* 12*/   4.2365300238e-15,  -1.6695314444e-18,

		/* 14*/  -1.0981554453e-19,

		/*tcx*/   47875.442993
	};

  static double      C_utj99 [] = {
    /* tc32_ed50 -> s34j */
    /* my =  1.73 cm    my_loss =    +7  y_enp =  +5.4 */
    /* mx =  1.58 cm    mx_loss =    +8  x_enp =  +4.6 */
    /* m_lim_gen:  0.139  red = 0        OBS =  26062  */

    /*deg*/  13.0,
    /*Poly NORTH :: e-degree =  0  : n-degree = 13 */
    /*  0*/   1.7632529430e+05,   1.0001388938e+00,  -1.1576375523e-10,
    /*  3*/  -1.6692522603e-15,   3.0592371879e-20,   2.8373079065e-25,
    /*  6*/  -4.4459215470e-30,  -2.3093174705e-35,   3.5879082147e-40,
    /*  9*/   7.4051733308e-46,  -1.5150719977e-50,   4.4684301183e-57,
    /* 12*/   2.5887381798e-61,  -5.2116351470e-67,
    /*Poly NORTH :: e-degree =  1  : n-degree = 12 */
    /* 14*/  -1.9979019458e-02,  -6.3625117370e-10,  -1.4014839916e-15,
    /* 17*/  -1.2493103310e-20,   4.0567818085e-25,  -1.0791240765e-31,
    /* 20*/  -3.7519362032e-35,   1.0272538097e-40,   1.0517328860e-45,
    /* 23*/  -6.4177560833e-51,   2.1625973620e-56,   1.2535076281e-61,
    /* 26*/  -1.0734049539e-66,
    /*Poly NORTH :: e-degree =  2  : n-degree = 11 */
    /* 27*/  -3.4533162605e-11,  -1.4140819778e-15,   7.7779650995e-21,
    /* 30*/   6.4174392143e-25,  -9.2008405822e-30,  -8.2628074667e-35,
    /* 33*/   1.4283759362e-39,   4.7322488467e-45,  -8.1265767189e-50,
    /* 36*/  -8.9810935240e-56,   1.6434142276e-60,  -7.7512876501e-67,
    /*Poly NORTH :: e-degree =  3  : n-degree = 10 */
    /* 39*/  -1.4425114447e-15,  -3.4391684250e-20,   7.4699781877e-25,
    /* 42*/   5.8620955020e-30,  -1.1003493870e-34,   2.8180168085e-40,
    /* 45*/   3.0810557733e-45,  -6.3497362070e-50,   2.5688465327e-55,
    /* 48*/   2.2075658407e-60,  -1.1061306192e-65,
    /*Poly NORTH :: e-degree =  4  : n-degree =  9 */
    /* 50*/   2.7957970501e-20,   7.2990995038e-25,   1.3479752303e-29,
    /* 53*/  -2.2102059886e-34,  -6.7732698734e-40,   1.5791546995e-44,
    /* 56*/  -4.1528215073e-50,  -3.2043997924e-55,   1.4174402428e-60,
    /* 59*/  -3.3596270409e-66,
    /*Poly NORTH :: e-degree =  5  : n-degree =  8 */
    /* 60*/   4.1472543131e-25,   9.8092251969e-30,  -1.5176965859e-34,
    /* 63*/  -3.0273348650e-39,   2.2275088132e-44,   1.7593697760e-49,
    /* 66*/  -9.1876452065e-55,  -3.0197579748e-60,   8.7941931044e-66,
    /*Poly NORTH :: e-degree =  6  : n-degree =  7 */
    /* 69*/  -1.5609718128e-29,  -1.7107108223e-34,  -3.7199002510e-39,
    /* 72*/   3.8108750102e-44,   2.8805938991e-49,  -2.2419674462e-54,
    /* 75*/  -9.7066507721e-61,   4.5950302714e-65,
    /*Poly NORTH :: e-degree =  7  : n-degree =  6 */
    /* 77*/  -5.8394454818e-35,  -6.3304805691e-40,   1.9677824522e-44,
    /* 80*/   2.8123695323e-49,  -2.3170561818e-54,  -9.4224432814e-60,
    /* 83*/   3.9320863713e-65,
    /*Poly NORTH :: e-degree =  8  : n-degree =  5 */
    /* 84*/   3.7076110190e-39,   1.8654759364e-44,   3.2570797963e-49,
    /* 87*/  -2.7814436271e-54,  -2.0484037857e-59,   8.2167397823e-65,
    /*Poly NORTH :: e-degree =  9  : n-degree =  4 */
    /* 90*/  -9.0446223926e-46,  -3.7286659566e-50,  -1.6010689067e-54,
    /* 93*/  -7.8301791540e-60,   1.3432883631e-64,
    /*Poly NORTH :: e-degree = 10  : n-degree =  3 */
    /* 95*/  -3.7286100066e-49,  -7.2272660280e-55,  -7.8350464649e-60,
    /* 98*/   7.4323486400e-65,
    /*Poly NORTH :: e-degree = 11  : n-degree =  2 */
    /* 99*/   9.4760189767e-55,   4.0455995368e-60,   4.0167584159e-65,
    /*Poly NORTH :: e-degree = 12  : n-degree =  1 */
    /*102*/   1.3453310976e-59,  -5.1561395100e-66,
    /*Poly NORTH :: e-degree = 13  : n-degree =  0 */
    /*104*/  -5.6336046875e-65,
    /*tcy*/    6208030.167965,

    /*Poly EAST  :: n-degree =  0  : e-degree = 13 */
    /*  0*/   2.6219050871e+05,  -1.0001375777e+00,   2.7781407173e-10,
    /*  3*/   8.3129733948e-16,   4.8889849265e-20,  -4.5522545693e-25,
    /*  6*/  -1.3579592407e-29,   1.2018015768e-34,   1.7108196172e-39,
    /*  9*/  -1.3782560539e-44,  -9.0531951558e-50,   6.7529622527e-55,
    /* 12*/   1.5103762396e-60,  -1.0509031710e-65,
    /*Poly EAST  :: n-degree =  1  : e-degree = 12 */
    /* 14*/  -1.9979871258e-02,   2.0657701921e-11,  -1.1853329189e-15,
    /* 17*/   1.0335055026e-20,   3.3240792566e-25,  -6.2333532713e-30,
    /* 20*/  -6.3703989125e-35,   1.4966750877e-39,   5.0445256244e-45,
    /* 23*/  -1.3923070140e-49,   4.1459059797e-57,   4.5608466513e-60,
    /* 26*/  -1.0898543510e-65,
    /*Poly EAST  :: n-degree =  2  : e-degree = 11 */
    /* 27*/  -3.7866780689e-10,   1.0958485983e-15,   6.2472441670e-20,
    /* 30*/   6.4773216915e-26,  -1.6702283594e-29,   3.8674527268e-35,
    /* 33*/   2.5714828191e-39,  -2.0493658816e-44,  -1.6333632793e-49,
    /* 36*/   1.9246302508e-54,   2.2347476328e-60,  -4.3042442986e-65,
    /*Poly EAST  :: n-degree =  3  : e-degree = 10 */
    /* 39*/  -6.6060603805e-16,  -2.4463660264e-20,   6.5988968807e-25,
    /* 42*/   3.4650490828e-30,  -1.6991901685e-34,   5.9109915302e-40,
    /* 45*/   1.1280861175e-44,  -1.8901126007e-49,   4.7398278599e-55,
    /* 48*/   1.2810750661e-59,  -7.2146495632e-65,
    /*Poly EAST  :: n-degree =  4  : e-degree =  9 */
    /* 50*/   1.4226125927e-20,  -3.8809073080e-25,  -1.5416458638e-29,
    /* 53*/   8.4501860198e-36,   2.1504520781e-39,   3.5054665257e-45,
    /* 56*/  -1.6635278855e-49,   4.9524378341e-55,   3.9714275163e-60,
    /* 59*/  -2.1130761400e-65,
    /*Poly EAST  :: n-degree =  5  : e-degree =  8 */
    /* 60*/   1.9591521417e-25,   5.5546763971e-30,  -1.1227576746e-34,
    /* 63*/  -6.9554502111e-40,   2.0627032981e-44,  -1.5669644568e-50,
    /* 66*/  -7.4240809919e-55,   1.5405688079e-60,   3.5221220444e-66,
    /*Poly EAST  :: n-degree =  6  : e-degree =  7 */
    /* 69*/  -2.2618689501e-30,   7.0670861040e-35,   1.7405475024e-39,
    /* 72*/  -8.5403342362e-45,  -1.4403628733e-49,   7.5330406576e-56,
    /* 75*/   4.6122718305e-60,  -1.8416270301e-65,
    /*Poly EAST  :: n-degree =  7  : e-degree =  6 */
    /* 77*/  -2.2361965907e-35,  -5.3791539152e-40,   8.8754865660e-45,
    /* 80*/   4.2756501241e-50,  -9.7186430645e-55,   1.5458498911e-60,
    /* 83*/   2.9007877778e-66,
    /*Poly EAST  :: n-degree =  8  : e-degree =  5 */
    /* 84*/   1.4952031111e-40,  -5.6728457924e-45,  -8.7956995652e-50,
    /* 87*/   7.6328031332e-55,   3.6021976499e-60,  -8.8798126405e-66,
    /*Poly EAST  :: n-degree =  9  : e-degree =  4 */
    /* 90*/   1.3064151308e-45,   2.5242968975e-50,  -3.5798203819e-55,
    /* 93*/  -1.0413550675e-60,   1.7004472500e-65,
    /*Poly EAST  :: n-degree = 10  : e-degree =  3 */
    /* 95*/  -4.2422565904e-51,   1.9806734435e-55,   1.6295501546e-60,
    /* 98*/  -2.0176214683e-65,
    /*Poly EAST  :: n-degree = 11  : e-degree =  2 */
    /* 99*/  -3.9344956214e-56,  -4.7818605153e-61,   6.2012436462e-66,
    /*Poly EAST  :: n-degree = 12  : e-degree =  1 */
    /*102*/   3.9859247397e-62,  -2.3306828460e-66,
    /*Poly EAST  :: n-degree = 13  : e-degree =  0 */
    /*104*/   5.0049039762e-67,
    /*tcx*/     533649.794619
  };

  static double        C_jtu99 [] = {
    /* s34j -> tc32_ed50                               */
    /* my =  1.73 cm    my_loss =    +7  y_enp =  +5.4 */
    /* mx =  1.58 cm    mx_loss =    +8  x_enp =  +4.8 */
    /* m_lim_gen:  0.139    red = 0      OBS   = 26062 */

    /*deg*/  13.0,
    /*Poly NORTH :: e-degree =  0  : n-degree = 13 */
    /*  0*/   6.2080299895e+06,   9.9946227330e-01,   9.5352430588e-11,
    /*  3*/   1.6244812523e-15,  -3.0474548755e-20,  -2.7093262065e-25,
    /*  6*/   4.3846463292e-30,   2.1805406516e-35,  -3.5250475877e-40,
    /*  9*/  -6.8908775603e-46,   1.4876736847e-50,  -4.8454626314e-57,
    /* 12*/  -2.5433927550e-61,   5.0736238756e-67,
    /*Poly NORTH :: e-degree =  1  : n-degree = 12 */
    /* 14*/  -1.9965529499e-02,  -6.3810588270e-10,  -1.4644626000e-15,
    /* 17*/  -9.8479255895e-21,   4.1512330403e-25,  -3.8156912528e-31,
    /* 20*/  -3.8746633129e-35,   1.1398799817e-40,   1.1048357722e-45,
    /* 23*/  -6.7546295725e-51,   2.2223295599e-56,   1.3324787388e-61,
    /* 26*/  -1.1281153706e-66,
    /*Poly NORTH :: e-degree =  2  : n-degree = 11 */
    /* 27*/   5.2771251612e-11,   1.3584781091e-15,  -8.0001362857e-21,
    /* 30*/  -6.1620154327e-25,   9.1962314257e-30,   7.8483266599e-35,
    /* 33*/  -1.3813051691e-39,  -4.5414553955e-45,   7.6340552455e-50,
    /* 36*/   9.2957156685e-56,  -1.4945754252e-60,   5.1988431064e-67,
    /*Poly NORTH :: e-degree =  3  : n-degree = 10 */
    /* 39*/  -1.4840670910e-15,  -3.6366706653e-20,   7.2413665046e-25,
    /* 42*/   3.9839828940e-30,  -1.0070892317e-34,   5.0535317326e-40,
    /* 45*/   2.7172062154e-45,  -7.2429436930e-50,   2.4408949213e-55,
    /* 48*/   2.3921237175e-60,  -1.0360045324e-65,
    /*Poly NORTH :: e-degree =  4  : n-degree =  9 */
    /* 50*/  -2.6225954658e-20,  -7.0802120737e-25,  -1.2961226101e-29,
    /* 53*/   2.1059201887e-34,   3.9464157892e-40,  -1.3622661242e-44,
    /* 56*/   6.3710463931e-50,   1.8044769625e-55,  -2.0433224594e-60,
    /* 59*/   6.3630603673e-66,
    /*Poly NORTH :: e-degree =  5  : n-degree =  8 */
    /* 60*/   4.3697262319e-25,   1.2266303455e-29,  -1.4477978619e-34,
    /* 63*/  -2.6203950672e-39,   1.9108271742e-44,   1.3591752487e-49,
    /* 66*/  -6.9623761938e-55,  -2.6840990203e-60,   2.7710554607e-66,
    /*Poly NORTH :: e-degree =  6  : n-degree =  7 */
    /* 69*/   1.5078642800e-29,   1.6651508456e-34,   3.7850050991e-39,
    /* 72*/  -3.6650080091e-44,  -2.6822846846e-49,   2.0060252803e-54,
    /* 75*/   3.6073771742e-61,  -4.1485026689e-65,
    /*Poly NORTH :: e-degree =  7  : n-degree =  6 */
    /* 77*/  -6.3918342403e-35,  -1.3964205587e-39,   1.9221636286e-44,
    /* 80*/   2.5253373077e-49,  -2.0931562273e-54,  -6.2693054194e-60,
    /* 83*/   3.4067133444e-65,
    /*Poly NORTH :: e-degree =  8  : n-degree =  5 */
    /* 84*/  -3.6411503633e-39,  -1.9351992641e-44,  -3.4218920772e-49,
    /* 87*/   2.6616960442e-54,   1.9807144520e-59,  -6.2668758749e-65,
    /*Poly NORTH :: e-degree =  9  : n-degree =  4 */
    /* 90*/  -2.5558139795e-46,   5.3029706925e-50,  -1.6253320182e-54,
    /* 93*/  -7.9909397575e-60,   1.2611686461e-64,
    /*Poly NORTH :: e-degree = 10  : n-degree =  3 */
    /* 95*/   3.6942581415e-49,   9.8812894442e-55,   8.8058074311e-60,
    /* 98*/  -7.6373542908e-65,
    /*Poly NORTH :: e-degree = 11  : n-degree =  2 */
    /* 99*/   9.1341610884e-55,   3.8572506252e-61,   4.4638823986e-65,
    /*Poly NORTH :: e-degree = 12  : n-degree =  1 */
    /*102*/  -1.3405129136e-59,  -1.1342912173e-65,
    /*Poly NORTH :: e-degree = 13  : n-degree =  0 */
    /*104*/  -5.5792025473e-65,
    /*tcy*/     176325.080506,

    /*Poly EAST  :: n-degree =  0  : e-degree = 13 */
    /*  0*/   5.3365156389e+05,  -9.9946358837e-01,   2.7668598883e-10,
    /*  3*/  -7.7750840602e-16,   4.9533630434e-20,   4.3863011417e-25,
    /*  6*/  -1.3967017193e-29,  -1.1718841181e-34,   1.8071908189e-39,
    /*  9*/   1.3627729891e-44,  -1.0029876448e-49,  -6.9047545531e-55,
    /* 12*/   1.8617194556e-60,   1.1791611793e-65,
    /*Poly EAST  :: n-degree =  1  : e-degree = 12 */
    /* 14*/  -1.9966380388e-02,   1.8321091899e-11,  -1.2163899389e-15,
    /* 17*/  -8.1327450427e-21,   3.9376965913e-25,   4.9921422931e-30,
    /* 20*/  -8.2017439521e-35,  -1.2880741803e-39,   7.0534179548e-45,
    /* 23*/   1.2551923073e-49,  -8.6370298949e-56,  -4.2563355339e-60,
    /* 26*/  -9.5988559590e-66,
    /*Poly EAST  :: n-degree =  2  : e-degree = 11 */
    /* 27*/  -3.8041731015e-10,  -1.0722517667e-15,   6.0466110374e-20,
    /* 30*/  -8.8961871777e-26,  -1.5624928809e-29,  -3.3977458632e-35,
    /* 33*/   2.3233047083e-39,   2.0209986661e-44,  -1.4302214378e-49,
    /* 36*/  -1.9102244270e-54,   1.8505412263e-60,   4.3582921281e-65,
    /*Poly EAST  :: n-degree =  3  : e-degree = 10 */
    /* 39*/  -7.1446257067e-16,   2.5922771112e-20,   6.3566341838e-25,
    /* 42*/  -3.6232638498e-30,  -1.7667875730e-34,  -4.0597063277e-40,
    /* 45*/   1.5143698350e-44,   1.7061772335e-49,   1.0622151674e-55,
    /* 48*/  -1.2405969368e-59,  -6.1817670757e-65,
    /*Poly EAST  :: n-degree =  4  : e-degree =  9 */
    /* 50*/   1.5315167370e-20,   3.8493668536e-25,  -1.5208617012e-29,
    /* 53*/  -9.3354761182e-36,   2.0172060251e-39,  -4.3180367127e-45,
    /* 56*/  -1.3636756786e-49,  -3.2397640655e-55,   1.4300694698e-60,
    /* 59*/   4.5760709369e-66,
    /*Poly EAST  :: n-degree =  5  : e-degree =  8 */
    /* 60*/   2.0884560098e-25,  -5.8664999159e-30,  -1.0565155141e-34,
    /* 63*/   6.4428847430e-40,   1.9417223374e-44,   1.1182637921e-50,
    /* 66*/  -8.3292182800e-55,  -1.4948870405e-60,   5.0574246039e-66,
    /*Poly EAST  :: n-degree =  6  : e-degree =  7 */
    /* 69*/  -2.4587723402e-30,  -7.0841387022e-35,   1.7257988475e-39,
    /* 72*/   8.8411967236e-45,  -1.3763094789e-49,  -2.6325558095e-56,
    /* 75*/   4.5858833823e-60,   1.7777411246e-65,
    /*Poly EAST  :: n-degree =  7  : e-degree =  6 */
    /* 77*/  -2.4172565368e-35,   5.7819207436e-40,   8.5503013539e-45,
    /* 80*/  -3.8507804174e-50,  -8.5513359826e-55,  -1.4789616768e-60,
    /* 83*/   5.1040658301e-66,
    /*Poly EAST  :: n-degree =  8  : e-degree =  5 */
    /* 84*/   1.6731324189e-40,   5.7358969688e-45,  -8.6906251589e-50,
    /* 87*/  -7.7358499331e-55,   3.2932519740e-60,   6.4698225296e-66,
    /*Poly EAST  :: n-degree =  9  : e-degree =  4 */
    /* 90*/   1.4308264996e-45,  -2.7591381108e-50,  -3.6451820914e-55,
    /* 93*/   9.4268146145e-61,   1.3561630442e-65,
    /*Poly EAST  :: n-degree = 10  : e-degree =  3 */
    /* 95*/  -5.0538407538e-51,  -2.0313311345e-55,   1.6030771885e-60,
    /* 98*/   2.0096329621e-65,
    /*Poly EAST  :: n-degree = 11  : e-degree =  2 */
    /* 99*/  -4.3117359080e-56,   5.2693713182e-61,   6.7948493979e-66,
    /*Poly EAST  :: n-degree = 12  : e-degree =  1 */
    /*102*/   5.4843441899e-62,   2.4673130442e-66,
    /*Poly EAST  :: n-degree = 13  : e-degree =  0 */
    /*104*/   5.3595732646e-67,
    /*tcx*/     262188.742761
  };

  static double     C_uts99 [] = {
    /* tc32_ed50 -> s34s */
    /* my =  1.26 cm    my_loss =    +6  y_enp =  +9.8 */
    /* mx =  1.19 cm    mx_loss =    +5  x_enp = +10.2 */
    /* m_lim_gen:  0.101  red = 0        OBS   =  8106 */

    /*deg*/  9.0,
    /*Poly NORTH :: e-degree =  0  : n-degree =  9 */
    /*  0*/   1.0790733557e+05,   9.9978922407e-01,   3.5199568602e-12,
    /*  3*/   5.1371006741e-17,  -5.2674982432e-21,  -6.8633477057e-26,
    /*  6*/   5.1727956866e-31,   9.2832920893e-36,  -2.2258447927e-41,
    /*  9*/  -2.2144983452e-46,
    /*Poly NORTH :: e-degree =  1  : n-degree =  8 */
    /* 10*/  -1.9602385333e-02,  -4.3675940379e-09,   7.6436547439e-18,
    /* 13*/   1.8802342887e-20,  -2.7487028436e-25,  -7.4776404487e-30,
    /* 16*/   8.0782627715e-35,   6.3325807179e-40,  -4.8834125991e-45,
    /*Poly NORTH :: e-degree =  2  : n-degree =  7 */
    /* 19*/   6.5564651697e-12,  -6.8104889506e-16,   3.7351975921e-20,
    /* 22*/   1.2750282849e-25,  -1.4236072742e-29,   3.4605532471e-35,
    /* 25*/   1.3987424974e-39,  -7.0228278061e-45,
    /*Poly NORTH :: e-degree =  3  : n-degree =  6 */
    /* 27*/  -8.6390226401e-16,  -4.8691448800e-21,   4.6681558601e-25,
    /* 30*/   8.2952775380e-30,   1.3331457339e-36,  -1.4070764915e-39,
    /* 33*/   1.7554514720e-46,
    /*Poly NORTH :: e-degree =  4  : n-degree =  5 */
    /* 34*/   1.1436559200e-20,  -3.0223353286e-25,  -7.1479244842e-30,
    /* 37*/   1.1181122276e-34,   2.2633804858e-39,  -2.0692978938e-44,
    /*Poly NORTH :: e-degree =  5  : n-degree =  4 */
    /* 40*/   3.3080882854e-25,  -1.5748600077e-30,  -1.8859051097e-34,
    /* 43*/  -8.7896010280e-40,   1.7785495142e-44,
    /*Poly NORTH :: e-degree =  6  : n-degree =  3 */
    /* 45*/  -5.9321703176e-31,   7.4259754996e-35,  -2.4544120405e-40,
    /* 48*/  -9.0807428104e-45,
    /*Poly NORTH :: e-degree =  7  : n-degree =  2 */
    /* 49*/  -3.8436267359e-35,   4.9811624316e-40,   9.5752951153e-45,
    /*Poly NORTH :: e-degree =  8  : n-degree =  1 */
    /* 52*/  -3.1746636958e-41,  -3.0596457190e-45,
    /*Poly NORTH :: e-degree =  9  : n-degree =  0 */
    /* 54*/   1.1310675824e-45,
    /*tcy*/    6142519.772410,

    /*Poly EAST  :: n-degree =  0  : e-degree =  9 */
    /*  0*/   1.1696718747e+05,  -9.9978831381e-01,   2.1776749302e-09,
    /*  3*/  -1.2496489584e-15,  -3.3527323606e-21,   3.7270837329e-25,
    /*  6*/   7.3856018504e-32,  -4.8628298904e-35,   3.5992539427e-41,
    /*  9*/   2.3406605032e-45,
    /*Poly EAST  :: n-degree =  1  : e-degree =  8 */
    /* 10*/  -1.9605529419e-02,  -1.8950453044e-12,   9.7761865754e-16,
    /* 13*/   7.1109195187e-21,  -6.8279010167e-25,   6.1201418390e-30,
    /* 16*/   2.0210581504e-34,  -5.9646652818e-40,  -1.7012215804e-44,
    /*Poly EAST  :: n-degree =  2  : e-degree =  7 */
    /* 19*/  -2.1724968176e-09,  -2.2833188475e-15,   1.5804419960e-20,
    /* 22*/   1.0046109955e-24,  -1.0905863818e-29,  -3.3246416930e-34,
    /* 25*/   1.4654115654e-39,   3.4837915567e-44,
    /*Poly EAST  :: n-degree =  3  : e-degree =  6 */
    /* 27*/   1.0061563224e-15,   2.3345263492e-20,  -5.0573180168e-25,
    /* 30*/   2.0779422372e-30,   1.9521533409e-34,  -2.3928335128e-39,
    /* 33*/  -3.4589422763e-44,
    /*Poly EAST  :: n-degree =  4  : e-degree =  5 */
    /* 34*/  -9.4604102082e-23,   7.7644335488e-25,   1.9141704670e-31,
    /* 37*/  -1.3775242735e-34,   2.0978770016e-39,   3.2391064284e-44,
    /*Poly EAST  :: n-degree =  5  : e-degree =  4 */
    /* 40*/  -2.0195860626e-25,  -3.1589746115e-30,   3.0469114609e-35,
    /* 43*/  -3.5974158333e-40,  -1.4395181443e-44,
    /*Poly EAST  :: n-degree =  6  : e-degree =  3 */
    /* 45*/  -6.6939312923e-31,  -8.2640389316e-35,  -3.3634105679e-40,
    /* 48*/   2.7882436780e-45,
    /*Poly EAST  :: n-degree =  7  : e-degree =  2 */
    /* 49*/   1.9839348020e-35,   1.9214332316e-40,   2.7771816013e-45,
    /*Poly EAST  :: n-degree =  8  : e-degree =  1 */
    /* 52*/   6.6045465312e-41,   2.5205909964e-45,
    /*Poly EAST  :: n-degree =  9  : e-degree =  0 */
    /* 54*/  -6.6096428142e-46,
    /*tcx*/     680161.119096
  };

  static double     C_stu99 [] = {
    /* s34s -> tc32_ed50 */
    /* m_lim_gen:  0.101  red = 0       OBS    =  8106 */
    /* my =  1.26 cm    my_loss =    +6  y_enp =  +9.9 */
    /* mx =  1.19 cm    mx_loss =    +5  x_enp = +10.1 */

    /*deg*/  9.0,
    /*Poly NORTH :: e-degree =  0  : n-degree =  9 */
    /*  0*/   6.1425176260e+06,   9.9982642270e-01,  -1.3168917417e-10,
    /*  3*/  -3.9708041280e-17,   5.6146952745e-21,   5.8802311638e-26,
    /*  6*/  -6.7090237676e-31,  -7.2703800574e-36,   3.5399175335e-41,
    /*  9*/   1.1362194189e-46,
    /*Poly NORTH :: e-degree =  1  : n-degree =  8 */
    /* 10*/  -1.9603123674e-02,  -4.3603758981e-09,   8.3991514570e-17,
    /* 13*/   1.6432988768e-20,  -3.0087468049e-25,  -6.7642087335e-30,
    /* 16*/   8.2029047097e-35,   5.6678762622e-40,  -4.6707562910e-45,
    /*Poly NORTH :: e-degree =  2  : n-degree =  7 */
    /* 19*/   1.2169460553e-10,   6.7593802589e-16,  -3.8294951950e-20,
    /* 22*/  -8.7128023349e-26,   1.5384275104e-29,  -4.3441068759e-35,
    /* 25*/  -1.5686253766e-39,   7.8385297914e-45,
    /*Poly NORTH :: e-degree =  3  : n-degree =  6 */
    /* 27*/  -8.5249457247e-16,  -4.4243649688e-21,   4.7595992589e-25,
    /* 30*/   7.6204541165e-30,  -1.2731004573e-36,  -1.3997953545e-39,
    /* 33*/   7.7759642704e-46,
    /*Poly NORTH :: e-degree =  4  : n-degree =  5 */
    /* 34*/  -1.1411170819e-20,   3.0175854442e-25,   6.2771815369e-30,
    /* 37*/  -1.2594682090e-34,  -2.1552562679e-39,   2.2003142841e-44,
    /*Poly NORTH :: e-degree =  5  : n-degree =  4 */
    /* 40*/   3.1748967872e-25,  -1.8957154350e-30,  -1.8300542516e-34,
    /* 43*/  -6.1875394978e-40,   1.6039178559e-44,
    /*Poly NORTH :: e-degree =  6  : n-degree =  3 */
    /* 45*/   6.2809773680e-31,  -6.7941076998e-35,   3.8963958677e-40,
    /* 48*/   8.2691774223e-45,
    /*Poly NORTH :: e-degree =  7  : n-degree =  2 */
    /* 49*/  -3.6073724771e-35,   5.0311388471e-40,   8.7585934010e-45,
    /*Poly NORTH :: e-degree =  8  : n-degree =  1 */
    /* 52*/   2.2831508241e-41,   2.5353252434e-45,
    /*Poly NORTH :: e-degree =  9  : n-degree =  0 */
    /* 54*/   1.0289124711e-45,
    /*tcy*/     107905.132295,

/* tcts_u   ver 1999.01           # page 11   17 Nov 1999 13 25 */


    /*Poly EAST  :: n-degree =  0  : e-degree =  9 */
    /*  0*/   6.8016404556e+05,  -9.9982733281e-01,   2.1740820158e-09,
    /*  3*/   1.2382715255e-15,  -2.9662643366e-21,  -3.6554059502e-25,
    /*  6*/   1.7496545569e-31,   4.5411700623e-35,   2.4479315571e-41,
    /*  9*/  -2.0352589996e-45,
    /*Poly EAST  :: n-degree =  1  : e-degree =  8 */
    /* 10*/  -1.9606267471e-02,   2.5792993170e-10,   9.4490902015e-16,
    /* 13*/  -7.8536713147e-21,  -6.8369046954e-25,  -5.6559633520e-30,
    /* 16*/   1.9646594761e-34,   5.3776287501e-40,  -1.6069390003e-44,
    /*Poly EAST  :: n-degree =  2  : e-degree =  7 */
    /* 19*/  -2.1687704677e-09,   2.2871505147e-15,   1.7552494613e-20,
    /* 22*/  -1.0379793993e-24,  -1.1511364558e-29,   3.4746687004e-34,
    /* 25*/   1.4031897593e-39,  -3.5537902330e-44,
    /*Poly EAST  :: n-degree =  3  : e-degree =  6 */
    /* 27*/   1.0525312560e-15,  -2.2976407795e-20,  -5.0233954159e-25,
    /* 30*/  -3.1489303440e-30,   2.1953774943e-34,   2.4133571832e-39,
    /* 33*/  -3.7003949066e-44,
    /*Poly EAST  :: n-degree =  4  : e-degree =  5 */
    /* 34*/  -6.4478340743e-22,  -7.6951221900e-25,  -6.0207896532e-31,
    /* 37*/   1.5126843484e-34,   2.3400992651e-39,  -3.5469421836e-44,
    /*Poly EAST  :: n-degree =  5  : e-degree =  4 */
    /* 40*/  -2.1846335209e-25,   3.3565726508e-30,   3.0201171366e-35,
    /* 43*/   6.0281731944e-40,  -1.7776719148e-44,
    /*Poly EAST  :: n-degree =  6  : e-degree =  3 */
    /* 45*/  -5.9548204246e-31,   7.9350728807e-35,  -2.4731347203e-40,
    /* 48*/  -4.4774264707e-45,
    /*Poly EAST  :: n-degree =  7  : e-degree =  2 */
    /* 49*/   2.1601953120e-35,  -2.2482835957e-40,   2.7797554420e-45,
    /*Poly EAST  :: n-degree =  8  : e-degree =  1 */
    /* 52*/   6.1447196093e-41,  -2.1967616472e-45,
    /*Poly EAST  :: n-degree =  9  : e-degree =  0 */
    /* 54*/  -7.1115410472e-46,
    /*tcx*/     116964.303712
  };

   static double     C_utb99 [] = {
    /* tc32_ed50 -> s45b */
    /* m_lim_gen:  0.162  red  = 0      OBS   = 932     */
    /* m = 1.438323 cm my_loss =    +3  y_enp = +8.3917 */
    /* m = 1.623518 cm mx_loss =    +4  x_enp = +8.6952 */
    /*deg*/  6.0,
    /*Poly NORTH :: e-degree = 0  : n-degree = 6 */
    /*  0*/   5.1814336221e+04,   9.9508093795e-01,  -4.0028833893e-10,
    /*  3*/   2.7437179258e-14,  -1.1091551172e-18,  -1.5483294018e-22,
    /*  6*/   8.7893008834e-27,

    /*Poly NORTH :: e-degree = 1  : n-degree = 5 */
    /*  7*/  -8.4285625335e-02,  -8.0349009250e-09,  -6.8564866088e-15,
    /* 10*/   6.3547365865e-19,  -2.1881554809e-22,   9.0033138602e-28,

    /*Poly NORTH :: e-degree = 2  : n-degree = 4 */
    /* 13*/   1.0603521925e-09,  -3.4102153151e-15,  -2.1909153453e-18,
    /* 16*/  -9.4074726761e-24,  -5.6264115657e-27,

    /*Poly NORTH :: e-degree = 3  : n-degree = 3 */
    /* 18*/   6.7717129041e-15,  -3.2812909264e-18,   2.0241183707e-22,
    /* 21*/   1.4908171431e-27,

    /*Poly NORTH :: e-degree = 4  : n-degree = 2 */
    /* 22*/  -3.4820626045e-18,  -5.3403400419e-23,   2.3756265004e-26,
    /*Poly NORTH :: e-degree = 5  : n-degree = 1 */
    /* 25*/  -1.3999010396e-22,   6.3364095347e-27,
    /*Poly NORTH :: e-degree = 6  : n-degree = 0 */
    /* 27*/   1.3463074034e-28,

    /*tcy*/    6125355.423385,

    /*Poly  EAST :: n-degree = 0  : e-degree = 6 */
    /*  0*/   4.6845505770e+04,  -9.9508028349e-01,   3.2152098784e-09,
    /*  3*/  -1.2140480167e-14,   7.8931192216e-18,  -3.9883754124e-23,
    /*  6*/  -2.2911874695e-26,

    /*Poly  EAST :: n-degree = 1  : e-degree = 5 */
    /*  7*/  -8.4285033262e-02,   7.2789707305e-10,  -7.6256332825e-14,
    /* 10*/   3.0130777888e-19,   8.0902511156e-23,  -1.0540930690e-27,

    /*Poly  EAST :: n-degree = 2  : e-degree = 4 */
    /* 13*/  -4.4846836993e-09,   5.6915832216e-16,   7.7305102232e-18,
    /* 16*/   4.0761918891e-22,   1.0860519815e-26,

    /*Poly  EAST :: n-degree = 3  : e-degree = 3 */
    /* 18*/  -3.7539014966e-14,   2.7183456572e-18,   5.4037571516e-22,
    /* 21*/  -1.5538984523e-26,

    /*Poly  EAST :: n-degree = 4  : e-degree = 2 */
    /* 22*/   2.0458495698e-18,  -6.6270459317e-23,  -4.6730676243e-26,
    /*Poly  EAST :: n-degree = 5  : e-degree = 1 */
    /* 25*/   1.0543070614e-22,  -2.4550148368e-27,
    /*Poly  EAST :: n-degree = 6  : e-degree = 0 */
    /* 27*/  -6.9007391522e-28,
    /*tcx*/     878528.616306
  };
	
  static double      C_btu99 [] = {
    /* s45b -> tc32_ed50 */
    /* m_lim_gen:  0.162  red  = 0      OBS   = 932     */
    /* m = 1.444596 cm my_loss =    +3  y_enp = +8.6834 */
    /* m = 1.621978 cm mx_loss =    +4  x_enp = +8.5800 */
    /*deg*/  6.0,
    /*Poly NORTH :: e-degree = 0  : n-degree = 6 */
    /*  0*/   6.1253556446e+06,   9.9778483987e-01,  -6.6655132860e-10,
    /*  3*/  -3.0980300846e-14,   1.3201810815e-18,   1.4430105396e-22,
    /*  6*/  -8.6055518012e-27,

    /*Poly NORTH :: e-degree = 1  : n-degree = 5 */
    /*  7*/  -8.4514709677e-02,  -8.1212299568e-09,   6.4821723202e-16,
    /* 10*/   3.7503311229e-19,  -2.6007267526e-22,   5.7646700891e-27,

    /*Poly NORTH :: e-degree = 2  : n-degree = 4 */
    /* 13*/  -1.0136130176e-10,  -4.2436616037e-16,   2.0381421457e-18,
    /* 16*/   1.7746666588e-22,  -7.9774771861e-29,

    /*Poly NORTH :: e-degree = 3  : n-degree = 3 */
    /* 18*/   7.9634190895e-15,  -2.2750555953e-18,   1.4525218271e-22,
    /* 21*/  -4.8029502905e-27,

    /*Poly NORTH :: e-degree = 4  : n-degree = 2 */
    /* 22*/   4.4009753090e-18,  -2.5303631109e-23,  -1.9409262503e-26,
    /*Poly NORTH :: e-degree = 5  : n-degree = 1 */
    /* 25*/  -1.3879421552e-22,   8.8610805100e-27,
    /*Poly NORTH :: e-degree = 6  : n-degree = 0 */
    /* 27*/  -2.7356671238e-27,

    /*tcy*/      51814.563112,

    /*Poly  EAST :: n-degree = 0  : e-degree = 6 */
    /*  0*/   8.7852853633e+05,  -9.9778549498e-01,   3.2548576438e-09,
    /*  3*/   1.7861032032e-14,   7.5717166808e-18,   4.1435647823e-23,
    /*  6*/  -2.2513598654e-26,

    /*Poly  EAST :: n-degree = 1  : e-degree = 5 */
    /*  7*/  -8.4514115824e-02,   1.2699823563e-09,  -7.2621209378e-14,
    /* 10*/   1.2026586680e-18,   1.7617507723e-22,  -1.2634696039e-26,

    /*Poly  EAST :: n-degree = 2  : e-degree = 4 */
    /* 13*/  -4.4690438087e-09,  -3.6083568092e-15,   8.3452616922e-18,
    /* 16*/  -5.0264336315e-22,   3.9585353843e-27,

    /*Poly  EAST :: n-degree = 3  : e-degree = 3 */
    /* 18*/  -3.5430575572e-14,  -2.0643851514e-18,   3.8673547744e-22,
    /* 21*/   3.3743621013e-26,

    /*Poly  EAST :: n-degree = 4  : e-degree = 2 */
    /* 22*/   1.7514612330e-18,   1.2333646726e-22,  -4.0512424856e-26,
    /*Poly  EAST :: n-degree = 5  : e-degree = 1 */
    /* 25*/   1.0171415520e-22,  -5.1795437025e-27,
    /*Poly  EAST :: n-degree = 6  : e-degree = 0 */
    /* 27*/  -6.8148631587e-29,
    /*tcx*/      46845.566703
  };

	/* Until we know different. */
	rtnValue = 0;

	/* The following code selects the proper constants from the above array
	   for the selected operation.  Notice that most of this is actually
	   selecting appropriate min.max contraints for extent testing. */

	/* Pointers to called landsdel */
	switch (landsdel) {

	case 1:  /* jylland */
	case 'j':
		cbu     = (vintage == 1999) ? C_utj99 : C_utj;
		cbs     = (vintage == 1999) ? C_jtu99 : C_jtu;
		utmNmax = U32JNMAX;
		utmNmin = U32JNMIN;
		utmEmax = U32JEMAX;
		utmEmin = U32JEMIN;
		s34ymax = S34JYMAX;
		s34ymin = S34JYMIN;
		s34xmax = S34JXMAX;
		s34xmin = S34JXMIN;
		break;

	case 2:  /* sjælland */
	case 's':
		cbu     = (vintage == 1999) ? C_uts99 : C_uts;
		cbs     = (vintage == 1999) ? C_stu99 : C_stu;
		utmNmax = U32SNMAX;
		utmNmin = U32SNMIN;
		utmEmax = U32SEMAX;
		utmEmin = U32SEMIN;
		s34ymax = S34SYMAX;
		s34ymin = S34SYMIN;
		s34xmax = S34SXMAX;
		s34xmin = S34SXMIN;
		break;

	case 3:  /*bornholm */
	case 'b':
		cbu     = (vintage == 1999) ? C_utb99 : C_utb;
		cbs     = (vintage == 1999) ? C_btu99 : C_btu;
		if (vintage == 1999)
		{
			utmNmax = U32BNMAX;
			utmNmin = U32BNMIN;
			utmEmax = U32BEMAX;
			utmEmin = U32BEMIN;
		}
		else
		{
			utmNmax = U33BNMAX;
			utmNmin = U33BNMIN;
			utmEmax = U33BEMAX;
			utmEmin = U33BEMIN;
		}
		s34ymax = S45BYMAX;
		s34ymin = S45BYMIN;
		s34xmax = S45BXMAX;
		s34xmin = S45BXMIN;
		break;

	default:
		cbu     = NULL;
		cbs     = NULL;
		utmNmax = U32SNMAX;
		utmNmin = U32SNMIN;
		utmEmax = U32SEMAX;
		utmEmin = U32SEMIN;
		s34ymax = S34SYMAX;
		s34ymin = S34SYMIN;
		s34xmax = S34SXMAX;
		s34xmin = S34SXMIN;
		CS_stncp (csErrnam,"CSsys34:1",MAXPATH);
		CS_erpt (cs_ISER);
		rtnValue = -1;
		break;
	} /* end landsdel cases */
	if (rtnValue != 0) return rtnValue;

	/* Sequence of pointers for direct/reverse */
	if (direct > 0)
	{
		/* utm -> s34 */
		cb  = cbu;
		cw  = cbs;
		ins = (utmNmin < Nin && Nin < utmNmax && utmEmin < Ein && Ein < utmEmax);
	}
	else if (direct < 0)
	{
		/* s34 -> utm */
		cb  = cbs;
		cw  = cbu;
		ins = (s34ymin < Nin && Nin < s34ymax && s34xmin < Ein && Ein < s34xmax);
	}
	else
	{
		ins = 0;
		cb = NULL;
		cw = NULL;
		CS_stncp (csErrnam,"CSsys34:2",MAXPATH);
		CS_erpt (cs_ISER);
		rtnValue = -1;
	}
	if (rtnValue != 0) return rtnValue;

/*
	ins tells us if the input cooridnate is within the normal bounds for
	the system being dealt with.  Since the CS-MAP convention is to always
	return a value, even if it is ridiculous, we do not return an error
	status if ins is false (as the original code would do).  Rather, we
	modify the code below to prevent a floating point exception, and
	force the cs_CNVRT_RNG return value as a signal that the results
	are questionable.
	
	loopLimit is used to control the number of iterations of the following
	loop.  In the original code, we looped three times.  OIn the first loop,
	the desired calculation was produced.  On the second iteration, the
	results of the first iteration were returned to the user.  On the
	third iteration, the inverse calculation was made for subsequent
	validation.
	
	We have modified this so that in the case where we know we are outside
	the normal limits, and we know we will be returning a non-normal
	status anyway, we skip the inverse calculation and validation.
	This was done to prevent floating point exceptions, and other
	nasty side affects when bogus numers are passed to these functions.  */
   
	loopLimit = 1;
	if (!ins)
	{
		rtnValue = 1;
		loopLimit = 0;
	}

	/* Preserve input for reverse check */
	N = Nin;
	E = Ein;

	/* Transformation loop */
	for (i = -1; i <= loopLimit; ++i)
	{
		if (i)
		{
			/* Collect constants and addresses */
			g   = (int) *cb;
			sz  = (g + 1)*(g + 2)/2 + 1;
			tcy = cb  + sz;
			tcx = tcy + sz;

			/* Double Horner's scheme */
			/* N = n*Cy*e -> yout, E = e*Cx*n -> xout */
			n   = N - *tcy;
			e   = E - *tcx;
			for (r = g,N = *--tcy,E = *--tcx;r > 0;r--)
			{
				for (c = g, u = *--tcy, v = *--tcx; c >= r; c--)
				{
					u = n*u + *--tcy;
					v = e*v + *--tcx;
				}
				N = e*N + u;
				E = n*E + v;
			}
		}
		else
		{
			/* collect output coord, switch to reverse checking */
			*yout = N;
			*xout = E;
			cb    = cw;
		}
	}

	/* tol-check of results */
	if (ins && fabs (N - Nin) >= tol && fabs (E - Ein) >= tol)
	{
		rtnValue = 1;
	}
	return rtnValue;
}
