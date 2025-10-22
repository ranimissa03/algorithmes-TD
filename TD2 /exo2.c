#include "utils.h"

void swap_int(int *a, int *b)
{
    // swap two elements
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool is_sorted_nondecreasing(int *arr, int n)
{
    // check if array is sorted, if yes return true
    // if not return false
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}

void copy_array(int *src, int *dst, int n)
{
    // copy array elements src into dst
    for (int i = 0; i < n; i++)
    {
        dst[i] = src[i];
    }
}


#include <stdbool.h>

void swap_int(int *a, int *b);
bool is_sorted_nondecreasing(int *arr, int n);
void copy_array(int *src, int *dst, int n);



#include <stdlib.h>
#include "sort.h"
#include "utils.h"

void selection_sort(int *arr, int n)
{
    // selection sort iterative
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap_int(&arr[i], &arr[min_idx]);
    }
}

void insertion_sort(int *arr, int n)
{
    // insertion sort iterative
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubble_sort(int *arr, int n){
    // bubble sort iterative
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap_int(&arr[j], &arr[j + 1]);
        }
    }
}


void merge(int *arr, int *tmp, int l, int m, int r)
{
    // merge function
    int i = l, j = m + 1, k = l;

    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }

    while (i <= m)
        tmp[k++] = arr[i++];
    while (j <= r)
        tmp[k++] = arr[j++];

    for (i = l; i <= r; i++)
        arr[i] = tmp[i];
}

void mergesort_rec(int *arr, int *tmp, int l, int r)
{
    // recursive steps of merge sort
     if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergesort_rec(arr, tmp, l, m);
    mergesort_rec(arr, tmp, m + 1, r);
    merge(arr, tmp, l, m, r);
}




void selection_sort(int *arr, int n);
void insertion_sort(int *arr, int n);
void bubble_sort(int *arr, int n);
void merge_sort(int *arr, int n);
void quick_sort(int *arr, int n);



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"


    // implement main here
    // create array example using malloc
    // use sorting algorithms and compare runtime
void display_array(int *arr, int n) {
    printf("[ ");
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("]\n");
}



int main(void)
{
    int n = 1000; // taille du tableau
    int *arr = (int *)malloc(n * sizeof(int));
    int *tmp = (int *)malloc(n * sizeof(int)); // pour merge sort
    int *copy = (int *)malloc(n * sizeof(int));

    if (!arr || !tmp || !copy)
        return 1;

    // remplir le tableau avec des valeurs aléatoires
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;

    printf("Original array (first 20 elements):\n");
    for (int i = 0; i < (n < 20 ? n : 20); i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    clock_t start, end;
    double time_taken;

    // ---------------- SELECTION SORT ----------------
    copy_array(arr, copy, n);
    start = clock();
    selection_sort(copy, n);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Selection sort time: %.6f sec\n", time_taken);

    // ---------------- INSERTION SORT ----------------
    copy_array(arr, copy, n);
    start = clock();
    insertion_sort(copy, n);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Insertion sort time: %.6f sec\n", time_taken);

    // ---------------- BUBBLE SORT ----------------
    copy_array(arr, copy, n);
    start = clock();
    bubble_sort(copy, n);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble sort time: %.6f sec\n", time_taken);

    // ---------------- MERGE SORT ----------------
    copy_array(arr, copy, n);
    start = clock();
    merge_sort(copy, n);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Merge sort time: %.6f sec\n", time_taken);

    // ---------------- QUICK SORT ----------------
    copy_array(arr, copy, n);
    start = clock();
    quick_sort(copy, n);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Quick sort time: %.6f sec\n", time_taken);

    free(arr);
    free(tmp);
    free(copy);

    return 0;
    return 0;
}
