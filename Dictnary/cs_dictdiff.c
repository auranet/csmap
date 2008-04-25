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

			 File Name: $Source: C:/Development/NewCsMap/rcs/CS_dictDiff.c $
			 Full Name:	DICTionary DIFFerence program
		   Description:	Compares dictionary files and reports
						differences.
			   Purpose:	Used to track changes in the dictionary files.

		Revision Level:	$Revision: #5 $
				  Date:	$Date: 2006/11/16 $

		 Last Revision:	$Log: CS_dictDiff.c $
		 Last Revision:	Revision 11.1300  2005/05/25 23:27:08  nto
		 Last Revision:	Official Release 11.13
		 Last Revision:	Revision 11.1200  2005/01/15 18:27:10  nto
		 Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		 Last Revision:	Revision 11.1100  2004/11/01 18:53:07  nto
		 Last Revision:	Official release 11.11
		 Last Revision:	Revision 11.1001  2004/10/07 19:25:16  nto
		 Last Revision:	Revision 11.900  2004/03/26 17:02:23  nto
		 Last Revision:	Official release: 11.09 - 3/25/2003
		 Last Revision:	Revision 11.800  2004/01/13 23:29:11  nto
		 Last Revision:	Revision 11.700  2003/12/19 01:49:51  nto
		 Last Revision:	Official release 11.07
		 Last Revision:	Revision 11.600  2003/12/04 02:46:26  nto
		 Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		 Last Revision:	Revision 11.501  2003/08/22 21:12:54  nto
		 Last Revision:	Official Release: 11.05
		 Last Revision:	Revision 11.401  2003/05/01 23:06:20  nto
		 Last Revision:	Revision 11.300  2003/02/25 04:29:15  nto
		 Last Revision:	Official Release 11.03
		 Last Revision:	Revision 11.100  2002/11/22 19:38:42  nto
		 Last Revision:	Official release: 11.01
		 Last Revision:	Revision 10.1502  2002/11/08 06:14:47  nto
		 Last Revision:	UYpdated for ANSI compliance.
		 Last Revision:	Revision 10.1501  2002/10/03 00:01:57  nto
		 Last Revision:	removed UNIX I/O in favor of ANSI stream I/O.
		 Last Revision:	Revision 10.1500  2002/09/22 00:01:18  nto
		 Last Revision:	Official Release:= 10.15
		 Last Revision:	Revision 10.1400  2002/08/09 18:14:21  nto
		 Last Revision:	Revision 10.1200  2002/07/14 03:26:13  nto
		 Last Revision:	Revision 10.1100  2002/06/13 14:18:36  nto
		 Last Revision:	Release 10.11 Official
		 Last Revision:	Revision 10.1000  2002/02/23 21:18:25  nto
		 Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		 Last Revision:	Revision 10.900  2001/09/24 04:31:09  nto
		 Last Revision:	Revision 10.701  2001/09/18 19:13:34  nto
		 Last Revision:	Use the MAXPATH constant (instead of 260) as the dimension for
		 Last Revision:	character arrays used to hold path names.
		 Last Revision:	Revision 10.700  2001/01/25 04:13:46  nto
		 Last Revision:	Revision 10.600  2000/12/11 06:39:40  nto
		 Last Revision:	Release 10.06
		 Last Revision:	Revision 10.500  2000/10/27 07:38:18  nto
		 Last Revision:	Official Release 10.05
		 Last Revision:	Revision 10.400  2000/09/13 01:16:52  nto
		 Last Revision:	Release 10.04
		 Last Revision:	Revision 10.300  2000/04/04 23:18:23  nto
		 Last Revision:	Revision 10.200  2000/03/02 18:51:15  nto
		 Last Revision:	Revision 1.2  1999/10/09 00:19:22  nto
		 Last Revision:	A releasable version of this program.

		       * * * * R E M A R K S * * * *

  Not very pretty code, but it works.  MOstly done with cut and paste.

******************************************************************************/

#include "cs_map.h"

static void Usage (void);

