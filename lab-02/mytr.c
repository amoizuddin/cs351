#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int translate(char to_rplc[], char rplmnt[],char* mystr);
char* delete(char rplmnt[],char* mystr);
void removeC(char *s, int c);
int main(int argc, char *argv[]) 
{
  char buffer[100000];
  char *del="-d";
  char *newstr;
  if (argc < 3) 
  {
    printf("Usage: %s STRING1 STRING2\n", argv[0]);
    printf("       %s -d STRING\n", argv[0]);
    exit(1);
  }
  
  if(strcmp(argv[1],del)==0)
  {
    while (fgets(buffer, sizeof(buffer), stdin) != 0)
    {
      newstr = delete(argv[2],buffer);
      strcpy(buffer,newstr);
      printf("%s", buffer);
    }
    exit(0);
  }
  else if(strlen(argv[1]) != strlen(argv[2]))
  {
      printf("STRING1 and STRING2 must have the same length\n");
      exit(1);
  }
  else
  {
    while (fgets(buffer, sizeof(buffer), stdin) != 0)
    {
      translate(argv[1], argv[2], buffer);
      printf("%s", buffer);
    }
    exit(0);
  }
  return 0;
}


  //get string from user

int translate(char to_rplc[], char rplmnt[],char* mystr)
{
  int num_chars = strlen(rplmnt);
  int cursor;
  int mystr_len = strlen(mystr);
  char map[num_chars][2];
  int y;

  //populating map
  for (cursor = 0; cursor < num_chars; cursor++)
  {
    map[cursor][0] = to_rplc[cursor];//make map at key= first letter of first param
    map[cursor][1] = rplmnt[cursor];//make map at value = first letter of second param
  }
  //traverse thru the string
  //check each letter to see if it is in the keys.
  //it it is in the keys. then replace it with the value at that key

  for(cursor = 0; cursor < mystr_len;cursor++)
  {
    for(y=0;y<num_chars;y++)
    {
      //if the
      if(mystr[cursor]==map[y][0])
      {
       mystr[cursor] = map[y][1];
      }
    }
  } 
  return 0;
}

char* delete(char rplmnt[],char* mystr)
{
  int x;
  for(x = 0; x < strlen(rplmnt);x++)
  {
    removeC(mystr,rplmnt[x]);
  }
  return mystr;
}


void removeC(char *s, int c){ 
  
    int j, n = strlen(s); 
    for (int i=j=0; i<n; i++) 
       if (s[i] != c) 
          s[j++] = s[i]; 
      
    s[j] = '\0'; 
} 