#include "array_functions.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List_ptr filter(Func_int_ptr predicate, List_ptr list)

{
  List_ptr filtered_list = create_list();
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    if (predicate(p_walk->value))
      add_to_end(filtered_list, p_walk->value);
    p_walk = p_walk->next;
  }
  return filtered_list;
}

List_ptr map(Func_int_ptr mapper, List_ptr list)
{
  List_ptr mapped_list = create_list();
  Int_ptr temp = malloc(sizeof(int) * list->count);
  Node_ptr p_walk = list->head;
  for (int index = 0; p_walk != NULL; index++)
  {
    temp[index] = mapper(p_walk->value);
    add_to_end(mapped_list, temp + index);
    p_walk = p_walk->next;
  }
  return mapped_list;
}

Void_ptr reduce(Func_int_ptr reducer, Void_ptr context, List_ptr list)
{
  Void_ptr result = malloc(sizeof(context));
  result = context;
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    *(result) = reducer(p_walk->value, context);
    p_walk = p_walk->next;
  }
  return result;
}
