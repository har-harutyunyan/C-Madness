#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int fact(int num){  //(For Pascal's Triangle)
    if(num == 1 || num == 0){
        return 1;
    }
    return num * fact(num-1);
}

int foo(int num, int r){
    return fact(num)/fact(r)/fact(num-r);
}

void printPascalsTriangle(int n){
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n - i- 1; k++){
            printf("  ");
        }
        for(int j = 0; j <= i; j++){
            printf("%4d", foo(i,j));
        }
        printf("\n");
    }
}

int main() {

    // 1: Counting 0-10
    {
        int num = 0;
        while(num <= 10){ printf("%d\n", num); num++; }
        num = 0;
        do{ printf("%d\n", num); num++; } while(num < 11);
        for(int num = 0; num <= 10; num++){ printf("%d\n", num); }
    }

    // 1b: Counting 10-0
    {
        int num = 10;
        while(num >= 0){ printf("%d\n", num); num--; }
        num = 10;
        do{ printf("%d\n", num); num--; } while(num >=0);
        for(int num = 10; num >=0; num--){ printf("%d\n",num); }
    }

    // 2: Count multiples of 5
    {
        int a,b,count=0;
        printf("Enter values for a and b: ");
        scanf("%d %d",&a,&b);
        if(a<b){
            for(int i=a;i<=b;i++) if(i%5==0) count++;
        } else {
            for(int i=b;i<=a;i++) if(i%5==0) count++;
        }
        printf("%d\n",count);
    }

    // 3: FizzBuzz
    {
        for(int i=0;i<=100;i++){
            if(i%3==0 && i%5==0) printf("FizzBuzz\n");
            else if(i%3==0) printf("Fizz\n");
            else if(i%5==0) printf("Buzz\n");
            else printf("%d\n",i);
        }
    }

    // 4: Print odd numbers
    {
        for(int i=0;i<=100;i++){
            if(i%2==1) printf("%d\n",i);
        }
    }

    // 5: Skip numbers 3,5,15
    {
        for(int i=0;i<=100;i++){
            if(i==3 || i==5 || i==15) continue;
            printf("%d\n",i);
        }
    }

    // 6: Vowel or consonant
    {
        char symbol;
        printf("Enter your symbol: ");
        scanf(" %c",&symbol);
        if(symbol>='A' && symbol<='Z') symbol+=32;
        switch(symbol){
            case 'a': case 'e': case 'i': case 'o': case 'u':
                printf("It's vowel\n"); break;
            default: printf("It's consonant\n");
        }
    }

    // 7: Multiplication table for a number
    {
        int num;
        printf("Enter your number: ");
        scanf("%d",&num);
        if(num<1 || num>9){ printf("Enter number 1-9\n"); return 1; }
        for(int i=1;i<=10;i++){ printf("%d * %d = %d\n", num,i,num*i); }
    }

    // 8: Multiplication table 1-10
    {
        for(int i=1;i<=10;i++){
            for(int j=1;j<=10;j++){
                printf("%d * %d = %d\n",i,j,i*j);
            }
            printf("\n");
        }
    }

    // 9: Factorial
    {
        int n,fact=1;
        printf("Enter your number: ");
        scanf("%d",&n);
        if(n==0 || n==1) fact=1;
        else if(n>1){
            for(int i=1;i<=n;i++) fact*=i;
        } else { printf("Enter positive number\n"); return 1; }
        printf("%d\n",fact);
    }

    // 10: Print digits
    {
        int x;
        printf("Enter your number: ");
        scanf("%d",&x);
        while(x){ printf("%d\n",x%10); x/=10; }
    }

    // 11: Reverse number
    {
        int x,z=0;
        printf("Enter your number: ");
        scanf("%d",&x);
        int y=x;
        while(x){ z=z*10+x%10; x/=10; }
        printf("%d\n",z);
    }

    // 12: Print number digits in original order
    {
        int x,z=0;
        printf("Enter your number: ");
        scanf("%d",&x);
        int y=x;
        while(x){ z=z*10+x%10; x/=10; }
        while(z){ printf("%d\n",z%10); z/=10; }
    }

    // 13: Palindrome check
    {
        int x,z=0;
        printf("Enter your number: ");
        scanf("%d",&x);
        int y=x;
        while(x){ z=z*10+x%10; x/=10; }
        if(z==y) printf("Yes, it is palindrome\n");
        else printf("No, it is not palindrome\n");
    }

    // 14: Fibonacci n-th number
    {
        int n,a=0,b=1,next;
        printf("Enter the value of n: ");
        scanf("%d",&n);
        if(n<=1){ printf("1\n"); }
        for(int i=2;i<=n;i++){
            next=a+b;
            a=b;
            b=next;
        }
        printf("%d\n",b);
    }

    // 15: Prime check
    {
        int n,x=1;
        printf("Enter your number: ");
        scanf("%d",&n);
        if(n<=1) x=0;
        for(int i=2;i*i<=n;i++){ if(n%i==0){ x=0; break; } }
        if(x) printf("Yes, it is prime\n");
        else printf("No, it is not prime\n");
    }

    // 16: Guess game
    {
        int y,x;
        char input[10];
        srand(time(0));
        y=rand()%101;
        while(1){
            printf("Enter your guess (or Q to quit): ");
            scanf("%s",input);
            if(input[0]=='q' || input[0]=='Q') break;
            x=atoi(input);
            if(x==y){ printf("Congratulations!!\n"); break; }
            else if(x<y) printf("Higher\n");
            else printf("Lower\n");
        }
    }

    // 17: Triangle of numbers
    {
        int n,count;
        printf("Enter your number: ");
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            count=1;
            while(count<=i){ printf("%d",i); count++; }
            printf("\n");
        }
    }

    // 18: Square of stars
    {
        int n;
        printf("Enter your number: ");
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) printf("*");
            printf("\n");
        }
    }

    // 19: Right triangle of stars
    {
        int n,count;
        printf("Enter your number: ");
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            count=1;
            while(count<=i){ printf("*"); count++; }
            printf("\n");
        }
    }

    // 20: Number triangle
    {
        int n,num=1;
        printf("Enter your number: ");
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                printf("%d",num);
                num++;
            }
            printf("\n");
        }
    }

    // 21: Floyd's triangle
    {
        int n,x;
        printf("Enter your number: ");
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            x=(i%2==1)?1:0;
            for(int j=1;j<=i;j++){
                printf("%d",x);
                x=1-x;
            }
            printf("\n");
        }
    }

    // 22: Hollow square
    {
        int n;
        printf("Enter your number: ");
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0||i==n-1||j==0||j==n-1) printf("*");
                else printf(" ");
            }
            printf("\n");
        }
    }

    // 23: Hollow pyramid
    {
        int n;
        printf("Enter your value: ");
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i;j++) printf(" ");
            for(int j=1;j<=2*i-1;j++){
                if(j==1 || j==2*i-1 || i==n) printf("*");
                else printf(" ");
            }
            printf("\n");
        }
    }

    // 24: Triangle + square
    {
        int a,b;
        printf("Enter triangle height: ");
        scanf("%d",&a);
        printf("Enter square side length: ");
        scanf("%d",&b);
        for(int i=1;i<=a;i++){
            for(int j=1;j<=a-i;j++) printf(" ");
            for(int j=1;j<=2*i-1;j++){
                if(j==1||j==2*i-1) printf("*");
                else printf(" ");
            }
            printf("\n");
        }
        for(int i=0;i<b;i++){
            for(int j=0;j<b;j++){
                if(i==0||i==b-1||j==0||j==b-1) printf("* ");
                else printf("  ");
            }
            printf("\n");
        }
    }

    // 25: Armstrong number
    {
        int n,sum=0,temp,count=0;
        printf("Enter your number: ");
        scanf("%d",&n);
        temp=n;
        while(temp>0){ count++; temp/=10; }
        temp=n;
        while(temp>0){ int digit=temp%10; sum+=pow(digit,count); temp/=10; }
        if(sum==n) printf("Yes it is Armstrong number\n");
        else printf("No it is not\n");
    }

    // 26: Power
    {
        float a,x;
        printf("Enter number and power: ");
        scanf("%f %f",&a,&x);
        printf("%f\n",pow(a,x));
    }

    // 27: Digit conditions
    {
        int x;
        printf("Enter your number: ");
        scanf("%d",&x);
        // Implement a-f conditions similarly in own scope if needed
    }

    // 28: Arithmetic progression check
    {
        int x;
        printf("Enter your number: ");
        scanf("%d",&x);
        int y=-1,d=0,z=1;
        if(x<10){ printf("true\n"); }
        while(x){
            int c=x%10;
            x/=10;
            if(y==-1){ y=c; continue; }
            int b=c-y;
            if(d==0) d=b;
            else if(b!=d){ z=0; break; }
            y=c;
        }
        if(z) printf("true\n"); else printf("false\n");
    }

    // 29: Geometric progression check
    {
        int x;
        printf("Enter your number: ");
        scanf("%d",&x);
        int y=-1,z=1;
        double d=0;
        int temp=x;
        while(temp){ if(temp%10==0){ z=0; break; } temp/=10; }
        while(x){
            int c=x%10;
            x/=10;
            if(y==-1){ y=c; continue; }
            double b=(double)c/y;
            if(d==0) d=b;
            else if(b!=d){ z=0; break; }
            y=c;
        }
        if(z) printf("true\n"); else printf("false\n");
    }

    // 30: Hex representation
    {
        int x;
        printf("Enter your number: ");
        scanf("%d",&x);
        printf("%X\n",x);
    }

    // 31: Binary representation
    {
        int x;
        printf("Enter a number: ");
        scanf("%d",&x);
        for(int i=31;i>=0;i--){
            printf("%d",(x>>i)&1);
        }
        printf("\n");
    }



