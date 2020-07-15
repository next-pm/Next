#include <file_next.hpp>

namespace NEXT::Linux
{
    File::File(/* args */)
    {
    }

    File::~File()
    {
    }

    void File::decode(std::string data)
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
        this->month = lines[5];
        this->day = lines[6];
        this->hour = lines[7];
        this->name = lines[8];
    }
} // namespace NEXT::Linux
