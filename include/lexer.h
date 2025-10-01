#ifndef LEXER_H
#define LEXER_H
#include "utils/vector.h"
#include <stdio.h>

typedef struct Lexer Lexer;


struct Lexer {
  FILE* file;
  // vector of tokens
  Vector* v; 
  size_t pos;
  size_t line;
  size_t column;
};



Lexer* lexer_create(FILE* file);


void lexer_destroy(Lexer* lex);


// returns a vector of tokens
Vector* lexer_tokenize();

#endif
