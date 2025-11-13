#include <stdio.h>
#include <stdlib.h>
#include <stdmath.h>

//1

struct Date {
  int day;
  int month;
  int year;
};

int foo(int year) {
  if (year % 400 == 0) {
    return 1;
  }
  if (year % 100 == 0) {
    return 0;
  }
  if (year % 4 == 0) {
    return 1;
  }
  return 0;
}

int buzz(int month, int year) {
  switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    return 31;
    case 4: case 6: case 9: case 11:
    return 30;
    case 2:
      return foo(year) ? 29 : 28;
    default:
      return 0;
  }
}

int countdays(struct Date d) {
  int days = d.day;
  for (int i = 1; i <= d.month; i++) {
    days += buzz(i, d.year);
  }
  days += (d.year - 1) * 365;
  days += (d.year - 1)/4 - (d.year - 1) / 100 + (d.year - 1) / 400;
  return days;
}

int dateDifference(struct Date d1, struct Date d2) {
  int n1 = countdays(d1);
  int n2 = countdays(d2);
  return abs(n2 - n1);
}

int main() {
  struct Date d1 = {10,4,2020};
  struct Date d2 = {25,4,2023};
  printf("%d\n", dateDifference(d1, d2));
  return 0;
}

//2

struct Point {
  int x;
  int y;
};

float calculateDistance(struct Point p1, struct Point p2) {
  int dx = p2.x - p1.x;
  int dy = p2.y - p1.y;
  return sqrt(dx*dx + dy*dy);
}

int main() {
  struct Point p1 = {15,4};
  struct Point p2 = {25,10};
  printf("%f\n", calculateDistance(p1, p2));
  return 0;
}

//3

struct Student {
  char name[50];
  int grade;
};

int main() {
  int n;
  printf("Enter number of students: ");
  scanf("%d", &n);
  struct Student students[n];
  for (int i = 0; i < n; i++) {
    printf("Enter student name and grade: ");
    scanf("%s", &students[i].name);
    scanf("%d", &students[i].grade);
  }
  for (int i = 0; i < n; i++) {
    if (students[i].grade >= 85) {
      printf("%s\n", students[i].name);
    }
  }
  return 0;
}

//4

struct Book {
  char title[100];
  char author[500];
  float price;
};

void inputBookData(struct Book *book) {
  printf("Please enter the title: ");
  getchar();
  fgets(book->title, sizeof(book -> title), stdin);
  printf("Please enter the author of your book: ");
  fgets(book->author, sizeof(book -> author), stdin);
  printf("Please enter the price: ");
  scanf("%f", &book->price);
}

void printBookData(struct Book book) {
  printf("Book:\n");
  printf("Title: %s\n", book.title);
  printf("Author: %s\n", book.author);
  printf("Price: %.2f dollars\n", book.price);
}

int main() {
  int n;
  printf("Enter number of books: ");
  scanf("%d", &n);
  struct Book books[n];
  for (int i = 0; i < n; i++) {
    printf("Enter info about your book:\n ");
    inputBookData(&books[i]);
  }

  printf("Here they are:\n");
  for (int i = 0; i < n; i++) {
     printBookData(books[i]);
  }
  return 0;
}

//5

struct BankAccount {
  int accountNumber;
  char holderName[50];
  float balance;
};

void deposit(struct BankAccount *account, float amount) {
  if (amount > 0) {
    account->balance += amount;
    printf("You have added you balance with %2.f dollars\n",amount);
  }else {
    printf("Enter the valid amount:\n");
  }
}

void withdraw(struct BankAccount *account, float amount) {
  if (amount > 0) {
    if (account->balance >= amount) {
      account->balance -= amount;
      printf("Your have cashed %2.f dollars:\n",amount);
    }else {
      printf("Your balance is not enough:\n");
    }
  }else {
    printf("Enter the valid amount:\n");
  }
}

void displayAccount(struct BankAccount account) {
  printf("Account number:%d\n",account.accountNumber);
  printf("Account holder name:%s\n",account.holderName);
  printf("Account balance:%.2f\n",account.balance);
}

int main() {
  struct BankAccount myAccount = {145480138,"Bob Marley",1000000};
  displayAccount(myAccount);
  deposit(&myAccount,2000);
  withdraw(&myAccount,3000);
  displayAccount(myAccount);
  return 0;
}

//6

struct Movie {
  char title[500];
  char director[500];
  int releaseYear;
  float rating;
};

void inputMovieData(struct Movie *m) {
  printf("Please enter the title of movie: ");
  getchar();
  fgets(m->title, sizeof(m -> title), stdin);
  printf("Please enter the director of movie: ");
  fgets(m->director, sizeof(m -> director), stdin);
  printf("Please enter the year of release: ");
  scanf("%d", &m->releaseYear);
  printf("Please enter the rating of movie: ");
  scanf("%f", &m->rating);
}

void printMovieData(struct Movie m) {
  printf("Movie:\n");
  printf("Title: %s", m.title);
  printf("Director: %s", m.director);
  printf("Release year:%d", m.releaseYear);
  printf("Rating: %.2f\n", m.rating);
  printf("\n");
}

int main() {
  int n;
  printf("Enter number of movies: ");
  scanf("%d", &n);
  struct Movie films[n];
  for (int i = 0; i < n; i++) {
    printf("Enter info about your movie:\n ");
    inputMovieData(&films[i]);
    printf("\n");
  }

  printf("Here they are:\n");
  printf("\n");
  for (int i = 0; i < n; i++) {
     printMovieData(films[i]);
  }
  return 0;
}