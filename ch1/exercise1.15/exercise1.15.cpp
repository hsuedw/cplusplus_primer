#include <iostream>

int main() {

#if 0
    // error: used colon, not a semicolon, after endl.
    // exercise1.15.cpp: In function ‘int main()’:
    // exercise1.15.cpp:6:48: error: expected ‘;’ before ‘:’ token
    //    6 |     std::cout << "Read each file." << std::endl:
    //      |                                                ^
    //      |                                                ;
    std::cout << "Read each file." << std::endl:
#endif

#if 0
    // error: missing quotes around string literal
    // exercise1.15.cpp: In function ‘int main()’:
    // exercise1.15.cpp:6:48: error: expected ‘;’ before ‘:’ token
    //    6 |     std::cout << "Read each file." << std::endl:
    //      |                                                ^
    //      |                                                ;
    std::cout << Update master. << std::endl;
#endif

#if 0
    // error: second output operator is missing
    // exercise1.15.cpp: In function ‘int main()’:
    // exercise1.15.cpp:22:37: error: expected ‘;’ before ‘std’
    //   22 |     std::cout << "Write new master." std::endl;
    //      |                                     ^~~~
    //      |
    std::cout << "Write new master." std::endl;
#endif

#if 0
    // error: missing ; on return statement
    // exercise1.15.cpp: In function ‘int main()’:
    // exercise1.15.cpp:30:13: error: expected ‘;’ before ‘int’
    //   30 |     return 0
    //      |             ^
    //      |             ;
    //   31 | 
    //   32 |     int sum = 0, value = 0;
    //      |     ~~~      
    return 0
#endif

    int sum = 0, value = 0;
    // read until end-of-file, calculating a running total of all values read
    // enter text to cause error in input.
    // $ ./exercise1.15
    // abc
    // Sum is: 0
    while (std::cin >> value) {
        sum += value;
    }
    std::cout << "Sum is: " << sum << std::endl;

#if 0
    int v1 = 0, v2 = 0;
    std::cin >> v >> v2; // error: user "v" not "v1"
    // exercise1.15.cpp: In function ‘int main()’:
    // exercise1.15.cpp:52:17: error: ‘v’ was not declared in this scope; did you mean ‘v2’?
    //   52 |     std::cin >> v >> v2; // error: user "v" not "v1"
    //      |                 ^
    //      |                 v2

    // error: cout not defined; should be std::cout
    // g++ exercise1.15.cpp -o exercise1.15
    // exercise1.15.cpp: In function ‘int main()’:
    // exercise1.15.cpp:60:5: error: ‘cout’ was not declared in this scope; did you mean ‘std::cout’?
    //    60 |     cout << v1 + v2 << std::endl;
    //       |     ^~~~
    //       |     std::cout
    // In file included from exercise1.15.cpp:1:
    // /usr/include/c++/9/iostream:61:18: note: ‘std::cout’ declared here
    //    61 |   extern ostream cout;  /// Linked to standard output
    //       |                  ^~~~
    cout << v1 + v2 << std::endl;
#endif

    return 0;
}
