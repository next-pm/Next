#include <string>
#include <thread>

#include <next.hpp>

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
                if (line.find(".cpp") != std::string::npos){
                    //this->source_files.push_back(dir_relative + "/" + line);
                    //std::cout<<dir_relative + "/" + line<<'\n';
                }
                    
                if( line.find("./") == std::string::npos && 
                    line.find("total ") == std::string::npos &&
                    line.find(".:") == std::string::npos &&
                    line.size() > 0){
                    File file;
                    file.decode(line);
                    if(file.name.find(".cpp") != std::string::npos){
                        this->source_files.push_back(dir_relative + "/" + file.name);
                        //std::cout<<dir_relative + "/" + file.name<<'\n';
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
} // namespace NEXT::Linux
