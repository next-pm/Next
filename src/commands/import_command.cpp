#include <commands/import_command.hpp>

ImportCommand::ImportCommand(std::string url_repo)
    : CommandBase()
{
#if defined(_WIN32)
    this->command += "cd build\\cmake && cmake ..\\.. && msbuild HELLO.sln /p:Configuration=Release";
#elif defined(__linux)
    this->command += "cd lib && git clone " +
                     url_repo;
#endif
}

ImportCommand::~ImportCommand()
{
}

int ImportCommand::execute()
{
    exec_void(this->command);
    exec_void("cat $(find lib/*/include_lib.cmake) >libs.cmake");
    return 0;
}