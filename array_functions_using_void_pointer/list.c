#include "list.h"
#include <stdio.h>
#include <stdlib.h>

Node_ptr create_node(Void_ptr data)
{
  Node_ptr node = malloc(sizeof(Node));
  node->value = data;
  node->next = NULL;
  return node;
}

List_ptr create_list()
{
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Bool add_to_end(List_ptr list, Void_ptr value)
{

  Node_ptr new_node = create_node(value);
  if (new_node == NULL)
    return False;
  if (list->head == NULL)
    list->head = new_node;
  else
    list->last->next = new_node;
  list->last = new_node;
  list->count += 1;
  return True;
}