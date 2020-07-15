#pragma once

#include <string>
#include <fstream>
#include <picojson.hpp>
#include <vector>
#include <file_next.hpp>

namespace NEXT::Linux
{
    class Next
    {
    public:
        picojson::value::object root;

        inline static const std::string ls_and_write_files{"ls -Rl >.next/next"};
        inline static const std::string read_files_data{".next/next"};
        inline static const std::string get_dir{"pwd >.next/next"};

        std::string name_project;
        std::string name_build;
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
        std::vector<std::string> cc_flags;
        std::vector<std::string> c_flags;
        std::vector<std::string> libs_flags;
        std::vector<std::string> linker_dirs;

        std::vector<File> source;
        std::vector<std::string> source_files;

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

        static void removeSubstrs(std::string &s,
                           const std::string &p)
        {
            std::size_t n = p.length();

            for ( std::string::size_type i = s.find(p);
                 i != std::string::npos;
                 i = s.find(p))
                s.erase(i, n);
        }
    };

} // namespace NEXT::Linux
