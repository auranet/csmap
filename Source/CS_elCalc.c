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

			 File Name: $RCSfile: CS_elCalc.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #3 $
		 Check In Date:	$Date: 2005/07/26 $

		Last Revision:	$Log: CS_elCalc.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:10  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:11  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:08  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:17  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:24  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:12  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:52  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:27  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:55  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:21  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:16  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:43  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1501  2002/11/12 04:21:56  nto
		Last Revision:	Added a high precision beta inverse.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:19  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:22  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:15  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:37  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:26  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:10  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:47  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:42  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:19  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:16:53  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:24  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:16  nto
		Last Revision:	Revision 10.1  2000/02/11 06:04:20  nto
		Last Revision:	Cosmetic
		Last Revision:	Revision 10.0  1999/10/05 18:27:13  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:24  nto
		Last Revision:	Revision 1.2  1999/09/06 20:15:58  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_elCalc.c#3 $"};
#endif

#include "cs_map.h"

/**********************************************************************
**	CSbtIsu (bt_ptrI,e_sq);
**	lat = CSbtIcal (bt_ptrI,beta);
**	CSbtFsu (bt_ptrF,e_sq);
**	beta = CSbtFcal (bt_ptrF,lat);
**
**	struct cs_BtcofI_ *btI_ptr;		carries the inverse setup results.
**	struct cs_BtcofF_ *btI_ptr;		carries the forward setup results.
**	double e_sq;					eccentricity of the ellipsoid squared.
**	double lat;						geographic latitude (in radians).
**	double beta;					authalic latitude (in radians).
**	
**	See Synder, equations 3-18 and 3-14 on page 16, and also
**	the Horner optimizations, equations 3-34 & 3-35 on page 19.
**********************************************************************/

void EXP_LVL5 CSbtIsu (struct cs_BtcofI_ *btI_ptr,double e_sq)
{
	extern double cs_Zero;			/* 0.0 */
	extern double cs_One;			/* 1.0 */
	extern double cs_Two;			/* 2.0 */
	extern double cs_Four;			/* 4.0 */

	double e_fourth;	/* eccentricity to the fourth power. */
	double e_sixth;		/* eccentricity to the sixth power. */

	double tmp_A;
	double tmp_B;
	double tmp_C;

	btI_ptr->e_sq = e_sq;
	btI_ptr->ecent = sqrt (e_sq);

	e_fourth = e_sq * e_sq;
	e_sixth  = e_sq * e_fourth;

	/* Compute the normal series coefficients. */

	tmp_C = ( 761.0 /45360.0) * e_sixth;

	tmp_B = (  23.0 /  360.0) * e_fourth +
			( 251.0 / 3780.0) * e_sixth;

	tmp_A = (   1.0 /    3.0) * e_sq +
			(  31.0 /  180.0) * e_fourth +
			( 517.0 / 5040.0) * e_sixth;

	/* Compute the Horner coefficients.  Note, no sign
	   reversals. */

	btI_ptr->d_prime = cs_Zero;
	btI_ptr->c_prime = cs_Four * tmp_C;
	btI_ptr->b_prime = cs_Two * tmp_B;
	btI_ptr->a_prime = tmp_A - tmp_C;

	/* Compute qPole; the value of q evaluated at the north pole. */
	tmp_A = (cs_One - e_sq) / (btI_ptr->ecent + btI_ptr->ecent);
	tmp_B = log ((cs_One - btI_ptr->ecent) / (cs_One + btI_ptr->ecent));
	btI_ptr->qPole = cs_One - tmp_A * tmp_B; 

	/* That's it. */
	return;
}

double EXP_LVL5 CSbtIcal (Const struct cs_BtcofI_ *btI_ptr,double beta)
{
	double two_beta;
	double lat;
	double sin_2beta;
	double cos_2beta;

	two_beta = beta + beta;
	sin_2beta = sin (two_beta);
	cos_2beta = cos (two_beta);

	lat = ((((((btI_ptr->c_prime) * cos_2beta) +
				btI_ptr->b_prime) * cos_2beta) +
				btI_ptr->a_prime) * sin_2beta) +
				beta;

	return (lat);
}

