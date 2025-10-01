#include "lexer.h"


Lexer* lexer_create(FILE* file) {
  Lexer* l = malloc(sizeof(Lexer));
  l->column = 1;
  l->line = 1;
  l->pos = 0;
  l->file = file;
  return l;
}

void lexer_destroy(Lexer *lex) {
  free(lex->file);
  free(lex);
}



Vector* lexer_tokenize() {

}
