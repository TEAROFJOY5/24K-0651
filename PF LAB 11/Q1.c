#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp1 = fopen("first.txt", "w");
    if (fp1 == NULL) {
        perror("Error! ");
        return 1; }
    fprintf(fp1, "My Name is Turab Ali.\nI study in FAST NUCES Karachi.\n");
    fclose(fp1);
    fp1 = fopen("first.txt", "r");
    if (fp1 == NULL) {
        perror("Error!");
        return 1; }
    FILE *fp2 = fopen("second.txt", "w");
    if (fp2 == NULL) 
      {
        perror("Error!");
        fclose(fp1);
        return 1;
      }
    char ch;
    while ((ch = fgetc(fp1)) != EOF)
      {
        fputc(ch, fp2);
      }
    fclose(fp1);
    fclose(fp2);
    printf("Date Copied\n");
    return 0; 
}
