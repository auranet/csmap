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

			 File Name: $RCSfile: csDualBrowse.cpp $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #4 $
		 Check In Date:	$Date: 2006/11/25 $

		Last Revision:	$Log: csDualBrowse.cpp $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:04  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:07  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:04  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:13  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:20  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:09  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:49  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:24  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:52  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:18  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:13  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:40  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1500  2002/09/22 00:01:16  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:19  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:11  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:32  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:23  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:08  nto
		Last Revision:	Revision 10.701  2001/09/18 19:03:45  nto
		Last Revision:	Changed stricmp to CS_stricmp.  stricmp is not ANSI standard.
		Last Revision:	Revision 10.700  2001/01/25 04:13:42  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:36  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:14  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:16:48  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 1.2  2000/09/12 21:27:32  nto
		Last Revision:	Fixed some bugs, it works now.
		Last Revision:	Revision 10.300  2000/04/04 23:18:19  nto
		Last Revision:	Revision 10.201  2000/04/03 21:50:10  nto
		Last Revision:	Added default values for minimum non-zero and map scale.
		Last Revision:	Revision 10.200  2000/03/02 18:51:12  nto
		Last Revision:	Revision 10.2  2000/01/31 00:32:38  nto
		Last Revision:	Adjusted to accomodate change in the type of second parameter to CS_prjEnum function.
		Last Revision:	Revision 10.1  2000/01/31 00:21:48  nto
		Last Revision:	Replaced stricmp with CS_stricmp.
		Last Revision:	Revision 10.0  1999/10/05 18:27:10  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:21  nto
		Last Revision:	Revision 1.2  1999/09/12 02:41:38  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/csDualBrowse.cpp#4 $"};
#endif

#if defined (__MFC__)

#include "cs_map.h"
#include "cs_mfc.h"
#include "cs_hlp.h"

/**********************************************************************
**	CcsDualBrowser csDualBrowser;
**		csDualBrowser.SetSrcKeyName (srcName)
**		csDualBrowser.SetTrgKeyName (trgName);
**		ok = elEdit.DoModal ();
**		newSrcName = elEdit.GetSrcKeyName ();
**		newTrgName = elEdit.GetTrgKeyName ();
**
**	extern "C" int CS_csDualBrowser (srcKeyName,trgKeyName);
**
**	char* srcName;				key name of the source coordinate system
**								which is to be displayed upon dialog
**								activation.
**	char* trgName;				key name of the target coordinate system
**								which is to be displayed upon dialog
**								activation.
**	int ok;						returns IDOK if user exited with OK button, else
**								returns IDCANCEL.
**	const char* newSrcName;		pointer to static memory containing the
**								key name of the selected source coordinate
**								system definition.
**	const char* newTrgName;		pointer to static memory containing the
**								key name of the selected target coordinate
**								system definition.
**	char srcKeyName [cs_KEYNM_DEF];
**								array in which the initial source key name
**								is obtained and the newly selected source
**								key name is returned.
**	char trgKeyName [cs_KEYNM_DEF];
**								array in which the initial target key name
**								is obtained and the newly selected target
**								key name is returned.
**
**	Note, values obtained from GetSrcKeyName and GetTrgKeyName become
**	invalid when the CcsDualBrowser object is destroyed.
**********************************************************************/

///////////////////////////////////////////////////////////////////////////////
// Basic API access function.
int EXP_LVL1 CS_csDualBrowser (char *srcKeyName,char *trgKeyName)
{
	INT_PTR st;
	CcsDualBrowse csDualBrowse;

	// First we verify that the CS-MAP stuff is up and running in a
	// normal fashion by checking the validity of the the 'LL84'
	// coordinate system.
	if (CS_csIsValid ("LL84") < 0) return -1; 

	// OK, we proceed assuming that all normal CS-MAP has been initialized
	// and has found all of its various pieces.
	csDualBrowse.SetSrcKeyName (srcKeyName);
	csDualBrowse.SetTrgKeyName (trgKeyName);
	st = csDualBrowse.DoModal ();

	// A return value of 1 indicates that the user canceled, no
	// changes were made.
	if (st != IDOK) return 1;

	// Return value of zero indicates that the dialog exited with
	// OK, and selections MAY have changed.
	CS_stncp (srcKeyName,csDualBrowse.GetSrcKeyName (),cs_KEYNM_DEF);
	CS_stncp (trgKeyName,csDualBrowse.GetTrgKeyName (),cs_KEYNM_DEF);
	return 0;
}

