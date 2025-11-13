#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//REALLOC

int* my_realloc(int* array, int old_size, int new_size) {
    int* new_array = (int*)malloc(new_size * sizeof(int));
    if (new_array == NULL) {
        return NULL;
    }

    int min = old_size < new_size ? old_size : new_size;
    for (int i = 0; i < min; i++) {
        new_array[i] = array[i];
    }
    free(array);
    array = NULL;
    return new_array;
}

int main() {
    int n,m;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter new size: ");
    scanf("%d", &m);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    arr = my_realloc(arr, n, m);
    for (int i = 0; i < m; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

//CALLOC

#include <stdio.h>
#include <stdlib.h>

void *mycalloc(int element_count, int byte_count) {
    size_t size = (size_t)element_count * (size_t)byte_count;
    void *ptr = malloc(size);
    if (ptr == NULL) {
        return NULL;
    }
    unsigned char *p = (unsigned char *)ptr;
    unsigned char *q = p + size;
    while (p < q) {
        *p++ = 0;
    }
    return ptr;
}

int main() {
    int n = 5;
    int *arr = (int*)mycalloc(n, sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    free(arr);
    return 0;
}

//2

int* foo(int *arr1,int n, int* arr2,int m,int *size) {
    int cap = n + m;
    int *result = (int *)malloc(sizeof(int)*cap);
    if (result == NULL) {
        *size = 0;
        return NULL;
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        if ((*(arr1+i))%2) {
            result[index++] = arr1[i];
        }
    }
    for (int i = 0; i < m; i++) {
        if ((*(arr2+i))%2) {
            result[index++] = arr2[i];
        }
    }
    *size = index;
    int *temp = (int *)realloc(result, sizeof(int) * (*size));
    if (temp != NULL) result = temp;
    return result;
}

int main() {
    int n,m;
    printf("Enter first array size: ");
    scanf("%d",&n);
    int* arr1 = (int *)malloc(n *sizeof(int));
    if (arr1 == NULL) {
        printf("Memory allocation error");
        return 1;
    }
    printf("Enter second array size: ");
    scanf("%d",&m);
    int* arr2 = (int *)malloc(m *sizeof(int));
    if (arr2 == NULL) {
        printf("Memory allocation error");
        return 1;
    }
    printf("Enter first array's elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr1[i]);
    }
    printf("Enter second array's elements: ");
    for (int i = 0; i < m; i++) {
        scanf("%d",&arr2[i]);
    }
    int size = 0;
    int *answer = foo(arr1,n,arr2,m,&size);
    if (answer == NULL) {
        printf("Memory allocation error");
        free(arr1);
        free(arr2);
        return 1;
    }
    printf("New array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ",answer[i]);
    }
    free(arr1);
    free(arr2);
    free(answer);
    return 0;
}

//3

 bool isPrime(int n) {
     if ( n <=1 ) return false;
     if ( n == 2 ) return true;
     if (n % 2 == 0) return false;
     for (int i = 3; i*i <= n; i += 2) {
         if ( n % i == 0 ) return false;
     }
     return true;
 }

 int* foo1(int *arr1,int n, int* arr2,int m,int *size) {
     int cap = n + m;
     int *result = (int *)malloc(sizeof(int)*cap);
     if (result == NULL) {
         *size = 0;
         return NULL;
     }
     int index = 0;
     for (int i = 0; i < n; i++) {
         if (isPrime(arr1[i])) {
             result[index++] = arr1[i];
         }
     }
     for (int i = 0; i < m; i++) {
         if (isPrime(arr2[i])){
             result[index++] = arr2[i];
         }
     }
     *size = index;
     int *temp = (int *)realloc(result, sizeof(int) * (*size));
     if (temp != NULL) result = temp;
     return result;
 }


 int main() {
     int n,m;
     printf("Enter first array size: ");
     scanf("%d",&n);
     int* arr1 = (int *)malloc(n *sizeof(int));
     if (arr1 == NULL) {
         printf("Memory allocation error");
         return 1;
     }
     printf("Enter second array size: ");
     scanf("%d",&m);
     int* arr2 = (int *)malloc(m *sizeof(int));
     if (arr2 == NULL) {
         printf("Memory allocation error");
         return 1;
     }
     printf("Enter first array's elements: ");
     for (int i = 0; i < n; i++) {
         scanf("%d",&arr1[i]);
     }
     printf("Enter second array's elements: ");
     for (int i = 0; i < m; i++) {
         scanf("%d",&arr2[i]);
     }
     int size = 0;
     int *answer = foo1(arr1,n,arr2,m,&size);
     if (answer == NULL) {
         printf("Memory allocation error");
         free(arr1);
         free(arr2);
         return 1;
     }
     printf("New array is:\n");
     for (int i = 0; i < size; i++) {
         printf("%d ",answer[i]);
     }
     free(arr1);
     free(arr2);
     free(answer);
     return 0;
 }

//4

 int* foo2(int *arr1,int n, int* arr2,int m,int *size) {
     int cap = n + m;
     int *result = (int *)malloc(sizeof(int)*cap);
     if (result == NULL) {
         *size = 0;
         return NULL;
     }
     int index = 0,i = 0, j = 0;
     while (i < n || j < m) {
         if (i < n) {
             result[index++] = arr1[i++];
         }
         if (j < m) {
             result[index++] = arr2[j++];
         }
     }
     *size = index;
     int *temp = (int *)realloc(result, sizeof(int) * (*size));
     if (temp != NULL) result = temp;
     return result;
 }


 int main() {
     int n,m;
     printf("Enter first array size: ");
     scanf("%d",&n);
     int* arr1 = (int *)malloc(n *sizeof(int));
     if (arr1 == NULL) {
         printf("Memory allocation error");
         return 1;
     }
     printf("Enter second array size: ");
     scanf("%d",&m);
     int* arr2 = (int *)malloc(m *sizeof(int));
     if (arr2 == NULL) {
         printf("Memory allocation error");
         return 1;
     }
     printf("Enter first array's elements: ");
     for (int i = 0; i < n; i++) {
         scanf("%d",&arr1[i]);
     }
     printf("Enter second array's elements: ");
     for (int i = 0; i < m; i++) {
         scanf("%d",&arr2[i]);
     }
     int size = 0;
     int *answer = foo2(arr1,n,arr2,m,&size);
     if (answer == NULL) {
         printf("Memory allocation error");
         free(arr1);
         free(arr2);
         return 1;
     }
     printf("New array is:\n");
     for (int i = 0; i < size; i++) {
         printf("%d ",answer[i]);
     }
     free(arr1);
     free(arr2);
     free(answer);
     return 0;
 }

//5

 int* foo3(int *arr,int n,int *size) {
     int *result = (int *)malloc(sizeof(int)*n);
     if (result == NULL) {
         *size = 0;
         return NULL;
     }
     int index = 0;
     for (int i = 0; i < n; i++) {
              if (*(arr + i)%2) {
                  result[index++] = arr[i];
              }
     }
     *size = index;
     int *temp = (int *)realloc(result, sizeof(int) * (*size));
     if (temp != NULL) result = temp;
     return result;
 }

 int main() {
     int n;
     printf("Enter array size: ");
     scanf("%d",&n);
     int* array = (int *)malloc(n *sizeof(int));
     if (array == NULL) {
         printf("Memory allocation error");
         return 1;
     }
     printf("Enter array's elements: ");
     for (int i = 0; i < n; i++) {
         scanf("%d",&array[i]);
     }
     int size = 0;
     int *answer = foo3(array,n,&size);
     if (answer == NULL) {
         printf("Memory allocation error");
         free(array);
         return 1;
     }
     for (int i = 0; i < size; i++) {
         printf("%d ",answer[i]);
     }
     free(array);
     free(answer);
     return 0;
 }
