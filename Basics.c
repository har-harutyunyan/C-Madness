#include <stdio.h>

int main() {

//1

 int x;
 printf("enter your integer number: ");
 scanf("%d", &x);
 printf("%d\n",x);

//2

double y;
printf("enter your real number: ");
scanf("%lf",&y);
printf("%lf\n", y);

//3

 char c;
 printf("enter yout character: ");
 scanf("%c", &c);
 printf("%c\n", c);

//4

 int a,b;
 printf("enter your numbers: ");
 scanf("%d %d",&a,&b);
 printf("%d\n",(a+b));

//5

 int z;
 printf("enter your age: ");
 scanf("%d", &z);
 printf("You are  %d  years old\n", z);

//6

int w;
printf("enter the value of w: ");
scanf("%d", &w);
printf("%d\n",( 4*x + 21* w * w - 12));

//7

float d,e;
printf("enter your float numbers: ");
scanf("%f %f", &d,&e);
printf("%f\n", (d*e));

//8

float t;
printf("enter your temprature in  Celsius: ");
scanf("%f", &t);
printf("Here is your temprature in Farenheit: %f\n", (t*9/5+32));

//9

float height,weight;
printf("enter your height and weight: ");
scanf("%f %f", &height, &weight);
printf("Your BMI(body mass index) is: %f\n", weight/height/ height);

//swap task

int f,g;
printf("Enter your numbers: ");
scanf("%d %d", &f,&g);
f += g;
g = f - g;
f = f - g;
printf("%d %d\n",f,g);

//10

float  l, o, p;
printf("enter your numbers: ");
scanf("%f %f %f",&l,&o,&p);
printf("Your average is: %f\n",(l + o + p)/3);

//11

int s;
printf("Enter the time in hours: ");
scanf("%d", &s);
printf("Time in minutes: %d\n", s * 60);

//12

int age;
printf("Enter your age: ");
scanf("%d", &age);
printf("Your age in days: %d\n",age*365);

//13

char m;
printf("Enter your symbol: ");
scanf("%c", &m);
printf("Your symbol's numerical value is: %d\n",m);

//14

unsigned int n;
printf("Enter your number: ");
scanf("%u", &n);
printf("Your number is: %u\n", n);

//15

float  h,k;
printf("Enter your numbers: ");
scanf("%f %f", &h,&k);
printf("The sum of numbers is: %f\n", (h + k));
printf("The difference of numbers is: %f\n", (h - k));
printf("The product of numbers is: %f\n", (h * k));
printf("The quotient of numbers is: %f\n", (h / k));

//16

int i,j;
printf("Enter your numbers: ");
scanf("%d %d", &i,&j);
printf("%d\n", i % j);


 return 0;
}
