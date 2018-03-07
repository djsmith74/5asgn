#ifndef PLINE_C
#define PLINE_C

typedef struct stage stage_stat

struct stage {
    int stage_num;
    char *c_line;
    char *input_line;
    char *output_line;
    int num_args;
    char **arguments;
}

#endif
