/*
 * gc.c
 *
 */
#include <stdlib.h>
#include <stdio.h>

extern "C"
{
    void *__dso_handle()
    {
        printf("%s,%d\n",__FILE__,__LINE__);
        return 0;
    }
    int __cxa_atexit ( void (*f)(void *), void *p, void *d )
    {
        //	return atexit(f,p,d);
        return 0;
    }
} //extern "C"
