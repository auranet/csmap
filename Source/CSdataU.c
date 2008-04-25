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

			 File Name: $RCSfile: CSdataU.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #6 $
		 Check In Date:	$Date: 2007/01/04 $

		Last Revision:	$Log: CSdataU.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:03  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:07  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:04  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:13  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:20  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.801  2004/03/25 21:07:51  nto
		Last Revision:	Added Gold Coast Foot, and three more Indian Foot's
		Last Revision:	Revision 11.800  2004/01/13 23:29:08  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:49  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:24  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.502  2003/11/07 03:58:06  nto
		Last Revision:	Added some units for WKT & EPSG support.
		Last Revision:	Revision 11.501  2003/08/22 21:12:51  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:18  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:12  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:40  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1500  2002/09/22 00:01:16  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1402  2002/09/21 23:59:50  nto
		Last Revision:	Removed Const property so table can be modified at runtime.
		Last Revision:	Revision 10.1401  2002/09/15 21:24:25  nto
		Last Revision:	Added Plural Unit Name and Unit System.  Also added dummy entries for UNitAdd function.
		Last Revision:	Revision 10.1400  2002/08/09 18:14:19  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:10  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:32  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:23  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:07  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:41  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:36  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:13  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:16:48  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:18  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:11  nto
		Last Revision:	Revision 10.1  2000/01/31 00:18:52  nto
		Last Revision:	PCLint clean up, removed extra comment block.
		Last Revision:	Revision 10.0  1999/10/05 18:27:10  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:21  nto
		Last Revision:	Revision 1.2  1999/09/06 19:54:22  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CSdataU.c#6 $"};
#endif

#include "cs_map.h"

struct cs_Unittab_ cs_Unittab [] =
{
	/* The following entries define the relationshil between units
	   of length.  The factor is the value which one multiplies a
	   value by to obtain meters.  To convert meters to one of the
	   units listed, divide the meter value by the constant given. */

