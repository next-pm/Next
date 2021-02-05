#pragma once

#include <iostream>
#include <string>

#include <command_base.hpp>
#include <next_data.hpp>
#include <tools/exec.hpp>

class ImportCommand : public CommandBase
{
private:
    std::string command;

public:
    ImportCommand(std::string url_repo);
    ~ImportCommand();
    int execute();
};