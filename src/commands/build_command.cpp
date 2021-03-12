#include <commands/build_command.hpp>

BuildCommand::BuildCommand(/* args */)
    : CommandBase()
{
//#if defined(_WIN32)
    //this->command += "cd build\\cmake && cmake ..\\.. && msbuild HELLO.sln "
    //                 "/p:Configuration=Release";
//#elif defined(__linux)

    this->command += "cd " + NextData::getInstance()->build_dir + " && cmake ";
    for (auto flag : NextData::getInstance()->cmake_flags)
    {
        this->command += " " + flag;
    }

    if (NextData::getInstance()->build_system == "Ninja" || NextData::getInstance()->build_system == "Unix Makefiles")
    {
        this->command += " && " + NextData::getInstance()->build_system_exe;

        for (auto flag : NextData::getInstance()->build_system_flags)
        {
            this->command += " " + flag;
        }
    }
    else
    {
        std::cout << termcolor::red << "Not Build System Suport\n"
                  << termcolor::reset;
        this->command.clear();
    }

//#endif
}

BuildCommand::BuildCommand(std::string typeBuild)
    : CommandBase(), typeBuild{typeBuild}
{
#if defined(_WIN32)
    //this->command += "cd build\\cmake && cmake ..\\.. && msbuild HELLO.sln "
    //                 "/p:Configuration=Release";
    this->command += "cd " + NextData::getInstance()->build_dir + " && cmake " + NextData::getInstance()->pwd + " -G \""+NextData::getInstance()->build_system+"\"";
#elif defined(__linux)
    this ->command += "mkdir -p " + NextData::getInstance()->build_dir + " && ";
    this->command += "cd " + NextData::getInstance()->build_dir + " && cmake " + NextData::getInstance()->pwd + " -G \""+NextData::getInstance()->build_system+"\"";
    //Add Compilers
#endif
    this->command += " -DCMAKE_C_COMPILER=" + NextData::getInstance()->c_compiler + " -DCMAKE_CXX_COMPILER=" + NextData::getInstance()->cxx_compiler;
    for (auto flag : NextData::getInstance()->cmake_flags)
    {
        this->command += " " + flag;
    }
    if (typeBuild == "-R" || typeBuild == "Release")
    {
        this->command += " -DCMAKE_BUILD_TYPE=Release ";
    }
    if (typeBuild == "-D" || typeBuild == "Debug")
    {
        this->command += " -DCMAKE_BUILD_TYPE=Debug ";
    }

    if (NextData::getInstance()->build_system == "Ninja" || NextData::getInstance()->build_system == "Unix Makefiles")
    {
        this->command += " && " + NextData::getInstance()->build_system_exe;

        for (auto flag : NextData::getInstance()->build_system_flags)
        {
            this->command += " " + flag;
        }
    }
    else
    {
        std::cout << termcolor::red << "Not Build System Suport\n"
                  << termcolor::reset;
        this->command.clear();
    }

}

BuildCommand::~BuildCommand() {}

int BuildCommand::execute()
{
    //std::cout<<this->command<<'\n';
    //NextData::getInstance()->printData();
#if defined(_WIN32)
    exec_void("mkdir " + NextData::getInstance()->build_dir);
#endif
    exec_void(this->command);
    if (typeBuild == "-R" || typeBuild == "Release")
    {
        std::cout << termcolor::green << termcolor::bold << "Type Build Release\n"
                  << termcolor::reset;
    }
    if (typeBuild == "-D" || typeBuild == "Debug")
    {
        std::cout << termcolor::green << termcolor::bold << "Type Build Debug\n"
                  << termcolor::reset;
    }
    return 0;
}