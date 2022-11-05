#include <iostream>
#include "ParamsClass.hpp"

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

int main(int argc, char **argv) {
	if (argc < 3)
		throw "argc!";
	Params params(argv[1], argv[2]);
	Search(params.getFile(), params.getMask());
	return (0);
}
