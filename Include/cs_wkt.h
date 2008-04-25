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

			 File Name: $RCSfile: cs_wkt.h $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #2 $
		 Check In Date:	$Date: 2006/11/16 $

		Last Revision:	$Log: cs_wkt.h $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:20  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:17  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1101  2005/01/15 06:02:20  nto
		Last Revision:	Added Oracle flavor.
		Last Revision:	Revision 11.1100  2004/11/01 18:53:15  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:22  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:29  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:18  nto
		Last Revision:	Revision 11.701  2004/01/13 20:49:43  nto
		Last Revision:	Added the CSwktDictRpl function.
		Last Revision:	Revision 11.700  2003/12/19 01:49:58  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:33  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 1.3  2003/11/24 01:14:55  nto
		Last Revision:	Major changes to fix several WKT problems.
		Last Revision:	Revision 1.2  2003/11/07 03:55:58  nto
		Last Revision:	Rewrote major portions to add flavor parameter to the WKT output functions.
		Last Revision:	Revision 1.1  2003/10/01 22:10:52  nto
		Last Revision:	Initial Revision

		*  *  *  *  R E M A R K S *  *  *  *  *


******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/inc/cs_wkt.h#2 $"};
#endif

#define cs_EL2WKT_NMTRUNC  1
#define cs_DT2WKT_NMTRUNC  2
#define cs_CS2WKT_NMTRUNC  4
#define cs_DT2WKT_DTDEF    8
#define cs_DT2WKT_NODEF   16

#define cs_WKTFLG_MAPNAMES  0x01

/******************************************************************************
   Various arrays of the following structure are used to reduce the length
   of WKT names assigned to coordinate systems, datums, and ellipsoids.  We
   use pointers here as all such arrays are declared as constants and the
   strings appearing on the "replace" side are often repeated. */
struct csKeyNmRed_
{
	char *original;
	char *replace;
};
/******************************************************************************
   TrcWktPrjNameMap  --  Form of Projection Code to Name mappint Table
  
   An array of the following struture is used to map WKT projection names to a
   CS-MAP cs_PRJCOD_????? value.  Not all of the supposedly supported WKT
   projection names (I've never heard of some of them) are supported by CS-MAP.

   In the table below, we have several names.  There is an enumeration,
   csWktFlavor, which is usually used to select which of the name entries is to
   be used.  It is likely that the number of these will grow. */
struct csWktPrjNameMap_
{
	unsigned short CsMapCode;			/* CS-MAP cs_PRJCOD_???? value */
	unsigned short EpsgNbr;				/* EPSG projection code number */
	char WktOgcName [64];				/* WKT OGC name, this may be the best choice */
	char WktGeoTiffName [64];			/* WKT GeoTiff name */ 
	char WktEsriName [64];				/* WKT ESRI name */
	char WktOracleName [64];			/* WKT Oracle name */
	char WktGeoToolsName [64];			/* GeoTools name */
	char EpsgName [64];					/* EPSG name as of v6.2 */
	/* The following field is reserved for application developer use.  That is,
	   the name and the space reserved by the declaration will be part of any
	   future distribution of this product.  Application developers who need
	   to, should write a completely separate module which populates this
	   member of the structure with the values they require.  This module can
	   be maintained completely independent of CS-MAP.  As a result, the
	   official table based on this structure as defined by RefCon is NOT
	   declared as constant. */
	char AppAltName [64];
	/* The following field is reserved for future support of a local flavor.
	   Names for the local flavor are expected to be obtained from the system's
	   XML initialization file; and these elements populated during
	   initialization.  */
	char LclAltName [64];
};

/******************************************************************************
   The following functions hide all of the flavor stuff.  Probably not very
   useful if __CPP__ is not defined, but there is no reason why they should
   not compile. */

