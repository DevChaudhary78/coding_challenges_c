#include <ctype.h>
#include <stdio.h>
#include <string.h>

long byte_count(char *filename);
long line_count(char *filename);
long word_count(char *filename);
long char_count(char *filename);

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s -c <filename>\n", argv[0]);
    return -1;
  }
  long answer = -1;
  char *filename = argv[2];

  if (strcmp(argv[1], "-c") == 0) {
    answer = byte_count(filename);
  } else if (strcmp(argv[1], "-l") == 0) {
    answer = line_count(filename);
  } else if (strcmp(argv[1], "-w") == 0) {
    answer = word_count(filename);
  } else if (strcmp(argv[1], "-m") == 0) {
    answer = char_count(filename);
  }

  if (answer != -1) {
    printf("%ld\t%s\n", answer, filename);
  } else {
    printf("Error reading file\n");
  }

  return 0;
}

long byte_count(char *filename) {
  FILE *fptr = fopen(filename, "rb");
  if (fptr == NULL) {
    return -1;
  }

  fseek(fptr, 0, SEEK_END);
  long size = ftell(fptr);

  fclose(fptr);
  return size;
}

long line_count(char *filename) {
  FILE *fptr = fopen(filename, "r");
  if (fptr == NULL) {
    return -1;
  }

  long count = 0;

  for (char c = fgetc(fptr); c != EOF; c = fgetc(fptr)) {
    if (c == '\n') {
      count++;
    }
  }

  fclose(fptr);

  return count;
}

long word_count(char *filename) {
  FILE *fptr = fopen(filename, "r");
  if (fptr == NULL) {
    return -1;
  }

  long count = 0;
  int in_word = 0;
  int c;

  while ((c = fgetc(fptr)) != EOF) {
    if (isspace(c)) {
      in_word = 0;
    } else if (!in_word) {
      count++;
      in_word = 1;
    }
  }

  fclose(fptr);

  return count;
}

long char_count(char *filename) {
  FILE *fptr = fopen(filename, "r");
  if (fptr == NULL) {
    return -1;
  }

  long count = 0;

  for (char c = getc(fptr); c != EOF; c = getc(fptr)) {
    count++;
  }

  fclose(fptr);

  return count;
}
