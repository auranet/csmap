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

			 File Name: $RCSfile: dtEdit.cpp $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #4 $
		 Check In Date:	$Date: 2006/11/25 $

		Last Revision:	$Log: dtEdit.cpp $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:20  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:17  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:16  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:23  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:30  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:19  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:58  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:33  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:13:00  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:26  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:21  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.101  2003/02/21 06:31:55  nto
		Last Revision:	Added a confirmation to a delete request.
		Last Revision:	Revision 11.100  2002/11/22 19:38:49  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1500  2002/09/22 00:01:25  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:26  nto
		Last Revision:	Revision 10.1200  2002/06/20 18:00:32  nto
		Last Revision:	Official release: 10.12
		Last Revision:	Revision 10.1100  2002/06/13 14:18:45  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:31  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:15  nto
		Last Revision:	Revision 10.701  2001/09/18 19:34:44  nto
		Last Revision:	Changed the minimum and maximum DDV numbers on the
		Last Revision:	Molodensky and 7 parameter parameters.  Required by the
		Last Revision:	rather strange Swedish test case.
		Last Revision:	Revision 10.700  2001/01/25 04:13:56  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:51  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:33  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.401  2000/10/27 07:35:50  nto
		Last Revision:	Fixed the status of parameter fiels for the CSRS technique.
		Last Revision:	Revision 10.400  2000/09/13 01:17:03  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.301  2000/09/12 21:35:20  nto
		Last Revision:	COrrected the button disabling logic.
		Last Revision:	Revision 10.300  2000/04/04 23:18:34  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:24  nto
		Last Revision:	Revision 10.2  2000/02/11 10:23:46  nto
		Last Revision:	Added field enable logic for the new datum conversion techinuqes.
		Last Revision:	Revision 10.1  2000/01/31 00:25:09  nto
		Last Revision:	Replaced stricmp with CS_stricmp.
		Last Revision:	Revision 10.0  1999/10/05 18:27:20  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:31  nto
		Last Revision:	Revision 1.2  1999/09/12 02:55:02  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/dtEdit.cpp#4 $"};
#endif

#if defined (__MFC__)

#include "cs_map.h"
#include "cs_mfc.h"
#include "cs_hlp.h"


/**********************************************************************
**	CdtEdit dtEdit;
**			dtEdit.SetKeyName (initialName);
**			ok = dtEdit.DoModal ();
**			finalName = dtEdit.GeKeyName ();
**			extern "C" CS_dtEditor (keyName);
**
**	char* initialName;			key name of the datum which is to be displayed
**								upon dialog activation.
**	int ok;						returns IDOK if user exited with OK button, else
**								returns IDCANCEL.
**	char* finalName;			pointer to static memory containing the key name
**								of the datum definition which was displayed
**								when the user terminated the dialog box.
**	char* keyName;				character array which holds the initial name
**								when the function is called, and in which the
**								function returns the name of the datum
**								which was displayed when the dialog terminated.
**
**	Note, that the finalName pointer becomes invalid when the
**	CdtEdit object is detroyed (i.e. goes out of scope).
**********************************************************************/

///////////////////////////////////////////////////////////////////////////////
// Basic API access function.
extern "C" void EXP_LVL1 CS_dtEditor (char *dtKeyName)
{
	CdtEdit dtEditor;
	CS_recvr ();
	dtEditor.SetKeyName (dtKeyName);
	dtEditor.DoModal ();
	CS_stncp (dtKeyName,dtEditor.GetKeyName (),cs_KEYNM_DEF);
	return;	
}
/////////////////////////////////////////////////////////////////////////////
// CdtEdit dialog
CdtEdit::CdtEdit(CWnd* pParent /*=NULL*/)
	: CDialog(CdtEdit::IDD, pParent)
{
	//{{AFX_DATA_INIT(CdtEdit)
	m_DeltaX = 0.0;
	m_DeltaY = 0.0;
	m_DeltaZ = 0.0;
	m_Description = _T("");
	m_RotX = 0.0;
	m_RotY = 0.0;
	m_RotZ = 0.0;
	m_Scale = 0.0;
	m_Source = _T("");
	m_EllipsoidDescr = _T("");
	//}}AFX_DATA_INIT

	m_Protected = false;
	m_Modified = false;
	m_NewIdx = -1;
	m_KeyName = _T("WGS84");
	m_PreviousKeyName = m_KeyName;
}

void CdtEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CdtEdit)
	DDX_Control(pDX, IDC_DTED_KEYNAME, m_KeyNameCombo);
	DDX_Control(pDX, IDC_DTED_284VIA, m_284Via);
	DDX_Text(pDX, IDC_DTED_DELTAX, m_DeltaX);
	DDV_MinMaxDouble(pDX, m_DeltaX, -50000., 50000.);
	DDX_Text(pDX, IDC_DTED_DELTAY, m_DeltaY);
	DDV_MinMaxDouble(pDX, m_DeltaY, -50000., 50000.);
	DDX_Text(pDX, IDC_DTED_DELTAZ, m_DeltaZ);
	DDV_MinMaxDouble(pDX, m_DeltaZ, -50000., 50000.);
	DDX_Text(pDX, IDC_DTED_DESCR, m_Description);
	DDV_MaxChars(pDX, m_Description, 63);
	DDX_Text(pDX, IDC_DTED_ROTX, m_RotX);
	DDV_MinMaxDouble(pDX, m_RotX, -50000., 50000.);
	DDX_Text(pDX, IDC_DTED_ROTY, m_RotY);
	DDV_MinMaxDouble(pDX, m_RotY, -50000., 50000.);
	DDX_Text(pDX, IDC_DTED_ROTZ, m_RotZ);
	DDV_MinMaxDouble(pDX, m_RotZ, -50000., 50000.);
	DDX_Text(pDX, IDC_DTED_SCALE, m_Scale);
	DDV_MinMaxDouble(pDX, m_Scale, -2000., 2000.);
	DDX_Text(pDX, IDC_DTED_SOURCE, m_Source);
	DDV_MaxChars(pDX, m_Source, 63);
	DDX_Text(pDX, IDC_DTED_ELIPDSCR, m_EllipsoidDescr);
	DDV_MaxChars(pDX, m_EllipsoidDescr, 63);
	//}}AFX_DATA_MAP
}

void CdtEdit::SetKeyName (const char* dtKeyName)
{
	char kyTemp [cs_KEYNM_DEF + 2];

	CS_stncp (kyTemp,dtKeyName,sizeof (kyTemp));
	CS_nampp (kyTemp);
	if (CS_dtIsValid (kyTemp))
	{
		m_KeyName = kyTemp;
	}
}

const char* CdtEdit::GetKeyName ()
{
	return (LPCTSTR)m_KeyName;
}

BOOL CdtEdit::OnInitDialog ()
{
	int ii, idx, ident;
	CWnd *wp;
	char description [64];

	CDialog::OnInitDialog ();

	// Enumerate the current ellisoid key names and populate the
	// Key Name combo box.  We record the CS_MAP index with the
	// entry in case MFC doesn't sort the same as CS-MAP.  Then,
	// we select the initial ellipsoid as desired, populate the
	// the necessary fields, and display the whole mess.

	CS_recvr ();
	RebuildComboBox ();
	// Populate the "to84_bia" combo box.
	m_284Via.ResetContent ();
	for (ii = 0;
		 CS_viaEnum (ii,description,sizeof (description),&ident) > 0;
		 ii += 1)
	{
		idx = m_284Via.AddString (description);
		m_284Via.SetItemData (idx,ident);
	}
	ChangeDatum (m_KeyName);

	// Disable the Help button if help isn't available.
	wp = GetDlgItem (IDC_DTED_HELP);
	if (wp != NULL) wp->EnableWindow (CS_isHlpAvailable ());
	return (TRUE);
}

void CdtEdit::RebuildComboBox ()
{
	int ii;
	char dtName [32];

	m_KeyNameCombo.ResetContent ();
	for (ii = 0;CS_dtEnum (ii,dtName,sizeof (dtName)) > 0;ii += 1)
	{
		m_KeyNameCombo.AddString (dtName);
	}
	if (ii < 0)
	{
		char errMesg [256];
		CS_errmsg (errMesg,sizeof (errMesg));
		AfxMessageBox (errMesg);
	}
}

void CdtEdit::NewDatum (const CString& dtKeyName)
{
	m_KeyName = dtKeyName;
	m_Description.Empty ();
	m_Source.Empty ();
	m_DeltaX = 0.0;
	m_DeltaY = 0.0;
	m_DeltaZ = 0.0;
	m_RotX = 0.0;
	m_RotY = 0.0;
	m_RotZ = 0.0;
	m_Scale = 0.0;
	m_284Via.SetCurSel (0);
	m_Ellipsoid = "WGS84";
	NewEllipsoid ();
	return;
}

