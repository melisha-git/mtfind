SRC = mtfind.cpp SearcherClass.hpp

DELETE = a.exe SearcherClass.hpp.gch

all:
	g++ -std=c++14 $(SRC) -O "mtfind"
	
run:
	./mtfind input.txt "?a?d"
	
clean :
	rm -rf $(DELETE)
	
.PHONY: all clean run