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

			 File Name: $RCSfile: rcWellKnownText.hpp $
		   Description:
			   Purpose:

		Revision Level:	$Revision: 11.1300 $
		 Check In Date:	$Date: 2005/05/25 23:27:26 $

		Last Revision:	$Log: rcWellKnownText.hpp $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:26  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:21  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1101  2005/01/15 06:04:24  nto
		Last Revision:	Added Oracle flavor.
		Last Revision:	Revision 11.1100  2004/11/01 18:53:22  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:27  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:33  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:23  nto
		Last Revision:	Revision 11.700  2003/12/19 01:50:02  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.601  2003/12/19 01:15:57  nto
		Last Revision:	Convert to the new ANSI C++ STL standard.
		Last Revision:	Revision 11.600  2003/12/04 02:46:39  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 1.3  2003/11/24 01:14:55  nto
		Last Revision:	Major changes to fix several WKT problems.
		Last Revision:	Revision 1.2  2003/11/07 03:55:59  nto
		Last Revision:	Rewrote major portions to add flavor parameter to the WKT output functions.
		Last Revision:	Revision 1.1  2003/10/01 22:10:58  nto
		Last Revision:	Initial Revision

		*  *  *  *  R E M A R K S *  *  *  *  *


******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: rcWellKnownText.hpp 11.1300 2005/05/25 23:27:26 nto RLS $"};
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

///////////////////////////////////////////////////////////////////////////////
// The following enumerator, structure, and table define the WKT primitive
// types and the name assigned to them.  The table is designed to be a one for
// one equivalent to the enumerator.  Maintain this relationship!
enum ErcWktEleType {	rcWktNone,
						rcWktAuthority,
						rcWktAxis,
						rcWktCompDCS,
						rcWktConcatMt,
						rcWktDatum,
						rcWktFittedCS,
						rcWktGeoCCS,
						rcWktGeogCS,
						rcWktGeogTran,
						rcWktInverseMt,
						rcWktLocalCS,
						rcWktMethod,
						rcWktParameter,
						rcWktParamMt,
						rcWktPassThroughMt,
						rcWktPrimeM,
						rcWktProjCS,
						rcWktProjection,
						rcWktSpheroid,
						rcWktToWgs84,
						rcWktUnit,
						rcWktVertDatum,
						rcWktVertCS,
						rcWktLocalDatum,		// found in Oracle stuff; is this standard(?) WKT???
						rcWktUnknown
				 };
struct TrcWktEleTypeMap
{
	char Name [16];
	ErcWktEleType Type;
	bool InitlName;
	
};
//newPage//
///////////////////////////////////////////////////////////////////////////////
// Similarly with the values for the AXIS primitive.  We have an enumerator and
// a mapping table.  Internally, we use the enumerator.  Turns out that this
// stuff is not really used.  But since it exists and seems to be correct, we
// leave it here for possible use in the future.
enum ErcWktAxisId {	rcWktAxisIdNone = 0,
					rcWktAxisIdLat,
					rcWktAxisIdLng,
					rcWktAxisIdX,
					rcWktAxisIdY,
					rcWktAxisIdZ,
					rcWktAxisIdUnknown
					};
enum ErcWktAxisValue {	rcWktAxisNone = 0,
						rcWktAxisNorth,
						rcWktAxisSouth,
						rcWktAxisEast,
						rcWktAxisWest,
						rcWktAxisUp,
						rcWktAxisDown,
						rcWktAxisOther,
						rcWktAxisUnknown
					};
