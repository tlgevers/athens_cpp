all: tree read_program test

%: %.cc
	g++ -std=c++11 $< -o $@

%: %.c
	gcc $< -o $@