	{cs_UTYP_LEN,        "Meter",             "Meters",     "M", cs_USYS_Metric,         1.00000000000000000000,    9001  },
	{cs_UTYP_LEN,         "Foot",    "U.S.Survey Feet",    "FT", cs_USYS_English,        0.30480060960121920243,    9003  },
	{cs_UTYP_LEN,         "Inch",  "U.S.Survey Inches",    "IN", cs_USYS_English,        0.02540005080010160020,       0  },
	{cs_UTYP_LEN,        "IFoot",              "IFeet",   "IFT", cs_USYS_English,        0.30480000000000000000,    9002  },
	{cs_UTYP_LEN,   "ClarkeFoot",         "ClarkeFeet",    "CF", cs_USYS_English,        0.3047972651151,           9005  },
	{cs_UTYP_LEN,    "SearsFoot",          "SearsFeet",    "SF", cs_USYS_English,        0.30479947153867624624,    9041  },
	{cs_UTYP_LEN,"GoldCoastFoot",      "GoldCoastFeet",   "GCF", cs_USYS_English,        0.30479971018150881758,    9094  },
	{cs_UTYP_LEN,        "IInch",            "IInches",   "IIN", cs_USYS_English,        0.02540000000000000000,       0  },
	{cs_UTYP_LEN,    "MicroInch",        "MicroInches",    "UI", cs_USYS_English,        0.00002540000000000000,       0  },
	{cs_UTYP_LEN,          "Mil",               "Mils",    "ML", cs_USYS_English,        0.00000002540000000000,       0  },
	{cs_UTYP_LEN,   "Centimeter",        "Centimeters",    "CM", cs_USYS_Metric,        0.01000000000000000000,        0  },
	{cs_UTYP_LEN,    "Kilometer",         "Kilometers",    "KM", cs_USYS_Metric,     1000.00000000000000000000,     9036  },
	{cs_UTYP_LEN,         "Yard",   "U.S.Survey Yards",    "YD", cs_USYS_English,        0.91440182880365760731,       0  },
	{cs_UTYP_LEN,    "SearsYard",         "SearsYards",    "SY", cs_USYS_English,        0.914398414616029,         9040  },
	{cs_UTYP_LEN,   "IndianYard",        "IndianYards",   "InY", cs_USYS_English,        0.91439853074444079983,    9084  },
	{cs_UTYP_LEN,   "IndianYd37",        "IndianYds37",   "InY", cs_USYS_English,        0.91439523,                9085  },
	{cs_UTYP_LEN,   "IndianFoot",         "IndianFeet",  "InFt", cs_USYS_English,        0.30479951,                9080  },
	{cs_UTYP_LEN,   "IndianFt37",         "IndianFt37","InFt37", cs_USYS_English,        0.30479841,                9081  },
	{cs_UTYP_LEN,   "IndianFt62",         "IndianFt62","InFt62", cs_USYS_English,        0.3047996,                 9082  },
	{cs_UTYP_LEN,   "IndianFt75",         "IndianFt75","InFt75", cs_USYS_English,        0.3047995,                 9083  },
	{cs_UTYP_LEN,         "Mile",   "U.S.Survey Miles",    "MI", cs_USYS_English,     1609.34721869443738887477,       0  },
	{cs_UTYP_LEN,        "IYard",             "IYards",   "IYD", cs_USYS_English,        0.91440000000000000000,    9096  },
	{cs_UTYP_LEN,        "IMile",             "IMiles",   "IMI", cs_USYS_English,     1609.34400000000000000000,    9093  },
	{cs_UTYP_LEN,         "Knot",              "Knots",    "KT", cs_USYS_English,     1852.00000000000000000000,    9030  },
	{cs_UTYP_LEN,        "NautM",             "NautMs",    "NM", cs_USYS_English,     1852.00000000000000000000,    9030  },
	{cs_UTYP_LEN,       "Lat-66",            "Lat-66s",   "L66", cs_USYS_None,      110943.316488932731        ,       0  },
	{cs_UTYP_LEN,       "Lat-83",            "Lat-83s",   "L83", cs_USYS_None,      110946.25736872234125      ,       0  },
	{cs_UTYP_LEN,    "Decimeter",         "Decimeters",    "DM", cs_USYS_Metric,         0.10000000000000000000,       0  },
	{cs_UTYP_LEN,   "Millimeter",        "Millimeters",    "MM", cs_USYS_Metric,         0.00100000000000000000,       0  },
	{cs_UTYP_LEN,    "Dekameter",         "Dekameters",    "DK", cs_USYS_Metric,        10.00000000000000000000,       0  },
	{cs_UTYP_LEN,   "Hectometer",        "Hectometers",    "HM", cs_USYS_Metric,       100.00000000000000000000,       0  },
	{cs_UTYP_LEN,  "GermanMeter",       "GermanMeters",    "GM", cs_USYS_Metric,         1.0000135965,              9031  },
	{cs_UTYP_LEN,       "CaGrid",            "CaGrids",    "CG", cs_USYS_English,        0.999738,                     0  },
	{cs_UTYP_LEN,  "ClarkeChain",       "ClarkeChains",    "CC", cs_USYS_English,       20.1166194976,              9039  },
	{cs_UTYP_LEN,  "GunterChain",       "GunterChains",    "GC", cs_USYS_English,       20.11684023368047,             0  },
	{cs_UTYP_LEN,  "BenoitChain",       "BenoitChains",    "BC", cs_USYS_English,       20.116782494375872,         9062  },
	{cs_UTYP_LEN,   "SearsChain",        "SearsChains",    "SC", cs_USYS_English,       20.11676512155,             9042  },
	{cs_UTYP_LEN,   "ClarkeLink",        "ClarkeLinks",    "CL", cs_USYS_English,         .201166194976,            9039  },
	{cs_UTYP_LEN,   "GunterLink",        "GunterLinks",    "GL", cs_USYS_English,         .2011684023368047,           0  },
	{cs_UTYP_LEN,   "BenoitLink",        "BenoitLinks",    "BL", cs_USYS_English,         .20116782494375872,       9063  },
	{cs_UTYP_LEN,    "SearsLink",         "SearsLinks",    "SL", cs_USYS_English,         .2011676512155,           9043  },
	{cs_UTYP_LEN,          "Rod",               "Rods",    "RD", cs_USYS_English,        5.02921005842012,             0  },
	{cs_UTYP_LEN,   "IntnlChain",        "IntnlCHains",  "IChn", cs_USYS_English,       20.1168,                    9097  },
	{cs_UTYP_LEN,    "IntnlLink",         "IntnlLinks",  "ILnk", cs_USYS_English,         .201168,                  9098  },
	{cs_UTYP_LEN,        "Perch",            "Perches",    "PE", cs_USYS_English,        5.02921005842012,             0  },
	{cs_UTYP_LEN,         "Pole",              "Poles",    "PO", cs_USYS_English,        5.02921005842012,             0  },
	{cs_UTYP_LEN,      "Furlong",           "Furlongs",    "FU", cs_USYS_English,      201.1684023368046,              0  },
	{cs_UTYP_LEN,         "Rood",              "Roods",    "RO", cs_USYS_English,        3.778266898,                  0  },
	{cs_UTYP_LEN,     "CapeFoot",           "CapeFeet",    "CA", cs_USYS_English,        0.3047972615,                 0  },
	{cs_UTYP_LEN,      "Brealey",           "Brealeys",    "BR", cs_USYS_English,      375.00000000000000000000,       0  },

