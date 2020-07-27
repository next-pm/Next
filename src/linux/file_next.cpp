#include <linux/file_next.hpp>

#include <linux/date.hpp>

namespace NEXT::CPP::Linux
{
    File::File(/* args */)
    {
    }

    File::File(picojson::object root)
    {
        this->permissions = picojson::find<std::string>("permissions", root);
        this->type = picojson::find<std::string>("type", root);
        this->owner = picojson::find<std::string>("owner", root);
        this->size = picojson::find<std::string>("size", root);
        this->name = picojson::find<std::string>("name", root);
        this->date = picojson::find<std::string>("date", root);
    }

    File::~File()
    {
    }

    picojson::value File::toJson()
    {
        picojson::object data;
        data["permissions"] = picojson::value(this->permissions);
        data["type"] = picojson::value(this->type);
        data["owner"] = picojson::value(this->owner);
        data["size"] = picojson::value(this->size);
        data["date"] = picojson::value(this->date);
        data["name"] = picojson::value(this->name);

        return picojson::value(data);
    }

    void File::decode(std::string data, std::string dir_relative)
    {
        std::string line;
        line.reserve(100);
        std::vector<std::string> lines;
        lines.reserve(10);
        for (std::size_t i = 0; i < data.size(); i++)
        {
            if (data[i] == ' ')
            {
                data[i] = ',';
            }
        }
        for (std::size_t i = 0; i < data.size(); i++)
        {
            if (data[i] != ',')
            {
                line.push_back(data[i]);
            }
            else
            {
                if (line.size() > 0)
                {
                    lines.push_back(line);
                    line.clear();
                    line.reserve(100);
                }

                continue;
            }
        }
        lines.push_back(line);

        this->permissions = lines[0];
        this->type = lines[1];
        this->owner = lines[2];
        this->size = lines[4];
        this->date = lines[5] + lines[6];
        this->name = dir_relative + "/" + lines[8];
    }

    bool File::equal(File &other)
    {
        return this->date == other.date;
    }

    void File::print()
    {
        std::cout << this->permissions << '\n';
        std::cout << this->type << '\n';
        std::cout << this->owner << '\n';
        std::cout << this->size << '\n';
        std::cout << this->date << '\n';
        std::cout << this->name << '\n';
    }
} // namespace NEXT::CPP::Linux
