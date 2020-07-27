#pragma once

#include <string>
#include <fstream>
#include <picojson.hpp>
#include <vector>
#include <linux/file_next.hpp>
#include <linux/color_terminal.hpp>

namespace NEXT::CPP::Linux
{
    class Next
    {
    public:
        picojson::value::object root;

        const std::string ls_and_write_files{"ls --full-time -R >.next"};
        const std::string read_files_data{".next"};
        const std::string get_dir{"pwd >.next"};

        std::string name_project;
        std::string name_build;
        std::string test_bin;
        std::string version_build;
        std::string language;
        std::string version_language;
        std::string compiler_CC;
        std::string compiler_C;
        std::string main_file;
        std::string test_file;
        std::string source_dir;
        std::string test_dir;
        std::string object_dir;
        std::string binary_dir;
        std::string include_dir;
        std::string libs_dir;
        std::string lib;
        std::vector<std::string> cc_flags;
        std::vector<std::string> c_flags;
        std::vector<std::string> libs_flags;
        std::vector<std::string> libs_test;
        std::vector<std::string> linker_dirs;
        inline static const std::string file_key{".180088743_7897716735_2294266832"};

        std::vector<File> source;
        std::vector<File> source_last;
        std::vector<std::string> source_files;
        std::vector<std::string> test_files;
        std::vector<std::string> source_obj;
        std::vector<std::string> test_obj;

    public:
        Next(/* args */);
        ~Next();

        int init(std::string file);

        template <typename Type>
        Type find(std::string object)
        {
            auto value = this->root.find(object);
            if (value != this->root.end())
            {
                if (value->second.is<Type>())
                {
                    return value->second.get<Type>();
                }
            }
            return Type();
        }

        void get_all_source();

        void get_all_source_test();

        void test();

        static void removeSubstrs(std::string &s,
                                  const std::string &p)
        {
            std::size_t n = p.length();

            for (std::string::size_type i = s.find(p);
                 i != std::string::npos;
                 i = s.find(p))
                s.erase(i, n);
        }

        static bool replace(std::string &str, const std::string &from, const std::string &to)
        {
            size_t start_pos = str.find(from);
            if (start_pos == std::string::npos)
                return false;
            str.replace(start_pos, from.length(), to);
            return true;
        }

        void compile_file(std::string file, int num, bool test = false, bool compile = true);

        void generate_dir(std::string file);

        void linker_files();

        void linker_files_test();

        void build_all();

        void build();

        void generate_lib();

        void run();

        void run_test();

        void create(std::string name);

        int help()
        {
            std::string line;
            std::system("find /home -name help.next >.next");
            std::ifstream source_dir(Next::read_files_data.c_str());
            std::string dir;
            getline(source_dir, dir);
            std::string helpFile;
            helpFile += dir.c_str();
            std::ifstream myfile(helpFile.c_str());
            if (myfile.is_open())
            {
                while (getline(myfile, line))
                {
                    std::cout << line << '\n';
                }
                myfile.close();
            }
            else
                std::cout << "Unable to open file";

            remove(Next::read_files_data.c_str());
            return 0;
        }

        std::string getDir()
        {

            std::string line;

            line += "find /home -name " + Next::file_key;
            line += " >.next";
            std::system(line.c_str());

            std::ifstream dir(Next::read_files_data.c_str());
            getline(dir, line);
            Next::removeSubstrs(line, Next::file_key);
            remove(Next::read_files_data.c_str());
            return line;
        }

        void writeFiles()
        {
            picojson::array list;
            for (auto f : this->source)
            {
                if (f.name.find(".cpp") != std::string::npos || f.name.find(".c") != std::string::npos)
                {
                    list.push_back(f.toJson());
                }
            }
            picojson::value::object write;
            picojson::value data = picojson::value(list);
            write["files"] = data;

            std::ofstream file("history.json");

            std::string str = "\\/";

            std::string object = picojson::value(write).serialize();
            while(this->replace(object, str, "/"));
            file << object;
        }

        void readFiles()
        {
            std::ifstream file("history.json");
            if (!file)
            {
                return;
            }

            picojson::value json;

            file >> json;

            file.close();
            auto root = json.get<picojson::object>();
            picojson::value list_root = picojson::value(root);
            auto list = list_root.get("files").get<picojson::array>();

            for (picojson::array::iterator iter = list.begin(); iter != list.end(); ++iter)
            {
                auto a = (*iter).get<picojson::object>();
                this->source_last.push_back(File(a));
            }
        }

        bool compareFile(File file){
            for(auto f : this->source_last){
                if(f.name == file.name){
                    if(!file.equal(f)){
                        return true;
                    }
                }
            }
            return false;
        }
    };

} // namespace NEXT::CPP::Linux
