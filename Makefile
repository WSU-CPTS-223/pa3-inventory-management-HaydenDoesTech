out: clean compile execute

compile: main.cpp
	g++ -g -Wall -std=c++14 main.cpp HashData.cpp InventoryWrapper.cpp -o mainexe

execute: mainexe
	./mainexe

clean:
	rm -f mainexe