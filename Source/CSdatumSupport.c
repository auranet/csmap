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

			 File Name: $Source: C:/Development/NewCsMap/rcs/CSdatumSupport.c $
			 Full Name:	US Canada Datum Support 
		   Description:
			   Purpose:	Implements basic support objects for US and
						Canadian datum shift calculations.

		Revision Level:	$Revision: #3 $
				  Date:	$Date: 2005/07/26 $

		 Last Revision:	$Log: CSdatumSupport.c $
		 Last Revision:	Revision 11.1300  2005/05/25 23:27:03  nto
		 Last Revision:	Official Release 11.13
		 Last Revision:	Revision 11.1200  2005/01/15 18:27:07  nto
		 Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		 Last Revision:	Revision 11.1100  2004/11/01 18:53:04  nto
		 Last Revision:	Official release 11.11
		 Last Revision:	Revision 11.1001  2004/10/07 19:25:13  nto
		 Last Revision:	Revision 11.900  2004/03/26 17:02:20  nto
		 Last Revision:	Official release: 11.09 - 3/25/2003
		 Last Revision:	Revision 11.800  2004/01/13 23:29:08  nto
		 Last Revision:	Revision 11.700  2003/12/19 01:49:49  nto
		 Last Revision:	Official release 11.07
		 Last Revision:	Revision 11.600  2003/12/04 02:46:24  nto
		 Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		 Last Revision:	Revision 11.501  2003/08/22 21:12:52  nto
		 Last Revision:	Official Release: 11.05
		 Last Revision:	Revision 11.401  2003/05/01 23:06:18  nto
		 Last Revision:	Revision 11.300  2003/02/25 04:29:12  nto
		 Last Revision:	Official Release 11.03
		 Last Revision:	Revision 11.100  2002/11/22 19:38:40  nto
		 Last Revision:	Official release: 11.01
		 Last Revision:	Revision 10.1501  2002/11/13 23:05:36  nto
		 Last Revision:	Added grid data file logging for Nad27ToNad83.
		 Last Revision:	Revision 10.1500  2002/09/22 00:01:16  nto
		 Last Revision:	Official Release:= 10.15
		 Last Revision:	Revision 10.1400  2002/08/09 18:14:19  nto
		 Last Revision:	Revision 10.1200  2002/07/14 03:26:10  nto
		 Last Revision:	Revision 10.1100  2002/06/13 14:18:32  nto
		 Last Revision:	Release 10.11 Official
		 Last Revision:	Revision 10.1001  2002/06/13 13:36:06  nto
		 Last Revision:	Some minor changes for the Datum SOurce file feature.
		 Last Revision:	Revision 10.1000  2002/02/23 21:18:23  nto
		 Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		 Last Revision:	Revision 10.901  2002/01/30 01:00:29  nto
		 Last Revision:	Rather superfluous changes to the test module.
		 Last Revision:	Revision 10.900  2001/09/24 04:31:08  nto
		 Last Revision:	Revision 10.701  2001/09/18 19:03:00  nto
		 Last Revision:	Fixed fallback generation to check for errors, and changed the
		 Last Revision:	dimensions on the double arrays to 3 to prevent memory
		 Last Revision:	addressing error.
		 Last Revision:	Revision 10.700  2001/01/25 04:13:42  nto
		 Last Revision:	Revision 10.600  2000/12/11 06:39:36  nto
		 Last Revision:	Release 10.06
		 Last Revision:	Revision 10.501  2000/12/04 18:06:25  nto
		 Last Revision:	Fixed a memory leak.
		 Last Revision:	Revision 10.500  2000/10/27 07:38:13  nto
		 Last Revision:	Official Release 10.05
		 Last Revision:	Revision 10.401  2000/10/27 03:41:15  nto
		 Last Revision:	Added the datum fallback feature to all datums which
		 Last Revision:	rely on grid data files
		 Last Revision:	Revision 10.400  2000/09/13 01:16:48  nto
		 Last Revision:	Release 10.04
		 Last Revision:	Revision 10.300  2000/04/04 23:18:18  nto
		 Last Revision:	Revision 10.200  2000/03/02 18:51:11  nto
		 Last Revision:	Revision 1.2  1999/11/03 23:41:09  nto
		 Last Revision:	Results of datum conversion rewrite.

		       * * * * R E M A R K S * * * *

	Includes implementation of several objects common to several of the
	datum objects uses in CS-MAP.

