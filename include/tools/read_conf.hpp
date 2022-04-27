#pragma once

#include <picojson.hpp>

#include <termcolor.hpp>

#include <next_data.hpp>

#include <fstream>

#include <cassert>

#include <string>

#include <sstream>

#include <tools/exec.hpp>

int read_conf();

int readString(std::string key, std::string &data, picojson::object &root);

int readVector(std::string key, std::vector<std::string> &data, picojson::object &root);