/////////////////////////////////////////////////////////////////////////////
// CcsDualBrowse dialog

CcsDualBrowse::CcsDualBrowse(CWnd* pParent /*=NULL*/)
			: CDialog(CcsDualBrowse::IDD, pParent)
{
	//{{AFX_DATA_INIT(CcsDualBrowse)
	m_SrcDescription = _T("");
	m_SrcReference = _T("");
	m_SrcRefLabel = _T("");
	m_SrcSource = _T("");
	m_SrcUnit = _T("");
	m_TrgDescription = _T("");
	m_TrgReference = _T("");
	m_TrgRefLabel = _T("");
	m_TrgSource = _T("");
	m_TrgUnit = _T("");
	//}}AFX_DATA_INIT

	m_Source = "US48";
	m_Target = "LL27";
}
void CcsDualBrowse::SetSrcKeyName (const char* srcKeyName)
{
	// We don't change to an invalid name.
	if (CS_csIsValid (srcKeyName)) m_Source = srcKeyName;
}
void CcsDualBrowse::SetTrgKeyName (const char* trgKeyName)
{
	// We don't change to an invalid name.
	if (CS_csIsValid (trgKeyName)) m_Target = trgKeyName;
}
BOOL CcsDualBrowse::OnInitDialog ()
{
	int st;
	int ii, idx;
	struct cs_Csdef_ *csPtr;
	char grpName [24], grpDescr [64];
	char srcGrpName [24], srcGrpDescr [64];
	char trgGrpName [24], trgGrpDescr [64];

	CDialog::OnInitDialog ();

	// We need to extract the group names from the coordinate system
	// definitions.
	csPtr = CS_csdef ((LPCTSTR)m_Source);
	if (csPtr == NULL)
	{
		// Should never happen.
		char errmsg [256];
		CS_errmsg (errmsg,sizeof (errmsg));
		AfxMessageBox (errmsg);
		return TRUE;
	}
	CS_stncp (srcGrpName,csPtr->group,sizeof (srcGrpName));
	CS_free (csPtr);
	
	csPtr = CS_csdef ((LPCTSTR)m_Target);
	if (csPtr == NULL)
	{
		// Should never happen.
		char errmsg [256];
		CS_errmsg (errmsg,sizeof (errmsg));
		AfxMessageBox (errmsg);
		return TRUE;
	}
	CS_stncp (trgGrpName,csPtr->group,sizeof (trgGrpName));
	CS_free (csPtr);

	// Set up the group combo boxes, making the proper current selections.
	srcGrpDescr [0] = trgGrpDescr [0] = '\0';
	m_SrcGroup.ResetContent ();
	m_TrgGroup.ResetContent ();
	for (ii = 0;CS_csGrpEnum (ii,grpName,sizeof (grpName),grpDescr,sizeof (grpDescr)) > 0;ii += 1)
	{
		idx = m_SrcGroup.AddString (grpDescr);
		m_SrcGroup.SetItemData (idx,ii);
		if (!CS_stricmp (grpName,srcGrpName)) CS_stncp (srcGrpDescr,grpDescr,sizeof (srcGrpDescr));

		idx = m_TrgGroup.AddString (grpDescr);
		m_TrgGroup.SetItemData (idx,ii);
		if (!CS_stricmp (grpName,trgGrpName)) CS_stncp (trgGrpDescr,grpDescr,sizeof (trgGrpDescr));
	}
	if (ii > 0)
	{
		m_SrcGroup.SelectString (-1,srcGrpDescr);
		m_TrgGroup.SelectString (-1,trgGrpDescr);
	}

	// Now, the Source Key Name combo box
	RebuildKeyNameCombo (m_SrcKeyName,srcGrpName);
	st = m_SrcKeyName.SelectString (-1,m_Source);
	if (st == CB_ERR) m_SrcKeyName.SetCurSel (0);
	OnChangeSrcKeyNm();

	// Now, the Source Key Name combo box
	RebuildKeyNameCombo (m_TrgKeyName,trgGrpName);
	st = m_TrgKeyName.SelectString (-1,m_Target);
	if (st == CB_ERR) m_TrgKeyName.SetCurSel (0);
	OnChangeTrgKeyNm();

	// Disable the Help button if help is not available.
	CWnd* wp = GetDlgItem (ID_BRWS_HELP);
	if (wp != NULL) wp->EnableWindow (CS_isHlpAvailable ());
	return TRUE;
}
void CcsDualBrowse::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CcsDualBrowse)
	DDX_Control(pDX, IDC_CSBR2_TRGKEYNM, m_TrgKeyName);
	DDX_Control(pDX, IDC_CSBR2_TRGGRP, m_TrgGroup);
	DDX_Control(pDX, IDC_CSBR2_SRCKEYNM, m_SrcKeyName);
	DDX_Control(pDX, IDC_CSBR2_SRCGRP, m_SrcGroup);
	DDX_Text(pDX, IDC_CSBR2_SRCDESCR, m_SrcDescription);
	DDX_Text(pDX, IDC_CSBR2_SRCREF, m_SrcReference);
	DDX_Text(pDX, IDC_CSBR2_SRCREFLBL, m_SrcRefLabel);
	DDX_Text(pDX, IDC_CSBR2_SRCSRC, m_SrcSource);
	DDX_Text(pDX, IDC_CSBR2_SRCUNIT, m_SrcUnit);
	DDX_Text(pDX, IDC_CSBR2_TRGDESCR, m_TrgDescription);
	DDX_Text(pDX, IDC_CSBR2_TRGREF, m_TrgReference);
	DDX_Text(pDX, IDC_CSBR2_TRGREFLBL, m_TrgRefLabel);
	DDX_Text(pDX, IDC_CSBR2_TRGSRC, m_TrgSource);
	DDX_Text(pDX, IDC_CSBR2_TRGUNIT, m_TrgUnit);
	//}}AFX_DATA_MAP
}
void CcsDualBrowse::RebuildKeyNameCombo (CComboBox& comboBox,const char* grpName)
{
	int ii, idx;
	struct cs_Csgrplst_ csDescr;

	comboBox.ResetContent ();
	for (ii = 0;CS_csEnumByGroup (ii,grpName,&csDescr) > 0;ii += 1)
	{
		idx = comboBox.AddString (csDescr.key_nm);
		comboBox.SetItemData (idx,ii);
	}
	if (ii == 0)
	{
		idx = comboBox.AddString ("<none>");
		comboBox.SetItemData (idx,9999999);
	}
}

