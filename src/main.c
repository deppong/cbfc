#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TOK_SIZE 4096

char input[] ={
    "1 + 2 + 3;"
};

typedef enum {
    literal,
    operator,
    semi,
    separator
}token_type_t ;

// TODO: a hashmap here would be kinda awesome
typedef struct token_t {
    token_type_t type;
    char data[64]; 
} token_t;

token_t* lex() {

    token_t *tokens = malloc(sizeof(token_t) * MAX_TOK_SIZE);
    int tok_curr_pos = 0;

    int exit_flag = 0;
    for (char *curr = input; *curr && !exit_flag; ++curr){
        // find the next nonblank char
        if (isspace(*curr)) ++curr;

        switch (*curr) {
            case EOF: exit_flag = 1; break;
            case ';': tokens[tok_curr_pos] = (token_t) {.type = semi, .data = '\0' };break; 
            case '=': break;
            case '+': tokens[tok_curr_pos] = (token_t) {.type = operator, .data = "+" };break; 
            case '*': break;
            default:
                if (!isalnum(*curr)) {
                    fprintf(stderr, "Ignoring <%c>\n", *curr);
                } else {
                    fprintf(stdout, "found literal <%c>\n", *curr);
                }
        }

    }
    return tokens; 
}

int main(void) {
    lex();
    return 0;
}
