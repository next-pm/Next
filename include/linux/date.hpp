#pragma once

#include <string>

#include <sstream>

int stringToInt(std::string num_string)
{
    std::stringstream num_int(num_string);
    int num = 0;
    num_int >> num;
    return num;
}

namespace NEXT::CPP::Linux
{
    class Date
    {
    private:
        std::string month;
        std::string day;
        std::string hour;

    public:
        Date(/* args */) {}
        Date(std::string month, std::string day, std::string hour) : month{month}, day{day}, hour{hour} {}
        ~Date() {}

        bool
        equal(Date &other)
        {
            if (stringToInt(this->day) == stringToInt(other.day))
            {
                std::string h1, h2;
                h1 += this->hour[0] + this->hour[1];
                h2 += other.hour[0] + other.hour[1];
                if (stringToInt(h1) == stringToInt(h2))
                {

                    h1.clear();
                    h2.clear();
                    h1 += this->hour[3] + this->hour[4];
                    h2 += other.hour[3] + other.hour[4];
                    if (stringToInt(h1) == stringToInt(h2))
                    {
                        return true;
                    }
                }
            }

            return false;
        }
    };

} // namespace NEXT::CPP::Linux
