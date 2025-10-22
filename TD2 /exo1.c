#include "utils.h"

bool is_sorted_nondecreasing(int *arr, int n)
{// return true if array is sorted and false otherwise
     for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
     }
    return true;
    
}

int min_int(int a, int b)
{
    // return smallest value between a and b
    if (a < b)
        return a;
    else
        return b;
} 


#include <stdbool.h>

bool is_sorted_nondecreasing(int *arr, int n);
int min_int(int a, int b);





#include <math.h>
#include <stdio.h>
#include "search.h"
#include "utils.h"

int linear_search(int *arr, int n, int target)
{
    // linear search, return index of target
    // return -1 if not found
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;  // trouvé
    }
    return -1;  // pas trouvé
}

int jump_search(int *arr, int n, int target)
{
    if (!is_sorted_nondecreasing(arr, n))
        return -1;

    int step = (int)sqrt(n);  // taille du saut
    int prev = 0;

    // Cherche le bloc contenant target
    while (arr[min_int(step, n) - 1] < target) {
        prev = step;
        step += (int)sqrt(n);
        if (prev >= n)
            return -1; // pas trouvé
    }

    // Recherche linéaire dans le bloc
    for (int i = prev; i < min_int(step, n); i++) {
        if (arr[i] == target)
            return i; // trouvé
    }

    return -1; // pas trouvé
}

int binary_search(int *arr, int n, int target)
{
    if (!is_sorted_nondecreasing(arr, n))
        return -1; // tableau non trié

    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}



int linear_search(int *arr, int n, int target);
int jump_search(int *arr, int n, int target);
int binary_search(int *arr, int n, int target); 



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void)
{
    int n = 10; // taille petite pour test simple
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 7;

    clock_t start, end;
    double time_taken;

    // Linear search
    start = clock();
    int idx1 = linear_search(arr, n, target);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Linear search: index=%d, time=%.6f sec\n", idx1, time_taken);

    // Jump search
    start = clock();
    int idx2 = jump_search(arr, n, target);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Jump search: index=%d, time=%.6f sec\n", idx2, time_taken);

    // Binary search
    start = clock();
    int idx3 = binary_search(arr, n, target);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Binary search: index=%d, time=%.6f sec\n", idx3, time_taken);
    return 0;
}
