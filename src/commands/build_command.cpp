#include <commands/build_command.hpp>

BuildCommand::BuildCommand(/* args */)
    : CommandBase()
{
#if defined(_WIN32)
    this->command += "cd build\\cmake && cmake ..\\.. && msbuild HELLO.sln /p:Configuration=Release";
#elif defined(__linux)
    this->command += "cd build/cmake && cmake ../.. && make VERBOSE=1";
#endif
}

BuildCommand::~BuildCommand()
{
}

int BuildCommand::execute()
{
    exec_void(this->command);
    return 0;
}