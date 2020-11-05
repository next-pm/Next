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
    std::string line;

    line += "make run";

    //std::cout<<exec(line)<<'\n';

    std::system(line.c_str());
    return 0;
}