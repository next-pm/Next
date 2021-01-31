#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <command_base.hpp>

#include <next_data.hpp>

class PathCommand : public CommandBase
{
private:
    std::string path_command;
    char separator;
    std::size_t displacement;
public:
    PathCommand(/* args */);
    ~PathCommand();
    int execute();
};

