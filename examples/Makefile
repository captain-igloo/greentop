CXX=g++

all:
	$(CXX) -o main -std=c++0x -I../include -L../lib main.cpp -lgreentop -ljsoncpp -lcurlpp
	$(CXX) -o get-account-statement -std=c++0x -I../include -L../lib getAccountStatement.cpp -lgreentop -ljsoncpp -lcurlpp

clean:
	rm main
