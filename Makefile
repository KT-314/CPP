VPATH = src include
GCC_OPTIONS =-std=c++17 -Wall --pedantic-errors -I include

vpath %.cpp src
vpath %.h include

prog: main.o start.o \
      learm.o HelloWorld.o HelloWorld1.o String.o IntDouble.o Variable.o FunctionLambda.o \
      learm1.o Operator1.o Operator2.o \
      learm2.o ContainerArray.o
	g++ $^ -o $@
prog.h.gch: prog.h
	g++ $(gcc_options) -x c++-header -o $@ $<
main.o: main.cpp prog.h prog.h.gch
	g++ $(GCC_OPTIONS) -c $<
start.o: start.cpp prog.h
	g++ $(GCC_OPTIONS) -c $<
learm.o: learm.cpp prog.h
	g++ $(GCC_OPTIONS) -c $<
learm1.o: learm1.cpp prog.h
	g++ $(GCC_OPTIONS) -c $<
learm2.o: learm2.cpp prog.h
	g++ $(GCC_OPTIONS) -c $<
HelloWorld.o: learm/HelloWorld.cpp prog.h
	g++ $(GCC_OPTIONS) -c $<
HelloWorld1.o: learm/HelloWorld1.cpp prog.h
	g++ $(GCC_OPTIONS) -c $<
String.o: learm/String.cpp prog.h
	g++ $(GCC_OPTIONS) -c $<
IntDouble.o: learm/IntDouble.cpp prog.h
	g++ $(GCC_OPTIONS) -c $<
Variable.o: learm/Variable.cpp prog.h
	g++ $(GCC_OPTIONS) -c $<
FunctionLambda.o: learm/FunctionLambda.cpp prog.h
	g++ $(GCC_OPTIONS) -c $<
Operator1.o: learm1/Operator1.cpp prog.h
	g++ $(GCC_OPTIONS) -c $<
Operator2.o: learm1/Operator2.cpp prog.h
	g++ $(GCC_OPTIONS) -c $<
ContainerArray.o: learm2/ContainerArray.cpp prog.h
	g++ $(GCC_OPTIONS) -c $<

run: prog
	./prog
clean:
	rm -f prog *.o
	rm -f ./prog.h.gch
.PHONY:
	run clean