double EXP_LVL5 CSbtIcalPrec (Const struct cs_BtcofI_ *btI_ptr,double beta)
{
	extern double cs_One;
	extern double cs_Two;

	int itCount;

	double qq;
	double latNew;
	double latLast;
	double latOrig;
	double sinLat;
	double cosLat;

	double tmpA, tmpB;
	double tmp1, tmp2, tmp3, tmp4;

	/* Precise version of the above.  A bit slower, but that just doesn't
	   seem to be that important anymore.  We use the fast version above
	   to get our first approximation.  This means we probably only need
	   a single iteration of the stuff used here. */
	itCount = 10;
	qq = sin (beta) * btI_ptr->qPole;
	tmp2 = qq / (cs_One - btI_ptr->e_sq);
	latOrig = latNew = CSbtIcal (btI_ptr,beta);
	do
	{
		if (itCount-- < 0) break;
		latLast = latNew;

		/* Compute next approximation. */
		sinLat = sin (latLast);
		cosLat = cos (latLast);

		tmpA = btI_ptr->ecent * sinLat;
		tmpB = cs_One - (btI_ptr->e_sq * sinLat * sinLat);
		tmp4 = cs_One / (btI_ptr->ecent + btI_ptr->ecent) * log ((cs_One - tmpA) / (cs_One + tmpA));
		tmp3 = sinLat / tmpB;
		tmp1 = (tmpB * tmpB) / (cs_Two * cosLat);
		latNew = latLast + tmp1 * (tmp2 - tmp3 + tmp4);
	} while (fabs (latNew-latLast) > 0.8E-11);
	return (itCount >= 0) ? latNew : latOrig;
}

void EXP_LVL5 CSbtFsu (struct cs_BtcofF_ *btF_ptr,double e_sq)
{
	extern double cs_Zero;			/* 0.0 */
	extern double cs_One;			/* 1.0 */
	extern double cs_Two;			/* 2.0 */
	extern double cs_Four;			/* 4.0 */

	double e_fourth;	/* eccentricity to the fourth power. */
	double e_sixth;		/* eccentricity to the sixth power. */

	double tmp_A;
	double tmp_B;
	double tmp_C;

	btF_ptr->e_sq = e_sq;
	btF_ptr->ecent = sqrt (e_sq);

	e_fourth = e_sq * e_sq;
	e_sixth  = e_sq * e_fourth;

	/* Compute the normal series coefficients. */

	tmp_C = ( 383.0 /45360.0) * e_sixth;

	tmp_B = (  17.0 /  360.0) * e_fourth +
			(  61.0 / 1260.0) * e_sixth;

	tmp_A = (   1.0 /    3.0) * e_sq +
			(  31.0 /  180.0) * e_fourth +
			(  59.0 /  560.0) * e_sixth;

	/* Compute the Horner coefficients.  Note, sign
	   reversals are required. */

	btF_ptr->d_prime = cs_Zero;
	btF_ptr->c_prime = -cs_Four * tmp_C;
	btF_ptr->b_prime = cs_Two * tmp_B;
	btF_ptr->a_prime = tmp_C - tmp_A;

	/* Compute qPole; the value of q evaluated at the north pole. */
	tmp_A = (cs_One - e_sq) / (btF_ptr->ecent + btF_ptr->ecent);
	tmp_B = log ((cs_One - btF_ptr->ecent) / (cs_One + btF_ptr->ecent));
	btF_ptr->qPole = cs_One - tmp_A * tmp_B; 

	/* That's it. */
	return;
}

double EXP_LVL5 CSbtFcal (Const struct cs_BtcofF_ *btF_ptr,double lat)
{
	double two_lat;
	double beta;
	double sin_2lat;
	double cos_2lat;

	two_lat = lat + lat;
	sin_2lat = sin (two_lat);
	cos_2lat = cos (two_lat);

	beta = ((((((btF_ptr->c_prime) * cos_2lat) +
				 btF_ptr->b_prime) * cos_2lat) +
				 btF_ptr->a_prime) * sin_2lat) +
				 lat;

	return (beta);
}

