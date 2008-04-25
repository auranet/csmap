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

			 File Name: $RCSfile: CS_elio.c $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #7 $
		 Check In Date:	$Date: 2006/11/27 $

		Last Revision:	$Log: CS_elio.c $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:10  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:11  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1100  2004/11/01 18:53:08  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:17  nto
		Last Revision:	Revision 11.901  2004/08/07 20:52:04  nto
		Last Revision:	Added the dictionary deferred close feature.
		Last Revision:	Revision 11.900  2004/03/26 17:02:24  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:12  nto
		Last Revision:	Revision 11.700  2003/12/19 01:49:52  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.600  2003/12/04 02:46:27  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 11.501  2003/08/22 21:12:55  nto
		Last Revision:	Official Release: 11.05
		Last Revision:	Revision 11.401  2003/05/01 23:06:21  nto
		Last Revision:	Revision 11.300  2003/02/25 04:29:16  nto
		Last Revision:	Official Release 11.03
		Last Revision:	Revision 11.100  2002/11/22 19:38:43  nto
		Last Revision:	Official release: 11.01
		Last Revision:	Revision 10.1505  2002/10/13 00:35:28  nto
		Last Revision:	Fixed a typo which prevented compilation.
		Last Revision:	Revision 10.1504  2002/10/13 00:22:42  nto
		Last Revision:	Added synchronizing seeks before reads and writes.  Also cleaned up some lint items.
		Last Revision:	Revision 10.1503  2002/10/06 22:23:04  nto
		Last Revision:	Fixed to be usuable under Windows CE (the 'time' function).
		Last Revision:	Revision 10.1502  2002/10/06 17:50:54  nto
		Last Revision:	Replaced 'time' system calls with CS_time to accomodate Windows CE compilation.
		Last Revision:	Revision 10.1501  2002/10/01 16:58:57  nto
		Last Revision:	Switched old UNIX I/O to ANSI standard stream I/O.
		Last Revision:	Revision 10.1500  2002/09/22 00:01:19  nto
		Last Revision:	Official Release:= 10.15
		Last Revision:	Revision 10.1400  2002/08/09 18:14:22  nto
		Last Revision:	Revision 10.1200  2002/07/14 03:26:15  nto
		Last Revision:	Revision 10.1100  2002/06/13 14:18:37  nto
		Last Revision:	Release 10.11 Official
		Last Revision:	Revision 10.1000  2002/02/23 21:18:26  nto
		Last Revision:	Official Release of 10.10, 2/22/02 - Norm Olsen
		Last Revision:	Revision 10.900  2001/09/24 04:31:10  nto
		Last Revision:	Revision 10.700  2001/01/25 04:13:47  nto
		Last Revision:	Revision 10.601  2001/01/25 00:18:53  nto
		Last Revision:	Added code to correctly handle the MSI protection system.
		Last Revision:	Revision 10.600  2000/12/11 06:39:42  nto
		Last Revision:	Release 10.06
		Last Revision:	Revision 10.501  2000/12/11 05:22:51  nto
		Last Revision:	Added the CS-MAP DLL protection scheme.
		Last Revision:	Revision 10.500  2000/10/27 07:38:19  nto
		Last Revision:	Official Release 10.05
		Last Revision:	Revision 10.401  2000/10/27 03:50:27  nto
		Last Revision:	Removed the attempt to export the hook function pointer variables.
		Last Revision:	Revision 10.400  2000/09/13 01:16:54  nto
		Last Revision:	Release 10.04
		Last Revision:	Revision 10.300  2000/04/04 23:18:25  nto
		Last Revision:	Revision 10.200  2000/03/02 18:51:16  nto
		Last Revision:	Revision 10.1  2000/01/30 23:36:05  nto
		Last Revision:	Added hook function for temporary ellipsoid definitions.  Also, reworked some code as suggested by PCLint.
		Last Revision:	Revision 10.0  1999/10/05 18:27:13  nto
		Last Revision:	Revision 9.99  1999/10/05 17:36:24  nto
		Last Revision:	Revision 1.2  1999/09/06 17:07:26  nto
		Last Revision:	This revision compiles, links, and generates a successful test program.

******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/CS_elio.c#7 $"};
#endif

#include "cs_map.h"

