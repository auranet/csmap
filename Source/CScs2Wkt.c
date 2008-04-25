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

			 File Name: $RCSfile: CScs2Wkt.c $
		   Description:
			   Purpose:	Converts the supplied coordinate system dictionary
						to an ASCII representation suitable for compilation;
						writing the definition to the provided stream.

		Revision Level:	$Revision: #14 $
		 Check In Date:	$Date: 2007/01/11 $

		Last Revision:	$Log: CScs2Wkt.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:03  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:06  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:03  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:12  nto
		Last Revision:	Revision 11.902  2004/10/07 02:35:06  nto
		Last Revision:	Replace the old table driven base CS with CSllCsFromDt.
		Last Revision:	Revision 11.901  2004/08/07 03:34:30  nto
		Last Revision:	Added CS_cs2Wkt, a high level version of CScs2Wkt.
		Last Revision:	Revision 11.900  2004/03/26 17:02:20  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:08  nto
		Last Revision:	Revision 11.701  2004/01/13 20:37:28  nto
		Last Revision:	Fixed the base coordinate system for EPSG coordinate systems.
		Last Revision:	Revision 11.700  2003/12/19 01:49:48  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.601  2003/12/19 01:00:15  nto
		Last Revision:	Removes duplicate check for Orthographic.
		Last Revision:	Revision 11.600  2003/12/04 02:46:23  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 1.3  2003/11/24 01:14:23  nto
		Last Revision:	Major modifications to fix several problems.
		Last Revision:	Revision 1.2  2003/11/07 03:57:06  nto
		Last Revision:	Modified major portions to add the flavor capability to WKT outout.
		Last Revision:	Revision 1.1  2003/10/01 22:09:42  nto
		Last Revision:	Initial Revision

	 Calling Sequence:	st = CS_Cs2Xml (cs_def,fstr_out);
	struct cs_Csdef_ *cs_def;
						the definition which os to be converted to ASCII
						form.
	FILE *fstr_out;		the stream to which the converted result is to
						be written.
	int st;				returns zero on success, -1 on I/O error on the
						stream.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CScs2Wkt.c#14 $"};
#endif

#include "cs_map.h"
#include "cs_wkt.h"

int EXP_LVL1 CS_cs2WktEx (char *bufr,size_t bufrSize,const char *csKeyName,int flavor,unsigned short flags)
{
	int rtnValue = -1;
	struct cs_Dtdef_ *dtDefPtr = 0;
	struct cs_Eldef_ *elDefPtr = 0;
	struct cs_Csdef_ *csDefPtr = 0;
	
	if (bufrSize > 0)
	{
		*bufr = '\0';
		csDefPtr = CS_csdef (csKeyName);
		if (csDefPtr != 0)
		{
			if (csDefPtr->dat_knm [0] == '\0')
			{
				CS_erpt (cs_WKT_NODTREF);
			}
			else
			{
				dtDefPtr = CS_dtdef (csDefPtr->dat_knm);
				if (dtDefPtr != 0)
				{
					elDefPtr = CS_eldef (dtDefPtr->ell_knm);
					if (elDefPtr != 0)
					{
						rtnValue = CScs2WktEx (bufr,bufrSize,flavor,csDefPtr,dtDefPtr,elDefPtr,flags);	/*lint !e64 */
						CS_free (elDefPtr);
						elDefPtr = 0;
					}
					CS_free (dtDefPtr);
					dtDefPtr = 0;
				}
			}
			CS_free (csDefPtr);
			csDefPtr = 0;
		}
	}
	return rtnValue;		
}

