/*

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>


char *strrstr(char *s1, char *s2){
  char *ret = s1;
  char *aux = s1;
  while(true){
    ret = aux;
    aux = strstr(aux+1, s2);
    if(aux == NULL)
      return ret;
  }
}

int main(){
  char haystack[] = "TutorialPointPoint";
  char needle[] = "Point";

  char *ret;
  ret = strrstr(haystack, needle);
  printf("%s\n", ret);
  return 0;
}