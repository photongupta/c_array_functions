#include "functions.h"
#include <stdio.h>

int add_one(int value)
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
  Dynamic_array_ptr user_data = create_dinamic_array(6);
  user_data->numbers[0] = 1;
  user_data->numbers[1] = 2;
  user_data->numbers[2] = 3;
  user_data->numbers[3] = 4;
  user_data->numbers[4] = 5;
  user_data->length = 5;
  printf("Given list :");
  print_numbers(user_data);
  NEW_LINE;

  printf("Mapped list(add one):");
  Dynamic_array_ptr mapped_list = map(&add_one, user_data);
  print_numbers(mapped_list);
  NEW_LINE;

  printf("Even list :");
  Dynamic_array_ptr even_list = filter(&is_even, user_data);
  print_numbers(even_list);
  NEW_LINE;

  printf("Sum of numbers in the list :\n");
  int result = reduce(&sum, 0, user_data);
  printf("%d", result);
  NEW_LINE;

  return 0;
}