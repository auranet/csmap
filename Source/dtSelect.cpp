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

			 File Name: $RCSfile: dtSelect.cpp $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #5 $
		 Check In Date:	$Date: 2006/11/27 $

		Last Revision:	$Log: dtSelect.cpp $
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
		Last Revision:	Revision 11.401  2003/05/01 23:06:27  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:21  nto
		Last Revision:	Official Release 11.03
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
		Last Revision:	Revision 10.701  2001/09/18 19:36:09  nto
		Last Revision:	Added a 'C' callable variation which returns all descriptive information
		Last Revision:	in addition to the selected datum key name.
		Last Revision:	Revision 10.700  2001/01/25 04:13:56  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:51  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:33  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:17:03  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:35  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:24  nto
		Last Revision:	Revision 10.1  2000/01/31 00:25:35  nto
		Last Revision:	PCLint clean up.
		Last Revision:	Revision 10.0  1999/10/05 18:27:20  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:31  nto
		Last Revision:	Revision 1.2  1999/09/12 02:58:10  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/dtSelect.cpp#5 $"};
#endif

#if defined (__MFC__)

#include "cs_map.h"
#include "cs_mfc.h"
#include "cs_hlp.h"

///////////////////////////////////////////////////////////////////////////////
// Basic 'C' callable function interface
int EXP_LVL1 CS_dtSelector (char *dtKeyName)
{
	CdtSelect dtSelect;

	dtSelect.SetInitialDatum (dtKeyName);
	INT_PTR st = dtSelect.DoModal ();
	if (st == IDOK)
	{
		CS_stncp (dtKeyName,dtSelect.GetSelectedDatum (),cs_KEYNM_DEF);
	}
	return (int)st;
}
int EXP_LVL1 CS_dtSelectorA (char *dtKeyName,char *description,char *source,char *ellipsoid,char *technique)
{
	CdtSelect dtSelect;

	dtSelect.SetInitialDatum (dtKeyName);
	INT_PTR st = dtSelect.DoModal ();
	if (st == IDOK)
	{
		CS_stncp (dtKeyName,dtSelect.GetSelectedDatum (),cs_KEYNM_DEF);
		CS_stncp (description,dtSelect.GetSelectedDescription (),64);
		CS_stncp (source,dtSelect.GetSelectedSource (),64);
		CS_stncp (ellipsoid,dtSelect.GetSelectedEllipsoid (),cs_KEYNM_DEF);
		CS_stncp (technique,dtSelect.GetSelectedTechnique (),32);
	}
	return (int)st;
}
/**********************************************************************
**	CdtSelect dtSelect;
**			dtSelect.SetInitialDatum (initialName);
**			finalName = GetSelectedDatum ();
**
**	char* initialName;			key name of the datum which is to be displayed
**								upon dialog activation.
**	char* finalName;			pointer to static memory containing the key name
**								of the datum definition which was displayed
**								when the user terminated the dialog box.
**********************************************************************/

/////////////////////////////////////////////////////////////////////////////
// CdtSelect dialog
CdtSelect::CdtSelect(CWnd* pParent /*=NULL*/)
		: CDialog(CdtSelect::IDD, pParent)
{
	//{{AFX_DATA_INIT(CdtSelect)
	m_Description = _T("");
	m_Ellipsoid = _T("");
	m_Source = _T("");
	m_Technique = _T("");
	//}}AFX_DATA_INIT
	m_KeyName = "WGS84";
}
void CdtSelect::SetInitialDatum (const char *dtKeyName)
{
	m_KeyName = dtKeyName;
}
BOOL CdtSelect::OnInitDialog (void)
{
	int ii, idx;
	CWnd *wp;
	char keyName [24];

	CDialog::OnInitDialog ();

	// Populate the datum key name combo box.

	m_KeyNameCombo.ResetContent ();
	for (ii = 0;
		 CS_dtEnum (ii,keyName,sizeof (keyName)) > 0;
		 ii += 1)
	{
		idx = m_KeyNameCombo.AddString (keyName);
		m_KeyNameCombo.SetItemData (idx,ii);
	}
	if (!CS_dtIsValid (m_KeyName))
	{
		m_KeyName = "WGS84";
	}
	m_KeyNameCombo.SelectString (-1,m_KeyName);
	ShowDetails ();

	wp = GetDlgItem (ID_DTSL_HELP);
	if (wp != NULL) wp->EnableWindow (CS_isHlpAvailable ());
	return (TRUE);
}

void CdtSelect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CdtSelect)
	DDX_Control(pDX, IDC_DTSL_KEYNAME, m_KeyNameCombo);
	DDX_Text(pDX, IDC_DTSL_DESCR, m_Description);
	DDV_MaxChars(pDX, m_Description, 63);
	DDX_Text(pDX, IDC_DTSL_ELLIP, m_Ellipsoid);
	DDV_MaxChars(pDX, m_Ellipsoid, 63);
	DDX_Text(pDX, IDC_DTSL_SOURCE, m_Source);
	DDV_MaxChars(pDX, m_Source, 63);
	DDX_Text(pDX, IDC_DTSL_TECHNIQUE, m_Technique);
	DDV_MaxChars(pDX, m_Technique, 63);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CdtSelect, CDialog)
	//{{AFX_MSG_MAP(CdtSelect)
	ON_CBN_SELCHANGE(IDC_DTSL_KEYNAME, OnSelchangeDtslKeyname)
	ON_BN_CLICKED(ID_DTSL_HELP, OnDtslHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CdtSelect message handlers

void CdtSelect::OnOK() 
{
	CDialog::OnOK();
}
void CdtSelect::OnSelchangeDtslKeyname() 
{
	int idx;
	char keyName [24];

	idx = m_KeyNameCombo.GetCurSel ();
	idx = static_cast<int>(m_KeyNameCombo.GetItemData (idx));
	CS_dtEnum (idx,keyName,sizeof (keyName));
	m_KeyName = keyName;
	ShowDetails ();
	return;
}
void CdtSelect::OnDtslHelp() 
{
	CSwinhlp (m_hWnd,csHLPID_DTSELECTOR);
}
void CdtSelect::ShowDetails ()
{
	int ii, ident;
	struct cs_Dtdef_ *dtPtr;
	struct cs_Eldef_ *elPtr;
	char description [64];

	dtPtr = CS_dtdef (m_KeyName);
	if (dtPtr == NULL)
	{
		char errMesg [256];
		CS_errmsg (errMesg,sizeof (errMesg));
		AfxMessageBox (errMesg);
		return;
	}
	m_Description = dtPtr->name;
	m_Source = dtPtr->source;
	elPtr = CS_eldef (dtPtr->ell_knm);
	if (elPtr == NULL) m_Ellipsoid = "???";
	else
	{
		m_Ellipsoid = elPtr->name;
		CS_free (elPtr);
	}
	m_Technique = "???";
	for (ii = 0;
		 CS_viaEnum (ii,description,sizeof (description),&ident) > 0;
		 ii += 1)
	{
		if (dtPtr->to84_via == ident)
		{
			m_Technique = description;
			break;
		}
	}
	CS_free (dtPtr);
	UpdateData (FALSE);
	return;
}

#endif
