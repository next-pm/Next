#pragma once

#include <iostream>
#include <string>

#include <command_base.hpp>
#include <next_data.hpp>
#include <tools/exec.hpp>

class MakeCommand : public CommandBase
{
private:
    std::string commands;
public:
    MakeCommand(/* args */);
    MakeCommand(std::string commands);
    ~MakeCommand();
    int execute();
};