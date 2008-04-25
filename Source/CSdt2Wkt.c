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

			 File Name: $RCSfile: CSdt2Wkt.c $
		   Description:
			   Purpose:	Converts the supplied datum dictionary
						entry to a WKT representation.

		Revision Level:	$Revision: #6 $
		 Check In Date:	$Date: 2007/01/12 $

		Last Revision:	$Log: CSdt2Wkt.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:04  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:07  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:04  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:13  nto
		Last Revision:	Revision 11.901  2004/08/07 03:35:27  nto
		Last Revision:	Added CS_dt2Wkt, a high level version of CSdt2Wkt
		Last Revision:	Revision 11.900  2004/03/26 17:02:20  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:08  nto
		Last Revision:	Revision 11.701  2004/01/13 20:41:37  nto
		Last Revision:	Removed the TWOWGS84 sub-elements with all zeros fir parameters.
		Last Revision:	Revision 11.700  2003/12/19 01:49:49  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.601  2003/12/19 01:01:11  nto
		Last Revision:	Added null datum transformation, and increased precision of ASCII numbers.
		Last Revision:	Revision 11.600  2003/12/04 02:46:24  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 1.2  2003/11/07 03:57:06  nto
		Last Revision:	Modified major portions to add the flavor capability to WKT outout.
		Last Revision:	Revision 1.1  2003/10/01 22:09:51  nto
		Last Revision:	Initial Revision

	 Calling Sequence:	st = CSdt2Xml (bufr,bufrSize,dt_def);

	char *bufr;			result is returned here.
	size_t bufrSize;	size of the supplied buffer in bytes.
	struct cs_Dtdef_ *dt_def;
						the definition which os to be converted to XML
						form.
	int st;				returns zero on success, -1 on I/O error on the
						stream.
	
	Note, this function calls CSel2Wkt to get a representation of the
	referenced ellipsoid in WKT form, and includes this in the result.

	Not all of the datum conversion techniques which CS-MAP supports are
	supported by WKT.  Therefore, this function returns an error in the
	case where a datum which relies on an unsupported conversion technique
	ids converted.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CSdt2Wkt.c#6 $"};
#endif

#include "cs_map.h"
#include "cs_wkt.h"

int EXP_LVL1 CS_dt2WktEx (char *bufr,size_t bufrSize,const char *dtKeyName,int flavor,unsigned short flags)
{
	int rtnValue = -1;
	struct cs_Dtdef_ *dtDefPtr = 0;
	struct cs_Eldef_ *elDefPtr = 0;
	
	if (bufrSize > 0)
	{
		*bufr = '\0';
		dtDefPtr = CS_dtdef (dtKeyName);
		if (dtDefPtr != 0)
		{
			elDefPtr = CS_eldef (dtDefPtr->ell_knm);
			if (elDefPtr != 0)
			{
				rtnValue = CSdt2WktEx (bufr,bufrSize,0,0,flavor,dtDefPtr,elDefPtr,flags);
				CS_free (elDefPtr);
				elDefPtr = 0;
			}
			CS_free (dtDefPtr);
			dtDefPtr = 0;
		}
	}
	return rtnValue;			
}

