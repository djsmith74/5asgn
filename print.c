/*print.c: prints the necessary info given in the struct list*/
#include "print.h"

void print(stage_stats **stats) {
   stage_stats *stg;
   int i = 0;

   while (stats[i] != NULL) {
      print_stats(i, stage_stats[i]);
      i++;
   }
}

void print_stats(int i, stage_stats stg) {
   int i = 0;

   printf("\n\n--------\n");
   printf("Stage %d: \"%s\"\n", i, stg->c_line);
   printf("--------\n");
   printf("     input: %s\n", stg->input_line);
   printf("    output: %s\n", stg->output_line);
   printf("      argc: %d\n", stg->num_args);
   printf("      argv: ");

   for (; i < stg->num_args - 1; i++) {
      printf("\"%s\",", stg->arg_list[i]);
   }

   printf("\"%s\"\n", stg->arg_list[i]);
}
