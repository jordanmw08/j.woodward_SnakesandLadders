CPPFLAGS=--std=gnu++11 -g
CC=g++
LD=g++

snakesandladders: snakesandladders.o
	g++ $(CPPFLAGS) -o snakesandladders  $^
clean:
	rm -f *.o snakesandladders