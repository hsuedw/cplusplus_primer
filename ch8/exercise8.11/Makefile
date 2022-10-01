all:
	g++ exercise8.11_org.cpp -o exercise8.11_org
	g++ exercise8.11.cpp -o exercise8.11

clean:
	rm -rf exercise8.11_org exercise8.11

test: clean all
	@echo "---------- Test exercise8.11_org ---------------" 
	cat data.txt | ./exercise8.11_org
	@echo "---------- Test exercise8.11 ---------------" 
	cat data.txt | ./exercise8.11
