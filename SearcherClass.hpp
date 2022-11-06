#ifndef SEARCHER_CLASS_HPP
#define SEARCHER_CLASS_HPP

#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <regex>
#include <thread>
#include <mutex>

class Searcher {
private:
    std::map<std::pair<int, int>, std::string > result_;
	std::string					mask_;
	std::vector<std::thread>    pthreads_;
    std::mutex                  lock_;
public:
	explicit Searcher(const std::string &fileName, const std::string &mask);
	void                        printSubstrings() const;
	std::string 				getMask() const;
	
private:
	void _search(std::ifstream &ifs);
	void _regexMask();
};

#include "SearcherClass.ipp"

#endif