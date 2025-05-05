/*
 * This C program reads words from a file (text.txt) and counts the frequency of each unique word. 
 * It then prints the list of unique words along with how many times each appeared in the file.
 */
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100   // MAX_WORDS is the Maximum number of unique words that program will track.
#define MAX_LEN 50      //MAX_LEN is the maximum length of any word (50 characters).

int main() {
    FILE *ptr;
    char words[MAX_WORDS][MAX_LEN], word[MAX_LEN];
    int counts[MAX_WORDS] = {0}, word_count = 0, found, i;
    ptr = fopen("text.txt", "r");
    if (ptr == NULL) {
        printf("Error! Could not open file\n");
        return 0; }
    while (fscanf(ptr, "%s", word) != EOF) {
        found = 0;
        for (i = 0; i < word_count; i++) {
            if (strcmp(words[i], word) == 0) {
                counts[i]++;
                found = 1;
                break; } }
        if (!found && word_count < MAX_WORDS) {
            strcpy(words[word_count], word);
            counts[word_count] = 1;
            word_count++; } }
    fclose(ptr);
    printf("Word Frequencies:\n");
    for (i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i], counts[i]); }
    return 0;
}
