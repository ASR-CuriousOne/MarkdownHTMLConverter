#ifndef ARG_PARSER_HPP
#define ARG_PARSER_HPP

#include <fstream>
#include <string>

struct Info{
    std::ifstream inputStream;
    std::ofstream outputStream;
    bool stopAtErrors = false;
};


void parseArgumentsAndExecute(int argc,char* argv[]);

#endif
