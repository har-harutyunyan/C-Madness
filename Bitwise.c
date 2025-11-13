#include <stdio.h>
int main(){

//1 Odd Even check

int x;
printf("Enter your number: ");
scanf("%d",&x);
int l = x & 1;
if(l == 1){
 printf("Given number is odd\n");
}else{
 printf("Given number is even\n");
}

//2 Odd number check, next odd number

int y;
printf("Enter your number: ");
scanf("%d", &y);
int z = y | 1;
if(z == y){
printf("%d\n",y);
}else{
 printf("%d\n", z);
}

//3 Number Double

int k;
printf("Enter your number: ");
scanf("%d",&k);
printf("%d\n", k << 1);

//4 English Letter Toggle

char a;
printf("Enter your symbol: ");
scanf("%c", &a);
printf("%c\n", a^32);

//5 nth Bit Set

int m,n;
printf("Enter your number and bit count: ");
scanf("%d %d", &m, &n);
m |= 1 << n;
printf("%d\n", m);

//6 Power of 2 check

int o;
printf("Enter your number: ");
scanf("%d", &o);
int p = o - 1;
if(!(o & p)){
  printf("Yes it is\n");
}else{
  printf("No\n");
}


//7 d-th bit deletion of number c

int c,d;
printf("Enter your number and bit count: ");
scanf("%d %d",&c,&d);
int e = ~(1 << d);
if(!(c | e)){
 printf("%d\n", c);
}else{
 printf("%d\n", c & e);
}

//8 qth bit flip

int w,q;
printf("Enter your number and bit count: ");
scanf("%d %d", &w,&q);
printf("%d\n", w ^= (1 << q));

//9 Bit Swap

int t,i,j;
printf("Enter your number and bit counts: ");
scanf("%d %d %d", &t,&i,&j);
if(((t >> i) & 1) ^ ((t >> j) & 1)){
 t ^= (1<<i);
 t ^= (1<<j);
}
printf("%d\n", n);

//10 Number reverse

unsigned char n2;
printf("Enter your number: ");
scanf("%hhu", &n2);
unsigned char n3 = 0;
    for (int i = 0; i < 8; i++) {
        n3 |= ((n2 >> i) & 1) << (7 - i);
    }
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n3 >> i) & 1);
 }
    printf("\n");


//11 Absolute Value

int n1;
printf("Enter your number: ");
scanf("%d", &n1);
if(n1 < 0){
 printf("%d\n", ~(n1 - 1));
} else if(n1 > 0){
 printf("%d\n", n1);
} else {
 printf("%d\n", 0);
}

//12 1 bits count even odd check

unsigned char ch;
printf("Enter your number: ");
scanf("%hhu", &ch);
int count = 0;
    for (int i = 0; i < 8; i++) {
        if ((ch >> i) & 1) {
            count++;
        }
    }
    if (count % 2 == 0) {
        printf("The number of 1-bits is even\n");
    } else {
        printf("The number of 1-bits is odd\n");
    }

//task 1

int v3;
printf("Enter your number: ");
scanf("%d", &v3);
printf("%d\n", v3 & (v3 - 1));

//task2

int v2;
printf("Enter your number: ");
scanf("%d", &v2);
printf("%d\n", v2 | (v2 + 1));

//task3

int v1;
printf("Enter your number: ");
scanf("%d", &v1);
printf("%d\n", v1 & (v1 + 1));

//task4

int v;
printf("Enter your number: ");
scanf("%d", &v);
printf("%d\n",v | (v - 1));

//Hamming distance

int alpha, betta;
printf("Enter your numbers: ");
scanf("%d %d", &alpha, &betta);
int sum = 0;
for(int i = 0; i < 8; i++){
    sum += ((alpha >> i) & 1) + ((betta >> i) & 1);
}
printf("%d\n", sum);

// Add task

int num3, num4, carry = 0;
printf("Enter your numbers: ");
scanf("%d %d", &num3, &num4);
while(num3){
   carry = num4 & num3;
   num4 ^= num3;
   num3 = carry << 1;
}
printf("%d\n",num4);

// Diff task

int num1, num2, diff = 0;
printf("Enter your numbers: ");
scanf("%d %d", &num1, &num2);
if(num1 < num2){
  int temp = num1;
  num2 = num1;
  num2 = temp;
}
  int u = ~(num2 + 1);
    while(num1){
  diff = num1 & u;
  u ^= num1;
  num1 = diff << 1;
  }

printf("%d", ~(u + 1));

return 0;
}
