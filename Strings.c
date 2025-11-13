#include <stdio.h>
#include <string.h>
int main(){
   //1
   
   char str[] = "Barev dzez";
   int length = strlen(str);
   printf("%d\n", length);

   //2

   char string[] = "barev134dzez";
   int l = strlen(string);
   int index = -1;
   for(int i = 0; i < l; i++){
      if(string[i] >= '0' && string[i] <= '9'){
         index = i;
         break;
      }
   }
   printf("%d\n", index);

   //3

   char s[1000];
   printf("Enter your text:");
   fgets(s, sizeof(s), stdin);
   int l1 = strlen(s);
   for(int i = 0; i < l1; i++){
      if(s[i] >= '0' && s[i] <= '9'){
         printf("%c\n", s[i]);
      }
   }

   //4

   char s1[1000];
   printf("Enter your text: ");
   fgets(string, sizeof(s1), stdin);
   int l2 = strlen(s1);
   for(int i = 0; i < l2; i++){
      if(s1[i] >= 'a' && s1[i] <= 'z'){
         s1[i] = s1[i] - 32;
      }
   }
   printf("%s", s1);

   //5

   char s2[1000];
   printf("Enter your text: ");
   fgets(s2, sizeof(s2), stdin);
   int l3 = strlen(s2);
   if(s2[0] >= 'a' && s2[0] <= 'z'){
       s2[0] -= 32;
   }
   for(int i = 1; i < l3; i++){
      if(s2[i] >= 'A' && s2[i] <= 'Z'){
         s2[i] += 32;
      }
   }
   printf("%s", s2);
   return 0;
}

//strcat


 char* fstrcat(char *dest,const char *src){
   char *ptr = dest;
   while(*ptr != '\0'){
     ptr++;
  }
   while(*src != '\0'){
     *ptr++ = *src++;
   }
  *ptr = '\0';
  return dest;
 }

 int main(){
   char str1[100] = "Hey what's up, ";
   const char *str2 = "Fine, what about you?";
   fstrcat(str1,str2);
   printf("%s", str1);
   return 0;
 }

//strcpy

 char* fstrcpy(char *dest,const char *src){
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
    char dest[100] = "barev";
    const char *text = "Hi Everone";
    fstrcpy(dest,text);
    printf("%s\n", dest);
    return 0;
 }

//strcmp

 int fstrcmp(const char* str ,const char* str1) {
    size_t len = strlen(str);
    size_t len1 = strlen(str1);
    int min = 0;
    int max = 0;
    len > len1 ? min = len1 : min = len;
    len > len1 ? max = len : max = len1;
    if (min < max) {
       for (int i = 0; i < min; i++) {
          if (*(i+str) != *(str1+i)){
             return *(i+str) - *(i+str1);
          }
       }
       for (int i = min; i < max; i++) {
          return *(i+str) - *(str1+i);
       }
    }
    return 0;
 }

 int main() {
    const char* str1 = "Hello World";
    const char* str2 = "Hello World";
    int result = fstrcmp(str1,str2);
    if (result == 0) {
       printf("%d\n",0);
    }
    else {
       printf("%d\n",fstrcmp(str1,str2));
    }
 }

//Version 2

 int fstrcmp1(const char *s1, const char *s2) {
     while (*s1 && (*s1 == *s2)){
         s1++;
         s2++;
     }
         return *s1 - *s2;
 }

 int main() {
    const char *s1 = "hello world";
    const char *s2 = "hello wold";
    int result = fstrcmp1(s1, s2);
     printf("%d\n", result);

    return 0;
 }

//strlen

size_t fstrlen(const char *str){
    size_t length = 0;
    while(*(str + length) != '\0'){
        length++;
    }
   return length;
}

int main(){
    const char *text = "Barev dzez";
    size_t len = fstrlen(text);
    printf("%zu\n",len);
    return 0;
}

//strchr

#include <stdio.h>

char *fstrchr(const char *str, int c) {
    while (*str) {
        if (*str == (char)c) {
            return (char *)str;
        }
        str++;
    }
    if (c == '\0') {
        return (char *)str;
    }
    return NULL;
}

int main(){
   const char *text = "Barev dzez";
   char *result = fstrchr(text,'z');
   if(result != NULL){
      printf("%s\n",result);
   }else{
      printf("Not found");
    }
  return 0;
}
