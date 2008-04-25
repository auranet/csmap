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

			 File Name: $RCSfile: csDataDir.cpp $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #4 $
		 Check In Date:	$Date: 2006/11/25 $

		Last Revision:	$Log: csDataDir.cpp $
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
		Last Revision:	Revision 11.700  2003/12/19 01:49:48  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:24  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:51  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:18  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:12  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:39  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1502  2002/11/06 23:57:10  nto
		Last Revision:	Added a browse button for the Directory control.
		Last Revision:	Revision 10.1501  2002/10/06 18:07:04  nto
		Last Revision:	Converted all direct references to 'access' to CS_access.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:15  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:19  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:10  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:32  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:23  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:07  nto
		Last Revision:	Revision 10.701  2001/05/01 16:47:01  nto
		Last Revision:	Correct possibility of character overflow on Unix systems where path names can get quite long.
		Last Revision:	Revision 10.700  2001/01/25 04:13:41  nto
		Last Revision:	Revision 10.600  2000/12/11 06:39:35  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.501  2000/12/04 18:03:05  nto
		Last Revision:	Set the dictionary name changes before attempting to change the directory.  This never worked before if the names changed in addition to the directory.
		Last Revision:	Revision 10.500  2000/10/27 07:38:13  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.400  2000/09/13 01:16:48  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:18  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:11  nto
		Last Revision:	Revision 10.1  2000/01/31 00:15:51  nto
		Last Revision:	PCLint clean up.
		Last Revision:	Revision 10.0  1999/10/05 18:27:10  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:21  nto
		Last Revision:	Revision 1.2  1999/09/12 02:34:14  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/csDataDir.cpp#4 $"};
#endif

#if defined (__MFC__)

#include "cs_map.h"
#include "cs_mfc.h"
#include "cs_hlp.h"

extern "C" char cs_DirsepC;
extern "C" char cs_Dir [];
extern "C" char *cs_DirP;
extern "C" char cs_Csname [];
extern "C" char cs_Dtname [];
extern "C" char cs_Elname [];


/**********************************************************************
**	CcsDataDir csDataDir;
**		extern "C" CS_csDataDir ();
**********************************************************************/

