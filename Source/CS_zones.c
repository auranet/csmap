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

			 File Name: $RCSfile: CS_zones.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #3 $
		 Check In Date:	$Date: 2005/07/26 $

		Last Revision:	$Log: CS_zones.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:20  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:17  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:15  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:23  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:29  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:18  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:58  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:33  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:13:00  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:26  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:21  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:49  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1500  2002/09/22 00:01:25  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:26  nto
		Last Revision:	Revision 10.1200  2002/06/20 18:00:32  nto
		Last Revision:	Official release: 10.12
		Last Revision:	Revision 10.1100  2002/06/13 14:18:45  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:30  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:14  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:56  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:51  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:32  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:17:02  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:33  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:24  nto
		Last Revision:	Revision 10.1  2000/01/31 00:12:18  nto
		Last Revision:	PCLint clean up.
		Last Revision:	Revision 10.0  1999/10/05 18:27:19  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:30  nto
		Last Revision:	Revision 1.2  1999/09/06 18:55:06  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_zones.c#3 $"};
#endif

#include "cs_map.h"

/**********************************************************************
**	zone_cnt = CS_zones (csdef,zones);
**	zone_flg = CSzone (zone_ptr,west,cent,east);
**	zone_ptr = CS_znlocF (zones,zone_cnt,lng,lat);
**	zone_ptr = CS_znlocI (zones,zone_cnt,xx,yy);
**
**	struct cs_Csdef_ *csdef;	definition of the coordinate system
**	struct cs_Zone_ zones [8];	pointer to an array of 8 cs_Zone structures
**								in which the results are returned.
**	int zone_flg;				returns TRUE if a valid zone definition was
**								extracted and returned, else returns FALSE.
**	struct cs_Zone_ *zone_ptr;	pointer to a single zone structure in which
**								results are returned; or a pointer to the
**								appropriate zone if found, else NULL.
**	double west;				cs_Csdef_ parameter which may be the western
**								extent of a zone in degrees.
**	double cent;				cs_Csdef_ parameter which may be the central
**								meridian of a zone in degrees.
**	double east;				cs_Csdef_ parameter which may be the eastern
**								extent of a zone in degrees.
**	int zone_cnt;				number of valid zone definitions located, or
**								contained in a zone definition array.
**	double lng,lat;				lat/long for which a pointer to the appropriate
**								zone is to be returned.
**	double xx,yy;				cartesian coordinate pair for which a pointer to
**								the approriate zone is to be returned.
**
**	CS_zones returns the number of zone definitions located in
**	the provided cs_Csdef_ structure.
**
**	CS_znlocF and CS_znlocI return NULL if an appropriate zone
**	could not be located.
**
**	CSzone exaines its arguments and determines if the three
**	values define a zone.  If so, the zone structure is
**	populated and TRUE is returned.  Otherwise, FALSE is
**	returned.
**********************************************************************/

int EXP_LVL9 CS_zones (	Const struct cs_Csdef_ *csdef,
						struct cs_Zone_ zones [8])
{
	extern double cs_Mpi;			/* -PI */

	int ii;
	int zone_cnt;
	int east_idx;

	struct cs_Zone_ *zp;

	double east_lng;

	zone_cnt = 0;

	zone_cnt += CSzone (&zones [zone_cnt],
						csdef->prj_prm1,
						csdef->prj_prm2,
						csdef->prj_prm3);
	zone_cnt += CSzone (&zones [zone_cnt],
						csdef->prj_prm4,
						csdef->prj_prm5,
						csdef->prj_prm6);
	zone_cnt += CSzone (&zones [zone_cnt],
						csdef->prj_prm7,
						csdef->prj_prm8,
						csdef->prj_prm9);
	zone_cnt += CSzone (&zones [zone_cnt],
						csdef->prj_prm10,
						csdef->prj_prm11,
						csdef->prj_prm12);
	zone_cnt += CSzone (&zones [zone_cnt],
						csdef->prj_prm13,
						csdef->prj_prm14,
						csdef->prj_prm15);
	zone_cnt += CSzone (&zones [zone_cnt],
						csdef->prj_prm16,
						csdef->prj_prm17,
						csdef->prj_prm18);
	zone_cnt += CSzone (&zones [zone_cnt],
						csdef->prj_prm19,
						csdef->prj_prm20,
						csdef->prj_prm21);
	zone_cnt += CSzone (&zones [zone_cnt],
						csdef->prj_prm22,
						csdef->prj_prm23,
						csdef->prj_prm24);

