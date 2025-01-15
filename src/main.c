#include "include/lexer.h"
#include "include/reader.h"
#include "include/parser.h"
#include "include/visitor.h"

int main(int argc, char** argv) {
    char* contents = read_file("../examples/main.pht");
    LEXER* lexer = init_lexer(contents);
    PARSER* parser = init_parser(lexer);
    AST_NODE* root = parse(parser);
    VISITOR* visitor = init_visitor();
    visit(visitor, root);
    return 0;
}
