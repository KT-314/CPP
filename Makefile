CPPFLAGS = -I include

prog: main.o
	g++ $^ -o $@

main.o: main.cpp
	g++ $(CPPFLAGS) -c $<

run: prog
	./prog

clean:
	rm -f prog *.o

.PHONY:
	run clean