double EXP_LVL5 CSbtFcalPrec (Const struct cs_BtcofF_ *btF_ptr,double lat)
{
	extern double cs_One;
	extern double cs_Pi_o_2;
	extern double cs_Mpi_o_2;

	double qq;
	double beta;
	double sinLat;

	double tmpA;
	double tmp1, tmp2;

	sinLat = sin (lat);
	tmpA = cs_One - (btF_ptr->e_sq * sinLat * sinLat);
	tmp1 = sinLat / tmpA;
	tmp2 = (cs_One / (btF_ptr->ecent + btF_ptr->ecent)) * log ((cs_One - btF_ptr->ecent * sinLat) / (cs_One + btF_ptr->ecent * sinLat));
	qq = (cs_One - btF_ptr->e_sq) * (tmp1 - tmp2);
	if (fabs (qq) >= btF_ptr->qPole)
	{
		/* This should only happen when the beta for a pole is requested. */
		beta = (qq > 0.0) ? cs_Pi_o_2 : cs_Mpi_o_2;
	}
	else
	{
		beta = asin (qq / btF_ptr->qPole);
	}
	return beta;
}

/**********************************************************************
**	CSchiIsu (chi_ptrI,e_sq);
**	lat = CSchiIcal (chi_ptrI,chi);
**	CSchiFsu (chi_ptrF,e_sq);
**	chi = CSchiFcal (chi_ptrF,lat);
**
**	struct cs_ChicofI_ *chi_ptrI;	inverse setup results holder.
**	struct cs_ChicofF_ *chi_ptrI;	forward setup results holder.
**	double e_sq;					eccentricity squared.
**	double chi;						conformal latitude.
**	double lat;						geographic latitude.
**	
**	Structures cs_ChiofI_ and cs_ChiofF_ are identical.  We
**	use two distinct structures for consistency.  Perhaps the
**	ANSI protype checking will find a bug for us at times.
**
**	There is a non-iterative formula for the forward calculation.
**	The series calculation used here is significantly faster, and
**	is accurate to within one millimeter.
**********************************************************************/

void EXP_LVL5 CSchiIsu (struct cs_ChicofI_ *chiI_ptr,double e_sq)
{
	extern double cs_Two;			/* 2.0 */
	extern double cs_Four;			/* 4.0 */
	extern double cs_Eight;			/* 8.0 */

	double e_fourth;		/* Eccenticity to the fourth power. */
	double e_sixth;			/* Eccenticity to the sixth power. */
	double e_eighth;		/* Eccenticity to the eighth power. */

	double tmp_A;
	double tmp_B;
	double tmp_C;
	double tmp_D;

	/* Compute the powers of eccentricty which are the
	   power components of the power series. */

	e_fourth = e_sq * e_sq;
	e_sixth = e_fourth * e_sq;
	e_eighth = e_sixth * e_sq;

	/* Compute the normal series coefficients which are used
	   more than once and save them.  Don't want to compute
	   them more than once.  These values come from page 15
	   of Synder, equation 3-5. */

	tmp_D = (4279.0 / 161280.0) * e_eighth;

	tmp_C = (   7.0 /    120.0) * e_sixth +
			(  81.0 /   1120.0) * e_eighth;

	tmp_B = (   7.0 /     48.0) * e_fourth +
			(  29.0 /    240.0) * e_sixth +
			( 811.0 /  11520.0) * e_eighth;

	tmp_A = (    1.0 /     2.0) * e_sq +
			(    5.0 /    24.0) * e_fourth +
			(    1.0 /    12.0) * e_sixth +
			(   13.0 /   360.0) * e_eighth;

	/* Compute the coefficients for the must computationally
	   efficient for of these calculation.  Save them in the
	   provided structure so we don't have to compute all
	   this again.  Note, no sign reversals here. */

	chiI_ptr->d_prime = cs_Eight * tmp_D;
	chiI_ptr->c_prime = cs_Four * tmp_C;
	chiI_ptr->b_prime = cs_Two * tmp_B - cs_Four * tmp_D;
	chiI_ptr->a_prime = tmp_A - tmp_C;

	/* That's it. */

	return;
}

double EXP_LVL5 CSchiIcal (Const struct cs_ChicofI_ *chiI_ptr,double chi)
{
	double lat;
	double two_chi;
	double sin_2chi;
	double cos_2chi;

	two_chi = chi + chi;
	sin_2chi = sin (two_chi);
	cos_2chi = cos (two_chi);

	lat = ((((((((chiI_ptr->d_prime) * cos_2chi) +
				  chiI_ptr->c_prime) * cos_2chi) +
				  chiI_ptr->b_prime) * cos_2chi) +
				  chiI_ptr->a_prime) * sin_2chi) +
				  chi;

	return (lat);
}

