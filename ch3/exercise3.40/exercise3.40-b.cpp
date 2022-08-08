#include <cstring>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    const char s1[] = "Hello ";
    const char s2[] = "world";
    const auto len = strlen(s1) + strlen(s2) + 1;
    char s3[len];

    strcpy(s3, s1);
    strcat(s3 + strlen(s1), s2);
    s3[len - 1] = '\0';
    cout << "s3: " << s3 << endl;
    cout << "length of s3: " << strlen(s3) << endl;
    cout << "size of s3: " << sizeof(s3) << endl;

    return 0;
}