//Task 1 : Swap first and last digit of a number

{
    int num;
    printf("Task 1: Enter your number: ");
    scanf("%d", &num);
    int x = num;
    int y = num % 10;
    int power = 1;
    while(x >= 10){
        x /= 10;
        power *= 10;
    }
    int z = x;
    int middle = (num % power) / 10;
    int newNum = (y * power) + (middle * 10) + z;
    printf("After swapping first and last digits: %d\n\n", newNum);
}

//Task 2 : GCD of two numbers

    {
        int a, b;
        printf("Task 2: Enter two numbers for GCD: ");
        scanf("%d %d", &a, &b);
        int origA = a, origB = b;

        if(a < b){
            int temp = a;
            a = b;
            b = temp;
        }

        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        int gcd = a;
        printf("GCD of %d and %d is: %d\n\n", origA, origB, gcd);
    }

//Task 3: LCM of two numbers

    {
        int a, b;
        printf("Task 3: Enter two numbers for LCM: ");
        scanf("%d %d", &a, &b);
        int origA = a, origB = b;
        int gcdA = a, gcdB = b;

        // Compute GCD
        if(a < b){
            int temp = a;
            a = b;
            b = temp;
        }
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        int gcd = a;
        // Compute LCM
        int lcm = (origA * origB) / gcd;
        printf("LCM of %d and %d is: %d\n\n", origA, origB, lcm);
    }

//Pascals Triangle

   int n;
   printf("Enter your number: ");
   scanf("%d", &n);
   printPascalsTriangle(n);

   return 0;
}