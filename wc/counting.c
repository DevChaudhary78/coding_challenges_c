#include "counting.h"

long byte_count(FILE *stream) {
  fseek(stream, 0, SEEK_END);
  long size = ftell(stream);
  rewind(stream);

  return size;
}

long line_count(FILE *stream) {
  long count = 0;

  for (char c = fgetc(stream); c != EOF; c = fgetc(stream)) {
    if (c == '\n') {
      count++;
    }
  }
  rewind(stream);
  return count;
}

long word_count(FILE *stream) {
  long count = 0;
  int in_word = 0;
  int c;

  while ((c = fgetc(stream)) != EOF) {
    if (isspace(c)) {
      in_word = 0;
    } else if (!in_word) {
      count++;
      in_word = 1;
    }
  }
  rewind(stream);
  return count;
}

long char_count(FILE *stream) {
  long count = 0;

  for (char c = fgetc(stream); c != EOF; c = fgetc(stream)) {
    count++;
  }
  rewind(stream);
  return count;
}
