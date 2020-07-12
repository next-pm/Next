#ifndef NEXT_HPP
#define NEXT_HPP

#include <string>
#include <string_view>
#include <fstream>
#include <picojson.hpp>
#include <vector>
#include <filesystem>

namespace NEXT
{
    class Next
    {
    public:
        picojson::value::object root;

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
        std::vector<std::string> source_files;

    public:
        Next(/* args */);
        ~Next();

        int init(std::string_view file);

        template <typename Type>
        Type find(std::string_view object)
        {
            auto value = this->root.find(object.data());
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
    };

} // namespace NEXT

#endif