#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char tmp_dir_holder[30];

void assign_file_relative_path_to_holder(char* file) {
    strcpy(tmp_dir_holder, "./resources/");
    strcat(tmp_dir_holder, file);
}

int main(int argc, char *argv[])
{
    char line[80];
    
    if (argc != 6) {
        fprintf(stderr, "You need to give 5 arguments\n");
        return 1;
    }
    
    assign_file_relative_path_to_holder("spooky.csv");
    // This will create a data stream to read from a file.
    FILE *in = fopen(tmp_dir_holder, "r");

    // This will create a data stream to write to a file.
    assign_file_relative_path_to_holder(argv[2]);
    FILE *file1 = fopen(tmp_dir_holder, "w");
    assign_file_relative_path_to_holder(argv[4]);
    FILE *file2 = fopen(tmp_dir_holder, "w");
    assign_file_relative_path_to_holder(argv[5]);
    FILE *file3 = fopen(tmp_dir_holder, "w");
    while ( fscanf(in, "%79[^\n]\n", line) == 1) {
        if (strstr(line, argv[1]))
            fprintf(file1, "%s\n", line);
        else if (strstr(line, argv[3]))
            fprintf(file2, "%s\n", line);
        else
            fprintf(file3, "%s\n", line);
    }
    fclose(file1);
    fclose(file2);
    fclose(file3);
    return 0;
}