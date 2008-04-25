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

			 File Name: $RCSfile: csTest.cpp $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #5 $
		 Check In Date:	$Date: 2006/11/25 $

		Last Revision:	$Log: csTest.cpp $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:05  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1201  2005/05/25 00:38:30  nto
		Last Revision:	Added a CS_recvr () to eliminate the appearance of a memory leak.
		Last Revision:	Revision 11.1200  2005/01/15 18:27:08  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
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
		Last Revision:	Revision 11.501  2003/08/22 21:12:52  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:19  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:13  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:40  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1500  2002/09/22 00:01:16  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:19  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:11  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:33  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:24  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:08  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:43  nto
		Last Revision:	Revision 10.601  2001/01/25 04:07:21  nto
		Last Revision:	Switched the datum error processing to the ten and ignore mode.
		Last Revision:	Revision 10.600  2000/12/11 06:39:37  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:15  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.401  2000/10/27 03:49:25  nto
		Last Revision:	Datum errors are know properly reported.
		Last Revision:	Revision 10.400  2000/09/13 01:16:49  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:20  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:12  nto
		Last Revision:	Revision 10.4  2000/02/14 07:06:11  nto
		Last Revision:	Added the use of CS_cs3ll and CS_ll3cs when 3D is checked.
		Last Revision:	Revision 10.3  2000/02/11 06:21:45  nto
		Last Revision:	Added the 3D conversion type.
		Last Revision:	Revision 10.2  2000/01/31 00:24:05  nto
		Last Revision:	PCLint clean up.
		Last Revision:	Revision 10.1  1999/11/03 23:41:10  nto
		Last Revision:	Results of datum conversion rewrite.
		Last Revision:	Revision 10.0  1999/10/05 18:27:11  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:22  nto
		Last Revision:	Revision 1.2  1999/09/12 03:07:44  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/csTest.cpp#5 $"};
#endif

#if defined (__MFC__)

#include "cs_map.h"
#include "cs_mfc.h"
#include "cs_hlp.h"

/**********************************************************************
**	CcsTest csTest;
**	Lots and lots opf member functions, see the header file.
**********************************************************************/

///////////////////////////////////////////////////////////////////////////////
// C callable function.  Note, name is not mangled for easy access from Visual
//	Basic, et al.
extern "C" void EXP_LVL1 CS_csTest (char *srcSystem,char *trgSystem,double srcXYZ [3])
{
	CcsTest csTest;
	CS_recvr ();
	csTest.SetSourceSystem (srcSystem);
	csTest.SetTargetSystem (trgSystem);
	csTest.SetSourceCoordinate (srcXYZ);
	csTest.DoModal ();
	// Must capture the final settings, for persistence, before the
	// class goes out of scope.
	CS_stncp (srcSystem,csTest.GetSourceSystem (),cs_KEYNM_DEF);
	CS_stncp (trgSystem,csTest.GetTargetSystem (),cs_KEYNM_DEF);
	csTest.GetSourceCoordinate (srcXYZ);
	
	// The Test object uses the high level caches.  The following
	// releases the memory consumed by such, and eliminates what
	// appears to be a memory leak.
	CS_recvr ();
	return;
}
/////////////////////////////////////////////////////////////////////////////
// CcsTest dialog
CcsTest::CcsTest(CWnd* pParent /*=NULL*/)
	: CDialog(CcsTest::IDD, pParent)
{
	//{{AFX_DATA_INIT(CcsTest)
	m_SrcConvergence = _T("");
	m_SrcDatumKeyName = _T("");
	m_SrcDatumLabel = _T("");
	m_SrcDescription = _T("");
	m_SrcKeyName = _T("");
	m_SrcSource = _T("");
	m_SrcStatus = _T("");
	m_SrcUnit = _T("");
	m_SrcXLatitude = _T("");
	m_SrcXLatLabel = _T("");
	m_SrcYLongitude = _T("");
	m_SrcZHeight = _T("");
	m_TrgConvergence = _T("");
	m_TrgDatLabel = _T("");
	m_TrgDescription = _T("");
	m_TrgDatumKeyName = _T("");
	m_TrgGridScale = _T("");
	m_TrgKeyName = _T("");
	m_TrgSource = _T("");
	m_TrgStatus = _T("");
	m_TrgUnit = _T("");
	m_TrgXLatLabel = _T("");
	m_SrcGridScale = _T("");
	m_TrgXLatitude = _T("");
	m_TrgYLongitude = _T("");
	m_TrgZHeight = _T("");
	m_DecimalDegrees = FALSE;
	m_HighPrecision = TRUE;
	m_SrcYLngLabel = _T("");
	m_TrgYLngLabel = _T("");
	m_SrcZHgtLabel = _T("");
	m_SrcZHgtLabel = _T("");
	m_SrcSPZone83 = FALSE;
	m_TrgSPZone83 = FALSE;
	m_ThreeDCalc = FALSE;
	//}}AFX_DATA_INIT
	m_SourceXY [0] = 0.0;
	m_SourceXY [1] = 0.0;
	m_SourceXY [3] = 0.0;
	m_SourceScale = 1.0;
	m_SourceConvergence = 0.0;
	m_TargetXY [0] = 0.0;
	m_TargetXY [1] = 0.0;
	m_TargetXY [2] = 0.0;
	m_TargetScale = 1.0;
	m_TargetConvergence = 0.0;
}

