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

			 File Name: $Source: C:/Development/NewCsMap/rcs/CS_gdcGenerator.c $
			 Full Name:	GDC GENERATOR function
		   Description:	Generates GDC files from existing directories.
			   Purpose:	Used in an attempt to reproduce the exact
						conditions of the previous release.
		Revision Level:	$Revision: #4 $
				  Date:	$Date: 2006/11/16 $

		 Last Revision:	$Log: CS_gdcGenerator.c $
		 Last Revision:	Revision 11.1300  2005/05/25 23:27:11  nto
		 Last Revision:	Official Release 11.13
		 Last Revision:	Revision 11.1200  2005/01/15 18:27:12  nto
		 Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		 Last Revision:	Revision 11.1100  2004/11/01 18:53:09  nto
		 Last Revision:	Official release 11.11
		 Last Revision:	Revision 11.1001  2004/10/07 19:25:17  nto
		 Last Revision:	Revision 11.900  2004/03/26 17:02:24  nto
		 Last Revision:	Official release: 11.09 - 3/25/2003
		 Last Revision:	Revision 11.800  2004/01/13 23:29:13  nto
		 Last Revision:	Revision 11.700  2003/12/19 01:49:53  nto
		 Last Revision:	Official release 11.07
		 Last Revision:	Revision 11.601  2003/12/19 01:05:27  nto
		 Last Revision:	Added DOT NET runtime compatibility.
		 Last Revision:	Revision 11.600  2003/12/04 02:46:28  nto
		 Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		 Last Revision:	Revision 11.501  2003/08/22 21:12:55  nto
		 Last Revision:	Official Release: 11.05
		 Last Revision:	Revision 11.401  2003/05/01 23:06:22  nto
		 Last Revision:	Revision 11.300  2003/02/25 04:29:16  nto
		 Last Revision:	Official Release 11.03
		 Last Revision:	Revision 11.100  2002/11/22 19:38:44  nto
		 Last Revision:	Official release: 11.01
		 Last Revision:	Revision 10.1503  2002/11/21 20:31:56  nto
		 Last Revision:	Lint cleanup.
		 Last Revision:	Revision 10.1502  2002/11/06 23:50:19  nto
		 Last Revision:	Adjusted to compile under various flavors of UNIX.
		 Last Revision:	Revision 10.1501  2002/10/06 18:07:02  nto
		 Last Revision:	Converted all direct references to 'access' to CS_access.
		 Last Revision:	Revision 10.1500  2002/09/22 00:01:20  nto
		 Last Revision:	Official Release:= 10.15
		 Last Revision:	Revision 10.1400  2002/08/09 18:14:22  nto
		 Last Revision:	Revision 10.1200  2002/07/14 03:26:16  nto
		 Last Revision:	Revision 10.1100  2002/06/13 14:18:37  nto
		 Last Revision:	Release 10.11 Official
		 Last Revision:	Revision 10.1000  2002/02/23 21:18:26  nto
		 Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		 Last Revision:	Revision 10.900  2001/09/24 04:31:11  nto
		 Last Revision:	Revision 10.700  2001/01/25 04:13:48  nto
		 Last Revision:	Revision 1.2  2001/01/25 04:04:27  nto
		 Last Revision:	Tested and it works now.
		 Last Revision:	Revision 1.1  2001/01/24 04:50:15  nto
		 Last Revision:	Initial Revision

		       * * * * R E M A R K S * * * *

	The order in which geodetic data files were searched previously was
	dependent upon their order in the actual data directory.  In order
	to reproduce this order in a new .GDC file, we need a module which
	will scan the directory in the physical order files appear on the
	disk, and build a .GDC file from such a scan.  This is that module.

******************************************************************************/


#include "cs_map.h"
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#if _RUN_TIME >= _rt_UNIXPCC
#	include <ftw.h>
#else
#	include <io.h>
#endif

#ifndef MAXPATH
#	define MAXPATH CSMAXPATH
#endif

#ifndef FTW_F
#	define FTW_F 0
#endif

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_gdcGenerator.c#4 $"};
#endif

/*
	The following integer is used to carry the value of the
	NADCON_USA environmental variable.  This variable should
	be set to whatever it was in the previous release in order
	for this module to regenerate the previous release
	conditions precisely.
*/
int cs_NadUSA = -1;

