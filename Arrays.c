#include <stdio.h>

int main(){

    //1: Max element
    {
        int n = 4;
        int array[n];
        int max = -2e9;
        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
        }
        for(int i = 0; i < n; i++){
            if(max < array[i]){
                max = array[i];
            }
        }
        printf("%d\n", max);
    }

    //2: Min element
    {
        int n = 4;
        int array[n];
        int min = 2e9;
        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
        }
        for(int i = 0; i < n; i++){
            if(min > array[i]){
                min = array[i];
            }
        }
        printf("%d\n", min);
    }

   //3: Index of max
    {
        int n = 5;
        int array[n];
        int maxIndex = 0;
        int max = -2e9;
        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
        }
        for(int i = 0; i < n; i++){
            if(max < array[i]){
                max = array[i];
                maxIndex = i;
            }
        }
        printf("%d\n", maxIndex);
    }

    //4: Index of min
    {
        int n = 5;
        int array[n];
        int minIndex = 0;
        int min = 2e9;
        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
        }
        for(int i = 0; i < n; i++){
            if(min > array[i]){
                min = array[i];
                minIndex = i;
            }
        }
        printf("%d\n", minIndex);
    }

    //5: Sum of min and max indices
    {
        int n = 6;
        int array[n];
        int minIndex = 0, maxIndex = 0;
        int min = 2e9, max = -2e9;
        int sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
        }
        for(int i = 0; i < n; i++){
            if(min > array[i]){
                min = array[i];
                minIndex = i;
            }
            if(max < array[i]){
                max = array[i];
                maxIndex = i;
            }
        }
        sum = minIndex + maxIndex;
        printf("%d\n", sum);
    }

    //6: Product of min and max indices
    {
        int n = 6;
        int array[n];
        int minIndex = 0, maxIndex = 0;
        int min = 2e9, max = -2e9;
        int product = 1;
        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
        }
        for(int i = 0; i < n; i++){
            if(min > array[i]){
                min = array[i];
                minIndex = i;
            }
            if(max < array[i]){
                max = array[i];
                maxIndex = i;
            }
        }
        product = minIndex * maxIndex;
        printf("%d\n", product);
    }

    //7: Divide each element by n
    {
        int n = 6;
        int array[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
        }
        for(int i = 0; i < n; i++){
            array[i] /= n;
            printf("%d\n", array[i]);
        }
    }

    //8: Element-wise multiplication of two arrays
    {
        int n = 8;
        int array[n], array2[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
        }
        for(int i = 0; i < n; i++){
            scanf("%d", &array2[i]);
        }
        for(int i = 0; i < n; i++){
            printf("%d\n", array[i] * array2[i]);
        }
    }

    //9: Reverse array
    {
        int n = 7;
        int array[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
        }
        for(int i = n-1; i >= 0; i--){
            printf("%d\n", array[i]);
        }
    }

    //10: Average of array
    {
        int n = 7;
        int array[n], sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
        }
        for(int i = 0; i < n; i++){
            sum += array[i];
        }
        printf("%f\n", (double)sum/n);
    }

    //11: Check if number exists
    {
        int n = 7, b;
        printf("Enter your number: ");
        scanf("%d", &b);
        int array[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
        }
        int found = 0;
        for(int i = 0; i < n; i++){
            if(array[i] == b){
                found = 1;
                break;
            }
        }
        printf(found ? "Yes\n" : "No\n");
    }

    //12: Uppercase conversion for characters
    {
        int n = 6;
        char array[n];
        for(int i = 0; i < n; i++){
            scanf(" %c", &array[i]); // space to skip newline
        }
        for(int i = 0; i < n; i++){
            if(array[i] >= 'a' && array[i] <= 'z'){
                array[i] ^= 32;
            }
            printf("%c\n", array[i]);
        }
    }

    //13: Count odd numbers
    {
        int n = 7;
        int array[n], count = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
        }
        for(int i = 0; i < n; i++){
            if(array[i] % 2 == 1){
                count++;
            }
        }
        printf("%d\n", count);
    }

    //14: Reverse character array
    {
        int n = 6;
        char array[n];
        for(int i = 0; i < n; i++){
            scanf(" %c", &array[i]);
        }
        for(int i = 0; i < n/2; i++){
            char temp = array[i];
            array[i] = array[n-i-1];
            array[n-i-1] = temp;
        }
        for(int i = 0; i < n; i++){
            printf("%c\n", array[i]);
        }
    }

    //15: Partition even/odd
    {
        int n = 6;
        int array[n];
        int x = 0, y = n-1;
        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
        }
        while(x < y){
            if(array[x] % 2 == 0){
                x++;
            } else if(array[y] % 2 == 1){
                y--;
            } else {
                int temp = array[x];
                array[x] = array[y];
                array[y] = temp;
            }
        }
        for(int i = 0; i < n; i++){
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    //16: Compare two arrays
    {
        int n = 6;
        int array[n], array2[n], equal = 1;
        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
        }
        for(int i = 0; i < n; i++){
            scanf("%d", &array2[i]);
        }
        for(int i = 0; i < n; i++){
            if(array[i] != array2[i]){
                equal = 0;
                break;
            }
        }
        printf(equal ? "Yes they are similar\n" : "No they are not\n");
    }

    //17: Find target index
    {
        int n = 10;
        int array[n], target = 8;
        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
        }
        int found = 0;
        for(int i = 0; i < n; i++){
            if(array[i] == target){
                printf("%d\n", i);
                found = 1;
                break;
            }
        }
        if(!found) printf("-1\n");
    }

    //18: Check if array is non-increasing
    {
        int n = 10;
        int array[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
        }
        int nonIncreasing = 1;
        for(int i = 1; i < n; i++){
            if(array[i] > array[i-1]){
                nonIncreasing = 0;
                break;
            }
        }
        printf(nonIncreasing ? "Yes\n" : "No\n");
    }

    //19: XOR of all elements
    {
        int n = 5;
        int array[n], unique = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
            unique ^= array[i];
        }
        printf("%d\n", unique);
    }

    //20: Missing number in 1..N
    {
        int N;
        printf("Enter your positive number: ");
        scanf("%d", &N);
        int array[N-1];
        for(int i = 0; i < N-1; i++){
            scanf("%d", &array[i]);
        }
        int expectedSum = N * (N + 1) / 2;
        int actualSum = 0;
        for(int i = 0; i < N-1; i++){
            actualSum += array[i];
        }
        printf("%d\n", expectedSum - actualSum);
    }

    return 0;
}