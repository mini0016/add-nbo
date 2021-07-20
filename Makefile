#Makefile
all: add-nbo

add-nbo: add-nbo.pro

main.o: main.cpp

clean:
	rm -f add-nbo
	rm -f *.pro
