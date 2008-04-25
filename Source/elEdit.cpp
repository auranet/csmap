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

			 File Name: $RCSfile: elEdit.cpp $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #4 $
		 Check In Date:	$Date: 2006/11/25 $

		Last Revision:	$Log: elEdit.cpp $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:21  nto
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
		Last Revision:	Revision 11.401  2003/05/01 23:06:27  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:21  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.101  2003/02/21 06:31:55  nto
		Last Revision:	Added a confirmation to a delete request.
		Last Revision:	Revision 11.100  2002/11/22 19:38:49  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1500  2002/09/22 00:01:25  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:27  nto
		Last Revision:	Revision 10.1200  2002/06/20 18:00:32  nto
		Last Revision:	Official release: 10.12
		Last Revision:	Revision 10.1100  2002/06/13 14:18:45  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:31  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:15  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:57  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:51  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:33  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:17:03  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:35  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:24  nto
		Last Revision:	Revision 10.1  2000/01/31 00:25:58  nto
		Last Revision:	PCLint clean up.
		Last Revision:	Revision 10.0  1999/10/05 18:27:20  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:31  nto
		Last Revision:	Revision 1.2  1999/09/12 03:02:14  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/elEdit.cpp#4 $"};
#endif

#if defined (__MFC__)

#include "cs_map.h"
#include "cs_mfc.h"
#include "cs_hlp.h"

/**********************************************************************
**	CelEdit elEdit;
**			elEdit.SetKeyName (initialName);
**			ok = elEdit.DoModal ();
**			finalName = elEdit.GeKeyName ();
**			extern "C" CS_elEditor (keyName);
**
**	char* initialName;			key name of the ellipsoid which is to be displayed
**								upon dialog activation.
**	int ok;						returns IDOK if user exited with OK button, else
**								returns IDCANCEL.
**	char* finalName;			pointer to static memory containing the key name
**								of the ellipsoid definition which was displayed
**								when the user terminated the dialog box.
**	char* keyName;				character array which holds the initial name
**								when the function is called, and in which the
**								function returns the name of the ellipsoid
**								which was displayed when the dialog terminated.
**
**	Note, that the finalName pointer becomes invalid when the
**	CelEdit object is detroyed (i.e. goes out of scope).
**********************************************************************/

///////////////////////////////////////////////////////////////////////////////
// Basic API access function.
extern "C" void EXP_LVL1 CS_elEditor (char *elKeyName)
{
	CelEdit elEditor;
	CS_recvr ();
	elEditor.SetKeyName (elKeyName);
	elEditor.DoModal ();
	CS_stncp (elKeyName,elEditor.GetKeyName (),cs_KEYNM_DEF);
	return;	
}
/////////////////////////////////////////////////////////////////////////////
// CelEdit dialog
CelEdit::CelEdit(CWnd* pParent) : CDialog(CelEdit::IDD, pParent)
{
	//{{AFX_DATA_INIT(CelEdit)
	m_EsqString = _T("");
	m_FlatString = _T("");
	m_Source = _T("");
	m_Description = _T("");
	m_EqRadius = 0.0;
	m_PlrRadius = 0.0;
	//}}AFX_DATA_INIT

	m_Protected = false;
	m_Modified = false;
	m_NewIdx = -1;
	m_KeyName = _T("WGS84");
	m_PreviousKeyName = m_KeyName;
}

void CelEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CelEdit)
	DDX_Control(pDX, IDC_ELED_KEYNAME, m_KeyNameCombo);
	DDX_Text(pDX, IDC_ELED_ESQDISP, m_EsqString);
	DDX_Text(pDX, IDC_ELED_FLTDISP, m_FlatString);
	DDX_Text(pDX, IDC_ELED_SOURCE, m_Source);
	DDV_MaxChars(pDX, m_Source, 63);
	DDX_Text(pDX, IDC_ELED_DESCR, m_Description);
	DDX_Text(pDX, IDC_ELED_EQRAD, m_EqRadius);
	DDV_MinMaxDouble(pDX, m_EqRadius, 1.e-004, 99999999.);
	DDX_Text(pDX, IDC_ELED_PLRAD, m_PlrRadius);
	DDV_MinMaxDouble(pDX, m_PlrRadius, 1.e-003, 99999999.);
	//}}AFX_DATA_MAP
}

void CelEdit::SetKeyName (const char* elKeyName)
{
	char kyTemp [cs_KEYNM_DEF + 2];

	CS_stncp (kyTemp,elKeyName,sizeof (kyTemp));
	CS_nampp (kyTemp);
	if (CS_elIsValid (kyTemp))
	{
		m_KeyName = kyTemp;
	}
}

const char* CelEdit::GetKeyName ()
{
	return (LPCTSTR)m_KeyName;
}