	/* The following entries define the relationship between units of
	   angular measure.  One multiplies a value by the given factor
	   to obtain a value in degrees.  To convert from degrees to
	   one of the units given, one divides the degree value by the
	   given factor. */

	{cs_UTYP_ANG,       "Degree",            "Degrees",    "DG", cs_USYS_None,           1.00000000000000000000,    9102  },
	{cs_UTYP_ANG,         "Grad",              "Grads",    "GR", cs_USYS_None,           0.90000000000000000000,    9105  },
	{cs_UTYP_ANG,        "Grade",             "Grades",    "GR", cs_USYS_None,           0.90000000000000000000,    9105  },
	{cs_UTYP_ANG,      "MapInfo",           "MapInfos",    "MA", cs_USYS_None,           0.00000100000000000000,       0  },
	{cs_UTYP_ANG,          "Mil",               "Mils",   "MIL", cs_USYS_None,           0.05625000000000000000,    9114  },
	{cs_UTYP_ANG,       "Minute",            "Minutes",    "MN", cs_USYS_None,           0.01666666666666666666,    9103  },
	{cs_UTYP_ANG,       "Radian",            "Radians",    "RA", cs_USYS_None,          57.2957795130823208772 ,    9101  },
	{cs_UTYP_ANG,       "Second",            "Seconds",    "SE", cs_USYS_None,           0.00027777777777777777,    9104  },
	{cs_UTYP_ANG,      "Decisec",           "Decisecs",    "DS", cs_USYS_None,           0.00002777777777777777,       0  },
	{cs_UTYP_ANG,     "Centisec",          "Centisecs",    "CS", cs_USYS_None,           0.00000277777777777777,       0  },
	{cs_UTYP_ANG,     "Millisec",          "Millisecs",    "MS", cs_USYS_None,           0.00000027777777777777,       0  },

	/* The following are essentially bogus unit definitions which are marked,
	   by virtue of the type, off (i.e. disabled).  These entries are replaced
	   by user defined entries.  There is no practical limit to the number
	   of slots can be added. */

	{cs_UTYP_OFF,      " <user>",            " <user>",    " z", cs_USYS_None,           0.00000000000000000000,       0  },
	{cs_UTYP_OFF,      " <user>",            " <user>",    " z", cs_USYS_None,           0.00000000000000000000,       0  },
	{cs_UTYP_OFF,      " <user>",            " <user>",    " z", cs_USYS_None,           0.00000000000000000000,       0  },
	{cs_UTYP_OFF,      " <user>",            " <user>",    " z", cs_USYS_None,           0.00000000000000000000,       0  },
	{cs_UTYP_OFF,      " <user>",            " <user>",    " z", cs_USYS_None,           0.00000000000000000000,       0  },
	{cs_UTYP_OFF,      " <user>",            " <user>",    " z", cs_USYS_None,           0.00000000000000000000,       0  },
	{cs_UTYP_OFF,      " <user>",            " <user>",    " z", cs_USYS_None,           0.00000000000000000000,       0  },
	{cs_UTYP_OFF,      " <user>",            " <user>",    " z", cs_USYS_None,           0.00000000000000000000,       0  },

	/* The following entry terminates the table. */

	{cs_UTYP_END,           " z",                 " z",    " z", cs_USYS_None,          0.00000000000000000000,        0  }
};
