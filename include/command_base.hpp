#pragma once

#include <string>
#include <vector>
#include <memory>

class CommandBase
{
public:
    CommandBase(/* args */);
    virtual ~CommandBase() = 0;
    virtual int execute() = 0;
};

class CommandBase_State
{
private:
    std::string name;
    std::vector<std::string> args;

public:
    CommandBase_State(/* args */);
    virtual ~CommandBase_State() = 0;
};