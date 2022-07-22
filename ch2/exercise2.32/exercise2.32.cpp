int main()
{
    //int null = 0, *p = null;
    // g++ exercise2.32.cpp -o exercise2.32
    // exercise2.32.cpp: In function ‘int main()’:
    // exercise2.32.cpp:3:24: error: invalid conversion from ‘int’ to ‘int*’ [-fpermissive]
    //     3 |     int null = 0, *p = null;
    //       |                        ^~~~
    //       |                        |
    //       |                        int
    // make: *** [Makefile:2: all] Error 1

    //int null = 0, *ptr = nullptr;   // OK
    //int null = 0, *ptr = 0;         // OK
    int null = 0, *ptr = &null;       // OK

    return 0;
}