extern csFILE* cs_ElStream;
extern short cs_ElStrmFlg;

/**********************************************************************
 Hook function to support the use of temporary ellipsoid definitions.

 To activate, set the global CS_usrElDefPtr variable to point to your
 function.  To deactivate, set CS_usrElDefPtr to NULL.
 
 CS_eldef calls the (*CS_usrElDefPtr) function before it does anything
 with the name.  Thus, temporary names need not adhere to any CS-MAP
 convention regarding key names.

 (*CS_usrElDefPtr) should return:
 -1 to indicate an error of sorts, in which case the error condition
    must have already been reported to CS_erpt.
 +1 to indicate that normal CS_eldef processing is to be performed.
  0 to indicate that the cs_Eldef_ structure provided by the first
    argument has been properly filled in with the desired definition
	which is to be returned by CS_eldef.

 In the case where (*CS_usrElDefPtr) returns 0, CS_eldef will return
 a copy of the data provided in a chunk of memory it malloc'ed from
 the heap.  Also note, that the data returned is not checked.  You
 are responsible for making sure this data is valid.
**********************************************************************/
extern int (*CS_usrElDefPtr) (struct cs_Eldef_ *elDef,Const char *keyName);

/**********************************************************************
**    Calling Sequence:	strm = CS_elopn (mode);
**
**	int mode;					mode of the file open, ala fcntl.h
**	csFILE *strm;				returns a file descriptor to the open file.
**
**	Will return NULL if a problem was encountered.
**
**	File is positioned past the magic number on the front.
**********************************************************************/
csFILE * EXP_LVL3 CS_elopn (Const char *mode)
{
	extern char cs_Dir [];
	extern char *cs_DirP;
	extern char cs_Elname [];
	extern char csErrnam [];

	size_t rdCnt;

	csFILE *strm = NULL;

	cs_magic_t magic;

	if (cs_ElStream != 0)
	{
		if (!CS_stricmp (mode,_STRM_BINRD))
		{
			strm = cs_ElStream;
			CS_fseek (strm,(long)sizeof (magic),SEEK_SET);
		}
		else
		{
			CS_fclose (cs_ElStream);
			cs_ElStream = NULL;
		}
	}
	if (strm == NULL)
	{
		strcpy (cs_DirP,cs_Elname);
		strm = CS_fopen (cs_Dir,mode);
		if (strm != NULL)
		{
			rdCnt = CS_fread ((char *)&magic,1,sizeof (magic),strm);
			if (rdCnt != sizeof (magic))
			{
				if (CS_ferror (strm)) CS_erpt (cs_IOERR);
				else                  CS_erpt (cs_INV_FILE);
				CS_fclose (strm);
				strm = NULL;
				strcpy (csErrnam,cs_Dir);
			}
			else
			{ 
				CS_bswap (&magic,"l");
				if (magic != cs_ELDEF_MAGIC)
				{
					CS_fclose (strm);
					strm = NULL;
					strcpy (csErrnam,cs_Dir);
					CS_erpt (cs_EL_BAD_MAGIC);
				}
				else if (!strcmp (mode,_STRM_BINRD))
				{
					cs_ElStream = strm;
				}
			}
		}
		else
		{
			strcpy (csErrnam,cs_Dir);
			CS_erpt (cs_ELDICT);
		}
	}
	return (strm);
}

/**********************************************************************
**	void CS_elDictCls (csFILE* stream);
**
**	csFILE *strm;			stream to be closed.
**
** The stream is closed.  If the stream is that to which cs_ElStream
** points, cs_ElStream is set to the NULL pointer.
**********************************************************************/

void CS_elDictCls (csFILE* stream)
{
	if (stream == cs_ElStream)
	{
		cs_ElStream = NULL;
	}
	CS_fclose (stream);
}

