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

			 File Name: $RCSfile: CS_wellKnownText.cpp $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #11 $
		 Check In Date:	$Date: 2007/01/16 $

		Last Revision:	$Log: CS_wellKnownText.cpp $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:20  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:17  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1101  2005/01/15 06:01:50  nto
		Last Revision:	Added Oracle flavor, fixed memory leak.
		Last Revision:	Revision 11.1100  2004/11/01 18:53:15  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:22  nto
		Last Revision:	Revision 11.902  2004/10/07 02:39:57  nto
		Last Revision:	Corrected a couple of bugs with regard to WKT conversions.
		Last Revision:	Revision 11.901  2004/08/07 03:41:15  nto
		Last Revision:	Added CS_wkt2Dict function, a high level WKT import function.
		Last Revision:	Revision 11.900  2004/03/26 17:02:29  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:18  nto
		Last Revision:	Revision 11.701  2004/01/13 20:49:43  nto
		Last Revision:	Added the CSwktDictRpl function.
		Last Revision:	Revision 11.700  2003/12/19 01:49:58  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.601  2003/12/19 01:12:07  nto
		Last Revision:	Added the null datum transformation where appropriate.
		Last Revision:	Revision 11.600  2003/12/04 02:46:33  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 1.4  2003/11/24 17:21:55  nto
		Last Revision:	Fixed divide by zero problem.
		Last Revision:	Revision 1.3  2003/11/24 01:14:23  nto
		Last Revision:	Major modifications to fix several problems.
		Last Revision:	Revision 1.2  2003/11/07 03:57:06  nto
		Last Revision:	Modified major portions to add the flavor capability to WKT outout.
		Last Revision:	Revision 1.1  2003/10/01 22:09:13  nto
		Last Revision:	Initial Revision

		*  *  *  *  R E M A R K S *  *  *  *  *


******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_wellKnownText.cpp#11 $"};
#endif

#if defined (__CPP__)

#include "cs_map.h"
#include "rcWellKnownText.hpp"
#include "cs_wkt.h"

extern "C" const double cs_Zero;
extern "C" const double cs_One;
extern "C" const double cs_K180;
extern "C" const double cs_K90;
extern "C" const double cs_Km180;
extern "C" const double cs_Km90;

extern "C" int cs_Errno;
extern "C" char csErrnam [MAXPATH];

extern "C" struct cs_Prjprm_ csPrjprm [];
extern "C" struct cs_Prjtab_ cs_Prjtab [];
extern "C" struct cs_PrjprmMap_ cs_PrjprmMap [];

extern TrcWktEleTypeMap KrcWktEleTypeMap [];
extern TrcWktAxisValueMap KrcWktAxisValueMap [];
extern "C" csWktPrjNameMap_ csWktPrjNameMap [];
extern TrcWktPrmNameMap KrcWktPrmNameMap [];

extern "C" const struct csKeyNmRed_ csAcronyms [];
extern "C" const struct csKeyNmRed_ csElReduce [];
extern "C" const struct csKeyNmRed_ csDtReduce [];
extern "C" const struct csKeyNmRed_ csCsReduce [];