BOOL CcsTest::OnInitDialog ()
{
	CWnd *wp;

	CDialog::OnInitDialog ();

	UpdateSource ();
	if (m_SrcKeyName.IsEmpty ()) m_SrcKeyName = "US48";
	if (m_TrgKeyName.IsEmpty ()) m_TrgKeyName = "LL27";
	SetLabels (true);
	SetLabels (false);
	FetchSource ();
	Calculate ();
	UpdateSource ();
	UpdateTarget ();
	UpdateData (FALSE);

	// Disable the Help button if help is not available.
	wp = GetDlgItem (ID_CSTST_HELP);
	if (wp != NULL) wp->EnableWindow (CS_isHlpAvailable ());

	return (TRUE);
};

void CcsTest::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CcsTest)
	DDX_Text(pDX, IDC_CSTST_SRCCNVRG, m_SrcConvergence);
	DDX_Text(pDX, IDC_CSTST_SRCDATKYNM, m_SrcDatumKeyName);
	DDX_Text(pDX, IDC_CSTST_SRCDATLBL, m_SrcDatumLabel);
	DDX_Text(pDX, IDC_CSTST_SRCDESCR, m_SrcDescription);
	DDV_MaxChars(pDX, m_SrcDescription, 64);
	DDX_Text(pDX, IDC_CSTST_SRCKEYNM, m_SrcKeyName);
	DDX_Text(pDX, IDC_CSTST_SRCSRC, m_SrcSource);
	DDX_Text(pDX, IDC_CSTST_SRCSTAT, m_SrcStatus);
	DDX_Text(pDX, IDC_CSTST_SRCUNIT, m_SrcUnit);
	DDX_Text(pDX, IDC_CSTST_SRCXLAT, m_SrcXLatitude);
	DDX_Text(pDX, IDC_CSTST_SRCXLATLBL, m_SrcXLatLabel);
	DDX_Text(pDX, IDC_CSTST_SRCYLNG, m_SrcYLongitude);
	DDX_Text(pDX, IDC_CSTST_SRCZHGT, m_SrcZHeight);
	DDX_Text(pDX, IDC_CSTST_TRGCNVRG, m_TrgConvergence);
	DDX_Text(pDX, IDC_CSTST_TRGDATLBL, m_TrgDatLabel);
	DDX_Text(pDX, IDC_CSTST_TRGDESCR, m_TrgDescription);
	DDX_Text(pDX, IDC_CSTST_TRGDTKY, m_TrgDatumKeyName);
	DDX_Text(pDX, IDC_CSTST_TRGGRIDSCL, m_TrgGridScale);
	DDX_Text(pDX, IDC_CSTST_TRGKEYNM, m_TrgKeyName);
	DDX_Text(pDX, IDC_CSTST_TRGSRC, m_TrgSource);
	DDX_Text(pDX, IDC_CSTST_TRGSTAT, m_TrgStatus);
	DDX_Text(pDX, IDC_CSTST_TRGUNIT, m_TrgUnit);
	DDX_Text(pDX, IDC_CSTST_TRGXLATLBL, m_TrgXLatLabel);
	DDX_Text(pDX, IDC_CSTST_SRCGRIDSCL, m_SrcGridScale);
	DDX_Text(pDX, IDC_CSTST_TRGXLAT, m_TrgXLatitude);
	DDX_Text(pDX, IDC_CSTST_TRGYLNG, m_TrgYLongitude);
	DDX_Text(pDX, IDC_CSTST_TRGZHGT, m_TrgZHeight);
	DDX_Check(pDX, IDC_CSTST_DECIMAL, m_DecimalDegrees);
	DDX_Check(pDX, IDC_CSTST_HIGHPREC, m_HighPrecision);
	DDX_Check(pDX, IDC_CSTST_3DCHECK, m_ThreeDCalc);
	DDX_Text(pDX, IDC_CSTST_SRCYLNGLBL, m_SrcYLngLabel);
	DDX_Text(pDX, IDC_CSTST_TRGYLNGLBL, m_TrgYLngLabel);
	DDX_Check(pDX, IDC_CSTST_SRCSP83, m_SrcSPZone83);
	DDX_Check(pDX, IDC_CSTST_TRGSP83, m_TrgSPZone83);
	//}}AFX_DATA_MAP

	if (pDX->m_bSaveAndValidate)
	{
		char csKeyName [cs_KEYNM_DEF];
		CS_stncp (csKeyName,m_SrcKeyName,sizeof (csKeyName));
		CS_spZoneNbrMap (csKeyName,m_SrcSPZone83);
		m_SrcKeyName = csKeyName;
		CS_stncp (csKeyName,m_TrgKeyName,sizeof (csKeyName));
		CS_spZoneNbrMap (csKeyName,m_TrgSPZone83);
		m_TrgKeyName = csKeyName;
	}
}

