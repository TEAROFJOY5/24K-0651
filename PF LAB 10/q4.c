#include <stdio.h>
#include <string.h>

struct LibraryItem {
    char bookTitle[100];
    char bookAuthor[100];
    int pubYear;
    float bookPrice;
};

// Function declarations
void showLibraryItems(struct LibraryItem library[], int itemCount);
void findBookByTitle(struct LibraryItem library[], int itemCount, char searchTitle[]);
void listBooksByAuthor(struct LibraryItem library[], int itemCount, char searchAuthor[]);

int main() {
    int numBooks, index;
    printf("Enter the number of books: ");
    scanf("%d", &numBooks);
    getchar(); // Consume newline

    struct LibraryItem library[numBooks];

    // Input details for each book
    for (index = 0; index < numBooks; index++) {
        printf("\nEnter details for book %d:\n", index + 1);

        printf("Enter book title: ");
        fgets(library[index].bookTitle, sizeof(library[index].bookTitle), stdin);
        library[index].bookTitle[strcspn(library[index].bookTitle, "\n")] = '\0';

        printf("Enter book author: ");
        fgets(library[index].bookAuthor, sizeof(library[index].bookAuthor), stdin);
        library[index].bookAuthor[strcspn(library[index].bookAuthor, "\n")] = '\0';

        printf("Enter publication year: ");
        scanf("%d", &library[index].pubYear);
        getchar(); // Consume newline

        printf("Enter book price: ");
        scanf("%f", &library[index].bookPrice);
        getchar(); // Consume newline
    }

    // Display all books
    printf("\nLibrary Collection:\n");
    showLibraryItems(library, numBooks);

    // Search for a book by title
    char titleToFind[100];
    printf("\nEnter the title of the book to search: ");
    fgets(titleToFind, sizeof(titleToFind), stdin);
    titleToFind[strcspn(titleToFind, "\n")] = '\0';
    findBookByTitle(library, numBooks, titleToFind);

    // List books by an author
    char authorToFind[100];
    printf("\nEnter the author to list their books: ");
    fgets(authorToFind, sizeof(authorToFind), stdin);
    authorToFind[strcspn(authorToFind, "\n")] = '\0';
    listBooksByAuthor(library, numBooks, authorToFind);

    return 0;
}

// Function to display all books
void showLibraryItems(struct LibraryItem library[], int itemCount) {
    for (int i = 0; i < itemCount; i++) {
        printf("Title: %s\nAuthor: %s\nPublication Year: %d\nPrice: $%.2f\n\n",
               library[i].bookTitle, library[i].bookAuthor, library[i].pubYear, library[i].bookPrice);
    }
}

// Function to search for a book by title
void findBookByTitle(struct LibraryItem library[], int itemCount, char searchTitle[]) {
    int isFound = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(library[i].bookTitle, searchTitle) == 0) {
            printf("\nBook Found:\nTitle: %s\nAuthor: %s\nPublication Year: %d\nPrice: $%.2f\n",
                   library[i].bookTitle, library[i].bookAuthor, library[i].pubYear, library[i].bookPrice);
            isFound 