int EXP_LVL1 CS_dt2Wkt (char *bufr,size_t bufrSize,const char *dtKeyName,int flavor)
{
	int rtnValue = -1;
	struct cs_Dtdef_ *dtDefPtr = 0;
	struct cs_Eldef_ *elDefPtr = 0;
	
	if (bufrSize > 0)
	{
		*bufr = '\0';
		dtDefPtr = CS_dtdef (dtKeyName);
		if (dtDefPtr != 0)
		{
			elDefPtr = CS_eldef (dtDefPtr->ell_knm);
			if (elDefPtr != 0)
			{
				rtnValue = CSdt2Wkt (bufr,bufrSize,0,0,flavor,dtDefPtr,elDefPtr);
				CS_free (elDefPtr);
				elDefPtr = 0;
			}
			CS_free (dtDefPtr);
			dtDefPtr = 0;
		}
	}
	return rtnValue;			
}
int EXP_LVL3 CSdt2Wkt (char *datum,size_t datumSize,char *geoTran,size_t geoTranSize,enum ErcWktFlavor flavor,const struct cs_Dtdef_ *dt_def,const struct cs_Eldef_ *el_def)
{
	int st;
	
	st = CSdt2WktEx (datum,datumSize,geoTran,geoTranSize,flavor,dt_def,el_def,0);
	return st;
}
int EXP_LVL3 CSdt2WktEx (char *datum,size_t datumSize,char *geoTran,size_t geoTranSize,enum ErcWktFlavor flavor,const struct cs_Dtdef_ *dt_def,const struct cs_Eldef_ *el_def,unsigned short flags)
{
	extern double cs_Zero;

	int status;

	short parmCount;
	Const char* kCp;
	const char *method;
	const char* prmNameXTr;
	const char* prmNameYTr;
	const char* prmNameZTr;
	const char* prmNameXRot;
	const char* prmNameYRot;
	const char* prmNameZRot;
	const char* prmNameScale;

	struct cs_Eldef_ *elDef;

	char wktDatumName [96];
	char gcsDatumName [96];
	char elWkt [256];
	char dtWkt [512];
	char geoCSdatum [512];
	char geoCSwgs84 [] = "GEOGCS[\"WGS84.LL\",DATUM[\"WGS84\",SPHEROID[\"WGS84\",6378137,298.257223563]],PRIMEM[\"Greenwich\",0],UNIT[\"Degree\",0.017453292519943295]]";
	char paramsWkt [512];
	char geoTranName [96];
	char geoTranWkt [1024];

	if (datumSize != 0) *datum = '\0';
	if (geoTranSize != 0) *geoTran = '\0';
	if (datumSize <= 1 && geoTranSize <=1)
	{
		return -1;
	}

	if (el_def == NULL)
	{
		elDef = CS_eldef (dt_def->ell_knm);
		if (elDef == NULL)
		{
			return -1;
		}
		status = CSel2WktEx (elWkt,sizeof (elWkt),flavor,elDef,flags);
		CS_free (elDef);
		if (status != 0)
		{
			return -1;
		}
	}
	else
	{
		status = CSel2WktEx (elWkt,sizeof (elWkt),flavor,el_def,flags);
	}

	/* Set up the parameter names consistent with the flavor. */
	prmNameXTr   = CSwktPrmCode2Name (cs_WKTCOD_DELTAX,flavor);
	prmNameYTr   = CSwktPrmCode2Name (cs_WKTCOD_DELTAY,flavor);
	prmNameZTr   = CSwktPrmCode2Name (cs_WKTCOD_DELTAZ,flavor);
	prmNameXRot  = CSwktPrmCode2Name (cs_WKTCOD_ROTATX,flavor);
	prmNameYRot  = CSwktPrmCode2Name (cs_WKTCOD_ROTATY,flavor);
	prmNameZRot  = CSwktPrmCode2Name (cs_WKTCOD_ROTATZ,flavor);
	prmNameScale = CSwktPrmCode2Name (cs_WKTCOD_ROTATZ,flavor);

	CS_stncp (wktDatumName,dt_def->key_nm,sizeof (wktDatumName));
	CS_stncp (gcsDatumName,dt_def->key_nm,sizeof (gcsDatumName));
	if (strlen (gcsDatumName) < sizeof (gcsDatumName) - 4)
	{
		strcat (gcsDatumName,".LL");
	}
	if ((flags & cs_WKTFLG_MAPNAMES) != 0)
	{
		if (flavor == wktFlvrEsri)
		{
			kCp = CS_msiDtmName2Esri (dt_def->key_nm,0);
			if (kCp != 0)
			{
				if (*kCp != 'D' || *(kCp + 1) != '_')
				{
					CS_stcpy (wktDatumName,"D_");
					CS_stncp (&wktDatumName [2],kCp,sizeof (wktDatumName) - 2);

					CS_stcpy (gcsDatumName,"GCS_");
					CS_stncp (&gcsDatumName [4],kCp,sizeof (gcsDatumName) - 4);
				}
				else
				{
					CS_stncp (wktDatumName,kCp,sizeof (wktDatumName));
					CS_stcpy (gcsDatumName,"GCS_");
					CS_stncp (&gcsDatumName [4],kCp+2,sizeof (gcsDatumName) - 4);
				}
			}
			CS_stncp (geoCSwgs84,"GEOGCS[\"GCS_WGS_1984\",DATUM[\"D_WGS_1984\",SPHEROID[\"WGS_1984\",6378137,298.257223563]],PRIMEM[\"Greenwich\",0],UNIT[\"Degree\",0.017453292519943295]]",sizeof (geoCSwgs84));
		}
		else if (flavor == wktFlvrOracle)
		{
			kCp = CS_msiDtmName2Oracle (dt_def->key_nm,0);
			if (kCp != 0)
			{
				CS_stncp (wktDatumName,kCp,sizeof (wktDatumName));
				CS_stncp (gcsDatumName,kCp,sizeof (gcsDatumName));
				CS_stncp (geoCSwgs84,"GEOGCS[\"WGS 84\",DATUM [\"WGS 84\",SPHEROID [\"WGS 84\",6378137.000000,298.257224]],PRIMEM [\"Greenwich\",0.000000],UNIT[\"Decimal Degree\", 0.01745329251994330]]",sizeof (geoCSwgs84));
			}
		}
	}
	sprintf (dtWkt,"DATUM[\"%s\",%s]",wktDatumName,elWkt);
	sprintf (geoCSdatum,"GEOGCS[\"%s\",%s,PRIMEM[\"Greenwich\",0],UNIT[\"Degree\",0.017453292519943295]]",gcsDatumName,dtWkt);

	/* I suspect that there are different "flavors" of the following.  I'll have to
	   do some more research before I know what they might be. */
	switch (dt_def->to84_via) {
	case cs_DTCTYP_MOLO:
		parmCount = 3;
		method = "Geocentric_Translation";
		break;
	case cs_DTCTYP_3PARM:
		parmCount = 3;
		method = "Geocentric_Translation";
		break;
	case cs_DTCTYP_BURS:
		parmCount = 7;
		method = "Coordinate_Frame";
		break;
	case cs_DTCTYP_7PARM:
		parmCount = 7;
		method = "Coordinate_Frame";
		break;
	case cs_DTCTYP_NAD83:
	case cs_DTCTYP_WGS84:
	case cs_DTCTYP_GDA94:
	case cs_DTCTYP_NZGD2K:
	case cs_DTCTYP_ETRF89:
	case cs_DTCTYP_RGF93:
		// This is the case where the datum is considered to be equivalent to
		// WGS84, no transformation is required.
		parmCount = -3;
		method = "Geocentric_Translation";
		break;
		
	case cs_DTCTYP_NAD27:
	case cs_DTCTYP_MREG:
	case cs_DTCTYP_WGS72:
	case cs_DTCTYP_HPGN:
	case cs_DTCTYP_AGD66:
	case cs_DTCTYP_6PARM:
	case cs_DTCTYP_4PARM:
	case cs_DTCTYP_AGD84:
	case cs_DTCTYP_NZGD49:
	case cs_DTCTYP_CSRS:  
	case cs_DTCTYP_ATS77:
	case cs_DTCTYP_TOKYO:
	case cs_DTCTYP_ED50:
	case cs_DTCTYP_DHDN:
	default:
		/* These may be supported in EPSG, but they are not supported in WKT. */
		parmCount = 0;
		method = "Unsupported";
		break;
	}

	if (parmCount == 3)
	{
		sprintf (paramsWkt,"METHOD[\"%s\"],PARAMETER[\"%s\",%.4f],PARAMETER[\"%s\",%.4f],PARAMETER[\"%s\",%.4f]",
															method,
															prmNameXTr,dt_def->delta_X,
															prmNameYTr,dt_def->delta_Y,
															prmNameZTr,dt_def->delta_Z);
	}
	else if (parmCount == 7)
	{
		sprintf (paramsWkt,"METHOD[\"%s\"],PARAMETER[\"%s\",%.4f],PARAMETER[\"%s\",%.4f],PARAMETER[\"%s\",%.4f],"
										  "PARAMETER[\"%s\",%.6f],PARAMETER[\"%s\",%.6f],PARAMETER[\"%s\",%.6f],"
										  "PARAMETER[\"%s\",%.8f]",
										  method,
										  prmNameXTr,dt_def->delta_X,
										  prmNameYTr,dt_def->delta_Y,
										  prmNameZTr,dt_def->delta_Z,
										  prmNameXRot,dt_def->rot_X,
										  prmNameYRot,dt_def->rot_Y,
										  prmNameZRot,dt_def->rot_Z,
										  prmNameScale,dt_def->bwscale);
	}
	else if (parmCount == -3)
	{
		sprintf (paramsWkt,"METHOD[\"%s\"],PARAMETER[\"%s\",%.4f],PARAMETER[\"%s\",%.4f],PARAMETER[\"%s\",%.4f]",
															method,
															prmNameXTr,cs_Zero,
															prmNameYTr,cs_Zero,
															prmNameZTr,cs_Zero);
	}
	else
	{
		sprintf (paramsWkt,"METHOD[\"Unsupport_Method\"]");
	}

	CS_stncp (geoTranName,dt_def->key_nm,sizeof (geoTranName) - 15); 
	if (flavor == wktFlvrEsri)
	{
		kCp = CS_msiDtmName2Esri (dt_def->key_nm,0);
		if (kCp != 0)
		{
			CS_stncp (geoTranName,kCp,sizeof (geoTranName) - 15);
		}
	}
	strcat (geoTranName,"_To_WGS_1984");
	sprintf (geoTranWkt,"GEOTRAN[\"%s\",%s,%s,%s]",geoTranName,geoCSdatum,geoCSwgs84,paramsWkt);

	/* We now redo the datum, this time we'll put the TOQGS84 thing in.
	   However, it makes no sense to do this unless there are some valid
	   paremeters. */
	if (parmCount == 3 || parmCount == 7)
	{
		sprintf (dtWkt,"DATUM[\"%s\",%s,TOWGS84[%.4f,%.4f,%.4f,%.6f,%.6f,%.6f,%.8f]]",wktDatumName,elWkt,
												dt_def->delta_X,dt_def->delta_Y,dt_def->delta_Z,
												dt_def->rot_X,dt_def->rot_Y,dt_def->rot_Z,dt_def->bwscale);
	}
/******************************************************************************
	Clients have indicated that this feature is rather undesireable; so we
	comment it out, leaving the code intact, in case anyone has a different
	opinion.
		
	else if (parmCount == -3)
	{
		sprintf (dtWkt,"DATUM[\"%s\",%s,TOWGS84[%.4f,%.4f,%.4f,%.6f,%.6f,%.6f,%.8f]]",wktDatumName,elWkt,
												cs_Zero,cs_Zero,cs_Zero,
												cs_Zero,cs_Zero,cs_Zero,cs_Zero);
	}
******************************************************************************/
	else
	{
		/* The datum type is one that is unsupported by WKT.  We simply write the
		   datum definition with the name of the datum. */
		sprintf (dtWkt,"DATUM[\"%s\",%s]",wktDatumName,elWkt);
	}	
	if (datumSize > 1)
	{
		CS_stncp (datum,dtWkt,(int)datumSize);
	}
	if (geoTranSize > 1)
	{
		CS_stncp (geoTran,geoTranWkt,(int)geoTranSize);
	}
	return 0;
}
