all:
	mkdir -p bin
		g++ test/main.cpp test/funcional_test.cpp src/model.cpp src/flow.cpp src/exponential.cpp src/logistic.cpp src/System.cpp -o bin/programa

run:
	./bin/programa

clean:
	rm -f bin/programa