int EXP_LVL1 CS_cs2Wkt (char *bufr,size_t bufrSize,const char *csKeyName,int flavor)
{
	int rtnValue = -1;
	
	const char* flavoredCsNamePtr = 0;
	const char* flavoredDtNamePtr = 0;
	const char* flavoredElNamePtr = 0;
	const char* msiCsNamePtr      = 0;
	const char* msiDtNamePtr      = 0;
	const char* msiElNamePtr      = 0; 

	struct cs_Dtdef_ *dtDefPtr = 0;
	struct cs_Eldef_ *elDefPtr = 0;
	struct cs_Csdef_ *csDefPtr = 0;
	
	if (bufrSize > 0)
	{
		*bufr = '\0';
		csDefPtr = CS_csdef (csKeyName);
		if (csDefPtr != 0)
		{
			if (csDefPtr->dat_knm [0] == '\0')
			{
				CS_erpt (cs_WKT_NODTREF);
			}
			else
			{
				dtDefPtr = CS_dtdef (csDefPtr->dat_knm);
				if (dtDefPtr != 0)
				{
					elDefPtr = CS_eldef (dtDefPtr->ell_knm);
					if (elDefPtr != 0)
					{
						msiCsNamePtr = csDefPtr->key_nm;
						msiDtNamePtr = dtDefPtr->key_nm;
						msiElNamePtr = elDefPtr->key_nm;

						/* now flavor that name */
						if (flavor == wktFlvrEsri)
						{
							if (msiCsNamePtr != 0)						/*lint !e774 */
							{
								flavoredCsNamePtr = CS_msiName2Esri(msiCsNamePtr);
							}
							if (msiDtNamePtr != 0)						/*lint !e774 */
							{
								flavoredDtNamePtr = CS_msiDtmName2Esri(msiDtNamePtr, 0);
							}
							if (msiElNamePtr != 0)						/*lint !e774 */
							{
								flavoredElNamePtr = CS_msiElpName2Esri(msiElNamePtr);
							}
						}
						else if (flavor == wktFlvrOracle)
						{
							if (msiCsNamePtr != 0)						/*lint !e774 */
							{
								flavoredCsNamePtr=CS_msiName2Oracle(msiCsNamePtr);
							}
							if (msiDtNamePtr != 0)						/*lint !e774 */
							{
								flavoredDtNamePtr=CS_msiDtmName2Oracle(msiDtNamePtr, 0);
							}
							if (msiElNamePtr != 0)						/*lint !e774 */
							{
								flavoredElNamePtr=CS_msiElpName2Oracle(msiElNamePtr);
							}
						}
						if (flavoredCsNamePtr != 0)
						{
							CS_stncp (csDefPtr->key_nm,flavoredCsNamePtr,cs_KEYNM_MAX);
						}
						if (flavoredDtNamePtr != 0)
						{
							CS_stncp (csDefPtr->dat_knm,flavoredDtNamePtr,cs_KEYNM_MAX);
							CS_stncp (dtDefPtr->key_nm,flavoredDtNamePtr,cs_KEYNM_MAX);
						}
						if (flavoredElNamePtr != 0)
						{
							CS_stncp (dtDefPtr->ell_knm,flavoredElNamePtr,cs_KEYNM_MAX);
							CS_stncp (elDefPtr->key_nm,flavoredElNamePtr,cs_KEYNM_MAX);
						}

						rtnValue = CScs2Wkt (bufr,bufrSize,flavor,csDefPtr,dtDefPtr,elDefPtr);	/*lint !e64 */
						CS_free (elDefPtr);
						elDefPtr = 0;
					}
					CS_free (dtDefPtr);
					dtDefPtr = 0;
				}
			}
			CS_free (csDefPtr);
			csDefPtr = 0;
		}
	}
	return rtnValue;
}

