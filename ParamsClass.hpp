#ifndef PARAMS_CLASS_HPP
#define PARAMS_CLASS_HPP

#include <vector>
#include <string>
#include <fstream>
#include <regex>
#include <thread>

class Params {
private:
	std::vector<std::string>	file_;
	std::string					mask_;

public:
	explicit Params(const std::string &fileName, const std::string &mask);
	std::string 				getMask() const;
	std::vector<std::string>	getFile() const;
};

#include "ParamsClass.ipp"

#endif