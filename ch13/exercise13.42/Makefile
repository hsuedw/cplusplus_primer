all:
	g++ -c StrVec.cpp -o StrVec.o
	g++ -c TextQuery.cpp -o TextQuery.o
	g++ -c exercise13.42.cpp -o exercise13.42.o
	g++ StrVec.o TextQuery.o exercise13.42.o -o main

clean:
	rm -rf *.o
	rm -rf main

