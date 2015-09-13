#ifndef __LOGGER_PARSER_H__
#define __LOGGER_PARSER_H__

#include "langext.h"

class LoggerParser
{
public:
    LoggerParser(const std::xStrT& conf_file);
    bool Parse();
    ~LoggerParser();

private:
    std::xStrT conf_file_;
};

#endif
