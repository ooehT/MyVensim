all:
	g++ -I src -I test src/*.cpp test/*.cpp -o programa


run:
	./programa

clean:
	rm -f programa