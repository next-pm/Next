#include <iostream>
#include <fstream>
#include <string>
#include <linux/next.hpp>
#include <linux/file_next.hpp>

int main(int argc, char const *argv[])
{

    NEXT::CPP::Linux::Next next;
    next.init("next.json");
    if (argc == 1)
    {
        next.help();
        return 0;
    }

    next.readFiles();

    for (int i = 1; i < argc; i++)
    {
        std::string op = argv[i];
        if (op == "--help" || op == "-h")
        {
            next.help();
        }
        if (op == "build_all")
        {
            next.build_all();
        }

        if (op == "build")
        {
            next.build();
        }

        if (op == "test")
        {
            next.test();
        }

        if (op == "run_test")
        {
            next.run_test();
        }
        if (op == "create")
        {
            op = argv[i + 1];
            if (op != ".")
            {
                next.create(op);
            }
        }
        if (op == "run")
        {
            next.run();
        }
        if (op == "testing")
        {
        }
        next.writeFiles();
    }

    return 0;
}
