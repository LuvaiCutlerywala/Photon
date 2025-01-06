#include "include/lexer.h"

#include <stdlib.h>
#include <stdio.h>
#include <logging/logger.h>

int main(int argc, char** argv) {
    LEXER* lexer = init_lexer("string name = \"john doe\";"
"print(name)");
    info("main.main", "Initialised lexer.");
    const TOKEN* token = next_token(lexer);
    while (token != NULL) {
        printf("TOKEN: (%d, %s)\n", token->type, token->value);
        token = next_token(lexer);
    }
    info("main.main", "Finished parsing file.");
    return 0;
}
