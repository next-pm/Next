#pragma once

#include <vector>

#include <command_base.hpp>

class StackCommand
{
public:
    std::vector<CommandBase*> stack_tasks;
    StackCommand(/* args */);
    ~StackCommand();
    void append(CommandBase* );
    void undo();
    void clear();
    void execute();
};
