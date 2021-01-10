VPATH = src include
CPPFLAGS = -I include

vpath %.cpp src
vpath %.h include

prog: main.o start.o learm.o
	g++ $^ -o $@
main.o: main.cpp prog.h
	g++ $(CPPFLAGS) -c $<
start.o: start.cpp prog.h
	g++ $(CPPFLAGS) -c $<
learm.o: learm.cpp learm.h menu.h
	g++ $(CPPFLAGS) -c $<

run: prog
	./prog
clean:
	rm -f prog *.o
.PHONY:
	run clean
