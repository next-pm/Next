#pragma once

#include <iostream>
#include <vector>
#include <string>

namespace NEXT::CPP::Linux
{
    class File
    {
    public:
        std::string permissions;
        std::string type;
        std::string owner;
        std::string size;
        std::string month;
        std::string day;
        std::string hour;
        std::string name;
        File(/* args */);
        ~File();

        void decode(std::string data);
    };
    
} // namespace NEXT::Linux