///////////////////////////////////////////////////////////////////////////////
// 'C' callable DataDir function.  Name is not mangled for ease of access from
//	Visual Basic, et. al.
extern "C" int EXP_LVL1 CS_csDataDir (int flags)
{
	int rtnVal;

	CS_recvr ();
	CcsDataDir csDataDir;
	if (flags & 1) csDataDir.EnableINIBox ();
	if (flags & 2) csDataDir.EnableRegBox ();
	csDataDir.DoModal ();
	rtnVal = 0;
	if (csDataDir.GetIniSave ()) rtnVal |= 1;
	if (csDataDir.GetRegSave ()) rtnVal |= 2;
	return rtnVal;
}
/////////////////////////////////////////////////////////////////////////////
// CcsDataDir dialog
CcsDataDir::CcsDataDir(CWnd* pParent /*=NULL*/)
			: CDialog(CcsDataDir::IDD, pParent)
{
	//{{AFX_DATA_INIT(CcsDataDir)
	m_CSName = _T("");
	m_DataDirectory = _T("");
	m_ElName = _T("");
	m_DtName = _T("");
	m_SaveInINI = FALSE;
	m_SaveInRegistry = FALSE;
	//}}AFX_DATA_INIT
	m_EnableINI = false;
	m_EnableReg = false;
	m_CSName = cs_Csname;
	m_DtName = cs_Dtname;
	m_ElName = cs_Elname;
	char ctemp [MAXPATH];
	*cs_DirP = '\0';
	CS_stncp (ctemp,cs_Dir,sizeof (ctemp));
	m_DataDirectory = ctemp;
}
void CcsDataDir::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CcsDataDir)
	DDX_Text(pDX, IDC_MPDR_CSNAME, m_CSName);
	DDX_Text(pDX, IDC_MPDR_DIRECTORY, m_DataDirectory);
	DDX_Text(pDX, IDC_MPDR_ELNAME, m_ElName);
	DDX_Text(pDX, IDC_MPDR_DTNAME, m_DtName);
	DDX_Check(pDX, IDC_MPDR_SVINI, m_SaveInINI);
	DDX_Check(pDX, IDC_MPDR_SVREGISTRY, m_SaveInRegistry);
	//}}AFX_DATA_MAP
}
BOOL CcsDataDir::OnInitDialog ()
{
	CWnd *wp;

	CDialog::OnInitDialog ();

	// Hide the check boxes as is appropriate.
	wp = GetDlgItem (IDC_MPDR_SVINI);
	if (wp != NULL) wp->EnableWindow (m_EnableINI);
	wp = GetDlgItem (IDC_MPDR_SVREGISTRY);
	if (wp != NULL) wp->EnableWindow (m_EnableReg);

	// Hide the Help button if Help isn't available.
	wp = GetDlgItem (IDC_MPDR_HELP);
	if (wp != NULL) wp->EnableWindow (CS_isHlpAvailable ());
	return TRUE;
}
BEGIN_MESSAGE_MAP(CcsDataDir, CDialog)
	//{{AFX_MSG_MAP(CcsDataDir)
	ON_BN_CLICKED(IDC_MPDR_HELP, OnMpdrHelp)
	ON_BN_CLICKED(IDC_BTN_DIRBRWSE, OnBtnDirbrwse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CcsDataDir message handlers
void CcsDataDir::OnBtnDirbrwse() 
{
	int ii;
	CString newPath;
	DWORD options = OFN_HIDEREADONLY | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR | OFN_SHAREAWARE;

	CS_stcpy (cs_DirP,cs_Csname);
	CFileDialog dataDir (TRUE,NULL,cs_Dir,options,"All Files (*.*)|*.*||",NULL);

	AfxMessageBox ("Windows does not provide a 'directory browser' as a 'common dialog'!  A 'file browser' dialog will next appear.  Use it to specify a directory by choosing a file (any file) in the desired directory.");
	INT_PTR st = dataDir.DoModal ();
	if (st == IDOK)
	{
		newPath = dataDir.GetPathName ();
		ii = newPath.ReverseFind (cs_DirsepC);
		if (ii >= 0)
		{
			m_DataDirectory = newPath.Left (ii);
			UpdateData (FALSE);
		}
	}
}
void CcsDataDir::OnOK ()
{
	char *cp;
	CWnd *wp;
	char ctemp [MAXPATH];

	if (!UpdateData (TRUE)) return;

	// Check the provided data.

	cp = CS_stncp (ctemp,m_DataDirectory,sizeof(ctemp));
	if (strlen (ctemp) < 3 || ctemp [1] != ':')
	{
		AfxMessageBox ("Full path to a directory must be provided.");
		wp = GetDlgItem (IDC_MPDR_DIRECTORY);
		if (wp != NULL) GotoDlgCtrl (wp);
		return;
	}
	if (*(cp - 1) == '\\')
	{
		cp -= 1;
		*cp = '\0';
	}
	if (CS_access (ctemp,0) != 0)
	{
		AfxMessageBox ("Directory provided does not exist.");
		wp = GetDlgItem (IDC_MPDR_DIRECTORY);
		if (wp != NULL) GotoDlgCtrl (wp);
		return;
	}
	*cp++ = '\\';
	strcpy (cp,(LPCTSTR)m_CSName);
	if (CS_access (ctemp,4) != 0)
	{
		AfxMessageBox ("Coordinate System dictionary file with name provided\ndoes not exist in directory provided.");
		wp = GetDlgItem (IDC_MPDR_CSNAME);
		if (wp != NULL) GotoDlgCtrl (wp);
		return;
	}
	strcpy (cp,(LPCTSTR)m_DtName);
	if (CS_access (ctemp,4) != 0)
	{
		AfxMessageBox ("Datum dictionary file with name provided\ndoes not exist in directory provided.");
		wp = GetDlgItem (IDC_MPDR_DTNAME);
		if (wp != NULL) GotoDlgCtrl (wp);
		return;
	}
	strcpy (cp,(LPCTSTR)m_ElName);
	if (CS_access (ctemp,4) != 0)
	{
		AfxMessageBox ("Ellipsoid dictionary file with name provided\ndoes not exist in directory provided.");
		wp = GetDlgItem (IDC_MPDR_ELNAME);
		if (wp != NULL) GotoDlgCtrl (wp);
		return;
	}

	// If we are still here, it all checks out.  We save the stuff in the proper
	// locations.

	CS_csfnm (m_CSName);
	CS_dtfnm (m_DtName);
	CS_elfnm (m_ElName);
	CS_altdr (m_DataDirectory);

#ifdef __SKIP__
	if (m_SaveInRegistry)
	{
		long reg_st;
		HKEY strtKey = HKEY_LOCAL_MACHINE;
		HKEY softKey = 0;
		HKEY mntrKey = 0;
		HKEY trlnKey = 0;
		HKEY vrsnKey = 0;
	
		reg_st = RegOpenKeyEx (strtKey,cs_RKeySoftware,0,KEY_SET_VALUE,&softKey);
		if (reg_st == ERROR_SUCCESS)
		{
			reg_st = RegOpenKeyEx (softKey,cs_RKeyCompany,0,KEY_SET_VALUE,&mntrKey);
			RegCloseKey (softKey);
		}
		if (reg_st == ERROR_SUCCESS)
		{
			reg_st = RegOpenKeyEx (mntrKey,cs_RKeyProduct,0,KEY_SET_VALUE,&trlnKey);
			RegCloseKey (mntrKey);
		}
		if (reg_st == ERROR_SUCCESS)
		{
			reg_st = RegOpenKeyEx (trlnKey,cs_RKeyVersion,0,KEY_SET_VALUE,&vrsnKey);
			RegCloseKey (trlnKey);
		}
		if (reg_st == ERROR_SUCCESS)
		{
			char uctemp [MAXPATH];
			strcpy (uctemp,(LPCTSTR)m_DataDirectory);
			reg_st = RegSetValueEx (vrsnKey,"DataDir",0,REG_SZ,(unsigned char*)uctemp,strlen (uctemp));
			if (reg_st == ERROR_SUCCESS)
			{
				strcpy (uctemp,(LPCTSTR)m_CSName);
				reg_st = RegSetValueEx (vrsnKey,"CSName",0,REG_SZ,(unsigned char*)uctemp,strlen (uctemp));
			}
			if (reg_st == ERROR_SUCCESS)
			{
				strcpy (uctemp,(LPCTSTR)m_DtName);
				reg_st = RegSetValueEx (vrsnKey,"DtName",0,REG_SZ,(unsigned char *)uctemp,strlen (uctemp));
			}
			if (reg_st == ERROR_SUCCESS)
			{
				strcpy (uctemp,(LPCTSTR)m_ElName);
				reg_st = RegSetValueEx (vrsnKey,"ElName",0,REG_SZ,(unsigned char *)uctemp,strlen (uctemp));
			}
			RegCloseKey (vrsnKey);
		}
	}
	if (m_SaveInINI)
	{
		BOOL ok;
		char ctemp [MAXPATH];
		CS_stncp (ctemp,theApp.m_FullPath,sizeof (ctemp));
		cp = strrchr (ctemp,'.');
		if (cp == NULL) return;
		strcpy (cp,".INI");
		if (CS_access (ctemp,0) != 0)
		{
			FILE* fstr = fopen (ctemp,"w");
			fclose (fstr);
		}
		if (CS_access (ctemp,2) != 0)
		{
			AfxMessageBox ("Write permission to .INI file has been denied.");
			return;
		}
		ok = WritePrivateProfileString ("Directories","DataDir",(LPCTSTR)m_DataDirectory,ctemp);
		if (ok)	ok = WritePrivateProfileString ("Directories","CSName",(LPCTSTR)m_CSName,ctemp);
		if (ok)	ok = WritePrivateProfileString ("Directories","DtName",(LPCTSTR)m_DtName,ctemp);
		if (ok)	ok = WritePrivateProfileString ("Directories","ElName",(LPCTSTR)m_ElName,ctemp);
	}
#endif
	CS_recvr ();
	CDialog::OnOK ();
	return;
}
void CcsDataDir::OnMpdrHelp() 
{
	CSwinhlp (m_hWnd,csHLPID_DATADIR_DLG);
}
#endif
