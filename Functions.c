#include <stdio.h>
#include <stdbool.h>
#include<math.h>

//1 Multiplication Table for a Number

void function1(int num){
   for(int i = 1; i<=10; i++){
       printf("%d * %d = %d\n", num, i, num * i);
     }
   printf("\n");
}

//2 Multiplication Table for 1-10

void function2(){
 for(int i = 1; i <=10; i++){
   for(int j = 1; j<=10; j++){
     printf("%d * %d = %d\n", i, j, i * j);
   }
    printf("\n");
 }
}

//3 Factorial

int function3(int num){
   int fact = 1;
   if(num == 0) return 1;
   for(int i = 1; i <= num; i++){
     fact *= i;
   }
  return fact;
}

//4 Number Digits Sum

int function4(int num){
   int sum = 0;
   while(num){
    sum += num % 10;
    num /= 10;
   }
  return sum;
}

//5 Square Root Check

bool function5(int num){
  if(num < 2) return 0;
  for(int i = 2; i * i <= num; i++){
    if(num % i == 0){
      return 0;
    }
  }
  return 1;
}

//6 Prime Number check

bool function6(int num){
  if(num < 2) return 0;
  for(int i = 2; i*i <= num; i++){
    if(num % i == 0){
      return 0;
    }
  }
  return 1;
}

//Goldbach's Hypothesis
int bzz(int num1){
   for(int i = 2; i <= num1 / 2; i++){
      if(foo(i) && foo(num1 - i)){
        printf("Yes we can\n");
        printf("%d %d\n", i, num1 - i);
        break;
      }
   }
  return 0;
}

//7 Number's Power

int power(int num, int exp){
  int product = num;
  if(exp == 0){
    printf("%d", 1);
    return 0;
  }else if(exp < 0){
    return 0;
  }
  for(int i = 2; i <= exp; i++){
      product *= num;
  }
  return product;
}

//8 Number Reverse

int function8(int num){
  int y = 0;
  while(num){
   y = 10 * y + (num % 10);
   num /= 10;
  }
 return y;
}

//9 Hexdecimal Representation

//1.

void function9(int num){
  printf("%X\n", num);
}

//2.

void _function9(int num) {
    char hex[20];
    int index = 0;
    if (num == 0) {
        printf("0\n");
        return;
    }
    while (num > 0) {
        int x = num % 16;
        if (x < 10){
            hex[index] = '0' + x;
        }else
            hex[index] = 'A' + (x - 10);
        index++;
        num /= 16;
    }
    for (int i = index - 1; i >= 0; i--) {
        putchar(hex[i]);
    }
    printf("\n");
}

//10 Fibonacci Number Iterative Approach

int function10(int n){
  if(n <= 0) return 0;
  if(n == 1) return 1;
  int a= 0, b = 1, c;
  for(int i = 2; i <= n; i++){
     c = a + b;
     a = b;
     b = c;
  }
  return b;
}

//11 Number Binary Representation

void function11(int num){
  if(num == 0){
    printf("0\n");
    return;
  }
  int bin[32];
  int index = 0;
  while(num){
    bin[index] = num % 2;
    index++;
    num /= 2;
  }
  for(int i = index - 1; i >= 0; i--){
     printf("%d",bin[i]);
  }
}

//12 Polyndrome Number Check

int function12(int num){
 int reversed = 0, original = num, digit;
 while(num){
   digit = num % 10;
   reversed = reversed * 10 + digit;
   num /= 10;
 }
 return original == reversed;
}

int buz(int num){
  int x = 0;
  while(num){
    x = x * 10 + (num % 10);
    num /= 10;
  }
  return x;
}

int step(int num){
  int steps = 0;
  while(!foo(num)){
    num += buz(num);
    steps++;
  }
 return steps;
}

//13 Binary Search

int function13(int arr[], int size, int target){
   int left = 0;
   int right = size - 1;
   while(left <= right) {
     int mid = left + (right-left)/2;
     if(arr[mid] ==  target){
        return mid;
     }else if(arr[mid] < target){
        left = mid + 1;
     }else {
       right = mid - 1;
     }
   }
  return -1;
}

//14 Array Reverse

void function14(char arr[], int size){
    for(int i = 0; i < size/2; i++){
        int temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp;
    }
    for(int i = 0; i < size; i++){
        printf("%d", arr[i]);
    }
}

//15 Step Number Check

bool function15(int num){
    int y = -1;
    int d = 0;
    bool p = true;
       if (num < 10) {
           return 0;
       }
      while (num) {
          int c = num % 10;
          num /= 10;
          if (y == -1) {
             y = c;
             continue;
          }
          int b = c - y;
         if (d == 0) {
            d = b;
         }else if (b != d) {
            p = false;
            break;
          }
          y = c;
     }
return p;
}

//16 Unique Element in Sorted Array

void function16(int arr[], int size){
    int unique = 0;
    int count = 0;
    for(int i = 0; i < size; i++){
        unique ^= arr[i];
        count ++;
        if(arr[i] != arr[i+1]){
           if(count != 1){
           unique = 0;
           count = 0;
           continue;
            }else{
             break;
            }
        }
    }
    printf("Unique element is: %d\n", unique);
}

//17 Sum of digits powered

void function17(int num){
int sum = 0;
int temp = num;
int count = 0;
  while (temp > 0) {
     count++;
     temp /= 10;
  }
temp = num;
   while (temp > 0){
      int digit = temp % 10;
      sum += pow(digit,count);
      temp /= 10;
   }
   if(sum == num){
     printf("Yes\n");
   }else{
     printf("No\n");
    }
}

//18 Pythagorean triplet check

void function18(int a, int b, int c){
    if(a < 0 || b < 0 || c < 0){
        return;
    }
    if(pow(a,2) + pow(b,2) == pow(c,2) || pow(b,2) + pow(c,2) == a || pow(a,2) + pow(c,2) == pow(b,2)){
       printf("Yes they are\n");
    }else{
       printf("No\n");
     }
}

//19 Arithmetic Series sum

void function19(int arr[], int size){
   printf("%d\n", (arr[0] + arr[size-1])*size/2);
}

//20 Geometric Series sum

void function20(int arr[], int size,int q){
    printf("%f\n", arr[0]*((pow(q,size-1) - 1)/(q-1)));
}

//21 Square root alternative

void function21(double num){
    if (num < 0) {
        return;
    }
    double x = num;
    double y = num / 2.0;
    double epsilon = 0.00001;
    while ((y * y - x) > epsilon || (y * y - x) < -epsilon) {
        y = (y + x / y) / 2.0;
    }
    printf("%.5f\n",y);
}

//22 Count 1 bits in unsigned int

void function22(unsigned int num){
    int count = 0;
    while(num){
    if(num % 2 == 1){
       count++;
    }
    num /= 2;
  }
  printf("%u\n",count);
}

int main() {
    return 0;
}
