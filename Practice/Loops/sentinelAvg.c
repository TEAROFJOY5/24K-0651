 /*   (Average a Sequence of Integers) Write a program that    calculates and prints the average of
  * several integers. Assume the last value read with scanf is the sentinel 9999. A typical input sequence
  * might be
  * 10 8 11 7 9 9999
  * indicating that the average of all the values preceding 9999 is to be calculated.
  */
  
  #include <stdio.h>

int main() {
    int n = 0, sum = 0, counter = 0, sen = 9999;
    float avg = 0;

    printf("Enter the integers (Enter 9999 to stop): ");

    while (1) {
        scanf("%d", &n);

        if (n == sen) {
            break;
        }

        sum += n;
        counter++;
    }

    if (counter > 0) {
        avg = (float)sum / counter;
        printf("The average is %.2f\n", avg);
    } else {
        printf("No values were entered before 9999.\n");
    }

    return 0;
}
