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
#if defined(_WIN32)
    line += "cd build/cmake && cmake ../.. && msbuild HELLO.sln /p:Configuration=Release";
#elif defined(__linux)
    line += "cd build/cmake && cmake ../.. && make VERBOSE=1";
#endif
    exec_void(line);

    return 0;
}