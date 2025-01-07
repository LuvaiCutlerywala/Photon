#include "include/lexer.h"
#include "include/reader.h"

#include <logging/logger.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    char* contents = read_file("../examples/main.pht");
    LEXER* lexer = init_lexer(contents);
    const TOKEN* token = next_token(lexer);
    while (token != NULL) {
        printf("TOKEN: (%d, %s)\n", token->type, token->value);
        token = next_token(lexer);
    }
    info("main.main", "Initialised lexer.");
    return 0;
}
