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

int main () {
    int s_num = 0;
}

int printStage (int stage_num, char *line, char *input, char *output, int num_args, char *arg_list) {
    printf("--------\n");
    printf("Stage %d: \"%s\"\n", stage_num, line);
    printf("--------\n");
    printf("     input: \n");
    printf("    output: \n");
    printf("      argc: %d\n", num_args);
    printf("      argv: \n");
}
