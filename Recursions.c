#include <stdio.h>

//1

void q(int num){
  if(num == -1) return;
  printf("%d\n", num);;
  q(--num);
}

//2

void p(int num){
  if(num < 0){
    return;
  }
  p(num - 1);
  printf("%d\n", num);
}

//3

void buz1(int arr[], int size){
    if(size == 0){
       return;
    }
    printf("%d\n",arr[0]);
    buz1(arr+1,size-1);
}

//4

void bar(int arr[], int size){
  if(size == 0){
     return;
   }
   printf("%d\n", arr[size-1]);
   bar(arr,size-1);
}

//5

void buzz(int num,int sum){
   if(num == 0){
     printf("%d\n",sum);
     return;
   }
   sum += num % 10;
   buzz(num/10,sum);
}

//6

void foo7(int a,int b){
   if(b==0){
    printf("%d\n", a);
    return;
   }
   foo7(b, a % b);
}

//7(Fibonacci)

int func(int num){
  if(num == 0) return 0;
  if(num == 1) return 1;
  return func(num-1) + func(num-2);
}

//8(Factorial)

int fact(int num){
  if(num == 0 || num == 1) return 1;
  return num * fact(num-1);
}

//9(Binary search)

int foo6(int arr[], int left, int right, int target) {
   int mid = left + (right - left) / 2;
    if (arr[mid] == target){
        return mid;
    }
    if(left > right){
        return -1;
      }
    else if (arr[mid] > target){
        return foo6(arr, left, mid - 1, target);
   }else if(arr[mid] < target) {
        return foo6(arr, mid + 1, right, target);
     }
}

//10

int foo5(char s[], int index){
    if(s[index] == '\0'){
       return 0;
    } else {
        return 1 + foo5(s, index + 1);
    }
}

//11(Convert to binary)

void foo4(int num){
   if(num){
     foo4(num / 2);
     printf("%d", num % 2);
   }
}

//12

void foo3(int num,int product){
   if(num == 0){
     printf("%d\n",product);
     return;
   }
   product *= num % 10;
   foo3(num/10,product);
}

//13

void foo2(char s[], int index){
   if(s[index] >= 'A' && s[index] <= 'Z'){
      printf("%c\n", s[index]);
      return;
   }
   foo2(s,index+1);
}

//14

//1(the greatest element)

int foo1(int arr[], int size){
   if(size == 1){
      return arr[0];
   }
  int max = foo1(arr, size - 1);
  return (arr[size - 1] > max) ? arr[size - 1] : max;
}

//2(the smallest element)

int foo(int arr[], int size){
   if(size == 1){
      return arr[0];
   }
  int min = foo(arr, size - 1);
  return (arr[size - 1] < min) ? arr[size - 1] : min;
}
