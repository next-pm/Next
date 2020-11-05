#pragma once

#include <unordered_map>
#include <memory>
#include <string>

#include <stack_command.hpp>

#include <commands/read_help_command.hpp>
#include <commands/version_command.hpp>
#include <commands/path_command.hpp>
#include <commands/create_project_command.hpp>

class ManagerCommand
{
private:
    StackCommand stackCommand;

public:
    ManagerCommand(/* args */);
    ~ManagerCommand();

    void execute();

    void initialize(int argc, char const *argv[]);

    constexpr bool isFlag(char const *arg)
    {
        return arg[0] == '-';
    }

    void createFlag(char const *arg)
    {
        if (std::string(arg) == "--help" || std::string(arg) == "-h")
        {
            this->stackCommand.append(new PathCommand());
            this->stackCommand.append(new ReadHelpCommand());
        }
        if (std::string(arg) == "--version" || std::string(arg) == "-v")
        {
            this->stackCommand.append(new PathCommand());
            this->stackCommand.append(new VersionCommand());
        }

        if (std::string(arg) == "--path" || std::string(arg) == "-p")
        {
            this->stackCommand.append(new PathCommand());
        }
    }

    bool isCommand(char const *arg)
    {
        if (std::string(arg) == "create")
        {
            return true;
        }
        return false;
    }
};
