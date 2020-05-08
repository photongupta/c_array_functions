
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List_ptr map(Func_int_ptr mapper, List_ptr list)

{
  List_ptr mapped_list = create_list();
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    add_to_end(mapped_list, mapper(p_walk->value));
    p_walk = p_walk->next;
  }
  return mapped_list;
}

List_ptr filter(Func_int_ptr predicate, List_ptr list)

{
  List_ptr filtered_list = create_list();
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    if (predicate(p_walk->value))
    {
      add_to_end(filtered_list, p_walk->value);
    }
    p_walk = p_walk->next;
  }
  return filtered_list;
}

int reduce(Func_int2_ptr reducer, int context, List_ptr list)
{
  int result = context;
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    int value = p_walk->value;
    result = reducer(result, value);
    p_walk = p_walk->next;
  }
  return result;
}
