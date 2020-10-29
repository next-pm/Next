#include <commands/path_command.hpp>

#include <tools/exec.hpp>

PathCommand::PathCommand(/* args */) : CommandBase()
{
}

PathCommand::~PathCommand()
{
}

int PathCommand::execute(/* args */)
{
    std::cout << exec("echo $PATH")<<'\n';
    //std::system("pwd");
    return 0;
}