#ifndef UTILS_HPP
#define UTILS_HPP

#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

namespace utils {
	std::string readFile(const std::string &);
	std::vector<std::string> split(const std::string &, const char &);
};

#endif