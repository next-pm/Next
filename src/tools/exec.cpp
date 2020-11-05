#include <tools/exec.hpp>

std::string exec(std::string command)
{
    command += " >file.txt";
    std::system(command.c_str());

    std::string line;
    std::string ret;

    std::ifstream myfile("file.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            ret += line;
        }
        myfile.close();
    }

    else
    {
        std::cout << "Unable to open file";
        return "null";
    }

    std::system("rm file.txt");

    return ret;
}