#ifdef __cplusplus
extern "C" {
#endif
int CS_isWkt (const char *wellKnownText);
long CSwktPrjName2Code (const char *wktName,enum ErcWktFlavor flavor);
long CSwktPrjName2Epsg (const char *wktName,enum ErcWktFlavor flavor);
const char* CSwktPrjCode2Name (long csCode,enum ErcWktFlavor flavor);
const char* CSwktPrjEpsg2Name (long epsgCode,enum ErcWktFlavor flavor);
int CSwktPrjSetName (long csmapCode,const char *newName,enum ErcWktFlavor flavor);
long CSwktPrmName2Code (const char *wktName,enum ErcWktFlavor flavor);
long CSwktPrmName2Epsg (const char *wktName,enum ErcWktFlavor flavor);
const char* CSwktPrmEnum2Name (enum EcsWktParameter enumCode,enum ErcWktFlavor flavor);
const char* CSwktPrmCode2Name (long csCode,enum ErcWktFlavor flavor);
const char* CSwktPrmEpsg2Name (long epsgCode,enum ErcWktFlavor flavor);
int CSwktPrmSetName (enum EcsWktParameter selCode,const char *newName,enum ErcWktFlavor flavor);
const char* CSwktUnitName2MsiName (const char *wktName,enum ErcWktFlavor flavor);
int CSwktUnitSetName (long espgNbr,const char *newName,enum ErcWktFlavor flavor);
const char* CSmsiUnitName2WktName (const char *msiName,enum ErcWktFlavor flavor);
long CSwktUnitName2Epsg (const char *wktName,enum ErcWktFlavor flavor);
const char* CSepsgUnitNbr2Name (long epsgNbr,enum ErcWktFlavor flavor);
int CSwktUnitSetName (long espgNbr,const char *newName,enum ErcWktFlavor flavor);
#ifdef __cplusplus
}
#endif

#if defined (__CPP__)

///////////////////////////////////////////////////////////////////////////////
// The following functions implement the CS-MAP 'C' interface to the Well
// Known Text C++ objects.
#ifdef __cplusplus
extern "C" {
#endif
int CS_wktToDt (struct cs_Dtdef_ *dtDef,struct cs_Eldef_ *elDef,enum ErcWktFlavor flavor,const char *wellKnownText);
int CS_wktToCs (struct cs_Csdef_ *csDef,struct cs_Dtdef_ *dtDef,struct cs_Eldef_ *elDef,enum ErcWktFlavor flavor,const char *wellKnownText);
int CS_wktToCsEx (struct cs_Csdef_ *csDef,struct cs_Dtdef_ *dtDef,struct cs_Eldef_ *elDef,enum ErcWktFlavor flavor,const char *wellKnownText);
int CS_wktDictRpl (struct cs_Csdef_ *csDef,struct cs_Dtdef_ *dtDef,struct cs_Eldef_ *elDef);
#ifdef __cplusplus
}
int CSwktToCs (struct cs_Csdef_ *csDef,struct cs_Dtdef_ *dtDef,struct cs_Eldef_ *elDef,enum ErcWktFlavor flavor,const TrcWktElement* wktElement);
#endif

/******************************************************************************
   The following are support functions to the above.  It is likely that these
   functions will become private members of the TrcWktElement class at some
   point in the future.  Application programmers should not rely on the
   future existence of these functions. */
#ifdef __cplusplus
int CS_wktEleToEl (struct cs_Eldef_ *elDef,ErcWktFlavor flavor,const TrcWktElement* wktPtr);
int CS_wktEleToDt (struct cs_Dtdef_ *dtDef,struct cs_Eldef_ *elDef,ErcWktFlavor flavor,const TrcWktElement* wktPtr);

/******************************************************************************
   Again, these functions are used internally.  Developers should not rely
   on access to these functions in future releases. */
short CS_wktReduceKeyNm (char *result,size_t rsltSize,const char *source,struct csKeyNmRed_ *reduceTbl);
void CS_wktElNameFix (char *ellipsoidName,size_t rsltSize,const char *srcName);
void CS_wktDtNameFix (char *datumName,size_t rsltSize,const char *srcName);
void CS_wktCsNameFix (char *csysName,size_t rsltSize,const char *srcName);
unsigned short CS_wktProjLookUp (ErcWktFlavor flavor,const char *wktName);

#endif
#endif
