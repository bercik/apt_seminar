#include <iostream>

void panic(const std::string& panic_msg)
{
    std::cerr << panic_msg << "\n";
    exit(1);
}
