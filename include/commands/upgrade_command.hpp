#pragma once

#include <iostream>
#include <string>

#include <command_base.hpp>
#include <next_data.hpp>
#include <tools/exec.hpp>

class UpgradeCommand : public CommandBase
{
private:
    std::string command;

public:
    UpgradeCommand();
    ~UpgradeCommand();
    int execute();
};