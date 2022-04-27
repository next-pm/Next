#include <commands/run_command.hpp>

RunCommand::RunCommand(/* args */)
    : CommandBase()
{
#if defined(_WIN32)
    this->command += "cd build\\Release && app.exe";
#elif defined(__linux)
    this->command += "cd build && ./app";
#endif
}

RunCommand::~RunCommand()
{
}

int RunCommand::execute()
{
    exec_void(this->command);
    return 0;
}