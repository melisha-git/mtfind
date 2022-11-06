#include <iostream>
#include "SearcherClass.hpp"
#include <ctime>

int main(int argc, char **argv) {
    if (argc != 3)
        throw "No arguments";
    unsigned int start_time =  clock();
	Searcher searcher1(argv[1], argv[2]);
	unsigned int end_time = clock();
	searcher1.printSubstrings();
	
	unsigned int search_time = end_time - start_time;
	
	search_time += end_time - start_time;
	
	std::cout << (search_time / 1000.0) / 3;
	return (0);
}