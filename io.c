/*io.c: handles all i/o required for command line*/
#include "io.h"


/*returns a char pointer to the whole line input by the user*/
void get_input(char *input) {
   int c;

   printf("line: ");

   if (fgets(input, MAX_IN + 1, stdin) == NULL) {
      printf("invalid null command\n");
      exit(EXIT_FAILURE);
   }

   if (input[MAX_IN] != '\0') {
      printf("command too long\n");
      exit(EXIT_FAILURE);
   }

   c = strlen(input);
   input[c - 1] = '\0';

   printf("input: %s\n", input);
}


/*cuts up the input string*/
void divide_line(char *input, char **buffer) {
   char d[1] = {' '};
   char *token;
   int i = 0;

   /*get the first token*/
   token = strtok(input, d);

   /*walk through other tokens*/
   while (token != NULL) {
      buffer[i] = token;
      printf("%d: %s\n", i, token);
      token = strtok(NULL, d);
      i++;
   }

}
