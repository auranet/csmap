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

			 File Name: $RCSfile: csBrowser.cpp $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #5 $
		 Check In Date:	$Date: 2006/11/27 $

		Last Revision:	$Log: csBrowser.cpp $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:02  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:06  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:03  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:12  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:19  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:08  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:48  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:23  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:51  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:17  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:12  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:39  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1500  2002/09/22 00:01:15  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:18  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:10  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:32  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:22  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:07  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:41  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:35  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.501  2000/12/04 18:01:54  nto
		Last Revision:	Added user message in the event of a Coordinate System Dictionary open failure.
		Last Revision:	Revision 10.500  2000/10/27 07:38:12  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:16:47  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.301  2000/08/05 19:27:22  nto
		Last Revision:	Fixed a memory leak.
		Last Revision:	Revision 10.300  2000/04/04 23:18:17  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:11  nto
		Last Revision:	Revision 10.1  2000/01/31 00:12:56  nto
		Last Revision:	Replaced stricmp with CS_stricmp; also some PCLint clean up.
		Last Revision:	Revision 10.0  1999/10/05 18:27:10  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:21  nto
		Last Revision:	Revision 1.2  1999/09/26 21:42:36  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/csBrowser.cpp#5 $"};
#endif

#if defined (__MFC__)
#include "cs_map.h"
#include "cs_mfc.h"
#include "cs_hlp.h"

/**********************************************************************
**	CcsBrowse csBrowse;
**		elSelect.SetInitialKeyName (initialName);
**		finalName = GetSelectedKeyName ();
**********************************************************************/

extern "C" int EXP_LVL1 CS_csBrowser (char* keyName)
{
	INT_PTR status;
	CcsBrowse csBrowse;

	csBrowse.SetInitialKeyName (keyName);
	status = csBrowse.DoModal ();
	if (status == IDOK)
	{
		CS_stncp (keyName,csBrowse.GetSelectedKeyName (),cs_KEYNM_DEF);
	}
	return (int)(status);
}

/////////////////////////////////////////////////////////////////////////////
// CcsBrowse dialog
CcsBrowse::CcsBrowse(CWnd* pParent /*=NULL*/)
	: CDialog(CcsBrowse::IDD, pParent)
{
	//{{AFX_DATA_INIT(CcsBrowse)
	m_Description = _T("");
	m_RefTo = _T("");
	m_Source = _T("");
	m_Unit = _T("");
	//}}AFX_DATA_INIT
	m_KeyName = _T("");
	m_Group = _T("");
}
void CcsBrowse::SetInitialKeyName (const char* keyName)
{
	char kyTemp [cs_KEYNM_DEF + 2];

	CS_stncp (kyTemp,keyName,sizeof (kyTemp));
	CS_nampp (kyTemp);
	if (CS_csIsValid (kyTemp))
	{
		m_KeyName = kyTemp;
	}
}
BOOL CcsBrowse::OnInitDialog ()
{
	int ii, idx, st;
	CWnd *wp;
	struct cs_Csdef_ *csPtr;
	char grpName [24], grpDescr [64];
	CString select;

	CDialog::OnInitDialog ();

	// Determine the appropriate group from the initial key name.
	// Set up the group combo, and select the appropriate group.
	// Set up the key name combo for the appropriate group, and
	// select the desired key name.

	if (!CS_csIsValid (m_KeyName)) m_KeyName = "LL";
	csPtr = CS_csdef (m_KeyName);
	if (csPtr == NULL)
	{
		char errBufr [256];
		CS_errmsg (errBufr,sizeof (errBufr));
		AfxMessageBox (errBufr,MB_OK,0);
		return FALSE;
	}
	m_Group = csPtr->group;
	CS_free (csPtr);
	csPtr = 0;

	select.Empty ();
	m_GroupCombo.ResetContent ();
	for (ii = 0;
		 CS_csGrpEnum (ii,grpName,sizeof (grpName),grpDescr,sizeof (grpDescr)) > 0;
		 ii += 1)
	{
		if (ii == 0) select = grpDescr;
		idx = m_GroupCombo.AddString (grpDescr);
		m_GroupCombo.SetItemData (idx,ii);
		if (!CS_stricmp (grpName,m_Group)) select = grpDescr;
	}
	if (ii > 0) m_GroupCombo.SelectString (-1,select);
	// Now, the Key Name combo
	RebuildKeynameCombo (m_Group);
	st = m_KeyNameCombo.SelectString (-1,m_KeyName);
	if (st == CB_ERR) m_KeyNameCombo.SetCurSel (0);
	OnSelchangeBrcsKeynm();

	// Disable the Help button if help is not available.
	wp = GetDlgItem (ID_BRWS_HELP);
	if (wp != NULL) wp->EnableWindow (CS_isHlpAvailable ());
	return TRUE;
}
void CcsBrowse::RebuildKeynameCombo (const char* grpName)
{
	int ii, idx;
	struct cs_Csgrplst_ csDescr;

	m_KeyNameCombo.ResetContent ();
	for (ii = 0;
		 CS_csEnumByGroup (ii,grpName,&csDescr) > 0;
		 ii += 1)
	{
		idx = m_KeyNameCombo.AddString (csDescr.key_nm);
		m_KeyNameCombo.SetItemData (idx,ii);
	}
	if (ii == 0)
	{
		idx = m_KeyNameCombo.AddString ("<none>");
		m_KeyNameCombo.SetItemData (idx,9999999);
	}
}
const char* CcsBrowse::GetSelectedKeyName (void)
{
	return (LPCTSTR)m_KeyName;
}
void CcsBrowse::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CcsBrowse)
	DDX_Control(pDX, IDC_BRCS_KEYNM, m_KeyNameCombo);
	DDX_Control(pDX, IDC_BRCS_GROUP, m_GroupCombo);
	DDX_Text(pDX, IDC_BRCS_DSCR, m_Description);
	DDV_MaxChars(pDX, m_Description, 63);
	DDX_Text(pDX, IDC_BRCS_REFTO, m_RefTo);
	DDV_MaxChars(pDX, m_RefTo, 48);
	DDX_Text(pDX, IDC_BRCS_SOURCE, m_Source);
	DDV_MaxChars(pDX, m_Source, 63);
	DDX_Text(pDX, IDC_BRCS_UNIT, m_Unit);
	DDV_MaxChars(pDX, m_Unit, 24);
	//}}AFX_DATA_MAP
}
BEGIN_MESSAGE_MAP(CcsBrowse, CDialog)
	//{{AFX_MSG_MAP(CcsBrowse)
	ON_BN_CLICKED(ID_BRWS_HELP, OnHelp)
	ON_CBN_SELENDOK(IDC_BRCS_GROUP, OnSelendokBrcsGroup)
	ON_CBN_SELCHANGE(IDC_BRCS_KEYNM, OnSelchangeBrcsKeynm)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CcsBrowse message handlers
