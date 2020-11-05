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

    std::system(line.c_str());
    return 0;
}