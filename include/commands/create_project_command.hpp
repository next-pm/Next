#pragma once

#include <iostream>
#include <string>

#include <command_base.hpp>
#include <next_data.hpp>
#include <tools/exec.hpp>

class CreateProjectCommand : public CommandBase
{
private:
    std::string name_project = "";
public:
    CreateProjectCommand(/* args */);
    CreateProjectCommand(std::string name_project);
    ~CreateProjectCommand();
    int execute();
};