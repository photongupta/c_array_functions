#include "list.h"
#include <stdio.h>

void display_node(Node_ptr node, Func_void_ptr displayer)
{
  (*displayer)(node->value);
}

void display_list(List_ptr list, Func_void_ptr displayer)
{
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    display_node(p_walk, displayer);
    p_walk = p_walk->next;
  }
  NEW_LINE;
}
