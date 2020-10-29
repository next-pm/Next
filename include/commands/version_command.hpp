#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include <command_base.hpp>

class VersionCommand : public CommandBase
{
private:
    /* data */
public:
    VersionCommand(/* args */);
    ~VersionCommand();
    int execute();
};

