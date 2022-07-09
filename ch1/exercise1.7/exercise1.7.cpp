/* 
 * comment pairs /*      */ cannot nest.
 * "cannot nest" is considered source code,
 * as this rest of the program
 */

int main()
{
    return 0;
}


#if 0
$ make clean all
rm -rf exercise1.7
g++ exercise1.7.cpp -o exercise1.7
exercise1.7.cpp:2:29: error: ‘cannot’ does not name a type
    2 |  * comment pairs /*      */ cannot nest.
      |                             ^~~~~~
make: *** [Makefile:2: all] Error 1
#endif
