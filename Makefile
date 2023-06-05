CC			:= g++

.PHONY: all clean

all: maszynaTuringa.x

%.x: %.cpp
	$(CC) -o $@ $< main.cpp -std=c++11

clean:
	rm -f *.o *.x

maszynaTuringa.x: maszynaTuringa.cpp main.cpp