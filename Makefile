all: tree read_program

%: %.cc
	g++ -std=c++11 $< -o $@

%: %.c
	gcc $< -o $@

