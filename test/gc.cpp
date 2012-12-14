/*
 * gc.c
 *
 */
#include <stdlib.h>

/*void *__dso_handle()
 {
 printf("%s,%d\n",__FILE__,__LINE__);
 return 0;
 }
 */
const void *const __dso_handle __attribute__ ((__visibility__ ("hidden")))
= &__dso_handle;
int __cxa_atexit ( void (*f)(void *), void *p, void *d )
{
    //	return atexit(f,p,d);
    return 0;
}
int
__cxa_atexit (void (*func) (void *), void *arg, void *d)
{
    struct exit_function *new_exit = __new_exitfn ();
    
    if (new_exit == NULL)
        return -1;
    
#ifdef PTR_MANGLE
    PTR_MANGLE (func);
#endif
    new_exit->func.cxa.fn = (void (*) (void *, int)) func;
    new_exit->func.cxa.arg = arg;
    new_exit->func.cxa.dso_handle = d;
    atomic_write_barrier ();
    new_exit->flavor = ef_cxa;
    return 0;
}