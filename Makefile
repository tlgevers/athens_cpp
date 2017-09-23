all: stack queue

%: %.cc
	g++ -std=c++11 $< -o $@

%: %.c
	gcc $< -o $@

