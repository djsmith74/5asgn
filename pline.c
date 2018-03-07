/* MACROS
 *  - COMMAND_LINE_LEN 512
 *  - NUM_COMMANDS 10
 *  - NUM_ARGS 10
 * DATA STRUCTURE
 *  - Com_line
 *      - input string
 *      - output string
 *      - num_args
 *      - args
 * 1) Check command line length
 *      - if exceeds -> ERROR
 * 2) strtok everything, separating by white spaces
 *      - while haven't reached the end of the line
 *          - SET FLAGS
 *
 *          - if word is "|"
 *              - double check that the next argument is not another "|"
 *                  - if is -> ERROR
 *                  - if not -> 
 *              - create a new data struct?
 *          - if word is "<"
 *              - check that there is a filename after 
 *                  - if not -> ERROR
 *                  - if is -> fill "input string"
 *          - if word is ">"
 *              - check that there is a filename after
 *                  - if not -> ERROR
 *                  - if is -> fill "output string"
 *          - if 
 *
 * 2) strtok everything, separating by white spaces
 *      - while haven't reached the end of the line
 *          CHECK FLAGS
 *          - if was "<"
 *              - if current word is not "<", ">", or "|"
 *                 - if is -> ERROR
 *              - if "input redirection has occured" flag has been set
 *                 - if is -> ERROR
 *              - else -> fill "input string"
 *                 - set flag saying input redirection has occured
 *          - else if was ">"
 *              - if current word is not "<", ">", or "|"
 *                 - if is -> ERROR
 *              - if "output redirection had occured" flag has been set
 *                 - if is -> ERROR
 *              - else -> fill "output string"
 *                 - set flag saying output redirection has occured
 *          - else if was "|"
 *              - if nothing in "input string"
 *                 - set input to "original stdin"
 *              - if nothing in "output string"
 *                 - set output to "original stdout"
 *              - check if current is "|"
 *                 - if is -> ERROR
 *              - if not -> create a new data struct???
 *          - else 
 *              - add the string to argv
 *              - increase argv index count
 *              - increase argc
 *
 *          SET FLAGS
 *          - if is "<"
 *              - set the "<" flag
 *          - if is ">"
 *              - set the ">" flag
 *          - if is "|" 
 *              - set the "|" flag
 *
 * Bad Idea:
 * Have a bunch of storage variables and keep adding to them when you get more stuff
 * Keep track of index in the argv[] so that at the end you can just print the argv[index]
 *
 * Questions:
 * How do we know what was the input from before pipe?
 * 
 * How to find num of stages - count the num times a pipe appears and add 1
 *
 * Do we print each stage or at the end? if at the end, how do we keep all info 
 * 
 * What do we need to use the parsing for?
 */
#include "io.c"
#include "pline.h"

int main (int argc, char *argv[]) {
    int s_num = 0;
    
    /* FLAGS */
    int found_input;
    int found_output;
    int found_pipe;
    int found_in_redir;
    int found_out_redir;
    int found_arg;

    /* VARIABLES */
    int max;
    int args_index;
    int stage_num;
    int pipe_num;
    char *line;
    char *input;
    char *output;
    int num_args;
    char *arguments[10] = {NULL};
    stage_stats *stage_list[10] = {NULL};
    int i;
    int j;
    int struct_index;

    /* INITIATION */
    char stdin_line[] = "original stdin";
    char stdout_line[] = "original stdout";

    char in_line[513] = {0};
    char *buffer[512];

    input = stdin_line;
    output = stdout_line;
     
    found_input = 0; 
    found_output = 0;
    found_in_redir = 0;
    found_out_redir = 0;
    found_pipe = 0;
    found_arg = 0;

    struct_index = 0;
    args_index = 0;
    num_args = 0;
    pipe_num = 0;
 
    /* THE START! */
    get_input(in_line);
    max = divide_line(in_line, buffer);
    printf("buffer size: %d\n", max);
    
    i = 0;   

    while ( i < max ) {
        /* CHECK FLAGS */
        /*printf("--------------\n");*/
        if (found_input) {
            if (strcmp(buffer[i], "<") == 0 || strcmp(buffer[i], ">") == 0 || strcmp(buffer[i], "|") == 0) {
                printf("cmd: bad input redirection\n");
                exit(EXIT_FAILURE);
            }
            else if (found_in_redir) {
                printf("cmd: bad input redirection\n");
                exit(EXIT_FAILURE);
            }
            else {
                input = buffer[i];
                /*found_input = 0;*/
                found_in_redir = 1;
                printf("input filename: %s\n", input);
            }
        }
        else if (found_output) {
            if (strcmp(buffer[i], "<") == 0 || strcmp(buffer[i], ">") == 0 || strcmp(buffer[i], "|") == 0) {
                printf("cmd: bad output redirection\n");
                exit(EXIT_FAILURE);
            }
            else if (found_out_redir) {
                printf("cmd: bad output redirection\n");
                exit(EXIT_FAILURE);
            }
            else {
                output = buffer[i];
                /*found_output = 0;*/
                found_out_redir = 1;
                printf("output filename: %s\n", output);
            }
        }
        else if (found_pipe) {
            if (strcmp(buffer[i], "|")) {
                printf("invalid null command\n");
                exit(EXIT_FAILURE);
            }
            else {
                stage_list[struct_index] = createStage(input, output, num_args, arguments);
                found_pipe = 0;

                input = stdin_line;
                output = stdout_line;
                num_args = 0;
                for (j = 0; j < MAX_ARGS; j++) {
                   arguments[j] = '\0';
                }

                pipe_num++;

                if (pipe_num > 10) {
                    printf("pipeline too deep\n");
                    exit(EXIT_FAILURE);
                }
                struct_index++;
            }
        }    

        /* SET FLAGS */
        if (strcmp(buffer[i], "<") == 0) {
            /*printf("found <\n");*/
            found_input = 1;
        }
        else if (strcmp(buffer[i], ">") == 0) {
            /*printf("found >\n");*/
            found_output = 1;
        }
        else if (strcmp(buffer[i], "|") == 0) {
            found_pipe = 1;
        }
        else if (found_input == 1 || found_output == 1) {
            /*printf("found arg\n");*/
            found_arg = 0;
            found_input = 0;
            found_output = 0;
        }
        else {
            found_arg = 1;
        }

        if (found_arg) {
            arguments[args_index] = buffer[i];
            printf("argument: %s\n", arguments[args_index]);
            found_arg = 0;
            args_index++;
            num_args++;
        }

        i++;
    }
} 
 
stage_stats *createStage(char *input, char *output, int num_args, char **arg_list) {
    stage_stats *new_stage;
    new_stage = calloc(1, sizeof(stage_stats));
    new_stage->input_line = input;
    new_stage->output_line = output;
    new_stage->num_args = num_args;
    new_stage->arg_list = arg_list;
    return new_stage;
}

/*
int printStage (int stage_num, char *line, char *input, char *output, int num_args, char *arg_list) {
    printf("--------\n");
    printf("Stage %d: \"%s\"\n", stage_num, line);
    printf("--------\n");
    printf("     input: \n");
    printf("    output: \n");
    printf("      argc: %d\n", num_args);
    printf("      argv: \n");
}*/
