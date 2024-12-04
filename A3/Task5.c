#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define MAX_SPECIES 10
#define MAX_SUPPLIES 20
#define MAX_NAME_LENGTH 50

typedef struct {
    char **supplies;
    int supplyCount;
} Species;

typedef struct {
    Species *speciesList;
    int speciesCount;
} Inventory;

void initializeInventory(Inventory *inventory, int speciesCount) {
    inventory->speciesList = (Species *)malloc(speciesCount * sizeof(Species));
    inventory->speciesCount = speciesCount;

    for (int i = 0; i < speciesCount; i++) {
        inventory->speciesList[i].supplies = NULL;
        inventory->speciesList[i].supplyCount = 0;
    }
}

void addSupplies(Inventory *inventory, int speciesIndex) {
    if (speciesIndex < 0 || speciesIndex >= inventory->speciesCount) {
        printf("Invalid species index.\n");
        return;
    }

    Species *species = &inventory->speciesList[speciesIndex];
    printf("Enter number of supplies to add for species %d: ", speciesIndex + 1);
    int numSupplies;
    scanf("%d", &numSupplies);
    getchar(); // Consume newline

    species->supplies = (char **)realloc(species->supplies, (species->supplyCount + numSupplies) * sizeof(char *));
    
    for (int i = 0; i < numSupplies; i++) {
        species->supplies[species->supplyCount + i] = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
        printf("Enter supply name %d: ", species->supplyCount + i + 1);
        fgets(species->supplies[species->supplyCount + i], MAX_NAME_LENGTH, stdin);
        species->supplies[species->supplyCount + i][strcspn(species->supplies[species->supplyCount + i], "\n")] = 0; // Remove newline
    }
    species->supplyCount += numSupplies;
}

void updateSupplies(Inventory *inventory, int speciesIndex, int supplyIndex) {
    if (speciesIndex < 0 || speciesIndex >= inventory->speciesCount) {
        printf("Invalid species index.\n");
        return;
    }

    Species *species = &inventory->speciesList[speciesIndex];
    if (supplyIndex < 0 || supplyIndex >= species->supplyCount) {
        printf("Invalid supply index.\n");
        return;
    }

    printf("Enter new supply name: ");
    char newSupply[MAX_NAME_LENGTH];
    fgets(newSupply, MAX_NAME_LENGTH, stdin);
    newSupply[strcspn(newSupply, "\n")] = 0; // Remove newline

    free(species->supplies[supplyIndex]);
    species->supplies[supplyIndex] = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
    strcpy(species->supplies[supplyIndex], newSupply);
}

void removeSpecies(Inventory *inventory, int speciesIndex) {
    if (speciesIndex < 0 || speciesIndex >= inventory->speciesCount) {
        printf("Invalid species index.\n");
        return;
    }

    Species *species = &inventory->speciesList[speciesIndex];
    for (int i = 0; i < species->supplyCount; i++) {
        free(species->supplies[i]);
    }
    free(species->supplies);

    for (int i = speciesIndex; i < inventory->speciesCount - 1; i++) {
        inventory->speciesList[i] = inventory->speciesList[i + 1];
    }
    inventory->speciesCount--;
}

void displayInventory(Inventory *inventory) {
    for (int i = 0; i < inventory->speciesCount; i++) {
        printf("Species %d:\n", i + 1);
        Species *species = &inventory->speciesList[i];
        for (int j = 0; j < species->supplyCount; j++) {
            printf("  Supply %d: %s\n", j + 1, species->supplies[j]);
        }
    }
}

void freeInventory(Inventory *inventory) {
    for (int i = 0; i < inventory->speciesCount; i++) {
        Species *species = &inventory->speciesList[i];
        for (int j = 0; j < species->supplyCount; j++) {
            free(species->supplies[j]);
        }
        free(species->supplies);
    }
    free(inventory->speciesList);
}



int main() {
    Inventory inventory;
    initializeInventory(&inventory, MAX_SPECIES);

    int choice;
    do {
        printf("\nPets in Heart - Inventory System\n");
        printf("1. Initialize Inventory\n");
        printf("2. Add Supplies\n");
        printf("3. Update Supply\n");
        printf("4. Remove Species\n");
        printf("5. Display Inventory\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        int speciesIndex, supplyIndex;
        switch (choice) {
            case 1:
                printf("Enter the number of species: ");
                int speciesCount;
                scanf("%d", &speciesCount);
                getchar(); 
                freeInventory(&inventory); 
                initializeInventory(&inventory, speciesCount);
                break;

            case 2:
                printf("Enter the species index to add supplies (1 to %d): ", inventory.speciesCount);
                scanf("%d", &speciesIndex);
                getchar(); 
                addSupplies(&inventory, speciesIndex - 1);
                break;

            case 3:
                printf("Enter the species index (1 to %d): ", inventory.speciesCount);
                scanf("%d", &speciesIndex);
                getchar(); 
                printf("Enter the supply index to update (1 to %d): ", inventory.speciesList[speciesIndex - 1].supplyCount);
                scanf("%d", &supplyIndex);
                getchar(); 
                updateSupplies(&inventory, speciesIndex - 1, supplyIndex - 1);
                break;

            case 4:
                printf("Enter the species index to remove (1 to %d): ", inventory.speciesCount);
                scanf("%d", &speciesIndex);
                getchar(); 
                removeSpecies(&inventory, speciesIndex - 1);
                break;

            case 5:
                displayInventory(&inventory);
                break;

            case 6:
                freeInventory(&inventory);
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
