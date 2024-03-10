#include "wc.h"
#include "counting.h"

int main(int argc, char **argv) {
  FILE *stream;

  if (argc < 2) {
    printf("Usage: %s -[m|l|c|w] <filename>\n", argv[0]);
    return -1;
  }

  if (argc == 3) {
    char *filename = argv[2];
    stream = fopen(filename, "r");

    if (stream == NULL) {
      printf("Failed to open stream!\n");
      return -1;
    }

    long answer = -1;

    if (strcmp(argv[1], "-c") == 0) {
      answer = byte_count(stream);
    } else if (strcmp(argv[1], "-l") == 0) {
      answer = line_count(stream);
    } else if (strcmp(argv[1], "-w") == 0) {
      answer = word_count(stream);
    } else if (strcmp(argv[1], "-m") == 0) {
      answer = char_count(stream);
    }

    printf("%ld\t%s\n", answer, filename);

    fclose(stream);
  }

  else if (argc == 2) {
    if (strcmp(argv[1], "-m") == 0 || strcmp(argv[1], "-w") == 0 ||
        strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "-c") == 0) {
      stream = stdin;

      long answer = -1;

      if (strcmp(argv[1], "-c") == 0) {
        answer = char_count(stream);
      } else if (strcmp(argv[1], "-l") == 0) {
        answer = line_count(stream);
      } else if (strcmp(argv[1], "-w") == 0) {
        answer = word_count(stream);
      } else if (strcmp(argv[1], "-m") == 0) {
        answer = byte_count(stream);
      }

      printf("%ld\n", answer);

    } else {
      char *filename = argv[1];
      stream = fopen(filename, "r");

      if (stream == NULL) {
        printf("Error opening file!\n");
        return -1;
      }

      printf("%ld\t%ld\t%ld\t%s\n", byte_count(stream), line_count(stream),
             word_count(stream), filename);
    }
  } else {
    printf("Invalid number of arguments!\n");
    return -1;
  }

  return 0;
}
