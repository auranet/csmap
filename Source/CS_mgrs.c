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

			 File Name: $RCSfile: cs_mgrs.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #2 $
		 Check In Date:	$Date: 2006/11/25 $

		Last Revision:	$Log: cs_mgrs.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:14  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1201  2005/05/25 00:42:20  nto
		Last Revision:	Changes required by Kruger Formulation changes to cs_Trmer_ structure.
		Last Revision:	Revision 11.1200  2005/01/15 18:27:14  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:11  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:19  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:26  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.801  2004/03/25 21:12:05  nto
		Last Revision:	Fixed potential floating point exception during error reporting.
		Last Revision:	Revision 11.800  2004/01/13 23:29:15  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:55  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.601  2003/12/19 01:08:21  nto
		Last Revision:	Added rt_MSDOTNET runtime.
		Last Revision:	Revision 11.600  2003/12/04 02:46:30  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:57  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:23  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:18  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:45  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1502  2002/11/21 21:08:22  nto
		Last Revision:	Lint cleanup.
		Last Revision:	Revision 10.1501  2002/10/13 00:29:28  nto
		Last Revision:	Added some casts to make the Windows CE compiler happy.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:22  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:24  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:19  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:39  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:28  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:12  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:51  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:45  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.501  2000/12/11 05:27:48  nto
		Last Revision:	Disable MGRS if the protection system is active.
		Last Revision:	Revision 10.500  2000/10/27 07:38:23  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.401  2000/10/27 03:57:22  nto
		Last Revision:	Fixed a bug when interpreting MGRS strings where the
		Last Revision:	precision is less than 5.
		Last Revision:	Revision 10.400  2000/09/13 01:16:57  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.301  2000/09/12 20:49:11  nto
		Last Revision:	Fixed a bug where we were using the wrong set of characters for a zone.  Also, added a new error message indicating longitude is not same zones as MGRS string.
		Last Revision:	Revision 10.300  2000/04/04 23:18:28  nto
		Last Revision:	Revision 1.2  2000/04/03 21:41:32  nto
		Last Revision:	Debugged and tested.  Ready for release.
		Last Revision:	Revision 1.1  2000/03/08 23:33:59  nto
		Last Revision:	Initial Revision

		       * * * * R E M A R K S * * * *

	Provides for conversion of Lat/Longs to MGRS designations and
	vice-versa.  You essentially construct an object using one of
	the CSnewMgrs functions, obtaining a pointer to the object.
	You then perform the desired conversions using the pointer.  Note,
	that the ellipsoid is specified as an argument to the constructor.
	Three different constructors are provided, enabling the specification
	of the ellipsoid in any of three different ways.

	This stuff has been tested against the Army TEC GeoTrans program.
	Please note that this program is not very good at computing
	UTM coordinates.  So, a difference of one meter between what this code
	produces and what GeoTrans produces is to be expected.

	These functions expect all alphabetic characters in MGRS strings
	to be upper	case.

			* * * * * * F U N C T I O N S * * * * * *

	Constructors:
		struct cs_Mgrs_ *CSnewMgrs (double e_rad,double e_sq,short bessel);
		struct cs_Mgrs_ *CSnewMgrsE (Const char *ellipsoid,short bessel);
		struct cs_Mgrs_ *CSnewMgrsD (Const char *datum,short bessel);

	Destructor:
		void CSdeleteMgrs (struct cs_Mgrs_ *__This);

	Calculations:
		int CScalcMgrsFromLl (struct cs_Mgrs_ *__This,char *result,int size,double latLng [2],int prec)
		int CScalcLlFromMgrs (struct cs_Mgrs_ *__This,double latLng [2],Const char *mgrsString)


	Internal Support:
		int CScalcUtmUps (struct cs_Mgrs_ *__This,double utmUps [2],double latLng [2]);
		int CScalcLatLng (struct cs_Mgrs_ *__This,double latLng [2],double utmUps [2],int utmZone)
		int CScalcMgrsFromLlUtm (struct cs_Mgrs_ *__This,char *result,int size,double latLng [2],double utmUps [2],int prec)

	Where:
		short bessel;				non-zero indicates use the Bessel character set.
		double e_rad;				radius, in meters, of the ellipsoid to be used.
		double e_sq;				ellipsoid eccenticity squared.
		char *ellipsoid;			key name of ellipsoid to use.
		char *datum;				key name of datum, which references the desired ellipsoid.
		struct cs_Mgrs_ *__This;	pointer to an MGRS object.
		char *result;				calculated MGRS string returned at this location.
		int size;					size, in characters, of the result buffer.
		double latLng [2];			longitude [0] and latitude [1] in degrees.
		char *mgrsString;			MGRS string to be converted.
		double utmUPS [2];			X [0] and Y [1] of either UTM or UPS coordinates.
		int utmZone;				carries UTM zone number: positive for northern hemisphere,
									negative for southern hemisphere, +61 for North UPS, and
									-61 of south UPS.  Zero is an invalid number.
		int prec;					number of digits in each element of MGRS numeric portion,
									0 thru 5.

	Note, CScalcUtmUps returns a utmZone value; zero to indicate an error.  Constructors
	return NULL for an error.  All other functions return zero for OK, -1 for error.

	CScalcLlFromMgrs will return a +1 if the resulting longitude is not in the
	same zone as the string indicates.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_mgrs.c#2 $"};
#endif

#include "cs_map.h"
#include <ctype.h>

#if _RUN_TIME == _rt_MSVC32 || _RUN_TIME == _rt_MSDOTNET
#	pragma warning (disable:4244)
#endif

/* Structure to used to build the following tables. */
struct csMgrsSet_
{
	char easting [9];
	char northing [20];
};

