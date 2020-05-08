#ifndef __LIST_H
#define __LIST_H

#define NEW_LINE printf("\n")

typedef enum Bool
{
  False,
  True
} Bool;

typedef void *Void_ptr;

typedef int *Int_ptr;
typedef void *Void_ptr;
typedef void (*Func_void_ptr)(Void_ptr);
typedef int (*Func_int_ptr)(Void_ptr);
typedef int (*Func_int2_ptr)(Void_ptr, Void_ptr);
typedef Bool (*Func_Bool_ptr)(int, int);

typedef struct Node
{
  Int_ptr value;
  struct Node *next;
} Node;

typedef Node *Node_ptr;

typedef struct List
{
  Node_ptr head;
  Node_ptr last;
  int count;
} List;

typedef List *List_ptr;

Node_ptr create_node(Void_ptr data);
List_ptr create_list();
Bool add_to_end(List_ptr list, Void_ptr value);

void display_list(List_ptr list, Func_void_ptr displayer);
void display_node(Node_ptr node, Func_void_ptr displayer);
void display_int(Void_ptr num);

#endif
