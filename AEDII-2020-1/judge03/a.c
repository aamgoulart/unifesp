#include <stdio.h>

void quick_sort(int*, int, int);
int  partition(int*, int, int);
void swap(int*, int, int);
void print_ary(int*, int);

int main() {
  int ary[10] = {5,3,7,8,6,1,2,9,0,4};

  quick_sort(ary, 0, 9);
  print_ary(ary, 9);

  return 0;
}

void quick_sort(int *ary, int l_end_index, int r_end_index) {
  if (l_end_index >= r_end_index) return;

  int pivot_index = partition(ary, l_end_index, r_end_index);
  quick_sort(ary, l_end_index, (pivot_index - 1));
  quick_sort(ary, (pivot_index + 1), r_end_index);
}

int partition(int *ary, int l_end_index, int r_end_index) {
  int middle_index   = (l_end_index + r_end_index) / 2;
  int l_end_element  = ary[l_end_index];
  int middle_element = ary[middle_index];
  int r_end_element  = ary[r_end_index];
  int median_index   = 0;

  if (l_end_element < middle_element)
    if (middle_element < r_end_element)
      median_index = middle_index;
    else if (l_end_element < r_end_element)
      median_index = r_end_index;
    else
      median_index = l_end_index;
  else if (r_end_element < middle_element)
    median_index = middle_index;
  else if (r_end_element < l_end_element)
    median_index = r_end_index;
  else
    median_index = l_end_index;

  swap(ary, median_index, r_end_index);

  int pivot = ary[r_end_index];
  int pivot_index = l_end_index - 1;
  int i;

  for (i = l_end_index; i < r_end_index; i++)
    if (ary[i] <= pivot) {
      pivot_index = pivot_index + 1;
      swap(ary, pivot_index, i);
    }

  swap(ary, pivot_index + 1, r_end_index);

  return pivot_index + 1;
}

void swap(int *ary, int pivot, int r_end_index) {
  int temp = ary[pivot];
  ary[pivot] = ary[r_end_index];
  ary[r_end_index] = temp;
}

void print_ary(int *ary, int size) {
  int i = 0;

  printf("[%d", ary[i]);
  while (i++ < size)
    printf(",%d", ary[i]);
  printf("]\n");
}



