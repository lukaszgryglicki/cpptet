all: cpptet
cpptet: cpptet.cc
	c++ -O3 -o cpptet cpptet.cc -lm
	strip cpptet
clean:
	-rm cpptet