******************************************************************************/

#include "cs_map.h"

#ifdef LABEL_MODULE
static char revlvl [] = {"%W"};
#endif

/****************************************************************************
	Coverage Implementation
*/

void CSinitCoverage (struct csGridCoverage_* __This)
{
	extern double cs_K90;
	extern double cs_Km90;
	extern double cs_K180;
	extern double cs_Km180;

	/* Set the coverage to something that won't match anything. */
	__This->southWest [LNG] = cs_K180;
	__This->southWest [LAT] = cs_K90;
	__This->northEast [LNG] = cs_Km180;
	__This->northEast [LAT] = cs_Km90;
}

double CStestCoverageUS (struct csGridCoverage_* __This,Const double point [2])
{
	/* Return value is the density value used to select a specific source in
	   the case of overlap which is rare, but possible.  A zero return value
	   indicates that the current coverage window does not include the
	   provided location.
	
	   The coverage is inclusive on the south and west, exclusive on the
	   north and east.  This is standard for US.  The north and east edges
	   of a US grid file are not part of the coverage of a US file. */

	double returnValue = 0.0;
	if (point [LNG] >= __This->southWest [LNG] &&
	    point [LAT] >= __This->southWest [LAT] &&
	    point [LNG] <  __This->northEast [LNG] &&
	    point [LAT] <  __This->northEast [LAT])
	{
		returnValue = __This->density;
	}
	return returnValue;
}

double CStestCoverageCA (struct csGridCoverage_* __This,Const double point [2])
{
	double myLng, myLat;

	/* Return value is the density value used to select a specific source in
	   the case of overlap which is rare, but possible.  A zero return value
	   indicates that the current coverage window does not include the
	   provided location.

	   The coverage is inclusive on both the south and west. In some cases,
	   the Canadaian technique uses an inclusive boundary on the north
	   and east.  However, we consider these to be special.  Omitting
	   this here causes the conversion to be referred to the main
	   conversion function which handles this properly. */

	double returnValue = 0.0;
	myLng = -point [LNG];
	myLat =  point [LAT];
	if (myLng >= __This->southWest [LNG] &&
	    myLat >= __This->southWest [LAT] &&
	    myLng <  __This->northEast [LNG] &&
	    myLat <  __This->northEast [LAT])
	{
		returnValue = __This->density;
	}
	return returnValue;
}

void CSsetCoverage (struct csGridCoverage_* __This,Const double* swLL,Const double* neLL)
{
	__This->southWest [LNG] = swLL [LNG];
	__This->southWest [LAT] = swLL [LAT];
	__This->northEast [LNG] = neLL [LNG];
	__This->northEast [LAT] = neLL [LAT];	
}

/****************************************************************************
	Grid Cell Implementation
*/
void CSinitGridCell (struct csGridCell_* __This)
{
	extern double cs_Zero;					/* 0.0 */
	CSinitCoverage (&__This->coverage);
	__This->deltaLng = cs_Zero;
	__This->deltaLat = cs_Zero;
	__This->currentAA = cs_Zero;
	__This->currentBB = cs_Zero;
	__This->currentCC = cs_Zero;
	__This->currentDD = cs_Zero;
	__This->sourceId [0] = '\0';
}

double CScalcGridCellUS (struct csGridCell_* __This,Const double *sourceLL)
{
	/* This function performs the interpolation of the grid cell, and
	   returns the result.  Type of result depends upon the application.
	   Calculation algorithm is the same for all applications. */

	double gridDeltaLng;
	double gridDeltaLat;
	double returnValue;

	gridDeltaLng  = (sourceLL [LNG] - __This->coverage.southWest [LNG]) / __This->deltaLng;
	gridDeltaLat  = (sourceLL [LAT] - __This->coverage.southWest [LAT]) / __This->deltaLat;
	returnValue = __This->currentAA + 
				  __This->currentBB * gridDeltaLng +
				  __This->currentCC * gridDeltaLat +
				  __This->currentDD * gridDeltaLng * gridDeltaLat;

	/* Note return value for datum shift grid files is usually in seconds.
	   However, this varies from application to application. */
	return returnValue;	
}

