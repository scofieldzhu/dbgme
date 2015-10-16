#ifndef __CONF_PARSER_H__
#define __CONF_PARSER_H__

#include "dgr2.h"
#include "cfpDLLExport.h"

#pragma warning(disable:4275 4290)

#define CFP cfp
#define CFP_NP_BEGIN NP_BEGIN(CFP)
#define USING_CFP USING_NP(CFP)

CFP_NP_BEGIN
class ConfParseException;
class ClsNodeParser;
class ClsNodeParserRegistrant;
NP_END

#endif