int EXP_LVL3 CScs2Wkt (char *csWktBufr,size_t bufrSize,enum ErcWktFlavor flavor,const struct cs_Csdef_ *cs_def,const struct cs_Dtdef_ *dt_def,const struct cs_Eldef_ *el_def)
{
	int st;
	unsigned short flags;

	flags = 0;
	st = CScs2WktEx (csWktBufr,bufrSize,flavor,cs_def,dt_def,el_def,flags);
	return st;
}
int EXP_LVL3 CScs2WktEx (char *csWktBufr,size_t bufrSize,enum ErcWktFlavor flavor,const struct cs_Csdef_ *cs_def,const struct cs_Dtdef_ *dt_def,const struct cs_Eldef_ *el_def,unsigned short flags)
{
	extern double cs_One;
	extern double cs_K90;
	extern double cs_Degree;
	extern char csErrnam [];
	extern struct cs_Prjtab_ cs_Prjtab [];

	int status;
	short prjCode;

	double tmpDbl;
	double primeMer;
	double unitFactor;

	const char *kCp;
	const char *prjNmPtr;

	const char *prmNmFalseEasting;
	const char *prmNmFalseNorthing;
	const char *prmNmScaleFactor;
	const char *prmNmCentralMeridian;
	const char *prmNmLatitudeOfOrigin;
	const char *prmNmStandardParallel1;
	const char *prmNmStandardParallel2;
	const char *prmNmYAxisAzimuth;
	const char *prmNmAzimuth;
	const char *prmNmLongitudeOfCenter;
	const char *prmNmLatitudeOfCenter;
	const char *prmNmLongitudeOf1stPoint;
	const char *prmNmLatitudeOf1stPoint;
	const char *prmNmLongitudeOf2ndPoint;
	const char *prmNmLatitudeOf2ndPoint;
	const char *prmNmLatitudeOfStdParall;

	struct cs_Dtdef_ *dtDefPtr;
	struct cs_Prjtab_ *prjPtr;

	char refDtmName [24];
	char baseName [24];
	char cTemp [64];

	char datmWkt [512];
	char pmerWkt [512];
	char geogWkt [512];
	char parmWkt [512];
	char unitWkt [128];
	char projWkt [1024];
	char geoAxis [1024];
	char prjAxis [1024];
	char geoTranWkt [1024];
	char projection [64];
	char gcsName [128];
	char dtmName [128];
	char csysWktName [96];
	
	status = 0;
	refDtmName [0] = '\0';
	dtDefPtr = 0;

	if (cs_def == 0)
	{
		CS_stncp (csErrnam,"CS_cs2Wkt:1",MAXPATH);
		CS_erpt (cs_ISER);
		goto error;
	}

	/* Make sure we have a datum pointer. */
	if (dt_def == NULL)
	{
		/* The calling application did not provide a specific datum definition.
		   We use the datum name in the Coordinate System definition to obtain
		   a definition fomr the dictionary. */
		if (cs_def->dat_knm [0] == '\0')
		{
			/* Oops!!! No datum definition in the coordinate system definition.
			   If we were to output something special for a cartographic definition,
			   i.e. a coordinate system referenced directly to an ellipsoid, we
			   would do that here. */
			CS_erpt (cs_NO_REFERNCE);
			goto error;
		}
		
		/* We need to free this definition, we stash it in a new pointer variable. */
		dtDefPtr = CS_dtdef (cs_def->dat_knm);
		if (dtDefPtr == NULL)
		{
			/* If the coordinate system definition came from the dictionary,
			   this shouldn't happen.  If the application got the cs_Csdef_
			   data from somewhere else, it is possible. */
			CS_erpt (cs_NO_REFERNCE);
			goto error;
		}
		dt_def = dtDefPtr;
	}
	
	if (el_def != 0)
	{
		if (CS_stricmp (dt_def->ell_knm,el_def->key_nm))
		{
			CS_erpt (cs_WKT_INCNSIST);
			goto error;
		}
	}

	/* Locate the projection in the projection table.  We need this for access
	   to the flag word for this projection. */
	for (prjPtr = cs_Prjtab;prjPtr->code != cs_PRJCOD_END;prjPtr += 1)
	{
		if (!strcmp (cs_def->prj_knm,prjPtr->key_nm)) break;
	}
	if (prjPtr->code == cs_PRJCOD_END)
	{
		CS_erpt (cs_UNKWN_PROJ);
		goto error;
	}
	prjCode = prjPtr->code;

	prjNmPtr = 0;
	if (prjCode == cs_PRJCOD_SWISS && (flavor == wktFlvrEsri || flavor == wktFlvrOracle))
	{
		prjNmPtr = CSwktPrjCode2Name (cs_PRJCOD_RSKEW,flavor);
	}
	else if (prjCode == cs_PRJCOD_LMTAN)
	{
		prjNmPtr = CSwktPrjCode2Name (cs_PRJCOD_LM1SP,flavor);
	}
	else if (prjPtr->code == cs_PRJCOD_UNITY)
	{
		prjNmPtr = "LL";
	}
	else
	{
		prjNmPtr = CSwktPrjCode2Name (prjCode,flavor);
	}
	if (prjNmPtr == 0 || *prjNmPtr == '\0')
	{
		/* This projection is not supported by this flavor of WKT. */
		CS_stncp (csErrnam,prjPtr->descr,MAXPATH);
		CS_erpt (cs_WKT_PRJSUPRT);
		goto error;
	}

	/* Locate the datum definition, if there is one.  We can't do anything
	   that isn't referenced to a datum. */
	if (dt_def == NULL)										/*lint !e774 */
	{
		/* The calling application did not provide a specific deatum definition.
		   We use the datum name in the Coordinate System definition to obtain
		   a definition fomr the dictionary. */
		if (cs_def->dat_knm [0] == '\0')
		{
			/* Oops!!! No datum definition in the coordinate system definition.
			   If we were to output something special for a cartographic definition,
			   i.e. a coordinate system referenced directly to an ellipsoid, we
			   would do that here. */
			CS_erpt (cs_NO_REFERNCE);	
			goto error;
		}
		dtDefPtr = CS_dtdef (cs_def->dat_knm);
		if (dtDefPtr == NULL)
		{
			/* If the coordinate system definition came from the dictionary,
			   this shouldn't happen.  If the application got the cs_Csdef_
			   data from somewhere else, it is possible. */
			CS_erpt (cs_NO_REFERNCE);
			goto error;
		}
		/* Capture the name of referenced datum which we will be using. */
		CS_stncp (refDtmName,cs_def->dat_knm,sizeof (refDtmName));
		
		/* I don't have to locate the ellipsoid, CSdt2WktEx will do that. */
		status = CSdt2WktEx (datmWkt,sizeof (datmWkt),geoTranWkt,sizeof (geoTranWkt),flavor,dtDefPtr,0,flags);
		CS_free (dtDefPtr);
		dtDefPtr = 0;
	}
	else
	{
		CS_stncp (refDtmName,dt_def->key_nm,sizeof (refDtmName));
		status = CSdt2WktEx (datmWkt,sizeof (datmWkt),geoTranWkt,sizeof (geoTranWkt),flavor,dt_def,el_def,flags);
	}
	if (status != 0)
	{
		/* CSdt2WktEx will have reported the nature of the error. */
		goto error;
	}

	/* Deal with the quad/axis situation. */
	geoAxis [0] = '\0';
	prjAxis [0] = '\0';
	if (cs_def->quad != 0 && cs_def->quad != 1)
	{
		if ((prjPtr->flags & cs_PRJFLG_GEOGR) != 0)
		{
			switch (cs_def->quad) {
			default:
			case 0:
			case 1:
				CS_stncp (geoAxis,",AXIS[\"Lon\",EAST],AXIS[\"Lat\",NORTH]",sizeof (prjAxis));
				break;
			case 2:
				CS_stncp (geoAxis,",AXIS[\"Lon\",WEST],AXIS[\"Lat\",NORTH]",sizeof (prjAxis));
				break;
			case 3:
				CS_stncp (geoAxis,",AXIS[\"Lon\",WEST],AXIS[\"Lat\",SOUTH]",sizeof (prjAxis));
				break;
			case 4:
				CS_stncp (geoAxis,",AXIS[\"Lon\",EAST],AXIS[\"Lat\",SOUTH]",sizeof (prjAxis));
				break;
			case -1:
				CS_stncp (geoAxis,",AXIS[\"Lat\",NORTH],AXIS[\"Lon\",EAST]",sizeof (prjAxis));
				break;
			case -2:
				CS_stncp (geoAxis,",AXIS[\"Lat\",NORTH],AXIS[\"Lon\",WEST]",sizeof (prjAxis));
				break;
			case -3:
				CS_stncp (geoAxis,",AXIS[\"Lat\",SOUTH],AXIS[\"Lon\",WEST]",sizeof (prjAxis));
				break;
			case -4:
				CS_stncp (geoAxis,",AXIS[\"Lat\",SOUTH],AXIS[\"Lon\",EAST]",sizeof (prjAxis));
				break;
			}
		}
		else
		{
			switch (cs_def->quad) {
			default:
			case 0:
			case 1:
				CS_stncp (prjAxis,",AXIS[\"X\",EAST],AXIS[\"Y\",NORTH]",sizeof (prjAxis));
				break;
			case 2:
				CS_stncp (prjAxis,",AXIS[\"X\",WEST],AXIS[\"Y\",NORTH]",sizeof (prjAxis));
				break;
			case 3:
				CS_stncp (prjAxis,",AXIS[\"X\",WEST],AXIS[\"Y\",SOUTH]",sizeof (prjAxis));
				break;
			case 4:
				CS_stncp (prjAxis,",AXIS[\"X\",EAST],AXIS[\"Y\",SOUTH]",sizeof (prjAxis));
				break;
			case -1:
				CS_stncp (prjAxis,",AXIS[\"Y\",NORTH],AXIS[\"X\",EAST]",sizeof (prjAxis));
				break;
			case -2:
				CS_stncp (prjAxis,",AXIS[\"Y\",NORTH],AXIS[\"X\",WEST]",sizeof (prjAxis));
				break;
			case -3:
				CS_stncp (prjAxis,",AXIS[\"Y\",SOUTH],AXIS[\"X\",WEST]",sizeof (prjAxis));
				break;
			case -4:
				CS_stncp (prjAxis,",AXIS[\"Y\",SOUTH],AXIS[\"X\",EAST]",sizeof (prjAxis));
				break;
			}
		}
	}

	/* Locate the base.  The base is what this coordinate system is referenced
	   to.  For example, the definition of UTM27-13 defines how to get from
	   LL27 to UTM27-13.  Therefore, LL27 is the base for that coordinate
	   system. */
	if ((prjPtr->flags & cs_PRJFLG_GEOGR) != 0)
	{
		/* This is a geographic coordinate system, so the base name is whatever
		   the coordinate system name is. */
		CS_stncp (baseName,cs_def->key_nm,sizeof (baseName));
	}
	else
	{
		/* Otherwise, basename is the name of a geographic coordinate system
		   referenced to the same datum as the projected coordinate system.
		   We have a function which will find this for us.  If we don't
		   have one, we are in trouble. */
		CSllCsFromDt (baseName,sizeof baseName,refDtmName);
		if (!CS_csIsValid (baseName))
		{
			CS_stncp (csErrnam,cs_def->key_nm,MAXPATH);
			CS_erpt (cs_WKT_NOLLBASE);
			return -1;
		}
	}

	/* Manufacture the prime meridian. */
	CS_stncp (pmerWkt,"PRIMEM[\"Greenwich\",0]",sizeof (pmerWkt));
	if ((prjPtr->flags & cs_PRJFLG_GEOGR) != 0 && cs_def->org_lng != 0.0)
	{
		int orgLng = (int)cs_def->org_lng;
		switch (orgLng) {
		case 0:
			primeMer = 0.0;
			CS_stncp (pmerWkt,"PRIMEM[\"Greenwich\",0]",sizeof (pmerWkt));
			break;
		case 2:
			primeMer = 2.337229166666667;
			CS_stncp (pmerWkt,"PRIMEM[\"Paris\",2.337229166666667]",sizeof (pmerWkt));
			break;
		case 9:
			primeMer = 9.13190611111111;
			CS_stncp (pmerWkt,"PRIMEM[\"Lisbon\",9.13190611111111]",sizeof (pmerWkt));
			break;
		case -17:
			primeMer = -17.4;
			CS_stncp (pmerWkt,"PRIMEM[\"Ferro\",-17.4]",sizeof (pmerWkt));
			break;
		case -74:
			primeMer = -74.08175;
			CS_stncp (pmerWkt,"PRIMEM[\"Bogota\",-74.08175]",sizeof (pmerWkt));
			break;
		default:
			break;
		}
	}

	/* We will always need the GEOGCS object.  If this is a geographic
	   coordinate system definition, than that's all we'll need.  If this is
	   a Projective coordinate system, the unit is the default for internal
	   coordinates within CS-MAP, namely the degree.  Only if this is a 
	   Geographic Coordinate system, is the actual unit of the definition
	   of importance to us here. */

   	kCp = CSmsiUnitName2WktName ("DEGREE",flavor);
   	if (kCp == 0 || *kCp == '\0')
   	{
		kCp = "Degree";
	}
	sprintf (unitWkt,"UNIT[\"%s\",0.017453292519943295]",kCp);
	if ((prjPtr->flags & cs_PRJFLG_GEOGR) != 0)
	{
		/* This is a geographic coordinate system, extract the unit information
		   from the definition. */
	   	kCp = CSmsiUnitName2WktName (cs_def->unit,flavor);
	   	if (kCp == 0)
	   	{
	   		/* Just in case the flavor does not define angular units... */
	   		kCp = "Degree";
			unitFactor = cs_Degree;
	   	}
	   	else
	   	{
			unitFactor = CS_unitlu (cs_UTYP_ANG,cs_def->unit) * cs_Degree;
		}
		sprintf (unitWkt,"UNIT[\"%s\",%.14f]",kCp,unitFactor);
	}
	
	/* If we are mapping names, the GCS name and the Datum name need to be
	   mapped, and then configured for the active flavor.
	   
	   First, we do the default in case anything goes wrong in the mapping
	   process. */
	sprintf (geogWkt,"GEOGCS[\"%s\",%s,%s,%s%s]",baseName,datmWkt,pmerWkt,unitWkt,geoAxis);
	if ((flags & cs_WKTFLG_MAPNAMES) != 0)
	{
		CS_stncp (dtmName,baseName,sizeof (dtmName));
		CS_stncp (gcsName,baseName,sizeof (gcsName));
		if (flavor == wktFlvrEsri)
		{
			kCp = CS_msiDtmName2Esri (dt_def->key_nm,0);
			if (kCp != 0)
			{
				if (*kCp != 'D' || *(kCp + 1) != '_')
				{
					CS_stcpy (dtmName,"D_");
					CS_stncp (&dtmName [2],kCp,sizeof (dtmName) - 2);

					CS_stcpy (gcsName,"GCS_");
					CS_stncp (&gcsName [4],kCp,sizeof (gcsName) - 4);
				}
				else
				{
					CS_stncp (dtmName,kCp,sizeof (dtmName));
					CS_stcpy (gcsName,"GCS_");
					CS_stncp (&gcsName [4],kCp+2,sizeof (gcsName) - 4);
				}
			}
		}
		else if (flavor == wktFlvrOracle)
		{
			kCp = CS_msiDtmName2Oracle (dt_def->key_nm,0);
			if (kCp != 0)
			{
				CS_stncp (dtmName,kCp,sizeof (dtmName));
				if ((prjPtr->flags & cs_PRJFLG_GEOGR) != 0)
				{
					sprintf (gcsName,"Longitude / Latitude (%s)",kCp);
				}
				else
				{
					CS_stncp (gcsName,kCp,sizeof (gcsName));
				}
			}
		}
		sprintf (geogWkt,"GEOGCS[\"%s\",%s,%s,%s%s]",gcsName,datmWkt,pmerWkt,unitWkt,geoAxis);
	}

	if ((prjPtr->flags & cs_PRJFLG_GEOGR) != 0)
	{
		/* If this is a geographic coordinate system, we're done. */
		CS_stncp (csWktBufr,geogWkt,(int)bufrSize);
	}
	else
	{
		/* We get here only if the coordinate system is of the projected type. */

		/* Do the linear unit for the projWkt. */
		unitFactor = CS_unitlu (cs_UTYP_LEN,cs_def->unit);
		kCp = CSmsiUnitName2WktName (cs_def->unit,flavor);
		if (kCp == 0 || *kCp == '\0')
		{
			CS_stncp (csErrnam,cs_def->unit,MAXPATH);
			CS_erpt (cs_WKT_UNITMAP);
			return -1;
		}
		sprintf (unitWkt,"UNIT[\"%s\",%.14f]",kCp,unitFactor);

		prmNmFalseEasting        = CSwktPrmEnum2Name (csWktPrmFalseEasting,flavor);
		prmNmFalseNorthing       = CSwktPrmEnum2Name (csWktPrmFalseNorthing,flavor);
		prmNmScaleFactor         = CSwktPrmEnum2Name (csWktPrmScaleAtCenter,flavor);
		prmNmCentralMeridian     = CSwktPrmEnum2Name (csWktPrmLongitudeOfOrg,flavor);
		prmNmLatitudeOfOrigin    = CSwktPrmEnum2Name (csWktPrmLatitudeOfOrg,flavor);
		prmNmStandardParallel1   = CSwktPrmEnum2Name (csWktPrmStdParallel1,flavor);
		prmNmStandardParallel2   = CSwktPrmEnum2Name (csWktPrmStdParallel2,flavor);
		prmNmYAxisAzimuth        = CSwktPrmEnum2Name (csWktPrmYaxisAzimuth,flavor);
		prmNmAzimuth             = CSwktPrmEnum2Name (csWktPrmAzimuth,flavor);
		prmNmLongitudeOfCenter   = CSwktPrmEnum2Name (csWktPrmLongitudeOfCtr,flavor);
		prmNmLatitudeOfCenter    = CSwktPrmEnum2Name (csWktPrmLatitudeOfCtr,flavor);
		prmNmLongitudeOf1stPoint = CSwktPrmEnum2Name (csWktPrmLngFirstPoint,flavor);
		prmNmLatitudeOf1stPoint  = CSwktPrmEnum2Name (csWktPrmLatFirstPoint,flavor);
		prmNmLongitudeOf2ndPoint = CSwktPrmEnum2Name (csWktPrmLngSecondPoint,flavor);
		prmNmLatitudeOf2ndPoint  = CSwktPrmEnum2Name (csWktPrmLatSecondPoint,flavor);
		prmNmLatitudeOfStdParall = CSwktPrmEnum2Name (csWktPrmLatOfStdParall,flavor);

		/* Build the projection and parameter portions of this thing. */ 
		parmWkt [0] = '\0';
		CS_stcpy (projection,prjNmPtr);
		switch (prjCode) {
		case  cs_PRJCOD_TRMER:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.12f]",prmNmScaleFactor,cs_def->scl_red);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfOrigin,cs_def->org_lat);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_ALBER:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmStandardParallel1,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmStandardParallel2,cs_def->prj_prm2);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfOrigin,cs_def->org_lat);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->org_lng);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_MRCAT:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmStandardParallel1,cs_def->prj_prm2);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfOrigin,cs_def->org_lat);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_AZMED:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmYAxisAzimuth,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->org_lng);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfOrigin,cs_def->org_lat);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_PLYCN:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfOrigin,cs_def->org_lat);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_AZMEA:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->org_lng);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfOrigin,cs_def->org_lat);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmYAxisAzimuth,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_EDCNC:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmStandardParallel1,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmStandardParallel2,cs_def->prj_prm2);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfOrigin,cs_def->org_lat);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_MILLR:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfOrigin,cs_def->org_lat);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_NZLND:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfOrigin,cs_def->org_lat);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->org_lng);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_SINUS:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_EDCYL:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmStandardParallel1,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfOrigin,cs_def->org_lat);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_VDGRN:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_CSINI:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfOrigin,cs_def->org_lat);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_ROBIN:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_BONNE:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmStandardParallel1,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_EKRT4:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_EKRT6:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_MOLWD:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_PSTRO:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfOrigin,cs_def->org_lat);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.12f]",prmNmScaleFactor,cs_def->scl_red);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_PSTROSL:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfOrigin,cs_def->org_lat);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmStandardParallel1,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			
			/* Kludge time again.  If the flavor is ESRI, we change the rpojection name based
			   on the origin latitude.  Sorry about that, but this WKT stuff is maddening. */
			if (flavor == wktFlvrEsri)
			{
				if (cs_def->org_lat < -89.0)
				{
					CS_stncp (projection,"Stereographic_South_Pole",sizeof (projection));
				}
				else if (cs_def->org_lat < -89.0)
				{
					CS_stncp (projection,"Stereographic_North_Pole",sizeof (projection));
				}
			}
			break;
		case  cs_PRJCOD_OSTRO:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfOrigin,cs_def->org_lat);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->org_lng);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.12f]",prmNmScaleFactor,cs_def->scl_red);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_LM1SP:
		case  cs_PRJCOD_LMTAN:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.12f]",prmNmScaleFactor,cs_def->scl_red);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->org_lng);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfOrigin,cs_def->org_lat);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_LM2SP:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->org_lng);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfOrigin,cs_def->org_lat);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmStandardParallel1,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmStandardParallel2,cs_def->prj_prm2);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_UTM:
			tmpDbl = 500000.00 / unitFactor;
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,tmpDbl);
			strcat (parmWkt,cTemp);
			tmpDbl = (cs_def->prj_prm2 >= 0.0) ? 0.0 : 10000000.0;
			tmpDbl /= unitFactor;
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,tmpDbl);
			strcat (parmWkt,cTemp);
			tmpDbl = (double)(-183 + (6 * (int)cs_def->prj_prm1)); 				/*lint !e790 */
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,tmpDbl);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",0.9996]",prmNmScaleFactor);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",0.000]",prmNmLatitudeOfOrigin);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_TRMRS:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.12f]",prmNmScaleFactor,cs_def->scl_red);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfOrigin,cs_def->org_lat);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_HOM1XY:
		case  cs_PRJCOD_RSKEW:
		case  cs_PRJCOD_RSKEWC:
		case  cs_PRJCOD_RSKEWO:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.12f]",prmNmScaleFactor,cs_def->scl_red);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmAzimuth,cs_def->prj_prm3);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLongitudeOfCenter,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfCenter,cs_def->prj_prm2);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_HOM2XY:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.12f]",prmNmScaleFactor,cs_def->scl_red);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLongitudeOf1stPoint,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOf1stPoint,cs_def->prj_prm2);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLongitudeOf2ndPoint,cs_def->prj_prm3);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOf2ndPoint,cs_def->prj_prm4);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfCenter,cs_def->org_lat);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_GAUSSK:
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.12f]",prmNmScaleFactor,cs_def->scl_red);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmCentralMeridian,cs_def->prj_prm1);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfOrigin,cs_def->org_lat);
			strcat (parmWkt,cTemp);
			break;
		case  cs_PRJCOD_SWISS:
			CS_stncp (projection,prjNmPtr,sizeof (projection));
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseEasting,cs_def->x_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.3f]",prmNmFalseNorthing,cs_def->y_off);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.12f]",prmNmScaleFactor,cs_One);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmAzimuth,cs_K90);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLongitudeOfCenter,cs_def->org_lng);
			strcat (parmWkt,cTemp);
			sprintf (cTemp,",PARAMETER[\"%s\",%.14f]",prmNmLatitudeOfCenter,cs_def->org_lat);
			strcat (parmWkt,cTemp);
			break;
		}												/*lint !e744 */

		/* Need to determine the name we will assign to this definition.  We
		generate a default value which is used if anything else fails. */
		CS_stncp (csysWktName,cs_def->key_nm,sizeof (csysWktName));
		if ((flags & cs_WKTFLG_MAPNAMES) != 0)
		{
			if (flavor == wktFlvrEsri)
			{
				kCp = CS_msiName2Esri (cs_def->key_nm);
				if (kCp != 0)
				{
					CS_stncp (csysWktName,kCp,sizeof (csysWktName));
				}
			}
			else if (flavor == wktFlvrOracle)
			{
				kCp = CS_msiName2Oracle (cs_def->key_nm);
				if (kCp != 0)
				{
					CS_stncp (csysWktName,kCp,sizeof (csysWktName));
				}
			}
		}

		/* Construct the final string. */
		sprintf (projWkt,"PROJCS[\"%s\",%s,PROJECTION[\"%s\"]%s,%s%s]",csysWktName,geogWkt,projection,parmWkt,unitWkt,prjAxis);
		CS_stncp (csWktBufr,projWkt,(int)bufrSize);
	}
	if (dtDefPtr != 0)
	{
		CS_free (dtDefPtr);
	}
	return 0;
error:
	if (dtDefPtr != 0)
	{
		CS_free (dtDefPtr);
	}
	return -1;
}
