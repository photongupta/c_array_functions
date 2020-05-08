#include "array_functions.h"
#include "list.h"
#include <stdio.h>

void display_int(Void_ptr num)

{
  printf("%d", *(int *)num);
  NEW_LINE;
}

int is_even(Void_ptr value)
{
  return !((*(int *)value) % 2);
}

int add_one(Void_ptr value)
{
  return (*(int *)value) + 1;
}

int main(void)
{
  int num1 = 4;
  int num2 = 5;
  int num3 = 6;
  List_ptr user_data = create_list();
  add_to_end(user_data, &num1);
  add_to_end(user_data, &num2);
  add_to_end(user_data, &num3);

  printf("INPUT LIST :\n");
  display_list(user_data, &display_int);

  Void_ptr even_list = filter(&is_even, user_data);
  printf("EVEN LIST :\n");
  display_list(even_list, &display_int);

  Void_ptr mapped_list = map(&add_one, user_data);
  printf("MAPPED LIST :\n");
  display_list(mapped_list, &display_int);

  return 0;
}