BOOL CelEdit::OnInitDialog ()
{
	CWnd *wp;

	CDialog::OnInitDialog ();

	// Enumerate the current ellisoid key names and populate the
	// Key Name combo box.  We record the CS_MAP index with the
	// entry in case MFC doesn't sort the same as CS-MAP.  Then,
	// we select the initial ellipsoid as desired, populate the
	// the necessary fields, and display the whole mess.

	CS_recvr ();
	RebuildComboBox ();
	ChangeEllipsoid (m_KeyName);

	// Disable the Help button if help isn't available.
	wp = GetDlgItem (ID_ELED_HELP);
	if (wp != NULL) wp->EnableWindow (CS_isHlpAvailable ());
	return (TRUE);
}

void CelEdit::RebuildComboBox ()
{
	int ii;
	char elName [32];

	m_KeyNameCombo.ResetContent ();
	for (ii = 0;CS_elEnum (ii,elName,sizeof (elName)) > 0;ii += 1)
	{
		m_KeyNameCombo.AddString (elName);
	}
	if (ii < 0)
	{
		char errMesg [256];
		CS_errmsg (errMesg,sizeof (errMesg));
		AfxMessageBox (errMesg);
	}
}

void CelEdit::NewEllipsoid (const CString& elKeyName)
{
	m_KeyName = elKeyName;
	m_Description.Empty ();
	m_Source.Empty ();
	m_EqRadius = 0.0;
	m_PlrRadius = 0.0;
	m_EsqString.Empty ();
	m_FlatString.Empty ();
	return;
}

bool CelEdit::ChangeEllipsoid (const CString& elKeyName)
{
	if (!GetEllipsoid (elKeyName)) return false;
	if (m_KeyNameCombo.SelectString (-1,m_KeyName) == CB_ERR)
	{	// Force WGS84 if the provided ellipsoid neame was bogus
		m_KeyName = _T("WGS84");
		m_KeyNameCombo.SelectString (-1,(LPCTSTR)m_KeyName);
		GetEllipsoid (m_KeyName);
	}
	CalculateDisplay ();
	m_Modified = false;
	m_NewIdx = -1;
	SetButtons ();
	UpdateData (FALSE);
	return true;
}

bool CelEdit::GetEllipsoid (const CString& elKeyName)
{
	struct cs_Eldef_ *elPtr;

	elPtr = CS_eldef (elKeyName);
	if (elPtr == NULL)
	{
		char errMesg [256];
		CS_errmsg (errMesg,sizeof (errMesg));
		AfxMessageBox (errMesg);
		return false;
	}
	m_Protected = (CS_prchk (elPtr->protect) != 0);
	m_Description = elPtr->name;
	m_Source = elPtr->source;
	m_EqRadius = elPtr->e_rad;
	m_PlrRadius = elPtr->p_rad;
	m_KeyName = elKeyName;
	CS_free (elPtr);
	return true;
}

int CelEdit::PutEllipsoid ()
{
	struct cs_Eldef_ elDef;

	memset (&elDef,'\0',sizeof (elDef));
	strncpy (elDef.key_nm,(LPCTSTR)m_KeyName,sizeof (elDef.key_nm));
	elDef.key_nm [sizeof (elDef.key_nm) - 1] = '\0';
	strncpy (elDef.name,(LPCTSTR)m_Description,sizeof (elDef.name));
	elDef.name [sizeof (elDef.name) - 1] = '\0';
	strncpy (elDef.source,(LPCTSTR)m_Source,sizeof (elDef.source));
	elDef.source [sizeof (elDef.source) - 1] = '\0';
	elDef.e_rad = m_EqRadius;
	elDef.p_rad = m_PlrRadius;
	elDef.flat = 1.0 - m_EqRadius / m_PlrRadius;
	double aSq = m_EqRadius * m_EqRadius;
	double bSq = m_PlrRadius * m_PlrRadius;
	elDef.ecent = sqrt ((aSq - bSq) / aSq);
	elDef.protect = 0;

	int st = CS_elupd (&elDef,0);
	if (st < 0)
	{
		char errMesg [256];
		CS_errmsg (errMesg,sizeof (errMesg));
		AfxMessageBox (errMesg);
	}
	return (st);
}