/**********************************************************************
**	flag = CS_elrd (strm,el_def,crypt);
**
**	csFILE strm;				file/device from which the possibly enrypted
**								ellipsoid definition is to be read.
**	struct cs_Eldef_ *el_def;	decoded ellipsoid definition is returned here.
**	int *crypt;					if the entry read was encrypted, a TRUE
**								value is returned here, else this variable is
**								set to FALSE.
**	int flag;					returns +1 for successful read, 0 for EOF,
**								-1 for error.
**
**********************************************************************/
int EXP_LVL3 CS_elrd (csFILE *strm,struct cs_Eldef_ *el_def,int *crypt)
{
	cs_Register unsigned char key;
	cs_Register unsigned char *cp;

	int st;
	size_t rdCnt;

	unsigned char *cpe;

	char tmpKeyName [cs_KEYNM_DEF];

	/* Synchronize the strm before the read. */
	st = CS_fseek (strm,0L,SEEK_CUR);
	if (st != 0)
	{
		CS_erpt (cs_IOERR);
		return (-1);
	}

	/* OK, now we can read. */
	cp = (unsigned char *)el_def;
	rdCnt = CS_fread ((char *)el_def,1,sizeof (*el_def),strm);
	if (rdCnt != sizeof (*el_def))
	{
		if (CS_feof (strm))
		{
			return 0;
		}
		if (CS_ferror (strm)) CS_erpt (cs_IOERR);
		else				  CS_erpt (cs_INV_FILE);
		return (-1);
	}

	/* Do the encryption thing. */
	key = (unsigned char)el_def->fill [0];
	if (key != '\0')
	{
		*crypt = TRUE;
		cpe = cp + sizeof (*el_def);
		while (cp < cpe)
		{
			key ^= *cp;
			*cp++ = key;
		}
	}
	else
	{
		*crypt = FALSE;
	}

	/* Swap the bytes if necessary. */
	CS_bswap (el_def,cs_BSWP_ELDEF);

	/* Check the result. The name must always meet the criteria
	   set by the CS_nmpp function.  At least so far, the criteria
	   established by CS_nampp over the years has always been
	   expanded, never restricted.  Thus, any definition which
	   was legitimate in a previous release would always be
	   legitimate iin subsequent releases. */
	CS_stncp (tmpKeyName,el_def->key_nm,sizeof (tmpKeyName));
	if (CS_nampp (tmpKeyName) != 0)
	{
		/* Replace the error condition reported by CS_nampp with
		   and Invalid File indication. */
		CS_erpt (cs_INV_FILE);
		return (-1);
	}

	/* Reset the encryption indicator in the record itself. */
	el_def->fill [0] = '\0';
	return (1);
}

/**********************************************************************
**	st = CS_elwr (strm,el_def,crypt);
**
**	csFILE *strm;				file/device to which the possibly enrypted
**								ellipsoid definition is to be written.
**	struct cs_Eldef_ *el_def;	the unencrypted Ellipsoid definition which is
**								to be written.
**	int crypt;					TRUE says that the definition is to be encoded
**								before writting, FALSE says no encoding.
**	int st;						returns FALSE if write was completed successfully,
**								else returns TRUE.
**
**********************************************************************/


int EXP_LVL3 CS_elwr (csFILE *strm,Const struct cs_Eldef_ *el_def,int crypt)
{
	cs_Register unsigned char key;
	cs_Register unsigned char *cp;

	static unsigned seed = 0;

	int st;
	size_t wrCnt;
	unsigned char *cpe;

 	__ALIGNMENT__1		/* For some versions of Sun compiler. */
	struct cs_Eldef_ lcl_el;

	/* Get a copy which we can modify without screwing up the
	   calling module. */
	memcpy ((char *)&lcl_el,(char *)el_def,sizeof (lcl_el));

	/* Need to swap before encryption. */
	CS_bswap (&lcl_el,cs_BSWP_ELDEF);

	/* Now encrypt if requeested. */
	if (crypt)
	{
		if (seed == 0)
		{
			seed = (unsigned)CS_time ((cs_Time_ *)0);
			srand (seed);
		}
		while (TRUE)
		{
			key = (unsigned char)rand ();
			cpe = (unsigned char *)&lcl_el;
			cp = cpe + sizeof (lcl_el);
			lcl_el.fill [0] = (char)key;
			lcl_el.fill [1] = (char)rand ();
			while (--cp > cpe)
			{
				*cp ^= *(cp - 1);
			}
			*cp ^= (unsigned char)lcl_el.fill [0];

			if (lcl_el.fill [0] != '\0') break;

			/* Opps!!! The key turned out to be zero.
			   This would indicate that it is not
			   encrypted.  Need to try another key.

			   Need to restore the original contents,
			   otherwise we will be encrypting
			   encrypted data. */
			memcpy ((char *)&lcl_el,(char *)el_def,sizeof (lcl_el));
			CS_bswap (&lcl_el,cs_BSWP_ELDEF);
		}
	}
	else
	{
		/* If no encryption, set code to
		   zero.  This effectively turns
		   encryption off. */
		lcl_el.fill [0] = '\0';
		lcl_el.fill [1] = '\0';
	}

	/* Synchronize the stream prior to the write. */
	st = CS_fseek (strm,0L,SEEK_CUR);
	if (st != 0)
	{
		CS_erpt (cs_IOERR);
		return TRUE;		
	}

	/* Now we can write. */
	wrCnt = CS_fwrite ((char *)&lcl_el,1,sizeof (lcl_el),strm);
	if (wrCnt != sizeof (lcl_el))
	{
		if (CS_ferror (strm)) CS_erpt (cs_IOERR);
		else				  CS_erpt (cs_DISK_FULL);
		return (TRUE);
	}
	return (FALSE);
}