	east_lng = cs_Mpi;
	east_idx = -1;
	for (ii = 0;ii < zone_cnt;ii++)
	{
		zp = &zones [ii];
		if (zp->east_lng > east_lng)
		{
			east_lng = zp->east_lng;
			east_idx = ii;
		}
	}
	if (east_idx >= 0)
	{
		zones [east_idx].east_flg = TRUE;
	}

	return (zone_cnt);
}

int EXP_LVL9 CSzone (	struct cs_Zone_ *zp,
						double west,
						double cent,
						double east)
{
	extern double cs_Zero;			/* 0.0 */
	extern double cs_Degree;		/* PI / 180.0 */
	extern double cs_Two_pi;		/* 2 PI */

	int flag;

	zp->ns_flag  = 0;
	zp->east_flg = FALSE;
	zp->west_xx  = cs_Zero;
	zp->x_off    = cs_Zero;
	zp->east_xx  = cs_Zero;

	if (west == cs_Zero && east == cs_Zero)			/*lint !e777 */
	{
		zp->west_lng = cs_Zero;
		zp->cent_lng = cs_Zero;
		zp->east_lng = cs_Zero;
		zp->width    = cs_Zero;
		return (0);
	}

	/* Extract the flag word from the west
	   argument. */

	flag = ((int)fabs (west) / 1000) % 4;
	west = fmod (west,1000.0);
	switch (flag) {
	case 1:
		zp->ns_flag = 1;
		break;
	case 2:
		zp->ns_flag = -1;
		break;
	default:
	case 0:
	case 3:
		zp->ns_flag = 0;
		break;
	}
	zp->west_lng = CS_adj2pi (west * cs_Degree);
	zp->cent_lng = CS_adj2pi (cent * cs_Degree);
	zp->east_lng = CS_adj2pi (east * cs_Degree);
	zp->width = zp->east_lng - zp->west_lng;
	if (zp->width < cs_Zero) zp->width += cs_Two_pi;
	return (1);
}

Const struct cs_Zone_ * EXP_LVL9 CS_znlocF (	Const struct cs_Zone_ zones [8],
												int zone_cnt,
												double lng,
												double lat)
{
	extern double cs_Zero;			/* 0.0 */
	extern double cs_Two_pi;		/* 2PI */

	int ii;
    const struct cs_Zone_ *zp;

	double del_lng;

	for (ii = 0,zp = zones;ii < zone_cnt;ii++,zp++)
	{
		/* The hemisphere check is pretty quick,
		   lets to that first before the more
		   intensive longitude test. */

		if ((lat >= cs_Zero && zp->ns_flag < 0) ||
			(lat <  cs_Zero && zp->ns_flag > 0)
		   )
		{
			continue;
		}

		/* The zone longitude boundaries are stored in
		   normalized longitudes in radians, -PI < lng <= PI.
		   Thus, to be able to straddle -180 properly, we use
		   the following.  Notice, by convention, we include
		   the western extreme in the zone, but not the
		   eastern extreme unless the zone is the easternmost
		   zone. */

		del_lng = (lng - zp->west_lng);
		if (del_lng < cs_Zero) del_lng += cs_Two_pi;

		if (del_lng < zp->width ||
			(del_lng <= zp->width && zp->east_flg))
		{
			return (zp);
		}
	}
	return (NULL);
}

Const struct cs_Zone_ * EXP_LVL9 CS_znlocI (	Const struct cs_Zone_ zones [8],
												int zone_cnt,
												double xx,
												double yy)
{
	extern double cs_Zero;		/* 0.0 */

	int ii;
    Const struct cs_Zone_ *zp;

	for (ii = 0,zp = zones;ii < zone_cnt;ii++,zp++)
	{
		if ((yy >= cs_Zero && zp->ns_flag < 0) ||
			(yy <  cs_Zero && zp->ns_flag > 0)
		   )
		{
			continue;
		}
		if (xx >= zp->west_xx &&
			(xx < zp->east_xx || (zp->east_flg && xx == zp->east_xx))	/*lint !e777 */		
		   )
		{
			return (zp);
		}
	}
	return (NULL);
}
