#include <cstdio>
#include <cstdlib>

//1 REALLOC

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

//1

#define COUNT 3

int main(){
   int matrix[COUNT][COUNT];
   for (int i = 0; i < COUNT; i++) {
      for (int j = 0; j < COUNT; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }
   for (int i = 0; i < COUNT; i++) {
      for (int j = 0; j < COUNT; j++) {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }
   return 0;
}

//2


int foo(int matrix[COUNT][COUNT]) {
   int sum = 0;
   for (int i = 0; i < COUNT; i++) {
      sum += matrix[i][i];
   }
   return sum;
}

int main(){
   int matrix[COUNT][COUNT];
   for (int i = 0; i < COUNT; i++) {
      for (int j = 0; j < COUNT; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }
 int  sum = foo(matrix);
   printf("%d\n", sum);
   return 0;
}

//3

#define COUNT 4

int (*foo(int matrix[COUNT][COUNT]))[COUNT] {
    for (int i = 0; i < COUNT; i++) {
        if ((i & 1) == 0) {
            for (int j = 0; j < COUNT; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

int main() {
    int matrix[COUNT][COUNT];
    for (int i = 0; i < COUNT; i++) {
        for (int j = 0; j < COUNT; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int (*res)[COUNT] = foo(matrix);
    for (int i = 0; i < COUNT; i++) {
        for (int j = 0; j < COUNT; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//4


int foo1(int matrix[COUNT][COUNT]) {
   int sum = 0;
   for (int i = 0; i < COUNT; i++) {
      sum += matrix[i][COUNT-1-i];
   }
   return sum;
}

int main() {
   int matrix[COUNT][COUNT];
   for (int i = 0; i < COUNT; i++) {
      for (int j = 0; j < COUNT; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }
   int sum = foo1(matrix);
   printf("%d\n", sum);
   return 0;
}

//5

int foo2(int matrix[COUNT][COUNT]) {
   int sum = 0;
   for (int i = 0; i < COUNT; i++) {
      for (int j = i; j < COUNT; j++) {
         sum += matrix[i][j];
      }
   }
   return sum;
}

int main() {
   int matrix[COUNT][COUNT];
   for (int i = 0; i < COUNT; i++) {
      for (int j = 0; j < COUNT; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }
   int sum = foo2(matrix);
   printf("%d\n", sum);
   return 0;
}

//6

void foo3(int matrix[COUNT][COUNT]) {
   for (int i = 0; i < COUNT; i++) {
      int temp = matrix[i][i];
      matrix[i][i] = matrix[i][COUNT - 1 - i];
      matrix[i][COUNT - 1 - i] = temp;
   }
   for (int i = 0; i < COUNT; i++) {
      for (int j = 0; j < COUNT; j++) {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }
}

int main() {
   int matrix[COUNT][COUNT];
   for (int i = 0; i < COUNT; i++) {
      for (int j = 0; j < COUNT; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }
   foo3(matrix);
   return 0;
}

//7

#define ROW_COUNT 3
#define COLUMN_COUNT 4

void foo4(int matrix[ROW_COUNT][COLUMN_COUNT]) {
   int min = matrix[0][0];
   int a = 0;
   int b = 0;
   for (int i = 0; i < ROW_COUNT; i++) {
      for (int j = 0; j < COLUMN_COUNT; j++) {
         if (matrix[i][j] < min) {
            min = matrix[i][j];
            a = i;
            b = j;
         }
      }
   }
   printf("%d %d\n", a,b);
}

int main() {
   int matrix[ROW_COUNT][COLUMN_COUNT];
   for (int i = 0; i < ROW_COUNT; i++) {
      for (int j = 0; j < COLUMN_COUNT; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }
   foo4(matrix);
   return 0;
}

//8

int main() {
    int n,m;
    printf("Matrix's sizes: ");
    scanf("%d %d", &n, &m);
    int** matrix = (int**)malloc(n * sizeof(int*));
    if (matrix == NULL) {
        printf("Memory allocation failed");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(m * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed");
            return 1;
        }
    }
    printf("Input matrix:\n");
    for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int* max_values = (int*)malloc(n * sizeof(int));
    if (max_values == NULL) {
        printf("Memory allocation failed");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        int max = matrix[i][0];
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
        max_values[i] = max;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", max_values[i]);
    }
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
          matrix[i] = NULL;
    }
    free(matrix);
    free(max_values);
    matrix = NULL;
    max_values = NULL;

    return 0;
}

//9

void func(int** matrix,int size) {
   int sum = 0;
   for (int i = 0; i < size; i++) {
      sum += matrix[i][i];
   }
   printf("%d\n", sum);
}

void buzz(int** matrix,int size) {
   int sum = 0;
   for (int i = 0; i < size; i++) {
      sum += matrix[i][size-1-i];
   }
   printf("%d\n", sum);
}

void swap(int** matrix,int size) {
   for (int i = 0; i < size; i++) {
      int temp = matrix[i][i];
      matrix[i][i] = matrix[i][size - 1 - i];
      matrix[i][size - 1 - i] = temp;
   }
}

void print(int**matrix,int size) {
      for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }
}

int main() {
   int n;
   printf("Enter Matrix's size: ");
   scanf("%d", &n);
   int** matrix = (int**) malloc(n * sizeof(int*));
   if(matrix == NULL){
     printf("Memory allocation is failed");
     return 1;
   }
   for (int i = 0; i < n; i++) {
      matrix[i] = (int*) malloc(n * sizeof(int));
      if(matrix[i] == NULL){
         printf("Memory allocation is failed");
         return 1;
      }
   }
   printf("Enter Matrix Elements: ");
   printf("\n");
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }
   printf("Main diagonal elements summary: ");
   func(matrix,n);
   printf("Secondary diagonal elements summary: ");
   buzz(matrix,n);
   printf("Swapped diagonals matrix: \n");
   swap(matrix,n);
   print(matrix,n);
   for (int i = 0; i < n; i++) {
      free(matrix[i]);
      matrix[i] = NULL;
   }
   free(matrix);
   matrix = NULL;
   return 0;
}

//10

void foo5(int **matrix, int n){
    for(int i = 0; i < n; i++){
       for(int j = i + 1; j < n; j++){
          int temp = matrix[i][j];
          matrix[i][j] = matrix[j][i];
          matrix[j][i] = temp;
       }
    }
}

void print(int **matrix, int n){
     for(int i = 0; i < n; i++){
         for(int j = 0; j < n; j++){
            printf("%d ", matrix[i][j]);
         }
       printf("\n");
     }
}

int main() {
   int n;
   printf("Enter Matrix's size: ");
   scanf("%d", &n);
   int** matrix = (int**) malloc(n * sizeof(int*));
   if(matrix == NULL){
     printf("Memory allocation is failed");
     return 1;
   }
   for (int i = 0; i < n; i++) {
      matrix[i] = (int*) malloc(n * sizeof(int));
      if(matrix[i] == NULL){
         printf("Memory allocation is failed");
         return 1;
      }
   }
   printf("Enter Matrix Elements: ");
   printf("\n");
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }
   foo5(matrix,n);
   printf("Transposed matrix\n");
   print(matrix,n);
   for(int i = 0; i < n; i++){
      free(matrix[i]);
   }
   free(matrix);
   return 0;
}

//11

int main() {
   int n;
   printf("Enter Matrix's size: ");
   scanf("%d", &n);
   int** matrix = (int**) malloc(n * sizeof(int*));
   if(matrix == NULL){
     printf("Memory allocation is failed");
     return 1;
   }
   for (int i = 0; i < n; i++) {
      matrix[i] = (int*) malloc(n * sizeof(int));
      if(matrix[i] == NULL){
         printf("Memory allocation is failed");
         return 1;
      }
   }
   printf("Enter Matrix Elements: ");
   printf("\n");
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }
   int array[n];
   for (int j = 0; j < n; j++) {
      array[j] = 0;
      for (int i = 0; i < n; i++) {
         array[j] += matrix[i][j];
      }
   }
   printf("Column elements summary: ");
   for (int i = 0; i < n; i++) {
      printf("%d ", array[i]);
   }
   for(int i = 0; i < n; i++){
      free(matrix[i]);
   }
   free(matrix);
   return 0;
}

//12

int main() {
   int n,m;
   printf("Enter Matrix's sizes: ");
   scanf("%d %d", &n, &m);
   int** matrix = (int**) malloc(n * sizeof(int*));
   if(matrix == NULL){
     printf("Memory allocation is failed");
     return 1;
   }
   for (int i = 0; i < n; i++) {
      matrix[i] = (int*) malloc(m * sizeof(int));
      if(matrix[i] == NULL){
         printf("Memory allocation is failed");
         return 1;
      }
   }
   printf("Enter Matrix Elements: ");
   printf("\n");
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }
   int array[n];
   for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = 0; j < m; j++) {
         int val = matrix[i][j];
         if (val > 0 && val % 2 == 0)
            sum += val;
      }
      array[i] = sum;
   }
   printf("Positive even numbers summary: ");
   for (int i = 0; i < n; i++) {
      printf("%d ", array[i]);
   }
   for(int i = 0; i < n; i++){
      free(matrix[i]);
   }
   free(matrix);
   return 0;
}

//13


int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1,  0,  1, 1, 1, 0, -1, -1};

int main() {
    int n;
    printf("Enter matrix size: ");
    scanf("%d", &n);
    int** matrix = (int**)malloc(n * sizeof(int*));
    int** result = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        result[i] = (int*)malloc(n * sizeof(int));
    }
    printf("Enter matrix, with 0 or M:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch;
            scanf(" %c", &ch);
            matrix[i][j] = (ch == 'M') ? -1 : 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                result[i][j] = -1;
            } else {
                int count = 0;
                for (int d = 0; d < 8; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n && matrix[ni][nj] == -1)
                        count++;
                }
                result[i][j] = count;
            }
        }
    }
    printf("Result matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (result[i][j] == -1)
                printf("M ");
            else
                printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
        free(result[i]);
    }
    free(matrix);
    free(result);
    return 0;
}

//task(Even and odd numbers arrays)


int main() {
    int n;
    int b =0;
    printf("Enter a number: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if ((arr[i] % 2) == 0){
            b++;
        }
    }
    int* even = (int*)malloc(b * sizeof(int));
    int* odd = (int*)malloc((n-b) * sizeof(int));
    int even_count = 0;
    int odd_count = 0;
    for (int i = 0; i < n; i++) {
        if ((arr[i] % 2)==0) {
            even[even_count++] = arr[i];
        }
        else {
            odd[odd_count++] = arr[i];
        }
    }
    for (int i = 0; i < (n-b); i++) {
        printf("%d ", odd[i]);
    }
    printf("\n");
    for (int i = 0; i < b; i++) {
        printf("%d ", even[i]);
    }
    free(arr);
    free(even);
    free(odd);
    arr = NULL;
    even = NULL;
    odd = NULL;

    return 0;
}
