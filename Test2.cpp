/*Test 2 2021*/

#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<ctype.h>


/*this creates a 2d array for keywords*/


int isKeyword(char buffer[]){

 char keywords[29][10] = {"auto","break","char","character","const","double","default",

       "do","else","enum","extern","float","for","goto",

       "int","if","long","return","short","signed",

       "sizeof","static","struct","switch","typedef",

       "unsigned","void","volatile","while"};

 int i, flag = 0;

 for(i = 0; i < 29; ++i){

  if(strcmp(keywords[i], buffer) == 0){

   flag = 1;

   break;

  }

 }

 return flag;

}

int main(){

 char ch, buffer[15], operators[] = "+-*/%=";

 FILE *fp;

 int i,j=0;

 fp = fopen("test2.txt","r"); /* im using fopen function to open this file*/

 if(fp == NULL){

  printf(" There was an error opening the file\n");

  exit(0);

 }

 

 while((ch = fgetc(fp)) != EOF){

     for(i = 0; i < 6; ++i){

      if(ch == operators[i])

       printf("%c is operator\n", ch); /*printing out operator*/

     }

     if(isalnum(ch)){

      buffer[j++] = ch;

     }

     else if((ch == ' ' || ch == '\n') && (j != 0)){

       buffer[j] = '\0';

       j = 0;

       if(isKeyword(buffer) == 1)

        printf("%s is keyword\n", buffer); /*printing out keyword*/


       else

        printf("%s is indentifier\n", buffer);/*printing out perl style identifier*/


     }

 }

 fclose(fp);

return 0;

}