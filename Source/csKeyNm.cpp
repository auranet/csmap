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

			 File Name: $RCSfile: csKeyNm.cpp $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #4 $
		 Check In Date:	$Date: 2006/11/25 $

		Last Revision:	$Log: csKeyNm.cpp $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:04  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:07  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:04  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:13  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:21  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:09  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:49  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:24  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:52  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:18  nto
		Last Revision:	Revision 11.301  2003/04/04 00:41:13  nto
		Last Revision:	Added a new 'C' interface which supports use of this dialog for non-dictionary names (i.e. Tralaine format template names).
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
		Last Revision:	Revision 10.1001  2002/04/18 21:09:28  nto
		Last Revision:	Added 'C' access to the dialog, and checking of the name as a new name.
		Last Revision:	Revision 10.1000  2002/02/23 21:18:23  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:08  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:43  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:37  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:14  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:16:49  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:19  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:12  nto
		Last Revision:	Revision 10.1  2000/01/31 00:23:30  nto
		Last Revision:	PCLint clean up.
		Last Revision:	Revision 10.0  1999/10/05 18:27:11  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:22  nto
		Last Revision:	Revision 1.2  1999/09/12 03:58:02  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/csKeyNm.cpp#4 $"};
#endif

#if defined (__MFC__)

#include "cs_map.h"
#include "cs_mfc.h"
#include "cs_hlp.h"

extern "C" char cs_Unique;
///////////////////////////////////////////////////////////////////////////////
// Basic 'C' callable function interface
extern "C" int EXP_LVL1 CS_newKeyName (char *keyName,int type,int preserve)
{
	int st = 0;

	CnewKeyName dlgNewKeyName (static_cast<CnewKeyName::TnewKeyNameTypes>(type));

	dlgNewKeyName.SetPreserveEnable (preserve != 0);
	INT_PTR stDlg = dlgNewKeyName.DoModal ();
	if (stDlg == IDOK)
	{
		CString tempStr = dlgNewKeyName.GetNewName ();
		CS_stncp (keyName,(LPCTSTR)tempStr,cs_KEYNM_DEF);
		st = dlgNewKeyName.GetPreserve () ? 1 : 0;
	}
	else
	{
		st = -1;
	}
	return st;
}
extern "C" int EXP_LVL1 CS_newKeyNameEx (char *keyName,int type,int preserve,const char *title,const char *legend)
{
	int st = 0;

	CnewKeyName dlgNewKeyName (static_cast<CnewKeyName::TnewKeyNameTypes>(type));

	dlgNewKeyName.SetPreserveEnable (preserve != 0);
	dlgNewKeyName.SetTitle (title);
	dlgNewKeyName.SetLegend (legend);
	INT_PTR stDlg = dlgNewKeyName.DoModal ();
	if (stDlg == IDOK)
	{
		CString tempStr = dlgNewKeyName.GetNewName ();
		CS_stncp (keyName,(LPCTSTR)tempStr,cs_KEYNM_DEF);
		st = dlgNewKeyName.GetPreserve () ? 1 : 0;
	}
	else
	{
		st = -1;
	}
	return st;
}
/**********************************************************************
**	CnewKeyName (type,pParent);
**	CString GetNewKeyName (void);
**	bool GetPreserve (void);
**
**	Dialog used to acquire a new key name.  The type of key name
**	is specified at construction time.  Type is necessary so that
**	an appropriate check for an existing name can be made.
**
**	Preserve is the status of the "Preserve Existing Data" check
**	box.  Of course, you use GetNewKeyName to obtain the key
**	name the user entered if DoDialog () returns IDOK.
**********************************************************************/

/////////////////////////////////////////////////////////////////////////////
// CnewKeyName dialog

CnewKeyName::CnewKeyName(TnewKeyNameTypes type,CWnd* pParent)
	: CDialog(CnewKeyName::IDD, pParent)
{
	//{{AFX_DATA_INIT(CnewKeyName)
	m_NewKeyName = _T("");
	m_Preserve = TRUE;
	//}}AFX_DATA_INIT
	m_PreserveEnabled = true;
	m_Type = type;
	m_Title = "New Dictionary Entry Key Name";
	m_Legend = "User defined key names usually require a colon character in the name.  "
			   "While case is preserved for display purposes, it is NOT used to distinguish one name from another.";
}
BOOL CnewKeyName::OnInitDialog ()
{
	CWnd *wp;

	CDialog::OnInitDialog ();

	// Disable the Help button if Help is not available
	wp = GetDlgItem (IDCHELP);
	if (wp != NULL) wp->EnableWindow (CS_isHlpAvailable ());
	wp = GetDlgItem (IDC_PRESERVE);
	if (wp != NULL) wp->EnableWindow (m_PreserveEnabled);
	wp = GetDlgItem (IDC_KYNM_LEGEND);
	if (wp != NULL) wp->SetWindowText ((LPCTSTR)m_Legend);
	SetWindowText (m_Title);
	return (TRUE);
}
void CnewKeyName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CnewKeyName)
	DDX_Text(pDX, IDC_NEWKEYNAME, m_NewKeyName);
	DDV_MaxChars(pDX, m_NewKeyName, 23);
	DDX_Check(pDX, IDC_PRESERVE, m_Preserve);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CnewKeyName, CDialog)
	//{{AFX_MSG_MAP(CnewKeyName)
	ON_BN_CLICKED(IDCHELP, OnChelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CnewKeyName message handlers
void CnewKeyName::OnOK() 
{
	char keyName [32];
	
	if (!UpdateData (TRUE)) return;
	// Verify that the new meets other requirements.
	strncpy (keyName,(LPCTSTR)m_NewKeyName,sizeof (keyName));
	keyName [sizeof (keyName) - 1] = '\0';
	if (CS_nampp (keyName) != 0)
	{
		// Show dialog box error and return.
		// By not calling CDialog::OnOK, the dialog box remains active.
		char errMesg [256];
		CS_errmsg (errMesg,sizeof (errMesg));
		AfxMessageBox (errMesg);
		return;
	}

	// Note, CS_nampp doesn't know that this is a new name, but we do.  So we
	// enforce the cs_Unique restriction if active.
	if (cs_Unique != '\0' && strchr (keyName,cs_Unique) == NULL && m_Type != NonDict)
	{
		char errMsg [256];
		sprintf (errMsg,"Keynames of user definitions must contain the '%c' character to avoid name collisions with\nupdate distributions.  Please adjust name appropriately.",cs_Unique);   
		AfxMessageBox (errMsg,MB_OK | MB_ICONEXCLAMATION);
		return;
	}

	// Verify that the new name does not already exist.
	switch (m_Type) {
	case CoordSys:
		if (CS_csIsValid (keyName))
		{
			AfxMessageBox ("Coordinate system with this name already exists.\nPlease choose another name.",MB_OK | MB_ICONEXCLAMATION);
			return;
		}
		break;
	case Datum:
		if (CS_dtIsValid (keyName))
		{
			AfxMessageBox ("Datum with this key name already exists.\nPlease choose another name.",MB_OK | MB_ICONEXCLAMATION);
			return;
		}
		break;
	case Ellipsoid:
		if (CS_elIsValid (keyName))
		{
			AfxMessageBox ("Ellipsoid with this key name already exists.\nPlease choose another name.",MB_OK | MB_ICONEXCLAMATION);
			return;
		}
		break;
	case NonDict:
	default:
		break;
	}
	// If we're still here, we have a valid name.
	CDialog::OnOK();
}
void CnewKeyName::OnChelp()
{
	CSwinhlp (m_hWnd,csHLPID_NEWKEYNM);
}
#endif
