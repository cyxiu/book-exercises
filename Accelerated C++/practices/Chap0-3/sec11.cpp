
//input
#include <iostream>
#include <string>

int main()
{
    const std::string hello = "Hello, ";
    const std::string message = hello + "World" + "!";

    const std::string exclam = "!a";
    //WRONG! + can not be used on two string literals
    //const std::string message2 = "Hello," + "World" + exclam;

    std::cout << hello << std::endl;
    std::cout << message << std::endl;
    std::cout << exclam << std::endl;
    //std::cout << message2 << std::endl;

    return 0;
}
