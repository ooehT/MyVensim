all: funcional unit

funcional:
	mkdir -p bin
	g++ test/funcional/*.cpp src/*.cpp -o bin/funcional_tests

unit:
	mkdir -p bin
	g++ test/unit/*.cpp src/*.cpp -o bin/unit_tests

run_funcional:
	./bin/funcional_tests

run_unit:
	./bin/unit_tests

clean:
	rm -rf bin/*