// The following function is used to compare a WKT ellipsoid definition as
// provided by the elDef argument, with an MSI dictionary definition indicated
// by the elKeyNamePtr argument.  Returns true if the two ellipsoids are
// numerically equivalent.
int CSelDictWktCompare (const char* elKeyNamePtr,const struct cs_Eldef_ *wktElDef)
{
	bool same = false;
	struct cs_Eldef_ *msiElDef;

	msiElDef = CS_eldef (elKeyNamePtr);
	if (msiElDef != 0)
	{
		same = (fabs (msiElDef->e_rad - wktElDef->e_rad) < 5.0E-03) &&
			(fabs (msiElDef->p_rad - wktElDef->p_rad) < 5.0E-03);
	}
	return same ? 1 : 0;
}
void CS_wktUnitNameFix (char *unitName,size_t rsltSize,ErcWktFlavor flavor,const char *wktName)
{
	const char *cp = CSwktUnitName2MsiName (wktName,flavor);
	if (cp != 0 && *cp != '\0') CS_stncp (unitName,cp,static_cast<int>(rsltSize));
	else                        CS_stncp (unitName,"<unknown>",static_cast<int>(rsltSize));
}
//newPage//
// Function to reduce a keyname by appying the provided table.
short CS_wktReduceKeyNm (char *result,size_t rsltSize,const char *source,const struct csKeyNmRed_ *reduceTbl)
{
	short esriType = FALSE;
	short spCount = 0;
	short usCount = 0;
	size_t charsLeft;
	char *cp;
	char *cpRpl;
	const struct csKeyNmRed_ *tblPtr;
	char lclSource [128];
	char lclResult [256];

	// Get a copy of the source string in a place where we can dink with it.
	CS_stncp (lclSource,source,sizeof (lclSource));

	// Count the underscores and spaces in the source.
	for (cp = lclSource;*cp != '\0';cp += 1)
	{
		if (*cp == ' ') spCount += 1;
		if (*cp == '_') usCount += 1;
	}
	esriType = (spCount == 0) && (usCount > 0);

	// If it is an esri type, replace all the underscores with spaces.
	if (esriType)
	{
		for (cp = lclSource;*cp != '\0';cp += 1)
		{
			if (*cp == '_') *cp = ' ';
		}
	}

	// For each entry in the reduce table, we see if our lclSource contains an
	// equivalent sub-string.
	cpRpl = NULL;
	for (tblPtr = reduceTbl;*(tblPtr->original) != '\0';tblPtr += 1)
	{
		cpRpl = (char *)CS_stristr (lclSource,tblPtr->original);
		if (cpRpl != NULL) break;
	}
	if (cpRpl != NULL)
	{
		*cpRpl = '\0';
		cpRpl += strlen (tblPtr->original);

		cp = CS_stncp (lclResult,lclSource,sizeof (lclResult));
		charsLeft = sizeof (lclResult) - strlen (lclResult);
		cp = CS_stncp (cp,tblPtr->replace,static_cast<int>(charsLeft));
		charsLeft = sizeof (lclResult) - strlen (lclResult);
		CS_stncp (cp,cpRpl,static_cast<int>(charsLeft));
	}
	else
	{
		CS_stncp (lclResult,lclSource,sizeof (lclResult));
	}
	CS_stncp (result,lclResult,static_cast<int>(rsltSize));
	return (cpRpl != NULL);
}
// Function processes WKT ellipsoid key names before passing on to CS-MAP.
void CS_wktElNameFix (char *ellipsoidName,size_t rsltSize,const char *srcName)
{
	char reducedName [128];

	CS_wktReduceKeyNm (reducedName,sizeof (reducedName),srcName,csAcronyms);
	CS_wktReduceKeyNm (reducedName,sizeof (reducedName),reducedName,csElReduce);
	CS_stncp (ellipsoidName,reducedName,static_cast<int>(rsltSize));
}
// Function processes WKT datum key names before passing on to CS-MAP.
void CS_wktDtNameFix (char *datumName,size_t rsltSize,const char *srcName)
{
	char reducedName [128];

	if (*srcName == 'D' && *(srcName + 1) == '_') srcName += 2;
	CS_wktReduceKeyNm (reducedName,sizeof (reducedName),srcName,csAcronyms);
	CS_wktReduceKeyNm (reducedName,sizeof (reducedName),reducedName,csDtReduce);
	CS_stncp (datumName,reducedName,static_cast<int>(rsltSize));
}
// Function processes WKT datum key names before passing on to CS-MAP.
void CS_wktCsNameFix (char *csysName,size_t rsltSize,const char *srcName)
{
	char reducedName [128];

	CS_stncp (reducedName,srcName,sizeof (reducedName));
	while (CS_wktReduceKeyNm (reducedName,sizeof (reducedName),reducedName,csAcronyms));
	while (CS_wktReduceKeyNm (reducedName,sizeof (reducedName),reducedName,csCsReduce));
	CS_stncp (csysName,reducedName,static_cast<int>(rsltSize));
}
unsigned short CS_wktProjLookUp (ErcWktFlavor flavor,const char *wktName)
{
	bool flag;
	unsigned short projCode = cs_PRJCOD_END;
	struct csWktPrjNameMap_ *mapPtr;

	for (mapPtr = csWktPrjNameMap;mapPtr->CsMapCode != cs_PRJCOD_END;mapPtr += 1)
	{
		switch (flavor) {
		case wktFlvrOgc:
			flag = !CS_stricmp (wktName,mapPtr->WktOgcName);
			break;
		case wktFlvrGeoTiff:
			flag = !CS_stricmp (wktName,mapPtr->WktGeoTiffName);
			break;
		case wktFlvrEsri:
			flag = !CS_stricmp (wktName,mapPtr->WktEsriName);
			break;
		case wktFlvrOracle:
			flag = !CS_stricmp (wktName,mapPtr->WktOracleName);
			break;
		case wktFlvrGeoTools:
			flag = !CS_stricmp (wktName,mapPtr->WktGeoToolsName);
			break;
		case wktFlvrAppAlt:
			flag = !CS_stricmp (wktName,mapPtr->AppAltName);
			break;
		case wktFlvrLclAlt:
			flag = !CS_stricmp (wktName,mapPtr->LclAltName);
			break;
		case wktFlvrUnknown:
		case wktFlvrNone:
		default:
			flag = !CS_stricmp (wktName,mapPtr->LclAltName);
			if (!flag) flag = !CS_stricmp (wktName,mapPtr->AppAltName);
			if (!flag) flag = !CS_stricmp (wktName,mapPtr->WktOgcName);
			if (!flag) flag = !CS_stricmp (wktName,mapPtr->WktEsriName);
			if (!flag) flag = !CS_stricmp (wktName,mapPtr->WktGeoTiffName);
			if (!flag) flag = !CS_stricmp (wktName,mapPtr->EpsgName);
			break;
		}
		if (flag)
		{
			projCode = mapPtr->CsMapCode;
			break;
		}		
	}
	return projCode;
}
//newPage//
int CS_wktAxisToQuad (const TrcWktElement* wktElement)
{
	bool swap = false;
	int quad = 1;
	size_t locateIndex = 0;

	ErcWktAxisId axisId1 = rcWktAxisIdNone;
	ErcWktAxisId axisId2 = rcWktAxisIdNone;
	ErcWktAxisValue axisValue1 = rcWktAxisNone;
	ErcWktAxisValue axisValue2 = rcWktAxisNone;
	const TrcWktElement *axis1;
	const TrcWktElement *axis2;

	axis1 = wktElement->ChildLocate (rcWktAxis,locateIndex);
	if (axis1 != 0)
	{
		axisId1    = axis1->GetAxisId ();
		axisValue1 = axis1->GetAxisValue ();
		axis2 = wktElement->ChildLocate (rcWktAxis,locateIndex);
		if (axis2 != 0)
		{
			axisId2    = axis2->GetAxisId ();
			axisValue2 = axis2->GetAxisValue ();
		}
	}
	if (axis1 != 0 && axis2 != 0)
	{
		swap = (axisId1 == rcWktAxisIdLat || axisId1 == rcWktAxisIdY);
		if (swap)
		{
			axisId1    = axis2->GetAxisId ();
			axisValue1 = axis2->GetAxisValue ();
			axisId2    = axis1->GetAxisId ();
			axisValue2 = axis1->GetAxisValue ();
		}
		if (axisId1 == rcWktAxisIdLng && axisId2 == rcWktAxisIdLat)
		{
			if      (axisValue1 == rcWktAxisEast) quad = (axisValue2 == rcWktAxisNorth) ? 1 : 4;
			else if (axisValue1 == rcWktAxisWest) quad = (axisValue2 == rcWktAxisNorth) ? 2 : 3;
		}
		else if (axisId1 == rcWktAxisIdX && axisId2 == rcWktAxisIdY)
		{
			if      (axisValue1 == rcWktAxisEast) quad = (axisValue2 == rcWktAxisNorth) ? 1 : 4;
			else if (axisValue1 == rcWktAxisWest) quad = (axisValue2 == rcWktAxisNorth) ? 2 : 3;
		}
	}
	return (swap) ? -quad : quad;
}
int CS_isWkt (const char *wellKnownText)
{
	int left = 0;
	int right = 0;
	int rtnValue = 0;
	const char* cp;

	for (cp = wellKnownText;*cp != '\0';cp++)
	{
		if (*cp == '[') left += 1;
		if (*cp == ']') right += 1;
	}
	/* Technically, a WKT string only needs one set of brackets, but such would
	   not be very useful.  We say two or more brackets qualfies as an attempt
	   at a WKT string. */
	if (left > 1 || right > 1)
	{
		if (left == right)
		{
			/* The brakets balance, we say it is a valid WKT. */
			rtnValue = 1;
		}
		else
		{
			/* Brackets don't balance, but there are at least two of them,
			   so we consider it to be an invalid WKT string. */
			rtnValue = -1;
		}
	}
	return rtnValue;
}
//newPage//
// This following is an extended version of the original CS_wktToCs function.
// It is specifically designed to work well with the CS_wktCsDefFunc function.
// Returns zero on success, -1 on hard failure.  Cause of hard failure will
// have already been reported to CS_erpt ().
//
// CS_wktToCs, CS_wktToDt, and CS_wktToEl attempt to produce a CS-MAP rendition
// of whatever was extracted from the WKT string, without any attempt to
// enhance the conversion.
//
// This extended version attempts to enhance the conversion to the degree
// possible.  The primary need here is to supply some sort of datum definition
// as such is rarely present in a WKT string.  Other enhancements rely on the
// mapping of a WKT name, using the provided (or determined) flavor, to a
// CS-MAP name.  In any case, use CS_wktToCs (et al) if you don't want any of
// these enhancements.
//
// If provided a flavor of wktFlvrNone, this function will attempt to
// determine the flavor.  The best results are obtained if the flavor
// is specified.  The difference being: If this function is to determine
// the flavor and it fails, you get a message to the effect that the flavor
// could not be determined.  If you specify a flavor, you will get a much
// more meaningful error message indicating where the WKT string departs
// from the flavor specified.
//
int CS_wktToCsEx (struct cs_Csdef_ *csDef,struct cs_Dtdef_ *dtDef,struct cs_Eldef_ *elDef,ErcWktFlavor flavor,const char *wellKnownText)
{
	bool mapNames = true;			// until we know different, we will map WKT names to
									// CS-MAP names wherever possible.
	unsigned short myFlags;
	int st;
	long esriNbr;
	long oracleNbr;
	long epsgNbr;
	const char* msiNamePtr;

	char wrkBufr [128];
	char csMapElName [cs_KEYNM_DEF];
	char csMapDtName [cs_KEYNM_DEF];
	char csMapCsName [cs_KEYNM_DEF];

	st = 0;
	csMapElName [0] = '\0';
	csMapDtName [0] = '\0';
	csMapCsName [0] = '\0';

	// Parse the provided string and determine the flavor if necessary.
	TrcWktElement wktElement (wellKnownText);
	if (wktElement.GetElementType () == rcWktUnknown)
	{
		// Parsing failed.  We assume that the provided string is either not
		// a WKT string, or is a badly formed WKT string.
		CS_stncp (csErrnam,wellKnownText,40);
		CS_erpt (cs_WKT_BADFORM);
		goto error;
	}
	wktElement.ParseChildren ();

	// Determine the flavor if the calling application has not specified one.
	// It is best if the end-user supplies the flavor, but this works most
	// of the time. MOST OF THE TIME; NOT ALL OF THE TIME.
	if (flavor == wktFlvrNone)
	{
		flavor = wktElement.DetermineFlavor ();
		if (flavor == wktFlvrUnknown)
		{
			// We could not determine the flavor.  This can also mean that
			// the projection, or a projection parameter, is not in the
			// appropriate flavor table.
			const char* cp = wktElement.GetElementNameC ();
			CS_stncp (csErrnam,cp,MAXPATH);
			CS_erpt (cs_WKT_FLAVOR);
			goto error;
		}
	}

	// Use the basic (non-extended) CS_wktToCs to parse and extract information
	// from the WKT string.  The returned information is pretty much what was
	// in the WKT string, no enhancements yet.
	st = CSwktToCs (csDef,dtDef,elDef,flavor,&wktElement);
	if (st < 0)
	{
		// Oops!!! Hard error.  It should have already been reported.
		// Simply return the hard error indication.
		goto error;
	}

	// See if we can map the ellipsoid name to a CS-MAP name.  Currently, we
	// only have name maps for ESRI and Oracle.  This should be replaced with
	// a more generic ellipsoid name map function to which flavor is
	// a parameter.
	msiNamePtr = 0;
	if (flavor == wktFlvrEsri)
	{
		msiNamePtr = CS_esriElpName2Msi (elDef->name);
	}
	else if (flavor == wktFlvrOracle)
	{
		msiNamePtr = CS_oracleElpName2Msi (elDef->name);
	}
	if (msiNamePtr != 0)
	{
		// The name mapping was successful.  The proposed name is saved for
		// possible replacement.
		CS_stncp (csMapElName,msiNamePtr,cs_KEYNM_MAX);
	}

	if ((st & cs_EL2WKT_NMTRUNC) != 0)
	{
		// If the name of the ellipsoid got truncated, we replace the name with
		// something more meaningful if we can.
		if (flavor == wktFlvrEsri)
		{
			// ESRI does not assign numbers to ellipsoids.  We use the
			// EPSG number instead.
			epsgNbr = CS_esriElpName2EpsgNbr (elDef->name);
			if (epsgNbr != 0)
			{
				sprintf (wrkBufr,"EPSG:%ld",epsgNbr);
				CS_stncp (elDef->key_nm,wrkBufr,cs_KEYNM_MAX);
				
				// Replace the ellipsoid key name in the dtDef structure with
				// the new name as well. We leave the source name alone.
				CS_stncp (dtDef->ell_knm,wrkBufr,cs_KEYNM_MAX);
			}
			else
			{
				// It didn't have an EPSG number assigned.  If it has an
				// equivalent MSI name, we'll stick that in there.
				msiNamePtr = CS_esriElpName2Msi (elDef->name);
				if (msiNamePtr != 0)
				{
					sprintf (wrkBufr,"MapsTo:%s",msiNamePtr);
					CS_stncp (elDef->key_nm,wrkBufr,cs_KEYNM_MAX);
					CS_stncp (dtDef->ell_knm,wrkBufr,cs_KEYNM_MAX);
				}
			}
			// Otherwise, we just leave the truncated name there.
		}
		else if (flavor == wktFlvrOracle)
		{
			// This is problematic as Oracle does not assign numbers to
			// ellipsoids.  We use EPSG numbers instead.
			epsgNbr = CS_oracleElpName2Epsg (elDef->name);
			if (epsgNbr != 0)
			{
				sprintf (wrkBufr,"EPSG:%ld",epsgNbr);
				CS_stncp (elDef->key_nm,wrkBufr,cs_KEYNM_MAX);

				// Replace the ellipsoid key name in the dtDef structure with
				// the new name as well.
				CS_stncp (dtDef->ell_knm,wrkBufr,cs_KEYNM_MAX);
			}
			else
			{
				// It didn't have an EPSG number assigned.  If it has an
				// equivalent MSI name, we'll stick that in there.
				msiNamePtr = CS_oracleElpName2Msi (elDef->name);
				if (msiNamePtr != 0)
				{
					sprintf (wrkBufr,"MapsTo:%s",msiNamePtr);
					CS_stncp (elDef->key_nm,wrkBufr,cs_KEYNM_MAX);
					CS_stncp (dtDef->ell_knm,wrkBufr,cs_KEYNM_MAX);
				}
			}
			// Otherwise, we just leave the truncated name there.
		}
		// Otherwise, we just leave the truncated name there.
	}

	if ((st & cs_DT2WKT_NODEF) != 0)
	{
		struct cs_Dtdef_ *dtDefPtr = 0;
		const char* msiDtNamePtr = 0;

		// There was no complete datum definition in the WKT string provided.
		// However, we should have a WKT datum name.  We use what name(s) we
		// have and try to map it to an MSI name.  If successful, we replace
		// the guts of the dtDef structure (which is not a complete datum
		// definition) with the datum definition from the MSI dictionary, and
		// replace the datum name in the csDef structure with the MSI name of
		// the definition which we used to obtain a complete definition.
		if (flavor == wktFlvrEsri)
		{
			// Map the ESRI name to an MSI name.
			msiDtNamePtr = CS_esriDtmName2Msi (dtDef->name,&myFlags);
		}
		else if (flavor == wktFlvrOracle)
		{
			// Map the Oracle name to an MSI name.
			msiDtNamePtr = CS_oracleDtmName2Msi (dtDef->name,&myFlags);
		}
		if (msiDtNamePtr == 0 && dtDef->epsgNbr != 0)
		{
			// Neither of the above mappings produced a name; but there
			// appears to be an EPSG number available.  See if that produces
			// a name we can use.
			short myFlags;
			long epsgNbr = static_cast<long>(dtDef->epsgNbr);
			msiDtNamePtr = CSepsg2msiDT (epsgNbr,&myFlags);
		}
		if (msiDtNamePtr == 0)
		{
			// Allthat failed to produce an MSI datum name, we use whatever name
			// was in the WKT string as a last resort.
			msiDtNamePtr = dtDef->key_nm;
		}
		if (msiDtNamePtr != 0)
		{
				dtDefPtr = CS_dtdef (msiDtNamePtr);
		}
		if (dtDefPtr != 0)
		{
			// Here when:
			// 1> there was no complete datum definition in the WKT string, AND
			// 2> name mapping produced the CS-MAP name of what we will consider
			//    to be the complete definition of the datum indicated by the
			//    WKT string.  Not 100% reliable by any means, but the only
			//    alternative is to return a set of unusable definitions.
			//
			// We have several jobs to do here.  First, we replace the WKT
			// datum name in the cs_Dtdef_ key name field, and also in the
			// cs_Csdef_ field that references it.

			// Below, we will copy the MSI dictionary datum definition which
			// the name mapping process indicates what the the WKT datum should
			// be.  It is entirely possible that the ellipsoid referenced in
			// the MSI dictionary entry is not the same as the ellipsoid
			// definition which was obtained from the WKT string.  Since the
			// WKT rendition of ellipsoids is complete and usable, we replace
			// the ellipsoid key name with that obtained from the MSI
			// dictionary only after we verify that the ellipsoids are indeed
			// the same.
			//
			// If they are not the same, we leave the ellipsoid name in the
			// cs_Dtdef_ structure alone, as it should be whatever name was
			// assigned to the WKT ellipsoid during the WKT parse.  Thus, the
			// returned definition will reference the actual ellipsoid
			// definition which was provided by the WKT string.
			int same = CSelDictWktCompare (dtDefPtr->ell_knm,elDef);
			if (same != 0)
			{
				// The ellipsoid referenced by the MSI datum dictionary
				// definition is the same (numerically) as the ellipsoid
				// definition extracted from the WKT string.  We choose
				// to use the MSI key name of the MSI dictionary definition
				// of the ellipsoid.
				CS_stncp (dtDef->ell_knm,dtDefPtr->ell_knm,sizeof (dtDef->ell_knm));
				
				// Since we will be using the CS-MAP definition with its CS_MAP key
				// name, we activate the datum key name replacement.
				CS_stncp (csMapDtName,msiDtNamePtr,cs_KEYNM_MAX);
			}
			else
			{
				// Since we have determined it inappropriate to map the ellipsoid
				// name, we suppress the mapping of all names.
				mapNames = false;
			}

			// Copy the rest of the MSI definition to the dtDef structure.
			// Preserve the 'source', 'descriptive name', and WKT flavor from
			// the WKT parse.
			CS_stncp (dtDef->group,dtDefPtr->group,sizeof (dtDef->group));
			CS_stncp (dtDef->locatn,dtDefPtr->locatn,sizeof (dtDef->locatn));
			CS_stncp (dtDef->cntry_st,dtDefPtr->cntry_st,sizeof (dtDef->cntry_st));
			CS_stncp (dtDef->fill,dtDefPtr->fill,sizeof (dtDef->fill));
			dtDef->delta_X  = dtDefPtr->delta_X;
			dtDef->delta_Y  = dtDefPtr->delta_Y;
			dtDef->delta_Z  = dtDefPtr->delta_Z;
			dtDef->rot_X    = dtDefPtr->rot_X;
			dtDef->rot_Y    = dtDefPtr->rot_Y;
			dtDef->rot_Z    = dtDefPtr->rot_Z;
			dtDef->bwscale  = dtDefPtr->bwscale;
			dtDef->protect  = dtDefPtr->protect;
			dtDef->to84_via = dtDefPtr->to84_via;
			dtDef->epsgNbr  = dtDefPtr->epsgNbr;
			dtDef->fill01   = dtDefPtr->fill01;
			dtDef->fill02   = dtDefPtr->fill02;
			dtDef->fill03   = dtDefPtr->fill03;
			dtDef->fill04   = dtDefPtr->fill04;
			CS_free (dtDefPtr);

			// Leave the original WKT name alone. It is useful info.
			// Use the source field to indicate where the definition came from.
			CS_stncp (dtDef->source,"Obtained from dictionary by mapping the WKT datum name.",sizeof (dtDef->source));
		}
		else
		{
			// There was no datum definition in the WKT string, AND the WKT
			// name did not provide us with a clue as to what the datum
			// definition is.  Not much we can do other than:
			CS_stncp (csErrnam,dtDef->name,sizeof (csErrnam));
			CS_erpt (cs_WKT_DTMAP);
			goto error;
		}
	}
	else
	{
		// There was a complete datum definition in the WKT string.  Rare, but
		// it happens, depending upon the flavor.  See if the WKT name maps
		// to an CS-MAP name.  If so, we'll use the CS-MAP name.
		msiNamePtr = 0;
		if (flavor == wktFlvrEsri)
		{
			// Map the ESRI name to an MSI name.
			msiNamePtr = CS_esriDtmName2Msi (dtDef->name,&myFlags);
		}
		else if (flavor == wktFlvrOracle)
		{
			// Map the Oracle name to an MSI name.
			msiNamePtr = CS_oracleDtmName2Msi (dtDef->name,&myFlags);
		}
		else
		{
			msiNamePtr = dtDef->key_nm;
		}
		if (msiNamePtr != 0)
		{
			// Note, if we replace the key name in the datum definition, we
			// must also replace the reference to it in the coordinate system
			// definition.
			CS_stncp (csMapDtName,msiNamePtr,cs_KEYNM_MAX);
		}
		if ((st & cs_DT2WKT_NMTRUNC) != 0)
		{
			// Here if there is a datum definition provided in the WKT, and the
			// name was truncated.  We generate a rational name which will fit
			// in the 23 characters supported by CS-MAP.
			if (flavor == wktFlvrEsri)
			{
				esriNbr = CS_esriDtmName2EpsgNbr (dtDef->name,&myFlags);
				if (esriNbr > 0)
				{
					sprintf (wrkBufr,"ESRI:%ld",esriNbr);
					CS_stncp (dtDef->key_nm,wrkBufr,cs_KEYNM_MAX);

					// Replace the datum key name in the csDef structure with
					// the new name as well.
					CS_stncp (csDef->dat_knm,wrkBufr,cs_KEYNM_MAX);
				}
				// If that didn't work, we go with the truncated name.
			}
			else if (flavor == wktFlvrOracle)
			{
				// This is problematic as Oracle does not assign numbers to
				// datums.  We use EPSG numbers instead.
				epsgNbr = CS_oracleDtmName2EpsgNbr (dtDef->name,&myFlags);
				if (epsgNbr > 0)
				{
					sprintf (wrkBufr,"EPSG:%ld",epsgNbr);
					CS_stncp (dtDef->key_nm,wrkBufr,cs_KEYNM_MAX);

					// Replace the datum key name in the csDef structure with
					// the new name as well.
					CS_stncp (csDef->dat_knm,wrkBufr,cs_KEYNM_MAX);
				}
			}
		}
	}

	// See if we can map the coordinate system name into an MSI name.
	msiNamePtr = 0;
	if (flavor == wktFlvrEsri)
	{
		msiNamePtr = CS_esriName2Msi (csDef->desc_nm,&myFlags);
	}
	else if (flavor == wktFlvrOracle)
	{
		msiNamePtr = CS_oracleName2Msi (csDef->desc_nm);
	}
	else
	{
		msiNamePtr = csDef->key_nm;
	}
	if (msiNamePtr != 0)
	{
		CS_stncp (csMapCsName,msiNamePtr,cs_KEYNM_MAX);
	}
	if ((st & cs_CS2WKT_NMTRUNC) != 0)
	{
		// If the key-name name of the resulting cs_Csdef_ was truncated,
		// do the best we can to replace it with something meaningful, and
		// untruncated.
		if (flavor == wktFlvrEsri)
		{
			esriNbr = CS_esriName2Nbr (csDef->desc_nm);
			if (esriNbr > 0)
			{
				sprintf (wrkBufr,"ESRI:%ld",esriNbr);
				CS_stncp (csDef->key_nm,wrkBufr,cs_KEYNM_MAX);
			}
		}
		else if (flavor == wktFlvrOracle)
		{
			oracleNbr = CS_oracleName2Nbr (csDef->desc_nm);
			if (oracleNbr > 0)
			{
				sprintf (wrkBufr,"Oracle:%ld",oracleNbr);
				CS_stncp (csDef->key_nm,wrkBufr,cs_KEYNM_MAX);
			}
		}
	}

	// If it has been determined appropriate to map names, we do so now.
	// We only map the datum and ellipsoid names if both are to be replaced.
	// We map the coordinate system name independently.   Thisis the case
	// as the major issue with WKT, and why we have to go to so much trouble,
	// is that WKT does not include (typically) a datum definition.  So,
	// if we have a datum (and related ellipsoid) match, we map them.
	if (mapNames && csMapElName [0] != '\0' &&
					csMapDtName [0] != '\0')
	{
		// Map datum and ellipsoid names.
		CS_stncp (csDef->dat_knm,csMapDtName,cs_KEYNM_DEF);
		CS_stncp (dtDef->key_nm,csMapDtName,cs_KEYNM_DEF);
		CS_stncp (dtDef->ell_knm,csMapElName,cs_KEYNM_DEF);
		CS_stncp (elDef->key_nm,csMapElName,cs_KEYNM_DEF);
		st &= ~(static_cast<int>(cs_DT2WKT_NMTRUNC | cs_EL2WKT_NMTRUNC));
		if (csMapCsName [0] != '\0')
		{
			CS_stncp (csDef->key_nm,csMapCsName,cs_KEYNM_DEF);
			st &= ~(static_cast<int>(cs_CS2WKT_NMTRUNC));
		}
	}

	if (st >= 0)
	{
       	// make all the names match on success
		CS_stncp (dtDef->ell_knm,elDef->key_nm,cs_KEYNM_DEF);
		CS_stncp (csDef->dat_knm,dtDef->key_nm,cs_KEYNM_DEF);
	}
	return st;
error:
	return -1;
}
///////////////////////////////////////////////////////////////////////////////
// The following converts a WKT PROJCS or GEOGCS object to CS-MAP form
// consisting of a a cs_Csdef_ structure, a cs_Dtdef_ structure, and a
// cs_Eldef_ structure.  The WKT PROJCS object often does not contain enough
// information for a cs_Dtdef_ structure.  The name of the referenced datum,
// if there is one, is inserted in the dat_knm member of the cs_Csdef_
// structure.
//
// Notes:
//
//	1> Note the "C" linkage!  Intended to be callable from the normal CS-MAP
//	   environment.
//	2> Use CS_wktToDt to process a WKT GEOTRAN object (ESRI) or a WKT DATUM
//	   object to obtain a cs_Dtdef_ structure.
//	3> This function will process a GEOGCS object and return a cs_Csdef_
//	   structure for the CS-MAP equivalent.
//	4> Use the flavor enumeration to indicate the types of names to be expected.
//	5> Returns zero to indicate success.
//	6> Returns negative value to indicate hard failure.  Use CS_errmsg to get a
//	   textual description.
//	7> A positive return may have any of the following bits set to indicate
//	   the state of the resulting conversion:
//		cs_EL2WKT_NMTRUNC (1)	Ellipsoid key name truncated
//		cs_DT2WKT_NMTRUNC (2)	Datum key name truncated
//		cs_CS2WKT_NMTRUNC (4)	Coordinate system key name truncated
//		cs_DT2WKT_DTDEF   (8)	Datum definition extracted from dictionary by name.
//		cs_DT2WKT_NODEF  (16)	No datum definition is present in dtDef.
//	8> The 'desc_nm' element will always carry the full WKT system name (up to 63 characters).
//	9> In the case of key names of all types,  they are generally trunctated to
//	   the 23 charcater maximum supported by CS-MAP.  In the case of a DATUM
//	   key name, a trailing "_To_WGS84" is removed before truncation.  A
//	   leading "D_" is removed from datum names as well.
// 10> In the case of processing a GEOTRAN, the name assigned to the result is
//	   extracted from the GEOTRAN name, after any embedded "_ToWGS84" is removed
//	   from the name.
//
// The bulk of the processing is embodied in the CSwktToCs function defined
// below.  This refactoring eliminates multiple parsings of the WKT string.
int CS_wktToCs (struct cs_Csdef_ *csDef,struct cs_Dtdef_ *dtDef,struct cs_Eldef_ *elDef,ErcWktFlavor flavor,const char *wellKnownText)
{
	int st;

	// Convert the text string to TrcWktElement form.  This object will get
	// deleted automatically as soon as it goes out of scope.
	TrcWktElement wktElement (wellKnownText);
	if (wktElement.GetElementType () == rcWktUnknown)
	{
		// Parsing failed.
		CS_stncp (csErrnam,wellKnownText,40);
		CS_erpt (cs_WKT_BADFORM);
	}
	wktElement.ParseChildren ();

	// Determine the flavor if the calling application has not specified one.
	if (flavor == wktFlvrNone)
	{
		flavor = wktElement.DetermineFlavor ();
		if (flavor == wktFlvrUnknown)
		{
			const char* cp = wktElement.GetElementNameC ();
			CS_stncp (csErrnam,cp,MAXPATH);
			CS_erpt (cs_WKT_FLAVOR);
			return -1;
		}
	}
	st = CSwktToCs (csDef,dtDef,elDef,flavor,&wktElement);
	return st;
}
// The following function embodies the majority of the functionality of
// the CS_wktToCs function defined immediately above, it takes a parsed
// TrcWktElement as an argument instead of a normal character string.
int CSwktToCs (struct cs_Csdef_ *csDef,struct cs_Dtdef_ *dtDef,struct cs_Eldef_ *elDef,ErcWktFlavor flavor,const TrcWktElement* wktElement)
{
	short unitType;
	short projCode;
	short parmIdx;
	short parmCode;

	int status = 0;
	size_t nameLength;
	unsigned long projFlags;

	double *dblPtr;
	const char *cp;
	const char *cp1;
	struct cs_Prjtab_ *pp;
	struct cs_PrjprmMap_ *mp;
	struct cs_Prjprm_ *csPrjPrmPtr;
	// These are all constant pointers to sub-elements of the main wktElement
	// object declared below.  Do not 'delete' these.
	const TrcWktElement* unit = 0;
	const TrcWktElement* datum = 0;
	const TrcWktElement* geogcs = 0;
	const TrcWktElement* authority = 0;
	const TrcWktElement* parameter = 0;
	const TrcWktElement* projection = 0;
	const TrcWktElement* primeMeridian = 0;
	const TrcWktElement* sclRedParm = 0;
	const TrcWktElement* orgLatParm = 0;

	double parmValue;
	double unitsFactor;
	double geogcsUnitsFactor;
	double primeMeridianLongitude;				// in degrees

	char unitName [64];
	char geogcsUnitName [64];
	char reducedName [64];

	// Erase any garbage which may be in the provided structures.
	if (csDef != 0)
	{
		memset (csDef,0,sizeof (*csDef));
	}
	if (dtDef != 0)
	{
		memset (dtDef,0,sizeof (*dtDef));
	}
	if (elDef != 0)
	{
		memset (elDef,0,sizeof (*elDef));
	}

	// We only process PROJCS or GEOGCS objects.
	if (wktElement->GetElementType () != rcWktProjCS && wktElement->GetElementType () != rcWktGeogCS)
	{
		CS_erpt (cs_WKT_WRNGTYP);
		goto error;
	}

	// Process the datum portion.  This does the ellipsoid as well.
	if (dtDef != 0)
	{
		int dtStatus;
		datum = wktElement->ChildSearch (rcWktDatum);
		if (datum == 0)
		{
			CS_erpt (cs_WKT_NODATUM);
			goto error;
		}
		dtStatus = CS_wktEleToDt (dtDef,elDef,flavor,datum);
		if (dtStatus < 0)
		{
			goto error;
		}
		status |= dtStatus;
	}

	// Some stuff common to PROJCS and GEOGCS.
	memset (csDef,'\0',sizeof (*csDef));
	csDef->wktFlvr = static_cast<short>(flavor);
	cp = wktElement->GetElementNameC ();
	CS_stncp (csDef->desc_nm,cp,sizeof (csDef->desc_nm));
	CS_stncp (reducedName,cp,sizeof (reducedName));
	nameLength = strlen (reducedName);
	if (nameLength > cs_KEYNM_MAX)
	{
		CS_wktCsNameFix (reducedName,sizeof (reducedName),reducedName);
	}
	CS_stncp (csDef->key_nm,reducedName,sizeof (csDef->key_nm));

	unitType = (wktElement->GetElementType () == rcWktGeogCS) ? cs_UTYP_ANG : cs_UTYP_LEN;
	unit = wktElement->ChildLocate (rcWktUnit);			// using ChildSearch here is bad news 
	if (unit == 0)
	{
		CS_erpt (cs_WKT_NOUNIT);
		goto error;
	}
	cp = unit->GetElementNameC ();
	if (cp != 0)
	{
		CS_stncp (csErrnam,cp,sizeof (csErrnam));
	}
	CS_wktUnitNameFix (unitName,sizeof (unitName),flavor,cp);
	CS_stncp (csDef->unit,unitName,sizeof (csDef->unit));
	unitsFactor = CS_unitlu (unitType,unitName);
	if (unitsFactor == 0.0)
	{
		// Name approach didn't work.  See is we can locate a CS-MAP unit name
		// using the unit factor in the WKT element.
		unitsFactor = unit->GetFieldDouble (0);
		cp = CS_unitluByFactor (unitType,unitsFactor);
		if (cp != 0)
		{
			CS_stncp (unitName,cp,sizeof (unitName));
		}
		else
		{
			unitsFactor = 0.0;
		}
	}
	if (unitsFactor == 0.0)
	{
		CS_erpt (cs_WKT_INVUNIT);
		goto error;
	}

	geogcs = (wktElement->GetElementType () == rcWktGeogCS) ? wktElement : wktElement->ChildLocate (rcWktGeogCS);
	if (geogcs == 0)
	{
		CS_erpt (cs_WKT_NOGEOCS);
		goto error;
	}
	unit = geogcs->ChildLocate (rcWktUnit);			// using ChildSearch here is bad news 
	if (unit == 0)
	{
		CS_erpt (cs_WKT_NOGUNIT);
		goto error;
	}
	cp = unit->GetElementNameC ();
	CS_wktUnitNameFix (geogcsUnitName,sizeof (geogcsUnitName),flavor,cp);
	geogcsUnitsFactor = CS_unitlu (cs_UTYP_ANG,geogcsUnitName);
	if (geogcsUnitsFactor == 0.0)
	{
		// Name approach didn't work.  See is we can locate a CS-MAP unit name
		// using the unit factor in the WKT element.
		geogcsUnitsFactor = unit->GetFieldDouble (0);
		cp = CS_unitluByFactor (cs_UTYP_ANG,geogcsUnitsFactor);
		if (cp != 0)
		{
			CS_stncp (geogcsUnitName,cp,sizeof (geogcsUnitName));
		}
		else
		{
			geogcsUnitsFactor = 0.0;
		}
	}
	if (geogcsUnitsFactor == 0.0)
	{
		if (cp != 0)
		{
			CS_stncp (csErrnam,cp,sizeof (csErrnam));
		}
		else
		{
			CS_stncp (csErrnam,"geogcsUnitName",sizeof (csErrnam));
		}
		CS_erpt (cs_WKT_INVGUNIT);
		goto error;
	}

	if (datum != 0)
	{
		CS_stncp (csDef->dat_knm,dtDef->key_nm,sizeof (csDef->dat_knm));
	}

	primeMeridianLongitude = cs_Zero;
	primeMeridian = geogcs->ChildLocate (rcWktPrimeM);
	if (primeMeridian != 0)
	{
		// Best I can tell, Prime Meridian values are always in degrees.
		primeMeridianLongitude = primeMeridian->GetFieldDouble (0);
	}

	csDef->scl_red = cs_One;
	csDef->unit_scl = unitsFactor;
	csDef->map_scl = cs_One;
	csDef->scale = cs_One / csDef->unit_scl;
	csDef->quad = static_cast<short>(CS_wktAxisToQuad (wktElement));

	// Process the easier of the two: GEOGCS.
	if (wktElement->GetElementType () == rcWktGeogCS)
	{
		CS_stncp (csDef->prj_knm,"LL",sizeof (csDef->prj_knm));
		CS_stncp (csDef->group,"LL",sizeof (csDef->group));
		// Best I can tell, Prime Meridian values are always in degrees.
		csDef->org_lng = primeMeridianLongitude;

		// There is no range information in the WKT, so we choose the
		// CS-MAP default by leaving parameters 1 and 2 at zero.
		csDef->zero [0] = csDef->zero [1] = 1.0E-12 / csDef->unit_scl;

		csDef->ll_min [0] = cs_Km180;
		csDef->ll_min [1] = cs_Km90;
		csDef->ll_max [0] = cs_K180;
		csDef->ll_max [1] = cs_K90;

		csDef->xy_min [0] = cs_Km180 / csDef->unit_scl;
		csDef->xy_min [1] = cs_Km90  / csDef->unit_scl;
		csDef->xy_max [0] = cs_K180  / csDef->unit_scl;
		csDef->xy_max [1] = cs_K90   / csDef->unit_scl;

		CS_stncp (dtDef->source,"Extracted from WKT string; description field carries WKT name.",sizeof (dtDef->source));
		// I think we are all done for a GEOGCS.
	}
	else if (wktElement->GetElementType () == rcWktProjCS)
	{
		// Do the stuff that is common to all projected systems.  Remember,
		// we initialized the whole thing to zeros above.  Key_nm, dat_knm,
		// elp_knm, and unit have already been taken care of.
		CS_stncp (csDef->group,"USER",sizeof (csDef->group));
		parameter = wktElement->ParameterLocate (flavor,cs_WKTCOD_FEAST);
		if (parameter != 0) csDef->x_off = parameter->GetFieldDouble (0);
		parameter = wktElement->ParameterLocate (flavor,cs_WKTCOD_FNORTH);
		if (parameter != 0) csDef->y_off = parameter->GetFieldDouble (0);
		parameter = wktElement->ParameterLocate (flavor,cs_WKTCOD_ORGLNG);
		if (parameter == 0)
		{
			parameter = wktElement->ParameterLocate (flavor,cs_PRMCOD_CNTMER);
		}
		if (parameter == 0)
		{
			parameter = wktElement->ParameterLocate (flavor,cs_PRMCOD_GCPLNG);
		}
		if (parameter != 0)
		{
			csDef->org_lng = parameter->GetFieldDouble (0) * geogcsUnitsFactor + primeMeridianLongitude;
		}
		parameter = wktElement->ParameterLocate (flavor,cs_WKTCOD_ORGLAT);
		if (parameter == 0)
		{
			parameter = wktElement->ParameterLocate (flavor,cs_PRMCOD_GCPLAT);
		}
		if (parameter != 0)
		{
			csDef->org_lat = parameter->GetFieldDouble (0) * geogcsUnitsFactor;
		}
		parameter = wktElement->ParameterLocate (flavor,cs_WKTCOD_SCLRED);
		if (parameter != 0)
		{
			csDef->scl_red = parameter->GetFieldDouble (0);
		}
		csDef->zero [0] = csDef->zero [1] = 0.001 / csDef->unit_scl;

		projection = wktElement->ChildSearch (rcWktProjection);
		if (projection == 0)
		{
			CS_erpt (cs_WKT_NOPROJ);
			goto error;	
		}
		cp = projection->GetElementNameC ();
		projCode = CS_wktProjLookUp (flavor,cp);
		if (projCode == cs_PRJCOD_END)
		{
			CS_stncp (csErrnam,cp,sizeof (csErrnam));
			CS_erpt (cs_WKT_INVPROJ);
			goto error;
		}

		// Get a pointer to the CS-MAP projection table entry for the indicated
		// projection.  We can do some more general stuff once we have that.
		for (pp = cs_Prjtab;*pp->key_nm != '\0';pp++)
		{
			if (pp->code == projCode) break;
		}
		if (*pp->key_nm == '\0' || pp->setup == NULL || pp->code == cs_PRJCOD_END)
		{
			CS_stncp (csErrnam,cp,sizeof (csErrnam));
			CS_erpt (cs_WKT_INVPROJ);
			goto error;
		}
		projFlags = pp->flags;

		// Special kludge.  In certain flavors of WKT, the projection name
		// "Lambert_Conformal_Conic" is used for both the 1 pararllel and
		// 2 parallel variations.  The CS_wktProjLookUp function will
		// always return cs_PROJCOD_LM1SP (for ESRI anyway) as it is the
		// first one in the table.
		if ((flavor == wktFlvrEsri || flavor == wktFlvrOracle) &&
			(projCode == cs_PRJCOD_LM1SP || projCode == cs_PRJCOD_LM2SP)
		   )
		{
			// Here if there is a potential problem.  We determine which
			// variation of the Lambert Conformal Conic based on the
			// type of parameters available.
			parmCode = cs_PRMCOD_SSTDPLL;
			parameter = wktElement->ParameterLocate (flavor,parmCode);
			projCode = (parameter == 0) ? cs_PRJCOD_LM1SP : cs_PRJCOD_LM2SP;

			// Reset the projection table pointer.
			for (pp = cs_Prjtab;*pp->key_nm != '\0';pp++)
			{
				if (pp->code == projCode) break;
			}
			if (*pp->key_nm == '\0' || pp->setup == NULL || pp->code == cs_PRJCOD_END)
			{
				// This should never happen.
				CS_stncp (csErrnam,cp,sizeof (csErrnam));
				CS_erpt (cs_WKT_INVPROJ);
				goto error;
			}
		}

		// Another kludge.  In certain flavors of WKT, the same name is used
		// Polar Stereographic and Polar Stereographic with Standard Parallel.
		// The projection mapping code will always return cs_PRJCOD_PSTEREO
		// as that is the projection name used in the WKT.  Here we see if the
		// definition also includes a Standard Parallel 1 parameter and if
		// so, switch the projection code to cs_PSRJCOD_PSTROSL.
		//
		// Also, many flavors like to use Stereographic for all sorts of things.
		// I'm just beginning to understand the why's and wherefore's.
		// In any case, if we have parsed a Polar Stereographic, is could
		// easily mean that it is an oblique stereographic.  This can't be
		// handled in the mapping tables, as the mapping tables don't know
		// about the parameters.  Thus, we do it here in a rather elaborate
		// kludge.
		if ((flavor == wktFlvrEsri || flavor == wktFlvrOracle) &&
			(projCode == cs_PRJCOD_PSTRO)
		   )
		{
			parmValue = -90.0;
			sclRedParm = wktElement->ParameterLocate (flavor,cs_WKTCOD_SCLRED);
			orgLatParm = wktElement->ParameterLocate (flavor,cs_WKTCOD_ORGLAT);
			if (orgLatParm != 0)
			{
				parmValue = orgLatParm->GetFieldDouble (0);
			}
			if (fabs (fabs (parmValue) - 90.0) > 1.0E-02)			
			{
				// We have an Oblique Stereographic.  Note, this maps to what most of
				// the world calls the Double Stereographic.
				projCode = cs_PRJCOD_OSTRO;
			}
			else
			{
				parmCode = cs_PRMCOD_NSTDPLL;
				parameter = wktElement->ParameterLocate (flavor,parmCode);
				projCode = (parameter == 0) ? cs_PRJCOD_PSTRO : cs_PRJCOD_PSTROSL;

				// Also, these flavors of WKT often refer to (eg)
				// "Stereographic_South_Pole as a projection, thus the origin
				// latitude is implied in the projection name.  We try to deal with
				// that here.
				cp = projection->GetElementNameC ();
				if (cp != 0)
				{
					cp1 = CS_stristr (cp,"South");
					if (cp1 != 0)
					{
						csDef->org_lat = -90.0;
					}
					cp1 = CS_stristr (cp,"North");
					if (cp1 != 0)
					{
						csDef->org_lat = 90.0;
					}
				}
			}

			// Reset the projection patble pointer.
			for (pp = cs_Prjtab;*pp->key_nm != '\0';pp++)
			{
				if (pp->code == projCode) break;
			}
			if (*pp->key_nm == '\0' || pp->setup == NULL || pp->code == cs_PRJCOD_END)
			{
				// This should never happen.
				CS_stncp (csErrnam,cp,sizeof (csErrnam));
				CS_erpt (cs_WKT_INVPROJ);
				goto error;
			}
		}

		// Another special kludge.  This is to handle ESRI's (and others I
		// presume) use of the "Hotine_Oblique_Mercator_Azimuth_Center"
		// projection to do what is really the job of the "Oblique Cylindrical"
		// projection.  Essentially, if the above produced any variation of
		// the oblique mercator, and the azimuth value is +/- 90.0; then
		// we switch to the either the Swiss or Oblique Cylindrical, based
		// on whether there is a "Standard Parallel" parameter or not.
		if ((projCode >= cs_PRJCOD_RSKEW && projCode <= cs_PRJCOD_RSKEWO) ||
			 projCode == cs_PRJCOD_HOM1XY)
		{
			// One of the single point rectified Oblique Mercator specifications.
			// There most be an azimuth parameter.
			parmCode = cs_PRMCOD_GCAZM;
			parameter = wktElement->ParameterLocate (flavor,parmCode);
			if (parameter != 0)
			{
				parmValue = parameter->GetFieldDouble (0);
				parmValue *= geogcsUnitsFactor;
				if (fabs (fabs (parmValue) - 90.0) < 1.0E-04)
				{
					// OK. The azimuth value is present, and it is +/-
					// 90 degrees.  We switch to either the Swiss Cylindrical
					// or Oblique Cylindrical projection depending upon
					// the existence of a standard parallel parameter.
					parmCode = cs_PRMCOD_NRMLPLL;
					parameter = wktElement->ParameterLocate (flavor,parmCode);
					projCode = (parameter == 0) ? cs_PRJCOD_SWISS : cs_PRJCOD_OBQCYL;
					for (pp = cs_Prjtab;*pp->key_nm != '\0';pp++)
					{
						if (pp->code == projCode) break;
					}
				}
			}
		}

		// OK, back to normal.
		CS_stncp (csDef->prj_knm,pp->key_nm,sizeof (csDef->prj_knm));
		projFlags = pp->flags;

		for (mp = cs_PrjprmMap;mp->prj_code != cs_PRJCOD_END;mp += 1)
		{
			if (mp->prj_code == projCode) break;
		}
		if (mp->prj_code == cs_PRJCOD_END)
		{
			CS_stncp (csErrnam,"CS_wellKnownText.cpp:1",MAXPATH);
			CS_erpt (cs_ISER);
			goto error;
		}

		// Now for each possible parameter.
		for (parmIdx = 0;parmIdx < 24;parmIdx += 1)
		{
			parmCode = mp->prm_types [parmIdx];
			if (parmCode <= 0) break;
			// WKT (some flavors anyway) use Standard_Parallel_1 whenever
			// only one parallel is in use.
			if (parmCode == cs_PRMCOD_STDPLL) parmCode = cs_PRMCOD_NSTDPLL;
			if (parmCode == cs_PRMCOD_STDCIR) parmCode = cs_PRMCOD_NSTDPLL;
			parameter = wktElement->ParameterLocate (flavor,parmCode);
			if (parameter != 0)
			{
				dblPtr = &csDef->prj_prm1 + parmIdx;
				parmValue = parameter->GetFieldDouble (0);
				// If the logical type of this parameter is of the angle logical type,
				// we need to adjust by the geogcs unitsto convert to degrees.
				csPrjPrmPtr = &csPrjprm [parmCode];
				if (csPrjPrmPtr->log_type == cs_PRMLTYP_LNG ||
					csPrjPrmPtr->log_type == cs_PRMLTYP_LAT ||
					csPrjPrmPtr->log_type == cs_PRMLTYP_AZM ||
					csPrjPrmPtr->log_type == cs_PRMLTYP_ANGD)
				{
					parmValue *= geogcsUnitsFactor;
				}
				if (csPrjPrmPtr->log_type == cs_PRMLTYP_LNG)
				{
					parmValue += primeMeridianLongitude;
				}
				*dblPtr = parmValue;
			}
		}

		// The above is supposed to work for all projections, all parameters.
		// When working with WKT, we know better than that.  Here below we
		// make provisions fot twiddleing as necessary on a projection by
		// projection basis.
		switch (projCode) {
		case cs_PRJCOD_TRMER:
			break;
		case cs_PRJCOD_LM1SP:
			parmValue = csDef->org_lat;
			parameter = wktElement->ParameterLocate (flavor,cs_PRMCOD_NSTDPLL);
			if (parameter != 0)
			{
				parmValue = parameter->GetFieldDouble (0);
				parmValue *= geogcsUnitsFactor;
			}
			if (!CS_cmpDbls (parmValue,csDef->org_lat))
			{
				CS_stncp (csErrnam,csDef->key_nm,sizeof (csErrnam));
				CS_erpt (cs_WKT_PRMSUPRT);
				goto error;
			}
			break;
		case cs_PRJCOD_LM2SP:
			break;
		case cs_PRJCOD_ALBER:
			break;
		case cs_PRJCOD_MRCAT:
			break;
		case cs_PRJCOD_AZMED:
			break;
		case cs_PRJCOD_PLYCN:
			break;
		case cs_PRJCOD_AZMEA:
			break;
		case cs_PRJCOD_EDCNC:
			break;
		case cs_PRJCOD_MILLR:
			break;
		case cs_PRJCOD_NZLND:
			break;
		case cs_PRJCOD_SINUS:
			break;
		case cs_PRJCOD_EDCYL:
			break;
		case cs_PRJCOD_VDGRN:
			break;
		case cs_PRJCOD_CSINI:
			break;
		case cs_PRJCOD_ROBIN:
			break;
		case cs_PRJCOD_BONNE:
			break;
		case cs_PRJCOD_EKRT4:
			break;
		case cs_PRJCOD_EKRT6:
			break;
		case cs_PRJCOD_MOLWD:
			break;
		case cs_PRJCOD_OSTRO:
			break;
		case cs_PRJCOD_HOM1XY:
			break;
		case cs_PRJCOD_HOM2XY:
			break;
		default:
			break;
		}
	}

	authority = wktElement->ChildLocate (rcWktAuthority);
	if (authority != 0)
	{
		long epsgCode;

		cp = authority->GetElementNameC ();
		if (cp == 0 || *cp == '\0') cp = "EPSG";
		epsgCode = authority->GetFieldLong (0);
		csDef->epsgNbr = static_cast<short>(epsgCode);
		sprintf (reducedName,"%s:%ld",cp,epsgCode);
		CS_stncp (csDef->key_nm,reducedName,sizeof (csDef->key_nm));
	}

	CS_stncp (csDef->source,"Extracted from WKT string; description field carries WKT name.",sizeof (csDef->source));

	// Hopefully, that's it.
	if (strlen (reducedName) > cs_KEYNM_MAX) status |= cs_CS2WKT_NMTRUNC;
	return status;
error:
	// Delete, free, whatever stuff is necessary; none just yet.
	return -1;
}
int EXP_LVL1 CS_wktToDict (const char *csKeyName,const char *dtKeyName,const char *elKeyName,const char *wellKnownText,int flavor)
{
	int rtnValue = -1;

	struct cs_Csdef_ csDef;
	struct cs_Dtdef_ dtDef;
	struct cs_Eldef_ elDef;

	rtnValue = CS_wktToCs (&csDef,&dtDef,&elDef,(ErcWktFlavor)flavor,wellKnownText);
	if (rtnValue >= 0)
	{
		if (elKeyName != 0 && *elKeyName != '\0')
		{
			CS_stncp (elDef.key_nm,elKeyName,sizeof (elDef.key_nm));
			rtnValue = CS_elupd (&elDef,0);
		}
		if (rtnValue == 0 && dtKeyName != 0 && *dtKeyName != '\0')
		{
			CS_stncp (dtDef.key_nm,dtKeyName,sizeof (dtDef.key_nm));
			rtnValue = CS_dtupd (&dtDef,0);
		}
		if (rtnValue == 0 && csKeyName != 0 && *csKeyName != '\0')
		{
			CS_stncp (csDef.key_nm,csKeyName,sizeof (csDef.key_nm));
			rtnValue = CS_csupd (&csDef,0);
		}
	}
	return rtnValue;
}
//newPage//
// Use this function to extract a cs_Dtdef_ and cs_Eldef_ structure from a
// pre-parsed DATUM WKT element.  If the provided definition does not have
// a TOWGS84 sub-element, a default datum definition with the datum and
// ellipsoid names set, but a to84_via value of cs_DTCTYP_NONE.
//
// Normally, a zero value is returned to indicate success.  A negative
// value is returned for a hard failure, use CS_errmsg to get a desrciption.
// The returned value, if positive, will have the cs_DT2WKT_DTDEF bit set in
// the event that the datum name was that of a datum already defined in the
// CS-MAP dictionary, and that very definition is returned in the location
// pointed to by the dtDef argument.  The cs_DT2WKT_NODEF is set in a positive
// return value to indicate that there was no specific datum definition in the
// WKT string and a dictionary lookup on the datum name provided failed.  That
// is, the  returned if the cs_DT2WKT_NODEF bit is set if there is no real
// datum definition in the WKT string, which is quite common.
//
// The cs_DT2WKT_NMTRUNC bit is set in a positive return value if the adjusted
// datum name was longer than what a CS-MAP key name can accomodate, i.e. the
// key name field contains a truncated value.  Note, if an EPSG number is available,
// the name will have the form of EPSG:####, and a zero value will be returned.
// It is assumed that an Authority WKT element will carry the appropriate
// EPSG number.
//
// The following function is, usually, not given a pointer to a full element;
// only the Datum element of a larger definition.  Thus, it is erroneous to
// expect this function to be able to determine the flavor of the WKT string
// being processed.
int CS_wktEleToDt (struct cs_Dtdef_ *dtDef,struct cs_Eldef_ *elDef,
										   ErcWktFlavor flavor,
										   const TrcWktElement* wktPtr)
{
	int status = 0;
	const char *cp;
	const char* namePtr;
	char datumName [64];

	// These are all constant pointers to sub-elements of the main wktElement
	// object declared below.  Do not delete these.
	const TrcWktElement* spheroid;
	const TrcWktElement* toWgs84;
	const TrcWktElement* authority;

	struct cs_Eldef_ myElDef;
	memset (&myElDef,0,sizeof (myElDef));

	if (elDef == 0) elDef = &myElDef;
	if (dtDef != 0)
	{
		memset (dtDef,'\0',sizeof (*dtDef));
	}
	if (wktPtr == 0)
	{
		// We report his as fatal, it's not supposed to happen.
		CS_erpt (cs_WKT_NODATUM);
		goto error;
	}

	// We only process DATUM objects.
	if (wktPtr->GetElementType () != rcWktDatum)
	{
		CS_erpt (cs_WKT_WRNGTYP);
		goto error;
	}

	// Take care of the ellipsoid portion.  This is rather simple, and applies
	// to most any WKT object.  ChildSearch searches the entire tree structure
	// of the element.  CS_wktEleToEl can handle a null pointer correctly.
	spheroid = wktPtr->ChildSearch (rcWktSpheroid);
	status |= CS_wktEleToEl (elDef,flavor,spheroid);
	if (status < 0)
	{
		goto error;
	}

	// Some basic stuff in preparation for doing the cs_Dtdef_ portion.
	cp = wktPtr->GetElementNameC ();
	CS_stncp (dtDef->name,cp,sizeof (dtDef->name));
	CS_wktDtNameFix (datumName,sizeof (datumName),cp);
	CS_stncp (dtDef->key_nm,datumName,sizeof (dtDef->key_nm));

	// Set the stuff independent of the TOWGS84 element.
	CS_stncp (dtDef->ell_knm,elDef->key_nm,sizeof (dtDef->ell_knm));
	dtDef->group  [0]   = '\0';
	dtDef->locatn [0]   = '\0';
	dtDef->cntry_st [0] = '\0';
	dtDef->delta_X = cs_Zero;
	dtDef->delta_Y = cs_Zero;
	dtDef->delta_Z = cs_Zero;
	dtDef->rot_X   = cs_Zero;
	dtDef->rot_Y   = cs_Zero;
	dtDef->rot_Z   = cs_Zero;
	dtDef->bwscale = cs_Zero;
	dtDef->source [0]   = '\0';
	dtDef->to84_via = cs_DTCTYP_NONE;
	dtDef->protect = 0;
	dtDef->epsgNbr = 0;
	dtDef->wktFlvr = static_cast<short>(flavor);

	// Process the TOWGS84 element if its there.
	toWgs84 = wktPtr->ChildSearch (rcWktToWgs84);
	if (toWgs84 != 0)
	{
		dtDef->delta_X = toWgs84->GetFieldDouble (0);
		dtDef->delta_Y = toWgs84->GetFieldDouble (1);
		dtDef->delta_Z = toWgs84->GetFieldDouble (2);
		dtDef->rot_X   = toWgs84->GetFieldDouble (3);
		dtDef->rot_Y   = toWgs84->GetFieldDouble (4);
		dtDef->rot_Z   = toWgs84->GetFieldDouble (5);
		dtDef->bwscale = toWgs84->GetFieldDouble (6);

		// Set the appropriate method value.
		int rotCnt = 0;
		if (dtDef->rot_X != 0.0) rotCnt += 1;
		if (dtDef->rot_Y != 0.0) rotCnt += 1;
		if (dtDef->rot_Z != 0.0) rotCnt += 1;

		int deltaCnt = 0;
		if (dtDef->delta_X != 0.0) deltaCnt += 1;
		if (dtDef->delta_Y != 0.0) deltaCnt += 1;
		if (dtDef->delta_Z != 0.0) deltaCnt += 1;

		int sclCnt = 0;
		if (dtDef->bwscale != 0.0) sclCnt += 1;

		if      (rotCnt != 0  ) dtDef->to84_via = cs_DTCTYP_7PARM;
		else if (sclCnt != 0  ) dtDef->to84_via = cs_DTCTYP_4PARM;
		else if (deltaCnt != 0) dtDef->to84_via = cs_DTCTYP_MOLO;
		else                    dtDef->to84_via = cs_DTCTYP_WGS84;
		CS_stncp (dtDef->source,"Extracted from WKT string; description field carries WKT name.",sizeof (dtDef->source));
	}
	else
	{
		// There was no TOWGS84 element, so this WKT definition has no
		// datum definition.  If it doesn't have a name, we report it as an
		// error.  Otherwise, we let the calling module deal with it.
		namePtr = wktPtr->GetElementNameC ();
		if (namePtr == 0)
		{
			// This doesn't work if the datum doesn't have a name.
			CS_erpt (cs_WKT_NODTMNM);
			goto error;
		}
		status |= cs_DT2WKT_NODEF;
		CS_stncp (dtDef->source,"Name extracted from WKT, no definition present.",sizeof (dtDef->source));
	}

	// See if this WKT datum has an AUTHORITY element.  If so, there may
	// be a valid EPSG datum number in it.  This is valuable information.
	// We save it in epsgNbr for the calling module.
	authority = wktPtr->ChildLocate (rcWktAuthority);
	if (authority != 0)
	{
		long epsgCode;

		cp = authority->GetElementNameC ();
		if (cp == 0 || *cp == '\0') cp = "EPSG";
		epsgCode = authority->GetFieldLong (0);
		dtDef->epsgNbr = static_cast<short>(epsgCode);
		sprintf (datumName,"%s:%ld",cp,epsgCode);
		CS_stncp (dtDef->key_nm,datumName,sizeof (dtDef->key_nm));
	}

	// Hopefully, that's it.
	if (strlen (datumName) > cs_KEYNM_MAX) status |= cs_DT2WKT_NMTRUNC;
	return status;
error:
	// Delete, free, whatever stuff is necessary; none just yet.
	return -1;
}
//newPage//
// Use this function to extract a cs_Eldef_ structure from a pre-parsed
// SPHEROID WKT element.  This is pretty straight forward stuff.
//
// The following function returns the MSI equivalent to a WKT ellipsoid
// definition.  No mapping occurs.  The returned value is a faithful
// rendition (in CS-MAP form) of what was in the WKT string.  We can do this
// as the WKT definition of ellipsoids is always complete, and there are no
// mapping problems such as unsupported projections.
int CS_wktEleToEl (struct cs_Eldef_ *elDef,ErcWktFlavor flavor,const TrcWktElement* wktPtr)
{
	int status = 0;
	const char *cp;
	double tempValue;
	char ellipsoidName [64];
	const TrcWktElement* authority;

	memset (elDef,'\0',sizeof (*elDef));
	if (wktPtr == 0)
	{
		// We deal with the case where the calling module didn't find a
		// SPHEROID element.	
		elDef->key_nm [0] = '\0';
		elDef->group [0] = '\0';
		CS_stncp (ellipsoidName,"<unspecified>",sizeof (ellipsoidName));
		CS_stncp (elDef->name,ellipsoidName,sizeof (elDef->name));
		CS_stncp (elDef->source,"<definition not supplied>",sizeof (elDef->source));
		elDef->e_rad = cs_Zero;
		elDef->p_rad = cs_Zero;
		elDef->flat  = cs_Zero;
		elDef->ecent = cs_Zero;
		elDef->protect = 0;
		elDef->epsgNbr = 0;
		elDef->wktFlvr = static_cast<short>(flavor);

		// We report his as fatal, it's not supposed to happen.
		CS_erpt (cs_WKT_NOELLIP);
		goto error;
	}
	else
	{
		// We only process SPHEROID objects.
		if (wktPtr->GetElementType () != rcWktSpheroid)
		{
			CS_erpt (cs_WKT_WRNGTYP);
			goto error;
		}

		elDef->p_rad = cs_Zero;
		elDef->flat  = cs_Zero;
		elDef->ecent = cs_Zero;

		// Set the ellipsoid key name to the first 23 characters of the WKT
		// spheroid name.  It is likely that this will be adjusted below.
		cp = wktPtr->GetElementNameC ();
		
		// Save the entire WKT ellipsoid name in the descriptive name field
		// of the ellipsoid definition structure.  We will want to have this
		// available to us later on.
		CS_stncp (elDef->name,cp,sizeof (elDef->name));
		
		// Use some standard trickery to reduce the size of the ellipsoid
		// name to the 23 character maximum supported by CS-MAP.
		CS_wktElNameFix (ellipsoidName,sizeof (ellipsoidName),cp);
		CS_stncp (elDef->key_nm,ellipsoidName,sizeof (elDef->key_nm));
		
		// Extract the numeric values from the WKT element.  tempValue
		// is the reciprocal of the flattening.
		elDef->e_rad = wktPtr->GetFieldDouble (0);
		tempValue  = wktPtr->GetFieldDouble (1);
		
		if (elDef->e_rad < cs_One)
		{
			// Something is very wrong.
			CS_erpt (cs_WKT_NOELLIP);
			goto error;
		}
	
		// Some flavors of WKT use a huge value for the reciprocal of
		// flattening to indicate a sphere instead of an ellipsoid.  We
		// try to honor that here.
		if (tempValue > 1.0E+03)
		{
			elDef->p_rad = elDef->e_rad;
			elDef->ecent = cs_Zero;
			elDef->flat = cs_Zero;
		}
		// Since tempValue is the reciprocal of the flattening, we need to
		// divide by it.  Make sure we don't divide by zero.
		else if (tempValue > 0.1)
		{
			elDef->flat  = cs_One / tempValue;
			elDef->p_rad = elDef->e_rad * (cs_One - elDef->flat);
			tempValue = ((elDef->e_rad * elDef->e_rad) - (elDef->p_rad * elDef->p_rad));
			tempValue /= (elDef->e_rad * elDef->e_rad);
			elDef->ecent = sqrt (tempValue);
		}
		else
		{
			// Here if the reciprocal of flattening value is absurd, like
			// sero or negative.  We essentially assume a sphere.  Maybe we
			// should produce a fatal error.
			elDef->p_rad = elDef->e_rad;
			elDef->ecent = cs_Zero;
			elDef->flat = cs_Zero;
		}
		elDef->protect = 0;
		elDef->wktFlvr = static_cast<short>(flavor);

		// If there is an AUTHORITY specification, we us it to name
		// this ellipsoid.
		authority = wktPtr->ChildLocate (rcWktAuthority);
		if (authority != 0)
		{
			long epsgCode;

			cp = authority->GetElementNameC ();
			if (cp == 0 || *cp == '\0') cp = "EPSG";
			epsgCode = authority->GetFieldLong (0);
			elDef->epsgNbr = static_cast<short>(epsgCode);
			sprintf (ellipsoidName,"%s:%ld",cp,epsgCode);
			CS_stncp (elDef->key_nm,ellipsoidName,sizeof (elDef->key_nm));
		}
	}
	CS_stncp (elDef->source,"Extracted from WKT string; 'Description' is full WKT name.",sizeof (elDef->source));
	if (strlen (ellipsoidName) > cs_KEYNM_MAX) status |= cs_EL2WKT_NMTRUNC;
	return status;
error:
	return -cs_Errno;
}
//newPage//
///////////////////////////////////////////////////////////////////////////////
// The following converts a WKT GEOTRANS object to CS-MAP format in the form
// of a cs_Dtdef_ and cs_Eldef_ structures.  If you have the newer format
// where the Datum element in the PROJCS element has the TOWGS84 element,
// simply use CS_wktToCs and convert the whole mess in one shot.  Use this
// function only when dealing with the older GEOTRAN WKT type string.
int CS_wktToDt (struct cs_Dtdef_ *dtDef,struct cs_Eldef_ *elDef,ErcWktFlavor flavor,const char *wellKnownText)
{
	int status;
	int rotCnt = 0;
	int deltaCnt = 0;
	int sclCnt = 0;
	size_t index = 0;

	const char *cp;
	const char *cpName;

	// These are all constant pointers to sub-elements of the main wktElement
	// object declared below.  Do not delete these.
	const TrcWktElement *datum;
	const TrcWktElement *method;
	const TrcWktElement *parameter;
	const TrcWktElement *srcGeogCS;
	const TrcWktElement *trgGeogCS;

	struct cs_Dtdef_ myDtDef;
	struct cs_Eldef_ myElDef;

	// The user should always provide a dtDef argument.  The elDef argument is
	// optional.  In any case, let's prevent a crash.
	if (dtDef == 0) dtDef = &myDtDef;
	if (elDef == 0) elDef = &myElDef;

	// Prepare for any kind of error; make sure the results are unusable.
	memset (dtDef,'\0',sizeof (*dtDef));
	CS_stncp (dtDef->key_nm,"<error>",sizeof (dtDef->key_nm));
	CS_stncp (dtDef->ell_knm,"<unknown>",sizeof (dtDef->ell_knm));
	dtDef->to84_via = cs_DTCTYP_NONE;
	memset (elDef,'\0',sizeof (*elDef));
	CS_stncp (elDef->key_nm,"<error>",sizeof (elDef->key_nm));

	// Convert the text string to TrcWktElement form.  This object will get
	// deleted automatically as soon as it goes out of scope.
	TrcWktElement wktElement (wellKnownText);
	wktElement.ParseChildren ();

	// We only process GEOTRAN objects.
	if (wktElement.GetElementType () != rcWktGeogTran)
	{
		CS_erpt (cs_WKT_WRNGTYP);
		goto error;
	}
	cpName = wktElement.GetElementNameC ();

	// Determine the flavor if the calling application has not specified it.
	if (flavor == wktFlvrNone)
	{
		flavor = wktElement.DetermineFlavor ();
		if (flavor == wktFlvrUnknown)
		{
			CS_stncp (csErrnam,cpName,MAXPATH);
			CS_erpt (cs_WKT_FLAVOR);
		}
	}

	// We can only deal with GEOTRAN's which convert from something to
	// WGS84.  Therefore, we get the first GEOGCS object (that's where we get
	// the actual datum name and the spheroid), and then the second
	// an verify that the datum name is "WGS84" (actually "WGS_1984").
	srcGeogCS = wktElement.ChildLocate (rcWktGeogCS,index);
	trgGeogCS = wktElement.ChildLocate (rcWktGeogCS,index);
	if (srcGeogCS == 0 || trgGeogCS == 0)
	{
		CS_stncp (csErrnam,cpName,sizeof (csErrnam));
		CS_erpt (cs_WKT_GEOGCNT);
		goto error;
	}
	cp = trgGeogCS->GetElementNameC ();
	
	// Verify that the target is WGS84.  "GCS_WGS_1984" is what will
	// be there in an ESRI GEOTRAN.  Currently, we don't know what would be
	// present in any other flavor (as we've never seen a GEOTRAN from any
	// other source.
	if (CS_stricmp (cp,"GCS_WGS_1984"))
	{
		CS_stncp (csErrnam,cpName,sizeof (csErrnam));
		CS_erpt (cs_WKT_WRNGTRG);
		goto error;
	}

	// OK, we should be able to do something with this.  We process the normal
	// datum and ellipsoid stuff.
	datum = srcGeogCS->ChildSearch (rcWktDatum);
	if (datum == 0)
	{
		CS_stncp (csErrnam,cpName,sizeof (csErrnam));
		CS_erpt (cs_WKT_NOSRCDT);
		goto error;
	}
	status = CS_wktEleToDt (dtDef,elDef,flavor,datum);
	if (status < 0) goto error;

	// The TOWGS84 element will not be there.  Process the parameters.  We'll
	// deal with the method after all parameter values have been extracted.
	parameter = wktElement.ParameterLocate (flavor,cs_WKTCOD_DELTAX);
	dtDef->delta_X = (parameter != 0) ? parameter->GetFieldDouble (0) : cs_Zero;
	parameter = wktElement.ParameterLocate (flavor,cs_WKTCOD_DELTAY);
	dtDef->delta_Y = (parameter != 0) ? parameter->GetFieldDouble (0) : cs_Zero;
	parameter = wktElement.ParameterLocate (flavor,cs_WKTCOD_DELTAZ);
	dtDef->delta_Z = (parameter != 0) ? parameter->GetFieldDouble (0) : cs_Zero;

	parameter = wktElement.ParameterLocate (flavor,cs_WKTCOD_ROTATX);
	dtDef->rot_X = (parameter != 0) ? parameter->GetFieldDouble (0) : cs_Zero;
	parameter = wktElement.ParameterLocate (flavor,cs_WKTCOD_ROTATY);
	dtDef->rot_Y = (parameter != 0) ? parameter->GetFieldDouble (0) : cs_Zero;
	parameter = wktElement.ParameterLocate (flavor,cs_WKTCOD_ROTATZ);
	dtDef->rot_Z = (parameter != 0) ? parameter->GetFieldDouble (0) : cs_Zero;

	parameter = wktElement.ParameterLocate (flavor,cs_WKTCOD_BWSCAL);
	dtDef->bwscale = (parameter != 0) ? parameter->GetFieldDouble (0) : cs_Zero;

	// Set the appropriate method value based on the number and type of
	// parameters present.  We'll adjust for METHOD later.
	if (dtDef->rot_X != 0.0) rotCnt += 1;
	if (dtDef->rot_Y != 0.0) rotCnt += 1;
	if (dtDef->rot_Z != 0.0) rotCnt += 1;

	if (dtDef->delta_X != 0.0) deltaCnt += 1;
	if (dtDef->delta_Y != 0.0) deltaCnt += 1;
	if (dtDef->delta_Z != 0.0) deltaCnt += 1;

	if (dtDef->bwscale != 0.0) sclCnt += 1;

	if      (rotCnt != 0  ) dtDef->to84_via = cs_DTCTYP_7PARM;
	else if (sclCnt != 0  ) dtDef->to84_via = cs_DTCTYP_4PARM;
	else if (deltaCnt != 0) dtDef->to84_via = cs_DTCTYP_MOLO;
	else                    dtDef->to84_via = cs_DTCTYP_WGS84;

	// OK, get the method and see if we should do anything to what we have
	// already determined.
	method = wktElement.ChildLocate (rcWktMethod);
	if (method == 0)
	{
		CS_stncp (csErrnam,cpName,sizeof (csErrnam));
		CS_erpt (cs_WKT_NOMETH);
		goto error;
	}
	cp = method->GetElementNameC ();
	if (!CS_stricmp (cp,"Geocentric_Translation"))
	{
		if (dtDef->to84_via != cs_DTCTYP_MOLO)
		{
			CS_stncp (csErrnam,cpName,sizeof (csErrnam));
			CS_erpt (cs_WKT_MTHERR);
			goto error;
		}		
		dtDef->rot_X   = cs_Zero;
		dtDef->rot_Y   = cs_Zero;
		dtDef->rot_Z   = cs_Zero;
		dtDef->bwscale = cs_Zero;
	}
	else if (!CS_stricmp (cp,"Position_Vector"))
	{
		if (dtDef->to84_via != cs_DTCTYP_7PARM)
		{
			CS_stncp (csErrnam,cpName,sizeof (csErrnam));
			CS_erpt (cs_WKT_MTHERR);
			goto error;
		}		
		dtDef->rot_X = -dtDef->rot_X;
		dtDef->rot_Y = -dtDef->rot_Y;
		dtDef->rot_Z = -dtDef->rot_Z;
	}
	else if (!CS_stricmp (cp,"Coordinate_Frame"))
	{
		if (dtDef->to84_via != cs_DTCTYP_7PARM)
		{
			CS_stncp (csErrnam,cpName,sizeof (csErrnam));
			CS_erpt (cs_WKT_MTHERR);
			goto error;
		}		
	}
	else
	{
		CS_stncp (csErrnam,cpName,sizeof (csErrnam));
		CS_erpt (cs_WKT_UKMETH);
		goto error;
	}
	return status;

error:
	// Delete, free, whatever stuff is necessary; none just yet.
	return -cs_Errno;
}
// Use this function to replace any of the supplied definitions with
// definitions from the CS-MAP Dictionaries if they do exist.  That is,
// for each definition parameter which is not zero, look the name up in
// the appropriate dictionary and replace the definition if an entry
// with the appropriate name in the dictionary already exists.
//
// The function returns -1 for a hard error.  A bit map of the substitutions
// made is returned in the case of success.  The bit map values are:
// 1 --> ellipsoid definition
// 2 --> datumn definition
// 4 --> coordinate definition.
//
// This implies that zero is returned if no subsitutions are made.
//
extern "C" int cs_Error;
int CS_wktDictRpl (struct cs_Csdef_ *csDef,struct cs_Dtdef_ *dtDef,struct cs_Eldef_ *elDef)
{

	int status;
	struct cs_Csdef_ *csPtr;
	struct cs_Dtdef_ *dtPtr;
	struct cs_Eldef_ *elPtr;
	
	status = 0;
	if (csDef != 0)
	{
		csPtr = CS_csdef (csDef->key_nm);
		if (csPtr != 0)
		{
			memcpy (csDef,csPtr,sizeof (*csDef));
			CS_free (csPtr);
			status |= 4;
		}
		else if (cs_Error != cs_CS_NOT_FND)
		{
			status = -1;
		}
	}
	if (status >= 0 && dtDef != 0)
	{
		dtPtr = CS_dtdef (dtDef->key_nm);
		if (dtPtr != 0)
		{
			memcpy (dtDef,dtPtr,sizeof (*dtDef));
			CS_free (dtPtr);
			status |= 2;
		}
		else if (cs_Error != cs_DT_NOT_FND)
		{
			status = -1;
		}
	}
	if (status >= 0 && elDef != 0)
	{
		elPtr = CS_eldef (elDef->key_nm);
		if (elPtr != 0)
		{
			memcpy (elDef,elPtr,sizeof (*elDef));
			CS_free (elPtr);
			status |= 1;
		}
		else if (cs_Error != cs_EL_NOT_FND)
		{
			status = -1;
		}
	}
	return status;
}
#endif
