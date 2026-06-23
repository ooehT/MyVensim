all: lib tests

lib:
	mkdir -p bin
	g++ -Wall -Wextra -std=c++11 -fPIC -shared src/*.cpp -I./src -o bin/libmodel.so

tests:
	g++ -Wall -Wextra -std=c++11 test/funcional/*.cpp -I./src -L./bin -lmodel -o bin/funcional_tests
	g++ -Wall -Wextra -std=c++11 test/unit/*.cpp -I./src -L./bin -lmodel -o bin/unit_tests

runFunctional:
	LD_LIBRARY_PATH=./bin ./bin/funcional_tests

runUnit:
	LD_LIBRARY_PATH=./bin ./bin/unit_tests

run: runFunctional runUnit

clean:
	rm -rf bin/