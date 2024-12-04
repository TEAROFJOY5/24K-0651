#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct Crops {
    char cropType[20];
    char growthStage[20];
    float expectedYield;
} Crops;

typedef struct smartEquipment {
    char name[30];
    float fuel_level;
    char operational_status[20];
} smartEquipment;

typedef struct Sensor {
    float soil_nutrients;
    float pH_level;
    int pest_activity;
} Sensor;

typedef struct Field {
    char GPS_coordinates[50];
    float soil_health;
    float moisture_level;
    Crops *crops;
    smartEquipment *equipment;
    Sensor *sensors;
    int num_crops, num_equipment, num_sensors;
} Field;

typedef struct RegionalHub {
    Field *fields;
    int num_fields;
} RegionalHub;

typedef struct CentralServer {
    RegionalHub *hubs;
    int num_hubs;
} CentralServer;

// Function prototypes
Field* create_field(int num_crops, int num_equipment, int num_sensors);
void populate_field(Field *field);
void display_field(const Field *field);
void free_field(Field *field);

RegionalHub* create_regional_hub(int num_fields);
void free_regional_hub(RegionalHub *hub);

CentralServer* create_central_server(int num_hubs);
void free_central_server(CentralServer *server);

// Function definitions
Field* create_field(int num_crops, int num_equipment, int num_sensors) {
    Field *field = (Field *)malloc(sizeof(Field));
    if (!field) {
        perror("Memory allocation failed for Field");
        exit(1);
    }

    field->crops = (Crops *)malloc(num_crops * sizeof(Crops));
    field->equipment = (smartEquipment *)malloc(num_equipment * sizeof(smartEquipment));
    field->sensors = (Sensor *)malloc(num_sensors * sizeof(Sensor));

    if (!field->crops || !field->equipment || !field->sensors) {
        perror("Memory allocation failed for Field components");
        exit(1);
    }

    field->num_crops = num_crops;
    field->num_equipment = num_equipment;
    field->num_sensors = num_sensors;

    return field;
}

void populate_field(Field *field) {
    printf("Enter GPS coordinates: ");
    scanf(" %[^\n]", field->GPS_coordinates);

    printf("Enter soil health: ");
    scanf("%f", &field->soil_health);

    printf("Enter moisture level: ");
    scanf("%f", &field->moisture_level);

    for (int i = 0; i < field->num_crops; i++) {
        printf("Enter details for crop %d:\n", i + 1);
        printf("  Crop type: ");
        scanf(" %[^\n]", field->crops[i].cropType);
        printf("  Growth stage: ");
        scanf(" %[^\n]", field->crops[i].growthStage);
        printf("  Expected yield: ");
        scanf("%f", &field->crops[i].expectedYield);
    }

    for (int i = 0; i < field->num_equipment; i++) {
        printf("Enter details for equipment %d:\n", i + 1);
        printf("  Name: ");
        scanf(" %[^\n]", field->equipment[i].name);
        printf("  Fuel level: ");
        scanf("%f", &field->equipment[i].fuel_level);
        printf("  Operational status: ");
        scanf(" %[^\n]", field->equipment[i].operational_status);
    }

    for (int i = 0; i < field->num_sensors; i++) {
        printf("Enter details for sensor %d:\n", i + 1);
        printf("  Soil nutrients: ");
        scanf("%f", &field->sensors[i].soil_nutrients);
        printf("  pH level: ");
        scanf("%f", &field->sensors[i].pH_level);
        printf("  Pest activity (0=No, 1=Low, 2=High): ");
        scanf("%d", &field->sensors[i].pest_activity);
    }
}

void display_field(const Field *field) {
    printf("\n--- Field Details ---\n");
    printf("GPS Coordinates: %s\n", field->GPS_coordinates);
    printf("Soil Health: %.2f\n", field->soil_health);
    printf("Moisture Level: %.2f\n", field->moisture_level);

    for (int i = 0; i < field->num_crops; i++) {
        printf("Crop %d: Type=%s, Growth Stage=%s, Expected Yield=%.2f\n",
               i + 1, field->crops[i].cropType, field->crops[i].growthStage, field->crops[i].expectedYield);
    }

    for (int i = 0; i < field->num_equipment; i++) {
        printf("Equipment %d: Name=%s, Fuel Level=%.2f, Status=%s\n",
               i + 1, field->equipment[i].name, field->equipment[i].fuel_level, field->equipment[i].operational_status);
    }

    for (int i = 0; i < field->num_sensors; i++) {
        printf("Sensor %d: Nutrients=%.2f, pH=%.2f, Pest Activity=%d\n",
               i + 1, field->sensors[i].soil_nutrients, field->sensors[i].pH_level, field->sensors[i].pest_activity);
    }
}

void free_field(Field *field) {
    free(field->crops);
    free(field->equipment);
    free(field->sensors);
    free(field);
}

RegionalHub* create_regional_hub(int num_fields) {
    RegionalHub *hub = (RegionalHub *)malloc(sizeof(RegionalHub));
    if (!hub) {
        perror("Memory allocation failed for RegionalHub");
        exit(1);
    }

    hub->fields = (Field *)malloc(num_fields * sizeof(Field));
    if (!hub->fields) {
        perror("Memory allocation failed for Fields in RegionalHub");
        exit(1);
    }

    hub->num_fields = num_fields;
    return hub;
}

void free_regional_hub(RegionalHub *hub) {
    for (int i = 0; i < hub->num_fields; i++) {
        free_field(&hub->fields[i]);
    }
    free(hub->fields);
    free(hub);
}

CentralServer* create_central_server(int num_hubs) {
    CentralServer *server = (CentralServer *)malloc(sizeof(CentralServer));
    if (!server) {
        perror("Memory allocation failed for CentralServer");
        exit(1);
    }

    server->hubs = (RegionalHub *)malloc(num_hubs * sizeof(RegionalHub));
    if (!server->hubs) {
        perror("Memory allocation failed for RegionalHubs in CentralServer");
        exit(1);
    }

    server->num_hubs = num_hubs;
    return server;
}

void free_central_server(CentralServer *server) {
    for (int i = 0; i < server->num_hubs; i++) {
        free_regional_hub(&server->hubs[i]);
    }
    free(server->hubs);
    free(server);
}

// Main Function
int main() {
    int num_fields = 1, num_crops = 2, num_equipment = 1, num_sensors = 1;

    CentralServer *server = create_central_server(1);
    server->hubs[0] = *create_regional_hub(num_fields);

    for (int i = 0; i < num_fields; i++) {
        server->hubs[0].fields[i] = *create_field(num_crops, num_equipment, num_sensors);
        populate_field(&server->hubs[0].fields[i]);
        display_field(&server->hubs[0].fields[i]);
    }

    free_central_server(server);

    return 0;
}
