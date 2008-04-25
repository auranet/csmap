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

			 File Name: $RCSfile: mgTest.cpp $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #3 $
		 Check In Date:	$Date: 2005/07/26 $

		Last Revision:	$Log: mgTest.cpp $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:23  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:18  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:17  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:24  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:30  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:19  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:59  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.601  2003/12/19 01:14:21  nto
		Last Revision:	Adjusted to compile with version 7 of MFC.
		Last Revision:	Revision 11.600  2003/12/04 02:46:34  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.502  2003/10/02 04:58:04  nto
		Last Revision:	Revision 11.501  2003/08/22 21:13:01  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:27  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:22  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:49  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1500  2002/09/22 00:01:26  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:27  nto
		Last Revision:	Revision 10.1200  2002/06/20 18:00:32  nto
		Last Revision:	Official release: 10.12
		Last Revision:	Revision 10.1100  2002/06/13 14:18:50  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:31  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:15  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:58  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:53  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:39  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.401  2000/10/27 04:01:42  nto
		Last Revision:	Added the MGRS persistence function.
		Last Revision:	Revision 10.400  2000/09/13 01:17:04  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.301  2000/09/12 21:40:26  nto
		Last Revision:	Added the ability to handle a  warning condition  to the MGRS conversion.
		Last Revision:	Revision 10.300  2000/04/04 23:18:41  nto
		Last Revision:	Revision 1.2  2000/04/03 21:52:53  nto
		Last Revision:	It actually works now.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/mgTest.cpp#3 $"};
#endif

#if defined (__MFC__)

#include "cs_map.h"
#include "cs_mfc.h"
#include "cs_hlp.h"

