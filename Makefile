all: stack queue LinkList recursion infix

%: %.cc
	g++ -std=c++11 $< -o $@

%: %.c
	gcc $< -o $@

