#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10000 

void replaceWord(const char *input_str, const char *target_word, const char *replacement_word, char *output_str) {
    char *position, temp_buffer[BUFFER_SIZE];
    int output_index = 0, target_len = strlen(target_word);
    strcpy(temp_buffer, input_str);
    while ((position = strstr(temp_buffer, target_word)) != NULL) {
        int segment_len = position - temp_buffer;
        strncpy(output_str + output_index, temp_buffer, segment_len);
        output_index += segment_len;
        strcpy(output_str + output_index, replacement_word);
        output_index += strlen(replacement_word);
        strcpy(temp_buffer, position + target_len);
    }
    strcpy(output_str + output_index, temp_buffer);
}

int main() {
    FILE *file_pointer;
    char file_name[100], search_word[50], replace_word[50];
    char file_content[BUFFER_SIZE], updated_content[BUFFER_SIZE];
    
    printf("Enter the file name: ");
    scanf("%s", file_name);
    printf("Enter the word to be replaced: ");
    scanf("%s", search_word);
    printf("Enter the replacement word: ");
    scanf("%s", replace_word);
    
    file_pointer = fopen(file_name, "r");
    if (file_pointer == NULL) {
        printf("Error! Could not open file.\n");
        return 0;
    }
    fread(file_content, sizeof(char), BUFFER_SIZE, file_pointer);
    fclose(file_pointer);

    replaceWord(file_content, search_word, replace_word, updated_content);

    file_pointer = fopen(file_name, "w");
    if (file_pointer == NULL) {
        printf("Error! Could not open file for writing.\n");
        return 0;
    }
    fprintf(file_pointer, "%s", updated_content);
    fclose(file_pointer);
    
    printf("Word replacement completed successfully.\n");
    return 0;
}
