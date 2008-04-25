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

			 File Name: $RCSfile: CSwktFlavors.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #8 $
		 Check In Date:	$Date: 2007/01/12 $

		Last Revision:	$Log: CSwktFlavors.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:05  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:08  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1101  2005/01/15 05:59:58  nto
		Last Revision:	Added the Oracle flavor, plus some other minor tweaks.
		Last Revision:	Revision 11.1100  2004/11/01 18:53:05  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:14  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:21  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:09  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:50  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:25  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 1.1  2003/11/24 01:18:28  nto
		Last Revision:	Initial Revision

		*  *  *  *  R E M A R K S *  *  *  *  *

	Implements all of the flavor based behavior of WKT.  These functions
	hide all of this stuff behind a pretty generic interface.  This
	interface is valid in C or C++.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CSwktFlavors.c#8 $"};
#endif

#include "cs_map.h"
#include "cs_wkt.h"

/*
	The following array associates a CS-MAP projection code value with an ESPG
	projection code value and many of the several names known to appear in
	various forms of WKT for the projection.  Provisions are included for local
	variations and developer variations.  These are useful as there is no
	definitive standard for WKT.

	Krovak does not appear in the following table as the parameter mapping is
	inconsistent between WKT and CS-MAP.  I have not been able to determine any
	rational mapping bewtween the two systems of parameters.  The parameters
	not listed in the WKT standard, so that's no help.  Krovak is not listed in
	the list of WKT support projections either.

	There are several other WKT projections which CS-MAP doesn't support, and
	several projections which CS-MAP supports, but are not supported by WKT.
	The following is a list of those projections which seem to map between the
	two systems.

	In this first go at such a table, we list only those necessary to support
	processing WKT, which is the reason for this effort.  Perhaps in a later
	release it will be expanded to cover all WKT AND CS-MAP projections.
*/
struct csWktPrjNameMap_ csWktPrjNameMap [] =
{
/*	The following is a guide to keep literal constants within the size of the 
	table elements.
                                     1         2         3         4         5         6
                            123456789012345678901234567890123456789012345678901234567890123  */
	{ cs_PRJCOD_LM1SP,9801,"Lambert_Conformal_Conic_1SP",			// WKT OCR
	                       "CT_LambertConfConic_1SP",				// WKT GeoTiff
	                       "Lambert_Conformal_Conic",				// WKT ESRI (std frm)
	                       "Lambert Conformal Conic",				// WKT Oracle
	                       "Lambert_Conic_Conformal_1SP",			// WKT Geo Tools
	                       "Lambert Conic Conformal (1SP)",			// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_LM2SP,9802,"Lambert_Conformal_Conic_2SP",
	                       "CT_LambertConfConic_2SP",
	                       "Lambert_Conformal_Conic",				// WKT ESRI (std frm)
	                       "Lambert Conformal Conic",				// WKT Oracle
	                       "Lambert_Conic_Conformal_2SP",			// Geo Tools
	                       "Lambert Conic Conformal (2SP)",
	                       "",
	                       ""},
	{ cs_PRJCOD_LM2SP,9802,"",
	                       "",
	                       "",										// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "Lambert_Conformal_Conic_2SP",			// Geo Tools
	                       "Lambert Conic Conformal (2SP)",
	                       "",
	                       ""},
	{ cs_PRJCOD_LMBLG,9803,"Lambert_Conformal_Conic_2SP_Belgium",
	                       "",
	                       "",										// WKT ESRI (std frm)
	                       "Lambert Conformal Conic (Belgium 1972)",// WKT Oracle
	                       "Lambert_Conic_Conformal_2SP_Belgium",	// Geo Tools
	                       "Lambert Conic Conformal (2SP Belgium)",
	                       "",
	                       ""},
	{ cs_PRJCOD_MRCAT,9804,"Mercator_1SP",
	                       "CT_Mercator",
	                       "Mercator",								// WKT ESRI (std frm)
	                       "Mercator",								// WKT Oracle
	                       "Mercator_1SP",							// WKT Geo Tools
	                       "Mercator (1SP)",
	                       "",
	                       ""},
	{ cs_PRJCOD_MRCAT,9805,"Mercator_2SP",
	                       "CT_Mercator",
	                       "Mercator",								// WKT ESRI (std frm)
	                       "Mercator",								// WKT Oracle
	                       "Mercator_2SP",							// WKT Geo Tools
	                       "Mercator (2SP)",
	                       "",
	                       ""},
	{ cs_PRJCOD_CSINI,9806,"Cassini-Soldner",
	                       "CT_CassiniSoldner",
	                       "Cassini",								// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "Cassini-Soldner",						// WKT Geo Tools
	                       "Cassini-Soldner",
	                        "",
	                        ""},
	{ cs_PRJCOD_TRMER,9807,"Transverse_Mercator",
	                       "CT_TransverseMercator",
	                       "Transverse_Mercator",					// WKT ESRI (std frm)
	                       "Transverse Mercator",					// WKT Oracle
	                       "Transverse_Mercator",					// WKT Geo Tools
	                       "Transverse Mercator",
	                        "",
	                        ""},
	{ cs_PRJCOD_TRMER,9807,"",
	                       "",
	                       "",										// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "Transverse Mercator Finnish KKJ",		// WKT Geo Tools
	                       "",
	                        "",
	                        ""},
	{cs_PRJCOD_GAUSSK,9807,"Gauss_Kruger",
	                       "GaussKruger",
	                       "Gauss_Kruger",							// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "Transverse Mercator",					// WKT Heo Tools
	                       "Transverse Mercator",
	                        "",
	                        ""},
	{ cs_PRJCOD_SOTRM,9808,"Transverse_Mercator_South_Oriented",
	                       "CT_TransverseMercator_SouthOriented",
	                       "",										// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "Transverse_Mercator_South_Orientated",	// WKT Geo Tools
	                       "Transverse Mercator (South Orientated)",
	                        "",
	                        ""},
	{ cs_PRJCOD_OSTRO,9809,"Oblique_Stereographic",
	                       "CT_ObliqueStereographic",
	                       "Double_Stereographic",					// WKT ESRI (std frm)
	                       "Stereographic",							// WKT Oracle
	                       "Oblique_Stereographic",					// WKT Geo Tools
	                       "Oblique Stereographic",
	                        "",
	                        ""},
	{ cs_PRJCOD_PSTRO,9810,"Polar_Stereographic",
	                       "CT_PolarStereographic",
	                       "Stereographic",							// WKT ESRI (std frm)
	                       "Stereographic",							// WKT Oracle
	                       "Polar_Stereographic",					// WKT Geo Tools
	                       "Polar Stereographic",
	                        "",
	                        ""},
	{ cs_PRJCOD_NZLND,9811,"New_Zealand_Map_Grid",
	                       "CT_NewZealandMapGrid",
	                       "New_Zealand_Map_Grid",					// WKT ESRI (std frm)
	                       "New Zealand Map Grid",					// WKT Oracle
	                       "New_Zealand_Map_Grid",					// Wkt Geo Tools
	                       "New Zealand Map Grid",
	                        "",
	                        ""},
	{cs_PRJCOD_HOM1XY,9812,"hotine_oblique_mercator",
	                       "CT_ObliqueMercator_Hotine",
	                       "Hotine_Oblique_Mercator_Azimuth_Natural_Origin",	// WKT ESRI (std frm)
	                       "Hotine Oblique Mercator",				// WKT Oracle
	                       "Hotine_Oblique_Mercator",				// WKT Geo Tools				
	                       "Hotine Oblique Mercator",
	                        "",
	                        ""},
	{cs_PRJCOD_LABORD,9813,"Laborde_Oblique_Mercator",
	                       "CT_ObliqueMercator_Laborde",
	                       "",										// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools				
	                       "Laborde Oblique Mercator",
	                       "",
	                       ""},
	{ cs_PRJCOD_SWISS,9814,"Swiss_Oblique_Cylindrical",
	                       "CT_SwissObliqueCylindrical",
	                       "",										// WKT ESRI (std frm)
	                       "Swiss Oblique Mercator",				// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "Swiss Oblique Cylindrical",
	                       "",
	                       ""},
	{ cs_PRJCOD_RSKEW,9815,"Oblique_Mercator",
	                       "CT_ObliqueMercator",
	                       "Hotine_Oblique_Mercator_Azimuth_Center",// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "Oblique_Mercator",						// WKT Geo Tools
	                       "Oblique Mercator",
	                       "",
	                       ""},
	{cs_PRJCOD_TUNGRD,9816,"Tunisia_Mining_Grid",
	                       "",
	                       "",										// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "Tunisia_Mining_Grid"					// WKT Geo Tools
	                       "Tunisia Mining Grid",
	                       "",
	                       ""},
	{ cs_PRJCOD_PLYCN,9818,"Polyconic",
	                       "CT_Polyconic",
	                       "Polyconic",								// WKT ESRI (std frm)
	                       "Polyconic",								// WKT Oracle
	                       "American_Polyconic",					// WKT Geo Tools
	                       "American Polyconic",
	                       "",
	                       ""},
	{cs_PRJCOD_KROVAK,9819,"Krovak",
	                       "",
	                       "Krovak",								// WKT ESRI (std frm)
	                       "",										// WKT Oracle
						   "Krovak_Oblique_Conic_Conformal",		// WKT Geo Tools
	                       "Krovak Oblique Conic Conformal",
	                       "",
	                       ""},
	{ cs_PRJCOD_AZMEA,9820,"Lambert_Azimuthal_Equal_Area",
	                       "CT_LambertAzimuthalEqualArea",
	                       "Lambert_Azimuthal_Equal_Area",				// WKT ESRI (std frm)
	                       "Lambert Azimuthal Equal Area",				// WKT Oracle
						   "Lambert_Azimuthal_Equal_Area_Spherical",	// WKT Geo Tools
	                       "Lambert Azimuthal Equal Area",
	                       "",
	                       ""},
	{ cs_PRJCOD_ALBER,9822,"Albers_Conic_Equal_Area",
	                       "CT_AlbersEqualArea",
	                       "Albers",								// WKT ESRI (std frm)
	                       "Albers Conical Equal Area",				// WKT Oracle
	                       "Albers_Conic_Equal_Area",				// WKT Geo Tools
	                       "",
	                       "",
	                       ""},
	{ cs_PRJCOD_EDCYL,9823,"Equirectangular",
	                       "CT_Equirectangular",
	                       "Equidistant_Cylindrical",				// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "Equidistant_Cylindrical",				// WKT Geo Tools
	                       "Equidistant Cylindrical",
	                       "",
	                       ""},
	{   cs_PRJCOD_UTM,9824,"Transverse_Mercator",
	                       "CT_TransverseMercator",
	                       "Transverse_Mercator",					// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "Transverse_Mercator",					// WKT Geo Tools
	                       "Transverse Mercator",
	                        "",
	                        ""},
	{ cs_PRJCOD_BONNE,9827,"",
	                       "",
	                       "Bonne",									// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "Bonne",
	                       "",
	                       ""},
	{ cs_PRJCOD_EDCNC,   0,"Equidistant_Conic",
	                       "",
	                       "Equidistant_Conic",						// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",
	                       "",
	                       ""},
	{ cs_PRJCOD_AZMED,   0,"Lambert_Azimuthal_Equidistant",
	                       "CT_LambertAzimuthalEquidistant",
	                       "Azimuthal_Equidistant",					// WKT ESRI (std frm)
	                       "Azimuthal Equidistant",					// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "Lambert Azimuthal Equidistant",
	                       "",
	                       ""},
	{ cs_PRJCOD_MILLR,   0,"Miller_Cylindrical",
	                       "CT_MillerCylindrical",
	                       "Miller_Cylindrical",					// WKT ESRI (std frm)
	                       "Miller Cylindrical",					// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",
	                       "",
	                       ""},
	{ cs_PRJCOD_SINUS,   0,"Sinusoidal",
	                       "CT_Sinusoidal",
	                       "Sinusoidal",							// WKT ESRI (std frm)
	                       "Sinusoidal",							// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",
	                       "",
	                       ""},
	{ cs_PRJCOD_VDGRN,   0,"VanDerGrinten",
	                       "CT_VanDerGrinten",
	                       "Van_der_Grinten_I",						// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",
	                       "",
	                       ""},
	{ cs_PRJCOD_ROBIN,   0,"Robinson",
	                       "CT_Robinson",
	                       "Robinson",								// WKT ESRI (std frm)
	                       "Robinson",								// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",
	                       "",
	                       ""},
	{ cs_PRJCOD_EKRT4,   0,"Eckert_IV",
	                       "",
	                       "Eckert_IV",								// WKT ESRI (std frm)
	                       "Eckert IV",								// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",
	                       "",
	                       ""},
	{ cs_PRJCOD_EKRT6,   0,"Eckert_VI",
	                       "",
	                       "Eckert_VI",								// WKT ESRI (std frm)
	                       "Eckert VI",								// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",
	                       "",
	                       ""},
	{ cs_PRJCOD_MOLWD,   0,"Mollweide",
	                       "Mollweide",
	                       "Mollweide",								// WKT ESRI (std frm)
	                       "Mollweide",								// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",
	                       "",
	                       ""},
	{ cs_PRJCOD_PSTRO,   0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Stereographic_North_Pole",				// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_PSTRO,   0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Stereographic_South_Pole",				// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_HOM2XY,  0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Hotine_Oblique_Mercator_Two_Point_Natural_Origin",	// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{  cs_PRJCOD_RSKEW,  0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Rectified_Skew_Orthomorphic_Natural_Origin", // WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_ORTHO,   0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Orthographic",							// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_GNOMC,   0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Gnomonic",								// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_EDCYL,   0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Cylindrical_Equal_Area",				// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_WINKL,   0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Winkel_Tripel",							// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Eckert_I",								// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Eckert_II",								// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Eckert_III",							// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Eckert_V",								// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Gall_Stereographic",					// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Behrmann",								// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Quartic_Authalic",						// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Loximuthal",							// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Two_Point_Equidistant",					// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Winkel_I",								// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Winkel_II",								// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Aitoff",								// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Hammer_Aitoff",							// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Flat_Polar_Quartic",					// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Craster_Parabolic",						// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Times",									// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Vertical_Near_Side_Perspective",		// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Plate_Carree",							// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Fuller",								// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Cube",									// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Transverse_Mercator_Complex",			// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",										// WKT OCR
	                       "",										// WKT GeoTiff
	                       "Flat_Polar_Quartic",					// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",									// WKT OCR
	                       "",										// WKT GeoTiff
	                       "",										// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "Bonne_South_Orientated",				// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",									// WKT OCR
	                       "",										// WKT GeoTiff
	                       "",										// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "Lambert_Conic_Conformal_West_Orientated",	// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",									// WKT OCR
	                       "",										// WKT GeoTiff
	                       "",										// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "Transverse_Mercator_Zoned_Grid_System",	// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{ cs_PRJCOD_NOTYET,    0,"",									// WKT OCR
	                       "",										// WKT GeoTiff
	                       "",										// WKT ESRI (std frm)
	                       "",										// WKT Oracle
	                       "Lambert_Conic_Near-Conformal",			// WKT Geo Tools
	                       "",										// EPSG Name
	                       "",										// Application Alternate
	                       ""},										// Local alternate
	{   cs_PRJCOD_END,   0,"",
	                       "",
	                       "",
	                       "",										// WKT Oracle
	                       "",										// WKT Geo Tools
	                       "",
	                       "",
	                       ""}
};
/*
	The following functions use the data above to accomplish the name mapping
	function.  Thus, the actual tables above remain "private" to this module.
	All access to the above tables is expected to be accomplished via the
	following functions.
*/
long CSwktPrjName2Code (const char *wktName,enum ErcWktFlavor flavor)
{
	short flag = 0;
	long rtnValue = 0L;
	struct csWktPrjNameMap_ *tblPtr;
	
	for (tblPtr = csWktPrjNameMap;tblPtr->CsMapCode != 0;tblPtr += 1)
	{
		switch (flavor) {
		case wktFlvrOgc:
			flag = !CS_stricmp (tblPtr->WktOgcName,wktName);
			break;
		case wktFlvrGeoTiff:
			flag = !CS_stricmp (tblPtr->WktGeoTiffName,wktName);
			break;
		case wktFlvrEsri:
			flag = !CS_stricmp (tblPtr->WktEsriName,wktName);
			break;
		case wktFlvrOracle:
			flag = !CS_stricmp (tblPtr->WktOracleName,wktName);
			break;
		case wktFlvrGeoTools:
			flag = !CS_stricmp (tblPtr->WktGeoToolsName,wktName);
			break;
		case wktFlvrEpsg:
			flag = !CS_stricmp (tblPtr->EpsgName,wktName);
			break;
		case wktFlvrAppAlt:
			flag = !CS_stricmp (tblPtr->AppAltName,wktName);
			break;
		case wktFlvrLclAlt:
			flag = !CS_stricmp (tblPtr->LclAltName,wktName);
			break;
		case wktFlvrUnknown:
			flag = !CS_stricmp (tblPtr->LclAltName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->AppAltName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktOgcName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktEsriName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktGeoTiffName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktGeoToolsName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->EpsgName,wktName);
			break;
		case wktFlvrNone:
		default:
			rtnValue = -1;
			break;
		}
		if (flag)
		{
			rtnValue = tblPtr->CsMapCode;
			break;
		}
	}
	return rtnValue;
}
long CSwktPrjName2Epsg (const char *wktName,enum ErcWktFlavor flavor)
{
	short flag = 0;
	long rtnValue = 0L;
	struct csWktPrjNameMap_ *tblPtr;
	
	for (tblPtr = csWktPrjNameMap;tblPtr->CsMapCode != 0;tblPtr += 1)
	{
		switch (flavor) {
		case wktFlvrOgc:
			flag = !CS_stricmp (tblPtr->WktOgcName,wktName);
			break;
		case wktFlvrGeoTiff:
			flag = !CS_stricmp (tblPtr->WktGeoTiffName,wktName);
			break;
		case wktFlvrEsri:
			flag = !CS_stricmp (tblPtr->WktEsriName,wktName);
			break;
		case wktFlvrOracle:
			flag = !CS_stricmp (tblPtr->WktOracleName,wktName);
			break;
		case wktFlvrGeoTools:
			flag = !CS_stricmp (tblPtr->WktGeoToolsName,wktName);
			break;
		case wktFlvrEpsg:
			flag = !CS_stricmp (tblPtr->EpsgName,wktName);
			break;
		case wktFlvrAppAlt:
			flag = !CS_stricmp (tblPtr->AppAltName,wktName);
			break;
		case wktFlvrLclAlt:
			flag = !CS_stricmp (tblPtr->LclAltName,wktName);
			break;
		case wktFlvrUnknown:
			flag = !CS_stricmp (tblPtr->LclAltName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->AppAltName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktOgcName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktEsriName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktOracleName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktGeoToolsName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktGeoTiffName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->EpsgName,wktName);
			break;
		case wktFlvrNone:
		default:
			rtnValue = -1;
			break;
		}
		if (flag)
		{
			rtnValue = tblPtr->EpsgNbr;
			break;
		}
	}
	return rtnValue;
}
const char* CSwktPrjCode2Name (long csCode,enum ErcWktFlavor flavor)
{
	const char *rtnValue;
	struct csWktPrjNameMap_ *tblPtr;

	for (tblPtr = csWktPrjNameMap;tblPtr->CsMapCode != 0;tblPtr += 1)
	{
		if (tblPtr->CsMapCode == csCode) break;
	}
	if (tblPtr->CsMapCode != 0)
	{
		switch (flavor) {
		case wktFlvrOgc:
			rtnValue = tblPtr->WktOgcName;
			break;
		case wktFlvrGeoTiff:
			rtnValue = tblPtr->WktGeoTiffName;
			break;
		case wktFlvrEsri:
			rtnValue = tblPtr->WktEsriName;
			break;
		case wktFlvrOracle:
			rtnValue = tblPtr->WktOracleName;
			break;
		case wktFlvrGeoTools:
			rtnValue = tblPtr->WktGeoToolsName;
			break;
		case wktFlvrEpsg:
			rtnValue = tblPtr->EpsgName;
			break;
		case wktFlvrAppAlt:
			rtnValue = tblPtr->AppAltName;
			break;
		case wktFlvrLclAlt:
			rtnValue = tblPtr->LclAltName;
			break;
		case wktFlvrUnknown:
			rtnValue = tblPtr->EpsgName;
			break;
		case wktFlvrNone:
		default:
			rtnValue = 0;
			break;
		}
	}
	else
	{
		/* Could use any null string here. */
		rtnValue = tblPtr->WktOgcName;
	}
	return rtnValue;
}
const char* CSwktPrjEpsg2Name (long epsgCode,enum ErcWktFlavor flavor)
{
	const char *rtnValue;
	struct csWktPrjNameMap_ *tblPtr;

	for (tblPtr = csWktPrjNameMap;tblPtr->CsMapCode != 0;tblPtr += 1)
	{
		if (tblPtr->CsMapCode == epsgCode) break;
	}
	if (tblPtr->CsMapCode != 0)
	{
		switch (flavor) {
		case wktFlvrOgc:
			rtnValue = tblPtr->WktOgcName;
			break;
		case wktFlvrGeoTiff:
			rtnValue = tblPtr->WktGeoTiffName;
			break;
		case wktFlvrEsri:
			rtnValue = tblPtr->WktEsriName;
			break;
		case wktFlvrOracle:
			rtnValue = tblPtr->WktOracleName;
			break;
		case wktFlvrGeoTools:
			rtnValue = tblPtr->WktGeoToolsName;
			break;
		case wktFlvrEpsg:
			rtnValue = tblPtr->EpsgName;
			break;
		case wktFlvrAppAlt:
			rtnValue = tblPtr->AppAltName;
			break;
		case wktFlvrLclAlt:
			rtnValue = tblPtr->LclAltName;
			break;
		case wktFlvrUnknown:
			rtnValue = tblPtr->EpsgName;
			break;
		case wktFlvrNone:
		default:
			rtnValue = 0;
			break;
		}
	}
	else
	{
		/* Could use any null string here. */
		rtnValue = tblPtr->WktOgcName;
	}
	return rtnValue;
}
int CSwktPrjSetName (long csmapCode,const char *newName,enum ErcWktFlavor flavor)
{
	int rtnValue = -1;
	struct csWktPrjNameMap_ *tblPtr;

	for (tblPtr = csWktPrjNameMap;tblPtr->CsMapCode != 0;tblPtr += 1)
	{
		if (tblPtr->CsMapCode == csmapCode) break;
	}
	if (tblPtr->CsMapCode != 0)
	{
		rtnValue = 0;
		switch (flavor) {
		case wktFlvrOgc:
			CS_stncp (tblPtr->WktOgcName,newName,sizeof (tblPtr->WktOgcName));
			break;
		case wktFlvrGeoTiff:
			CS_stncp (tblPtr->WktGeoTiffName,newName,sizeof (tblPtr->WktGeoTiffName));
			break;
		case wktFlvrEsri:
			CS_stncp (tblPtr->WktEsriName,newName,sizeof (tblPtr->WktEsriName));
			break;
		case wktFlvrOracle:
			CS_stncp (tblPtr->WktOracleName,newName,sizeof (tblPtr->WktOracleName));
			break;
		case wktFlvrGeoTools:
			CS_stncp (tblPtr->WktGeoToolsName,newName,sizeof (tblPtr->WktGeoToolsName));
			break;
		case wktFlvrEpsg:
			CS_stncp (tblPtr->EpsgName,newName,sizeof (tblPtr->EpsgName));
			break;
		case wktFlvrAppAlt:
			CS_stncp (tblPtr->AppAltName,newName,sizeof (tblPtr->AppAltName));
			break;
		case wktFlvrLclAlt:
			CS_stncp (tblPtr->LclAltName,newName,sizeof (tblPtr->LclAltName));
			break;
		case wktFlvrUnknown:
			CS_stncp (tblPtr->EpsgName,newName,sizeof (tblPtr->EpsgName));
			break;
		case wktFlvrNone:
		default:
			rtnValue = -1;
			break;
		}
	}
	return rtnValue;
}
/*newPage*/
/*
	The following does the same for projection (and transformation) parameters
	as the above does for projections.  I.e. map several flavors of names
	back and forth between Names and Codes.
*/
struct csWktPrmNameMap_
{
	enum EcsWktParameter PrmCode;
	unsigned short MsiParmCode;
	unsigned short EpsgNbr;
	char WktOgcName [48];
	char WktGeoTiffName [48];
	char WktEsriName [48];
	char WktOracleName [48];
	char WktGeoToolsName [48];
	char EpsgName   [64];
	char AppAltName [64];
	/*
		In future, we expect to support a "local" flavor of WKT.  This element
		will contain the Local Alternate Name, which will be supplied via the
		system's XML configuration file. */
	char LclAltName [64];
};
/******************************************************************************
	The following table maps a WKT parameter name with an enumeration value.
	Where appropriate, equivalent cs_PRMCOD_????? values are given as well as
	EPSG numeric code values.  Note, that:

	1> cs_PRMCOD_????? is actually an index into the cs_Prjprm table defined
	   above. 
	2> This table includes datum parameter codes as these values appear as
	   elements of the Parameter type in WKT.
	3> The above enumeration classifies several parameters as being Cartesian
	   transformation parameters as that uis what they will be in the soon to
	   be release RefCon Engine product.
	4> Several names are given, and the actual names used depend upon the
	   specific flavor of WKT being processed.  CS-MAP prefers the OGC flavor
	   of WKT believing it to be the most standardized of the various flavors,
	   although the ESRI flavor may be the most ubiquitous.

	Some of the names here are guesses as I can't find official documentation
	for all of these.  Help me out if and when you can (888-ASK-NORM).
*/
struct csWktPrmNameMap_ csWktPrmNameMap [] =
{
	{ csWktPrmXTranslation,   cs_WKTCOD_DELTAX,8605,"X_Axis_Translation",	// WKT OCR
													"X_Axis_Translation",	// WKT GeoTiff
													"X_Axis_Translation",	// WKT ESRI (std frm?)
													"X Axis Translation",	// WKT Oracle
													"",						// WKT Geo Tools
													"X-axis translation",	// EPGS Name
													"",						// Application ALternate Name
													"" },					// Local Alternate Name
	{ csWktPrmYTranslation,   cs_WKTCOD_DELTAY,8606,"Y_Axis_Translation",
													"Y_Axis_Translation",
													"Y_Axis_Translation",
													"Y Axis Translation",	// WKT Oracle
													"",						// WKT Geo Tools
													"Y-axis translation",
													"",
													""},
	{ csWktPrmZTranslation,   cs_WKTCOD_DELTAZ,8607,"Z_Axis_Translation",
													"Z_Axis_Translation",
													"Z_Axis_Translation",
													"Z Axis Translation",	// WKT Oracle
													"",						// WKT Geo Tools
													"Z-axis translation",
													"",
													""},
	{ csWktPrmXRotation,      cs_WKTCOD_ROTATX,8608,"X_Axis_Rotation",
													"X_Axis_Rotation",
													"X_Axis_Rotation",
													"X Axis Rotation",		// WKT Oracle
													"",						// WKT Geo Tools
													"X-axis rotation",
													"",
													""},
	{ csWktPrmYRotation,      cs_WKTCOD_ROTATY,8609,"Y_Axis_Rotation",
													"Y_Axis_Rotation",
													"Y_Axis_Rotation",
													"Y Axis Rotation",		// WKT Oracle
													"",						// WKT Geo Tools
													"Y-axis rotation",
													"",
													""},
	{ csWktPrmZRotation,      cs_WKTCOD_ROTATZ,8610,"Z_Axis_Rotation",
													"Z_Axis_Rotation",
													"Z_Axis_Rotation",
													"Z Axis Rotation",		// WKT Oracle
													"",						// WKT Geo Tools
													"Z-axis rotation",
													"",
													""},
	{ csWktPrmDatumScale,     cs_WKTCOD_BWSCAL,8611,"Datum_Scale",
													"Datum_Sale",
													"Scale_Difference",
													"Scale Difference",		// WKT Oracle
													"",						// WKT Geo Tools
													"Scale difference",
													"",
													""},
	{csWktPrmLatitudeOfOrg,   cs_WKTCOD_ORGLAT,8801,"latitude_of_origin",
													"NatOriginLat",
													"Latitude_Of_Origin",
													"Latitude_Of_Origin",	// WKT Oracle
													"latitude_of_origin",	// WKT Geo Tools
													"Latitude of natural origin",
													"",
													""},
	{csWktPrmLongitudeOfOrg,  cs_PRMCOD_CNTMER,8802,"central_meridian",
													"NatOriginLong",
													"Central_Meridian",
													"Central_Meridian",		// WKT Oracle
													"central_meridian",		// WKT Geo Tools
													"Longitude of natural origin",
													"",
													""},
	/* ESRI uses Central_Meridian for all projections, except the New Zealnd Map Grid.  For
	   that one projection it uses Longitude_of_Origin".  Strange, and painful, but true. */
	{csWktPrmLongitudeOfOrg,  cs_PRMCOD_CNTMER,8802,"",
													"",
													"Longitude_of_Origin",	// WKT ESRI
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""},
	{csWktPrmLongitudeOfOrg,  cs_PRMCOD_CNTMER,8802,"",
													"",
													"Longitude_Of_Origin",		// ESRI uses this for 1 projection: New Zealand Map Grid
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""},
	{csWktPrmScaleAtOrigin,   cs_WKTCOD_SCLRED,8805,"scale_factor",
													"ScaleAtNatOrigin",
													"Scale_Factor",
													"Scale_Factor",			// WKT Oracle
													"scale_factor",			// WKT Geo Tools
													"Scale factor at natural origin",
													"",
													""},
	{csWktPrmFalseEasting,     cs_WKTCOD_FEAST,8806,"false_easting",
													"FalseEasting",
													"False_Easting",
													"False_Easting",		// WKT Oracle
													"false_easting",		// WKT Geo Tools
													"False easting",
													"",
													""},
	{csWktPrmFalseNorthing,   cs_WKTCOD_FNORTH,8807,"false_northing",
													"FalseNorthing",
													"False_Northing",
													"False_Northing",		// WKT Oracle
													"false_northing",		// WKT Geo Tools
													"False northing",
													"",
													""},
	{csWktPrmLatitudeOfCtr,   cs_PRMCOD_GCPLAT,8811,"latitude_of_center",
													"CenterLat",
													"Latitude_Of_Center",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Latitude of projection centre",
													"",
													""},
	{csWktPrmLongitudeOfCtr,  cs_PRMCOD_GCPLNG,8812,"longitude_of_center",
													"CenterLong",
													"Longitude_Of_Center",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Longitude of projection centre",
													"",
													""},
	{      csWktPrmAzimuth,    cs_PRMCOD_GCAZM,8813,"azimuth",
													"AzimuthAngle",
													"Azimuth",
													"Azimuth",				// WKT Oracle
													"",						// WKT Geo Tools
													"Azimuth of initial line",
													"",
													""},
	{csWktPrmRectifiedGrdAng, cs_PRMCOD_SKWAZM,8814,"rectified_grid_angle",
													"RectifiedGridAngle",
													"Rectified_Grid_Angle",		/*??*/
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Angle from Rectified to Skew Grid",
													"",
													""},
	{ csWktPrmScaleAtCenter,  cs_WKTCOD_SCLRED,8815,"scale_factor",
													"ScaleAtCenter",
													"Scale_Factor",
													"",						// WKT Oracle
													"scale_factor",			// WKT Geo Tools
													"Scale factor on initial line",
													"",
													""},
	{csWktPrmEastingOfCtr,     cs_WKTCOD_FEAST,8816,"false_easting",
													"FalseEasting",
													"False_Easting",
													"",						// WKT Oracle
													"false_easting",		// WKT Geo Tools
													"Easting at projection center",
													"",
													""},
	{csWktPrmNorthingOfCtr,   cs_WKTCOD_FNORTH,8817,"false_northing",
													"FalseNorthing",
													"False_Northing",
													"",						// WKT Oracle
													"false_northing",		// WKT Geo Tools
													"Northing at projection center",
													"",
													""},
	{csWktPrmPsdoParallelLat,cs_PRMCOD_OSTDPLL,8818,"pseudo_standard_parallel_1",
													"",
													"Pseudo_Standard_Parallel_1",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Latitude of pseudo standard parallel",
													"",
													""},
	{csWktPrmPsdoParallelScl, cs_PRMCOD_NOTYET,8819,"scale_factor",
													"ScaleAtCenter",
													"Scale_Factor",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Scale factor on pseudo standard parallel",
													"",
													""},
	{csWktPrmLatOfFalseOrg,   cs_WKTCOD_ORGLAT,8821,"latitude_of_origin",
													"FalseOriginLat",
													"Latitude_Of_Origin",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Latitude of false origin",
													"",
													""},
	{csWktPrmLngOfFalseOrg,   cs_WKTCOD_ORGLNG,8822,"central_meridian",
													"FalseOriginLong",
													"Central_Meridian",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Longitude of false origin",
													"",
													""},
	{csWktPrmStdParallel1,   cs_PRMCOD_NSTDPLL,8823,"standard_parallel_1",
													"StdParallel1",
													"Standard_Parallel_1",
													"Standard_Parallel_1",	// WKT Oracle
													"standard_parallel1",	// WKT Geo Tools
													"Longitude of 1st standard parallel",
													"",
													""},
	{csWktPrmStdParallel2,  cs_PRMCOD_SSTDPLL,8824,"standard_parallel_2",
													"StdParallel2",
													"Standard_Parallel_2",
													"Standard_Parallel_2",	// WKT Oracle
													"standard_parallel2",	// WKT Geo Tools
													"Longitude of 2nd standard parallel",
													"",
													""},
	{csWktPrmEastingFalseOrg, cs_WKTCOD_FEAST,8826,"false_easting",
													"FalseOriginEasting",
													"False_Easting",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Easting of false origin",
													"",
													""},
	{csWktPrmNorthingFalseOrg,cs_WKTCOD_FNORTH,8827,"false_northing",
													"FalseOriginNorthing",
													"False_Northing",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Northing of false origin",
													"",
													""},
	{  csWktPrmLatOfStdParall,cs_PRMCOD_STDCIR,8832,"",
													"",
													"",
													"",						// WKT Oracle
													"latitude_true_scale",	// WKT Geo Tools
													"Latitude of Standard Parallel",
													"",
													""},
	/* We use the cs_PRMCOD_NOTYET to indicate a parameter which is not
	   used by any CS-MAP projection, but will likely have at least an
	   equivalent parameter in the future.  Notice, that WKT does not support
	   any of the EPSG projections which require these parameters either. */
	{csWktPrmSemiMajor,          cs_PRMCOD_NOTYET,0,"",
													"",
													"",						// WKT ESRI
													"",						// WKT Oracle
													"semi_major",			// WKT Geo Tools
													"",
													"",
													""},
	{csWktPrmSemiMinor,          cs_PRMCOD_NOTYET,0,"",
													"",
													"",						// WKT ESRI
													"",						// WKT Oracle
													"semi_minor",			// WKT Geo Tools
													"",
													"",
													""},
	{csWktPrmXScale,             cs_PRMCOD_NOTYET,0,"",
													"",
													"X_Scale",				// WKT ESRI
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""},
	{csWktPrmYScale,             cs_PRMCOD_NOTYET,0,"",
													"",
													"Y_Scale",				// WKT ESRI
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""},
	{csWktPrmXYRotation,         cs_PRMCOD_NOTYET,0,"",
													"",
													"XY_Plane_Rotation",	// WKT ESRI
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""},
	{csWktPrmPseudoStdParall1,   cs_PRMCOD_NOTYET,0,"",
													"",
													"Pseudo_Standard_Parallel_1",	// WKT ESRI
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""},
	{csWktPrmPseudoStdParall2,   cs_PRMCOD_NOTYET,0,"",
													"",
													"Pseudo_Standard_Parallel_2",	// WKT ESRI
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""},
	{csWktPrmOption,             cs_PRMCOD_NOTYET,0,"",
													"",
													"Option",				// WKT ESRI
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""},
	{csWktPrmHeight,             cs_PRMCOD_NOTYET,0,"",
													"",
													"Height",				// WKT ESRI
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""},
	{csWktPrmCentralParallel,    cs_PRMCOD_NOTYET,0,"",
													"",
													"Central_Parallel",		// WKT ESRI
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""},
	{csWktPrmSphericalOrgLat, cs_PRMCOD_NOTYET,8828,"",
													"",
													"",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Spherical latitude of origin",
													"",
													""},
	{csWktPrmSphericalOrgLng, cs_PRMCOD_NOTYET,8829,"",
													"",
													"",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Spherical longitude of origin",
													"",
													""},
	{csWktPrmSystemWestLimit, cs_PRMCOD_NOTYET,8830,"",
													"",
													"",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Initial longitude",
													"",
													""},
	{csWktPrmSystemZoneWidth, cs_PRMCOD_NOTYET,8831,"",
													"NatOriginLong",
													"",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"Zone width",
													"",
													""},
	/* The following are parameters which appear to be supported by WKT but not
	   by EPSG.  Therefore, the names are (in many cases) guesses and there are
	   no EPSG names or codes. */
	{csWktPrmLatFirstPoint,   cs_PRMCOD_P1LAT,8802,"latitude_of_1st_point",
													"",
													"Latitude_Of_1st_Point",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""},
	{csWktPrmLngFirstPoint,    cs_PRMCOD_P1LNG,   0,"longitude_of_1st_point",
													"",
													"Longitude_Of_1st_Point",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""},
	{csWktPrmLatSecondPoint,   cs_PRMCOD_P2LAT,   0,"latitude_of_2nd_point",
													"",
													"Latitude_Of_2nd_Point",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""},
	{csWktPrmLngSecondPoint,  cs_PRMCOD_P2LNG,8802,"longitude_of_2nd_point",
													"",
													"Longitude_Of_2nd_Point",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""},
	/* The Y Axis Azimuth parameter is a parameter MSI has added to its 
	   implementation of the Lambert Equidistant Azimuthal and the Lambert
	   Equal Area Azimuthal.  Neither EPSG or WKT support it. */
	{csWktPrmYaxisAzimuth,   cs_PRMCOD_YAXISAZ,   0,"",
													"",
													"",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""},
	/* The following entry terminates the table. */
	{    csWktPrmUnknown,    cs_PRMCOD_NOTUSED,   0,"",
													"",
													"",
													"",						// WKT Oracle
													"",						// WKT Geo Tools
													"",
													"",
													""}
};
/*
	The following functions use the data above to accomplish the name mapping
	function.  Thus, the actual tables above remain "private" to this module.
	All access to the above tables is expected to be accomplished via the
	following functions.
*/
long CSwktPrmName2Code (const char *wktName,enum ErcWktFlavor flavor)
{
	short flag = 0;
	long rtnValue = 0L;
	struct csWktPrmNameMap_ *tblPtr;
	
	for (tblPtr = csWktPrmNameMap;tblPtr->PrmCode != csWktPrmUnknown;tblPtr += 1)
	{
		switch (flavor) {
		case wktFlvrOgc:
			flag = !CS_stricmp (tblPtr->WktOgcName,wktName);
			break;
		case wktFlvrGeoTiff:
			flag = !CS_stricmp (tblPtr->WktGeoTiffName,wktName);
			break;
		case wktFlvrEsri:
			flag = !CS_stricmp (tblPtr->WktEsriName,wktName);
			break;
		case wktFlvrOracle:
			flag = !CS_stricmp (tblPtr->WktOracleName,wktName);
			break;
		case wktFlvrGeoTools:
			flag = !CS_stricmp (tblPtr->WktGeoToolsName,wktName);
			break;
		case wktFlvrEpsg:
			flag = !CS_stricmp (tblPtr->EpsgName,wktName);
			break;
		case wktFlvrAppAlt:
			flag = !CS_stricmp (tblPtr->AppAltName,wktName);
			break;
		case wktFlvrLclAlt:
			flag = !CS_stricmp (tblPtr->LclAltName,wktName);
			break;
		case wktFlvrUnknown:
			flag = !CS_stricmp (tblPtr->LclAltName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->AppAltName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktOgcName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktEsriName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktOracleName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktGeoToolsName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktGeoTiffName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->EpsgName,wktName);
			break;
		case wktFlvrNone:
		default:
			rtnValue = -1;
			break;
		}
		if (flag)
		{
			rtnValue = tblPtr->MsiParmCode;
			break;
		}
	}
	return rtnValue;
}
long CSwktPrmName2Epsg (const char *wktName,enum ErcWktFlavor flavor)
{
	short flag = 0;
	long rtnValue = 0L;
	struct csWktPrmNameMap_ *tblPtr;
	
	for (tblPtr = csWktPrmNameMap;tblPtr->PrmCode != csWktPrmUnknown;tblPtr += 1)
	{
		switch (flavor) {
		case wktFlvrOgc:
			flag = !CS_stricmp (tblPtr->WktOgcName,wktName);
			break;
		case wktFlvrGeoTiff:
			flag = !CS_stricmp (tblPtr->WktGeoTiffName,wktName);
			break;
		case wktFlvrEsri:
			flag = !CS_stricmp (tblPtr->WktEsriName,wktName);
			break;
		case wktFlvrOracle:
			flag = !CS_stricmp (tblPtr->WktOracleName,wktName);
			break;
		case wktFlvrGeoTools:
			flag = !CS_stricmp (tblPtr->WktGeoToolsName,wktName);
			break;
		case wktFlvrEpsg:
			flag = !CS_stricmp (tblPtr->EpsgName,wktName);
			break;
		case wktFlvrAppAlt:
			flag = !CS_stricmp (tblPtr->AppAltName,wktName);
			break;
		case wktFlvrLclAlt:
			flag = !CS_stricmp (tblPtr->LclAltName,wktName);
			break;
		case wktFlvrUnknown:
			flag = !CS_stricmp (tblPtr->LclAltName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->AppAltName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktOgcName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktEsriName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktOracleName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktGeoToolsName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktGeoTiffName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->EpsgName,wktName);
			break;
		case wktFlvrNone:
		default:
			rtnValue = -1;
			break;
		}
		if (flag)
		{
			rtnValue = tblPtr->EpsgNbr;
			break;
		}
	}
	return rtnValue;
}
const char* CSwktPrmEnum2Name (enum EcsWktParameter enumCode,enum ErcWktFlavor flavor)
{
	const char *rtnValue;
	struct csWktPrmNameMap_ *tblPtr;

	for (tblPtr = csWktPrmNameMap;tblPtr->PrmCode != csWktPrmUnknown;tblPtr += 1)
	{
		if (tblPtr->PrmCode == enumCode) break;
	}
	if (tblPtr->PrmCode != csWktPrmUnknown)
	{
		switch (flavor) {
		case wktFlvrOgc:
			rtnValue = tblPtr->WktOgcName;
			break;
		case wktFlvrGeoTiff:
			rtnValue = tblPtr->WktGeoTiffName;
			break;
		case wktFlvrEsri:
			rtnValue = tblPtr->WktEsriName;
			break;
		case wktFlvrOracle:
			rtnValue = tblPtr->WktOracleName;
			break;
		case wktFlvrGeoTools:
			rtnValue = tblPtr->WktGeoToolsName;
			break;
		case wktFlvrEpsg:
			rtnValue = tblPtr->EpsgName;
			break;
		case wktFlvrAppAlt:
			rtnValue = tblPtr->AppAltName;
			break;
		case wktFlvrLclAlt:
			rtnValue = tblPtr->LclAltName;
			break;
		case wktFlvrUnknown:
			rtnValue = tblPtr->EpsgName;
			break;
		case wktFlvrNone:
		default:
			rtnValue = 0;
			break;
		}
	}
	else
	{
		/* Could use any null string here. */
		rtnValue = tblPtr->WktOgcName;
	}
	return rtnValue;
}
const char* CSwktPrmCode2Name (long csCode,enum ErcWktFlavor flavor)
{
	const char *rtnValue;
	struct csWktPrmNameMap_ *tblPtr;

	for (tblPtr = csWktPrmNameMap;tblPtr->PrmCode != csWktPrmUnknown;tblPtr += 1)
	{
		if (tblPtr->MsiParmCode == csCode) break;
	}
	if (tblPtr->PrmCode != csWktPrmUnknown)
	{
		switch (flavor) {
		case wktFlvrOgc:
			rtnValue = tblPtr->WktOgcName;
			break;
		case wktFlvrGeoTiff:
			rtnValue = tblPtr->WktGeoTiffName;
			break;
		case wktFlvrEsri:
			rtnValue = tblPtr->WktEsriName;
			break;
		case wktFlvrOracle:
			rtnValue = tblPtr->WktOracleName;
			break;
		case wktFlvrGeoTools:
			rtnValue = tblPtr->WktGeoToolsName;
			break;
		case wktFlvrEpsg:
			rtnValue = tblPtr->EpsgName;
			break;
		case wktFlvrAppAlt:
			rtnValue = tblPtr->AppAltName;
			break;
		case wktFlvrLclAlt:
			rtnValue = tblPtr->LclAltName;
			break;
		case wktFlvrUnknown:
			rtnValue = tblPtr->EpsgName;
			break;
		case wktFlvrNone:
		default:
			rtnValue = 0;
			break;
		}
	}
	else
	{
		/* Could use any null string here. */
		rtnValue = tblPtr->WktOgcName;
	}
	return rtnValue;
}
const char* CSwktPrmEpsg2Name (long epsgCode,enum ErcWktFlavor flavor)
{
	const char *rtnValue;
	struct csWktPrmNameMap_ *tblPtr;

	for (tblPtr = csWktPrmNameMap;tblPtr->PrmCode != csWktPrmUnknown;tblPtr += 1)
	{
		if (tblPtr->EpsgNbr == epsgCode) break;
	}
	if (tblPtr->PrmCode != csWktPrmUnknown)
	{
		switch (flavor) {
		case wktFlvrOgc:
			rtnValue = tblPtr->WktOgcName;
			break;
		case wktFlvrGeoTiff:
			rtnValue = tblPtr->WktGeoTiffName;
			break;
		case wktFlvrEsri:
			rtnValue = tblPtr->WktEsriName;
			break;
		case wktFlvrOracle:
			rtnValue = tblPtr->WktOracleName;
			break;
		case wktFlvrGeoTools:
			rtnValue = tblPtr->WktGeoToolsName;
			break;
		case wktFlvrEpsg:
			rtnValue = tblPtr->EpsgName;
			break;
		case wktFlvrAppAlt:
			rtnValue = tblPtr->AppAltName;
			break;
		case wktFlvrLclAlt:
			rtnValue = tblPtr->LclAltName;
			break;
		case wktFlvrUnknown:
			rtnValue = tblPtr->EpsgName;
			break;
		case wktFlvrNone:
		default:
			rtnValue = 0;
			break;
		}
	}
	else
	{
		/* Could use any null string here. */
		rtnValue = tblPtr->WktOgcName;
	}
	return rtnValue;
}
int CSwktPrmSetName (enum EcsWktParameter selCode,const char *newName,enum ErcWktFlavor flavor)
{
	int rtnValue = -1;
	struct csWktPrmNameMap_ *tblPtr;

	for (tblPtr = csWktPrmNameMap;tblPtr->PrmCode != csWktPrmUnknown;tblPtr += 1)
	{
		if (tblPtr->PrmCode == selCode) break;
	}
	if (tblPtr->PrmCode != csWktPrmUnknown)
	{
		rtnValue = 0;
		switch (flavor) {
		case wktFlvrOgc:
			CS_stncp (tblPtr->WktOgcName,newName,sizeof (tblPtr->WktOgcName));
			break;
		case wktFlvrGeoTiff:
			CS_stncp (tblPtr->WktGeoTiffName,newName,sizeof (tblPtr->WktGeoTiffName));
			break;
		case wktFlvrEsri:
			CS_stncp (tblPtr->WktEsriName,newName,sizeof (tblPtr->WktEsriName));
			break;
		case wktFlvrOracle:
			CS_stncp (tblPtr->WktOracleName,newName,sizeof (tblPtr->WktOracleName));
			break;
		case wktFlvrGeoTools:
			CS_stncp (tblPtr->WktGeoToolsName,newName,sizeof (tblPtr->WktGeoToolsName));
			break;
		case wktFlvrEpsg:
			CS_stncp (tblPtr->EpsgName,newName,sizeof (tblPtr->EpsgName));
			break;
		case wktFlvrAppAlt:
			CS_stncp (tblPtr->AppAltName,newName,sizeof (tblPtr->AppAltName));
			break;
		case wktFlvrLclAlt:
			CS_stncp (tblPtr->LclAltName,newName,sizeof (tblPtr->LclAltName));
			break;
		case wktFlvrUnknown:
			CS_stncp (tblPtr->EpsgName,newName,sizeof (tblPtr->EpsgName));
			break;
		case wktFlvrNone:
		default:
			rtnValue = -1;
			break;
		}
	}
	return rtnValue;
}
//newPage//
/*
	The following does the same for projection (and transformation) parameters
	as the above does for projections.  I.e. map several flavors of names
	back and forth between Names and Codes.
*/
/******************************************************************************
	TrcWktUnitNameMap  --  Form of Units Name Mapping Table

	An array of the following struture is used to map WKT unit names to a
	CS-MAP unit name and vice versa.  I don't know that there are different
	names for the different flavors, but I'm going to assume so.
	
	We're just mapping names here, so we care not about unit types.
*/
struct csWktUnitNameMap_
{
	char MsiName [16];					/* MSI unit name. */
	unsigned short EpsgNbr;				/* EPSG "Unit of Measure" code number */
	char EpsgName [32];					/* EPSG name as of v6.2 */
	char WktOgcName [32];				/* WKT OGC name, this may be the best choice */
	char WktGeoTiffName [32];			/* WKT GeoTiff name */ 
	char WktEsriName [32];				/* WKT ESRI name */
	char WktOracleName [32];			/* WKT Oracle name */
	char WktGeoToolsName [32];			/* WKT Geo Tools name */
	char AppAltName [32];
	char LclAltName [32];
};
/******************************************************************************
	The MSI <-->  WKT unit mapping table.  There are a ton more units, but I
	only have reliable information about the WKT names assigned to a very few.
	So, for now, we do these very few and add others as information becomes
	available.  We assume the names will vary with the various flavors. */
