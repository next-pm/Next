#pragma once

#include <string>
#include <fstream>
#include <iostream>

#if defined(_WIN32)

std::string exec(std::string command)
{
}

#elif defined(__linux)

std::string exec(std::string command);

#endif