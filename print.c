/*print.c: prints the necessary info given in the struct list*/
#include "print.h"

void print(stage_stats **stats) {
   int i = 0;

   while (stats[i] != NULL) {
      print_stats(i, stats[i]);
      i++;
   }
}

void print_stats(int i, stage_stats *stg) {
   int k = 0;

      

   printf("\n\n--------\n");
   printf("Stage %d: \"%s\"\n", i, stg->c_line);
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
