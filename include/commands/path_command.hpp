#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include <command_base.hpp>

class PathCommand : public CommandBase
{
private:
    /* data */
public:
    PathCommand(/* args */);
    ~PathCommand();
    int execute();
};

