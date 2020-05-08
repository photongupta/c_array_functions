#ifndef __ARRAY_FUNCTIONS_H
#define __ARRAY_FUNCTIONS_H

#include "list.h"

List_ptr filter(Func_int_ptr, List_ptr);
List_ptr map(Func_int_ptr, List_ptr);
int reduce(Func_void_ptr, List_ptr);

#endif