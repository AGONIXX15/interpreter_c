#include "utils/vector.h"
#include <string.h>



Vector* vector_create(size_t size) {
  Vector* v = malloc(sizeof(Vector));
  v->size = size;
  v->data = malloc(size * 4);
  v->capacity = 4;
  v->length = 0;
  return v;
}

void* vector_get(Vector *v, size_t index) {
  return (unsigned char*)(v->data + index * v->size);
}

void vector_push(Vector *v, void *element) {
  if(v->length == v->capacity) {
    v->capacity *= 2;
    v->data = realloc(v->data, v->capacity * v->size);
  }


  void* dest = vector_get(v, v->length);
  memcpy(dest, element, v->size);
  v->length++;
}

void vector_destroy(Vector *v) {
  free(v->data);
  free(v);
}




