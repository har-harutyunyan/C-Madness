#include <stdio.h>

//1

int main(){
  int a = 14;
  float b = 2.78;
  char c = 'G';
  int* p = &a;
  float* q = &b;
  char* w = &c;
  printf("Int variable address is %p\n", p);
  printf("Float variable address is %p\n",q);
  printf("Char variable address is %p\n",w);
  return 0;
}

//2

int main(){
  int arr[] = {1,2,3,4,5,6,70};
  int size = sizeof(arr)/sizeof(arr[0]);
  int* ptr = arr;
  for(int i = 0; i < size; i++){
    printf("%d\n", *(ptr + i));
  }
 printf("\n");
 return 0;
}

//3

int main(){
   int* ptr = NULL;
   if(ptr == NULL){
     printf("Your pointer does'nt have any address\n");
   }
 return 0;
}

//4

int main(){
  int a = 98;
  int* ptr = &a;
  printf("Value is %d\n", *ptr);
  return 0;
}

//5

int main(){
  int a = 87;
  int b = 63;
  int* p = &a;
  int* q = &b;
  printf("The summary is %d\n", *p + *q);
  printf("The difference is %d\n", *p - *q);
  printf("The product is %d\n", *p * *q);
  printf("The quantity is %d\n", *p / *q);
  return 0;
}

//6

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
  int x,y;
  printf("Enter your numbers: ");
  scanf("%d %d", &x,&y);
  swap(&x,&y);
  return 0;
}

//7

void foo2(const char* str){
   int length;
   while(str[length] != '\0'){
      length++;
   }
  printf("%d\n", length);
}

int main(){
  const char* text = "Hello World!!";
  foo2(text);
  printf("\n");
  return 0;
}

//8

char* foo3(const char* str,char c){
  while(*str != '\0'){
    if(*str == c){
       return (char*)str;
    }
  str++;
}
 if(c == '\0'){
    return (char*)str;
 }
return NULL;
}

int main(){
  const char *text = "Abcdef";
  char ch = 'b';
  char* result = foo3(text,ch);
  if(result != NULL){
    printf("Your symbol was found, here the text tail %s: ",result);
  }else{
    printf("No\n");
   }
 return 0;
}

//9 Strcat

char* foo1(char *dest,const char *src){
  char *ptr = dest;
  while(*ptr != '\0'){
    ptr++;
 }
  while(*src != '\0'){
    *ptr = *src;
    ptr++;
    src++;
  }
 *ptr = '\0';
 return dest;
}

int main(){
  char str1[100] = "Hey what's up, ";
  const char *str2 = "Fine, what about you?";
  foo1(str1,str2);
  printf("%s", str1);
  return 0;
}

//10 Strcpy

char* foo4(char *dest,const char *src){
     char *ptr = dest;
     while(*src != '\0'){
       *ptr = *src;
       ptr++;
       src++;
     }
  *ptr = '\0';
  return dest;
}

int main(){
   char dest[100];
   const char *text = "Hi Everone";
   foo4(dest,text);
   printf("%s\n", dest);
   return 0;
}

//11 Strstr

char* foo5(const char *text, const char *subtext){
    if(*subtext == '\0'){
       return (char*)text;
    }
    while(*text != '\0'){
     const char *t = text;
      const char *sub = subtext;

     while(*t == *sub && *sub != '\0'){
        t++;
        sub++;
     }

   if(*sub == '\0'){
     return (char*)text;
   }

   text++;
 }
 return NULL;
}

int main(){
   const char *test = "Hey World";
   const char *word = "World";
   char *result = foo5(test,word);
   if(result != NULL){
     printf("Yes, here is the tail text \"%s\"\n", result);
   }else{
      printf("Word was'nt found\n");
    }
  return 0;
}

//12 Union alike thing

void foo6(char sym1, char sym2,short  num, int *res){
    char* ptr1 = (char*)res;
    *ptr1 = sym1;
    ++ptr1;
    *ptr1 = sym2;
    ++ptr1;
    *((short*)ptr1) = num;
}

int main(){
   char sym1 = 'A';
   char sym2 = 'B';
   int result = 0;
   short num = 10;
   foo6(sym1,sym2,num,&result);
   printf("%d\n", result);
 return 0;
}

//13(Remove Element)


int foo(int* arr, int size, int val) {
    int k = 0;
    for (int i = 0; i < size; i++) {
        if (*(arr+i) != val) {
            *(arr + k) = *(arr + i);
            k++;
        }
    }
    return k;
}

int main() {
    int array[] = { 1,1,-9,5,6,7,7,2,7};
    int size = sizeof(array) / sizeof(array[0]);
    int value = 7;
    printf("%d\n", foo(array, size, value));
    return 0;
}

//14(Remove duplicates form sorted array)


int buz(int* arr, int size) {
    if (size==0) return 0;
    int k = 1;
    for (int i = 1; i < size; i++){
        if (*(i+arr) != *(arr + i - 1)) {
            *(arr + k) = *(arr + i);
            k++;
        }
    }
    return k;
}

int main() {
    int array[] = { 1,1,1,2,2,2,2,3,3,3,4,5,6,7,8,8,8,9};
    int size = sizeof(array) / sizeof(array[0]);
    printf("%d\n", buz(array, size));
    return 0;
}

//15(Single Number)


int bar(int* arr, int size) {
    int result = 0;
    for (int i = 0; i < size; i++){
        result ^= *(arr + i);
    }
    return result;
}

int main() {
    int array[] = {1,2,1,2,3,4,3,4,5,6,5,6,7,8,9,8,9};
    int size = sizeof(array) / sizeof(array[0]);
    printf("%d\n", bar(array, size));
    return 0;
}

//task1

int* find(int* arr,int size, int value){
    for(int i = 0; i < size; i++){
        if((*(arr+i)) == value){
            return arr+i;
        }
    }
  return NULL;
}

int main(){
   int array[] = {1,2,3,45,67,-8,91};
   int size = sizeof(array)/sizeof(array[0]);
   int value = 4;
   int* result = find(array,size,value);
   if(result != NULL){
      printf("Your number was found\n");
   }else{
      printf("Your number was'nt found\n");
    }
  return 0;
}

//task2

void reverse(int* arr, int size){
    for(int i = 0; i <= size/2; i++){
       int temp = *(i+arr);
       *(i+arr) = *(size - i - 1 + arr);
       *(size - i - 1 + arr) = temp;
    }
    
    for(int i = 0; i < size; i++){
        printf("%d", *(arr+i));

    }
}

int main(){
     int array[] = {1,2,3,4,5,6};
     int size = sizeof(array)/sizeof(array[0]);
     reverse(array,size);
     return 0;
}

//task3

double average(int* arr, int size){
  int sum = 0;
  for(int i = 0; i < size; i++){
     sum += *(i+arr);
  }
return (double)sum/size;
}

int main(){
   int array[] = {1,2,3,4,5,66,54,32};
   int size = sizeof(array)/sizeof(array[0]);
   double result = average(array,size);
   printf("%lf\n", result);
   return 0;
}

//task 4

void find_min_max(int* arr, int size, int* min, int* max){
   *min = *arr;
   *max = *arr;
   for(int i = 1; i < size; i++){
      if(*min > *(arr+i)){
         *min = *(arr+i);
      }
      if(*max < *(arr+i)){
         *max = *(arr+i);
      }
   }
}

int main(){
  int array[] = {1,2,3,4,5,6};
  int size = sizeof(array)/sizeof(array[0]);
  int max,min;

  find_min_max(array,size,&min,&max);
  printf("%d\n",min);
  printf("%d\n",max);
  return 0;
}
