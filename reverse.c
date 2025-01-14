#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>

/*void readLines(FILE *file);

int main(int argc, char *argv[]) {
    FILE *file;
    char *line = NULL;

    if (argc < 2) {
        file = stdin;
    } else {
        file = fopen(argv[1], "r");
        if (file == NULL) {
            fprintf(stderr, "error: cannot open file\n");
            exit(0);
        }
    }

    readLines(file);

    if (file != stdin) {
        fclose(file);
    }

    return 0;
}

void readLines(FILE *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1) {
        fprintf(stdout, "%s", line);
    }

    free(line);
} */

/*void readLines(FILE *file);

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[256];

    printf("Give file name or let empty to use stdin: ");
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        exit(1);
    }

    filename[strcspn(filename, "\n")] = '\0';

    if (strlen(filename) == 0) {
        printf("Reading from stdin (type input and press Ctrl+D to end):\n");
        file = stdin;
    } else {
        file = fopen(filename, "r");
        if (file == NULL) {
            fprintf(stderr, "error: cannot open file\n");
            exit(0);
        }
    }

    readLines(file);

    if (file != stdin) {
        fclose(file);
    }

    return 0;
}

void readLines(FILE *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1) {
        fprintf(stdout, "%s", line);
    }

    free(line);
}*/

void readLines(FILE *inputFile, FILE *outputFile);

int main(int argc, char *argv[]) {
    FILE *inputFile, *outputFile;
    char *line = NULL;

    if (argc > 3) {
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }

    if (argc == 1) {
        inputFile = stdin;
        outputFile = stdout;
    } else if (argc == 2) {
        inputFile = fopen(argv[1], "r");
        if (inputFile == NULL) {
            fprintf(stderr, "error: cannot open file\n");
            exit(1);
        }
        outputFile = stdout;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        fprintf(stderr, "error: cannot open output file\n");
        exit(1);
    }

// mi
    readLines(inputFile, outputFile);

    if (inputFile != stdin) {
        fclose(inputFile);
    } fclose(outputFile);

    return 0;
}

void readLines(FILE *inputFile, FILE *outputFile) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, inputFile)) != -1) {
        fprintf(outputFile, "%s", line);
    }

    free(line);
}