/**********************************************************************
**	st = CS_eldel (eldef);
**
**	struct cs_Eldef_ *eldef;	a pointer to the ellipsoid definition
**								structure which is to be deleted from the
**								Ellipsoid Dictionary.
**	int st;						returns a zero if the delete was successfully
**								completed, else returns -1.
**
**********************************************************************/

int EXP_LVL3 CS_eldel (struct cs_Eldef_ *eldef)
{
	extern char csErrnam [];
	extern char cs_Dir [];
	extern short cs_Protect;

	short cs_time;

	int st;
	int crypt;
	int rdSt;
	size_t wrCnt;

	csFILE *old_strm;
	csFILE *new_strm;

	cs_magic_t magic;

	struct cs_Eldef_ *my_ptr;

	char tmp_nam [MAXPATH];
 
 	__ALIGNMENT__1		/* For some versions of Sun compiler. */
	struct cs_Eldef_ cpy_buf;

	/* Capture the current time. */
	cs_time = (short)((CS_time ((cs_Time_ *)0) - 630720000L) / 86400L);

	/* Prepare for an error. */
	new_strm = NULL;
	old_strm = NULL;
	my_ptr = NULL;

	/* Adjust the name and make sure it is all upper case.
	   By convention, ellipsoid names are case insensitive. */
	st = CS_nampp (eldef->key_nm);
	if (st != 0) goto error;

	/* Get a pointer to the existing definition. If it doesn't
	   exist, we're all done. */
	my_ptr = CS_eldef (eldef->key_nm);
	if (my_ptr == NULL)
	{
		goto error;
	}

	/* See if this definition is protected.  If so, we have to
	   leave it alone. If cs_Protect < 0, there is no protection. */
	if (cs_Protect >= 0)
	{
		if (my_ptr->protect == 1)
		{
			CS_stncp (csErrnam,my_ptr->key_nm,MAXPATH);
			CS_erpt (cs_EL_PROT);
			goto error;
		}
		if (cs_Protect > 0)
		{
			/* Here if user definition protection is
			   enabled. */
			if (my_ptr->protect < (cs_time - cs_Protect))
			{
				CS_stncp (csErrnam,my_ptr->key_nm,MAXPATH);
				CS_erpt (cs_EL_UPROT);
				goto error;
			}
		}
	}
	CS_free (my_ptr);
	my_ptr = NULL;

	/* Make sure the entry we have been provided is marked as
	   unencrypted so that the compariosn functions will work. */
	eldef->fill [0] = '\0';

	/* Open up the ellipsoid dictionary file and verify its
	   magic number. */
	old_strm = CS_elopn (_STRM_BINRD);
	if (old_strm == NULL)
	{
		goto error;
	}

	/* Create a temporary file for the new dictionary. */
	st = CS_tmpfn (tmp_nam);
	if (st != 0)
	{
		goto error;
	}
	new_strm = CS_fopen (tmp_nam,_STRM_BINWR);
	if (new_strm == NULL)
	{
		CS_erpt (cs_TMP_CRT);
		goto error;
	}

	/* Copy the file, skipping the entry to be deleted.  First
	   we must write the magic number. */
	magic = cs_ELDEF_MAGIC;
	CS_bswap (&magic,"l");
	wrCnt = CS_fwrite ((char *)&magic,1,sizeof (magic),new_strm);
	if (wrCnt != sizeof (magic))
	{
		if (CS_ferror (new_strm)) CS_erpt (cs_IOERR);
		else					  CS_erpt (cs_DISK_FULL);
		goto error;
	}

	/* Now we copy the file, skipping the entry to be
	   deleted.  If the entry we just read was encrypted,
	   we encrypt it when we write it out. */
	while ((rdSt = CS_elrd (old_strm,&cpy_buf,&crypt)) > 0)
	{
		if (CS_elcmp (&cpy_buf,eldef) != 0)
		{
			if (CS_elwr (new_strm,&cpy_buf,crypt))
			{
				goto error;
			}
		}
	}

	/* See if the copy loop terminated due to an error. */
	if (rdSt != 0) goto error;

	/* Close up, remove the old dictionary and rename the
	   new dictionary. */
	CS_fclose (new_strm);
	new_strm = NULL;
	CS_elDictCls (old_strm);
	old_strm = NULL;
	st = CS_remove (cs_Dir);
	if (st != 0)
	{
		strcpy (csErrnam,cs_Dir);
		CS_erpt (cs_UNLINK);
		goto error;
	}
	st = CS_rename (tmp_nam,cs_Dir);
	if (st != 0) goto error;

	/* We're done. */
	return (0);

error:
	if (new_strm != NULL)
	{
		/* tmp_nam must have been initialize if new_fd >= 0 */
		CS_fclose (new_strm);
		CS_remove (tmp_nam);						/*lint !e534 !e645 */
	}
	if (old_strm != NULL) CS_elDictCls (old_strm);
	if (my_ptr != NULL) CS_free (my_ptr);
	return (-1);
}

