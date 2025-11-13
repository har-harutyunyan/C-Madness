//1

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fptr = fopen("test.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    const char* str = "Hello what is your name";
    size_t len = strlen(str);
    size_t countW = fwrite(str, 1, len, fptr);
    if (countW != len) {
        perror("Error writing to file");
        fclose(fptr);
        return -1;
    }
    fclose(fptr);
    fptr = fopen("test.txt", "r");
    if (fptr == NULL) {
        perror("Error opening file");
        return -1;
    }
    char buffer[100] = {0};
    size_t countR = fread(buffer, 1, len, fptr);
    if (countR != len) {
        perror("Error reading from file");
        fclose(fptr);
        return -1;
    }
    printf("%s\n", buffer);
    fclose(fptr);
    return 0;
}

//2

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr = fopen("input.txt", "r+");
    if (!fptr) {
        perror("File open error");
        return 1;
    }
    char ch;
    long pos = 0;
    while ((ch = fgetc(fptr)) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            fseek(fptr, pos, SEEK_SET);
            fputc(ch + 32, fptr);
        }
        pos++;
    }
    fclose(fptr);
    return 0;
}

//3

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fptr = fopen("input.txt", "r");
    if (fptr == NULL) {
        perror("Error opening file");
        return -1;
    }
    int digits[10] = {0};
    int ch;
    while ((ch = fgetc(fptr)) != EOF) {
        if (ch >= '0' && ch <= '9') {
            digits[ch - '0']++;
        }
    }
    fclose(fptr);
    printf("Digit counts:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d: %d\n", i, digits[i]);
    }
    return 0;
}

//4

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr = fopen("input.txt", "r");
    if (fptr == NULL) {
        perror("Error opening file");
        return 1;
    }
    int length = 20;
    char buffer[21];
    size_t r1 = fread(buffer, 1, length, fptr);
    buffer[r1] = '\0';
    printf("First time: %s\n", buffer);
    rewind(fptr);
    size_t r2 = fread(buffer, 1, length, fptr);
    buffer[r2] = '\0';
    printf("Second time: %s\n", buffer);
    fclose(fptr);
    return 0;
}

//5

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr1 = fopen("a.txt", "r");
    if (fptr1 == NULL) {
        perror("Error opening file");
        return 1;
    }
    fseek(fptr1, 0, SEEK_END);
    long size = ftell(fptr1);
    rewind(fptr1);
    char *buf = (char *)malloc(size + 1);
    if (buf == NULL) {
        perror("Memory allocation error");
        fclose(fptr1);
        return 1;
    }

    fread(buf, 1, size, fptr1);
    buf[size] = '\0';
    fclose(fptr1);
    FILE *fptr2 = fopen("b.txt", "w");
    if (fptr2 == NULL) {
        perror("Error opening file");
        free(buf);
        return 1;
    }
    for (long i = size - 1; i >= 0; i--) {
        fputc(buf[i], fptr2);
    }
    fclose(fptr2);
    free(buf);
    return 0;
}

//6

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr = fopen("input.txt", "r");
    if (fptr == NULL) {
        perror("Error opening file");
        return 1;
    }
    char line[1024];
    while (fgets(line, sizeof(line), fptr)) {
        printf("%s", line);
    }
    fclose(fptr);
    return 0;
}


//7

#include <stdio.h>
#include <stdlib.h>

int is_space(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r' || ch == ',';
}

int main() {
    const char *name = "input.txt";
    FILE *fptr = fopen(name, "r");
    if (fptr == NULL) {
        perror("Error opening file");
        return 1;
    }
    int lines = 0;
    int words = 0;
    int space = 0;
    int ch;
    fseek(fptr, 0, SEEK_END);
    int size = ftell(fptr);
    rewind(fptr);
    while ((ch = fgetc(fptr)) != EOF) {
        if (ch == '\n')
            lines++;

        if (is_space(ch)) {
            space = 0;
        } else if (!space) {
            words++;
            space = 1;
        }
    }
    fclose(fptr);
    printf("File size in bytes:%d\n",size);
    printf("Words in file:%d\n",words);
    printf("Lines in file:%d\n",lines);
    return 0;
}

//8

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    printf("Enter your number: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Enter a positive number");
        return 1;
    }
    FILE *fptr = fopen("factorials.txt", "w");
    if (fptr == NULL) {
        perror("Error opening file");
        exit(1);
    }
    unsigned long long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
        fprintf(fptr, "%llu", factorial);
        if (i != n) {
            fprintf(fptr, ",");
        }
    }
    fclose(fptr);
    return 0;
}

//9

#include <stdio.h>
#include <string.h>

int main() {
    FILE *file = fopen("input.txt", "a");
    if (file == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }
    char word[100];
    while (1) {
        printf("Enter a word (or type 'exit' to stop): ");
        scanf("%s", word);
        if (strcmp(word, "exit") == 0) {
            break;
        }
        fprintf(file, "%s\n", word);
    }
    fclose(file);
    printf("Program ended.\n");
    return 0;
}

//10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}

int is_symbol(char c) {
    char *symb = ".,!?;:\"()[]{}<>-'";
    for (int i = 0; symb[i]; i++) {
        if (c == symb[i])
            return 1;
    }
    return 0;
}

void replace_symbols(char *str) {
    for (int i = 0; str[i]; i++) {
        if (is_symbol(str[i])) {
            str[i] = ' ';
        }
    }
}


void add_word(WordCount *words, int *word_count, char *word) {
    for (int i = 0; i < *word_count; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }
    strcpy(words[*word_count].word, word);
    words[*word_count].count = 1;
    (*word_count)++;
}

int compare(const void *a, const void *b) {
    return strcmp(((WordCount*)a)->word, ((WordCount*)b)->word);
}

int main() {
    FILE *infile = fopen("text.txt", "r");
    FILE *outfile = fopen("statistics.txt", "w");

    if (!infile || !outfile) {
        printf("Cannot open file.\n");
        return 1;
    }

    WordCount words[MAX_WORDS];
    int word_count = 0;
    char buffer[MAX_WORD_LEN];

   char line[1024];
   while (fgets(line, sizeof(line), infile)) {
       replace_symbols(line);
       to_lowercase(line);
       char *token = strtok(line, " \t\n");
      while (token != NULL) {
          add_word(words, &word_count, token);
          token = strtok(NULL, " \t\n");
      }
   }


    qsort(words, word_count, sizeof(WordCount), compare);

    for (int i = 0; i < word_count; i++) {
        fprintf(outfile, "%s: %d\n", words[i].word, words[i].count);
    }

    fclose(infile);
    fclose(outfile);
    return 0;
}

