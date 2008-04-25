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

			 File Name: $RCSfile: CS_gissupprt.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #3 $
		 Check In Date:	$Date: 2005/07/26 $

		Last Revision:	$Log: CS_gissupprt.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:12  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:12  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:09  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:18  nto
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
		Last Revision:	Revision 10.1500  2002/09/22 00:01:20  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:22  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:16  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:37  nto
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
		Last Revision:	Revision 10.200  2000/03/02 18:51:17  nto
		Last Revision:	Revision 10.1  2000/01/30 23:41:47  nto
		Last Revision:	PCLint clean up.
		Last Revision:	Revision 10.0  1999/10/05 18:27:14  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:25  nto
		Last Revision:	Revision 1.2  1999/09/06 19:05:58  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_gissupprt.c#3 $"};
#endif

#include "cs_map.h"

struct cs_MIunit_
{
	char mentor [16];
	char mapinfo [16];
	short mi_nbr;
};
struct cs_MIunit_ cs_MIunit [] =
{
	{      "METER", "m",          7},
	{       "FOOT", "survey ft",  8},
	{       "INCH", "in",        -1},
	{      "IFOOT", "ft",         3},
	{      "IINCH", "in",         2},
	{ "CENTIMETER", "cm",         6},
	{  "KILOMETER", "km",         1},
	{       "YARD", "yd",        -1},
	{       "MILE", "mi",        -1},
	{      "IYARD", "yd",         4},
	{      "IMILE", "mi",         0},
	{       "KNOT", "nmi",        9},
	{      "NAUTM", "nmi",        9},
	{  "DECIMETER", "dm",        -2},
	{ "MILLIMETER", "mm",         5},
	{           "", "",          -3}
};

struct cs_MIdatum_
{
   	char mentor [10];
	short mapinfo;
};

struct cs_MIdatum_ cs_MIdatum [] =
{
	{  "ADINDAN",  1 },
	{  "AFGOOYE",  2 },
	{ "AINELABD",  3 },
	{   "ANNA65",  4 },
	{  "ARC1960",  6 },
	{  "ASCENSN",  7 },
	{ "ASTATN52", 11 },
	{ "ASTRLA66", 12 },
	{ "ASTRLA84", 13 },
	{ "BELLEVUE", 14 },
	{  "BERMUDA", 15 },
	{   "BOGOTA", 16 },
	{    "CAMPO", 17 },
	{   "CANTON", 18 },
	{     "CAPE", 19 },
	{  "CANAVRL", 20 },
	{ "CARTHAGE", 21 },
	{  "CHATHAM", 22 },
	{     "CHAU", 23 },
	{  "CORREGO", 24 },
	{  "DJAKRTA", 25 },
	{  "DOS1968", 26 },
	{   "EASTER", 27 },
	{  "EUROP50", 28 },
	{  "EUROP79", 29 },
	{ "GNDAJIKA", 30 },
	{   "GD1949", 31 },
	{   "GUAM63", 34 },
	{     "GUX1", 35 },
	{  "HJORSEY", 37 },
	{ "HONGKONG", 38 },
	{   "INDIAN", 41 },
	{ "INDIANTV", 40 },
	{ "IRELND65", 42 },
	{   "ISTS69", 43 },
	{   "JHNSTN", 44 },
	{ "KANDWALA", 45 },
	{ "KERGUELN", 46 },
	{ "KERTAU48", 47 },
	{     "L-C5", 48 },
	{  "LIBERIA", 49 },
	{    "LUZON", 50 },
	{ "LUZON-MI", 51 },
	{  "MADEIRA", 94 },
	{ "MAHE1971", 52 },
	{    "MARCO", 53 },
	{  "MASSAWA", 54 },
	{ "MERCHICH", 55 },
	{ "MICHIGAN", 73 },
	{   "MIDWAY", 56 },
	{    "MINNA", 57 },
	{    "NAD27", 62 },
	{ "NAD27-AK", 63 },
	{ "NAD27-BH", 64 },
	{ "NAD27-SS", 64 },
	{ "NAD27-CA", 66 },
	{ "NAD27-CZ", 67 },
	{ "NAD27-CB", 68 },
	{ "NAD27-CX", 69 },
	{ "NAD27-CU", 70 },
	{ "NAD27-GR", 71 },
	{ "NAD27-MX", 72 },
	{    "NAD83", 74 },
	{  "NHRWN-O", 58 },
	{  "NHRWN-S", 60 },
	{  "NHRWN-U", 59 },
	{ "NAPARIMA", 61 },
	{  "OBSRV66", 75 },
	{ "OLD_EGYP", 76 },
	{    "OLDHI", 77 },
	{     "OMAN", 78 },
	{     "OSGB", 79 },
	{ "PITCAIRN", 81 },
	{     "PRVI", 83 },
	{   "PSAD56", 82 },
	{    "PSC63", 36 },
	{    "QATAR", 84 },
	{   "QORNOQ", 85 },
	{  "REUNION", 86 },
	{ "ROME1940", 87 },
	{   "SA1969", 92 },
	{    "SANTO", 88 },
	{  "SAOBRAZ", 89 },
	{   "SAPPER", 90 },
	{ "SCHWARZK", 91 },
	{  "SINGAPR", 93 },
	{ "TIMBALAI", 96 },
	{    "TOKYO", 97 },
	{  "TRISTAN", 98 },
	{     "VITI", 99 },
	{     "WAKE",100 },
	{    "WGS72",103 },
	{    "WGS84",104 },
	{ "ZANDERIJ",106 },
	{         "", -1 }
};

