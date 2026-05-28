all:
	mkdir -p bin
	g++ test/*.cpp src/*.cpp -o bin/programa
run:
	./bin/programa

clean:
	rm -f bin/programa