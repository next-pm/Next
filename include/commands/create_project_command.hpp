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
    std::vector<std::string> dirs;
    std::vector<std::string> copy_commands;
    std::vector<std::string> move_commands;
public:
    CreateProjectCommand(/* args */);
    CreateProjectCommand(std::string name_project);
    ~CreateProjectCommand();
    int execute();
    void createDirs();
    void copyFiles();
    void moveFiles();
};