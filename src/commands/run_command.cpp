#include <commands/run_command.hpp>

RunCommand::RunCommand(/* args */)
    : CommandBase()
{
#if defined(_WIN32)
    this->command += "cd build\\Release && app.exe";
#elif defined(__linux)
    this->command += "cd " + NextData::getInstance()->build_dir + " && ./" +
                     NextData::getInstance()->name_build;
#endif
}

RunCommand::~RunCommand()
{
}

int RunCommand::execute()
{
    //std::cout<<this->command;
    exec_void(this->command);
    return 0;
}