#pragma once

class CommandBase
{
private:
    /* data */
public:
    CommandBase(/* args */);
    virtual ~CommandBase() = 0;
    virtual int execute() = 0;
};