struct TrcWktAxisValueMap
{
	char Name [16];
	ErcWktAxisValue Value;
};
//newPage//
///////////////////////////////////////////////////////////////////////////////
// The following enumerates the various parameters supported by WKT, and the
// various names used to identify these.  Nothing like a "standard" :>)
//
// All ESPG parameters are listed even though many are not really used by
// anything in the real world.  In these cases, the parameter "types" are
// mapped, via the cs_PRMCOD_?????? values to the usual use in reality.
//
// Since the original form of WKT used the PARAMETER element to convey the
// three/seven datum shift parameters, we include them in the parameter table.
//
// We considered making the enumeration tag values map to EPSG codes, but
// we decided to remain as independent of EPSG as possible.  They are not
// software developers and often make changes that us developers would frown
// upon.  Maybe the POSC folk will prevent that from happening in the future.
enum TrcWktParameter {	rcWktPrmNone = 0,
						// Some datum transformation parameters
						rcWktPrmXTranslation = 101,
						rcWktPrmYTranslation,
						rcWktPrmZTranslation,
						rcWktPrmXRotation,
						rcWktPrmYRotation,
						rcWktPrmZRotation,
						rcWktPrmDatumScale,
						// Projection parameters
						rcWktPrmLatitudeOfOrg = 201,
						rcWktPrmLongitudeOfOrg,
						rcWktPrmScaleAtOrigin,
						rcWktPrmFalseEasting,
						rcWktPrmFalseNorthing,
						rcWktPrmLatitudeOfCtr,
						rcWktPrmLongitudeOfCtr,
						rcWktPrmAzimuth,
						rcWktPrmRectifiedGrdAng,
						rcWktPrmScaleAtCenter,
						rcWktPrmEastingOfCtr,
						rcWktPrmNorthingOfCtr,
						rcWktPrmPsdoParallelLat,
						rcWktPrmPsdoParallelScl,
						rcWktPrmLatOfFalseOrg,
						rcWktPrmLngOfFalseOrg,
						rcWktPrmStdParallel1,
						rcWktPrmStdParallel2,
						rcWktPrmEastingFalseOrg,
						rcWktPrmNorthingFalseOrg,
						rcWktPrmSphericalOrgLat,
						rcWktPrmSphericalOrgLng,
						rcWktPrmSystemWestLimit,
						rcWktPrmSystemZoneWidth,
						rcWktPrmLatOfStdParall,
						// The following WKT,  but not EPSG parameters
						rcWktPrmLatFirstPoint,
						rcWktPrmLngFirstPoint,
						rcWktPrmLatSecondPoint,
						rcWktPrmLngSecondPoint,
						// The following neither WKT oro EPSG
						rcWktPrmYaxisAzimuth,
						// Cartesian transformation parameters
						rcWktPrmAffineA0 = 501,
						rcWktPrmAffineB0,
						rcWktPrmAffineA1,
						rcWktPrmAffineB1,
						rcWktPrmAffineA2,
						rcWktPrmAffineB2,
						// The following is used to terminate tables, etc.
						rcWktPrmUnknown
					 };