void EXP_LVL5 CSchiFsu (struct cs_ChicofF_ *chiF_ptr,double e_sq)
{
	extern double cs_Two;			/*  2.0 */
	extern double cs_Four;			/*  4.0 */
	extern double cs_Mfour;			/* -4.0 */
	extern double cs_Eight;			/*  8.0 */

	double e_fourth;		/* Eccenticity to the fourth power. */
	double e_sixth;			/* Eccenticity to the sixth power. */
	double e_eighth;		/* Eccenticity to the eighth power. */

	double tmp_A;
	double tmp_B;
	double tmp_C;
	double tmp_D;

	/* Compute the powers of eccentricty which are the
	   power components of the power series. */

	e_fourth = e_sq * e_sq;
	e_sixth = e_fourth * e_sq;
	e_eighth = e_sixth * e_sq;

	/* Compute the normal series coefficients which are used
	   more than once and save them.  Don't want to compute
	   them more than once.  These values come from page 15
	   of Synder, equation 3-2. */

	tmp_D = (1237.0 / 161280.0) * e_eighth;

	tmp_C = (  13.0 /    480.0) * e_sixth +
			( 461.0 /  13440.0) * e_eighth;

	tmp_B = (   5.0 /     48.0) * e_fourth +
			(   7.0 /     80.0) * e_sixth +
			( 697.0 /  11520.0) * e_eighth;

	tmp_A = (    1.0 /     2.0) * e_sq +
			(    5.0 /    24.0) * e_fourth +
			(    3.0 /    32.0) * e_sixth +
			(  281.0 /  5760.0) * e_eighth;

	/* Compute the coefficients for the must computationally
	   efficient for of these calculation.  Save them in the
	   provided structure so we don't have to compute all
	   this again.  Note, sign reversals are necessary here. */

	chiF_ptr->d_prime = cs_Eight * tmp_D;
	chiF_ptr->c_prime = cs_Mfour * tmp_C;
	chiF_ptr->b_prime = cs_Two * tmp_B - cs_Four * tmp_D;
	chiF_ptr->a_prime = tmp_C - tmp_A;

	/* That's it. */

	return;
}

double EXP_LVL5 CSchiFcal (Const struct cs_ChicofF_ *chiF_ptr,double lat)
{
	double chi;
	double two_lat;
	double sin_2lat;
	double cos_2lat;

	two_lat = lat + lat;
	sin_2lat = sin (two_lat);
	cos_2lat = cos (two_lat);

	chi = ((((((((chiF_ptr->d_prime) * cos_2lat) +
				  chiF_ptr->c_prime) * cos_2lat) +
				  chiF_ptr->b_prime) * cos_2lat) +
				  chiF_ptr->a_prime) * sin_2lat) +
				  lat;

	return (chi);
}

/**********************************************************************
**	CSmmFsu (mmF_ptr,ka,e_sq);
**	mm = CSmmFcal (mmF_ptr,lat,sin_lat,cos_lat);
**	CSmmIsu (mmI_ptr,ka,e_sq);
**	lat = CSmmIcal (mmI_ptr,mm);
**
**	struct cs_MmcofF_ *mmF_ptr;	pointer the the structure which carries the
**								setup results for the forward calculation.
**	struct cs_MmcofI_ *mmI_ptr;	pointer the the structure which carries the
**								setup results for the inverse calculation.
**	double e_sq;				eccentricity squared of the ellipsoid.
**	double lat;					the geographic latitude.
**	double mm;					geodetic distance along a meridian from the equator.
**	double sin_lat;				sine of the geographic latitude.
**	double cos_lat;				cosine of the geographic latitude.
**	
**	All of these functions are very closely related to the rectifying
**	latitude, what Synder calls mu. In general, the meridional arc
**	length is used in many projections, thus we have one place for
**	this calculation. And since the Transverse Mercator relies on
**	this heavily, great pains ahve been taken to optimize this
**	calculation as much as possible.
**
**	Note, in the forward calculation, the calling sequence requires
**	the presentation of the sine and cosine in addition to the
**	latitude. This was chosen as in most instances these values
**	are already available in the calling module and it would be
**	inefficient to have the CSmmFcal function recalculate them.
**********************************************************************/

