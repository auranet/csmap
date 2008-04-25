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

			 File Name: $RCSfile: elSelect.cpp $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #5 $
		 Check In Date:	$Date: 2006/11/27 $

		Last Revision:	$Log: elSelect.cpp $
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
		Last Revision:	Revision 11.100  2002/11/22 19:38:49  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1500  2002/09/22 00:01:25  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:27  nto
		Last Revision:	Revision 10.1200  2002/06/20 18:00:32  nto
		Last Revision:	Official release: 10.12
		Last Revision:	Revision 10.1100  2002/06/13 14:18:46  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:31  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:15  nto
		Last Revision:	Revision 10.701  2001/09/18 19:36:44  nto
		Last Revision:	Added a 'C' callable version which returns all descriptive information
		Last Revision:	in addition to the selected ellipsoid key name.
		Last Revision:	Revision 10.700  2001/01/25 04:13:57  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:51  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.500  2000/10/27 07:38:34  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:17:03  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:36  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:24  nto
		Last Revision:	Revision 10.1  2000/01/31 00:26:21  nto
		Last Revision:	PCLint clean up.
		Last Revision:	Revision 10.0  1999/10/05 18:27:20  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:31  nto
		Last Revision:	Revision 1.2  1999/09/12 03:04:58  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/elSelect.cpp#5 $"};
#endif

#if defined (__MFC__)

#include "cs_map.h"
#include "cs_mfc.h"
#include "cs_hlp.h"

///////////////////////////////////////////////////////////////////////////////
// Basic 'C' callable function interface
int EXP_LVL1 CS_elSelector (char *elKeyName)
{
	CelSelect elSelect;

	elSelect.SetInitialEllipsoid (elKeyName);
	INT_PTR st = elSelect.DoModal ();
	if (st == IDOK)
	{
		CS_stncp (elKeyName,elSelect.GetSelectedEllipsoid (),cs_KEYNM_DEF);
	}
	return (int)st;
}
int EXP_LVL1 CS_elSelectorA (char *elKeyName,char *description,char *source)
{
	CelSelect elSelect;

	elSelect.SetInitialEllipsoid (elKeyName);
	INT_PTR st = elSelect.DoModal ();
	if (st == IDOK)
	{
		CS_stncp (elKeyName,elSelect.GetSelectedEllipsoid (),cs_KEYNM_DEF);
		CS_stncp (description,elSelect.GetSelectedDescription (),64);
		CS_stncp (source,elSelect.GetSelectedSource (),64);
	}
	return (int)st;
}
/**********************************************************************
**	CelSelect elSelect;
**			elSelect.SetInitialEllipsoid (initialName);
**			finalName = GetSelectedEllipsoid ();
**
**	char* initialName;			key name of the ellipsoid which is to be displayed
**								upon dialog activation.
**	char* finalName;			pointer to static memory containing the key name
**								of the ellipsoid definition which was displayed
**								when the user terminated the dialog box.
**********************************************************************/

/////////////////////////////////////////////////////////////////////////////
// CelSelect dialog
CelSelect::CelSelect(CWnd* pParent /*=NULL*/)
				: CDialog(CelSelect::IDD, pParent)
{
	//{{AFX_DATA_INIT(CelSelect)
	m_Description = _T("");
	m_Source = _T("");
	m_Numbers = _T("");
	//}}AFX_DATA_INIT
	m_KeyName = "WGS84";
}
void CelSelect::SetInitialEllipsoid (const char* elKeyName)
{
	m_KeyName = elKeyName;
}
BOOL CelSelect::OnInitDialog ()
{
	int ii, idx;
	CWnd *wp;
	char keyName [24];

	CDialog::OnInitDialog ();

	m_KeyNameCombo.ResetContent ();
	for (ii = 0;
		 CS_elEnum (ii,keyName,sizeof (keyName)) > 0;
		 ii += 1)
	{
		idx = m_KeyNameCombo.AddString (keyName);
		m_KeyNameCombo.SetItemData (idx,ii);
	}
	if (!CS_elIsValid (m_KeyName))
	{
		m_KeyName = "WGS84";
	}
	m_KeyNameCombo.SelectString (-1,m_KeyName);
	ShowDetails ();

	// Disable the Help button if Help is not available
	wp = GetDlgItem (ID_ELSL_HELP);
	if (wp != NULL) wp->EnableWindow (CS_isHlpAvailable ());

	return (TRUE);
}
void CelSelect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CelSelect)
	DDX_Control(pDX, IDC_ELSL_KEYNAME, m_KeyNameCombo);
	DDX_Text(pDX, IDC_ELSL_DESCR, m_Description);
	DDV_MaxChars(pDX, m_Description, 64);
	DDX_Text(pDX, IDC_ELSL_SOURCE, m_Source);
	DDV_MaxChars(pDX, m_Source, 64);
	DDX_Text(pDX, IDC_ELSL_NUMBERS, m_Numbers);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CelSelect, CDialog)
	//{{AFX_MSG_MAP(CelSelect)
	ON_BN_CLICKED(ID_ELSL_HELP, OnElslHelp)
	ON_CBN_SELCHANGE(IDC_ELSL_KEYNAME, OnSelchangeElslKeyname)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CelSelect message handlers
void CelSelect::OnElslHelp() 
{
	CSwinhlp (m_hWnd,csHLPID_ELSELECTOR);
}
void CelSelect::OnSelchangeElslKeyname() 
{
	int idx;
	char keyName [24];

	idx = m_KeyNameCombo.GetCurSel ();
	idx = static_cast<int>(m_KeyNameCombo.GetItemData (idx));
	CS_elEnum (idx,keyName,sizeof (keyName));
	m_KeyName = keyName;
	ShowDetails ();
	return;
}
void CelSelect::OnOK() 
{
	if (!UpdateData (TRUE)) return;
	CDialog::OnOK();
}
void CelSelect::ShowDetails ()
{
	double flat;
	struct cs_Eldef_ *elPtr;

	elPtr = CS_eldef (m_KeyName);
	if (elPtr == NULL)
	{
		char errMesg [256];
		CS_errmsg (errMesg,sizeof (errMesg));
		AfxMessageBox (errMesg);
		return;
	}
	flat = 0.0;
	if (fabs (elPtr->flat) > 1.0E-10) flat = 1.0 / elPtr->flat;
	m_Description = elPtr->name;
	m_Source = elPtr->source;
	m_Numbers.Format ("%12.3f, %12.3f, %10.5f, %10.8f",
			elPtr->e_rad,
			elPtr->p_rad,
			flat,
			elPtr->ecent * elPtr->ecent);
	CS_free (elPtr);
	UpdateData (FALSE);
	return;
}
#endif