struct TrcWktPrmNameMap
{
	TrcWktParameter PrmCode;
	unsigned short MsiParmCode;
	unsigned short EpsgNbr;
	char WktOgcName [48];
	char WktGeoTiffName [48];
	char WktEsriName [48];
	char WktOracleName [48];
	char WktGeoToolsName [48];
	char EpsgName   [64];
	char AppAltName [64];
	///////////////////////////////////////////////////////////////////////////
	// In future, we expect to support a "local" flavor of WKT.  This element
	// will contain the Local Alternate Name, which will be supplied via the
	// system's XML configuration file.
	char LclAltName [64];
};
//newPage//
///////////////////////////////////////////////////////////////////////////////
// TrcWktUnitNameMap  --  Form of Units Name Mapping Table
//
// An array of the following struture is used to map WKT unit names to a
// CS-MAP unit name and vice versa.  I don't know that there are different
// names for the different flavors, but I'm going to assume so.
//
// We're just mapping names here, so we care not about unit types.
//
struct TrcWktUnitNameMap
{
	char MsiName [16];					/* MSI unit name. */
	unsigned short EpsgNbr;				/* EPSG "Unit of Measure" code number */
	char EpsgName [32];					/* EPSG name as of v6.2 */
	char WktOgcName [32];				/* WKT OGC name, this may be the best choice */
	char WktGeoTiffName [32];			/* WKT GeoTiff name */ 
	char WktEsriName [32];				/* WKT ESRI name */
	char WktOracleName [32];			/* WKT Oracle name */
	char AppAltName [32];
	char LclAltName [32];
};
//newPage//
class TrcWktElement;
///////////////////////////////////////////////////////////////////////////////
// The following are non-member support functions implemented specifically to
// support processing of WKT data.
long csExtractEsriNbr (std::istream& inStrm,unsigned& lineNbr);
std::string rcExtractWkt (std::istream& inStrm,unsigned& lineNbr,unsigned& startLineNbr);
const char *rcWktTypeToName (ErcWktEleType type);
bool rcWktHasInitialName (ErcWktEleType type);
ErcWktEleType rcWktNameToType (const char *name);
const char *rcWktAxisDirToName (ErcWktAxisValue axisValue);
ErcWktAxisValue rcWktNameToAxisValue (const char *name);
int CSelDictWktCompare (const char* elKeyNamePtr,const struct cs_Eldef_ *wktElDef);
///////////////////////////////////////////////////////////////////////////////
// TrcWktElements  --  Abstracts a vector (array) of TrcWktElement
class TrcWktElements
{
public:
	///////////////////////////////////////////////////////////////////////////
	// Construction  /  Detsruction  /  Assignemnt
	TrcWktElements (void);
	TrcWktElements (const TrcWktElements& source);
	~TrcWktElements (void);
	TrcWktElements& operator= (const TrcWktElements& rhs);
	///////////////////////////////////////////////////////////////////////////
	// Operator Overrides
	const TrcWktElement* operator[] (ErcWktEleType type) const;
	const TrcWktElement* operator[] (size_t index) const;
	TrcWktElements& operator-= (const TrcWktElement* toBeRemoved)
	{
		return RemoveChild (toBeRemoved);
	}
	///////////////////////////////////////////////////////////////////////////
	// Public Named Function Memebers
	size_t GetCount (void) const {return Elements.size (); };
	void ParseGrandChildren (void);
	const TrcWktElement* LocateChild (ErcWktEleType type) const;
	const TrcWktElement* LocateChild (ErcWktEleType type,size_t& index) const;
	TrcWktElements& AddChild (const TrcWktElement& newChild,const TrcWktElement* parent,
															ErcWktEleType parentType);
	TrcWktElements& RemoveChild (const TrcWktElement* toBeRemoved);
private:
	std::vector<TrcWktElement> Elements;
};
//newPage//
///////////////////////////////////////////////////////////////////////////////
// A WKT primitive takes the following form.  it consists of a type (which
// replaces the keyword), a name (as most all primitives have a name as the
// first element of the primitive value), and a string value which is the
// remainder of the value after the name if any.
//
class TrcWktElement
{
public:
	///////////////////////////////////////////////////////////////////////////
	// Construction  /  Destruction  /  Assignment
	TrcWktElement (void);
	TrcWktElement (ErcWktEleType type,const char *value);
	TrcWktElement (ErcWktEleType type,const char *name,const char *value);
	TrcWktElement (ErcWktEleType type,const std::string& value);
	TrcWktElement (ErcWktEleType type,const std::string& name,const std::string& value);
	TrcWktElement (const char *wellKnownText);
	TrcWktElement (const TrcWktElement& source);
	~TrcWktElement (void);
	TrcWktElement& operator= (const TrcWktElement& rhs);
	///////////////////////////////////////////////////////////////////////////
	// Public Named Member Functions
	ErcWktEleType GetElementType (void) const {return ElementType; };
	ErcWktEleType GetParentType (void) const {return ParentType; };
	std::string GetElementName (void) const {return ElementName; };
	const char* GetElementNameC (void) const {return ElementName.c_str (); };
	std::string GetCompleteValue (void) const {return Value; };
	bool HasInitialName (void) const;
	void SetParent (const TrcWktElement* parent) {WktParent = parent; };
	void SetParentType (ErcWktEleType type) {ParentType = type; };
	const TrcWktElement *ChildLocate (ErcWktEleType type) const;
	const TrcWktElement *ChildLocate (ErcWktEleType type,size_t& index) const;
	const TrcWktElement *ChildSearch (ErcWktEleType type) const;
	const TrcWktElement *ParameterLocate (ErcWktFlavor flavor,short csMapParamCode) const;
	// First field, which is usually the name, is field number 0.
	void GetFieldChar (char *bufr,size_t bufrSize,size_t fieldNbr) const;
	std::string GetFieldStr (size_t fieldNbr) const;
	double GetFieldDouble (size_t fieldNbr) const;
	long GetFieldLong (size_t fieldNbr) const;
	ErcWktAxisId GetAxisId (void) const;
	ErcWktAxisValue GetAxisValue (void) const;
	ErcWktFlavor DetermineFlavor (void) const;
	///////////////////////////////////////////////////////////////////////////
	// The following member functions are used to construct a WKT object for
	// subsequent output.
	void AddChild (const TrcWktElement& childElement);
	void RemoveChild (const TrcWktElement* toBeRemoved);
	void ReconstructValue (void);
	std::string ProduceWkt (void) const;
	void ParseChildren (void);
private:
	///////////////////////////////////////////////////////////////////////////
	// Private Support Functions
	static ErcWktEleType ParseWellKnownText (std::string& value,size_t& eleStrt,
																size_t& eleTerm,
																const char *wellKnownText);
	static void RemoveElementFromString (std::string& value,size_t eleStrt,size_t eleTerm);
	std::string ExtractField  (size_t fieldNbr,bool trimQuotes = true) const;
	void ExtractField  (char *bufr,size_t bufrSize,size_t fieldNbr) const;
	void DeleteField (size_t fieldNbr);
	void CommonConstruct (void);
	static void TrimQuotes (std::string& value);
	static void TrimWhiteSpace (std::string& value);
	///////////////////////////////////////////////////////////////////////////
	// Private data items.
	const TrcWktElement *WktParent;			// pointer to parent element
	ErcWktEleType ElementType;				// Type of this primitive
	ErcWktEleType ParentType;				// Type of parent primitive
	std::string Value;						// Complete CSV value of the
											// primitive.
	std::string ElementName;				// First field of the value CSV,
											// enclosing quotes are stripped.
											// We call it name as it is a name
											// 99% of the time.
	TrcWktElements Children;				// WKT primitives parsed from
											// Value.  Extraneous stuff on
											// the front and end of Value
											// is ignored.
	unsigned short LineNbr;					// Line number in the stream at
											// which this primitive began.
	std::string FileName;					// last 15 characters of the
											// name of the file from which
											// this element was extracted
											// if known.  No path, no
											// extension.
};