///////////////////////////////////////////////////////////////////////////////
// Basic API access function.
extern "C" void EXP_LVL1 CS_mgTest (char *elKeyName)
{
	CmgTest mgTest;
	mgTest.SetEllipsoid (elKeyName);
	mgTest.DoModal ();
	CS_stncp (elKeyName,mgTest.GetEllipsoid (),cs_KEYNM_DEF);
	return;	
}
extern "C" void EXP_LVL1 CS_mgTestA (char *elKeyName,int* prec,long* latFrmt,long* lngFrmt)
{
	CmgTest mgTest;
	mgTest.SetEllipsoid (elKeyName);
	mgTest.SetPrecision (*prec);
	mgTest.SetLatFrmt (*latFrmt);
	mgTest.SetLngFrmt (*lngFrmt);
	mgTest.DoModal ();
	CS_stncp (elKeyName,mgTest.GetEllipsoid (),cs_KEYNM_DEF);
	*prec = mgTest.GetPrecision ();
	*latFrmt = mgTest.GetLatFrmt ();
	*lngFrmt = mgTest.GetLngFrmt ();
	return;
}
/////////////////////////////////////////////////////////////////////////////
// CmgTest dialog
CmgTest::CmgTest(CWnd* pParent /*=NULL*/)
	: CDialog(CmgTest::IDD, pParent)
{
	//{{AFX_DATA_INIT(CmgTest)
	m_Bessel = FALSE;
	m_MgrsString = _T("");
	m_Precision = 5;
	m_Ellipsoid = _T("");
	m_Latitude = 0.0;
	m_Longitude = 0.0;
	m_Easting = 0.0;
	m_Northing = 0.0;
	//}}AFX_DATA_INIT

	m_ElKeyName [0] = '\0';
	m_Zone = 0;
	m_ERad = 6378137.0;
	m_ESqr = 0.00669437999013;
	m_LngFrmt = cs_ATOF_LNGDFLT;
	m_LatFrmt = cs_ATOF_LATDFLT;
	m_XFrmt   = cs_ATOF_XXXDFLT;
	m_YFrmt   = cs_ATOF_YYYDFLT;
}
void CmgTest::SetEllipsoid (const char *elKeyName)
{
	CS_stncp (m_ElKeyName,elKeyName,sizeof (m_ElKeyName));
}
const char* CmgTest::GetEllipsoid ()
{
	return m_ElKeyName;
}
void CmgTest::SetMgrsString (const char *mgrsString)
{
	m_MgrsString = mgrsString;
}
const char* CmgTest::GetMgrsString ()
{
	return (LPCTSTR)m_MgrsString;
}
BOOL CmgTest::OnInitDialog ()
{
	BOOL rtnValue;
	struct cs_Eldef_ *elDef;
	char bufr [256];

	rtnValue = CDialog::OnInitDialog ();
	// Set the ellipsoid name.

	if (m_ElKeyName [0] != '\0')
	{
		elDef = CS_eldef (m_ElKeyName);
		if (elDef == NULL)
		{
			strcpy (m_ElKeyName,"WGS84");
			m_ERad = 6378137.0;
			m_ESqr = 0.00669437999013;
			m_Ellipsoid = "World Geodetic System of 1984";
		}
		else
		{
			m_ERad = elDef->e_rad;
			m_ESqr = elDef->ecent * elDef->ecent;
			m_Ellipsoid = elDef->name;
		}
	}
	else
	{
		strcpy (m_ElKeyName,"WGS84");
		m_ERad = 6378137.0;
		m_ESqr = 0.00669437999013;
		m_Ellipsoid = "World Geodetic System of 1984";
	}

	m_Mgrs = CSnewMgrs (m_ERad,m_ESqr,m_Bessel ? 1 : 0);
	if (m_Mgrs == NULL)
	{
		CS_errmsg (bufr,sizeof (bufr));
		AfxMessageBox (bufr);
	}
	// Set up the zone combo box.  We use indicies of 0 through 122.
	m_ZoneCombo.ResetContent ();
	for (int idx = 0;idx <= 122;idx += 1)
	{
		if (idx == 0) m_ZoneCombo.AddString ("Error");
		else if (idx <= 60)
		{
			sprintf (bufr,"%dN",idx);
			m_ZoneCombo.AddString (bufr);
		}
		else if (idx <= 120)
		{
			sprintf (bufr,"%dS",(idx - 60));
			m_ZoneCombo.AddString (bufr);
		}
		else if (idx == 121) m_ZoneCombo.AddString ("North Polar");
		else if (idx == 122) m_ZoneCombo.AddString ("South Polar");
	}

	// Set up the spinner for precision.

	CWnd* wPtr = GetDlgItem (IDC_MGTST_PREC);
	if (wPtr != 0) m_PrecSpin.SetBuddy (wPtr);
	m_PrecSpin.SetBase (10);
	m_PrecSpin.SetRange (0,5);
	m_PrecSpin.SetPos (m_Precision);

	// Disable the Help button if help isn't available.
	CWnd* wp = GetDlgItem (ID_MGTST_HELP);
	if (wp != NULL) wp->EnableWindow (CS_isHlpAvailable ());

	// Update the display
	UpdateData (FALSE);
	
	// If the MGRS String is not empty, call the MGRS Calculate function.
	if (!m_MgrsString.IsEmpty ())
	{
		OnMgtstMgrsbtn();
	}
	return rtnValue;
}
void CmgTest::DoDataExchange(CDataExchange* pDX)
{
	int curSel;

	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CmgTest)
	DDX_Control(pDX, IDC_MGTST_ZONECOMBO, m_ZoneCombo);
	DDX_Control(pDX, IDC_MGTST_PRECSPIN, m_PrecSpin);
	DDX_Check (pDX, IDC_MGTST_BESSEL, m_Bessel);
	DDX_Text (pDX,IDC_MGTST_MGRS,m_MgrsString);
	DDX_Text (pDX,IDC_MGTST_PREC,m_Precision);
	DDV_MinMaxInt (pDX, m_Precision,0,5);
	DDX_Text (pDX,IDC_MGTST_ELLIPSOID, m_Ellipsoid);
	//}}AFX_DATA_MAP

	if (pDX->m_bSaveAndValidate)
	{
		curSel = m_ZoneCombo.GetCurSel ();
		if      (curSel ==   0) m_Zone = 0;
		else if (curSel <=  60) m_Zone = curSel;
		else if (curSel <= 120) m_Zone = 60 - curSel;
		else if (curSel == 121) m_Zone = 61;
		else if (curSel == 122) m_Zone = -61;
		else                    m_Zone = 0;
	}
	else
	{
		if      (m_Zone ==   0) curSel = 0;
		else if (m_Zone == -61) curSel = 122;
		else if (m_Zone ==  61) curSel = 121;
		else if (m_Zone <    0) curSel = 60 - m_Zone;
		else if (m_Zone >    0) curSel = m_Zone;
		m_ZoneCombo.SetCurSel (curSel);
	}

	DDX_Coord (pDX,IDC_MGTST_LAT,m_Latitude,&m_LatFrmt);
	DDX_Coord (pDX,IDC_MGTST_LONG,m_Longitude,&m_LngFrmt);

	long xxx, yyy;
	xxx = m_XFrmt;	yyy = m_YFrmt;
	DDX_Coord (pDX,IDC_MGTST_UTMX, m_Easting,&xxx);
	DDX_Coord (pDX,IDC_MGTST_UTMY,m_Northing,&yyy);
}