static const struct csMgrsSet_ csMgrsSetsNormal [6] =
{
	{	"ABCDEFGH", "ABCDEFGHJKLMNPQRSTUV" },
	{	"JKLMNPQR", "FGHJKLMNPQRSTUVABCDE" },
	{	"STUVWXYZ", "ABCDEFGHJKLMNPQRSTUV" },
	{	"ABCDEFGH", "FGHJKLMNPQRSTUVABCDE" },
	{	"JKLMNPQR", "ABCDEFGHJKLMNPQRSTUV" },
	{	"STUVWXYZ", "FGHJKLMNPQRSTUVABCDE" }
};

static const struct csMgrsSet_ csMgrsSetsBessel [6] =
{
	{	"ABCDEFGH", "LMNPQRSTUVABCDEFGHJK" },
	{	"JKLMNPQR", "RSTUVABCDEFGHJKLMNPQ" },
	{	"STUVWXYZ", "LMNPQRSTUVABCDEFGHJK" },
	{	"ABCDEFGH", "RSTUVABCDEFGHJKLMNPQ" },
	{	"JKLMNPQR", "LMNPQRSTUVABCDEFGHJK" },
	{	"STUVWXYZ", "RSTUVABCDEFGHJKLMNPQ" }
};
static const char csMgrsPolarSouth [2][24] =
{
	{"JKLPQRSTUXYZABCFGHJKLPQR" },
	{"ABCDEFGHJKLMNPQRSTUVWXYZ" }
};
static const char csMgrsPolarNorth [2][14] =
{
	{"RSTUXYZABCFGHJ" },
	{"ABCDEFGHJKLMNP" }
};
static const char csMgrsBaseLat [20] = "CDEFGHJKLMNPQRSTUVWX";

/* Round off value for the different possible precision values. */
static const double csMgrsRoundOff [6] =
{
	 50000.0,		/* not really used, something to occupy the [0] slot. */
	  5000.0,
	   500.0,
	    50.0,
	     5.0,
	     0.5
};
/*
	Funtions to implement this capability follow.  We mimick
	C++ as we will be porting everythig to C++ soon.

	We construct with the ellipsoid parameters.
*/	
struct cs_Mgrs_ *CSnewMgrs (double e_rad,double e_sq,short bessel)
{
	extern double cs_Zero;					/* 0.0    */
	extern double cs_Half;					/* 0.5    */
	extern double cs_One;                   /* 1.0    */
	extern double cs_Two;					/* 2.0    */
	extern double cs_Degree;				/* 2 * Pi / 180.0 */

	struct cs_Mgrs_ *__This;

	double tmp1, tmp2;

	/* Prepare for some sort of error. */
	__This = NULL;

