/*print.c: prints the necessary info given in the struct list*/
#include "print.h"

void print(stage_stats **stats, char *buffer) {
   int i = 0;
   char *token;
  
   /*printf("buffer: %s\n", buffer); */
   token = strtok(buffer, "|");

   while (stats[i] != NULL && i < MAX_COMMANDS && token != NULL) {
      print_stats(i, stats[i], token);
      /*printf("index: %d\n", i);
      printf("stats[i]->num_args: %d\n", stats[i]->num_args);
      printf("token: %s\n", token); 
      printf("MAX_COMMANDS: %d\n", MAX_COMMANDS);*/
      token = strtok(NULL, "|");
      /*printf("token2: %s\n", token);*/
      i++;
   }
}

void print_stats(int i, stage_stats *stg, char *line) {
   int k = 0;
   /*int j = 0;
   char *line = calloc(;
   int mystg = 0;*/

   /*while (mystg < i) {
      if (!(buffer[j][0] == '|')) {
         j++;
      }
      else {
         j++;
         mystg++;
      }
   }

   if (mystg != 0) {
      strcat(line, " ");
   }

   while (!(buffer[j][0] != '|')) {
      strcat(line, buffer[j];
      j++
   }

   if (mystg
*/
   printf("\n--------\n");
   printf("Stage %d: \"%s\"\n", i, line);
   printf("--------\n");

   if (stg->input_line == NULL) {
      printf("     input: pipe from stage %d\n", i - 1);
   }
   else {
      printf("     input: %s\n", stg->input_line);
   }

   if (stg->output_line == NULL) {
      printf("    output: pipe to stage %d\n", i + 1);
   }
   else {
      printf("    output: %s\n", stg->output_line);
   }

   printf("      argc: %d\n", stg->num_args);
   printf("      argv: ");

   for (; k < stg->num_args - 1; k++) {
      printf("\"%s\",", stg->arg_list[k]);
   }

   printf("\"%s\"\n", stg->arg_list[k]);
}