bool CdtEdit::ChangeDatum (const CString& dtKeyName)
{
	if (!GetDatum (dtKeyName)) return false;
	if (m_KeyNameCombo.SelectString (-1,m_KeyName) == CB_ERR)
	{	// Force WGS84 if the provided datum name was bogus
		m_KeyName = _T("WGS84");
		m_KeyNameCombo.SelectString (-1,(LPCTSTR)m_KeyName);
		GetDatum (m_KeyName);
	}
	m_Modified = false;
	m_NewIdx = -1;
	SetButtons ();
	UpdateData (FALSE);
	return true;
}

bool CdtEdit::GetDatum (const CString& dtKeyName)
{
	struct cs_Dtdef_ *dtPtr;

	dtPtr = CS_dtdef (dtKeyName);
	if (dtPtr == NULL)
	{
		char errMesg [256];
		CS_errmsg (errMesg,sizeof (errMesg));
		AfxMessageBox (errMesg);
		return false;
	}
	m_Protected = (CS_prchk (dtPtr->protect) != 0);
	m_Description = dtPtr->name;
	m_Source = dtPtr->source;
	m_Ellipsoid = dtPtr->ell_knm;
	NewEllipsoid ();
	m_DeltaX = dtPtr->delta_X;
	m_DeltaY = dtPtr->delta_Y;
	m_DeltaZ = dtPtr->delta_Z;
	m_RotX = dtPtr->rot_X;
	m_RotY = dtPtr->rot_Y;
	m_RotZ = dtPtr->rot_Z;
	m_Scale = dtPtr->bwscale;
	int selIdx = 0;
	for (int ii = 0;ii < m_284Via.GetCount ();ii += 1)
	{
		if (m_284Via.GetItemData (ii) == (DWORD)dtPtr->to84_via)
		{
			selIdx = ii;
			break;
		}
	}
	m_284Via.SetCurSel (selIdx);
	m_KeyName = dtKeyName;
	CS_free (dtPtr);
	return true;
}

int CdtEdit::PutDatum ()
{
	CString stemp;
	struct cs_Dtdef_ dtDef;

	memset (&dtDef,'\0',sizeof (dtDef));
	strncpy (dtDef.key_nm,(LPCTSTR)m_KeyName,sizeof (dtDef.key_nm));
	dtDef.key_nm [sizeof (dtDef.key_nm) - 1] = '\0';
	strncpy (dtDef.name,(LPCTSTR)m_Description,sizeof (dtDef.name));
	dtDef.name [sizeof (dtDef.name) - 1] = '\0';
	strncpy (dtDef.source,(LPCTSTR)m_Source,sizeof (dtDef.source));
	dtDef.source [sizeof (dtDef.source) - 1] = '\0';

	dtDef.delta_X = m_DeltaX;
	dtDef.delta_Y = m_DeltaY;
	dtDef.delta_Z = m_DeltaZ;
	dtDef.rot_X = m_RotX;
	dtDef.rot_Y = m_RotY;
	dtDef.rot_Z = m_RotZ;
	dtDef.bwscale = m_Scale;
	CS_stncp (dtDef.ell_knm,m_Ellipsoid,sizeof (dtDef.ell_knm));
	int idx = m_284Via.GetCurSel ();
	dtDef.to84_via = (short)m_284Via.GetItemData (idx);
	dtDef.protect = 0;

	int st = CS_dtupd (&dtDef,0);
	if (st < 0)
	{
		char errMesg [256];
		CS_errmsg (errMesg,sizeof (errMesg));
		AfxMessageBox (errMesg);
	}
	return (st);
}

bool CdtEdit::DeleteDatum (const CString& dtKeyName)
{
	bool rtnValue;
	int st = IDOK;
	struct cs_Dtdef_ dtDef;

	if (m_Protected)
	{
		AfxMessageBox ("Displayed datum definition is protected and may not be deleted.");
		st = IDCANCEL;
		rtnValue = false;
	}
	else
	{
		st = AfxMessageBox ("Click 'OK' to confirm your request to delete this datum definition.",MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2);
		rtnValue = false;
	}
	if (st == IDOK)
	{
		memset (&dtDef,'\0',sizeof (dtDef));
		strncpy (dtDef.key_nm,(LPCTSTR)dtKeyName,sizeof (dtDef.key_nm));
		int st = CS_dtdel (&dtDef);
		if (st != 0)
		{
			char errMesg [256];
			CS_errmsg (errMesg,sizeof (errMesg));
			AfxMessageBox (errMesg);
			rtnValue = false;
		}
	}
	return rtnValue;
}

