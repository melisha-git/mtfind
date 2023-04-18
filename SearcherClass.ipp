#ifndef SEARCHER_CLASS_IPP
#define SEARCHER_CLASS_IPP

#include "SearcherClass.hpp"

// Constructor
Searcher::Searcher(const std::string &fileName, const std::string &mask) : mask_(mask) {
	std::ifstream ifs(fileName);
	this->_regexMask();

	if (!ifs.is_open())
		throw "File not open!";
     	for (int i = 0; i <= 7; ++i)
	    	(this->pthreads_).push_back(std::thread(&Searcher::_search, this, std::ref(ifs)));
    	for (int i = 0; i <= 7; ++i)
	    	(this->pthreads_[i]).join();
     	ifs.close();
}

//print result
void Searcher::printSubstrings() const {
    std::cout << this->result_.size() << std::endl;
    for (std::pair<std::pair<int, int>, std::string> s : this->result_) {
        std::cout << s.second << std::endl;
    }
}

//get modified mask
std::string Searcher::getMask() const {
	return this->mask_;
}

// private
// search substrings
void Searcher::_search(std::ifstream &ifs) {
	static int countStr = 0;
	std::string substring;
	std::smatch match;

	while (1) {
	    this->lock_.lock();
	    if (!(std::getline(ifs, substring, '\n'))) {
	        this->lock_.unlock();
		    break ;
	    }
	    int x = ++countStr;
	    this->lock_.unlock();
	    int count = 0;
	    while (std::regex_search (substring, match, std::regex(this->mask_))) {
		    count += substring.find(match.str());
		    this->result_[std::pair<int, int>(x, count + 1)] = std::to_string(x) +  " " + 
		    std::to_string(count + 1) + " " + match.str();
		    substring = match.suffix().str();
	    }
	}
}

// modified mask
void Searcher::_regexMask() {
	this->mask_ = std::regex_replace(this->mask_, std::regex("\\?"), "([^ ]?)");
}

#endif
