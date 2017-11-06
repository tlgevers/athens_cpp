all: tree read_program test recursion scratcha 

%: %.cc
	g++ -std=c++11 $< -o $@

%: %.c
	gcc $< -o $@

