SRC = mtfind.cpp ParamsClass.hpp

DELETE = a.exe ParamsClass.hpp.gch

all:
	g++ $(SRC) -O "mtfind"
	
run:
	./mtfind input.txt "?ad"
	
clean :
	rm -rf $(DELETE)
	
.PHONY: all clean run