BEGIN_MESSAGE_MAP(CdtEdit, CDialog)
	//{{AFX_MSG_MAP(CdtEdit)
	ON_BN_CLICKED(IDC_DTED_DELSAV, OnDtedDelsav)
	ON_EN_CHANGE(IDC_DTED_DELTAX, OnChange)
	ON_BN_CLICKED(IDC_DTED_HELP, OnDtedHelp)
	ON_BN_CLICKED(IDC_DTED_NEWCNCL, OnDtedNewcncl)
	ON_BN_CLICKED(ID_DTED_CLOSE, OnDtedClose)
	ON_CBN_SELENDOK(IDC_DTED_284VIA, OnSelendokDted284via)
	ON_CBN_SELCHANGE(IDC_DTED_KEYNAME, OnSelchangeDtedKeyname)
	ON_EN_CHANGE(IDC_DTED_DELTAY, OnChange)
	ON_EN_CHANGE(IDC_DTED_DELTAZ, OnChange)
	ON_EN_CHANGE(IDC_DTED_DESCR, OnChange)
	ON_EN_CHANGE(IDC_DTED_ROTX, OnChange)
	ON_EN_CHANGE(IDC_DTED_ROTY, OnChange)
	ON_EN_CHANGE(IDC_DTED_ROTZ, OnChange)
	ON_EN_CHANGE(IDC_DTED_SCALE, OnChange)
	ON_EN_CHANGE(IDC_DTED_SOURCE, OnChange)
	ON_BN_CLICKED(IDC_DTED_ELIPBTN, OnDtedNewEllipsoid)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CdtEdit message handlers

void CdtEdit::OnDtedDelsav() 
{
	int st;

	if (m_Modified)
	{	// Here to perform the save operation.
		if (!UpdateData (TRUE)) return;
		st = PutDatum ();
		if (st == 0)
		{
			CS_recvr ();
			RebuildComboBox ();
		}
		if (st >= 0)
		{
			m_NewIdx = -1;
			ChangeDatum (m_KeyName);
		}
	}
	else
	{	// Here to perform the delete operation.  Must determine
		// which datum to display after the delete operation.
		char dtName [32];
		int newIdx = 0;
		for (int ii = 0;CS_dtEnum (ii,dtName,sizeof (dtName)) > 0;ii += 1)
		{
			if (m_KeyName == dtName) break;
			newIdx = ii;		
		}
		if (CS_dtEnum (newIdx,dtName,sizeof (dtName)) <= 0)
		{	// Display WGS84 if all else fails.
			strcpy (dtName,"WGS84");
		}
		if (DeleteDatum (m_KeyName))
		{
			m_KeyName = dtName;
			// Rebuild the combo box with new names and indices.
			CS_recvr ();
			RebuildComboBox ();
			// Select the new ellipsoid
			ChangeDatum (m_KeyName);
		}
	}
}

void CdtEdit::OnChange() 
{
	if (!m_Modified)
	{
		if (m_Protected)
		{
			AfxMessageBox (_T("Current definition is protected.  You will\n not be able to save your changes."));
		}
		m_Modified = true;
		SetButtons ();
	}
}
void CdtEdit::OnDtedHelp() 
{
	CSwinhlp (m_hWnd,csHLPID_DTEDIT);
}
void CdtEdit::OnDtedNewcncl() 
{
	if (m_Modified)
	{	// Here to perform a cancel.
		if (m_NewIdx >= 0)
		{
			m_KeyNameCombo.DeleteString (m_NewIdx);
			m_NewIdx = -1;
			m_KeyName = m_PreviousKeyName;
		}
		ChangeDatum (m_KeyName);
	}
	else
	{	// Here to create a new datum.  Save the current name for
		// use in the event of a subsequent cancel operation.  Then,
		// have operator provide the name of the new datum.

		m_PreviousKeyName = m_KeyName;
		CnewKeyName dtNewName (CnewKeyName::Datum,this);
		INT_PTR st = dtNewName.DoModal ();
		if (st == IDOK)
		{
			m_KeyName = dtNewName.GetNewName ();
			// See if we are to reset all values.
			if (!dtNewName.GetPreserve ())
			{
				NewDatum (m_KeyName);
			}
			m_Modified = true;
			m_Protected = false;
			m_NewIdx = m_KeyNameCombo.AddString (m_KeyName);
			m_KeyNameCombo.SelectString (-1,m_KeyName);
			SetButtons ();
			UpdateData (FALSE);
		}
	}
}

