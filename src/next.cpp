#include <next.hpp>

namespace NEXT
{
    Next::Next(/* args */)
    {
    }

    Next::~Next()
    {
    }

    int Next::init(std::string_view file_dir)
    {
        std::ifstream file(file_dir.data());
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
        
        std::system("ls -R >.next");

        std::string line;
        std::string dir;
        std::ifstream source(".next");
        char caracter;
        if(source.is_open()){
            while(getline(source, line)){
                for (std::size_t i = 0; i < line.size(); i++)
                {
                    caracter = line[i];
                    if(caracter == '.'){
                        if(line[i + 1] == 'c'){
                            dir[dir.size() - 1] = '/';
                            //std::cout<<dir + line<<'\n';
                            
                            this->source_files.push_back(dir + line);
                            break;
                        }
                    }
                    if(caracter == '.'){
                        if(line[i + 1] == '/'){
                            dir = line;
                            break;
                        }
                    }
                }
                
                
            }
        }
    }
} // namespace NEXT