double CScalcGridCellCA (struct csGridCell_* __This,Const double *sourceLL)
{
	double myLng, myLat;
	double gridDeltaLng;
	double gridDeltaLat;
	double returnValue;

	/* This function performs the interpolation of the grid cell, and
	   returns the result.  Type of result depends upon the application.
	   Calculation algorithm is the same for all applications. */

	myLng = -sourceLL [LNG];
	myLat =  sourceLL [LAT];
	gridDeltaLng  = (myLng - __This->coverage.southWest [LNG]) / __This->deltaLng;
	gridDeltaLat  = (myLat - __This->coverage.southWest [LAT]) / __This->deltaLat;
	returnValue = __This->currentAA + 
				  __This->currentBB * gridDeltaLng +
				  __This->currentCC * gridDeltaLat +
				  __This->currentDD * gridDeltaLng * gridDeltaLat;

	/* Note return value for datum shift grid files is usually in seconds.
	   However, this varies from application to application. */
	return returnValue;	
}

const char *CSsourceGridCell (struct csGridCell_* __This)
{
	return __This->sourceId;
}
/******************************************************************************
	Returns NULL if an error, otherwise returns an initialized cs_DtcXform
	structure.
*/
struct cs_DtcXform_ *CSnewFallback (Const char *dtKeyName,Const char *catalog)
{
	extern int cs_Error;
	extern char csErrnam [];
	extern double cs_Zero;
	extern struct cs_Datum_ cs_Wgs84Dt;

	char *cp;
	struct cs_DtcXform_ *__This;
	struct cs_Datum_ *dt_ptr;
	struct cs_Datum_ *wgs84Ptr;

	/* Prepare for an error of some sort. */
	__This = NULL;
	dt_ptr = NULL;

	/* Just in case, we do the simple case.  This is better than crashing. */
	if (dtKeyName == NULL || *dtKeyName == '\0')
	{
		CS_stncp (csErrnam,catalog,MAXPATH);
		CS_erpt (cs_FLBK_NOSET);
		return NULL;
	}

	/* Get a copy of the WGS84 datum definition.  We use that internally. */
	if (cs_Wgs84Dt.key_nm [0] == '\0')
	{
		wgs84Ptr = CS_dtloc ("WGS84");
		if (wgs84Ptr == NULL)
		{
			return NULL;
		}
		memcpy (&cs_Wgs84Dt,wgs84Ptr,sizeof (cs_Wgs84Dt));
		CS_free (wgs84Ptr);
		cs_Wgs84Dt.rot_X = cs_Zero;
		cs_Wgs84Dt.rot_Y = cs_Zero;
		cs_Wgs84Dt.rot_Z = cs_Zero;
		cs_Wgs84Dt.bwscale = cs_Zero;
	}

	/* Get the definition of the proposed fallabck. */
	dt_ptr = CS_dtloc (dtKeyName);
	if (dt_ptr == NULL)
	{
		if (cs_Error == cs_DT_NOT_FND)
		{
			CS_stncp (csErrnam,catalog,MAXPATH);
			CS_erpt (cs_FLBK_NTFND);
		}
		goto error;
	}

	/* Allocate the fallback object. */
	__This = CS_malc (sizeof (struct cs_DtcXform_));
	if (__This == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}
	__This->sourceId [0] = '\0';

