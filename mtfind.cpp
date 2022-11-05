#include <iostream> // all
#include "utils.hpp"
#include <regex>

void Search(const std::vector<std::string> &file, const std::string &mask) {
	std::regex reg(mask);
	std::smatch words;
	
	int x = 0;
	
	for (std::string s : file) {
		++x;
		while (std::regex_search (s, words, reg)) {
			std::cout << x << " ";
			std::cout << file[x - 1].find(words.str()) + 1 << " ";
			std::cout << words.str() << std::endl;
			s = words.suffix().str();
		}
	}
}

std::string getMask(std::string str) {
	int pos = 0;
	std::string mask = "([^ ]?)";
	return std::regex_replace(str, std::regex("\\?"), mask);
}

int main(int argc, char **argv) {
	if (argc < 3)
		throw "argc!";
	std::vector<std::string> file = utils::split(utils::readFile(argv[1]), '\n');
	std::string mask = getMask(argv[2]);
	Search(file, mask);
	return (0);
}
