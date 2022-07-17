#include <iostream>

int main()
{
    /*
     * The statements in this program are valid.
     */
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i) {
        sum += i;   /* After this for-loop finishes, sum holds the summation from 0 to 9*/
    }

    /* 
     * The i is that defined before the for-loop rather than the one inside the for-loop.
     * Therefore, this statement prints 100 (the value held by variable i) 
     * and 45 (the value held by the variable sum).
     */
    std::cout << i << " " << sum << std::endl;
    return 0;
}