	/* Allocate the new structure. */
	__This = (struct cs_Mgrs_ *)CS_malc (sizeof (struct cs_Mgrs_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		return NULL;
	}

	/* Initialize it properly. */
	__This->Bessel = bessel;
	__This->E_rad = e_rad;
	__This->E_sq = e_sq;

	/* Transverse Mercator, northern hemisphere. */
	__This->NorthHemi.cent_lng = cs_Zero;			/* This gets manipulated dynamically. */
	__This->NorthHemi.org_lat = cs_Zero;
	__This->NorthHemi.k = 0.9996;
	__This->NorthHemi.k0 = 0.9996;
	__This->NorthHemi.x_off = 500000.0;
	__This->NorthHemi.y_off = 0.0;
	__This->NorthHemi.ecent = sqrt (e_sq);
	__This->NorthHemi.e_sq = e_sq;
	__This->NorthHemi.e_rad = e_rad;
	__This->NorthHemi.Rk = e_rad * __This->NorthHemi.k;
	__This->NorthHemi.Rk_ovr_2 = __This->NorthHemi.Rk * cs_Half;
	__This->NorthHemi.var_K = cs_One;
	__This->NorthHemi.eprim_sq = __This->NorthHemi.e_sq / (cs_One - __This->NorthHemi.e_sq);
	__This->NorthHemi.xx_max = 1500000.0;
	CSmmFsu (&__This->NorthHemi.mmcofF,e_rad,e_sq);
	CSmmIsu (&__This->NorthHemi.mmcofI,e_rad,e_sq);
	__This->NorthHemi.M0 = CSmmFcal (&__This->NorthHemi.mmcofF,cs_Zero,cs_Zero,cs_One);
	__This->NorthHemi.quad = 0;
	__This->NorthHemi.kruger = 0;

	__This->NorthHemi.affineA0 = cs_Zero;
	__This->NorthHemi.affineA1 = cs_Zero;
	__This->NorthHemi.affineA2 = cs_Zero;
	__This->NorthHemi.affineB0 = cs_Zero;
	__This->NorthHemi.affineB1 = cs_Zero;
	__This->NorthHemi.affineB2 = cs_Zero;
	__This->NorthHemi.affineK  = cs_Zero;
	__This->NorthHemi.affineGamma = cs_Zero;
	__This->NorthHemi.affineDenom = cs_One;

	__This->NorthHemi.nTerm = cs_Zero;
	__This->NorthHemi.aHat = cs_Zero;
	__This->NorthHemi.k0aHat = cs_Zero;
	__This->NorthHemi.beta1 = cs_Zero;
	__This->NorthHemi.beta2 = cs_Zero;
	__This->NorthHemi.beta3 = cs_Zero;
	__This->NorthHemi.beta4 = cs_Zero;
	__This->NorthHemi.delta1 = cs_Zero;
	__This->NorthHemi.delta2 = cs_Zero;
	__This->NorthHemi.delta3 = cs_Zero;
	__This->NorthHemi.delta4 = cs_Zero;

	/* Transverse Mercator, southern hemisphere. */
	__This->SouthHemi.cent_lng = cs_Zero;			/* This gets manipulated dynamically. */
	__This->SouthHemi.org_lat = cs_Zero;
	__This->SouthHemi.k = 0.9996;
	__This->SouthHemi.k0 = 0.9996;
	__This->SouthHemi.x_off = 500000.0;
	__This->SouthHemi.y_off = 10000000.0;
	__This->SouthHemi.ecent = sqrt (e_sq);
	__This->SouthHemi.e_sq = e_sq;
	__This->SouthHemi.e_rad = e_rad;
	__This->SouthHemi.Rk = e_rad * __This->SouthHemi.k;
	__This->SouthHemi.Rk_ovr_2 = __This->SouthHemi.Rk * cs_Half;
	__This->SouthHemi.var_K = cs_One;
	__This->SouthHemi.eprim_sq = __This->SouthHemi.e_sq / (cs_One - __This->SouthHemi.e_sq);
	__This->SouthHemi.xx_max = 1500000.0;
	CSmmFsu (&__This->SouthHemi.mmcofF,e_rad,e_sq);
	CSmmIsu (&__This->SouthHemi.mmcofI,e_rad,e_sq);
	__This->SouthHemi.M0 = CSmmFcal (&__This->SouthHemi.mmcofF,cs_Zero,cs_Zero,cs_One);
	__This->SouthHemi.quad = 0;
	__This->SouthHemi.kruger = 0;

	__This->SouthHemi.affineA0 = cs_Zero;
	__This->SouthHemi.affineA1 = cs_Zero;
	__This->SouthHemi.affineA2 = cs_Zero;
	__This->SouthHemi.affineB0 = cs_Zero;
	__This->SouthHemi.affineB1 = cs_Zero;
	__This->SouthHemi.affineB2 = cs_Zero;
	__This->SouthHemi.affineK  = cs_Zero;
	__This->SouthHemi.affineGamma = cs_Zero;
	__This->SouthHemi.affineDenom = cs_One;

	__This->SouthHemi.nTerm = cs_Zero;
	__This->SouthHemi.aHat = cs_Zero;
	__This->SouthHemi.k0aHat = cs_Zero;
	__This->SouthHemi.beta1 = cs_Zero;
	__This->SouthHemi.beta2 = cs_Zero;
	__This->SouthHemi.beta3 = cs_Zero;
	__This->SouthHemi.beta4 = cs_Zero;
	__This->SouthHemi.delta1 = cs_Zero;
	__This->SouthHemi.delta2 = cs_Zero;
	__This->SouthHemi.delta3 = cs_Zero;
	__This->SouthHemi.delta4 = cs_Zero;

	/* North polar UPS */
	__This->NorthPole.org_lng =  0.0 * cs_Degree;
	__This->NorthPole.org_lat = 90.0 * cs_Degree;
	__This->NorthPole.k = 0.994;
	__This->NorthPole.x_off = 2000000.0;
	__This->NorthPole.y_off = 2000000.0;
	__This->NorthPole.ka = e_rad * __This->NorthPole.k;
	__This->NorthPole.one_mm = 0.001;
	__This->NorthPole.ecent = sqrt (e_sq);
	__This->NorthPole.e_sq = e_sq;
	__This->NorthPole.e_o_2 = __This->NorthPole.ecent * cs_Half;
	tmp1 = cs_One + __This->NorthPole.ecent;
	tmp1 = pow (tmp1,tmp1);
	tmp2 = cs_One - __This->NorthPole.ecent;
	tmp2 = pow (tmp2,tmp2);
	__This->NorthPole.e_term = sqrt (tmp1 * tmp2);
	CSchiIsu (&__This->NorthPole.chicofI,e_sq);
	__This->NorthPole.two_k0 = cs_Two * 0.994;
	__This->NorthPole.two_ka = cs_Two * __This->NorthPole.ka;
	__This->NorthPole.cos_org_lat = cs_Zero;
	__This->NorthPole.sin_org_lat = cs_One;
	__This->NorthPole.aspect = cs_STERO_NORTH;
	__This->NorthPole.quad = 0;

	/* South polar UPS */
	__This->SouthPole.org_lng =  0.0 * cs_Degree;
	__This->SouthPole.org_lat = -90.0 * cs_Degree;
	__This->SouthPole.k = 0.994;
	__This->SouthPole.x_off = 2000000.0;
	__This->SouthPole.y_off = 2000000.0;
	__This->SouthPole.ka = e_rad * __This->SouthPole.k;
	__This->SouthPole.one_mm = 0.001;
	__This->SouthPole.ecent = sqrt (e_sq);
	__This->SouthPole.e_sq = e_sq;
	__This->SouthPole.e_o_2 = __This->SouthPole.ecent * cs_Half;
	tmp1 = cs_One + __This->SouthPole.ecent;
	tmp1 = pow (tmp1,tmp1);
	tmp2 = cs_One - __This->SouthPole.ecent;
	tmp2 = pow (tmp2,tmp2);
	__This->SouthPole.e_term = sqrt (tmp1 * tmp2);
	CSchiIsu (&__This->SouthPole.chicofI,e_sq);
	__This->SouthPole.two_k0 = cs_Two * 0.994;
	__This->SouthPole.two_ka = cs_Two * __This->SouthPole.ka;
	__This->SouthPole.cos_org_lat = cs_Zero;
	__This->SouthPole.sin_org_lat = cs_One;
	__This->SouthPole.aspect = cs_STERO_SOUTH;
	__This->SouthPole.quad = 0;

	return __This;
}

struct cs_Mgrs_ *CSnewMgrsE (Const char *ellipsoid,short bessel)
{
	struct cs_Mgrs_ *__This;
	struct cs_Eldef_ *elDef;
	double e_sq;

