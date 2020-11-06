#include <commands/run_command.hpp>

RunCommand::RunCommand(/* args */)
    : CommandBase()
{
}

RunCommand::~RunCommand()
{
}

int RunCommand::execute()
{
    int status;
    std::string line;

    line += "make run";

    //std::cout<<exec(line)<<'\n';

    status = std::system(line.c_str());
    return status;
}