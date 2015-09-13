#include "loggerParser.h"
#include <fstream>
#include <iostream>
#include "rapidxml.hpp"
using namespace rapidxml;
using namespace std;

namespace{
    namespace XmlNodeNames {
        const xStrT ROOT = XT("Config");
        const xStrT 
    }
    
}

LoggerParser::LoggerParser(const std::xStrT& conf_file)
    :conf_file_(conf_file)
{
}


bool LoggerParser::Parse()
{
    std::ifstream fs("logger-conf.xml");
    assert(fs);    
    fs.seekg(0, ios::end);
    int size = fs.tellg();
    char* content = new char[size + 1];
    memset(content, 0, size + 1);
    fs.seekg(0, ios::beg);
    fs.read(content, size);

    xml_document<> doc;
    doc.parse<0>(content);

    //std::cout << doc;
    cout << "Name of my first node is: " << doc.first_node()->name() << "\n";
    xml_node<> *node = doc.first_node("config");
    cout << "Node config has value " << node->value() << "\n";
    for (xml_attribute<> *attr = node->first_attribute();
    attr; attr = attr->next_attribute())
    {
        cout << "Node foobar has attribute " << attr->name() << " ";
        cout << "with value " << attr->value() << "\n";
    }

    return true;
}

LoggerParser::~LoggerParser()
{
}
