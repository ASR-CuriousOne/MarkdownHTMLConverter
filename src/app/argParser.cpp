#include <cstring>
#include <iostream>
#include <fstream>
#include <regex>
#include <stdexcept>
#include "argParser.hpp"

void parseArgumentsAndExecute(int argc,char* argv[]){
    if(argc < 2){
        std::cout << "Not enough arguments" << '\n';
        return;
    }
    
    Info info{};
    bool inputSet = false;
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i],"-o") == 0 && i < argc - 1) {
            info.outputStream.open(argv[i + 1]);
            if(info.outputStream.is_open()) std::cout << "Output File is Open\n";
            i++;
        }
        if(!inputSet){
            info.inputStream.open(argv[i]);
            if(info.inputStream.fail()) {
                std::cerr << "Error!! '"<<argv[i] << "' no such file exists." << std::endl;
                return;
            }
            inputSet = true;
        }
    }
    std::string line;
    while(getline(info.inputStream,line)){
        info.outputStream << line << '\n';
    }    
}




