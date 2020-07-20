#include <string>
#include <thread>

#include <linux/next.hpp>

namespace NEXT::CPP::Linux
{
    Next::Next(/* args */)
    {
    }

    Next::~Next()
    {
    }

    int Next::init(std::string file_dir)
    {
        std::ifstream file(file_dir);
        if (!file)
        {
            return -1;
        }

        picojson::value json;

        file >> json;

        this->root = json.get<picojson::object>();

        this->name_project = this->find<std::string>("name_project");
        this->name_build = this->find<std::string>("name_build");
        this->version_build = this->find<std::string>("version_build");
        this->language = this->find<std::string>("language");
        this->version_language = this->find<std::string>("version_language");
        this->compiler_CC = this->find<std::string>("compiler_CC");
        this->compiler_C = this->find<std::string>("compiler_C");
        this->main_file = this->find<std::string>("main_file");
        this->test_file = this->find<std::string>("test_file");
        this->source_dir = this->find<std::string>("source_dir");
        this->test_dir = this->find<std::string>("test_dir");
        this->object_dir = this->find<std::string>("object_dir");
        this->binary_dir = this->find<std::string>("binary_dir");
        this->include_dir = this->find<std::string>("include_dir");
        this->libs_dir = this->find<std::string>("libs_dir");
        this->lib = this->find<std::string>("lib");

        auto array_linker_dirs{this->find<picojson::array>("linker_dirs")};

        for (size_t i = 0; i < array_linker_dirs.size(); i++)
        {
            this->linker_dirs.push_back(array_linker_dirs[i].get<std::string>());
        }

        auto array_cc_flags{this->find<picojson::array>("cc_flags")};

        for (size_t i = 0; i < array_cc_flags.size(); i++)
        {
            this->cc_flags.push_back(array_cc_flags[i].get<std::string>());
        }

        auto array_c_flags{this->find<picojson::array>("c_flags")};

        for (size_t i = 0; i < array_c_flags.size(); i++)
        {
            this->c_flags.push_back(array_c_flags[i].get<std::string>());
        }

        auto array_libs_flags{this->find<picojson::array>("libs_flags")};

        for (size_t i = 0; i < array_libs_flags.size(); i++)
        {
            this->libs_flags.push_back(array_libs_flags[i].get<std::string>());
        }

        return 0;
    }

    void Next::get_all_source()
    {
        std::system(Next::get_dir.c_str());
        std::ifstream source_dir(Next::read_files_data.c_str());
        std::string dir;
        getline(source_dir, dir);

        std::system(Next::ls_and_write_files.c_str());
        std::string line;
        std::ifstream source(Next::read_files_data.c_str());

        std::string dir_relative;

        if (source.is_open())
        {
            while (getline(source, line))
            {
                if (line.find("./") == std::string::npos &&
                    line.find("total ") == std::string::npos &&
                    line.find(".:") == std::string::npos &&
                    line.size() > 0)
                {
                    File file;
                    file.decode(line);
                    if (file.name.find(".cpp") != std::string::npos && dir_relative.find(this->source_dir) != std::string::npos)
                    {
                        this->source_files.push_back(dir_relative + "/" + file.name);
                    }
                    this->source.push_back(file);
                }

                if (line.find("./") != std::string::npos)
                {
                    //line.copy
                    Next::removeSubstrs(line, std::string("."));
                    Next::removeSubstrs(line, std::string(":"));
                    dir_relative = dir + line;
                }
            }
        }
        remove(Next::read_files_data.c_str());
    }

    void Next::compile_file(std::string file, int num)
    {
        this->generate_dir(file);
        std::string sourceFile = file;
        Next::replace(file, this->source_dir, this->object_dir);
        Next::replace(file, ".cpp", ".o");

        this->source_obj.push_back(file);

        std::string lineCompile;

        std::string progress;
        progress += "[" + std::to_string(100 / this->source_files.size() * num) + "%] ";
        NEXT::Print(progress, NEXT::Colors::boldgreen);

        lineCompile += this->compiler_CC + " ";
        NEXT::Print(this->compiler_CC + " ", NEXT::Colors::boldred);

        for (auto s : this->cc_flags)
        {
            s.push_back(' ');
            lineCompile += s;
            NEXT::Print(s, NEXT::Colors::blue);
        }

        lineCompile += "-o ";
        NEXT::Print("-o ", NEXT::Colors::boldgreen);

        lineCompile += file + " ";
        NEXT::Print(file + " ", NEXT::Colors::green);

        lineCompile += "-c ";
        NEXT::Print("-c ", NEXT::Colors::boldgreen);

        lineCompile += sourceFile + " ";
        NEXT::Print(sourceFile + " ", NEXT::Colors::white);

        for (auto s : this->libs_flags)
        {
            s.push_back(' ');
            lineCompile += s;
            NEXT::Print(s, NEXT::Colors::blue);
        }
        for (auto s : this->linker_dirs)
        {
            s.push_back(' ');
            lineCompile += "-I" + s + " ";
            NEXT::Print("-I" + s, NEXT::Colors::boldyellow);
        }
        std::cout << "\n\n";
        std::system(lineCompile.c_str());
    }