/**********************************************************************
**	coordsys = CS_mifcs (cs_def);
**
**	struct cs_Csdef_ *cs_def;	pointer to the definition of the coordinate
**								system for which a COORDSYS line is required.
**	char *coordsys;				returns a pointer to a static character array
**								which contains the formatted string.
**
**	Since the return pointer is to a static character array,
**	the results will only remain valid until the next call to
**	this function.
**
**********************************************************************/

Const char* EXP_LVL3 CS_mifcs (Const struct cs_Csdef_ *cs_def)
{
	extern struct cs_Prjtab_ cs_Prjtab [];
	extern char csErrnam [];

   	static char cs_claus [256];

	int datum;
	int zoneNbr;

	char *unit;

	char *cp;
	struct cs_Prjtab_ *pp;
	struct cs_MIdatum_ *dt_ptr;
	struct cs_MIunit_  *un_ptr;

	double cntMer;
	double falseEasting;
	double falseNorthing;
	double unitFactor;

	/* Locate the proper units string. If the coordinate system is
	   geographic in nature, the unit string is blank. */

	for (pp = cs_Prjtab;*pp->key_nm != '\0';pp++)
	{
		if (!CS_stricmp (pp->key_nm,cs_def->prj_knm)) break;
	}
	if (*pp->key_nm == '\0' || pp->setup == NULL)
	{
		CS_stncp (csErrnam,cs_def->prj_knm,MAXPATH);
		CS_erpt (cs_UNKWN_PROJ);
		goto error;
	}
	if (pp->code != cs_PRJCOD_UNITY)
	{
		for (un_ptr = cs_MIunit;un_ptr->mentor [0] != '\0';un_ptr += 1)
		{
			if (!CS_stricmp (cs_def->unit,un_ptr->mentor)) break;
		}
		if (un_ptr->mi_nbr <= 0)
		{
			CS_stncp (csErrnam,cs_def->prj_knm,MAXPATH);
			CS_erpt (cs_MIF_UNIT);
			goto error;
		}
		unit = un_ptr->mapinfo;
	}
	else
	{
		unit = " ";
	}

	/* Locate the datum number. */

	if (cs_def->dat_knm [0] == '\0')
	{
		CS_erpt (cs_MIF_ELREF);
		goto error;
	}
	else
	{
		datum = -1;
		for (dt_ptr = cs_MIdatum;dt_ptr->mapinfo >= 0;dt_ptr += 1)
		{
			if (!CS_stricmp (cs_def->dat_knm,dt_ptr->mentor))
			{
				datum = dt_ptr->mapinfo;
				break;
			}
		}
		if (dt_ptr->mapinfo < 0)
		{
			CS_stncp (csErrnam,cs_def->dat_knm,MAXPATH);
			CS_erpt (cs_MIF_DATUM);
			goto error;
		}
	}

	cp = cs_claus;
	cp += sprintf (cp,"Coordsys Earth Projection ");

	/* Now we ve special code for each projection for which there is
	  known MapInfo support. */

	CS_stncp (csErrnam,cs_def->key_nm,MAXPATH);
	switch (pp->code) {

	case cs_PRJCOD_TRMER:

		sprintf (cp,"8, %d, \"%s\", %.8f, %.8f, %.9f,%.2f,%.2f",
							datum,
							unit,
							cs_def->prj_prm1,
							cs_def->org_lat,
							cs_def->scl_red,
							cs_def->x_off,
							cs_def->y_off);
		break;

	case cs_PRJCOD_UTM:

		unitFactor = CS_unitlu (cs_UTYP_LEN,cs_def->unit);
		if (unitFactor == 0.0) unitFactor = 1.0;
		zoneNbr = (int)cs_def->prj_prm1;
		cntMer = (double)(-183 + (6 * zoneNbr));		/*lint !e790 */
		falseEasting = 500000.0 / unitFactor;
		if (cs_def->prj_prm2 >= 0) falseNorthing = 0.0;
		else falseNorthing = 10000000.0;
		falseNorthing /= unitFactor;
		sprintf (cp,"8, %d, \"%s\", %.8f, %.8f, %.9f,%.2f,%.2f",
							datum,
							unit,
							cntMer,
							0.0,
							0.9996,
							falseEasting,
							falseNorthing);
		break;

	case cs_PRJCOD_LM2SP:

		sprintf (cp,"3, %d, \"%s\", %.8f, %.8f, %.8f, %.8f, %.2f, %.2f",
							datum,
							unit,
							cs_def->org_lng,
							cs_def->org_lat,
							cs_def->prj_prm1,
							cs_def->prj_prm2,
							cs_def->x_off,
							cs_def->y_off);
		break;

	case cs_PRJCOD_ALBER:

		sprintf (cp,"9, %d, \"%s\", %.8f, %.8f, %.8f, %.8f, %.2f, %.2f",
								datum,
								unit,
								cs_def->org_lng,
								cs_def->org_lat,
								cs_def->prj_prm1,
								cs_def->prj_prm2,
								cs_def->x_off,
								cs_def->y_off);
		break;

	case cs_PRJCOD_MRCAT:

		if (cs_def->prj_prm2 != 0.0 ||
			cs_def->x_off != 0.0 ||
			cs_def->y_off != 0.0)
		{
			CS_erpt (cs_MIF_FEATR);
			goto error;
		}
		sprintf (cp,"10, %d, \"%s\", %.8f",
						datum,
						unit,
						cs_def->prj_prm1);
		break;

	case cs_PRJCOD_AZMED:
		if (cs_def->prj_prm1 != 0.0  ||
			cs_def->x_off != 0.0 ||
			cs_def->y_off != 0.0)
		{
			CS_erpt (cs_MIF_FEATR);
			goto error;
		}
		sprintf (cp,"5, %d, \"%s\", %.8f, %.8f, 90.0",
							datum,
							unit,
							cs_def->org_lng,
							cs_def->org_lat);
		break;

	case cs_PRJCOD_AZMEA:
		if (cs_def->prj_prm1 != 0.0 ||
			cs_def->x_off != 0.0 ||
			cs_def->y_off != 0.0)
		{
			CS_erpt (cs_MIF_FEATR);
			goto error;
		}
		sprintf (cp,"5, %d, \"%s\", %.8f, %.8f, 90.0",
							datum,
							unit,
							cs_def->org_lng,
							cs_def->org_lat);
		break;

	case cs_PRJCOD_HOM1XY:
		sprintf (cp,"7, %d, \"%s\", %.8f, %.8f, %.8f, %.9f, %.3f, %.3f",
							datum,
							unit,
							cs_def->prj_prm1,
							cs_def->prj_prm2,
							cs_def->prj_prm3,
							cs_def->scl_red,
							cs_def->x_off,
							cs_def->y_off);
		break;

	case cs_PRJCOD_EDCNC:

		sprintf (cp,"6, %d, \"%s\", %.8f, %.8f, %.8f, %.8f, %.2f, %.2f",
							datum,
							unit,
							cs_def->org_lng,
							cs_def->org_lat,
							cs_def->prj_prm1,
							cs_def->prj_prm2,
							cs_def->x_off,
							cs_def->y_off);
		break;

	case cs_PRJCOD_MILLR:

		if (cs_def->x_off != 0.0 ||
			cs_def->y_off != 0.0)
		{
			CS_erpt (cs_MIF_FEATR);
			goto error;
		}
		sprintf (cp,"11, %d, \"%s\", %.8f",
							datum,
							unit,
							cs_def->prj_prm1);
		break;

	case cs_PRJCOD_UNITY:

		if (cs_def->org_lng != 0.0 ||
			CS_stricmp (cs_def->unit,"DEGREE"))
		{
			CS_erpt (cs_MIF_FEATR);
			goto error;
		}
		sprintf (cp,"1, %d",datum);
		break;

	default:
		CS_erpt (cs_MIF_PROJ);
		goto error;
	}
	return (cs_claus);
error:
	return (NULL);
}

