#pragma once

#include <iostream>
#include <vector>
#include <string>

#include <picojson.hpp>

namespace NEXT::CPP::Linux
{
    class File
    {
    public:
        std::string permissions;
        std::string type;
        std::string owner;
        std::string size;
        std::string date;
        std::string name;
        File(/* args */);
        File(picojson::object root);
        ~File();

        void decode(std::string data, std::string dir_relative);

        picojson::value toJson();

        bool equal(File& other);

        void print();
    };
    
} // namespace NEXT::Linux
