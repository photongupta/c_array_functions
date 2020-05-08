#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

Dynamic_array_ptr create_dinamic_array(int length)
{
  Dynamic_array_ptr dynamic_array = malloc(sizeof(Dynamic_array));
  dynamic_array->numbers = malloc(length * sizeof(int));
  dynamic_array->length = 0;
  return dynamic_array;
}

Dynamic_array_ptr get_copy(Dynamic_array_ptr list)
{

  Dynamic_array_ptr copy_of_list = create_dinamic_array(list->length);
  for (int i = 0; i < list->length; i++)
  {
    copy_of_list->numbers[copy_of_list->length] = list->numbers[i];
    copy_of_list->length += 1;
  }
  return copy_of_list;
}

Dynamic_array_ptr map(Mapper mapper, Dynamic_array_ptr list)
{
  Dynamic_array_ptr mapped_list = create_dinamic_array(list->length);
  for (int index = 0; index < list->length; index++)
  {
    mapped_list->numbers[index] = mapper(list->numbers[index]);
    mapped_list->length++;
  }
  return mapped_list;
}

Dynamic_array_ptr filter(Predicate predicate, Dynamic_array_ptr list)
{
  Dynamic_array_ptr filtered_list = create_dinamic_array(list->length);
  for (int index = 0; index < list->length; index++)
  {
    if (predicate(list->numbers[index]) == 1)
    {
      filtered_list->numbers[filtered_list->length] = list->numbers[index];
      filtered_list->length += 1;
    }
  }
  return get_copy(filtered_list);
}

int reduce(Reducer reduce, int context, Dynamic_array_ptr list)
{
  int result = context;
  for (int index = 0; index < list->length; index++)
  {
    result = reduce(result, list->numbers[index]);
  }
  return result;
}

void print_numbers(Dynamic_array *list)
{
  NEW_LINE;
  for (int i = 0; i < list->length; i++)
  {
    printf("%d ", list->numbers[i]);
  }
}
