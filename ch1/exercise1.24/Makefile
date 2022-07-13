all: build

build:
	g++ exercise1.24.cpp -o exercise1.24

test: build
	cat book_sales | ./exercise1.24

clean:
	rm -rf exercise1.24
