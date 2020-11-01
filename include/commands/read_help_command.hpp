#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include <command_base.hpp>

#include <next_data.hpp>

class ReadHelpCommand : public CommandBase
{
private:
    /* data */
public:
    ReadHelpCommand(/* args */);
    ~ReadHelpCommand();
    int execute();
};