BEGIN_MESSAGE_MAP(CcsDualBrowse, CDialog)
	//{{AFX_MSG_MAP(CcsDualBrowse)
	ON_BN_CLICKED(ID_CSBR2_HELP, OnCsbr2Help)
	ON_CBN_SELCHANGE(IDC_CSBR2_SRCGRP, OnChangeSrcGroup)
	ON_CBN_SELCHANGE(IDC_CSBR2_TRGGRP, OnChangeTrgGroup)
	ON_CBN_SELCHANGE(IDC_CSBR2_TRGKEYNM, OnChangeTrgKeyNm)
	ON_CBN_SELCHANGE(IDC_CSBR2_SRCKEYNM, OnChangeSrcKeyNm)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CcsDualBrowse message handlers
void CcsDualBrowse::OnCsbr2Help() 
{
}
void CcsDualBrowse::OnCancel() 
{
	CDialog::OnCancel();
}
void CcsDualBrowse::OnOK() 
{
	
	CDialog::OnOK();
}
void CcsDualBrowse::OnChangeSrcGroup() 
{
	int ii, idx, st;
	char grpName [24], grpDescr [64];

	ii = m_SrcGroup.GetCurSel ();
	idx = static_cast<int>(m_SrcGroup.GetItemData (ii));
	st = CS_csGrpEnum (idx,grpName,sizeof (grpName),grpDescr,sizeof (grpDescr));
	RebuildKeyNameCombo (m_SrcKeyName,grpName);
	m_SrcKeyName.SetCurSel (0);
	OnChangeSrcKeyNm ();
	return;
}
void CcsDualBrowse::OnChangeTrgGroup() 
{
	int ii, idx, st;
	char grpName [24], grpDescr [64];

	ii = m_TrgGroup.GetCurSel ();
	idx = static_cast<int>(m_TrgGroup.GetItemData (ii));
	st = CS_csGrpEnum (idx,grpName,sizeof (grpName),grpDescr,sizeof (grpDescr));
	RebuildKeyNameCombo (m_TrgKeyName,grpName);
	m_TrgKeyName.SetCurSel (0);
	OnChangeTrgKeyNm ();
	return;
}
void CcsDualBrowse::OnChangeSrcKeyNm() 
{
	int ii, idx, st;
	char grpName [24];
	struct cs_Csgrplst_ csDescr;

	// First, we get ther current group name.
	ii = m_SrcGroup.GetCurSel ();
	idx = static_cast<int>(m_SrcGroup.GetItemData (ii));
	st = CS_csGrpEnum (idx,grpName,sizeof (grpName),NULL,0);

	// Here when the selected source key name changes.
	ii = m_SrcKeyName.GetCurSel ();
	idx = static_cast<int>(m_SrcKeyName.GetItemData (ii));
	st = -1;
	if (idx < 9999999)
	{
		st = CS_csEnumByGroup (idx,grpName,&csDescr);
		if (st > 0)
		{
			m_Source = csDescr.key_nm;
			m_SrcDescription = csDescr.descr;
			m_SrcSource = csDescr.source;
			m_SrcRefLabel = csDescr.ref_typ;
			m_SrcRefLabel += ":";
			m_SrcReference = csDescr.ref_to;
			m_SrcUnit = csDescr.unit;
		}
	}
	if (st <= 0)
	{
		m_Source = "";
		m_SrcDescription = "";
		m_SrcSource = "";
		m_SrcRefLabel = "";
		m_SrcReference = "";
		m_SrcUnit = "";
	}
	UpdateData (FALSE);
}
void CcsDualBrowse::OnChangeTrgKeyNm() 
{
	// Here when the selected target key name changes.
	int ii, idx, st;
	char grpName [24];
	struct cs_Csgrplst_ csDescr;

	// First, we get ther current group name.
	ii = m_TrgGroup.GetCurSel ();
	idx = static_cast<int>(m_TrgGroup.GetItemData (ii));
	st = CS_csGrpEnum (idx,grpName,sizeof (grpName),NULL,0);

	// Here when the selected source key name changes.
	ii = m_TrgKeyName.GetCurSel ();
	idx = static_cast<int>(m_TrgKeyName.GetItemData (ii));
	st = -1;
	if (idx < 9999999)
	{
		st = CS_csEnumByGroup (idx,grpName,&csDescr);
		if (st > 0)
		{
			m_Target = csDescr.key_nm;
			m_TrgDescription = csDescr.descr;
			m_TrgSource = csDescr.source;
			m_TrgRefLabel = csDescr.ref_typ;
			m_TrgRefLabel += ":";
			m_TrgReference = csDescr.ref_to;
			m_TrgUnit = csDescr.unit;
		}
	}
	if (st <= 0)
	{
		m_Target = "";
		m_TrgDescription = "";
		m_TrgSource = "";
		m_TrgRefLabel = "";
		m_TrgReference = "";
		m_TrgUnit = "";
	}
	UpdateData (FALSE);
}
#endif