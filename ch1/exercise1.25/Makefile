all: build

build:
	g++ exercise1.25.cpp -o exercise1.25

test: build
	cat book_sales | ./exercise1.25

clean:
	rm -rf exercise1.25
