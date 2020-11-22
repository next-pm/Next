#include <commands/make_command.hpp>

MakeCommand::MakeCommand(/* args */)
    : CommandBase()
{
}

MakeCommand::~MakeCommand()
{
}

MakeCommand::MakeCommand(std::string commands)
    : commands{commands}, CommandBase()
{
}

int MakeCommand::execute()
{

    std::string command;

    command += "make PATH_NEXT=" + NextData::getInstance()->path;

    command += commands;
    

    int status = std::system(command.c_str());
    return 0;
}