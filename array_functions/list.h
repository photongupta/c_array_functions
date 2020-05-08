#ifndef __LIST_H
#define __LIST_H

#define NEW_LINE printf("\n")
#define EXIT 'm'

typedef enum
{
  Failure,
  Success
} Status;

typedef struct node
{
  int value;
  struct node *next;
} Node;

typedef Node *Node_ptr;

typedef struct
{
  Node *head;
  Node *last;
  int count;
} List;
typedef int (*Func_int_ptr)(int);
typedef int (*Func_int2_ptr)(int,int);

typedef List *List_ptr;
int enter_number(void);
Node_ptr create_node(int value);
List_ptr create_list(void);

List_ptr map(Func_int_ptr mapper, List_ptr list);
List_ptr filter(Func_int_ptr predicate, List_ptr list);
int reduce(Func_int2_ptr reducer, int context, List_ptr list);


void display_list(List_ptr);

Status add_to_end(List_ptr, int value);

void destroy_list(List_ptr); // Frees the elements and the list structure from memory

#endif