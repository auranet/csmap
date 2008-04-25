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

			 File Name: $RCSfile: rcWellKnownText.cpp $
		   Description:
			   Purpose:

		Revision Level:	$Revision: #7 $
		 Check In Date:	$Date: 2007/01/11 $

		Last Revision:	$Log: rcWellKnownText.cpp $
		Last Revision:	Revision 11.1300  2005/05/25 23:27:26  nto
		Last Revision:	Official Release 11.13
		Last Revision:	Revision 11.1200  2005/01/15 18:27:21  nto
		Last Revision:	Official Release of CS-MAP 11.12, 11:26am 15 Jan 2005
		Last Revision:	Revision 11.1101  2005/01/15 06:03:58  nto
		Last Revision:	Adjusted to handles the Oracle flavor, which uses white space more liberally.l
		Last Revision:	Revision 11.1100  2004/11/01 18:53:21  nto
		Last Revision:	Official release 11.11
		Last Revision:	Revision 11.1001  2004/10/07 19:25:27  nto
		Last Revision:	Revision 11.900  2004/03/26 17:02:33  nto
		Last Revision:	Official release: 11.09 - 3/25/2003
		Last Revision:	Revision 11.800  2004/01/13 23:29:23  nto
		Last Revision:	Revision 11.700  2003/12/19 01:50:02  nto
		Last Revision:	Official release 11.07
		Last Revision:	Revision 11.601  2003/12/19 01:15:12  nto
		Last Revision:	Update to the new ANSI C++ STL standard (std namespace).
		Last Revision:	Revision 11.600  2003/12/04 02:46:39  nto
		Last Revision:	Release 11.06.  Never shipped. Source captured in prep for C++ V7.
		Last Revision:	Revision 1.2  2003/11/24 01:14:24  nto
		Last Revision:	Major modifications to fix several problems.
		Last Revision:	Revision 1.1  2003/10/01 22:10:20  nto
		Last Revision:	Initial Revision

		*  *  *  *  R E M A R K S *  *  *  *  *


******************************************************************************/

#ifdef LABEL_MODULE
static char revlvl [] = {"$Id: //depot/Libraries/CsMap/current/src/rcWellKnownText.cpp#7 $"};
#endif

#if defined (__CPP__)

#include "cs_map.h"
#include "rcWellKnownText.hpp"
#include "cs_wkt.h"

extern "C" struct csWktPrjNameMap_ csWktPrjNameMap [];
extern "C" struct csWktPrmNameMap_ csWktPrmNameMap [];
extern TrcWktUnitNameMap KrcWktUnitNameMap [];
extern TrcWktEleTypeMap KrcWktEleTypeMap [];
extern TrcWktAxisValueMap KrcWktAxisValueMap [];