    void Next::generate_dir(std::string file)
    {
        Next::replace(file, this->source_dir, this->object_dir);
        std::vector<std::string> lines;
        std::string line;
        for (size_t i = 0; i < file.size(); i++)
        {
            if (file[i] != '/')
            {
                line.push_back(file[i]);
            }
            else
            {
                lines.push_back(line + "/");
                line.clear();
            }
        }
        line.clear();
        line += "mkdir -p ";
        line.push_back(34);
        for (auto s : lines)
        {
            line += s;
        }
        line.push_back(34);
        std::system(line.c_str());
    }

    void Next::linker_files()
    {
        std::string linker("[linker] ");
        NEXT::Print(linker, NEXT::Colors::boldgreen);

        std::string lineLinker;

        lineLinker += this->compiler_CC + " ";
        NEXT::Print(this->compiler_CC + " ", NEXT::Colors::boldred);

        lineLinker += "-o ";
        NEXT::Print("-o ", NEXT::Colors::boldgreen);

        lineLinker += this->binary_dir + "/" + this->name_build + " ";
        NEXT::Print(this->binary_dir + "/" + this->name_build + " ", NEXT::Colors::green);

        for (auto s : this->source_obj)
        {
            s.push_back(' ');
            lineLinker += s;
            NEXT::Print(s, NEXT::Colors::white);
        }
        for (auto s : this->libs_flags)
        {
            s.push_back(' ');
            lineLinker += s;
            NEXT::Print(s, NEXT::Colors::blue);
        }
        std::cout << "\n\n";
        std::system(lineLinker.c_str());
    }

    void Next::build()
    {
        this->init("next.json");

        std::string mk_bin_dir;
        mk_bin_dir += "mkdir -p ./" + this->binary_dir;

        std::system(mk_bin_dir.c_str());

        this->get_all_source();
        int i = 0;
        for (auto s : this->source_files)
        {
            this->compile_file(s, i);
            i++;
        }

        if (this->lib == "")
        {
            this->linker_files();
        }
        else
        {
            this->generate_lib();
        }
    }

    void Next::generate_lib()
    {
        std::string linker("[lib] ");
        NEXT::Print(linker, NEXT::Colors::boldgreen);

        std::string lineLib;

        lineLib += "ar ";
        NEXT::Print("ar ", NEXT::Colors::boldred);

        lineLib += "-crs ";
        NEXT::Print("-crs ", NEXT::Colors::boldgreen);

        lineLib += this->binary_dir + "/" + this->name_build + " ";
        NEXT::Print(this->binary_dir + "/" + this->name_build + " ", NEXT::Colors::green);

        for (auto s : this->source_obj)
        {
            s.push_back(' ');
            lineLib += s;
            NEXT::Print(s, NEXT::Colors::white);
        }
        for (auto s : this->libs_flags)
        {
            s.push_back(' ');
            lineLib += s;
            NEXT::Print(s, NEXT::Colors::blue);
        }
        std::system(lineLib.c_str());
        std::cout<<"\n\n";
        lineLib.clear();
        lineLib += "ranlib ";
        NEXT::Print("[ranlib] ", NEXT::Colors::boldgreen);
        lineLib += this->binary_dir + "/" + this->name_build;
        NEXT::Print(this->binary_dir + "/" + this->name_build, NEXT::Colors::green);
        std::cout<<"\n\n";
        std::system(lineLib.c_str());
    }

    void Next::create(std::string name)
    {
        std::string line;
        line += "mkdir -p " + name;
        std::system(line.c_str());

        line.clear();
        line += "cd " + name;
        std::system(line.c_str());

        line.clear();
        line += "mkdir -p " + name + "/src " + name + "/include " + name + "/bin " + name + "/obj " + name + "/test ";
        std::system(line.c_str());

        line.clear();
        line += "cp " + getDir() + "assets/next.json ./" + name;
        std::cout << line << '\n';
        std::system(line.c_str());

        line.clear();
        line += "cp " + getDir() + "assets/main.cpp ./" + name + "/src";
        std::cout << line << '\n';
        std::system(line.c_str());
    }

    void Next::run()
    {
        std::string line;
        line += "./" + this->binary_dir + "/" + this->name_build;
        system(line.c_str());
    }
} // namespace NEXT::CPP::Linux
