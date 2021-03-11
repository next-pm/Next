#include <commands/clear_command.hpp>

ClearCommand::ClearCommand(/* args */)
    : CommandBase()
{
#if defined(_WIN32)
    this->command += "cd build\\Release && app.exe";
#elif defined(__linux)
    this->command += "rm -r " + NextData::getInstance()->build_dir;
#endif
}

ClearCommand::~ClearCommand()
{
}

int ClearCommand::execute()
{
    exec_void(this->command);
    std::cout<< termcolor::red << "Clear CmakeCache\n"<<termcolor::reset;
    return 0;
}