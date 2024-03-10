#ifndef COUNTING_H
#define COUNTING_H

#include <ctype.h>
#include <stdio.h>
#include <string.h>

long byte_count(FILE *stream);
long line_count(FILE *stream);
long word_count(FILE *stream);
long char_count(FILE *stream);

#endif // !COUNTING_H
