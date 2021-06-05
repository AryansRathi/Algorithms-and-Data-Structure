 p1: a1.cpp
	g++ -Wall -o p1 a1.cpp

p2: testStack.cpp
	g++ -Wall -o p2 testStack.cpp

p4: a4.cpp
	g++ -Wall -o p4 a4.cpp

p5: a5.cpp
	g++ -Wall -o p5 a5.cpp

all: p1 p2 p4 p5

clean:
	rm p1 p2 p4 p5