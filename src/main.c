#include "include/lexer.h"
#include "include/reader.h"
#include "include/parser.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    char* contents = read_file("../examples/main.pht");
    LEXER* lexer = init_lexer(contents);
    PARSER* parser = init_parser(lexer);
    AST_NODE* root = parse(parser);

    printf("%d\n", root->type);
    printf("%lu\n", root->compound_size);
    return 0;
}