/**********************************************************************
**	flag = CS_elupd (eldef,crypt);
**
**	struct cs_Eldef_ *eldef;	a pointer to the ellipsoid definition structure which
**								is to be written to the Ellipsoid Dictionary.
**	int crypt;					if TRUE, the ellipsoid entry is encrypted
**								before it is written.
**	int flag;					returns TRUE if the indicated ellipsoid previously
**								existed and was simply updated, returns FALSE if the
**								ellipsoid had to be added as a new ellipsoid, returns
**								-1 if the update process failed.
**
**	If the Ellipsoid Dictionary does not already contain an entry
**	with the indicated key name, the entry is added.
**********************************************************************/
int EXP_LVL3 CS_elupd (struct cs_Eldef_ *eldef,int crypt)
{
	extern double cs_Zero;			/* 0.0 */
	extern double cs_One;			/* 1.0 */
	extern double cs_Two;			/* 2.0 */
	extern double cs_ERadMin;		/* 1.0 */
	extern double cs_ERadMax;		/* 100 million */
	extern double cs_PRadMin;		/* 0.75 */
	extern double cs_PRadMax;		/* 100 million */
	extern double cs_EccentMax;		/* 0.2 */

	extern char csErrnam [];
	extern short cs_Protect;
	extern char cs_Unique;

	short cs_time;

	int st;
	int flag;
	int dummy;

	long fpos;

	char *cp;
	csFILE *strm;

	double my_flat;
	double my_ecent;
 
 	__ALIGNMENT__1		/* For some versions of Sun compiler. */
	struct cs_Eldef_ my_eldef;

	/* Prepare for a possible error. */
	strm = NULL;

	/* Compute the time, as we use it internally.  This is
	   days since January 1, 1990. If this record does get
	   written, we want it to have the current date in it.
	   This means that even if allowed, a distribution
	   coordinate system will be marked as having been
	   twiddled. */
	cs_time = (short)((CS_time ((cs_Time_ *)0) - 630720000L) / 86400L);
	if (eldef->protect >= 0)
	{
		eldef->protect = cs_time;
	}

	/* Adjust the name and make sure it is all upper
	   case.  By convention, ellipsoid names are case
	   insensitive. */
	st = CS_nampp (eldef->key_nm);
	if (st != 0) goto error;

	/* Check the definition for basic validity. */
	if (eldef->e_rad < cs_ERadMin || eldef->e_rad > cs_ERadMax ||
	    eldef->p_rad < cs_PRadMin || eldef->p_rad > cs_PRadMax)
	{
		CS_stncp (csErrnam,eldef->key_nm,MAXPATH);
		CS_erpt (cs_ELDEF_INV);
		goto error;
	}

	/* Check/Calculate the flattening and/or the eccentricity.
	   If the provided values are zero or less, we assume that
	   the calling module wants us to calculate the values.

	   Note, at this point, we know that neither e_rad or p_rad
	   is zero. */
	my_flat = cs_One - (eldef->p_rad / eldef->e_rad);
	if (my_flat < 0.0)
	{
		CS_stncp (csErrnam,eldef->key_nm,MAXPATH);
		CS_erpt (cs_ELDEF_INV);
		goto error;
	}
	else if (my_flat < 1.0e-07)
	{
		eldef->p_rad = eldef->e_rad;
		eldef->flat = cs_Zero;
		eldef->ecent = cs_Zero;
	}
	else
	{
		my_ecent = sqrt (cs_Two * my_flat - (my_flat * my_flat));

		if (eldef->flat  <= 0.0) eldef->flat  = my_flat;
		if (eldef->ecent <= 0.0) eldef->ecent = my_ecent;

		if (fabs (my_flat - eldef->flat) > 1.0E-08 ||
		    fabs (my_ecent - eldef->ecent) > 1.0E-08 ||
		    my_ecent > cs_EccentMax)
		{
			CS_stncp (csErrnam,eldef->key_nm,MAXPATH);
			CS_erpt (cs_ELDEF_INV);
			goto error;
		}
	}

	/* Open up the Ellipsoid Dictionary and verify its magic number. */
	strm = CS_elopn (_STRM_BINUP);
	if (strm == NULL)
	{
		goto error;
	}

	/* See if we have a ellipsoid with this name already. */
	flag = CS_bins (strm,(long)sizeof (cs_magic_t),0L,sizeof (*eldef),(char *)eldef,(CMPFUNC_CAST)CS_elcmp);
	if (flag < 0) goto error;
	if (flag)
	{
		/* Here when the coordinate system already exists. See
		   if it is OK to write it. If cs_Protect is less than
		   zero, all protection has been turned off. */
		if (cs_Protect >= 0)
		{
			fpos = CS_ftell (strm);
			if (fpos < 0L)
			{
				CS_erpt (cs_IOERR);
				goto error;
			}
			st = CS_elrd (strm,&my_eldef,&dummy);
			if (st == 0)
			{
				CS_erpt (cs_INV_FILE);
			}
			if (st <= 0)
			{
				goto error;
			}
			if (my_eldef.protect == 1)
			{
				/* We don't allow distribution ellipsoid
				   definitions to be overwritten, period. */
				CS_stncp (csErrnam,eldef->key_nm,MAXPATH);
				CS_erpt (cs_EL_PROT);
				goto error;
			}
			if (cs_Protect > 0 && my_eldef.protect > 0)
			{
				/* We protect user defined ellipsoids only
				   if cs_Protect is greater than zero. */
				if (my_eldef.protect < (cs_time - cs_Protect))		/*lint !e644 */
				{
					/* It has been more than cs_Protect
					   days since this coordinate system
					   has been twiddled, we consider it
					   to be protected. */
					CS_stncp (csErrnam,eldef->key_nm,MAXPATH);
					CS_erpt (cs_EL_UPROT);
					goto error;
				}
			}
			st = CS_fseek (strm,fpos,SEEK_SET);
			if (st != 0)
			{
				CS_erpt (cs_IOERR);
				goto error;
			}
		}

		/* OK, if we're still here, it's OK to overwrite the
		   record. */
		if (CS_elwr (strm,eldef,crypt))
		{
			goto error;
		}
	}
	else
	{
		/* Here if the ellipsoid definition doesn't exist.  We
		   have to add it. If cs_Unique is not zero, we
		   require that a cs_Unique character be present
		   in the key name before we'll allow it to be
		   written. */
		if (cs_Unique != '\0')
		{
			cp = strchr (eldef->key_nm,cs_Unique);
			if (cp == NULL)
			{
				csErrnam [0] = cs_Unique;
				csErrnam [1] = '\0';
				CS_erpt (cs_UNIQUE);
				goto error;
			}
		}

		/* If we're stiil here, we write the new ellipsoid to
		   the end of the file. */
		st = CS_fseek (strm,0L,SEEK_END);
		if (CS_elwr (strm,eldef,crypt))
		{
			goto error;
		}

		/* Sort the file into proper order, thereby
		   moving the new ellipsoid to its proper place
		   in the dictionary. */
		st = CS_fseek (strm,(long)sizeof (cs_magic_t),SEEK_SET);
		if (st != 0)
		{
			CS_erpt (cs_IOERR);
			goto error;
		}
		st = CS_ips (strm,sizeof (*eldef),0L,(CMPFUNC_CAST)CS_elcmp);
		if (st < 0) goto error;
	}

	/* The Ellipsoid Dictionary has been updated. */
	CS_elDictCls (strm);
	return (flag);

error:
	if (strm != NULL) CS_elDictCls (strm);
	return (-1);
}

