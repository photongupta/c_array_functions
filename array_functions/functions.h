#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

#define NEW_LINE printf("\n")

typedef int *Int_ptr;

typedef struct Dynamic_array
{
  Int_ptr numbers;
  int length;
} Dynamic_array;

typedef Dynamic_array *Dynamic_array_ptr;

typedef int (*Mapper)(int);
typedef int (*Predicate)(int);
typedef int (*Reducer)(int, int);

Dynamic_array_ptr create_dinamic_array(int length);
void print_numbers(Dynamic_array *numbers);
Dynamic_array_ptr map(Mapper,Dynamic_array_ptr);
Dynamic_array_ptr filter(Predicate,Dynamic_array_ptr);
int reduce(Reducer,int,Dynamic_array_ptr);

#endif