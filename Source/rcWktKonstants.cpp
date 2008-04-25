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
	** co/uld be cause for legal action against you and/or your         **
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

			 File Name: $RCSfile: rcWktKonstants.cpp $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #6 $
		 Check In Date:	$Date: 2007/01/10 $

		Last Revision:	$Log: rcWktKonstants.cpp $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:26  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:21  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1101  2005/01/15 06:05:06  nto
		Last Revision:	Adjusted to hande Oracle flavor of WKT.
		Last Revision:	Revision 11.1100  2004/11/01 18:53:22  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:27  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:33  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:23  nto
		Last Revision:	Revision 11.700  2003/12/19 01:50:02  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:39  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 1.2  2003/11/24 01:14:24  nto
		Last Revision:	Major modifications to fix several problems.
		Last Revision:	Revision 1.1  2003/10/01 22:10:26  nto
		Last Revision:	Initial Revision

		*  *  *  *  R E M A R K S *  *  *  *  *


******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/rcWktKonstants.cpp#6 $"};
#endif

#include "cs_map.h"
#include "rcWellKnownText.hpp"
#include "cs_wkt.h"

////////////////////////////////////////////////////////////////////////////////
// This array associates the WKT type enumerator with the identifying text
// string.  The boolean indicates if the type includes a name as the value
// item.  Note that the implementation assumes a one-to-one correspondence
// between the enumerator and this table.
TrcWktEleTypeMap KrcWktEleTypeMap [] =
{
	{         "<None>", rcWktNone,          false                },
	{      "AUTHORITY", rcWktAuthority,     true                 },
	{           "AXIS", rcWktAxis,          true                 },
	{       "COMPD_CS", rcWktCompDCS,       true                 },
	{      "CONCAT_MT", rcWktConcatMt,      false                },
	{          "DATUM", rcWktDatum,         true                 },
	{      "FITTED_CS", rcWktFittedCS,      true                 },
	{         "GEOCCS", rcWktGeoCCS,        true                 },
	{         "GEOGCS", rcWktGeogCS,        true                 },
	{       "GEOGTRAN", rcWktGeogTran,      true                 },
	{     "INVERSE_MT", rcWktInverseMt,     false                },
	{       "LOCAL_CS", rcWktLocalCS,       true                 },
	{         "METHOD", rcWktMethod,        true                 },
	{      "PARAMETER", rcWktParameter,     true                 },
	{       "PARAM_MT", rcWktParamMt,       true                 },
	{ "PASSTHROUGH_MT", rcWktPassThroughMt, false                },
	{         "PRIMEM", rcWktPrimeM,        true                 },
	{         "PROJCS", rcWktProjCS,        true                 },
	{     "PROJECTION", rcWktProjection,    true                 },
	{       "SPHEROID", rcWktSpheroid,      true                 },
	{        "TOWGS84", rcWktToWgs84,       false                },
	{           "UNIT", rcWktUnit,          true                 },
	{     "VERT_DATUM", rcWktVertDatum,     true                 },
	{        "VERT_CS", rcWktVertCS,        true                 },
	{    "LOCAL_DATUM", rcWktLocalDatum,    true                 },
	{      "<Unknown>", rcWktUnknown,       false                }
};
//newPage//
///////////////////////////////////////////////////////////////////////////////
// This array associates a text string with the axis enumerator.  This is not
// really used.  It was developed, and appears to be correct.  It is preserved
// only in case it may be useful in the future.
TrcWktAxisValueMap KrcWktAxisValueMap [] =
{
	{         "<None>", rcWktAxisNone                           },
	{          "NORTH", rcWktAxisNorth                          },
	{          "SOUTH", rcWktAxisSouth                          },
	{           "EAST", rcWktAxisEast                           },
	{           "WEST", rcWktAxisWest                           },
	{             "UP", rcWktAxisUp                             },
	{           "DOWN", rcWktAxisDown                           },
	{          "OTHER", rcWktAxisOther                          },
	{        "Unknown", rcWktAxisUnknown                        }
};
#ifdef __SKIP__
//newPage//
///////////////////////////////////////////////////////////////////////////////
// The following table maps a WKT parameter name with an enumeration value.
// Where appropriate, equivalent cs_PRMCOD_????? values are given as well as
// EPSG numeric code values.  Note, that:
//
// 1> cs_PRMCOD_????? is actually an index into the cs_Prjprm table defined
//    above. 
// 2> This table includes datum parameter codes as these values appear as
//    elements of the Parameter type in WKT.
// 3> The above enumeration classifies several parameters as being Cartesian
//    transformation parameters as that uis what they will be in the soon to
//    be release RefCon Engine product.
// 4> Several names are given, and the actual names used depend upon the
//    specific flavor of WKT being processed.  CS-MAP prefers the OGC flavor
//    of WKT believing it to be the most standardized of the various flavors,
//    although the ESRI flavor may be the most ubiquitous.
//
// Some of the names here are guesses as I can't find official documentation
// for all of these.  Help me out if and when you can (888-ASK-NORM).
//
TrcWktPrmNameMap KrcWktPrmNameMap [] =
{
	{ rcWktPrmXTranslation,   cs_WKTCOD_DELTAX,8605,"X_Axis_Translation",	// WKT OCR
													"X_Axis_Translation",	// WKT GeoTiff
													"X_Axis_Translation",	// WKT ESRI (std frm?)
													"X Axis Translation",	// WKT Oracle
													"",						// WKT Geo Tools
													"X-axis translation",	// EPGS Name
													"",						// Application ALternate Name
													"" },					// Local Alternate Name
	{ rcWktPrmYTranslation,   cs_WKTCOD_DELTAY,8606,"Y_Axis_Translation",
													"Y_Axis_Translation",
													"Y_Axis_Translation",
													"Y Axis Translation",	// WKT Oracle
													"",						// WKT Geo Tools
													"Y-axis translation",
													"",
													""},
	{ rcWktPrmZTranslation,   cs_WKTCOD_DELTAZ,8607,"Z_Axis_Translation",
													"Z_Axis_Translation",
													"Z_Axis_Translation",
													"Z Axis Translation",	// WKT Oracle
													"",						// WKT Geo Tools
													"Z-axis translation",
													"",
													""},
	{ rcWktPrmXRotation,      cs_WKTCOD_ROTATX,8608,"X_Axis_Rotation",
													"X_Axis_Rotation",
													"X_Axis_Rotation",
													"X Axis Rotation",		// WKT Oracle
													"",						// WKT Geo Tools
													"X-axis rotation",
													"",
													""},
	{ rcWktPrmYRotation,      cs_WKTCOD_ROTATY,8609,"Y_Axis_Rotation",
													"Y_Axis_Rotation",
													"Y_Axis_Rotation",
													"Y Axis Rotation",		// WKT Oracle
													"",						// WKT Geo Tools
													"Y-axis rotation",
													"",
													""},
	{ rcWktPrmZRotation,      cs_WKTCOD_ROTATZ,8610,"Z_Axis_Rotation",
													"Z_Axis_Rotation",
													"Z_Axis_Rotation",
													"Z Axis Rotation",		// WKT Oracle
													"",						// WKT Geo Tools
													"Z-axis rotation",
													"",
													""},
	{ rcWktPrmDatumScale,     cs_WKTCOD_BWSCAL,8611,"Datum_Scale",
													"Datum_Sale",
													"Scale_Difference",
													"Scale Difference",		// WKT Oracle
													"",						// WKT Geo Tools
													"Scale difference",
													"",
													""},
	{rcWktPrmLatitudeOfOrg,   cs_WKTCOD_ORGLAT,8801,"latitude_of_origin",
													"NatOriginLat",
													"Latitude_Of_Origin",
													"Latitude_Of_Origin",	// WKT Oracle
													"latitude_of_origin",	// WKT Geo Tools
													"Latitude of natural origin",
													"",
													""},
	{rcWktPrmLongitudeOfOrg,  cs_PRMCOD_CNTMER,8802,"central_meridian",
													"NatOriginLong",
													"Central_Meridian",
													"Central_Meridian",		// WKT Oracle
													"central_meridian",		// WKT Geo Tools
													"Longitude of natural origin",
													"",
													""},
	{rcWktPrmScaleAtOrigin,   cs_WKTCOD_SCLRED,8805,"scale_factor",
													"ScaleAtNatOrigin",
													"Scale_Factor",
													"Scale_Factor",			// WKT Oracle
													"scale_factor",			// WKT Geo Tools
													"Scale factor at natural origin",
													"",
													""},
	{rcWktPrmFalseEasting,     cs_WKTCOD_FEAST,8806,"false_easting",
													"FalseEasting",
													"False_Easting",
													"False_Easting",		// WKT Oracle
													"false_easting",		// WKT Geo Tools
													"False easting",
													"",
													""},
	{rcWktPrmFalseNorthing,   cs_WKTCOD_FNORTH,8807,"false_northing",
													"FalseNorthing",
													"False_Northing",
													"False_Northing",		// WKT Oracle
													"false_northing",		// WKT Geo Tools
													"False northing",
													"",
													""},
	{rcWktPrmLatitudeOfCtr,   cs_PRMCOD_GCPLAT,8811,"latitude_of_center",
													"CenterLat",
													"Latitude_Of_Center",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Latitude of projection centre",
													"",
													""},
	{rcWktPrmLongitudeOfCtr,  cs_PRMCOD_GCPLNG,8812,"longitude_of_center",
													"CenterLong",
													"Longitude_Of_Center",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Longitude of projection centre",
													"",
													""},
	{      rcWktPrmAzimuth,    cs_PRMCOD_GCAZM,8813,"azimuth",
													"AzimuthAngle",
													"Azimuth",
													"Azimuth",				// WKT Oracle
													"",						// WKT Geo Tools
													"Azimuth of initial line",
													"",
													""},
	{rcWktPrmRectifiedGrdAng, cs_PRMCOD_SKWAZM,8814,"rectified_grid_angle",
													"RectifiedGridAngle",
													"Rectified_Grid_Angle",		/*??*/
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Angle from Rectified to Skew Grid",
													"",
													""},
	{ rcWktPrmScaleAtCenter,  cs_WKTCOD_SCLRED,8815,"scale_factor",
													"ScaleAtCenter",
													"Scale_Factor",
													"Scale_Factor",			// WKT Oracle
													"scale_factor",			// WKT Geo Tools
													"Scale factor on initial line",
													"",
													""},
	{rcWktPrmEastingOfCtr,     cs_WKTCOD_FEAST,8816,"false_easting",
													"FalseEasting",
													"False_Easting",
													"",						// WKT Oracle
													"false_easting",		// WKT Geo Tools
													"Easting at projection center",
													"",
													""},
	{rcWktPrmNorthingOfCtr,   cs_WKTCOD_FNORTH,8817,"false_northing",
													"FalseNorthing",
													"False_Northing",
													"",						// WKT Oracle
													"false_northing",		// WKT Geo Tools
													"Northing at projection center",
													"",
													""},
	{rcWktPrmPsdoParallelLat,cs_PRMCOD_OSTDPLL,8818,"pseudo_standard_parallel_1",
													"",
													"Pseudo_Standard_Parallel_1",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Latitude of pseudo standard parallel",
													"",
													""},
	{rcWktPrmPsdoParallelScl, cs_PRMCOD_NOTYET,8819,"scale_factor",
													"ScaleAtCenter",
													"Scale_Factor",
													"Scale_Factor",			// WKT Oracle
													"",						// WKT Geo Tools
													"Scale factor on pseudo standard parallel",
													"",
													""},
	{rcWktPrmLatOfFalseOrg,   cs_WKTCOD_ORGLAT,8821,"latitude_of_origin",
													"FalseOriginLat",
													"Latitude_Of_Origin",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Latitude of false origin",
													"",
													""},
	{rcWktPrmLngOfFalseOrg,   cs_WKTCOD_ORGLNG,8822,"central_meridian",
													"FalseOriginLong",
													"Central_Meridian",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Longitude of false origin",
													"",
													""},
	{rcWktPrmStdParallel1,   cs_PRMCOD_NSTDPLL,8823,"standard_parallel_1",
													"StdParallel1",
													"Standard_Parallel_1",
													"Standard_Parallel_1",	// WKT Oracle
													"standard_parallel1",	// WKT Geo Tools
													"Longitude of 1st standard parallel",
													"",
													""},
	{rcWktPrmStdParallel2,  cs_PRMCOD_SSTDPLL,8824,"standard_parallel_2",
													"StdParallel2",
													"Standard_Parallel_2",
													"Standard_Parallel_2",	// WKT Oracle
													"standard_parallel2",	// WKT Geo Tools
													"Longitude of 2nd standard parallel",
													"",
													""},
	{rcWktPrmEastingFalseOrg, cs_WKTCOD_FEAST,8826,"false_easting",
													"FalseOriginEasting",
													"False_Easting",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Easting of false origin",
													"",
													""},
	{rcWktPrmNorthingFalseOrg,cs_WKTCOD_FNORTH,8827,"false_northing",
													"FalseOriginNorthing",
													"False_Northing",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Northing of false origin",
													"",
													""},
	{  rcWktPrmLatOfStdParall,cs_PRMCOD_STDCIR,8832,"",
													"",
													"",
													"",						// WKT Oracle
													"latitude_true_scale",	// WKT Geo Tools
													"Latitude of Standard Parallel",
													"",
													""},
	// We use the cs_PRMCOD_NOTYET to indicate an EPSG parameter which is not
	// used by any CS-MAP projection, but will likely have at least an
	// equivalent paramete i future.  Notice, that WKT does not support any
	// of the EPSG parameters which require these parameters either.
	{rcWktPrmSphericalOrgLat, cs_PRMCOD_NOTYET,8828,"",
													"",
													"",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Spherical latitude of origin",
													"",
													""},
	{rcWktPrmSphericalOrgLng, cs_PRMCOD_NOTYET,8829,"",
													"",
													"",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Spherical longitude of origin",
													"",
													""},
	{rcWktPrmSystemWestLimit, cs_PRMCOD_NOTYET,8830,"",
													"",
													"",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Initial longitude",
													"",
													""},
	{rcWktPrmSystemZoneWidth, cs_PRMCOD_NOTYET,8831,"",
													"",
													"",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Zone width",
													"",
													""},
	///////////////////////////////////////////////////////////////////////////
	// The following are parameters which appear to be supported by WKT but not
	// by EPSG.  Therefore, the names are (in many cases) guesses and there are
	// no EPSG names or codes.
	{rcWktPrmLatFirstPoint,   cs_PRMCOD_P1LAT,8802,"latitude_of_1st_point",
													"",
													"Latitude_Of_1st_Point",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""},
	{rcWktPrmLngFirstPoint,    cs_PRMCOD_P1LNG,   0,"longitude_of_1st_point",
													"",
													"Longitude_Of_1st_Point",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""},
	{rcWktPrmLatSecondPoint,   cs_PRMCOD_P2LAT,   0,"latitude_of_2nd_point",
													"",
													"Latitude_Of_2nd_Point",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""},
	{rcWktPrmLngSecondPoint,  cs_PRMCOD_P2LNG,8802,"longitude_of_2nd_point",
													"",
													"Longitude_Of_2nd_Point",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""},
	///////////////////////////////////////////////////////////////////////////
	// The following are parameters which appear to be supported by some WKT
	// flavors but not by anybody else.  Therefore, the names are here just
	// so that they will not produce errors.
	{         rcWktPrmNone,  cs_PRMCOD_NOTUSED,   0,"",
													"",
													"",
													"",						// WKT Oracle
													"semi_major",			// WKT Geo Tools
													"",
													"",
													""},
	{         rcWktPrmNone,  cs_PRMCOD_NOTUSED,   0,"",
													"",
													"",
													"",						// WKT Oracle
													"semi_minor",			// WKT Geo Tools
													"",
													"",
													""},
	///////////////////////////////////////////////////////////////////////////
	// The Y Axis Azimuth parameter is a parameter MSI has added to its 
	// implementation of the Lambert Equidistant Azimuthal and the Lambert
	// Equal Area Azimuthal.  Neither EPSG or WKT support it.
	{rcWktPrmYaxisAzimuth,   cs_PRMCOD_YAXISAZ,   0,"",
													"",
													"",
													"",						// WKT Oracle"",						// WKT Geo Tools
													"",
													"",
													""},
	// The following entry terminates the table.
	{    rcWktPrmUnknown,    cs_PRMCOD_NOTUSED,   0,"",
													"",
													"",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""}
};
#endif
//newPage//
///////////////////////////////////////////////////////////////////////////////
// The following is a table of acronyms which is the first step in reducing
// the size of a key name.  Many of these are widely used.  Some were
// invented for the purpose of this table.  This table is used to reduce
// all key name types.
extern "C" const struct csKeyNmRed_ csAcronyms [] =
{
	{                      "Ancienne Triangulation Francaise",  "ATF"      },
	{                            "Australian Antarctic Datum",  "AAD"      },
	{                             "Australian Geodetic Datum",  "AGD"      },
	{                            "Average Terrestrial System",  "ATS"      },
	{                 "European Terrestrial Reference System",  "ETRF"     },
	{                         "Geocentric Datum of Australia",  "GDA"      },
	{                             "Geodetic Reference System",  "GRS"      },
	{                               "Japanese Geodetic Datum",  "JDA"      },
	{                        "Militar-Geographische Institut",  "MGI"      },
	{                        "High Accuracy Regional Network",  "HARN"     },
	{                     "Canadian Spatial Reference System",  "CSRS"     },
	{                            "New Zealand Geodetic Datum",  "NZGD"     },
	{                                  "North American Datum",  "NAD"      },
	{                      "Nouvelle Triangulation Francaise",  "NTF"      },
	{                      "Posiciones Geodesicas Argentinas",  "PGA"      },
	{                      "Provisional South American Datum",  "PSAD"     },
	{                                  "Qatar National Datum",  "QND"      },
	{                              "Red Geodesica Venezolana",  "RGV"      },
	{                            "Reseau Geodesique Francais",  "RGF"      },
	{                                 "Reseau National Belge",  "RGB"      },
	{"Sistema de Referencia Geocentrico para America del Sur",  "GRS-SA"   },
	{                                  "South American Datum",  "SAD"      },
	{                     "Swiss Terrestrial Reference Frame",  "STRF"     },
	{                                 "World Geodetic System",  "WGS"      },
	{                       "Yemen National Geodetic Network",  "Yeman"    },
	{                                   "British West Indies",  "BWI"      },
	{                                   "Tunisia Mining Grid",  "TMG"      },
	{                                                      "",   ""        }
};
//newPage//
///////////////////////////////////////////////////////////////////////////////
// The following table is used to reduce some special cases with regard to
// ellipsoid names.
extern "C" const struct csKeyNmRed_ csElReduce [] =
{
	{      "Spheroid",  ""         },
	{   "Adjustment)",  "Adj)"     },
	{   "Definition)",  "Def)"     },
	{              "",   ""        }
};
//newPage//
///////////////////////////////////////////////////////////////////////////////
// The following table is used to reduce some special cases with regard to
// datum names.  Essentially, we try to eliminate redundant information.  For
// example, "Azores Central Islands" is reduced to "Azores Central" with the
// justification that with regard to the Azores, the term "Islands" is
// redundant.  Similarly, this table applies only to datum names.  Therefore,
// the term datum within a datum name is considered to be redundant.
extern "C" const struct csKeyNmRed_ csDtReduce [] =
{
	{                             " To WGS 1984",  ""                       },
	{                   "Azores Central Islands",  "Azores Central"         },
	{                "Azores Occidental Islands",  "Azores Occidental"      },
	{                  "Azores Oriental Islands",  "Azores Oriental"        },
	{              "Deutsches Hauptdreiecksnetz",  "Hauptdreiecksnetz"      },
	{                  "EPSG example Platform Y",  "EPSG exmpl Y"           },
	{                           "European Datum",  "European"               },
	{                    "European Libyan Datum",  "European/Libyan"        },
	{          "Greek Geodetic Reference System",  "Greek GRS"              },
	{"Jednotne Trigonometricke Site Katastralni",  "Katastralni"            },
	{         "Kartasto Koordinaati Jarjestelma",  "Jarjestelma"            },
	{                "National Geodetic Network",  "National Geodetic Net"  },
	{                              "Nord Sahara",  "N Sahara"               },
	{                 "Not specified (based on ",  "Ellp: "                 },
	{                              " ellipsoid)",  ""                       },
	{                   "Rikets koordinatsystem",  "Rikets"                 },
	{                              "(Stockholm)",  "(Stckhlm)"              },
	{          "Yemen National Geodetic Network",  "Yeman"                  },
	{                                         "",   ""                      }
};
//newPage//
///////////////////////////////////////////////////////////////////////////////
// The following table is used to reduce some special cases with regard to
// datum names.  Essentially, we try to eliminate redundant information.  For
// example, "Azores Central Islands" is reduced to "Azores Central" with the
// justification that with regard to the Azores, the term "Islands" is
// redundant.  Similarly, this table applies only to datum names.  Therefore,
// the term datum within a datum name is considered to be redundant.
//
// As of this writing (October 1, 2003) this list is rather incomplete.
// However, the basic functionality associated with it has been tested.
//
extern "C" const struct csKeyNmRed_ csCsReduce [] =
{
	{                                " / ",  "."          },
	{                             " zone ",  "-"          },
	{                           "National",  "Ntnl"       },
	{                       "Gauss-Kruger",  "GK"         },
	{                     "Nord de Guerre",  "NdG"        },
	{                           "3-degree",  "3d"         },
	{                     "American Samoa",  "Samoa"      },
	{                     "Azores Central",  "AzoresCtrl" },
	{                  "Azores Occidental",  "AzoresOccd" },
	{                      "Azores Orient",  "AzoresOrnt" },
	{                     "Campo Inchause",  "Campo"      },
	{                 "NAD 1927 CGQ77 MTM",  "MTM77"      },
	{                              " 1987",  "87"         },
	{                              " 1962",  "62"         },
	{                              " 1958",  "58"         },
	{                              " 1957",  "57"         },
	{                              " 1943",  "43"         },
	{                              " 1950",  "50"         },
	{                              " 1960",  "60"         },
	{                              " 1940",  "40"         },
	{                              " 1948",  "48"         },
	{                              " 1939",  "39"         },
	{                              " 1954",  "54"         },
	{                              " 1987",  "97"         },
	{                              " 1987",  "97"         },
	{                              " 1987",  "97"         },
	{                              " 1987",  "97"         },
	{                              " 1905",  "05"         },
	{                              " 1907",  "07"         },
	{                          "(Jakarta)",  "(Jkta)"     },
	{                         "(Brussels)",  "(Brsls)"    },
	{                                   "",  ""           }
};