	/* Properly initialize it. */
	cp = CS_stcpy (__This->sourceId,"Fallback: ");
	CS_stncp (cp,dt_ptr->key_nm,cs_KEYNM_DEF);
	switch (dt_ptr->to84_via) {
	case cs_DTCTYP_MOLO:
		__This->xfrmType = dtcTypMolodensky;
		__This->parms.molo = CS_moInit (dt_ptr,&cs_Wgs84Dt);
		if (__This->parms.molo == NULL) goto error;
		break;

	case cs_DTCTYP_MREG:
		__This->xfrmType = dtcTypDMAMulReg;
		__This->parms.mreg = CS_dmaMrInit (dt_ptr);
		if (__This->parms.mreg == NULL) goto error;
		break;

	case cs_DTCTYP_BURS:
		__This->xfrmType = dtcTypBursaWolf;
		__This->parms.bursa = CS_bwInit (dt_ptr,&cs_Wgs84Dt);
		if (__This->parms.bursa == NULL) goto error;
		break;

	case cs_DTCTYP_7PARM:
		__This->xfrmType = dtcTypSevenParm;
		__This->parms.parm7 = CS_7pInit (dt_ptr,&cs_Wgs84Dt);
		if (__This->parms.parm7 == NULL) goto error;
		break;

	case cs_DTCTYP_6PARM:
		__This->xfrmType = dtcTypSixParm;
		__This->parms.parm6 = CS_6pInit (dt_ptr,&cs_Wgs84Dt);
		if (__This->parms.parm6 == NULL) goto error;
		break;

	case cs_DTCTYP_3PARM:
		__This->xfrmType = dtcTypThreeParm;
		__This->parms.parm3 = CS_3pInit (dt_ptr,&cs_Wgs84Dt);
		if (__This->parms.parm3 == NULL) goto error;
		break;

	case cs_DTCTYP_4PARM:
		__This->xfrmType = dtcTypFourParm;
		__This->parms.parm4 = CS_4pInit (dt_ptr,&cs_Wgs84Dt);
		if (__This->parms.parm4 == NULL) goto error;
		break;

	default:
		CS_stncp (csErrnam,catalog,MAXPATH);
		CS_erpt (cs_FLBK_WRNGT);
		goto error;
	}
	CS_free (dt_ptr);
	return __This;

error:
	if (dt_ptr != NULL) CS_free (dt_ptr);
	if (__This != NULL) CS_free (__This);
	return NULL;
}
/******************************************************************************
	Deletes the internal transformation, then deletes the fallback guy
	itself.
*/
void CSdeleteFallback (struct cs_DtcXform_ *__This)
{
	switch (__This->xfrmType) {
	case dtcTypMolodensky:
	case dtcTypMolodenskyInv:
		CS_free (__This->parms.molo);
		break;
	case dtcTypDMAMulReg:
	case dtcTypDMAMulRegInv:
		CS_free (__This->parms.mreg);
		break;

	case dtcTypBursaWolf:
	case dtcTypBursaWolfInv:
		CS_free (__This->parms.bursa);
		break;

	case dtcTypSevenParm:
	case dtcTypSevenParmInv:
		CS_free (__This->parms.parm7);
		break;

	case dtcTypThreeParm:
	case dtcTypThreeParmInv:
		CS_free (__This->parms.parm3);
		break;

	case dtcTypSixParm:
	case dtcTypSixParmInv:
		CS_free (__This->parms.parm6);
		break;

	case dtcTypFourParm:
	case dtcTypFourParmInv:
		CS_free (__This->parms.parm4);
		break;
	default:
		/* Should never get here.  What would we do if we did? */
		break;
	}
	CS_free (__This);
	return;
}
/* Used for datum calculation logging. */
Const char *CSsourceFallback (struct cs_DtcXform_ *__This)
{
	return __This->sourceId;
}
/* Forward calculation. */
int CScalcFallbackForward (struct cs_DtcXform_ *__This,double trg [3],Const double src [3])
{
	extern char csErrnam [];

	int status;

	if (__This == NULL)
	{
		CS_erpt (cs_FLBK_NOSET);
		return -1;
	}

	switch (__This->xfrmType) {
	case dtcTypMolodensky:
		status = CS_mo2dFowrd (trg,src,__This->parms.molo);
		break;

	case dtcTypDMAMulReg:
		status = CS_dmaMr2dFowrd (trg,src,__This->parms.mreg);
		break;

	case dtcTypBursaWolf:
		status = CS_bw2dFowrd (trg,src,__This->parms.bursa);
		break;

	case dtcTypSevenParm:
		status = CS_7p2dFowrd (trg,src,__This->parms.parm7);
		break;

	case dtcTypThreeParm:
		status = CS_3p2dFowrd (trg,src,__This->parms.parm3);
		break;

	case dtcTypSixParm:
		status = CS_6p2dFowrd (trg,src,__This->parms.parm6);
		break;

	case dtcTypFourParm:
		status = CS_4p2dFowrd (trg,src,__This->parms.parm4);
		break;

	default:
		CS_stncp (csErrnam,"CScalcFallbackForward:1",MAXPATH);
		CS_erpt (cs_ISER);
		goto error;
	}
	return (status == 0) ? 2 : 1;

error:
	return -1;
}