bool CelEdit::DeleteEllipsoid (const CString& elKeyName)
{
	bool rtnValue = true;
	int st = IDOK;
	struct cs_Eldef_ elDef;

	if (m_Protected)
	{
		AfxMessageBox ("Displayed ellipsoid definition is protected and may not be deleted.");
		st = IDCANCEL;
		rtnValue = false;
	}
	else
	{
		st = AfxMessageBox ("Click 'OK' to confirm your request to delete this ellipsoid definition.",MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2);
		rtnValue = false;
	}
	if (st == IDOK)
	{
		memset (&elDef,'\0',sizeof (elDef));
		strncpy (elDef.key_nm,(LPCTSTR)elKeyName,sizeof (elDef.key_nm));
		int st = CS_eldel (&elDef);
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

void CelEdit::CalculateDisplay ()
{
	double eSq;
	double flat;

	if (m_PlrRadius <= 0.0 || m_EqRadius <= 0.0 || fabs (m_PlrRadius - m_EqRadius) < 0.001)
	{	// Don't want to divide by zero.
		m_PlrRadius = m_EqRadius;
		m_EsqString.Empty ();
		m_FlatString.Empty ();
	}
	else
	{
		flat = 1.0 - m_PlrRadius / m_EqRadius;
		eSq = (flat + flat) - (flat * flat);
		m_EsqString.Format ("%.10f",eSq);
		m_FlatString.Format ("%.6f",(1.0 / flat));
	}
	return;
}

BEGIN_MESSAGE_MAP(CelEdit, CDialog)
	//{{AFX_MSG_MAP(CelEdit)
	ON_BN_CLICKED(ID_ELED_CLOSE, OnEledClose)
	ON_BN_CLICKED(ID_ELED_HELP, OnEledHelp)
	ON_EN_CHANGE(IDC_ELED_DESCR, OnChange)
	ON_BN_CLICKED(ID_ELED_NEWCNCL, OnEledNewcncl)
	ON_EN_KILLFOCUS(IDC_ELED_PLRAD, OnChangeRadii)
	ON_BN_CLICKED(ID_ELED_DELSAV, OnEledDelsav)
	ON_EN_CHANGE(IDC_ELED_SOURCE, OnChange)
	ON_EN_KILLFOCUS(IDC_ELED_EQRAD, OnChangeRadii)
	ON_EN_CHANGE(IDC_ELED_EQRAD, OnChange)
	ON_EN_CHANGE(IDC_ELED_PLRAD, OnChange)
	ON_CBN_SELCHANGE(IDC_ELED_KEYNAME, OnNewSelection)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CelEdit message handlers

void CelEdit::OnEledClose() 
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

void CelEdit::OnCancel ()
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

void CelEdit::OnEledDelsav() 
{
	int st;

	if (m_Modified)
	{	// Here to perform the save operation.
		if (!UpdateData (TRUE)) return;
		st = PutEllipsoid ();
		if (st == 0)
		{
			CS_recvr ();
			RebuildComboBox ();
		}
		if (st >= 0)
		{
			m_NewIdx = -1;
			ChangeEllipsoid (m_KeyName);
		}
	}
	else
	{	// Here to perform the delete operation.  Must determine
		// which ellipsoid to display after the delete operation.
		char elName [32];
		int newIdx = 0;
		for (int ii = 0;CS_elEnum (ii,elName,sizeof (elName)) > 0;ii += 1)
		{
			if (m_KeyName == elName) break;
			newIdx = ii;		
		}
		if (CS_elEnum (newIdx,elName,sizeof (elName)) <= 0)
		{	// Display WGS84 if all else fails.
			strcpy (elName,"WGS84");
		}
		if (DeleteEllipsoid (m_KeyName))
		{
			m_KeyName = elName;
			// Rebuild the combo box with new names and indices.
			CS_recvr ();
			RebuildComboBox ();
			// Select the new ellipsoid
			ChangeEllipsoid (m_KeyName);
		}
	}
}
void CelEdit::OnEledHelp() 
{
	CSwinhlp (m_hWnd,csHLPID_ELEDIT);
}
void CelEdit::OnEledNewcncl()
{
	if (m_Modified)
	{	// Here to perform a cancel.
		if (m_NewIdx >= 0)
		{
			m_KeyNameCombo.DeleteString (m_NewIdx);
			m_NewIdx = -1;
			m_KeyName = m_PreviousKeyName;
		}
		ChangeEllipsoid ((LPCTSTR)m_KeyName);
	}
	else
	{
		// Here to create a new ellipsoid.  Save the current name for
		// use in the event of a subsequent cancel operation.  Then,
		// have operator provide the name of the new ellipsoid.

		m_PreviousKeyName = m_KeyName;
		CnewKeyName elNewName (CnewKeyName::Ellipsoid,this);
		INT_PTR st = elNewName.DoModal ();
		if (st == IDOK)
		{
			m_KeyName = elNewName.GetNewName ();
			// See if we are to reset all values.
			if (!elNewName.GetPreserve ())
			{
				NewEllipsoid (m_KeyName);
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

void CelEdit::OnNewSelection() 
{
	int idx = m_KeyNameCombo.GetCurSel ();
	m_KeyNameCombo.GetLBText (idx,m_KeyName);
	ChangeEllipsoid (m_KeyName);
	return;
}

void CelEdit::OnChange() 
{
	if (!m_Modified)
	{
		if (m_Protected)
		{
			AfxMessageBox (_T("Current definition is protected.\nYou will not be able to save your changes."));
		}
		m_Modified = true;
		SetButtons ();
	}
}

void CelEdit::OnChangeRadii() 
{
	if (!UpdateData (TRUE)) return;
	CalculateDisplay ();
	UpdateData (FALSE);
	return;
}

void CelEdit::SetButtons ()
{
	CWnd *wp;

	wp = GetDlgItem (ID_ELED_NEWCNCL);
	if (wp != NULL) wp->SetWindowText (m_Modified ? "Cancel" : "New");
	wp = GetDlgItem (ID_ELED_DELSAV);
	if (wp != NULL)
	{
		wp->SetWindowText (m_Modified ? "Save" : "Delete");
		wp->EnableWindow (!m_Protected);
	}
	wp = GetDlgItem (IDC_ELED_KEYNAME);
	if (wp != NULL) wp->EnableWindow (!m_Modified);
}
#endif
