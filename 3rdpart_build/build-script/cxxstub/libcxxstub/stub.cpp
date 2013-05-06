extern "C" {

#include <stdlib.h>
#include <unwind.h>

/* These programs do not use thread cancellation, so _Unwind_Resume
   and the personality routine are never actually called.  */

void
_Unwind_Resume (struct _Unwind_Exception *exc __attribute__ ((unused)))
{
  abort ();
}

_Unwind_Reason_Code
__gcc_personality_v0 (int version __attribute__ ((unused)),
		      _Unwind_Action actions __attribute__ ((unused)),
		      _Unwind_Exception exception_class
		      __attribute__ ((unused)),
		      struct _Unwind_Exception *ue_header
		      __attribute__ ((unused)),
		      struct _Unwind_Context *context __attribute__ ((unused)))
{
  abort ();
}


void *__dso_handle = NULL; 

} // extern "C"