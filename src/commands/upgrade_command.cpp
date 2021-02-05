#include <commands/upgrade_command.hpp>

UpgradeCommand::UpgradeCommand()
    : CommandBase()
{
#if defined(_WIN32)
    this->command += "cd build\\cmake && cmake ..\\.. && msbuild HELLO.sln /p:Configuration=Release";
#elif defined(__linux)
    this->command += "cd " + NextData::getInstance()->path + " && git pull origin master";
#endif
}

UpgradeCommand::~UpgradeCommand()
{
}

int UpgradeCommand::execute()
{
    exec_void(this->command);
    return 0;
}