#include "list.h"
#include <stdio.h>

int increase_by_one(int value)
{
  return value + 1;
}

int is_even(int value)
{
  return !(value % 2);
}

int sum(int num1, int num2)
{
  return num1 + num2;
}

int main(void)
{
  List_ptr user_data = create_list();
  add_to_end(user_data, 1);
  add_to_end(user_data, 2);
  add_to_end(user_data, 3);
  add_to_end(user_data, 4);
  add_to_end(user_data, 5);
  List_ptr increamend_list = map(&increase_by_one, user_data);
  display_list(increamend_list);
  List_ptr even_list = filter(&is_even, user_data);
  display_list(even_list);
  int reduced_value = reduce(&sum, 0, user_data);
  printf("Result:\n");
  printf("%d", reduced_value);
  NEW_LINE;

  return 0;
}