/**********************************************************************
**	cmp_val = CS_elcmp (pp,qq);
**
**	struct cs_Eldef_ *pp;
**	struct cs_Eldef_ *qq;		The two ellipsoid definition structures which are
**								to be compared.
**	int cmp_val;				return is negative if pp follows qq in the
**								collating sequence, positive if pp preceeds
**								qq, and zero if they are equivalent.
**********************************************************************/
int EXP_LVL7 CS_elcmp (Const struct cs_Eldef_ *pp,Const struct cs_Eldef_ *qq)
{
	cs_Register unsigned char key;
	cs_Register unsigned char *cp;

	int st;

	unsigned char *cpe;

	char pp_key [24];
	char qq_key [24];

	/* If the entries are encoded, we must decode before the
	   comparision is made. */

	(void)memcpy (pp_key,pp->key_nm,sizeof (pp_key));
	key = (unsigned char)pp->fill [0];
	if (key != '\0')
	{
		cp = (unsigned char *)pp_key;
		cpe = cp + sizeof (pp_key);
		while (cp < cpe)
		{
			key ^= *cp;
			*cp++ = key;
		}
	}
	(void)memcpy (qq_key,qq->key_nm,sizeof (qq_key));
	key = (unsigned char)qq->fill [0];
	if (key != '\0')
	{
		cp = (unsigned char *)qq_key;
		cpe = cp + sizeof (qq_key);
		while (cp < cpe)
		{
			key ^= *cp;
			*cp++ = key;
		}
	}

	/* OK, now we can compare the two structures.  For sorting
	   and binary search purposes, we only lookl at the key name. */

	st = CS_stricmp (pp_key,qq_key);

	return (st);
}