struct csWktUnitNameMap_ csWktUnitNameMap [] =
{
	{      "Meter", 9001, "metre",                  "Meter",
													"Meter",
													"Meter",
													"Meter",		// WKT Oracle
													"metre",		// WKT Geo Tools
													"",
													""},
	{  "Kilometer", 9036, "kilometre",              "Kilometer",
													"Kilometer",
													"Kilometer",
													"Kilometer",	// WKT Oracle
													"kilometre",	// WKT Geo Tools
													"",
													""},
	{      "IFoot", 9002, "foot",                   "Foot_Intnl",
													"Foot_Intnl",
													"Foot",
													"Foot (International)",	// WKT Oracle
													"3.048 dm",				// WKT Geo Tools
													"",
													""},
	{       "Foot", 9003, "US survey foot",         "Foot_US",
													"Foot_US",
													"Foot_US",
													"U.S. Foot",		// WKT Oracle
													"3.048 dm",			// WKT Geo Tools
													"",
													""},
	{       "Mile", 9035, "US survey mile",         "Mile_US",
													"Mile_US",
													"Mile_US",
													"",					// WKT Oracle
													"",					// WKT Geo Tools
													"",
													""},
	{      "IMile", 9093,   "Statute Mile",         "",
													"",
													"",
													"Mile",				// WKT Oracle
													"",					// WKT Geo Tools
													"",
													""},
	{      "IYard", 9096,           "yard",         "",
													"",
													"yard",
													"Yard",				// WKT Oracle
													"",					// WKT Geo Tools
													"",
													""},
	{ "IntnlChain",9097,           "chain",         "",
													"",
													"chain",
													"Chain",			// WKT Oracle
													"",
													""},
	{  "IntnlLink",9098,            "link",         "",
													"",
													"link",
													"Link",				// WKT Oracle
													"",
													""},
	{ "ClarkeFoot", 9005, "Clarke's foot",          "foot_clarke",
													"Foot_Clarke",
													"Foot_Clarke",
													"",					// WKT Oracle
													"",					// WKT Geo Tools
													"",
													""},
	{ "ClarkeYard", 9037, "Clarke's yard",          "Yard_Clarke",
													"Yard_Clarke",
													"Yard_Clarke",
													"",					// WKT Oracle
													"",					// WKT Geo Tools
													"",
													""},
	{ "SearsYard", 9040, "Sears yard",              "Yard_Sears",
													"Yard_Sears",
													"Yard_Sears",
													"",					// WKT Oracle
													"",					// WKT Geo Tools
													"",
													""},
	{ "IndianYard", 9084, "Indian yard",            "Yard_Indian",
													"Yard_Indian",
													"Yard_Indian",
													"",					// WKT Oracle
													"",					// WKT Geo Tools
													"",
													""},
	{ "ClarkeLink", 9084, "Clarke's link",          "Link_Clarke",
													"Link_Clarke",
													"Link_Clarke",
													"",					// WKT Oracle
													"",					// WKT Geo Tools
													"",
													""},
	{"GoldCoastFoot", 9094, "Gold Coast foot",      "gold_coast_foot",
													"GoldCoastFoot",
													"Foot_Gold_Coast",
													"",					// WKT Oracle
													"3.048 dm",			// WKT Geo Tools
													"",
													""},
	{  "BenoitChain", 9062, "British chain (Benoit 1895 B)",
													"benoit_chain",
													"BenoitChain",
													"Chain_Benoit_1895_B",
													"",					// WKT Oracle
													"2.012 dam",		// WKT Geo Tools
													"",
													""},
	{  "SearsChain", 9042, "British chain (Sears 1922)",
													"",
													"",
													"Chain_Sears",
													"",					// WKT Oracle
													"",					// WKT Geo Tools
													"",
													""},
	{  "SearsFoot", 9041, "British foot (Sears 1922)",
													"",
													"",
													"Foot_Sears",
													"",					// WKT Oracle
													"3.048 dm",			// WKT Geo Tools
													"",
													""},
	{  "IndianYd37", 9085, "Indian yard (1937)",
													"",
													"",
													"Yard_Indian_1937",
													"",					// WKT Oracle
													"",					// WKT Geo Tools
													"",
													""},
	{  "GermanMeter", 9031, "German legal metre",   "german_meter",
													"GermanMeter",
													"German_Meter",
													"",					// WKT Oracle
													"",					// WKT Geo Tools
													"",
													""},
	{     "Radian", 9101, "radian",                 "Radian",
													"Radian",
													"Radian",
													"",					// WKT Oracle
													"",					// WKT Geo Tools
													"",
													""},
	{     "Degree", 9102, "degree",                 "Degree",
													"Degree",
													"Degree",
													"Decimal Degree",	// WKT Oracle
													"degree of angle",	// WKT Geo Tools
													"",
													""},
	{       "Grad", 9105, "grad",                   "Grad",
													"Grad",
													"Grad",
													"",					// WKT Oracle
													"0.016 rad",		// WKT Geo Tools
													"",
													""},
	{      "Grade", 9105, "grad",                   "Grad",
													"Grad",
													"Grad",
													"",					// WKT Oracle
													"",					// WKT Geo Tools
													"",
											 		""},
	{       "Grad", 9106, "gon",                    "Gon",
													"Gon",
													"Gon",
													"",					// WKT Oracle
													"",					// WKT Geo Tools
													"",
													""},
	// The following entries are simply to keep the flavor detector working, we don't
	// really support them.
	{"50kilometers ",    0,    "",                  "",
													"",
													"50_Kilometers",	// WKT ESRI
													"",					// WKT Oracle
													"",					// WKT Geo Tools
													"",
													""},
	{"150Kilometers ",    0,    "",                 "",
													"",
													"150_Kilometers",	// WKT ESRI
													"",					// WKT Oracle
													"",					// WKT Geo Tools
													"",
													""},
	// The following entry terminates the table.
	{           "",    0, "",	                    "",
													"",
													"",
													"",					// WKT Oracle
													"",					// WKT Geo Tools
													"",
													""}
};
const char* CSwktUnitName2MsiName (const char *wktName,enum ErcWktFlavor flavor)
{
	short flag = 0;
	const char *rtnValue = 0;
	struct csWktUnitNameMap_ *tblPtr;
	
	for (tblPtr = csWktUnitNameMap;tblPtr->MsiName [0] != '\0';tblPtr += 1)
	{
		switch (flavor) {
		case wktFlvrOgc:
			flag = !CS_stricmp (tblPtr->WktOgcName,wktName);
			break;
		case wktFlvrGeoTiff:
			flag = !CS_stricmp (tblPtr->WktGeoTiffName,wktName);
			break;
		case wktFlvrEsri:
			flag = !CS_stricmp (tblPtr->WktEsriName,wktName);
			break;
		case wktFlvrOracle:
			flag = !CS_stricmp (tblPtr->WktOracleName,wktName);
			break;
		case wktFlvrGeoTools:
			flag = !CS_stricmp (tblPtr->WktGeoToolsName,wktName);
			break;
		case wktFlvrEpsg:
			flag = !CS_stricmp (tblPtr->EpsgName,wktName);
			break;
		case wktFlvrAppAlt:
			flag = !CS_stricmp (tblPtr->AppAltName,wktName);
			break;
		case wktFlvrLclAlt:
			flag = !CS_stricmp (tblPtr->LclAltName,wktName);
			break;
		case wktFlvrUnknown:
			flag = !CS_stricmp (tblPtr->LclAltName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->AppAltName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktOgcName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktEsriName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktOracleName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktGeoToolsName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktGeoTiffName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->EpsgName,wktName);
			break;
		case wktFlvrNone:
		default:
			rtnValue = 0;
			break;
		}
		if (flag)
		{
			rtnValue = tblPtr->MsiName;
			break;
		}
	}
	return rtnValue;
}
const char* CSmsiUnitName2WktName (const char *msiName,enum ErcWktFlavor flavor)
{
	const char *rtnValue = 0;
	struct csWktUnitNameMap_ *tblPtr;
	
	for (tblPtr = csWktUnitNameMap;tblPtr->MsiName [0] != '\0';tblPtr += 1)
	{
		if (!CS_stricmp (tblPtr->MsiName,msiName)) break;
	}
	if (tblPtr->EpsgNbr != 0)
	{
		switch (flavor) {
		case wktFlvrOgc:
			rtnValue = tblPtr->WktOgcName;
			break;
		case wktFlvrGeoTiff:
			rtnValue = tblPtr->WktGeoTiffName;
			break;
		case wktFlvrEsri:
			rtnValue = tblPtr->WktEsriName;
			break;
		case wktFlvrOracle:
			rtnValue = tblPtr->WktOracleName;
			break;
		case wktFlvrGeoTools:
			rtnValue = tblPtr->WktGeoToolsName;
			break;
		case wktFlvrEpsg:
			rtnValue = tblPtr->EpsgName;
			break;
		case wktFlvrAppAlt:
			rtnValue = tblPtr->AppAltName;
			break;
		case wktFlvrLclAlt:
			rtnValue = tblPtr->LclAltName;
			break;
		case wktFlvrUnknown:
			rtnValue = tblPtr->EpsgName;
			break;
		case wktFlvrNone:
		default:
			rtnValue = 0;
			break;
		}
	}
	return rtnValue;
}
long CSwktUnitName2Epsg (const char *wktName,enum ErcWktFlavor flavor)
{
	short flag = 0;
	long rtnValue = 0L;
	struct csWktUnitNameMap_ *tblPtr;
	
	for (tblPtr = csWktUnitNameMap;tblPtr->MsiName [0] != '\0';tblPtr += 1)
	{
		switch (flavor) {
		case wktFlvrOgc:
			flag = !CS_stricmp (tblPtr->WktOgcName,wktName);
			break;
		case wktFlvrGeoTiff:
			flag = !CS_stricmp (tblPtr->WktGeoTiffName,wktName);
			break;
		case wktFlvrEsri:
			flag = !CS_stricmp (tblPtr->WktEsriName,wktName);
			break;
		case wktFlvrOracle:
			flag = !CS_stricmp (tblPtr->WktOracleName,wktName);
			break;
		case wktFlvrGeoTools:
			flag = !CS_stricmp (tblPtr->WktGeoToolsName,wktName);
			break;
		case wktFlvrEpsg:
			flag = !CS_stricmp (tblPtr->EpsgName,wktName);
			break;
		case wktFlvrAppAlt:
			flag = !CS_stricmp (tblPtr->AppAltName,wktName);
			break;
		case wktFlvrLclAlt:
			flag = !CS_stricmp (tblPtr->LclAltName,wktName);
			break;
		case wktFlvrUnknown:
			flag = !CS_stricmp (tblPtr->LclAltName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->AppAltName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktOgcName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktEsriName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktOracleName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktGeoToolsName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->WktGeoTiffName,wktName);
			if (!flag) flag = !CS_stricmp (tblPtr->EpsgName,wktName);
			break;
		case wktFlvrNone:
		default:
			rtnValue = -1;
			break;
		}
		if (flag)
		{
			rtnValue = tblPtr->EpsgNbr;
			break;
		}
	}
	return rtnValue;
}
const char* CSepsgUnitNbr2Name (long epsgNbr,enum ErcWktFlavor flavor)
{
	const char *rtnValue = 0;
	struct csWktUnitNameMap_ *tblPtr;

	for (tblPtr = csWktUnitNameMap;tblPtr->MsiName [0] != '\0';tblPtr += 1)
	{
		if (tblPtr->EpsgNbr == epsgNbr) break;
	}
	if (tblPtr->EpsgNbr != 0)
	{
		switch (flavor) {
		case wktFlvrOgc:
			rtnValue = tblPtr->WktOgcName;
			break;
		case wktFlvrGeoTiff:
			rtnValue = tblPtr->WktGeoTiffName;
			break;
		case wktFlvrEsri:
			rtnValue = tblPtr->WktEsriName;
			break;
		case wktFlvrOracle:
			rtnValue = tblPtr->WktOracleName;
			break;
		case wktFlvrGeoTools:
			rtnValue = tblPtr->WktGeoToolsName;
			break;
		case wktFlvrEpsg:
			rtnValue = tblPtr->EpsgName;
			break;
		case wktFlvrAppAlt:
			rtnValue = tblPtr->AppAltName;
			break;
		case wktFlvrLclAlt:
			rtnValue = tblPtr->LclAltName;
			break;
		case wktFlvrUnknown:
			rtnValue = tblPtr->EpsgName;
			break;
		case wktFlvrNone:
		default:
			break;
		}
	}
	return rtnValue;
}
int CSwktUnitSetName (long espgNbr,const char *newName,enum ErcWktFlavor flavor)
{
	int rtnValue = -1;
	struct csWktUnitNameMap_ *tblPtr;

	for (tblPtr = csWktUnitNameMap;tblPtr->MsiName [0] != '\0';tblPtr += 1)
	{
		if (tblPtr->EpsgNbr == espgNbr) break;
	}
	if (tblPtr->EpsgNbr != 0)
	{
		rtnValue = 0;
		switch (flavor) {
		case wktFlvrOgc:
			CS_stncp (tblPtr->WktOgcName,newName,sizeof (tblPtr->WktOgcName));
			break;
		case wktFlvrGeoTiff:
			CS_stncp (tblPtr->WktGeoTiffName,newName,sizeof (tblPtr->WktGeoTiffName));
			break;
		case wktFlvrEsri:
			CS_stncp (tblPtr->WktEsriName,newName,sizeof (tblPtr->WktEsriName));
			break;
		case wktFlvrOracle:
			CS_stncp (tblPtr->WktOracleName,newName,sizeof (tblPtr->WktOracleName));
			break;
		case wktFlvrGeoTools:
			CS_stncp (tblPtr->WktGeoToolsName,newName,sizeof (tblPtr->WktGeoToolsName));
			break;
		case wktFlvrEpsg:
			CS_stncp (tblPtr->EpsgName,newName,sizeof (tblPtr->EpsgName));
			break;
		case wktFlvrAppAlt:
			CS_stncp (tblPtr->AppAltName,newName,sizeof (tblPtr->AppAltName));
			break;
		case wktFlvrLclAlt:
			CS_stncp (tblPtr->LclAltName,newName,sizeof (tblPtr->LclAltName));
			break;
		case wktFlvrUnknown:
			CS_stncp (tblPtr->EpsgName,newName,sizeof (tblPtr->EpsgName));
			break;
		case wktFlvrNone:
		default:
			break;
		}
	}
	return rtnValue;
}