void CdtEdit::OnDtedClose() 
{
	int response;
	if (m_Modified && !m_Protected)
	{
		response = AfxMessageBox ("Changes have been made, but not saved.\nDo you want to exit and discard these changes?",MB_YESNO | MB_ICONQUESTION);
		if (response == IDNO) return;
	}
	CDialog::OnCancel ();
	return;
}
void CdtEdit::SetButtons ()
{
	bool deltas, rots, scale, grid;
	int idx;
	CWnd *wp;

	idx = m_284Via.GetCurSel ();
	idx = static_cast<int>(m_284Via.GetItemData (idx));

	deltas = rots = scale = grid = false;
	switch (idx) {
	case cs_DTCTYP_NAD83:
	case cs_DTCTYP_MREG:
	case cs_DTCTYP_WGS84:
	case cs_DTCTYP_WGS72:
	case cs_DTCTYP_HPGN:
	case cs_DTCTYP_GDA94:
	case cs_DTCTYP_NZGD2K:
		break;
	case cs_DTCTYP_AGD66:
	case cs_DTCTYP_NAD27:
	case cs_DTCTYP_AGD84:
	case cs_DTCTYP_NZGD49:
	case cs_DTCTYP_ATS77:
	case cs_DTCTYP_CSRS:
		deltas = rots = scale = false;
		break;
	case cs_DTCTYP_MOLO:
		deltas = true;
		break;
	case cs_DTCTYP_7PARM:
	case cs_DTCTYP_BURS:
		deltas = rots = scale = true;
		break;
	case cs_DTCTYP_3PARM:
		deltas = true;
		break;
	case cs_DTCTYP_6PARM:
		deltas = rots = true;
		break;
	case cs_DTCTYP_4PARM:
		deltas = scale = true;
		break;
	default:
		deltas = rots = scale = false;
		break;
	}

	wp = GetDlgItem (IDC_DTED_NEWCNCL);
	if (wp != NULL) wp->SetWindowText (m_Modified ? "Cancel" : "New");
	wp = GetDlgItem (IDC_DTED_DELSAV);
	if (wp != NULL)
	{
		wp->SetWindowText (m_Modified ? "Save" : "Delete");
		wp->EnableWindow (!m_Protected);
	}
	wp = GetDlgItem (IDC_DTED_KEYNAME);
	if (wp != NULL) wp->EnableWindow (!m_Modified);

	wp = GetDlgItem (IDC_DTED_DELTAX);
	if (wp != NULL) wp->EnableWindow (deltas);
	wp = GetDlgItem (IDC_DTED_DELTAY);
	if (wp != NULL) wp->EnableWindow (deltas);
	wp = GetDlgItem (IDC_DTED_DELTAZ);
	if (wp != NULL) wp->EnableWindow (deltas);

	wp = GetDlgItem (IDC_DTED_ROTX);
	if (wp != NULL) wp->EnableWindow (rots);
	wp = GetDlgItem (IDC_DTED_ROTY);
	if (wp != NULL) wp->EnableWindow (rots);
	wp = GetDlgItem (IDC_DTED_ROTZ);
	if (wp != NULL) wp->EnableWindow (rots);

	wp = GetDlgItem (IDC_DTED_SCALE);
	if (wp != NULL) wp->EnableWindow (scale);

	return;
}

void CdtEdit::OnCancel() 
{
	int response;
	if (m_Modified && !m_Protected)
	{
		response = AfxMessageBox ("Changes have been made, but not saved.\nDo you to exit and discard these changes?",MB_YESNO | MB_ICONQUESTION);
		if (response == IDNO) return;
	}
	CDialog::OnCancel ();
	return;
}
void CdtEdit::OnSelendokDted284via() 
{
	OnChange ();
	SetButtons ();
}
void CdtEdit::OnSelchangeDtedKeyname() 
{
	int idx = m_KeyNameCombo.GetCurSel ();
	m_KeyNameCombo.GetLBText (idx,m_KeyName);
	ChangeDatum (m_KeyName);
	return;
}
void CdtEdit::OnDtedNewEllipsoid() 
{
	char newKeyName [32];
	CelSelect elSelect;
	
	UpdateData (TRUE);
	elSelect.SetInitialEllipsoid (m_Ellipsoid);
	INT_PTR st = elSelect.DoModal ();
	if (st == IDOK)
	{
		CS_stncp (newKeyName,elSelect.GetSelectedEllipsoid (),sizeof (newKeyName));		
		if (CS_stricmp (m_Ellipsoid,newKeyName))
		{
			OnChange ();
			m_Ellipsoid = newKeyName;
			OnChange ();
			NewEllipsoid ();
			UpdateData (FALSE);
		}
	}
}
void CdtEdit::NewEllipsoid()
{
	struct cs_Eldef_ *elPtr;
	m_EllipsoidDescr = "???";
	elPtr = CS_eldef (m_Ellipsoid);
	if (elPtr != NULL)
	{
		m_EllipsoidDescr = elPtr->name;
		CS_free (elPtr);
	}
	return;
}
#endif