//newPage//
///////////////////////////////////////////////////////////////////////////////
// The following are non-member support functions implemented specifically to
// support processing of WKT data.
std::string rcExtractWkt (std::istream& inStrm,unsigned& lineNbr,unsigned& startLineNbr)
{
	int curChar = '\0';
	int startChar = '\0';
	int termChar = '\0';
	int nestLevel = 0;
	int keyWordIdx = 0;
	int whiteSpaceIdx = 0;

	char keyWord [32];
	char whiteSpace [64];

	enum ErcWktPrsState {	wktScan = 0,
							wktKeyword,
							wktBracket,
							wktCapture,
							wktDone
						};
	ErcWktPrsState state = wktScan;

	// wktPrimitive is the return value.  It is empty upon return if the stream
	// did not have a WKT primitive.  You could also check the stream for EOF.
	// Note, as far as I knowm, WKT is only defined for 8 bit characters.
	std::string wktPrimitive;

	// Skip stuff in stream until we see a WKT keyword.  What little spec
	// there is for WKT says that keywords are always upper case.
	keyWord [0] = '\0';
	whiteSpace [0] = '\0';
	while (state != wktDone)
	{
		if (inStrm.eof ()) break;
		curChar = inStrm.get ();
		if (curChar == '\n')
		{
			lineNbr += 1;
			continue;
		}

		switch (state) {
		case wktScan:
			if (isupper (curChar))
			{
				keyWordIdx = 0;
				if (keyWordIdx < 60)
				{
					keyWord [keyWordIdx++] = curChar;
				}
				state = wktKeyword;
			}
			break;

		case wktKeyword:
			if (isupper (curChar) || curChar == '_')
			{
				keyWord [keyWordIdx++] = curChar;
			}
			else
			{
				keyWord [keyWordIdx] = '\0';
				ErcWktEleType wktType = rcWktNameToType (keyWord);
				if (wktType != rcWktUnknown)
				{
					startLineNbr = lineNbr;			// line number at which this def starts
					whiteSpace [0] = '\0';
					whiteSpaceIdx = 0;
					if (curChar == '(' || curChar == '[')
					{
						startChar = curChar;
						termChar = (curChar == '(') ? ')' : ']';
						nestLevel = 1;
						state = wktCapture;
						wktPrimitive.erase ();
						wktPrimitive += keyWord;
						wktPrimitive += whiteSpace;
						wktPrimitive += startChar;
					}
					else if (isspace (curChar))
					{
						whiteSpace [whiteSpaceIdx++] = curChar;
						whiteSpace [whiteSpaceIdx] = '\0';
						state = wktBracket;
					}
					else
					{
						state = wktScan;
					}
				}
				else
				{
					state = wktScan;
				}
			}
			break;

		case wktBracket:
			if (curChar == '(' || curChar == '[')
			{
				startChar = curChar;
				termChar = (startChar == '(') ? ')' : ']';
				state = wktCapture;
				wktPrimitive.erase ();
				wktPrimitive += keyWord;
				wktPrimitive += whiteSpace;
				wktPrimitive += startChar;
				nestLevel = 1;
				state = wktCapture;
			}
			else if (isspace (curChar))
			{
				if (whiteSpaceIdx < 100)
				{
					whiteSpace [whiteSpaceIdx++] = curChar;
				}
			}
			else
			{
				state = wktScan;
			}
			break;

		case wktCapture:
			wktPrimitive += curChar;
			if (curChar == startChar)
			{
				nestLevel += 1;
			}
			else if (curChar == termChar)
			{
				nestLevel -= 1;
				if (nestLevel <= 0)
				{
					state = wktDone;
					nestLevel = 0;
				}
			}
			break;
			
		case wktDone:
			// to keep gcc compiler happy.
			break;
		}
	}
	if (state != wktDone) wktPrimitive.erase ();
	return wktPrimitive;
}
const char *rcWktTypeToName (ErcWktEleType type)
{
	const char *rtnValue = "";

	if (type < rcWktUnknown)
	{
		rtnValue = KrcWktEleTypeMap [type].Name;
	}
	return rtnValue;
}
bool rcWktHasInitialName (ErcWktEleType type)
{
	bool hasInitialName = false;
	if (type < rcWktUnknown)
	{
		hasInitialName = KrcWktEleTypeMap [type].InitlName;
	}
	return hasInitialName;
}
ErcWktEleType rcWktNameToType (const char *name)
{
	TrcWktEleTypeMap *tblPtr;
	for (tblPtr = KrcWktEleTypeMap;tblPtr->Type < rcWktUnknown;tblPtr += 1)
	{
		if (!strcmp (tblPtr->Name,name)) break;
	}
	return tblPtr->Type;
}
const char *rcWktAxisValueToName (ErcWktAxisValue axisValue)
{
	if (axisValue > rcWktAxisNone && axisValue < rcWktAxisUnknown)
	{
		axisValue = rcWktAxisUnknown;
	}
	return	KrcWktAxisValueMap [axisValue].Name;
}
ErcWktAxisValue rcWktNameToAxisValue (const char *name)
{
	TrcWktAxisValueMap *tblPtr;

	for (tblPtr = &KrcWktAxisValueMap [1];tblPtr->Value < rcWktAxisUnknown;tblPtr += 1)
	{
		if (!CS_stricmp (tblPtr->Name,name)) break;
	}
	return tblPtr->Value;
}
//newPage//
class TrcWktElements;
///////////////////////////////////////////////////////////////////////////////
// The TrcWktElement Object
///////////////////////////////////////////////////////////////////////////////
// Construction  /  Destruction  /  Assignment
TrcWktElement::TrcWktElement (void) :	WktParent (0),
										ElementType (rcWktNone),
										ParentType (rcWktNone),
										Value (),
										ElementName (),
										Children (),
										LineNbr (0),
										FileName ()
{
}
// For this constructor, name (if appropriate for the type) must be the first
// CSV field of the value string.
TrcWktElement::TrcWktElement (ErcWktEleType type,const char *value) :
										WktParent (0),
										ElementType (type),
										ParentType (rcWktNone),
										Value (value),
										ElementName (),
										Children (),
										LineNbr (0),
										FileName ()
{
	CommonConstruct ();
}
// For this constructor, name (if appropriate for the type) must be the first
// CSV field of the value string.
TrcWktElement::TrcWktElement (ErcWktEleType type,const std::string& value) :
										WktParent (0),
										ElementType (type),
										ParentType (rcWktNone),
										Value (value),
										ElementName (),
										Children (),
										LineNbr (0),
										FileName ()
{
	CommonConstruct ();
}
// This constructor will prepend the name to the value for you.
TrcWktElement::TrcWktElement (ErcWktEleType type,const std::string& name,const std::string& value) :
										WktParent (0),
										ElementType (type),
										ParentType (rcWktNone),
										Value (),
										ElementName (name),
										Children (),
										LineNbr (0),
										FileName ()
{
	Value = "\"" + name + "\"" + "," + value;
}
TrcWktElement::TrcWktElement (const char *wellKnownText) :
										WktParent (0),
										ElementType (rcWktNone),
										ParentType (rcWktNone),
										Value (),
										ElementName (),
										Children (),
										LineNbr (0),
										FileName ()
{
	size_t eleStrt;
	size_t eleTerm;

	ElementType = ParseWellKnownText (Value,eleStrt,eleTerm,wellKnownText);
	if (ElementType == rcWktUnknown)
	{
		// Guess the text was not so Well Known!!!
		Value.erase ();
	}
	else
	{
		CommonConstruct ();
	}
}
TrcWktElement::TrcWktElement (const TrcWktElement& source) :
										WktParent (0),
										ElementType (source.ElementType),
										ParentType (source.ParentType),
										Value (source.Value),
										ElementName (source.ElementName),
										Children (source.Children),
										LineNbr (0),
										FileName ()
{
}
TrcWktElement::~TrcWktElement (void)
{
	// Nothing to do here, yet!
}
TrcWktElement& TrcWktElement::operator= (const TrcWktElement& rhs)
{
	if (&rhs != this)
	{
		WktParent   = 0;
		ElementType = rhs.ElementType;
		ParentType  = rhs.ParentType;
		Value       = rhs.Value;
		ElementName = rhs.ElementName;
		Children    = rhs.Children;
		LineNbr     = rhs.LineNbr;
		FileName    = rhs.FileName;
	}
	return *this;
}
void TrcWktElement::CommonConstruct (void)
{
	if (HasInitialName ())
	{
		ElementName = ExtractField (0);
		DeleteField (0);
	}
	else
	{
		ElementName.erase ();
	}
}
///////////////////////////////////////////////////////////////////////////////
// Public Named Memebr Functions
bool TrcWktElement::HasInitialName (void) const
{
	return rcWktHasInitialName (ElementType);
}
void TrcWktElement::GetFieldChar (char *bufr,size_t bufrSize,size_t fieldNbr) const
{
	ExtractField (bufr,bufrSize,fieldNbr);
}
std::string TrcWktElement::GetFieldStr (size_t fieldNbr) const
{
	return ExtractField (fieldNbr);
}
double TrcWktElement::GetFieldDouble (size_t fieldNbr) const
{
	char bufr [64];
	ExtractField (bufr,sizeof (bufr),fieldNbr);
	return atof (bufr);
}
long TrcWktElement::GetFieldLong (size_t fieldNbr) const
{
	char bufr [64];
	ExtractField (bufr,sizeof (bufr),fieldNbr);
	return atol (bufr);
}
///////////////////////////////////////////////////////////////////////////
// The following member functions are used to construct a WKT object for
// subsequent output.
void TrcWktElement::AddChild (const TrcWktElement& childElement)
{
	Children.AddChild (childElement,this,ElementType);
}
void TrcWktElement::RemoveChild (const TrcWktElement* toBeRemoved)
{
	Children.RemoveChild (toBeRemoved);
}
void TrcWktElement::ParseChildren (void)
{
	// Extract each sub-element from the value of this element.
	for (;;)
	{
		size_t eleStrt;
		size_t eleTerm;
		ErcWktEleType elementType;
		std::string value;
		const char *wellKnownText = Value.c_str ();
		elementType = ParseWellKnownText (value,eleStrt,eleTerm,wellKnownText);

		// We get an unknown back if there were no more sub-elements.
		if (elementType == rcWktUnknown)
		{
			break;
		}
	
		// Add the element we just extracted to out Children list.
		TrcWktElement newChild (elementType,value);
		AddChild (newChild);
		RemoveElementFromString (Value,eleStrt,eleTerm);
	}

	// Now we need to parse the grandchildren.
	Children.ParseGrandChildren ();
}
void TrcWktElement::ReconstructValue (void)		// from possibly modified children
{
	size_t ii;
	const TrcWktElement* wktPtr;

	Value.erase ();
	Value += '\"';
	Value += ElementName;
	Value += '\"';
	Value += ',';

	switch (ElementType) {
	case rcWktAuthority:
	case rcWktAxis:
	case rcWktCompDCS:
	case rcWktConcatMt:
	case rcWktDatum:
	case rcWktFittedCS:
	case rcWktGeoCCS:
	case rcWktLocalCS:
	case rcWktMethod:
	case rcWktParameter:
	case rcWktParamMt:
	case rcWktPrimeM:
	case rcWktProjCS:
	case rcWktProjection:
	case rcWktSpheroid:
	case rcWktUnit:
	case rcWktVertDatum:
	case rcWktVertCS:
		for (ii = 0;ii < Children.GetCount ();ii += 1)
		{
			wktPtr = Children [ii];
			Value += wktPtr->ProduceWkt ();
		}
		Value += "]";
		break;
	case rcWktToWgs84:
		break;
	case rcWktInverseMt:
	case rcWktPassThroughMt:
	default:
		// These don't have a name or any sub-elements, so we
		// don't really have anything to do here.
		Value.erase ();
		break;
	}
}
std::string TrcWktElement::ProduceWkt () const
{
	const TrcWktElement* wktPtr;
	std::string rtnValue;
	const char *typeName = rcWktTypeToName (ElementType);
	rtnValue += typeName;
	rtnValue += "[";

	// The actual value which we produce is a function of the element
	// type.
	if (HasInitialName ())
	{
		rtnValue += '"';
		rtnValue += ElementName;
		rtnValue += '"';
	}

	// Any Children???
	for (size_t ii = 0;ii < Children.GetCount ();ii += 1)
	{
		wktPtr = Children [ii];
		rtnValue += ',';
		rtnValue += wktPtr->ProduceWkt ();
	}

	// Any additional Value???
	if (Value.length () > 0)
	{
		rtnValue += ',';
		rtnValue += Value;
	}
	rtnValue += "]";
	return rtnValue;
}
///////////////////////////////////////////////////////////////////////////////
// Private Support Functions
std::string TrcWktElement::ExtractField (size_t fieldNbr,bool trimQuotes) const
{
	bool inQuote;
	char ch;
	int idx;
	size_t first = 0;
	size_t last = 0;
	size_t curFldNbr = 0;
	const char *chPtr;	

	// Because we can have quoted strings which can have commas in them,
	// we must avoid the temptation to used "find_first_of" et al.
	idx = -1;
	chPtr = Value.c_str ();
	inQuote = false;
	while ((ch = *chPtr++) != '\0')
	{
		idx += 1;
		if (inQuote)
		{
			if (ch == '\"')
			{
				if (*chPtr == '\"')
				{
					idx += 1;
					chPtr += 1;
				}
				else
				{
					inQuote = false;
				}
			}
		}
		else					// !inQuote
		{
			if (ch == '\"')
			{
				inQuote = true;
			}
			else
			{
				if (ch == ',')
				{
					if (curFldNbr == fieldNbr)
					{
						last = static_cast<size_t>(idx - 1); 
					}
					else
					{
						curFldNbr += 1;
						if (curFldNbr == fieldNbr)
						{
							first = static_cast<size_t>(idx + 1);
						}
					}
				}
			}
		}
		if (last != 0) break;
	}
	if (ch == '\0' && curFldNbr == fieldNbr) last = static_cast<size_t>(idx);
	std::string tmpStr = Value.substr (first,(last - first + 1));
	TrimWhiteSpace (tmpStr);
	if (trimQuotes)
	{
		TrimQuotes (tmpStr);
		TrimWhiteSpace (tmpStr);
	}
	return tmpStr;
}
void TrcWktElement::DeleteField (size_t fieldNbr)
{
	bool inQuote;
	char ch;
	int idx;
	size_t first = 0;
	size_t last = 0;
	size_t curFldNbr = 0;
	const char *chPtr;	

	// Because we can have quoted strings which can have commas in them,
	// we must avoid the temptation to used "find_first_of" et al.
	idx = -1;
	chPtr = Value.c_str ();
	inQuote = false;
	while ((ch = *chPtr++) != '\0')
	{
		idx += 1;
		if (inQuote)
		{
			if (ch == '\"')
			{
				if (*chPtr == '\"')
				{
					idx += 1;
					chPtr += 1;
				}
				else
				{
					inQuote = false;
				}
			}
		}
		else			// !inQuote
		{
			if (ch == '\"')
			{
				inQuote = true;
			}
			else if (ch == ',')
			{
				if (curFldNbr == fieldNbr)
				{
					// If we are removing the first field, we include the
					// terminating comma.  Otherwise, we leave the terminating
					// comma in.
					if (fieldNbr == 0) last = static_cast<size_t>(idx);
					else               last = static_cast<size_t>(idx - 1);
				}
				else
				{
					curFldNbr += 1;
					if (curFldNbr == fieldNbr)
					{
						// Can't get here for field zero, and we include the
						// initial comma in the erase portion.
						first = static_cast<size_t>(idx);
					}
				}
			}
		}
		if (last != 0) break;
	}
	if (ch == '\0' && curFldNbr == fieldNbr) last = static_cast<size_t>(idx);
	if (last != 0)
	{
		Value.erase (first,(last - first + 1));
		TrimWhiteSpace (Value);
	}
}
void TrcWktElement::ExtractField (char *bufr,size_t bufrSize,size_t fieldNbr) const
{
	std::string tmpStr = ExtractField (fieldNbr);
	const char *chPtr = tmpStr.c_str ();
	strncpy (bufr,chPtr,bufrSize);
	*(bufr + bufrSize - 1) = '\0';
}
void TrcWktElement::TrimQuotes (std::string& value)
{
	size_t length;
	
	length = value.length ();
	if (length >= 2)
	{
		if (value [0] == '\"' && value [length - 1] == '\"')
		{
			value.erase (length - 1,1);
			value.erase (0,1);	
		}
	}
}
void TrcWktElement::TrimWhiteSpace (std::string& value)
{
	size_t begin;		// index of first char of trimmed string
	size_t end;			// index of last char of trimmed string
	size_t last;		// index of the last char of the untrimmed string.
	size_t length;
	
	length = value.length ();
	if (length > 0)
	{
		last = length - 1;
		begin = value.find_first_not_of (' ');
		end = value.find_last_not_of (' ');
		if ((begin > 0 || end < last) && (end >= begin)) 
		{
			value = value.substr (begin,(end - begin + 1));
		}
	}
	return;
}
ErcWktEleType TrcWktElement::ParseWellKnownText (std::string& value,size_t& eleStrt,size_t& eleTerm,const char *wellKnownText)
{
	char curChar = '\0';
	char strtChar = '\0';
	char termChar = '\0';
	int nestLevel = 0;
	size_t keyWordIdx = 0;
	const char *chPtr;
	char keyWord [64];

	value.erase ();
	ErcWktEleType elementType = rcWktUnknown;
	eleStrt = 0;
	eleTerm = 0;

	enum  {	wktScan,
			wktKeyword,
			wktBracket,
			wktCapture,
			wktCaptureQ,
			wktTrim,
			wktDone
		  } state;

	state = wktScan;
	chPtr = wellKnownText;
	while ((curChar = *chPtr++) != '\0')
	{
		switch (state) {
		case wktScan:
			if (isupper (curChar))
			{
				keyWordIdx = 0;
				keyWord [keyWordIdx++] = curChar;
				eleStrt = chPtr - wellKnownText - 1;
				state = wktKeyword;
			}
			break;

		case wktKeyword:
			if (isupper (curChar) || (curChar == '_') || ((keyWordIdx > 0) && isdigit (curChar)))
			{
				if (keyWordIdx < 60)
				{
					keyWord [keyWordIdx++] = curChar;
				}
			}
			else if (curChar == '(' || curChar == '[')
			{
				keyWord [keyWordIdx] = '\0';
				elementType = rcWktNameToType (keyWord);
				if (elementType == rcWktUnknown)
				{
					keyWordIdx = 0;	
					keyWord [0] = '\0';		//make debugging easier
					eleStrt = 0;
					state = wktScan;
				}
				else
				{
					strtChar = curChar;
					termChar = (strtChar == '(') ? ')' : ']';
					value.erase ();
					nestLevel = 1;
					state = wktCapture;
				}
			}
			else if (isspace (curChar))
			{
				state = wktBracket;
			}
			else
			{
				keyWordIdx = 0;	
				keyWord [0] = '\0';		//make debugging easier
				eleStrt = 0;
				state = wktScan;
			}
			break;

		case wktBracket:
			if (curChar == '(' || curChar == '[')
			{
				keyWord [keyWordIdx] = '\0';
				elementType = rcWktNameToType (keyWord);
				if (elementType == rcWktUnknown)
				{
					keyWordIdx = 0;	
					keyWord [0] = '\0';		//make debugging easier
					eleStrt = 0;
					state = wktScan;
				}
				else
				{
					strtChar = curChar;
					termChar = (strtChar == '(') ? ')' : ']';
					value.erase ();
					nestLevel = 1;
					state = wktCapture;
				}
			}
			else if (!isspace (curChar))
			{
				keyWordIdx = 0;	
				keyWord [0] = '\0';		//make debugging easier
				eleStrt = 0;
				state = wktScan;
			}
			break;

		case wktCapture:
			if (curChar == termChar)
			{
				nestLevel -= 1;
				if (nestLevel <= 0)
				{
					// Don't add the terminating bracket.
					if (*chPtr == '\0')
					{
						eleTerm = chPtr - wellKnownText - 1;
						state = wktDone;
					}
					else
					{
						state = wktTrim;
					}
				}
				else
				{
					value += curChar;
				}
			}
			else if (curChar == strtChar)
			{
				value += curChar;
				nestLevel += 1;
			}
			else if (curChar == '\"')
			{
				value += curChar;
				state = wktCaptureQ;
			}
			else if (curChar != '\n')
			{
				value += curChar;
			}
			break;

		case wktCaptureQ:
			value += curChar;
			if (curChar == '\"' && *chPtr == '\"')
			{
				// Escaped quote, copy both and maintain state.
				value += *chPtr++;
			}
			else if (curChar == '\"')
			{
				state = wktCapture;
			}
			break;

		case wktTrim:
			if (!isspace (curChar))
			{
				eleTerm = chPtr - wellKnownText - 2;
				state = wktDone;
			}
			break;

		case wktDone:
		default:
			// To keep lint happy.			
			break;
		}
		if (state == wktDone) break;
	}
	if (!value.empty ())
	{
		TrimWhiteSpace (value);
	}
	return elementType;
}
// eleStrt and eleTerm are the index values for the first and last characters
// to be removed.  We may remove some extra commas and whitespace as indicated
// by the surrounding data.
void TrcWktElement::RemoveElementFromString (std::string& value,size_t eleStrt,size_t eleTerm)
{
	size_t begIdx = eleStrt;
	size_t endIdx = eleTerm;

	// Move begIdx back over any leading whitespace in the stuff we are to remove.
	while (begIdx > 0 && isspace (value [begIdx - 1])) begIdx -= 1;

	// If the thing we are removing is followed by a comma, we always remove that.
	if (value [endIdx + 1] == ',')
	{
		endIdx += 1;
	}
	else
	{
		// Here if the thing we are removing is not followed by a comma.
		// Remove any comma which might precede the thing we are removing.
		if (begIdx > 0 && value [begIdx - 1] == ',')
		{
			begIdx -= 1;
			while (begIdx > 0 && isspace (value [begIdx])) begIdx -= 1;
		}
	}
	value.erase (begIdx,(endIdx - begIdx + 1));
}
// This function will only look at the children of this element.  Returns the
// first child so located.
const TrcWktElement *TrcWktElement::ChildLocate (ErcWktEleType type) const
{
	return Children.LocateChild (type);
}
// This function will only look at the children of this element.  Use the index
// arument to step through multiple children of the same type.
const TrcWktElement *TrcWktElement::ChildLocate (ErcWktEleType type,size_t& index) const
{
	return Children.LocateChild (type,index);
}
// This function will not only look at the children of this element, but also
// cause a search of all children.  In other words, a search is a recursive
// search, while a Locate is simply a search of the children of a specific
// elements.  Returns the first element so located.
const TrcWktElement *TrcWktElement::ChildSearch (ErcWktEleType type) const
{
	size_t childIdx;
	const TrcWktElement *rtnValue = 0;
	const TrcWktElement *srchPtr;

	rtnValue = ChildLocate (type);
	if (rtnValue == 0)
	{
		for (childIdx = 0;childIdx < Children.GetCount ();childIdx += 1)
		{
			srchPtr = Children [childIdx];
			rtnValue = srchPtr->ChildSearch (type);
			if (rtnValue != 0) break;
		}
	}
	return rtnValue;
}
const TrcWktElement* TrcWktElement::ParameterLocate (ErcWktFlavor flavor,short csMapParmCode) const
{
	size_t index = 0;
	long msiCode;
	const char *nmPtr;
	const TrcWktElement* rtnParameter = 0;
	const TrcWktElement* srchParameter;

	// We use a double loop.  Outer loop, which should be the smallest, steps
	// through each WKT PARAMETER object contained in this element.
	do
	{
		srchParameter = Children.LocateChild (rcWktParameter,index);
		if (srchParameter == 0) break;
		nmPtr = srchParameter->GetElementNameC ();
		if (nmPtr == 0 || *nmPtr == '\0') continue;

		// OK, we have a parameter with a name.  We need to see if it meets our criteria.
		msiCode = CSwktPrmName2Code (nmPtr,flavor);
		if (msiCode == csMapParmCode)
		{
			rtnParameter = srchParameter;
		}
	} while (rtnParameter == 0);
	return rtnParameter;
}
ErcWktAxisId TrcWktElement::GetAxisId (void) const
{	
	ErcWktAxisId axisId = rcWktAxisIdNone;
	if (ElementType == rcWktAxis)
	{
		if      (ElementName == "Lat") axisId = rcWktAxisIdLat;
		else if (ElementName == "Lon") axisId = rcWktAxisIdLng;
		else if (ElementName == "X")   axisId = rcWktAxisIdX;
		else if (ElementName == "Y")   axisId = rcWktAxisIdY;
		else if (ElementName == "Z")   axisId = rcWktAxisIdZ;
	}
	return axisId;
}
ErcWktAxisValue TrcWktElement::GetAxisValue (void) const
{
	ErcWktAxisValue axisValue = rcWktAxisNone;
	if (ElementType == rcWktAxis)
	{
		axisValue = rcWktNameToAxisValue (Value.c_str ());
	}
	return axisValue;
}
ErcWktFlavor TrcWktElement::DetermineFlavor (void) const
{
	int idx;
	size_t prmIdx;
	const TrcWktElement* wktElePtr;
	const TrcWktElement* gcsElePtr;
	ErcWktFlavor curFlavor;
	ErcWktFlavor flavor = wktFlvrUnknown;
	// Order the flavors in this array in the order of desired precedence.
	ErcWktFlavor flavors [] = {wktFlvrEsri,wktFlvrOracle,wktFlvrEpsg,wktFlvrGeoTiff,wktFlvrOgc,wktFlvrGeoTools,wktFlvrUnknown};

	if (ElementType == rcWktProjCS)
	{
		unsigned long prjBitMap = 0UL;
		unsigned long prmBitMap = 0UL;
		unsigned long unitBitMap = 0UL;
		unsigned long gcsBitMap = 0UL;

		wktElePtr = ChildLocate (rcWktProjection);
		if (wktElePtr != 0)
		{
			const char* wktPrjName = wktElePtr->GetElementNameC ();
			for (idx = 0;flavors [idx] != wktFlvrUnknown;idx += 1)
			{
				curFlavor = flavors [idx];
				long prjCode = CSwktPrjName2Code (wktPrjName,curFlavor);
				if (prjCode != 0)
				{
					prjBitMap |= 1UL << idx;
				}
			}
		}

		wktElePtr = ChildLocate (rcWktUnit);
		if (wktElePtr != 0)
		{
			const char* wktUnitName = wktElePtr->GetElementNameC ();
			for (idx = 0;flavors [idx] != wktFlvrUnknown;idx += 1)
			{
				curFlavor = flavors [idx];
				const char* unitMsiName = CSwktUnitName2MsiName (wktUnitName,curFlavor);
				if (unitMsiName != 0)
				{
					unitBitMap |= 1UL << idx;
				}
			}
		}

		gcsElePtr = ChildLocate (rcWktGeogCS);
		if (gcsElePtr != 0)
		{
			wktElePtr = gcsElePtr->ChildLocate (rcWktUnit);
			if (wktElePtr != 0)
			{
				const char* wktUnitName = wktElePtr->GetElementNameC ();
				for (idx = 0;flavors [idx] != wktFlvrUnknown;idx += 1)
				{
					curFlavor = flavors [idx];
					const char* unitMsiName = CSwktUnitName2MsiName (wktUnitName,curFlavor);
					if (unitMsiName != 0)
					{
						gcsBitMap |= 1UL << idx;
					}
				}
			}
		}

		for (idx = 0;flavors [idx] != wktFlvrUnknown;idx += 1)
		{
			int prmCnt = 0;
			int mapCnt = 0;
			curFlavor = flavors [idx];

			prmIdx = 0;
			while ((wktElePtr = ChildLocate (rcWktParameter,prmIdx)) != 0)
			{
				prmCnt += 1;
				const char* wktPrmName = wktElePtr->GetElementNameC ();
				long prmCode = CSwktPrmName2Code (wktPrmName,curFlavor);
				if (prmCode != 0)
				{
					mapCnt += 1;
				}
			}
			if (mapCnt == prmCnt)
			{
				// Here if the above loop did not terminate due to an
				// unmappable parameter name.
				prmBitMap |= 1UL << idx;
			}
		}

		unsigned long flvrBitMap = prjBitMap & prmBitMap & unitBitMap & gcsBitMap;
		if (flvrBitMap != 0UL)
		{
			for (idx = 0;flavors [idx] != wktFlvrUnknown;idx += 1)
			{
				if ((flvrBitMap & 1) != 0)
				{
					flavor = flavors [idx];
					break;
				}
				flvrBitMap >>= 1;
			}
		}
		else
		{
			flvrBitMap = 1UL;
		}
	}
	else if (ElementType == rcWktGeogCS)
	{
		// Since unit is the only flavopr dependent thing here, we take
		// the first match.
		wktElePtr = ChildLocate (rcWktUnit);
		if (wktElePtr != 0)
		{
			const char* wktUnitName = wktElePtr->GetElementNameC ();
			for (idx = 0;flavors [idx] != wktFlvrUnknown;idx += 1)
			{
				curFlavor = flavors [idx];
				const char* unitMsiName = CSwktUnitName2MsiName (wktUnitName,curFlavor);
				if (unitMsiName != 0)
				{
					flavor = flavors [idx];
					break;
				}
			}
		}
	}
	else if (ElementType == rcWktGeogTran)
	{
		unsigned long prmBitMap = 0UL;

		for (idx = 0;flavors [idx] != wktFlvrUnknown;idx += 1)
		{
			curFlavor = flavors [idx];
			prmIdx = 0;
			while ((wktElePtr = ChildLocate (rcWktParameter,prmIdx)) != 0)
			{
				const char* wktPrmName = wktElePtr->GetElementNameC ();
				long prmCode = CSwktPrmName2Code (wktPrmName,curFlavor);
				if (prmCode == 0) break;
			}
			if (wktElePtr == 0)
			{
				// Here is the above loop did not terminate due to an
				// unmappable parameter name.
				prmBitMap |= 1UL << idx;
			}
		}
		if (prmBitMap != 0UL)
		{
			for (idx = 0;flavors [idx] != wktFlvrUnknown;idx += 1)
			{
				if ((prmBitMap & 1) != 0)
				{
					flavor = flavors [idx];
					break;
				}
				prmBitMap >>= 1;
			}
		}
	}
	else
	{
		flavor = wktFlvrUnknown;
	}
	return flavor;
}
//newPage//
///////////////////////////////////////////////////////////////////////////////
// TrcWktElements  --  Abstracts a vector of TrcWktElement
TrcWktElements::TrcWktElements (void)
{
}
TrcWktElements::TrcWktElements (const TrcWktElements& source) :
										Elements (source.Elements)
{
}
TrcWktElements::~TrcWktElements (void)
{
	// Nothing to do here, yet!
}
TrcWktElements& TrcWktElements::operator= (const TrcWktElements& rhs)
{
	if (&rhs != this)
	{
		Elements = rhs.Elements;
	}
	return *this;
}
const TrcWktElement* TrcWktElements::operator[] (ErcWktEleType type) const
{
	return LocateChild (type);
}
const TrcWktElement* TrcWktElements::operator[] (size_t index) const
{
	return (index < Elements.size ()) ? &Elements [index] : 0;
}
const TrcWktElement* TrcWktElements::LocateChild (ErcWktEleType type) const
{
	size_t index;
	const TrcWktElement* rtnValue = 0;

	for (index = 0;index < Elements.size ();index += 1)
	{
		if (Elements [index].GetElementType () == type)
		{
			rtnValue = &Elements [index];
			break;
		}
	}
	return rtnValue;
}
const TrcWktElement* TrcWktElements::LocateChild (ErcWktEleType type,size_t& index) const
{
	size_t myIndex = index;
	const TrcWktElement* rtnValue = 0;

	for (myIndex = index;myIndex < Elements.size ();myIndex += 1)
	{
		if (Elements [myIndex].GetElementType () == type)
		{
			rtnValue = &Elements [myIndex];
			break;
		}
	}
	if (rtnValue != 0) index = myIndex + 1;
	return rtnValue;
}
TrcWktElements& TrcWktElements::AddChild (const TrcWktElement& newChild,
										  const TrcWktElement* parent,
										  ErcWktEleType parentType)
{
	Elements.push_back (newChild);

	TrcWktElement& newChldRef = Elements [Elements.size () - 1];
	newChldRef.SetParent (parent);
	newChldRef.SetParentType (parentType);
	return *this;
}
void TrcWktElements::ParseGrandChildren (void)
{
	std::vector<TrcWktElement>::iterator wktItr;

	for (wktItr = Elements.begin ();wktItr != Elements.end ();wktItr++)
	{
		wktItr->ParseChildren ();
	}
}
TrcWktElements& TrcWktElements::RemoveChild (const TrcWktElement* toBeRemoved)
{
	std::vector<TrcWktElement>::iterator wktItr;

	for (wktItr = Elements.begin ();wktItr != Elements.end ();wktItr++)
	{
		if (&(*wktItr) == toBeRemoved)
		{
			Elements.erase (wktItr);
			break;
		}
	}
	return *this;
}
//newPage//
///////////////////////////////////////////////////////////////////////////////
// The following two functions are used to extract the identification numbers
// from the data files we have been provided with.  They MUST extract the
// 'next' id number without processing even the first character of the WKT
// definition.  This is based on very subjective data.  Hopefully, it will
// not need to be used often as once the name/number mapping is done correctly,
// this process will not need to be repeated.
//
long csExtractEsriNbr (std::istream& inStrm,unsigned& lineNbr)
{
	char curChar;
	long esriNbr = -1;
	char* dummy;
	char contextData [8];
	char nbrNameTag [] = "<b> ";
	char wktDefTag []  = "colSpan";

	// Assumption here is that the file is the HTML file you can download from
	// the web.  Thus, we are looking for a certain HTML sequence which
	// encloses the identification number.  If we don't see it before we
	// encounter a sequence that normally preceeds a WKT definition, we return
	// a zero.  If we see an 'end of file' in all this, we return -1L.
	
	// We start a loop which will extract data into the contectData array in a
	// circular fashion.  That is, the context data array will always have the
	// last 7 characters obtained from the stream.  We use those 8 characters
	// to determine where we are in the data stream.
	contextData [0] = ' ';
	contextData [1] = ' ';
	contextData [2] = ' ';
	contextData [3] = ' ';
	contextData [4] = ' ';
	contextData [5] = ' ';
	contextData [6] = ' ';
	contextData [7] = '\0';
	while (esriNbr <= 0L)
	{
		if (inStrm.eof ()) break;
	
		curChar = inStrm.get ();
		if (curChar == '\n')
		{
			lineNbr += 1;
		}
		contextData [0] = contextData [1];
		contextData [1] = contextData [2];
		contextData [2] = contextData [3];
		contextData [3] = contextData [4];
		contextData [4] = contextData [5];
		contextData [5] = contextData [6];
		contextData [6] = curChar;
		
		// See what we have now.
		if (!strcmp (contextData,wktDefTag))
		{
			// We didn't see an identification number.  Return zero now.
			esriNbr = 0L;
			break;
		}
		else if (contextData [0] == '<')
		{
			if (!strncmp (contextData,nbrNameTag,4))
			{
				size_t nbrIdx = 0;
				char nbrData [16];
				nbrData [nbrIdx] = '\0';
				
				// Could be a number.  Could be a name
				while (isspace (inStrm.peek ()))
				{
					inStrm.get ();
				}
				if (isdigit (contextData [5]))
				{
					nbrData [nbrIdx++] = contextData [5];
					nbrData [nbrIdx] = '\0';
				}
				if (isdigit (contextData [6]))
				{
					nbrData [nbrIdx++] = contextData [6];
					nbrData [nbrIdx] = '\0';
				}
				while (isdigit (inStrm.peek ()))
				{
					// Looks like a number.  We chase it and see where it leads us.
					nbrData [nbrIdx++] = inStrm.get ();
					nbrData [nbrIdx] = '\0';
				}
				if (nbrIdx >= 4)
				{
					// If we got 4 pr more digits, we assume we have seen an
					// identification number.  We capture it, and return it now.
					esriNbr = strtol (nbrData,&dummy,10);
				}
			}
		}
	}
	return esriNbr;
}
#endif
