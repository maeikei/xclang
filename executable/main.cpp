#include <iostream>
#include <cstdlib>
#include "driver.hpp"

//#define DEBUG_CMDLINE
int main(const int argc,const char *argv[])
{
#ifdef DEBUG_CMDLINE
    for(auto i = 0; i < argc  ;i++ )
    {
        cout << "argv=<" << argv[i] << ">" << endl;
    }
#endif
    xclang::XClangDriver driver(argc,argv);
    
    return driver.exce();
}