/**********************************************************************
**	el_ptr = CS_eldef (el_nam);
**
**	char *el_nam;				key name of the ellipsoid definition to be
**								fetched.
**	struct cs_Eldef_ *el_ptr;	returns a pointer to a malloc'ed ellipsoid definition
**								structure.
**
**	This function only fetches the ellipsoid definition as recorded in
**	the ellipsoid dictionary.  This is only a part of a datum definition.
**	CS_dtdef will fetch a datum definition, CS_dtloc fetches an entire
**	datum definition which includes both the datum definition and
**	the ellipsoid parameters.
**********************************************************************/

struct cs_Eldef_ * EXP_LVL3 CS_eldef (Const char *el_nam)
{
	extern char csErrnam [];
	extern double cs_One;			/* 1.0 */
	extern double cs_Two;			/* 2.0 */
	extern double cs_Zero;			/* 0.0 */
	extern double cs_ERadMin;		/* 1.0 */
	extern double cs_ERadMax;		/* 100 million */
	extern double cs_PRadMin;		/*  0.75 */
	extern double cs_PRadMax;		/* 100 million */
	extern double cs_EccentMax;		/* 0.2 */

	int st;
	int flag;
	int crypt;

	csFILE *strm;
	struct cs_Eldef_ *el_ptr;

	double my_ecent;
	double my_flat;

 	__ALIGNMENT__1				/* For some versions of Sun compiler. */
	struct cs_Eldef_ eldef;

	/* Prepare for the potential error condition. */
	strm = NULL;
	el_ptr = NULL;

