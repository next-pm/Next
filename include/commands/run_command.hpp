#pragma once

#include <iostream>
#include <string>

#include <command_base.hpp>
#include <next_data.hpp>
#include <tools/exec.hpp>

class RunCommand : public CommandBase
{
private:
    std::string command;
public:
    RunCommand(/* args */);
    ~RunCommand();
    int execute();
};