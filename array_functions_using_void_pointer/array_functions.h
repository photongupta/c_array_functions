#ifndef __ARRAY_FUNCTIONS_H
#define __ARRAY_FUNCTIONS_H

#include "list.h"

List_ptr filter(Func_int_ptr, List_ptr);
List_ptr map(Func_int_ptr, List_ptr);
Void_ptr reduce(Func_int2_ptr, Void_ptr, List_ptr);

#endif