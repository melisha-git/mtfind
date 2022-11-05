#ifndef PARAMS_CLASS_IPP
#define PARAMS_CLASS_IPP

#include "ParamsClass.hpp"

void _regexMask(std::string &mask) {
	mask = std::regex_replace(mask, std::regex("\\?"), "([^ ]?)");
}

Params::Params(const std::string &fileName, const std::string &mask) : mask_(mask) {
	// TODO Добавить многопоточность
	std::thread maskThread(_regexMask, std::ref(this->mask_));
	this->_readFile(fileName);
	//maskThread.join();
	
}

std::string Params::getMask() const {
	return this->mask_;
}

std::vector<std::string> Params::getFile() const {
	return this->file_;
}

void Params::_readFile(const std::string &fileName) {
		std::ifstream ifs(fileName);
		std::string word;
	
		if (!ifs.is_open())
			throw "File not open!";
		while (std::getline(ifs, word, '\n'))
			this->file_.push_back(word);
	
		ifs.close();
}

#endif