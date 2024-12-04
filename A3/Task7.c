#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Content Metadata Structure
typedef struct ContentMetadata {
    char title[50];
    float rating;
    int runtime; // in minutes
    char encodingFormat[20];
} ContentMetadata;

// Function Prototypes
double** create_engagement_matrix(int num_users, int num_categories);
void free_engagement_matrix(double** matrix, int num_users);

double*** create_device_matrix(int num_users, int num_devices);
void free_device_matrix(double*** matrix, int num_users, int num_devices);

ContentMetadata*** create_content_metadata_matrix(int num_categories, int num_contents);
void free_content_metadata_matrix(ContentMetadata*** matrix, int num_categories, int num_contents);

// Main Function
int main() {
    int num_users = 3, num_categories = 4, num_devices = 2, num_contents = 5;

    // Create and initialize engagement matrix
    double** engagementMatrix = create_engagement_matrix(num_users, num_categories);

    // Simulate user engagement updates
    engagementMatrix[0][0] = 4.5; // User 0, Category 0 engagement score
    engagementMatrix[1][2] = 3.8; // User 1, Category 2 engagement score

    // Print engagement matrix
    printf("Engagement Matrix:\n");
    for (int i = 0; i < num_users; i++) {
        for (int j = 0; j < num_categories; j++) {
            printf("%.2f ", engagementMatrix[i][j]);
        }
        printf("\n");
    }

    // Create and initialize device matrix
    double*** deviceMatrix = create_device_matrix(num_users, num_devices);

    // Update device-specific data
    deviceMatrix[0][0][0] = 1080; // User 0, Device 0, Resolution (e.g., 1080p)
    deviceMatrix[1][1][1] = 720;  // User 1, Device 1, Resolution (e.g., 720p)

    // Create and initialize content metadata matrix
    ContentMetadata*** contentMatrix = create_content_metadata_matrix(num_categories, num_contents);

    // Populate a content metadata example
    strcpy(contentMatrix[0][0]->title, "Action Movie 1");
    contentMatrix[0][0]->rating = 4.2;
    contentMatrix[0][0]->runtime = 120;
    strcpy(contentMatrix[0][0]->encodingFormat, "H.264");

    // Print content metadata
    printf("\nContent Metadata for Category 0:\n");
    for (int i = 0; i < num_contents; i++) {
        printf("Title: %s, Rating: %.1f, Runtime: %d mins, Format: %s\n",
               contentMatrix[0][i]->title, contentMatrix[0][i]->rating,
               contentMatrix[0][i]->runtime, contentMatrix[0][i]->encodingFormat);
    }

    // Free all matrices
    free_engagement_matrix(engagementMatrix, num_users);
    free_device_matrix(deviceMatrix, num_users, num_devices);
    free_content_metadata_matrix(contentMatrix, num_categories, num_contents);

    return 0;
}

// Function Implementations
double** create_engagement_matrix(int num_users, int num_categories) {
    double** matrix = (double**)malloc(num_users * sizeof(double*));
    for (int i = 0; i < num_users; i++) {
        matrix[i] = (double*)calloc(num_categories, sizeof(double));
    }
    return matrix;
}

void free_engagement_matrix(double** matrix, int num_users) {
    for (int i = 0; i < num_users; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

double*** create_device_matrix(int num_users, int num_devices) {
    double*** matrix = (double***)malloc(num_users * sizeof(double**));
    for (int i = 0; i < num_users; i++) {
        matrix[i] = (double**)malloc(num_devices * sizeof(double*));
        for (int j = 0; j < num_devices; j++) {
            matrix[i][j] = (double*)calloc(3, sizeof(double)); // Example: 3 fields per device
        }
    }
    return matrix;
}

void free_device_matrix(double*** matrix, int num_users, int num_devices) {
    for (int i = 0; i < num_users; i++) {
        for (int j = 0; j < num_devices; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}

ContentMetadata*** create_content_metadata_matrix(int num_categories, int num_contents) {
    ContentMetadata*** matrix = (ContentMetadata***)malloc(num_categories * sizeof(ContentMetadata**));
    for (int i = 0; i < num_categories; i++) {
        matrix[i] = (ContentMetadata**)malloc(num_contents * sizeof(ContentMetadata*));
        for (int j = 0; j < num_contents; j++) {
            matrix[i][j] = (ContentMetadata*)malloc(sizeof(ContentMetadata));
        }
    }
    return matrix;
}

void free_content_metadata_matrix(ContentMetadata*** matrix, int num_categories, int num_contents) {
    for (int i = 0; i < num_categories; i++) {
        for (int j = 0; j < num_contents; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}
