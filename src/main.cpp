#include <iostream>
#include <fstream>
#include <string>

#include <next.hpp>

int main(int argc, char const *argv[])
{
    NEXT::Next next;
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

    instruction += "-I" + next.include_dir;

    std::cout<<instruction<<'\n';

    std::system(instruction.c_str());

    return 0;
}
