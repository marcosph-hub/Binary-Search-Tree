main: ./src/main.cc
	g++ -std=c++14 -Wall -o ./bin/arbol_binario ./src/main.cc ./src/clave.cc ./src/node.cc ./src/arbol_bin.cc ./src/claveNumber.cc 

clave.o: clave.cc
	g++ -std=c++14 -Wall -o ./bin/clave ./src/clave.cc

node.o: node.cc
	g++ -std=c++14 -Wall -o ./bin/node ./src/node.cc

arbol_bin.o: arbol_bin.cc
	g++ -std=c++14 -Wall -o ./bin/arbol_bin ./src/arbol_bin.cc

run:
	./bin/arbol_binario 

clean:
	rm -f arbol_binario *.o ./bin/*