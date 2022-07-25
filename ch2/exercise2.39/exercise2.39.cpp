struct Foo { /* empty */ }  // Note: no semicolon
//struct Foo { /* empty */ }; // Note: fixed by append a semicolon

int main()
{
    return 0;
}

#if 0
$ make clean all
rm -rf exercise2.39
g++ exercise2.39.cpp -o exercise2.39
exercise2.39.cpp:1:27: error: expected ‘;’ after struct definition
    1 | struct Foo { /* empty */ }  // Note: no semicolon
      |                           ^
      |                           ;
make: *** [Makefile:2: all] Error 1
#endif