BEGIN_MESSAGE_MAP(CmgTest, CDialog)
	//{{AFX_MSG_MAP(CmgTest)
	ON_BN_CLICKED(ID_MGTST_HELP, OnMgtstHelp)
	ON_BN_CLICKED(IDC_MGTST_LATLNGBTN, OnMgtstLatlngbtn)
	ON_BN_CLICKED(IDC_MGTST_BESSEL, OnMgtstBessel)
	ON_BN_CLICKED(IDC_MGTST_MGRSBTN, OnMgtstMgrsbtn)
	ON_BN_CLICKED(IDC_MGTST_UTMBTN, OnMgtstUtmbtn)
	ON_BN_CLICKED(IDC_MGTST_ELSELECT, OnMgtstElselect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CmgTest message handlers

void CmgTest::OnMgtstHelp() 
{
	CSwinhlp (m_hWnd,csHLPID_MGRS_TEST);
}

void CmgTest::OnMgtstLatlngbtn() 
{
	int st;
	char bufr [256];
	double latLng [2];
	double utmUps [2];

	if (!UpdateData (TRUE)) return;
	if (m_Mgrs == NULL)
	{
		AfxMessageBox ("MGRS system initialization failed.");
	}

	m_MgrsString.Empty ();
	m_Easting = m_Northing = 0.0;

	latLng [0] = m_Longitude;
	latLng [1] = m_Latitude;
	m_Zone = CScalcUtmUps (m_Mgrs,utmUps,latLng);
	if (m_Zone == 0)
	{
		CS_errmsg (bufr,sizeof (bufr));
		AfxMessageBox (bufr);
	}
	else
	{
		m_Easting = utmUps [0];
		m_Northing = utmUps [1];
		st = CScalcMgrsFromLlUtm (m_Mgrs,bufr,sizeof (bufr),latLng,utmUps,m_Precision);
		if (st != 0)
		{
			CS_errmsg (bufr,sizeof (bufr));
			AfxMessageBox (bufr);
		}
		else
		{
			m_MgrsString = bufr;
		}
	}
	UpdateData (FALSE);
}

void CmgTest::OnMgtstBessel() 
{
	if (!UpdateData (TRUE)) return;

	CSdeleteMgrs (m_Mgrs);
	m_Mgrs = NULL;	
	m_Mgrs = CSnewMgrs (m_ERad,m_ESqr,m_Bessel ? 1 : 0);
	return;
}

void CmgTest::OnMgtstMgrsbtn() 
{
	int st;
	char bufr [256];
	double latLng [2];
	double utmUps [2];

	if (!UpdateData (TRUE)) return;
	if (m_Mgrs == NULL)
	{
		AfxMessageBox ("MGRS system initialization failed.");
	}

	m_Latitude = m_Longitude = m_Easting = m_Northing = 0.0;

	st = CScalcLlFromMgrs (m_Mgrs,latLng,(LPCTSTR)m_MgrsString);
	if (st != 0)
	{
		CS_errmsg (bufr,sizeof (bufr));
		AfxMessageBox (bufr);
	}
	if (st >= 0)
	{
		m_Latitude = latLng [1];
		m_Longitude = latLng [0];
		m_Zone = CScalcUtmUps (m_Mgrs,utmUps,latLng);
		if (m_Zone == 0)
		{
			CS_errmsg (bufr,sizeof (bufr));
			AfxMessageBox (bufr);
		}
		else
		{
			m_Easting = utmUps [0];
			m_Northing = utmUps [1];
		}
	}
	UpdateData (FALSE);
}

void CmgTest::OnCancel() 
{
	CDialog::OnCancel();
}

void CmgTest::OnMgtstUtmbtn() 
{
	int st;
	char bufr [256];
	double latLng [2];
	double utmUps [2];

	if (!UpdateData (TRUE)) return;
	if (m_Mgrs == NULL)
	{
		AfxMessageBox ("MGRS system initialization failed.");
		return;
	}

	m_MgrsString.Empty ();
	m_Latitude = m_Longitude = 0.0;

	utmUps [0] = m_Easting;
	utmUps [1] = m_Northing;
	st = CScalcLatLng (m_Mgrs,latLng,utmUps,m_Zone);
	if (st != 0)
	{
		CS_errmsg (bufr,sizeof (bufr));
		AfxMessageBox (bufr);
	}
	else
	{
		m_Longitude = latLng [0];
		m_Latitude = latLng [1];
		st = CScalcMgrsFromLlUtm (m_Mgrs,bufr,sizeof (bufr),latLng,utmUps,m_Precision);
		if (st != 0)
		{
			CS_errmsg (bufr,sizeof (bufr));
			AfxMessageBox (bufr);
		}
		else
		{
			m_MgrsString = bufr;
		}
	}
	UpdateData (FALSE);
}

void CmgTest::OnMgtstElselect() 
{
	int st;
	struct cs_Eldef_ *elDef;
	char bufr [256];
	CelSelect elSelect;

	elSelect.SetInitialEllipsoid (m_ElKeyName);
	st = elSelect.DoModal ();
	if (st == IDOK)
	{
		CSdeleteMgrs (m_Mgrs);
		m_Mgrs = NULL;	
		m_Longitude = m_Latitude = m_Easting = m_Northing = 0.0;
		CS_stncp (m_ElKeyName,elSelect.GetSelectedEllipsoid (),sizeof (m_ElKeyName));
		elDef = CS_eldef (m_ElKeyName);
		if (elDef == NULL)
		{
			CS_errmsg (bufr,sizeof (bufr));
			AfxMessageBox (bufr);
		}
		else
		{
			m_ERad = elDef->e_rad;
			m_ESqr = elDef->ecent * elDef->ecent;
			m_Ellipsoid = elDef->name;
			m_Mgrs = CSnewMgrs (m_ERad,m_ESqr,m_Precision);
			if (m_Mgrs == NULL)
			{
				CS_errmsg (bufr,sizeof (bufr));
				AfxMessageBox (bufr);
			}
		}
		UpdateData (FALSE);
	}
}

long AFXAPI DDX_Coord (CDataExchange* pDX,int nIDC,double& value,long* frmt)
{
	int err_flg;

	long st;

	double dtmp;

	char buffer [32];

	err_flg = FALSE;
	HWND hWndCtrl = pDX->PrepareEditCtrl(nIDC);

	if (pDX->m_bSaveAndValidate)
	{
		::GetWindowText(hWndCtrl,buffer,sizeof (buffer));
		st = CS_atof (&dtmp,buffer);
		value = dtmp;
		if (st < 0L)
		{
			err_flg = TRUE;

			// A problem was detected in the conversion to
			// double.  Tell the user what the problem is
			// and throw an exception.

			if ((st & cs_ATOF_SECS60) != 0)
			{
				AfxMessageBox ("Value expected to be seconds was 60 or larger.");
			}
			else if ((st & cs_ATOF_MINS60) != 0)
			{
				AfxMessageBox ("Value expected to be minutes was 60 or larger.");
			}
			else if ((st & cs_ATOF_MLTPNT) != 0)
			{
				AfxMessageBox ("Multiple decimal points encountered, value intended is ambiguous.");
			}
			else if ((st & cs_ATOF_MLTSGN) != 0)
			{
				AfxMessageBox ("Multiple sign indications were encountered, value intended is ambiguous.");
			}
			else if ((st & cs_ATOF_ERRCMA) != 0)
			{
				AfxMessageBox ("Thousands separator was used inconsistently, value intended is ambiguous.");
			}
			else
			{
				AfxMessageBox ("Numeric input formatting error.");
			}
		}
		if ((*frmt & cs_ATOF_VALLNG) != 0 &&
		    fabs (dtmp) > 200.0)
		{
			err_flg = TRUE;
			AfxMessageBox ("Longitude value provided is suspiciously large.");
		}
		else if ((*frmt & cs_ATOF_VALLAT) != 0 &&
		          fabs (dtmp) > 90.0)
		{
			err_flg = TRUE;
			AfxMessageBox ("Latitude value provided is suspiciously large.");
		}
		if (err_flg)
		{
			pDX->Fail ();
		}

		// Return the format to the calling function.
		*frmt = st;
	}
	else
	{
		dtmp = value;
		st = CS_ftoa (buffer,sizeof (buffer),dtmp,*frmt);
		::SetWindowText (hWndCtrl,buffer);
	}
	return (st);
}
#endif