	/* Give the application first shot at satisfying this request. */
	if (CS_usrElDefPtr != NULL)
	{
		st = (*CS_usrElDefPtr)(&eldef,el_nam);
		if (st < 0) return NULL;
		if (st == 0)
		{
			el_ptr = (struct cs_Eldef_ *)CS_malc (sizeof (struct cs_Eldef_));
			if (el_ptr == NULL)
			{
				CS_erpt (cs_NO_MEM);
				goto error;
			}
			memmove (el_ptr,&eldef,sizeof (*el_ptr));
			return el_ptr;
		}
	}

	/* Make sure the name is not too large. */
	CS_stncp (eldef.key_nm,el_nam,sizeof (eldef.key_nm));
	st = CS_nampp (eldef.key_nm);
	if (st != 0) goto error;

	/* Mark this entry as unencrypoted so that the name comparison
	   function will work. */
	eldef.fill [0] = '\0';

	/* Open up the coordinate system dictionary file. */
	strm = CS_elopn (_STRM_BINRD);
	if (strm == NULL) goto error;

	/* Search the file for the requested ellipsoid definition. */
	flag = CS_bins (strm,(long)sizeof (cs_magic_t),0L,sizeof (eldef),(char *)&eldef,(CMPFUNC_CAST)CS_elcmp);
	if (flag < 0) goto error;

	/* See if the ellipsoid definition exists.  If not, there's not
	   much more we can do. */
	if (!flag)
	{
		CS_stncp (csErrnam,el_nam,MAXPATH);
		CS_erpt (cs_EL_NOT_FND);
		goto error;
	}
	else
	{
		/* The ellipsoid definition exists.  Therefore, we malloc the
		   ellipsoid definition structure and read it in. */
		el_ptr = (struct cs_Eldef_ *)CS_malc (sizeof (struct cs_Eldef_));
		if (el_ptr == NULL)
		{
			CS_erpt (cs_NO_MEM);
			goto error;
		}
		if (!CS_elrd (strm,el_ptr,&crypt))
		{
			goto error;
		}
	}
	if (!cs_ElStrmFlg)
	{
		CS_elDictCls (strm);
	}
	strm = NULL;

	/* Check the ellipsoid definition for valitity. */
	if (el_ptr->e_rad < cs_ERadMin || el_ptr->e_rad > cs_ERadMax ||
	    el_ptr->p_rad < cs_PRadMin || el_ptr->p_rad > cs_PRadMax)
	{
		CS_stncp (csErrnam,eldef.key_nm,MAXPATH);
		CS_erpt (cs_ELDEF_INV);
		goto error;
	}


	/* e_rad and p_rad are both greater than zero. */
	my_flat = cs_One - (el_ptr->p_rad / el_ptr->e_rad);
	if (my_flat < 0.0)
	{
		CS_stncp (csErrnam,el_ptr->key_nm,MAXPATH);
		CS_erpt (cs_ELDEF_INV);
		goto error;
	}
	else if (my_flat < 1.0E-07)
	{
		el_ptr->p_rad = el_ptr->e_rad;
		el_ptr->flat = cs_Zero;
		el_ptr->ecent = cs_Zero;
	}
	else
	{
		my_ecent = sqrt (cs_Two * my_flat - (my_flat * my_flat));
		if (my_ecent > cs_EccentMax ||
			fabs (my_ecent - el_ptr->ecent) > 1.0E-08 ||
			fabs (my_flat  - el_ptr->flat)   > 1.0E-08)
		{
			CS_stncp (csErrnam,el_nam,MAXPATH);
			CS_erpt (cs_ELDEF_INV);
			goto error;
		}
	}

	/* Return a pointer to the malloc'ed ellipsoid definition to the
	   user. */
	return (el_ptr);

error:
	if (strm != NULL) CS_elDictCls (strm);
	if (el_ptr != NULL)
	{
		CS_free (el_ptr);
		el_ptr = NULL;
	}
	return (el_ptr);
}

/**********************************************************************
**	CS_elfnm (new_name);
**
**	char *new_name;				the name of the ellipsoid dictionary file.
**
**	This function specifies the name only.  The directory,
**	and possibly drive, are specified using CS_altdr.
**********************************************************************/

void EXP_LVL1 CS_elfnm (Const char *new_name)
{
	extern char cs_Elname [];

	(void)CS_stncp (cs_Elname,new_name,cs_FNM_MAXLEN);
	return;
}