/*
	Now, for some code which actually does something.

	Note, directory must be the data directory without a trailing
	separator character.  The results are written to two data files
	in the provided directory.  The names of the two files are given
	by the cs_NadName and cs_HarnName external variables.
*/
static csFILE *csNadStream = NULL;
static csFILE *csHarnStream = NULL;
static char csLocalDirectory [MAXPATH];


int EXP_LVL9 CSgdcNadDra (Const char *fname,Const struct stat *stat_ptr,int parm);
int EXP_LVL9 CSgdcHarnDra (Const char *fname,Const struct stat *stat_ptr,int parm);

int EXP_LVL7 CSgdcGenerate (Const char *directory)
{
	extern char cs_NadName [];
	extern char cs_HarnName [];
	extern char cs_DirsepC;

	int st;

	char *cp;

	char lclPath [MAXPATH + MAXPATH];
#if _RUN_TIME < _rt_UNIXPCC
	char ctemp [MAXPATH + MAXPATH];
#endif

	/* Isolate a copy of directory withou a separator on the end. */
	cp = CS_stncp (csLocalDirectory,directory,sizeof (csLocalDirectory));
	if (*(cp - 1) == cs_DirsepC) *(cp - 1) = '\0';

	/* Manufacture path names for the two output files and create them. */
	cp = CS_stcpy (lclPath,csLocalDirectory);
	*cp++ = cs_DirsepC;
	cp = CS_stcpy (cp,cs_NadName);
	csNadStream = CS_fopen (lclPath,_STRM_TXTWR);
	if (csNadStream == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}

	/* Write the header portion of the file, some canned text. */
	CS_fputs ("#\n",csNadStream);
	CS_fputs ("# Each line points to a datum shift data file.  In the case of\n",csNadStream);
	CS_fputs ("# overlapping coverage, the program selects the data file with\n",csNadStream);
	CS_fputs ("# the smallest grid cell in the region of the conversion.  If\n",csNadStream);
	CS_fputs ("# the grid cell sizes are the same, the program selects the\n",csNadStream);
	CS_fputs ("# file which appears first in this file.  Check the Help\n",csNadStream);
	CS_fputs ("# file for more options.\n",csNadStream);
	CS_fputs ("#\n",csNadStream);
	CS_fputs ("# Order the list of files as appropriate for your application.\n",csNadStream);
	CS_fputs ("# You can add additional files as they become available.  While\n",csNadStream);
	CS_fputs ("# the name, letter case, and location of the file name is not\n",csNadStream);
	CS_fputs ("# important, the extension must be correct.  Use \"L?S\" as the\n",csNadStream);
	CS_fputs ("# extension for US NADCON files, use \".gsb\" if the file is in\n",csNadStream);
	CS_fputs ("# the Canadian National Transformation, Version 2 format.  Each\n",csNadStream);
	CS_fputs ("# line may be a full path name.  The \".\\\" sequence used here is\n",csNadStream);
	CS_fputs ("# a relative folder/directory reference, relative to the folder\n",csNadStream);
	CS_fputs ("# (directory) in which this file resides.\n",csNadStream);
	CS_fputs ("#\n",csNadStream);
	CS_fputs ("#    C A N A D A     S P E C I F I C   N O T E S\n",csNadStream);
	CS_fputs ("#\n",csNadStream);
	CS_fputs ("# Activate one or the other (V1 or V2), depending upon which file\n",csNadStream);
	CS_fputs ("# you have.  Do not activate both.  You will never know which one\n",csNadStream);
	CS_fputs ("# is actually used for a specific point.\n",csNadStream);
	CS_fputs ("#\n",csNadStream);

	/* Prepare to do the appropriate stuff for the density of the US and
	   Canadian files. */
	if (cs_NadUSA == -1)
	{
		cp = getenv ("NADCON_USA");
		if (cp == NULL) cs_NadUSA = 0;
		else		cs_NadUSA = atoi (cp);
	}

	/* OK, scan the directory and call the CSnaddra funtion once for
	   each file which meets the selected criteria.  On the first pass,
	   we do the NAD file. */
#if _RUN_TIME >= _rt_UNIXPCC
	{
		/* This is for UNIX.  Note, there is no filter in UNIX. */
		st = CS_ftw (csLocalDirectory,CSgdcNadDra,1);
		if (st != 0)
		{
			/* Here if something went wrong on the
			   scan. */
			goto error;
		}
	}
#elif _RUN_TIME == _rt_MSVC32 || _RUN_TIME == _rt_MSDOTNET
	/* NT is, conceptually, very similar to MS-DOS. The
	   function names and calling sequqences are slightly
	   different. */
	{
		int done;
		long fnd_hdl;
		
		struct _finddata_t fnd_cb;
		struct stat stat_buf; 
		
		cp = CS_stcpy (ctemp,csLocalDirectory);
		if (*(cp - 1) != cs_DirsepC)
		{
			*cp++ = cs_DirsepC;
			*cp = '\0';
		}

		/* This is the filter.  But since we're looking for *.L?S and .GSB, and .DAC,
		   we have to do it the hard way in the CSnaddra function. */
		CS_stcpy (cp,"*.*");
		fnd_hdl = _findfirst (ctemp,&fnd_cb);
		done = (fnd_hdl < 0);
		while (!done)
		{
			cp = CS_stcpy (lclPath,csLocalDirectory);
			*cp++ = cs_DirsepC;
			cp = CS_stcpy (cp,fnd_cb.name);
			st = stat (lclPath,&stat_buf);
			if (st == 0)
			{
				st = CSgdcNadDra (lclPath,&stat_buf,FTW_F);
				if (st != 0)
				{
					goto error;
				}
			}
			done = _findnext (fnd_hdl,&fnd_cb);
		}
	}
#else
	/* Under MS_DOS, we need to use the findfirst and
	   findnext functions as one cannot open a directory
	   file directly. */
	{
		int done;
		struct find_t fnd_cb;
		struct stat stat_buf;

		cp = CS_stcpy (ctemp,csLocalDirectory);
		if (*(cp - 1) != cs_DirsepC)
		{
			*cp++ = cs_DirsepC;
			*cp = '\0';
		}
		CS_stcpy (cp,"*.*");
		done = _dos_findfirst (ctemp,_A_NORMAL,&fnd_cb);
		while (!done)
		{
			cp = CS_stcpy (lclPath,csLocalDirectory);
			*cp++ = cs_DirsepC;
			cp = CS_stcpy (cp,fnd_cb.name);
			st = stat (lclPath,&stat_buf);
			if (st == 0)
			{
				st = CSgdcNadDra (lclPath,&stat_buf,FTW_F);
				if (st != 0)
				{
					goto error;
				}
			}
			done = _dos_findnext (&fnd_cb);
		}
	}
#endif

	/* OK, should be done with the NAD file.  Close er up and on to HARN. */
	CS_fclose (csNadStream);
	csNadStream = NULL;


	/* Similarly with the HARN file. */
	cp = CS_stcpy (lclPath,csLocalDirectory);
	*cp++ = cs_DirsepC;
	cp = CS_stcpy (cp,cs_HarnName);
	csHarnStream = CS_fopen (lclPath,_STRM_TXTWR);
	if (csHarnStream == NULL)
	{
		CS_erpt (cs_NO_MEM);
		goto error;
	}

	/* Output the canned text that goes with the HARN file. */
	CS_fputs ("#\n",csHarnStream);
	CS_fputs ("# Each line points to a datum shift data file.  In the case of\n",csHarnStream);
	CS_fputs ("# overlapping coverage, the program selects the data file with\n",csHarnStream);
	CS_fputs ("# the smallest grid cell in the region of the conversion.  If\n",csHarnStream);
	CS_fputs ("# the grid cell sizes are the same, the program selects the\n",csHarnStream);
	CS_fputs ("# file which appears first in this file.  Check the Help\n",csHarnStream);
	CS_fputs ("# file for more options.\n",csHarnStream);
	CS_fputs ("#\n",csHarnStream);
	CS_fputs ("# Order the list of files as appropriate for your application.\n",csHarnStream);
	CS_fputs ("# You can add additional files as they become available.  While\n",csHarnStream);
	CS_fputs ("# the name, letter case, and location of the file name is not\n",csHarnStream);
	CS_fputs ("# importantant, the extension must be correct.  Use \"l?s\" for\n",csHarnStream);
	CS_fputs ("# US NADCON files.  Use \".gsb\" if the file is in the Canadian\n",csHarnStream);
	CS_fputs ("# National Transformation, Version 2 format.  Each line may be\n",csHarnStream);
	CS_fputs ("# a full path name.  The \".\\\" sequence, when used here, is\n",csHarnStream);
	CS_fputs ("# a relative folder/directory reference, relative to the folder\n",csHarnStream);
	CS_fputs ("# (directory) in which this file resides.\n",csHarnStream);
	CS_fputs ("#\n",csHarnStream);
	CS_fputs ("# Deleteing, or commenting out, references to files that\n",csHarnStream);
	CS_fputs ("# you are unlikely to use may improve performance slightly.\n",csHarnStream);
	CS_fputs ("#\n",csHarnStream);
	CS_fputs ("# Note that the files can be in any directory.\n",csHarnStream);
	CS_fputs ("#\n",csHarnStream);

	/* OK, scan the directory and call the CSharndra funtion once for
	   each file which meets the selected criteria. */
#if _RUN_TIME >= _rt_UNIXPCC
	{
		/* This is for UNIX.  Note, there is no filter in UNIX. */
		st = CS_ftw (csLocalDirectory,CSgdcHarnDra,1);
		if (st != 0)
		{
			/* Here if something went wrong on the
			   scan. */
			goto error;
		}
	}
#elif _RUN_TIME == _rt_MSVC32 || _RUN_TIME == _rt_MSDOTNET
	/* NT is, conceptually, very similar to MS-DOS. The
	   function names and calling sequqences are slightly
	   different. */
	{
		int done;
		long fnd_hdl;
		
		struct _finddata_t fnd_cb;
		struct stat stat_buf; 
		
		cp = CS_stcpy (ctemp,csLocalDirectory);
		if (*(cp - 1) != cs_DirsepC)
		{
			*cp++ = cs_DirsepC;
			*cp = '\0';
		}
		CS_stcpy (cp,"??hpgn.*");
		fnd_hdl = _findfirst (ctemp,&fnd_cb);
		done = (fnd_hdl < 0);
		while (!done)
		{
			cp = CS_stcpy (lclPath,csLocalDirectory);
			*cp++ = cs_DirsepC;
			cp = CS_stcpy (cp,fnd_cb.name);
			st = stat (lclPath,&stat_buf);
			if (st == 0)
			{
				st = CSgdcHarnDra (lclPath,&stat_buf,FTW_F);
				if (st != 0)
				{
					goto error;
				}
			}
			done = _findnext (fnd_hdl,&fnd_cb);
		}
	}
#else
	/* Under MS_DOS, we need to use the findfirst and
	   findnext functions as one cannot open a directory
	   file directly. */
	{
		int done;
		struct find_t fnd_cb;
		struct stat stat_buf;

		cp CS_stcpy (ctemp,csLocalDirectory);
		if (*(cp - 1) != cs_DirsepC)
		{
			*cp++ = cs_DirsepC;
			*cp = '\0';
		}
		CS_stcpy (cp,"??hpgn.*");
		done = _dos_findfirst (ctemp,_A_NORMAL,&fnd_cb);
		while (!done)
		{
			cp = CS_stcpy (lclPath,csLocalDirectory);
			*cp++ = cs-SirsepC;
			cp = CS_stcpy (cp,fnd_cb.name);
			st = stat (lclPath,&stat_buf);
			if (st == 0)
			{
				st = CSgdcHarnDra (lclPath,&stat_buf,FTW_F);
				if (st != 0)
				{
					goto error;
				}
			}
			done = _dos_findnext (&fnd_cb);
		}
	}
#endif
	CS_fclose (csHarnStream);
	csHarnStream = NULL;
	return 0;

error:
	if (csNadStream != NULL)
	{
		CS_fclose (csNadStream);
		csNadStream = NULL;
		cp = CS_stcpy (lclPath,csLocalDirectory);
		*cp++ = cs_DirsepC;
		cp = CS_stcpy (cp,cs_NadName);
		CS_remove (lclPath);									/*lint !e534 */
	}
	if (csHarnStream != NULL)
	{
		CS_fclose (csHarnStream);
		csHarnStream = NULL;
		cp = CS_stcpy (lclPath,csLocalDirectory);
		*cp++ = cs_DirsepC;
		cp = CS_stcpy (cp,cs_HarnName);
		CS_remove (lclPath);									/*lint !e534 */
	}
	return -1;
}
/*
	The following function is called by the directory scan
	functions for all files on the scan for the NAD file.  It
	examines the name passed to it and determines what to do
	with it.
*/
int EXP_LVL9 CSgdcNadDra (Const char *fname,Const struct stat *stat_ptr,int parm)
{
	extern char cs_DirsepC;
	extern char cs_ExtsepC;

	int dir_len;

	char *cp;
	csFILE* cntStream;

	char path [MAXPATH];
	char name [cs_FNM_MAXLEN];
	char ext [8];
	char ctemp [MAXPATH + cs_FNM_MAXLEN + 12];

	struct csGridFileCa2HdrCA cnt2_hdr;

	/* If the given file is not an ordinary file, we ignore the entry. */
	if (parm != FTW_F || 
	    (stat_ptr != NULL && ((stat_ptr->st_mode & S_IFMT) != S_IFREG))
	   )
	{
		return (FALSE);
	}

	/* Separate the name into the components we need.  First we get the extension. */
	CS_stncp (path,fname,sizeof (path));
	cp = strrchr (path,cs_ExtsepC);
	if (cp == NULL)
	{
		ext [0] = '\0';
	}
	else
	{
		*cp++ = '\0';
		CS_stncp (ext,cp,sizeof (ext));
	}

	/* Now for the base file name.  Path will carry the directory path to the file
	   as a result of extracting the name. */
	cp = strrchr (path,cs_DirsepC);
	if (cp == NULL)
	{
		CS_stncp (name,path,sizeof (name));
		path [0] = '\0';
	}
	else
	{
		*cp++ = '\0';
		CS_stncp (name,cp,sizeof (name));
	}
	dir_len = strlen (path);

	/* Make sure the file is in the expected directory.  This is
	   only necessary under UNIX.  In the NT/95 case, the directory
	   portion is actually a copy of what we started with (i.e. not
	   generated by findfirst).  Therefore, a case sensitive compare
	   should be OK. */
	if (strncmp (path,csLocalDirectory,dir_len))
	{
		/* Nope, this isn't the directory we started
		   in, ignore this entry. */
		return (FALSE);
	}

	/* Check the extension. */
	if (!CS_stricmp (ext,cs_NADCON_LOS))
	{
		/* This could be a US NADCON file.  Make sure it's
		   not an HPGN file, then make sure it has a companion
		   file. Note, there is no ANSI version of a case
		   insensitive strstr function, so we have provided
		   our own. */
		if (CS_stristr (name,cs_HPGN_TAG) != NULL)
		{
			/* It's an HPGN/HARN file.  Ignore it. */
			return (FALSE);
		}

		if (path [0] != '\0')
		{
			cp = CS_stcpy (ctemp,path);
			*cp++ = cs_DirsepC;
		}
		else
		{
			cp = ctemp;
		}
		cp = CS_stcpy (cp,name);
		*cp++ = cs_ExtsepC;
		CS_stcpy (cp,cs_NADCON_LAS);
		if (CS_access (ctemp,0))
		{
			/* No companion file there, skip this one. */
			return (FALSE);
		}

		/* The companion file is there, process this file as a US file NADCON file. */
		CS_fprintf (csNadStream,"%s%c%s.L?S\n",path,cs_DirsepC,name);
	}
	else if (!CS_stricmp (ext,cs_CANNT_DAC))
	{
		/* We assume this is a Canadian, Version 1 file, for now. */
		if (cs_NadUSA)
		{
			CS_fprintf (csNadStream,"%s%c%s.%s,,,1.0\n",path,cs_DirsepC,name,cs_CANNT_DAC);
		}
		else
		{
			CS_fprintf (csNadStream,"%s%c%s.%s\n",path,cs_DirsepC,name,cs_CANNT_DAC);
		}
	}
	else if (!CS_stricmp (ext,cs_CANNT_GSB))
	{
		/* Need to p[en up a file of this type and extract the longitude.
		   This desirable as we don't want to include, say, Australian
		   data files in this catalog. */
		cntStream = CS_fopen (fname,_STRM_BINRD);
		if (cntStream == NULL)
		{
			/* If we can't open it, we ignore it. */
			return (FALSE);
		}
		CS_fread (&cnt2_hdr,1,sizeof (cnt2_hdr),cntStream);		/*lint !e534 */
		CS_fclose (cntStream);

		/* Make sure we swap bytes before we use any data. */
		CS_bswap (&cnt2_hdr,cs_BSWP_GridFileCa2HdrCA);

		/* Now if the from and to datums indicate that this is a NAD (i.e. North
		   American Datum) file (as opposed to Australia/New Zealand).  Note, this
		   test will fail because of the alignment in the case of an Australian
		   file also. */
		if (!CS_strnicmp (cnt2_hdr.datum_f,"NAD27 ",6) &&
		    !CS_strnicmp (cnt2_hdr.datum_t,"NAD83 ",6))
		{
			/* Looks like a version 2 Canadian (geography) file. */
			if (cs_NadUSA)
			{
				CS_fprintf (csNadStream,"%s%c%s.%s,,,1.0\n",path,cs_DirsepC,name,cs_CANNT_GSB);
			}
			else
			{
				CS_fprintf (csNadStream,"%s%c%s.%s\n",path,cs_DirsepC,name,cs_CANNT_GSB);
			}
		}
	}
	else
	{
		/* Otherwise, we're not interested. */
		return (FALSE);
	}
	return (FALSE);
}
/*
	The following function is called by the directory scan
	functions for all files on the scan for the HARN file.  It
	examines the name passed to it and determines what to do
	with it.
*/
int EXP_LVL9 CSgdcHarnDra (Const char *fname,Const struct stat *stat_ptr,int parm)
{
	extern char cs_DirsepC;
	extern char cs_ExtsepC;

	int dir_len;

	char *cp;

	char path [MAXPATH];
	char name [cs_FNM_MAXLEN];
	char ext [8];
	char ctemp [MAXPATH + cs_FNM_MAXLEN + 12];

	/* If the given file is not an ordinary file, we ignore the entry. */
	if (parm != FTW_F ||
	    (stat_ptr != NULL && ((stat_ptr->st_mode & S_IFMT) != S_IFREG))
	   )
	{
		return (FALSE);
	}

	/* Separate the name into the components we need.  First we get the extension. */
	CS_stncp (path,fname,sizeof (path));
	cp = strrchr (path,cs_ExtsepC);
	if (cp == NULL)
	{
		ext [0] = '\0';
	}
	else
	{
		*cp++ = '\0';
		CS_stncp (ext,cp,sizeof (ext));
	}

	/* Now for the base file name.  Path will carry the directory path to the file
	   as a result of extracting the name. */
	cp = strrchr (path,cs_DirsepC);
	if (cp == NULL)
	{
		CS_stncp (name,path,sizeof (name));
		path [0] = '\0';
	}
	else
	{
		*cp++ = '\0';
		CS_stncp (name,cp,sizeof (name));
	}
	dir_len = strlen (path);

	/* Make sure the file is in the expected directory.  This is
	   only necessary under UNIX.  In the NT/95 case, the directory
	   portion is actually a copy of what we started with (i.e. not
	   generated by findfirst).  Therefore, a case sensitive compare
	   should be OK. */
	if (strncmp (path,csLocalDirectory,dir_len))
	{
		/* Nope, this isn't the directory we started
		   in, ignore this entry. */
		return (FALSE);
	}

	/* Check the extension.  We're only interested in .LOS files now. */
	if (CS_stricmp (ext,cs_NADCON_LOS))
	{
		/* Not an .LOS file; we're not interested. */
		return (FALSE);
	}

	/* Make sure it is an HPGN/HARN file. */
	if (CS_stristr (name,cs_HPGN_TAG) == NULL)
	{
		/* It's not an HPGN/HARN file.  Ignore it. */
		return (FALSE);
	}

	/* OK, its a HPGN/HARN file.  Make sure the companion file exists. */
	if (path [0] != '\0')
	{
		cp = CS_stcpy (ctemp,path);
		*cp++ = cs_DirsepC;
	}
	else
	{
		cp = ctemp;
	}
	cp = CS_stcpy (cp,name);
	*cp++ = cs_ExtsepC;
	CS_stcpy (cp,cs_NADCON_LAS);
	if (CS_access (ctemp,0))
	{
		/* No companion file there, skip this one. */
		return (FALSE);
	}

	/* The companion file is there, process this file as a HARN file. */
	CS_fprintf (csHarnStream,"%s%c%s.L?S\n",path,cs_DirsepC,name);
	return (FALSE);
}

