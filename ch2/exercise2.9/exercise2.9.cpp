#include <iostream>

int main() {
    //std::cin >> int input_value;
    /* (a)
     * g++ exercise2.9.cpp -o exercise2.9
     * exercise2.9.cpp: In function ‘int main()’:
     * exercise2.9.cpp:4:17: error: expected primary-expression before ‘int’
     *     4 |     std::cin >> int input_value;
     *       |                 ^~~
     * make: *** [Makefile:2: all] Error 1
     */
    int input_value;
    std::cin >> input_value;

    //int i = { 3.14 };
    /* (b)
     * g++ exercise2.9.cpp -o exercise2.9
     * exercise2.9.cpp: In function ‘int main()’:
     * exercise2.9.cpp:16:20: error: narrowing conversion of ‘3.1400000000000001e+0’ from ‘double’ to ‘int’ [-Wnarrowing]
     *    16 |     int i = { 3.14 };
     *       |                    ^
     * make: *** [Makefile:2: all] Error 1
     */
     double i = {3.14};

     //double salay = wage = 9999.99;
     /* (c)
      * g++ exercise2.9.cpp -o exercise2.9
      * exercise2.9.cpp: In function ‘int main()’:
      * exercise2.9.cpp:27:21: error: ‘wage’ was not declared in this scope
      *    27 |      double salay = wage = 9999.99;
      *       |                     ^~~~
      * make: *** [Makefile:2: all] Error 1
      */
      double salay = 9999.99;
      double wage = salay;

      //int a = 3.14;
      /* (d)
       * g++ -Wall exercise2.9.cpp -o exercise2.9
       * exercise2.9.cpp:39:11: warning: unused variable ‘a’ [-Wunused-variable]
       *    39 |       int a = 3.14;
       *       |           ^
       */
      double a = 3.14;

    return 0;
}
