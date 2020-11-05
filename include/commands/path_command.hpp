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
    /* data */
public:
    PathCommand(/* args */);
    ~PathCommand();
    int execute();
};

