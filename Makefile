all: stack queue LinkList

%: %.cc
	g++ -std=c++11 $< -o $@

%: %.c
	gcc $< -o $@

