#ifndef __LOGGER_CLS_NODE_PARSER_H__
#define __LOGGER_CLS_NODE_PARSER_H__

#include "clsNodeParser.h"

DGR2_NP_BEGIN
class CFP_API LoggerClsNodeParser : public ClsNodeParser
{
public:
    DGR2::DGRObject* parse(my_xml_node& cls_node);
    LoggerClsNodeParser();
    virtual ~LoggerClsNodeParser();
};
NP_END
#endif