void CcsBrowse::OnHelp() 
{
	CSwinhlp (m_hWnd,csHLPID_CSBROWSER);
}
void CcsBrowse::OnOK ()
{
	char keyName [32];

	if (!UpdateData (TRUE)) return;
	strncpy (keyName,(LPCTSTR)m_KeyName,sizeof (keyName));
	keyName [sizeof (keyName) - 1] = '\0';
	if (!CS_csIsValid (keyName))
	{
		AfxMessageBox ("Coordinate system selection is invalid; please select again or Cancel.",MB_OK | MB_ICONEXCLAMATION);
		return;
	}
	CDialog::OnOK ();
	return;
}
void CcsBrowse::OnSelendokBrcsGroup() 
{
	int ii, idx, st;
	char grpName [24], grpDescr [64];

	ii = m_GroupCombo.GetCurSel ();
	idx = static_cast<int>(m_GroupCombo.GetItemData (ii));
	st = CS_csGrpEnum (idx,grpName,sizeof (grpName),grpDescr,sizeof (grpDescr));
	ASSERT (st > 0);
	m_Group = grpName;
	RebuildKeynameCombo (grpName);
	m_KeyNameCombo.SetCurSel (0);
	OnSelchangeBrcsKeynm ();
	return;
}
void CcsBrowse::OnSelchangeBrcsKeynm() 
{
	int ii, idx, st;
	struct cs_Csgrplst_ csDescr;

	ii = m_KeyNameCombo.GetCurSel ();
	idx = static_cast<int>(m_KeyNameCombo.GetItemData (ii));
	st = -1;
	if (idx < 9999999)
	{
		st = CS_csEnumByGroup (idx,m_Group,&csDescr);
		if (st > 0)
		{
			m_KeyName = csDescr.key_nm;
			m_Description = csDescr.descr;
			m_Source = csDescr.source;
			m_RefTo.Format ("%s: %s",csDescr.ref_typ,csDescr.ref_to);
			m_Unit = csDescr.unit;
		}
	}
	if (st <= 0)
	{
		m_KeyName = "";
		m_Description = "";
		m_Source = "";
		m_RefTo = "";
		m_Unit = "";
	}
	UpdateData (FALSE);
}
#endif
