#include "utils.hpp"

std::string utils::readFile(const std::string &fileName) {
	std::ifstream ifs(fileName, std::ios::binary);
	std::string res;
	
	if (!ifs.is_open())
		throw "File not open!";
	std::copy(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>(), std::back_inserter(res));
	
	ifs.close();
	return res;
}

std::vector<std::string> utils::split(const std::string &s, const char &delimetr) {
	std::vector<std::string> res;
	std::stringstream str(s);
	std::string word;
	
	while (std::getline(str, word, delimetr))
		res.push_back(word);
	
	return res;
}