all:
	mkdir -p bin
	g++ -I src -I test src/*.cpp test/*.cpp -o bin/programa

run:
	./bin/programa

clean:
	rm -f bin/programa