VPATH = src include
CPPFLAGS = -I include

vpath %.cpp src
vpath %.h include

prog: main.o start.o \
      learm.o HelloWorld.o \
      learm1.o
	g++ $^ -o $@
main.o: main.cpp prog.h
	g++ $(CPPFLAGS) -c $<
start.o: start.cpp prog.h
	g++ $(CPPFLAGS) -c $<
HelloWorld.o: HelloWorld.cpp prog.h
	g++ $(CPPFLAGS) -c $<
learm.o: learm.cpp prog.h
	g++ $(CPPFLAGS) -c $<
learm1.o: learm1.cpp prog.h
	g++ $(CPPFLAGS) -c $<

run: prog
	./prog
clean:
	rm -f prog *.o
.PHONY:
	run clean
