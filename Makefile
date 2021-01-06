CPPFLAGS = -I include

prog: main.o start.o
	g++ $^ -o $@

main.o: main.cpp prog.h
	g++ $(CPPFLAGS) -c $<
start.o: start.cpp prog.h
	g++ $(CPPFLAGS) -c $<

run: prog
	./prog

clean:
	rm -f prog *.o

.PHONY:
	run clean