BEGIN_MESSAGE_MAP(CcsTest, CDialog)
	//{{AFX_MSG_MAP(CcsTest)
	ON_BN_CLICKED(ID_CSTST_CALCULATE, OnCststCalculate)
	ON_BN_CLICKED(ID_CSTST_REVERSE, OnCststReverse)
	ON_BN_CLICKED(ID_HELP, OnHelp)
	ON_EN_KILLFOCUS(IDC_CSTST_SRCKEYNM, OnKillfocusCststSrckeynm)
	ON_EN_KILLFOCUS(IDC_CSTST_TRGKEYNM, OnKillfocusCststTrgkeynm)
	ON_EN_CHANGE(IDC_CSTST_SRCKEYNM, OnChange)
	ON_BN_CLICKED(IDC_CSTST_SRCCSBTN, OnCststSrccsbtn)
	ON_BN_CLICKED(IDC_CSTST_TRGCSBTN, OnCststTrgcsbtn)
	ON_BN_CLICKED(IDC_CSTST_3DCHECK, OnCstst3DCheck)
	ON_EN_CHANGE(IDC_CSTST_SRCXLAT, OnChange)
	ON_EN_CHANGE(IDC_CSTST_SRCYLNG, OnChange)
	ON_EN_CHANGE(IDC_CSTST_TRGKEYNM, OnChange)
	ON_BN_CLICKED(ID_CSTST_HELP, OnCststHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
//	Support Functions

void CcsTest::SetSourceSystem (const char* srcSystem)
{
	m_SrcKeyName = srcSystem;
}
void CcsTest::SetTargetSystem (const char* trgSystem)
{
	m_TrgKeyName = trgSystem;
}
void CcsTest::SetSourceCoordinate (const double srcXY [3])
{
	m_SourceXY [0] = srcXY [0];
	m_SourceXY [1] = srcXY [1];
	m_SourceXY [2] = srcXY [2];
}
const char* CcsTest::GetSourceSystem ()
{
	return m_SrcKeyName;
}
const char* CcsTest::GetTargetSystem ()
{
	return m_TrgKeyName;
}
void CcsTest::GetSourceCoordinate (double* srcXY)
{
	srcXY [0] = m_SourceXY [0];
	srcXY [1] = m_SourceXY [1];
	srcXY [2] = m_SourceXY [2];
}
void CcsTest::UpdateSource ()
{
	int prec;
	long frmtXLat, frmtYLng, frmtZHgt;
	char ctemp [24];

	// Is this a geographic coordinate???
	if (CS_isgeo (m_SrcKeyName))
	{
		if (m_DecimalDegrees)
		{
			prec = m_HighPrecision ? 13 : 9;
			frmtXLat = prec;
			frmtYLng = prec;
		}
		else
		{
			prec = m_HighPrecision ? 6 : 2;
			frmtXLat = cs_ATOF_MINSEC | cs_ATOF_DIRCHR | (prec + 1);
			frmtYLng = cs_ATOF_MINSEC | cs_ATOF_DIRCHR | cs_ATOF_XEAST | (prec + 1);
		}
		prec = m_HighPrecision ? 4 : 1;
		frmtZHgt = cs_ATOF_COMMA | (prec + 1);

		CS_ftoa (ctemp,sizeof (ctemp),m_SourceXY [1],frmtXLat);
		m_SrcXLatitude = ctemp;
		CS_ftoa (ctemp,sizeof (ctemp),m_SourceXY [0],frmtYLng);
		m_SrcYLongitude = ctemp;
		CS_ftoa (ctemp,sizeof (ctemp),m_SourceXY [2],frmtZHgt);
		m_SrcZHeight = ctemp;

		m_SrcGridScale = "Not Applicable";
		m_SrcConvergence = "Not Applicable";
	}
	else
	{
		prec = m_HighPrecision ? 5 : 3;
		frmtXLat = cs_ATOF_COMMA | (prec + 1);
		frmtYLng = cs_ATOF_COMMA | (prec + 1);
		frmtZHgt = cs_ATOF_COMMA | (prec + 1);
		CS_ftoa (ctemp,sizeof (ctemp),m_SourceXY [0],frmtXLat);
		m_SrcXLatitude = ctemp;
		CS_ftoa (ctemp,sizeof (ctemp),m_SourceXY [1],frmtYLng);
		m_SrcYLongitude = ctemp;
		CS_ftoa (ctemp,sizeof (ctemp),m_SourceXY [2],frmtZHgt);
		m_SrcZHeight = ctemp;

		// Grid Scale for the source system.
		if (m_SourceScale >= 9999.00)
		{
			m_SrcGridScale = "Infinite";
		}
		else if (m_SourceScale > 0.0)
		{
			prec = m_HighPrecision ? 9 : 5;
			CS_ftoa (ctemp,sizeof (ctemp),m_SourceScale,(prec + 1));
			m_SrcGridScale = ctemp;
		}
		else if (m_SourceScale < 0.0)
		{
			m_SrcGridScale = "Domain Err";
		}
		else
		{
			m_SrcGridScale = "";
		}

		// Convergence for the source system.
		if (m_SourceConvergence > -360.0)
		{
			if (m_DecimalDegrees)
			{
				prec = m_HighPrecision ? 9 : 5;
				CS_ftoa (ctemp,sizeof (ctemp),m_SourceConvergence,(prec + 1));
				m_SrcConvergence = ctemp;
			}
			else
			{
				prec = m_HighPrecision ? 4 : 0;
				frmtYLng = cs_ATOF_MINSEC | cs_ATOF_DIRCHR | cs_ATOF_XEAST | (prec + 1);
				CS_ftoa (ctemp,sizeof (ctemp),m_SourceConvergence,frmtYLng);
				m_SrcConvergence = ctemp;
			}
		}
		else if (m_SourceConvergence == -360.0)
		{
			m_SrcConvergence = "Domain Err";
		}
		else
		{
			m_SrcConvergence = "";
		}
	}
	return;
}
void CcsTest::UpdateTarget ()
{
	int prec;
	long frmtXLat, frmtYLng, frmtZHgt;
	char ctemp [24];

	// Is this a geographic coordinate???
	if (CS_isgeo (m_TrgKeyName))
	{
		if (m_DecimalDegrees)
		{
			prec = m_HighPrecision ? 13 : 9;
			frmtXLat = prec;
			frmtYLng = prec;
		}
		else
		{
			prec = m_HighPrecision ? 6 : 2;
			frmtXLat = cs_ATOF_MINSEC | cs_ATOF_DIRCHR | (prec + 1);
			frmtYLng = cs_ATOF_MINSEC | cs_ATOF_DIRCHR | cs_ATOF_XEAST | (prec + 1);
		}
		prec = m_HighPrecision ? 4 : 2;
		frmtZHgt = cs_ATOF_COMMA | (prec + 1);

		CS_ftoa (ctemp,sizeof (ctemp),m_TargetXY [1],frmtXLat);
		m_TrgXLatitude = ctemp;
		CS_ftoa (ctemp,sizeof (ctemp),m_TargetXY [0],frmtYLng);
		m_TrgYLongitude = ctemp;
		CS_ftoa (ctemp,sizeof (ctemp),m_TargetXY [2],frmtZHgt);
		m_TrgZHeight = ctemp;
		m_TrgGridScale = "Not Applicable";
		m_TrgConvergence = "Not Applicable";
	}
	else
	{
		prec = m_HighPrecision ? 5 : 3;
		frmtXLat = cs_ATOF_COMMA | (prec + 1);
		frmtYLng = cs_ATOF_COMMA | (prec + 1);
		frmtZHgt = cs_ATOF_COMMA | (prec + 1);
		CS_ftoa (ctemp,sizeof (ctemp),m_TargetXY [0],frmtXLat);
		m_TrgXLatitude = ctemp;
		CS_ftoa (ctemp,sizeof (ctemp),m_TargetXY [1],frmtYLng);
		m_TrgYLongitude = ctemp;
		CS_ftoa (ctemp,sizeof (ctemp),m_TargetXY [2],frmtZHgt);
		m_TrgZHeight = ctemp;
		// Grid Scale for the target system.
		if (m_TargetScale >= 9999.00)
		{
			m_TrgGridScale = "Infinite";
		}
		else if (m_TargetScale > 0.0)
		{
			prec = m_HighPrecision ? 9 : 5;
			CS_ftoa (ctemp,sizeof (ctemp),m_TargetScale,(prec + 1));
			m_TrgGridScale = ctemp;
		}
		else if (m_TargetScale < 0.0)
		{
			m_TrgGridScale = "Domain Err";
		}
		else
		{
			m_TrgGridScale = "";
		}
		// Convergence for the source system.
		if (m_TargetConvergence > -360.0)
		{
			if (m_DecimalDegrees)
			{
				prec = m_HighPrecision ? 9 : 5;
				CS_ftoa (ctemp,sizeof (ctemp),m_TargetConvergence,(prec + 1));
				m_TrgConvergence = ctemp;
			}
			else
			{
				prec = m_HighPrecision ? 4 : 0;
				frmtYLng = cs_ATOF_MINSEC | cs_ATOF_DIRCHR | cs_ATOF_XEAST | (prec + 1);
				CS_ftoa (ctemp,sizeof (ctemp),m_TargetConvergence,frmtYLng);
				m_TrgConvergence = ctemp;
			}
		}
		else if (m_TargetConvergence == -360.0)
		{
			m_TrgConvergence = "Domain Err";
		}
		else
		{
			m_TrgConvergence = "";
		}
	}
	return;
}
CWnd* CcsTest::FetchSource ()
{
	CWnd* errorPtr;
	long format;

	errorPtr = NULL;
	if (CS_isgeo (m_SrcKeyName))
	{
		format = CS_atof (&m_SourceXY [1],(LPCTSTR)m_SrcXLatitude);
		if (format < 0L) errorPtr = GetDlgItem (IDC_CSTST_SRCXLAT);
		else
		{
			format = CS_atof (&m_SourceXY [0],(LPCTSTR)m_SrcYLongitude);
			if (format < 0L) errorPtr = GetDlgItem (IDC_CSTST_SRCYLNG);
			else
			{
				format = CS_atof (&m_SourceXY [2],(LPCTSTR)m_SrcZHeight);
				if (format < 0L) errorPtr = GetDlgItem (IDC_CSTST_SRCZHGT);
			}
		}
	}
	else
	{
		format = CS_atof (&m_SourceXY [0],(LPCTSTR)m_SrcXLatitude);
		if (format < 0L) errorPtr = GetDlgItem (IDC_CSTST_SRCXLAT);
		else
		{
			format = CS_atof (&m_SourceXY [1],(LPCTSTR)m_SrcYLongitude);
			if (format < 0L) errorPtr = GetDlgItem (IDC_CSTST_SRCYLNG);
			else
			{
				format = CS_atof (&m_SourceXY [2],(LPCTSTR)m_SrcZHeight);
				if (format < 0L) errorPtr = GetDlgItem (IDC_CSTST_SRCZHGT);
			}
		}
	}
	return errorPtr;
}
bool CcsTest::SetLabels (bool target)
{
	struct cs_Csprm_ *csPtr;

	if (!target)
	{
		csPtr = CSbcclu (m_SrcKeyName);
		if (csPtr == NULL) return false;
		m_SrcDescription = csPtr->csdef.desc_nm;
		m_SrcSource = csPtr->csdef.source;
		if (csPtr->csdef.dat_knm [0] != '\0')
		{
			m_SrcDatumLabel = "Datum:";
			m_SrcDatumKeyName = csPtr->csdef.dat_knm;
		}
		else
		{
			m_SrcDatumLabel = "Ellipsoid:";
			m_SrcDatumKeyName = csPtr->csdef.elp_knm;
		}
		m_SrcUnit = csPtr->csdef.unit;
		if ((csPtr->prj_flags & cs_PRJFLG_GEOGR) == 0)
		{
			m_SrcXLatLabel = "X/Easting";
			m_SrcYLngLabel = "Y/Northing";
			if (m_ThreeDCalc) m_SrcZHgtLabel = "Z/Elevation";
			else              m_SrcZHgtLabel = "";
		}
		else
		{
			m_SrcXLatLabel = "Latitude";
			m_SrcYLngLabel = "Longitude";
			if (m_ThreeDCalc) m_SrcZHgtLabel = "Height";
			else              m_SrcZHgtLabel = "";
		}
	}
	else
	{
		csPtr = CSbcclu (m_TrgKeyName);
		if (csPtr == NULL) return false;
		m_TrgDescription = csPtr->csdef.desc_nm;
		m_TrgSource = csPtr->csdef.source;
		if (csPtr->csdef.dat_knm [0] != '\0')
		{
			m_TrgDatLabel = "Datum:";
			m_TrgDatumKeyName = csPtr->csdef.dat_knm;
		}
		else
		{
			m_TrgDatLabel = "Ellipsoid:";
			m_TrgDatumKeyName = csPtr->csdef.elp_knm;
		}
		m_TrgUnit = csPtr->csdef.unit;
		if ((csPtr->prj_flags & cs_PRJFLG_GEOGR) == 0)
		{
			m_TrgXLatLabel = "X/Easting";
			m_TrgYLngLabel = "Y/Northing";
			if (m_ThreeDCalc) m_TrgZHgtLabel = "Z/Elevation";
			else              m_TrgZHgtLabel = "";
		}
		else
		{
			m_TrgXLatLabel = "Latitude";
			m_TrgYLngLabel = "Longitude";
			if (m_ThreeDCalc) m_TrgZHgtLabel = "Height";
			else              m_TrgZHgtLabel = "";
		}
	}
	return true;
}
CWnd* CcsTest::Calculate ()
{
	int status;
	CWnd* errorPtr;
	struct cs_Csprm_ *srcPtr;
	struct cs_Csprm_ *trgPtr;
	struct cs_Dtcprm_ *dtcPtr;
	double xy [3], ll [3];
	char ctemp [512];

	errorPtr = FetchSource ();
	if (errorPtr != NULL) goto error;

	xy [0] = m_SourceXY [0];
	xy [1] = m_SourceXY [1];
	if (m_ThreeDCalc) xy [2] = m_SourceXY [2];
	else              xy [2] = 0.0;

	// Set up the conversion.
	srcPtr = CSbcclu (m_SrcKeyName);
	if (srcPtr == NULL)
	{
		errorPtr = GetDlgItem (IDC_CSTST_SRCKEYNM);
		goto error;
	}
	trgPtr = CSbcclu (m_TrgKeyName);
	if (trgPtr == NULL)
	{
		errorPtr = GetDlgItem (IDC_CSTST_TRGKEYNM);
		goto error;
	}
	dtcPtr = CSbdclu (srcPtr,trgPtr,cs_DTCFLG_DAT_W,cs_DTCFLG_BLK_10);
	if (dtcPtr == NULL)
	{
		errorPtr = GetDlgItem (IDC_CSTST_SRCKEYNM);
		goto error;
	}

	// Do the conversion
	if (m_ThreeDCalc)
	{
		status = CS_cs3ll (srcPtr,ll,xy);
	}
	else
	{
		status = CS_cs2ll (srcPtr,ll,xy);
	}

	if (status == cs_CNVRT_OK)
	{
		m_SrcStatus = "OK";
	}
	else if (status == cs_CNVRT_USFL)
	{
		m_SrcStatus = "Range";
	}
	else if (status == cs_CNVRT_DOMN)
	{
		m_SrcStatus = "Domain";
	}
	else if (status = cs_CNVRT_DEMO)
	{
		m_SrcStatus = "Demo";
	}
	else
	{
		m_SrcStatus = "???";
	}
	// Source Grid Scale and Convergence.
	m_SourceScale = CS_csscl (srcPtr,ll);
	m_SourceConvergence = CS_cscnv (srcPtr,ll);
	UpdateSource ();

	// Do the datum shift.
	if (m_ThreeDCalc)
	{
		status = CS_dtcvt3D (dtcPtr,ll,ll);
	}
	else
	{
		status = CS_dtcvt (dtcPtr,ll,ll);
	}
	if (status == 0)
	{
		m_TrgStatus.Empty ();
	}
	else if (status < 0)
	{
		m_TrgStatus = "DtErr";
		errorPtr = GetDlgItem (IDC_CSTST_SRCKEYNM);
		goto error;
	}
	else
	{
		m_TrgStatus = "DtRng";
		CS_errmsg (ctemp,sizeof (ctemp));
		AfxMessageBox (ctemp);
	}

	// Target conversion
	if (m_ThreeDCalc)
	{
		status = CS_ll3cs (trgPtr,xy,ll);
	}
	else
	{
		status = CS_ll2cs (trgPtr,xy,ll);
	}
	if (m_TrgStatus.IsEmpty ())
	{
		if (status == cs_CNVRT_OK)
		{
			m_TrgStatus = "OK";
		}
		else if (status == cs_CNVRT_USFL)
		{
			m_TrgStatus = "Range";
		}
		else if (status == cs_CNVRT_DOMN)
		{
			m_TrgStatus = "Domain";
		}
		else if (status = cs_CNVRT_DEMO)
		{
			m_TrgStatus = "Demo";
		}
		else
		{
			m_TrgStatus = "???";
		}
	}
	m_TargetXY [0] = xy [0];
	m_TargetXY [1] = xy [1];
	if (m_ThreeDCalc) m_TargetXY [2] = xy [2];
	else              m_TargetXY [2] = 0.0;
	// Target Grid Scale and Convergence.
	m_TargetScale = CS_csscl (trgPtr,ll);
	m_TargetConvergence = CS_cscnv (trgPtr,ll);
	// Update the display
	UpdateTarget ();
	UpdateData (FALSE);
	return NULL;
error:
	m_TrgStatus = "Error";
	m_TargetXY [0] = 0.0;
	m_TargetXY [1] = 0.0;
	m_TargetXY [2] = 0.0;
	UpdateTarget ();
	UpdateData (FALSE);
	return errorPtr;
}
/////////////////////////////////////////////////////////////////////////////
// CcsTest message handlers
void CcsTest::OnCststCalculate() 
{
	CWnd* errorPtr;
	CWnd* rvPtr;
	char ctemp [256];

	if (!UpdateData (TRUE)) return;
	errorPtr = Calculate ();
	if (errorPtr != NULL)
	{
		CS_errmsg (ctemp,sizeof (ctemp));
		AfxMessageBox (ctemp);
	}
	else
	{
		errorPtr = GetDlgItem (IDC_CSTST_SRCXLAT);
	}
	GotoDlgCtrl (errorPtr);
	rvPtr = GetDlgItem (ID_CSTST_REVERSE);
	if (rvPtr != NULL) rvPtr->EnableWindow (TRUE);
	UpdateData (FALSE);
}
void CcsTest::OnCststReverse() 
{
	CWnd* errorPtr;
	CString tmpSystem;
	double tmpXY [3];

	// Capture status of the check boxes before we proceed.
	if (!UpdateData (TRUE)) return;
	tmpSystem = m_SrcKeyName;
	m_SrcKeyName = m_TrgKeyName;
	m_TrgKeyName = tmpSystem;
	SetLabels (false);
	SetLabels (true);
	tmpXY [0] = m_SourceXY [0];
	tmpXY [1] = m_SourceXY [1];
	tmpXY [2] = m_SourceXY [2];
	m_SourceXY [0] = m_TargetXY [0];
	m_SourceXY [1] = m_TargetXY [1];
	m_SourceXY [2] = m_TargetXY [2];
	m_TargetXY [0] = tmpXY [0];
	m_TargetXY [1] = tmpXY [1];
	m_TargetXY [2] = tmpXY [2];
	UpdateSource ();
	FetchSource ();
	errorPtr = Calculate ();
	if (errorPtr == NULL)
	{
		UpdateTarget ();
		errorPtr = GetDlgItem (IDC_CSTST_SRCXLAT);
	}
	else
	{
		char ctemp [256];
		CS_errmsg (ctemp,sizeof (ctemp));
		AfxMessageBox (ctemp);
	}
	GotoDlgCtrl (errorPtr);
	UpdateData (FALSE);
	return;
}
void CcsTest::OnHelp() 
{
	CSwinhlp (m_hWnd,csHLPID_CSTEST);
}
void CcsTest::OnKillfocusCststSrckeynm() 
{
	if (!UpdateData (TRUE)) return;
	SetLabels (false);
	UpdateData (FALSE);	
}
void CcsTest::OnKillfocusCststTrgkeynm() 
{
	if (!UpdateData (TRUE)) return;
	SetLabels (true);
	UpdateData (FALSE);	
}

void CcsTest::OnChange() 
{
	CWnd* rvPtr;
	
	rvPtr = GetDlgItem (ID_CSTST_REVERSE);
	if (rvPtr != NULL) rvPtr->EnableWindow (FALSE);
}
void CcsTest::OnCststSrccsbtn() 
{
	CcsBrowse csBrowse;

	if (!UpdateData (TRUE)) return;
	csBrowse.SetInitialKeyName (m_SrcKeyName);
	INT_PTR st = csBrowse.DoModal ();
	if (st == IDOK)
	{
		m_SrcKeyName = csBrowse.GetSelectedKeyName ();
		SetLabels (false);
		OnChange ();
		UpdateData (FALSE);
	}
}
void CcsTest::OnCststTrgcsbtn() 
{
	CcsBrowse csBrowse;

	if (!UpdateData (TRUE)) return;
	csBrowse.SetInitialKeyName (m_TrgKeyName);
	INT_PTR st = csBrowse.DoModal ();
	if (st == IDOK)
	{
		m_TrgKeyName = csBrowse.GetSelectedKeyName ();
		SetLabels (true);
		OnChange ();
		UpdateData (FALSE);
	}
}
void CcsTest::OnCstst3DCheck () 
{
	int checked;
	CWnd *wp;

	checked = IsDlgButtonChecked (IDC_CSTST_3DCHECK);
	wp = GetDlgItem (IDC_CSTST_SRCZHGT);
	if (wp != NULL) wp->EnableWindow (checked != 0);
	wp = GetDlgItem (IDC_CSTST_SRCZHGTLBL);
	if (wp != NULL) wp->EnableWindow (checked != 0);
	wp = GetDlgItem (IDC_CSTST_TRGZHGT);
	if (wp != NULL) wp->EnableWindow (checked != 0);
	wp = GetDlgItem (IDC_CSTST_TRGZHGTLBL);
	if (wp != NULL) wp->EnableWindow (checked != 0);
}
void CcsTest::OnCststHelp() 
{
	CSwinhlp (m_hWnd,csHLPID_CSTEST);
}

#endif
