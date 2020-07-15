#include <iostream>
#include <fstream>
#include <string>
#include <next.hpp>
#include <file_next.hpp>

int main(int argc, char const *argv[])
{

    NEXT::Linux::Next next;
    next.init("next.json");
    next.get_all_source();

    std::string instruction = next.compiler_CC + " ";
    for (std::string s : next.cc_flags)
    {
        instruction += s + " ";
    }

    instruction += "-o " + next.binary_dir + "/" + next.name_build + " ";

    for (std::string s : next.source_files)
    {
        instruction += s + " ";
    }

    for (std::string s : next.linker_dirs)
    {
        instruction += "-I" + s + " ";
    }

    for (std::string s : next.libs_flags)
    {
        instruction += s + " ";
    }

    std::cout << instruction << '\n';

    std::system(instruction.c_str());

    return 0;
}
