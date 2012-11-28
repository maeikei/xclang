#include <iostream>
#include <cstdlib>
#include "driver.hpp"
int main(const int argc,const char *argv[])
{
    xclang::XClangDriver driver(argc,argv);
    return driver.exce();
}
