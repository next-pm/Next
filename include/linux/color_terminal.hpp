#ifndef COLOR_TERMINAL
#define COLOR_TERMINAL

#include <string>
#include <iostream>

namespace NEXT
{
    class Color
    {
    private:
        std::string code;

    public:
        const std::string getCode() const  { return code; }
        Color(std::string code) : code{code} {}
        Color() {}
        ~Color() {}
    };

    class Colors
    {
    public:
        inline static const Color reset = Color("\033[0m");
        inline static const Color black = Color("\033[30m");
        inline static const Color red = Color("\033[31m");
        inline static const Color green = Color("\033[32m");
        inline static const Color yellow = Color("\033[33m");
        inline static const Color blue = Color("\033[34m");
        inline static const Color magenta = Color("\033[35m");
        inline static const Color cyan = Color("\033[36m");
        inline static const Color white = Color("\033[37m");
        inline static const Color boldblack = Color("\033[1m\033[30m");
        inline static const Color boldred = Color("\033[1m\033[31m");
        inline static const Color boldgreen = Color("\033[1m\033[32m");
        inline static const Color boldyellow = Color("\033[1m\033[33m");
        inline static const Color boldblue = Color("\033[1m\033[34m");
        inline static const Color boldmagenta = Color("\033[1m\033[35m");
        inline static const Color boldcyan = Color("\033[1m\033[36m");
        inline static const Color boldwhite = Color("\033[1m\033[37m");
    };

    //class Fla
    static void Print(std::string text, Color color)
    {
        std::cout<<color.getCode()<<text<<Colors::reset.getCode();
    }
} // namespace Next

#endif