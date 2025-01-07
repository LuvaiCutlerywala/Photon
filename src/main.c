#include "include/lexer.h"

#include <stdlib.h>
#include <stdio.h>
#include <logging/logger.h>

int main(int argc, char** argv) {
    LEXER* lexer = init_lexer("3.141592654");
    info("main.main", "Initialised lexer.");
    const TOKEN* token = next_token(lexer);
    printf("%s\n", token->value);
    info("main.main", "Finished parsing file.");
    return 0;
}
