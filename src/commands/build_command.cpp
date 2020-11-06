#include <commands/build_command.hpp>

BuildCommand::BuildCommand(/* args */)
    : CommandBase()
{
}

BuildCommand::~BuildCommand()
{
}

int BuildCommand::execute()
{
    std::string line;

    line += "make build";

    return std::system(line.c_str());
}