int CScalcFallbackInverse (struct cs_DtcXform_ *__This,double trg [3],Const double src [3])
{
	extern char csErrnam [];

	int status;

	if (__This == NULL)
	{
		CS_erpt (cs_FLBK_NOSET);
		return -1;
	}

	switch (__This->xfrmType) {

	case dtcTypMolodensky:
		status = CS_mo2dInvrs (trg,src,__This->parms.molo);
		break;

	case dtcTypDMAMulReg:
		status = CS_dmaMr2dInvrs (trg,src,__This->parms.mreg);
		break;

	case dtcTypBursaWolf:
		status = CS_bw2dInvrs (trg,src,__This->parms.bursa);
		break;

	case dtcTypSevenParm:
		status = CS_7p2dInvrs (trg,src,__This->parms.parm7);
		break;

	case dtcTypThreeParm:
		status = CS_3p2dInvrs (trg,src,__This->parms.parm3);
		break;

	case dtcTypSixParm:
		status = CS_6p2dInvrs (trg,src,__This->parms.parm6);
		break;

	case dtcTypFourParm:
		status = CS_4p2dInvrs (trg,src,__This->parms.parm4);
		break;

	default:
		CS_stncp (csErrnam,"CScalcFallbackInverse:1",MAXPATH);
		CS_erpt (cs_ISER);
		goto error;
	}
	return (status == 0) ? 2 : 1;

error:
	return -1;
}

#ifdef __TEST__
/******************************************************************************
	A quick and dirty set of test code used to build a test module for
	debugging the new datum stuff.  Paths to catalog files are hard
	coded in this test program; you'll need to change them before you
	can use it.
*/
int main (int argc,char *argv [])
{
	struct csNad27ToNad83_ *nadObj;
	struct csNad83ToHarn_ *harnObj;
	struct csGeoidHeight_ *ghgtObj;
	struct csVertconUS_ *vconObj;

	double ll27 [2];
	double ll83 [2];
	double llHarn [2];
	double geoidHgt;
	double v88Mv29;

	char ctemp [256];

	ll27 [0] = -115.123456789;
	ll27 [1] = 35.123456789;

	nadObj = CSnewNad27ToNad83 ("H:\\CS_MAP\\DATA\\TEST\\Nad27ToNad83.gdc");
	if (nadObj == NULL)
	{
		CS_errmsg (ctemp,sizeof (ctemp));
		printf ("%s\n",ctemp);
		goto error;
	}
	harnObj = CSnewNad83ToHarn ("H:\\CS_MAP\\DATA\\TEST\\Nad83ToHarn.gdc");
	if (harnObj == NULL)
	{
		CS_errmsg (ctemp,sizeof (ctemp));
		printf ("%s\n",ctemp);
		goto error;
	}
	ghgtObj = CSnewGeoidHeight ("H:\\CS_MAP\\DATA\\TEST\\GeoidHeight.gdc");
	if (harnObj == NULL)
	{
		CS_errmsg (ctemp,sizeof (ctemp));
		printf ("%s\n",ctemp);
		goto error;
	}
	vconObj = CSnewVertconUS ("H:\\CS_MAP\\DATA\\TEST\\Vertcon.gdc");
	if (harnObj == NULL)
	{
		CS_errmsg (ctemp,sizeof (ctemp));
		printf ("%s\n",ctemp);
		goto error;
	}

	CScalcNad27ToNad83 (nadObj,ll83,ll27);
	CScalcNad83ToHarn (harnObj,llHarn,ll83);
	CScalcGeoidHeight (ghgtObj,&geoidHgt,ll83);
	CScalcVertconUS (vconObj,&v88Mv29,ll83);

	CSdeleteNad27ToNad83 (nadObj);
	CSdeleteNad83ToHarn (harnObj);
	CSdeleteGeoidHeight (ghgtObj);
	CSdeleteVertconUS (vconObj);
	return 0;

error:
	return 1;
}
#endif