void EXP_LVL5 CSmmFsu (struct cs_MmcofF_ *mmF_ptr,double ka,double e_sq)
{
	extern double cs_Fourth;		/* 0.25 */
	extern double cs_Half;			/* 0.5 */
	extern double cs_One;			/* 1.0 */
	extern double cs_Two;			/* 2.0 */
	extern double cs_Four;			/* 4.0 */
	extern double cs_Eight;			/* 8.0 */

	double aa2, bb;
	double nn, nn2, nn3, nn4, nn5;
	double alpha, beta, gamma, delta;
	double tmp;

	aa2 = ka * ka;
	bb = sqrt (aa2 - aa2 * e_sq);

	nn = (ka - bb) / (ka + bb);
	nn2 = nn * nn;
	nn3 = nn2 * nn;
	nn4 = nn2 * nn2;
	nn5 = nn3 * nn2;

	/* This is not really the rectifying radius, but close to it. */

	tmp = cs_One + cs_Fourth * nn2 + (nn4 / 64.0);
	mmF_ptr->rect_rad = cs_Half * (ka + bb) * tmp;

	/* Develop the Williams coefficients. */

	alpha  = (  3.0 /   2.0) * nn  -
			 (  9.0 /  16.0) * nn3 +
			 (  3.0 /  32.0) * nn5;
	beta   = ( 15.0 /  16.0) * nn2 -
			 ( 15.0 /  32.0) * nn4;
	gamma  = ( 35.0 /  48.0) * nn3 -
			 (105.0 / 256.0) * nn5;
	delta  = (315.0 / 512.0) * nn4;

	/* Convert to Horner coefficients. Note, A term and C term require
	   a sign reversal. */

	mmF_ptr->a_prime = gamma - alpha;
	mmF_ptr->b_prime = cs_Two * beta - cs_Four * delta;
	mmF_ptr->c_prime = -cs_Four * gamma;
	mmF_ptr->d_prime = cs_Eight * delta;
	return;
}
/*
	Calculate a meridional arc length.
*/
double EXP_LVL5 CSmmFcal (	Const struct cs_MmcofF_ *mmF_ptr,
							double lat,
							double sin_lat,
							double cos_lat)
{
	extern double cs_Two;			/* 2.0 */

	double kk;
	double sin_2lat;		/* read sine (2 * lat); */
	double cos_2lat;		/* read cosine (2 * lat); */

	sin_2lat = cs_Two * sin_lat * cos_lat;
	cos_2lat = (cos_lat * cos_lat) - (sin_lat * sin_lat);
	
	/* Hope the compiler can figure this out, and do it efficiently. */

	kk = ((((((mmF_ptr->d_prime  * cos_2lat  +
			   mmF_ptr->c_prime) * cos_2lat) +
			   mmF_ptr->b_prime) * cos_2lat) +
			   mmF_ptr->a_prime) * sin_2lat) + lat;

	return (kk * mmF_ptr->rect_rad);
}
/*
	Setup the inverse of the above. This calculates the latitude
	given a meridianl arc.
*/
void EXP_LVL5 CSmmIsu (struct cs_MmcofI_ *mmI_ptr,double ka,double e_sq)
{
	extern double cs_One;			/* 1.0 */

	double aa2, bb;
	double nn, nn2, nn3, nn4;
	double alpha, beta, gamma, delta;
	double tmp;

	/* Calculate n (ie.e nn) */

	aa2 = ka * ka;
	bb = sqrt (aa2 - aa2 * e_sq);
	nn = (ka - bb) / (ka + bb);

	/* Powers of nn. */

	nn2 = nn * nn;
	nn3 = nn2 * nn;
	nn4 = nn2 * nn2;

	/* rTerm is referred to as the radius of the rectifying sphere. */

	tmp = cs_One + ( 9.0 / 4.0) * nn2 + (225.0 / 64.0) * nn4;
	mmI_ptr->rect_rad = ka * (cs_One - nn) * (cs_One - nn2) * tmp;

	/* Williams coeficients. Note, these terms are not the same as
	   the forward calculation. */

	alpha = (   3.0/   2.0) * nn  - ( 27.0/ 32.0) * nn3;
	beta  = (  21.0/  16.0) * nn2 - ( 55.0/ 32.0) * nn4;
	gamma = ( 151.0/  96.0) * nn3;
	delta = (1097.0/ 512.0) * nn4;
	
	/* Now the actual pwer series coeficients. */

	mmI_ptr->coef_0 = (  2.0 * alpha)  - (  4.0 * beta)   + ( 6.0 * gamma) - (8.0 * delta);
	mmI_ptr->coef_2 = (  8.0 * beta)   - ( 32.0 * gamma)  + (80.0 * delta);
	mmI_ptr->coef_4 = ( 32.0 * gamma)  - (192.0 * delta);
	mmI_ptr->coef_6 = (128.0 * delta);

	return;
}
/*
	Latitude from meridional arc length
*/
double EXP_LVL5 CSmmIcal (Const struct cs_MmcofI_ *mmI_ptr,double mm)
{
	double phi, lat;
	double sinPhi, cosPhi;
	double cos2Phi;				/* read cosine squared phi */

	phi = mm / mmI_ptr->rect_rad;
	sinPhi  = sin (phi);
	cosPhi  = cos (phi);
	cos2Phi = cosPhi  * cosPhi;

	lat = ((((((mmI_ptr->coef_6  * cos2Phi) +
				mmI_ptr->coef_4) * cos2Phi) +
				mmI_ptr->coef_2) * cos2Phi) +
				mmI_ptr->coef_0) * sinPhi * cosPhi +
				phi;
	return (lat);
}
/* CSmpFsu -- Set up for Synder equation 18-17, page 130.
	      See equations 3-34 & 3-35 on page 19 for the
	      Horner optimization.

	Similar, but not the same as the M calcualted above.
	This is a special guy only used for the American Polyconic.
*/
void EXP_LVL5 CSmpFsu (struct cs_MpcofF_ *mpF_ptr,double e_sq)
{
	extern double cs_One;		/* 1.0 */
	extern double cs_Two;		/* 2.0 */
	extern double cs_Three;		/* 3.0 */
	extern double cs_Four;		/* 4.0 */
	extern double cs_Six;		/* 6.0 */

	double e_fourth;		/* eccentricity to the fourth power. */
	double e_sixth;			/* eccentricity to the sixth power. */

	double tmp_A;
	double tmp_B;
	double tmp_C;
	double tmp_D;

	/* Save the scaled equatorial radius. */

	e_fourth = e_sq * e_sq;
	e_sixth = e_sq * e_fourth;

	/* Compute the normal series coefficients. */

	tmp_A = cs_One -
			e_sq     * (1.0 /   4.0) -
			e_fourth * (3.0 /  64.0) -
			e_sixth  * (5.0 / 256.0);

	tmp_B = cs_Two   *
			e_sq     * ( 3.0 /    8.0) +
			e_fourth * ( 3.0 /   32.0) +
			e_sixth  * (45.0 / 1024.0);

	tmp_C = cs_Four  *
			e_fourth * (15.0 /  256.0) +
			e_sixth  * (45.0 / 1024.0);

	tmp_D = cs_Six   *
			e_sixth  * (35.0 / 3072.0);

	/* Compute the optimized coeficients which we actually use
	   in the forward calculation. */

	mpF_ptr->a_prime = tmp_A - tmp_C;
	mpF_ptr->b_prime = cs_Three * tmp_D - tmp_B;
	mpF_ptr->c_prime = tmp_C + tmp_C;
	mpF_ptr->d_prime = -cs_Four * tmp_D;

	/* That's it. */

	return;
}
/* CSmpFcal -- Calculation of Synder equation 18-17, page 130. */
double EXP_LVL5 CSmpFcal (Const struct cs_MpcofF_ *mmF_ptr,double lat)
{
	double Mp;
	double cos_2lat;

	cos_2lat = cos (lat + lat);

	Mp = (((((mmF_ptr->d_prime  * cos_2lat) +
		  mmF_ptr->c_prime) * cos_2lat) +
		  mmF_ptr->b_prime) * cos_2lat) +
		  mmF_ptr->a_prime;

	return (Mp);
}