	__This = NULL;
	elDef = CS_eldef (ellipsoid);
	if (elDef != NULL)
	{
		e_sq = elDef->ecent * elDef->ecent;
		__This = CSnewMgrs (elDef->e_rad,e_sq,bessel);
		CS_free (elDef);
	}
	return __This;
}

struct cs_Mgrs_ *CSnewMgrsD (Const char *datum,short bessel)
{
	struct cs_Mgrs_ *__This;
	struct cs_Datum_ *dtDef;
	double e_sq;

	__This = NULL;
	dtDef = CS_dtloc (datum);
	if (dtDef != NULL)
	{
		e_sq = dtDef->ecent * dtDef->ecent;
		__This = CSnewMgrs (dtDef->e_rad,e_sq,bessel);
		CS_free (dtDef);
	}
	return __This;
}

void CSdeleteMgrs (struct cs_Mgrs_ *__This)
{
	if (__This != NULL)
	{
		CS_free (__This);
	}
}

int CScalcUtmUps (struct cs_Mgrs_ *__This,double utmUps [2],double latLng [2])
{
	extern int csErrlng;
	extern int csErrlat;
	extern double cs_Degree;				/* converts degrees to radians by
											   multiplication */
	int status;
	int utmZone;

	/* Check the input arguments. */
	if (latLng [LAT] <  -90.0 || latLng [LAT] >  90.0 ||
		latLng [LNG] < -180.0 || latLng [LNG] > 180.0)
	{
		csErrlng = (int)((fabs (latLng [LNG]) >= 10000.0) ? 9999.99 : latLng [LNG]);
		if (latLng [LNG] < 0.0) csErrlng = -csErrlng;
		csErrlat = (int)((fabs (latLng [LAT]) >= 10000.0) ? 9999.99 : latLng [LAT]);
		if (latLng [LAT] < 0.0) csErrlat = -csErrlat;
		CS_erpt (cs_MGRS_LL);
		return 0;
	}

	/* Four different cases, depends upon the latitude of the point to
	   be converted. */
	if (latLng [LAT] < -80.0)
	{
		/* South polar UPS */
		status = CSpstroF (&__This->SouthPole,utmUps,latLng);
		utmZone = -61;
	}
	else if (latLng [LAT] > 84.0)
	{
		/* North polar UPS */
		status = CSpstroF (&__This->NorthPole,utmUps,latLng);
		utmZone = 61;
	}
	else
	{
		/* Transverse Mercator.  This one is a little harder.
		   Figure out the appropriate central meridian. */
		utmZone = CS_utmzon (latLng [LNG]);

		/* Apply the Norway/Svaldberg kludge. */
		if (latLng [LAT] >= 56.0 && latLng [LAT] < 64.0 &&
		    latLng [LNG] >=  3.0 && latLng [LNG] < 12.0)
		{
			utmZone = 32;
		}
		if (latLng [LAT] >= 72.0 && latLng [LNG] >= 0.0 && latLng [LNG] < 42.0)
		{
			if      (latLng [LNG] <  9.0) utmZone = 31;
			else if (latLng [LNG] < 21.0) utmZone = 33;
			else if (latLng [LNG] < 33.0) utmZone = 35;
			else						  utmZone = 37;
		}   

		/* Do the calculation. */
		if (latLng [LAT] >= 0.0)
		{
			__This->NorthHemi.cent_lng = (double)(-183 + (6 * utmZone)) * cs_Degree;
			status = CStrmerF (&__This->NorthHemi,utmUps,latLng);
		}
		else
		{
			__This->SouthHemi.cent_lng = (double)(-183 + (6 * utmZone)) * cs_Degree;
			status = CStrmerF (&__This->SouthHemi,utmUps,latLng);
			utmZone = -utmZone;
		}
	}
	if (status != 0)
	{
		csErrlng = (int)((fabs (latLng [LNG]) >= 10000.0) ? 9999.99 : latLng [LNG]);
		if (latLng [LNG] < 0.0) csErrlng = -csErrlng;
		csErrlat = (int)((fabs (latLng [LAT]) >= 10000.0) ? 9999.99 : latLng [LAT]);
		if (latLng [LAT] < 0.0) csErrlat = -csErrlat;
		CS_erpt (cs_MGRS_LL);
		utmZone = 0;
	}
	return utmZone;
}

int CScalcLatLng (struct cs_Mgrs_ *__This,double latLng [2],double utmUps [2],int utmZone)
{
	extern double cs_Degree;				/* converts degrees to radians by
											   multiplication */
	int status;

	/* Check the input arguments. */
	if (utmZone == 0 || utmZone < -61 || utmZone > 61)
	{
		CS_erpt (cs_MGRS_ZONE);
		return -1;
	}

	/* Four different cases, depends upon the zone. */
	if (utmZone == -61)
	{
		/* South polar UPS */
		status = CSpstroI (&__This->SouthPole,latLng,utmUps);
	}
	else if (utmZone == 61)
	{
		/* North polar UPS */
		status = CSpstroI (&__This->NorthPole,latLng,utmUps);
	}
	else
	{
		/* Transverse Mercator. */
		if (utmZone > 0)
	
		{
			__This->NorthHemi.cent_lng = (double)(-183 + (6 * utmZone)) * cs_Degree;
			status = CStrmerI (&__This->NorthHemi,latLng,utmUps);
		}
		else
		{
			utmZone = -utmZone;
			__This->SouthHemi.cent_lng = (double)(-183 + (6 * utmZone)) * cs_Degree;
			status = CStrmerI (&__This->SouthHemi,latLng,utmUps);
		}
	}
	if (status != 0)
	{
		CS_erpt (cs_MGRS_UTM);
	}
	return status == 0 ? 0 : -1;
}

int CScalcMgrsFromLl (struct cs_Mgrs_ *__This,char *result,int size,double latLng [2],int prec)
{
	int utmZone;
	double utmUps [2];

	/* First we calculate the utmUps coordinates.  Then we call the
	   CScalcMgrsFromLlUtm function. */
 
	utmZone = CScalcUtmUps (__This,utmUps,latLng);
	if (utmZone == 0)
	{
		return -1;
	}
	return CScalcMgrsFromLlUtm (__This,result,size,latLng,utmUps,prec);
}

int CScalcMgrsFromLlUtm (struct cs_Mgrs_ *__This,char *result,int size,double latLng [2],double utmUps [2],int prec)
{
	extern int csErrlng;
	extern int csErrlat;

	int ii;
	int idx;
	int idxX, idxY;
	int setIdx;
	int utmZone;

	long intUtmX;
	long intUtmY;
	char *rsltPtr;
	char lclResult [64];
	const struct csMgrsSet_ *setPtr;

	char utmXascii [16];
	char utmYascii [16];

	/* Prepare for an error. */
	if (size <= 0) return -1;
	*result = '\0';

	/* Check the input arguments. */
	if (latLng [LAT] <  -90.0 || latLng [LAT] >  90.0 ||
		latLng [LNG] < -180.0 || latLng [LNG] > 180.0)
	{
		csErrlng = (int)((fabs (latLng [LNG]) >= 10000.0) ? 9999.99 : latLng [LNG]);
		if (latLng [LNG] < 0.0) csErrlng = -csErrlng;
		csErrlat = (int)((fabs (latLng [LAT]) >= 10000.0) ? 9999.99 : latLng [LAT]);
		if (latLng [LAT] < 0.0) csErrlat = -csErrlat;
		CS_erpt (cs_MGRS_LL);
		return -1;
	}
	if (prec < 0) prec = 0;
	if (prec > 5) prec = 5;

	/* Select the alpha code set. */
	setPtr = (__This->Bessel) ? csMgrsSetsBessel : csMgrsSetsNormal;

	/* Now we're ready to go. */
	rsltPtr = lclResult;

	/* It is not clear exactly what the MGRS for a precise UTM coordinate
	   is.  The following commented out code rounds the utm coordinate so
	   as to produce the MGRS designation of the closest grid cell.  The
	   code which follows simply truncates, providing the MGRS designation
	   of the cell (assuming a cell's designation is that of the southwest
	   corner) which contains the UTM point. */
/*	intUtmX = (long)(utmUps [XX] + csMgrsRoundOff [prec]); */
/*	intUtmY = (long)(utmUps [YY] + csMgrsRoundOff [prec]); */
	intUtmX = (long)(utmUps [XX]);
	intUtmY = (long)(utmUps [YY]);

	/* Select which of the three algorithms is to be used. */
	if (latLng [LAT] < -80.0)
	{
		/* South Pole UPS */
		idxX = (intUtmX / 100000) - 8;
		idxY = (intUtmY / 100000) - 8;
		if (idxX < 0 || idxX > 19 || idxY < 0 || idxY > 19)
		{
			CS_erpt (cs_MGRS_XY);
			return -1;
		} 
		*rsltPtr++ = (latLng [LNG] < 0.0) ? 'A' : 'B';
		*rsltPtr++ = csMgrsPolarSouth [0][idxX];
		*rsltPtr++ = csMgrsPolarSouth [1][idxY];
	}
	else if (latLng [LAT] > 84.0)
	{
		/* North Pole UPS */
		idxX = (intUtmX / 100000) - 13;
		idxY = (intUtmY / 100000) - 13;
		if (idxX < 0 || idxX > 13 || idxY < 0 || idxY > 13)
		{
			CS_erpt (cs_MGRS_XY);
			return -1;
		} 
		*rsltPtr++ = (latLng [LNG] < 0.0) ? 'Y' : 'Z';
		*rsltPtr++ = csMgrsPolarNorth [0][idxX];
		*rsltPtr++ = csMgrsPolarNorth [1][idxY];
	}
	else
	{
		/* Compute the zone number. */
		utmZone = CS_utmzon (latLng [LNG]);

		/* Apply the Norway/Svaldberg kludge. */
		if (latLng [LAT] >= 56.0 && latLng [LAT] < 64.0 &&
			latLng [LNG] > 3.0 && latLng [LNG] < 6.0)
		{
			utmZone = 32;
		}
		if (latLng [LAT] >= 72.0 && latLng [LNG] > 0.0 && latLng [LNG] < 42.0)
		{
			if      (latLng [LNG] <  9.0) utmZone = 31;
			else if (latLng [LNG] < 21.0) utmZone = 33;
			else if (latLng [LNG] < 33.0) utmZone = 35;
			else                      utmZone = 37;
		}

		/* Back to sanity. */
		*rsltPtr++ = '0' + (utmZone / 10);
		*rsltPtr++ = '0' + (utmZone % 10);
		if (latLng [LAT] >= 72.0)
		{
			*rsltPtr++ = 'X';
		}
		else
		{
			idx = (int)(latLng [LAT] + 80.0) / 8;
			*rsltPtr++ = csMgrsBaseLat [idx];
		}
		setIdx = (utmZone - 1) % 6;
		intUtmX %= 2000000;
		intUtmY %= 2000000;
		idxX = (intUtmX / 100000) - 1;
		idxY = intUtmY / 100000;
		if (idxX < 0 || idxX > 7 || idxY < 0 || idxY > 19)
		{
			CS_erpt (cs_MGRS_XY);
			return -1;
		}
		*rsltPtr++ = setPtr [setIdx].easting [idxX];
		*rsltPtr++ = setPtr [setIdx].northing [idxY];
	}
	sprintf (utmXascii,"%05ld",(intUtmX % 100000));
	sprintf (utmYascii,"%05ld",(intUtmY % 100000));
	for (ii = 0;ii < prec;ii += 1)
	{
		*rsltPtr++ = utmXascii [ii];
	}
	for (ii = 0;ii < prec;ii += 1)
	{
		*rsltPtr++ = utmYascii [ii];
	}
	*rsltPtr = '\0';
	if (size > 0) CS_stncp (result,lclResult,size);
	return 0;
}

/* Converts an Mgrs string to latitude and longitude. */
int CScalcLlFromMgrs (struct cs_Mgrs_ *__This,double latLng [2],Const char *mgrsString)
{
	extern char csErrnam [MAXPATH];

	char cc;
	int count;
	int status;
	int setIdx;
	int rtnValue;
	int utmZone, utmZone1;
	int idx, idxX, idxY;
	int baseLat, maximumLat;
	long multiplier;
	long xBase, yBase;
	char *mgrsPtr;
	const char *chrPtr;
	const struct csMgrsSet_ *setPtr;
	double utmUps [2];
	char mgrs [64];

	rtnValue = 0;

	/* Copy the MGRS string to a local array which can be modified.  In
	   so doing, we strip all white space. */
	count = sizeof (mgrs) - 1;
	chrPtr = mgrsString;
	mgrsPtr = mgrs;
	while (count > 0 && ((cc = *chrPtr++) != '\0'))
	{
		if (cc == ' ' || cc == '\t') continue;
		*mgrsPtr++ = cc;
		count -= 1;
	}
	*mgrsPtr = '\0';

	/* Extract the zone number and the utm coordinate, this is the easy part. */
	cc = mgrs [0];
	if (cc == 'A' || cc == 'B')
	{
		/* South polar coordinate.  Convert the second and third
		   letters to index values.  Note how need to use the first
		   letter to determine where we start our search in the array. */
		if (cc == 'A')
		{
			for (idxX = 0;idxX < 12;idxX += 1)
			{
				if (csMgrsPolarSouth [0][idxX] == mgrs [1]) break;
			}
			if (idxX >= 12)
			{
				CS_stncp (csErrnam,mgrs,sizeof (mgrs));
				CS_erpt (cs_MGRS_STR1);
				goto error;
			}
		}
		else
		{
			for (idxX = 12;idxX < 24;idxX += 1)
			{
				if (csMgrsPolarSouth [0][idxX] == mgrs [1]) break;
			}
			if (idxX >= 24)
			{
				CS_stncp (csErrnam,mgrs,sizeof (mgrs));
				CS_erpt (cs_MGRS_STR1);
				goto error;
			}
		}
		idxX -= 12;

		/* The Y cooordinate is the same regardless of the first letter. */
		for (idxY = 0;idxY < 24;idxY += 1)
		{
			if (csMgrsPolarSouth [1][idxY] == mgrs [2]) break;
		}
		if (idxY >= 24)
		{
			CS_stncp (csErrnam,mgrs,sizeof (mgrs));
			CS_erpt (cs_MGRS_STR1);
			goto error;
		}
		idxY -= 12;					/* accounts for +/- */
	
		/* Extract the offset into the block from the MGRS string.  This
		   relies on the fact that there must always be an even numebr of
		   digits in the MGRS string.  If not, we throw an error.  Note,
		   we are only dealing with south pole stuff here, so there is no
		   zone number to contend with. */
		count = (int)(strlen (mgrs) - 3);
		if ((count & 1) != 0)
		{
			CS_stncp (csErrnam,mgrs,sizeof (mgrs));
			CS_erpt (cs_MGRS_STR2);
			goto error;
		}
		count /= 2;
		if (count > 5)
		{
			CS_stncp (csErrnam,mgrs,sizeof (mgrs));
			CS_erpt (cs_MGRS_STR3);
			goto error;
		}

		/* Capture the X offset. */
		xBase = 0;
		multiplier = 100000L;
		for (idx = 3;idx < (3 + count);idx += 1)
		{
			if (!isdigit (mgrs [idx]))
			{
				CS_stncp (csErrnam,mgrs,sizeof (mgrs));
				CS_erpt (cs_MGRS_STR4);
				goto error;
			}
			xBase = xBase * 10 + (mgrs [idx] - '0');
			multiplier /= 10L;
		}
		xBase = (long)((double)xBase * (double)multiplier);

		/* The Y offset */
		yBase = 0;
		multiplier = 100000L;
		for (idx = 3 + count;idx < (3 + count + count);idx += 1)
		{
			if (!isdigit (mgrs [idx]))
			{
				CS_stncp (csErrnam,mgrs,sizeof (mgrs));
				CS_erpt (cs_MGRS_STR4);
				return -1;
			}
			yBase = yBase * 10 + (mgrs [idx] - '0');
			multiplier /= 10L;
		}
		yBase = (long)((double)yBase * (double)multiplier);

		/* Compute the Ups value for X and Y. */
		utmUps [XX] = 2000000.0 + (idxX * 100000) + xBase;
		utmUps [YY] = 2000000.0 + (idxY * 100000) + yBase;

		/* The above will give us the lat long of the lower left (often, but
		   not always the southwest) corner of the particular cell described
		   by the MGRS string.  The following should move us to the center
		   of the cell.  In this case, count is the precision of the
		   MGRS string. */
		utmUps [XX] += csMgrsRoundOff [count];
		utmUps [YY] += csMgrsRoundOff [count];

		/* Convert back to lat/longs. */
		CSpstroI (&__This->SouthPole,latLng,utmUps);							/*lint !e534 */
	}
	else if (cc == 'Y' || cc == 'Z')
	{
		/* North polar coordinate.  Similar to the above, but the north
		   polar zone only covers 6 degrees of latitude, rather than the
		   10 degrees of the southern zone.  Because of this, there is no
		   duplication of the letter codes, and the logic is a bit
		   simplar. */
		for (idxX = 0;idxX < 14;idxX += 1)
		{
			if (csMgrsPolarNorth [0][idxX] == mgrs [1]) break;
		}
		if (idxX >= 14)
		{
			CS_stncp (csErrnam,mgrs,sizeof (mgrs));
			CS_erpt (cs_MGRS_STR1);
			goto error;
		}
		idxX -= 7;

		for (idxY = 0;idxY < 14;idxY += 1)
		{
			if (csMgrsPolarNorth [1][idxY] == mgrs [2]) break;
		}
		if (idxY >= 14)
		{
			CS_stncp (csErrnam,mgrs,sizeof (mgrs));
			CS_erpt (cs_MGRS_STR1);
			return -1;
		}
		idxY -= 7;

		count = (int)(strlen (mgrs) - 3);
		if ((count & 1) != 0)
		{
			CS_stncp (csErrnam,mgrs,sizeof (mgrs));
			CS_erpt (cs_MGRS_STR2);
			goto error;
		}
		count /= 2;
		if (count > 5)
		{
			CS_stncp (csErrnam,mgrs,sizeof (mgrs));
			CS_erpt (cs_MGRS_STR3);
			goto error;
		}

		xBase = 0;
		multiplier = 100000L;
		for (idx = 3;idx < (3 + count);idx += 1)
		{
			if (!isdigit (mgrs [idx]))
			{
				CS_stncp (csErrnam,mgrs,sizeof (mgrs));
				CS_erpt (cs_MGRS_STR4);
				goto error;
			}
			xBase = xBase * 10 + (mgrs [idx] - '0');
			multiplier /= 10L;
		}
		xBase = (long)((double)xBase * (double)multiplier);

		yBase = 0;
		multiplier = 100000L;
		for (idx = 3 + count;idx < (3 + count + count);idx += 1)
		{
			if (!isdigit (mgrs [idx]))
			{
				CS_stncp (csErrnam,mgrs,sizeof (mgrs));
				CS_erpt (cs_MGRS_STR4);
				goto error;
			}
			yBase = yBase * 10 + (mgrs [idx] - '0');
			multiplier /= 10L;
		}
		yBase = (long)((double)yBase * (double)multiplier);

		utmUps [XX] = 2000000.0 + (idxX * 100000) + xBase;
		utmUps [YY] = 2000000.0 + (idxY * 100000) + yBase;

		utmUps [XX] += csMgrsRoundOff [count];
		utmUps [YY] += csMgrsRoundOff [count];

		CSpstroI (&__This->NorthPole,latLng,utmUps);			/*lint !e534 */
	} 
	else if (cc >= '0' && cc <= '9')
	{
		/* This is where the real fun begins.  Select the character set to use. */
		setPtr = (__This->Bessel) ? csMgrsSetsBessel : csMgrsSetsNormal;

		/* Extract the zone number. Can be one or two digits, possible
		   zero fill.  Note, that it is expected that the zone number
		   accounts for the strange stuff that happens in and around
		   Norway and the Svaldberg Islands. Thus, if the major latitude
		   zone is 'X', zones 32, 33, 34, and 36 do not exist!!! 
		   Similarly, in the 'V' band, zone 32 is 9 degrees wide,
		   and zone 31 is only 3 degrees wide.  One assumes that the
		   central meridians of these strange zones comply with the
		   standard convention. */
		mgrsPtr = mgrs;
		if (isdigit (mgrs [1]))
		{
			/* Second char is a digit, so we assume two zone digits. */
			utmZone = (mgrs [0] - '0') * 10 + (mgrs [1] - '0');
			mgrsPtr = &mgrs [2];
		}
		else
		{
			/* Second char is not a digit, so we assume one zone digit. */
			utmZone = mgrs [0] - '0';
			mgrsPtr = &mgrs [1];
		}

		/* We check for the strange stuff.  */
		if (*mgrsPtr == 'X' &&
		    (utmZone == 32 || utmZone == 34 || utmZone == 36)
		   )
		{
			CS_stncp (csErrnam,mgrs,sizeof (mgrs));
			CS_erpt (cs_MGRS_STR5);
			goto error;
		}

		/* Resolve the 8 degree latitude block designation.  That is, the
		   base latitude for the specific cell. */
		for (idx = 0;idx < 20;idx += 1)
		{
			if (csMgrsBaseLat [idx] == *mgrsPtr) break;
		}

		/* Throw an error if the first non-zone char is not legit. */
		if (idx >= 20)
		{
			CS_stncp (csErrnam,mgrs,sizeof (mgrs));
			CS_erpt (cs_MGRS_STR6);
			goto error;
		}

		/* BaseLat to the southern edge of the 8 degree band.  Note, will be
		   negative for southern hemisphere.  If this is less than -80, or
		   greater than 72, our algorithm is screwed up.  maximumLat is used
		   to verify the result given below. */
		baseLat = (idx * 8) - 80;
		if (baseLat < -80 || baseLat > 72)
		{
			CS_stncp (csErrnam,"CS_mgrs:1",MAXPATH);
			CS_erpt (cs_ISER);
			goto error;
		}
		maximumLat = (baseLat == 72) ? baseLat + 12 : baseLat + 8;
		mgrsPtr += 1;

		/* Locate the zone codes and adjust xBase and yBase appropriately.
		   Note, xBase and yBase are eventually multipled by 100,000 to
		   form the base for the UTM coordinate. */
		setIdx = (utmZone - 1) % 6;
		for (idxX = 0;idxX < 8;idxX += 1)
		{
			if (setPtr [setIdx].easting [idxX] == *mgrsPtr) break;
		}
		if (idxX >= 8)
		{
			/* Oops!!! Invalid letter.  Could be a zone screw up,
			   Perhaps we're using the wrong character set. */
			CS_stncp (csErrnam,mgrs,sizeof (mgrs));
			CS_erpt (cs_MGRS_STR7);
			goto error;
		}
		mgrsPtr += 1;
		idxX += 1;					/* A/F == 100,000.00 */

		/* Now for idxY. */
		for (idxY = 0;idxY < 20;idxY += 1)
		{
			if (setPtr [setIdx].northing [idxY] == *mgrsPtr) break;
		}
		if (idxY >= 20)
		{
			/* Again, could be a zone screw up.  You can't just change
			   zone number and use the same letters. */
			CS_stncp (csErrnam,mgrs,sizeof (mgrs));
			CS_erpt (cs_MGRS_STR8);
			goto error;
		}
		mgrsPtr += 1;

		/* Now to parse the digits following the third letter.  Number
		   of digits must be even. */
		count = (int)(strlen (mgrsPtr));
		if ((count & 1) != 0)
		{
			CS_stncp (csErrnam,mgrs,sizeof (mgrs));
			CS_erpt (cs_MGRS_STR2);
			goto error;
		}
		count /= 2;
		if (count > 5)
		{
			CS_stncp (csErrnam,mgrs,sizeof (mgrs));
			CS_erpt (cs_MGRS_STR3);
			goto error;
		}

		/* Get the X offset. */
		xBase = 0;
		multiplier = 100000L;
		for (idx = 0;idx < count;idx += 1)
		{
			if (!isdigit (*mgrsPtr))
			{
				CS_stncp (csErrnam,mgrs,sizeof (mgrs));
				CS_erpt (cs_MGRS_STR4);
				return -1;
			}
			xBase = xBase * 10 + (*mgrsPtr++ - '0');
			multiplier /= 10L;
		}
		xBase = (long)((double)xBase * (double)multiplier);

		/* Now the Y. */
		yBase = 0;
		multiplier = 100000L;
		for (idx = 0;idx < count;idx += 1)
		{
			if (!isdigit (*mgrsPtr))
			{
				CS_stncp (csErrnam,mgrs,sizeof (mgrs));
				CS_erpt (cs_MGRS_STR4);
				return -1;
			}
			yBase = yBase * 10 + (*mgrsPtr++ - '0');
			multiplier /= 10L;
		}
		yBase = (long)((double)yBase * (double)multiplier);

		/* Compute a UTM coordinate for this thing. */
		utmUps [XX] = (idxX * 100000) + xBase;
		utmUps [YY] = (idxY * 100000) + yBase;

		/* The above are supposed to be the UTM coordinates of the
		   southwest corner of the reference grid cell.  We do the
		   following to give us the center of the grid cell. */

		utmUps [XX] += csMgrsRoundOff [count];
		utmUps [YY] += csMgrsRoundOff [count];

		/* Convert back to lat/long. Note, we do the add 2,000,000
		   trick to get the right cycle of the Y coordinate.  That
		   is, the Y series of letters cycles as many as four times.
		   So we add 2,000,000 as many times as we need to in order
		   to get the resulting latitude to fall in the right cell
		   per the first letter of the MGRS string. */
		if (baseLat < 0.0) utmZone = -utmZone;
		while (TRUE)
		{
			/* Use our own little function which knows about the
			   funny Norway stuff. */
			status = CScalcLatLng (__This,latLng,utmUps,utmZone);
			if (latLng [LAT] >= (double)baseLat) break;
			utmUps [YY] += 2000000.00;
		}
		if (status != 0)
		{
			CS_stncp (csErrnam,mgrs,sizeof (mgrs));
			CS_erpt (cs_MGRS_STRA);
			goto error;
		}

		/* If the resulting latitude is greater than or equal to maximumLat,
		   the original string was actually bogus. */
		if (latLng [LAT] >= maximumLat)
		{
			CS_stncp (csErrnam,mgrs,sizeof (mgrs));
			CS_erpt (cs_MGRS_STR9);
			goto error;
		}

		/* If the resulting longitude is in a different zone than what the
		   string is, we set up a warning situation.  Note, we have to deal
		   with the Norway issue, again. */
		if (latLng [LAT] >= 72 && latLng [LNG] >= 0.0 && latLng [LNG] < 42.0)
		{
			if      (latLng [LNG] <  9.0) utmZone1 = 31;
			else if (latLng [LNG] < 21.0) utmZone1 = 33;
			else if (latLng [LNG] < 33.0) utmZone1 = 35;
			else                          utmZone1 = 37;
		}
		else if (latLng [LAT] >= 56.0 && latLng [LAT] < 64.0 &&
				 latLng [LNG] >=  3.0 && latLng [LNG] < 12.0)
		{
			utmZone1 = 32;
		}
		else
		{
			utmZone1 =	CS_utmzon (latLng [LNG]);
			if (latLng [LAT] < 0.0) utmZone1 = -utmZone1;
		}

		/* Make sure we stayed in the right zone.  Otherwise, the string
		   is suspect. */
		if (utmZone1 != utmZone)
		{
			/* Note, this is a warning message. */
			rtnValue = 1;
			CS_erpt (cs_MGRS_STRC);
		}		
 	}
	else
	{
		CS_stncp (csErrnam,mgrs,sizeof (mgrs));
		CS_erpt (cs_MGRS_STRB);
		goto error;
	}
	return rtnValue;
error:
	return -1;
}
