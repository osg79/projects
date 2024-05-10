#include "my_strings/my_strings.h"

int main()
{
    std::string s0("This is my first string");
    char sC[] = "C string";

    //string constructors
    std::string s1;
    std::string s2(s0);
    std::string s3(s2, 1, 4);
    std::string s4(sC);
    std::string s5("C++ string");
    std::string s6(sC, 1);
    std::string s7(s0.begin(), s0.begin()+10);
    std::string* s8 = new std::string;
    *s8 = std::string("String in the heap");
    std::string* s9(s8);

    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;
    std::cout << "s3 = " << s3 << std::endl;
    std::cout << "s4 = " << s4 << std::endl;
    std::cout << "s5 = " << s5 << std::endl;
    std::cout << "s6 = " << s6 << std::endl;
    std::cout << "s7 = " << s7 << std::endl;
    std::cout << "s8 = " << *s8 << std::endl;
    std::cout << "s9 = " << *s9 << std::endl;
    delete s9;

    return 0;
}