int main (int argc,char *argv [])
{
	extern char cs_Dir [];
	extern char* cs_DirP;
	extern char cs_Csname [];
	extern char cs_Dtname [];
	extern char cs_Elname [];
	
	/* The following variables are part of the deferred close scheme.  Under
	   ordinary circumstances they preclude having two Coordsys (et al)
	   dictionary files open at once.  We set this variable to zero in
	   order to allow multiple dictionary files to be open. */
	extern csFILE* cs_CsStream;
	extern csFILE* cs_DtStream;
	extern csFILE* cs_ElStream;

	int cmpVal, iTmp;
	int csDiffCnt, dtDiffCnt, elDiffCnt;
	int dummy;
	int nlFlag;

	csFILE *wasStrm, *isStrm;

	char wasDir [MAXPATH];
	char isDir [MAXPATH];
	char errorText [260];

	struct cs_Csdef_ wasCsDef, isCsDef;
	struct cs_Dtdef_ wasDtDef, isDtDef;
	struct cs_Eldef_ wasElDef, isElDef;

	csDiffCnt = 0;
	dtDiffCnt = 0;
	elDiffCnt = 0;

	if (argc != 3) Usage ();

	strncpy (wasDir,argv [1],sizeof (wasDir));
	wasDir [sizeof (wasDir) - 1] = '\0';

	strncpy (isDir,argv [2],sizeof (isDir));
	isDir [sizeof (isDir) - 1] = '\0';

	if (CS_altdr (wasDir) != 0)
	{
		printf ("%s file not found in %s directory.\n",cs_Csname,wasDir);
		Usage ();
	}
	CS_stcpy (cs_DirP,cs_Dtname);
	if (CS_access (cs_Dir,4) != 0)
	{
		printf ("%s file not found in %s directory.\n",cs_Dtname,wasDir);
		Usage ();
	}
	CS_stcpy (cs_DirP,cs_Elname);
	if (CS_access (cs_Dir,4) != 0)
	{
		printf ("%s file not found in %s directory.\n",cs_Elname,wasDir);
		Usage ();
	}

	if (CS_altdr (isDir) != 0)
	{
		printf ("%s file not found in %s directory.\n",cs_Csname,isDir);
		Usage ();
	}
	CS_stcpy (cs_DirP,cs_Dtname);
	if (CS_access (cs_Dir,4) != 0)
	{
		printf ("%s file not found in %s directory.\n",cs_Dtname,isDir);
		Usage ();
	}
	CS_stcpy (cs_DirP,cs_Elname);
	if (CS_access (cs_Dir,4) != 0)
	{
		printf ("%s file not found in %s directory.\n",cs_Elname,isDir);
		Usage ();
	}

	/* Ok, we're ready to do our thing.  Do coordinate systems first. */
	CS_altdr (wasDir);											/*lint !e534 */
	wasStrm = CS_csopn (_STRM_BINRD);
	if (wasStrm == NULL)
	{
		printf ("Open of %s in the 'WAS' directory failed.\n",cs_Csname);
		Usage ();
	}
	cs_CsStream = 0;

	CS_altdr (isDir);											/*lint !e534 */
	isStrm = CS_csopn (_STRM_BINRD);
	if (isStrm == NULL)
	{
		printf ("Open of %s in the 'IS' directory failed.\n",cs_Csname);
		Usage ();
	}
	cs_CsStream = 0;

	/* Now, we loop through the dictionaries.  In this module, we simply
	   compare key names, looking for new definitions, or deleted
	   definitions.  When we have definitions with the same name, we call
	   CS_csDiff to report any differences.

	   First, we prime the pump. */
	iTmp = CS_csrd (wasStrm,&wasCsDef,&dummy);
	if (iTmp < 0)
	{
		CS_errmsg (errorText,sizeof (errorText));
		printf ("%s\n",errorText);
		Usage ();
	}
	if (iTmp == 0)
	{
		printf ("'WAS' coordinate system dictionary is empty.\n");
		Usage ();
	}

	iTmp = CS_csrd (isStrm,&isCsDef,&dummy);
	if (iTmp < 0)
	{
		CS_errmsg (errorText,sizeof (errorText));
		printf ("%s\n",errorText);
		Usage ();
	}
	if (iTmp == 0)
	{
		printf ("'IS' coordinate system dictionary is empty.\n");
		Usage ();
	}

	nlFlag = FALSE;
	while (TRUE)
	{
		cmpVal = CS_stricmp (wasCsDef.key_nm,isCsDef.key_nm);
		if (cmpVal < 0)
		{
			if (nlFlag)
			{
				printf ("\n");
				nlFlag = FALSE;
			}
			printf ("%s deleted from coordinate system dictionary!!!\n",wasCsDef.key_nm);
			csDiffCnt += 1;
		}
		else if (cmpVal > 0)
		{
			if (nlFlag)
			{
				printf ("\n");
				nlFlag = FALSE;
			}
			printf ("%s added to coordinate system dictionary!!!\n",isCsDef.key_nm);
			csDiffCnt += 1;
		}
		else
		{
			/* Normal case, we have two definitions with the same name, */
			iTmp = CS_csDiff (stdout,&wasCsDef,&isCsDef);
			if (iTmp != 0)
			{
				csDiffCnt += 1;
				nlFlag = TRUE;
			}
		}
		if (cmpVal >= 0)
		{
			iTmp = CS_csrd (isStrm,&isCsDef,&dummy);
			if (iTmp < 0)
			{
				CS_errmsg (errorText,sizeof (errorText));
				printf ("%s\n",errorText);
				Usage ();
			}
			if (iTmp == 0)
			{
				CS_fclose (isStrm);
				isStrm = NULL;
				break;
			}
		}
		if (cmpVal <= 0)
		{
			iTmp = CS_csrd (wasStrm,&wasCsDef,&dummy);
			if (iTmp < 0)
			{
				CS_errmsg (errorText,sizeof (errorText));
				printf ("%s\n",errorText);
				Usage ();
			}
			if (iTmp == 0)
			{
				CS_fclose (wasStrm);
				wasStrm = NULL;
				break;
			}
		}
	}

	/* Finish up properly. */
	nlFlag = TRUE;
	while (wasStrm != NULL)
	{
		iTmp = CS_csrd (wasStrm,&wasCsDef,&dummy);
		if (iTmp > 0)
		{
			if (nlFlag)
			{
				printf ("\n");
				nlFlag = FALSE;
			}
			printf ("%s deleted from coordinate system dictionary!!!\n",wasCsDef.key_nm);
			csDiffCnt += 1;
		}
		else if (iTmp == 0)
		{
			CS_fclose (wasStrm);
			wasStrm = NULL;
		}
		else
		{
			CS_errmsg (errorText,sizeof (errorText));
			printf ("%s\n",errorText);
			Usage ();
		}
	}
	while (isStrm != NULL)
	{
		iTmp = CS_csrd (isStrm,&wasCsDef,&dummy);
		if (iTmp > 0)
		{
			if (nlFlag)
			{
				printf ("\n");
				nlFlag = FALSE;
			}
			printf ("%s added to coordinate system dictionary!!!\n",isCsDef.key_nm);
			csDiffCnt += 1;
		}
		else if (iTmp == 0)
		{
			CS_fclose (isStrm);
			isStrm = NULL;
		}
		else
		{
			CS_errmsg (errorText,sizeof (errorText));
			printf ("%s\n",errorText);
			Usage ();
		}
	}
	if (csDiffCnt == 0)
	{
		printf ("\nCoordinate system dictionaries are the same.\n\n");
	}
	else
	{
		printf ("\n%d coordinate systems are different.\n\n",csDiffCnt);
	}

	/* Done with the coordinate system dictionary. Same as above, but with the
	   Datum Dictionary this time. */
	CS_altdr (wasDir);											/*lint !e534 */
	wasStrm = CS_dtopn (_STRM_BINRD);
	if (wasStrm == NULL)
	{
		printf ("Open of %s in the 'WAS' directory failed.\n",cs_Dtname);
		Usage ();
	}
	cs_DtStream = 0;

	CS_altdr (isDir);											/*lint !e534 */
	isStrm = CS_dtopn (_STRM_BINRD);
	if (isStrm == NULL)
	{
		printf ("Open of %s in the 'IS' directory failed.\n",cs_Dtname);
		Usage ();
	}
	cs_DtStream = 0;

	iTmp = CS_dtrd (wasStrm,&wasDtDef,&dummy);
	if (iTmp < 0)
	{
		CS_errmsg (errorText,sizeof (errorText));
		printf ("%s\n",errorText);
		Usage ();
	}
	if (iTmp == 0)
	{
		printf ("'WAS' datum dictionary is empty.\n");
		Usage ();
	}

	iTmp = CS_dtrd (isStrm,&isDtDef,&dummy);
	if (iTmp < 0)
	{
		CS_errmsg (errorText,sizeof (errorText));
		printf ("%s\n",errorText);
		Usage ();
	}
	if (iTmp == 0)
	{
		printf ("'IS' datum dictionary is empty.\n");
		Usage ();
	}

	nlFlag = FALSE;
	while (TRUE)
	{
		cmpVal = CS_stricmp (wasDtDef.key_nm,isDtDef.key_nm);
		if (cmpVal < 0)
		{
			if (nlFlag)
			{
				printf ("\n");
				nlFlag = FALSE;
			}
			printf ("%s deleted from datum dictionary!!!\n",wasDtDef.key_nm);
			dtDiffCnt += 1;
		}
		else if (cmpVal > 0)
		{
			if (nlFlag)
			{
				printf ("\n");
				nlFlag = FALSE;
			}
			printf ("%s added to datum dictionary!!!\n",isDtDef.key_nm);
			dtDiffCnt += 1;
		}
		else
		{
			/* Normal case, we have two definitions with the same name, */
			iTmp = CS_dtDiff (stdout,&wasDtDef,&isDtDef);
			if (iTmp != 0)
			{
				dtDiffCnt += 1;
				nlFlag = TRUE;
			}
		}
		if (cmpVal >= 0)
		{
			iTmp = CS_dtrd (isStrm,&isDtDef,&dummy);
			if (iTmp < 0)
			{
				CS_errmsg (errorText,sizeof (errorText));
				printf ("%s\n",errorText);
				Usage ();
			}
			if (iTmp == 0)
			{
				CS_fclose (isStrm);
				isStrm = NULL;
				break;
			}
		}
		if (cmpVal <= 0)
		{
			iTmp = CS_dtrd (wasStrm,&wasDtDef,&dummy);
			if (iTmp < 0)
			{
				CS_errmsg (errorText,sizeof (errorText));
				printf ("%s\n",errorText);
				Usage ();
			}
			if (iTmp == 0)
			{
				CS_fclose (wasStrm);
				wasStrm = NULL;
				break;
			}
		}
	}

	nlFlag = TRUE;
	while (wasStrm != NULL)
	{
		iTmp = CS_dtrd (wasStrm,&wasDtDef,&dummy);
		if (iTmp > 0)
		{
			if (nlFlag)
			{
				printf ("\n");
				nlFlag = FALSE;
			}
			printf ("%s deleted from datum dictionary!!!\n",wasDtDef.key_nm);
			dtDiffCnt += 1;
		}
		else if (iTmp == 0)
		{
			CS_fclose (wasStrm);
			wasStrm = NULL;
		}
		else
		{
			CS_errmsg (errorText,sizeof (errorText));
			printf ("%s\n",errorText);
			Usage ();
		}
	}
	while (isStrm != NULL)
	{
		iTmp = CS_dtrd (isStrm,&wasDtDef,&dummy);
		if (iTmp > 0)
		{
			if (nlFlag)
			{
				printf ("\n");
				nlFlag = FALSE;
			}
			printf ("%s added to datum dictionary!!!\n",isDtDef.key_nm);
			dtDiffCnt += 1;
		}
		else if (iTmp == 0)
		{
			CS_fclose (isStrm);
			isStrm = NULL;
		}
		else
		{
			CS_errmsg (errorText,sizeof (errorText));
			printf ("%s\n",errorText);
			Usage ();
		}
	}
	if (dtDiffCnt == 0)
	{
		printf ("\nDatum dictionaries are the same.\n\n");
	}
	else
	{
		printf ("\n%d datum definitions are different.\n\n",dtDiffCnt);
	}

	/* Ellipsoid Dictionary */
	CS_altdr (wasDir);											/*lint !e534 */
	wasStrm = CS_elopn (_STRM_BINRD);
	if (wasStrm == NULL)
	{
		printf ("Open of %s in the 'WAS' directory failed.\n",cs_Elname);
		Usage ();
	}
	cs_ElStream = 0;

	CS_altdr (isDir);											/*lint !e534 */
	isStrm = CS_elopn (_STRM_BINRD);
	if (isStrm == NULL)
	{
		printf ("Open of %s in the 'IS' directory failed.\n",cs_Elname);
		Usage ();
	}
	cs_ElStream = 0;

	iTmp = CS_elrd (wasStrm,&wasElDef,&dummy);
	if (iTmp < 0)
	{
		CS_errmsg (errorText,sizeof (errorText));
		printf ("%s\n",errorText);
		Usage ();
	}
	if (iTmp == 0)
	{
		printf ("'WAS' ellipsoid dictionary is empty.\n");
		Usage ();
	}

	iTmp = CS_elrd (isStrm,&isElDef,&dummy);
	if (iTmp < 0)
	{
		CS_errmsg (errorText,sizeof (errorText));
		printf ("%s\n",errorText);
		Usage ();
	}
	if (iTmp == 0)
	{
		printf ("'IS' ellipsoid dictionary is empty.\n");
		Usage ();
	}

	nlFlag = FALSE;
	while (TRUE)
	{
		cmpVal = CS_stricmp (wasElDef.key_nm,isElDef.key_nm);
		if (cmpVal < 0)
		{
			if (nlFlag)
			{
				printf ("\n");
				nlFlag = FALSE;
			}
			printf ("%s deleted from ellipsoid dictionary!!!\n",wasElDef.key_nm);
			elDiffCnt += 1;
		}
		else if (cmpVal > 0)
		{
			if (nlFlag)
			{
				printf ("\n");
				nlFlag = FALSE;
			}
			printf ("%s added to ellipsoid dictionary!!!\n",isElDef.key_nm);
			elDiffCnt += 1;
		}
		else
		{
			/* Normal case, we have two definitions with the same name, */
			iTmp = CS_elDiff (stdout,&wasElDef,&isElDef);
			if (iTmp != 0)
			{
				elDiffCnt += 1;
				nlFlag = TRUE;
			}
		}
		if (cmpVal >= 0)
		{
			iTmp = CS_elrd (isStrm,&isElDef,&dummy);
			if (iTmp < 0)
			{
				CS_errmsg (errorText,sizeof (errorText));
				printf ("%s\n",errorText);
				Usage ();
			}
			if (iTmp == 0)
			{
				CS_fclose (isStrm);
				isStrm = NULL;
				break;
			}
		}
		if (cmpVal <= 0)
		{
			iTmp = CS_elrd (wasStrm,&wasElDef,&dummy);
			if (iTmp < 0)
			{
				CS_errmsg (errorText,sizeof (errorText));
				printf ("%s\n",errorText);
				Usage ();
			}
			if (iTmp == 0)
			{
				CS_fclose (wasStrm);
				wasStrm = NULL;
				break;
			}
		}
	}

	nlFlag = TRUE;
	while (wasStrm != NULL)
	{
		iTmp = CS_elrd (wasStrm,&wasElDef,&dummy);
		if (iTmp > 0)
		{
			if (nlFlag)
			{
				printf ("\n");
				nlFlag = FALSE;
			}
			printf ("%s deleted from ellipsoid dictionary!!!\n",wasElDef.key_nm);
			elDiffCnt += 1;
		}
		else if (iTmp == 0)
		{
			CS_fclose (wasStrm);
			wasStrm = NULL;
		}
		else
		{
			CS_errmsg (errorText,sizeof (errorText));
			printf ("%s\n",errorText);
			Usage ();
		}
	}
	while (isStrm != NULL)
	{
		iTmp = CS_elrd (isStrm,&wasElDef,&dummy);
		if (iTmp > 0)
		{
			if (nlFlag)
			{
				printf ("\n");
				nlFlag = FALSE;
			}
			printf ("%s added to ellipsoid dictionary!!!\n",isElDef.key_nm);
			dtDiffCnt += 1;
		}
		else if (iTmp == 0)
		{
			CS_fclose (isStrm);
			isStrm = NULL;
		}
		else
		{
			CS_errmsg (errorText,sizeof (errorText));
			printf ("%s\n",errorText);
			Usage ();
		}
	}
	if (elDiffCnt == 0)
	{
		printf ("\nEllipsoid dictionaries are the same.\n\n");
	}
	else
	{
		printf ("\n%d ellipsoid definitions are different.\n\n",elDiffCnt);
	}

	return 0;
}
void Usage (void)
{
	printf ("Usage: DictDiff previous_directory new_directory\n");
	exit (1);
}
