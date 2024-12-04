#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Weather Structure
typedef struct Weather {
    float temperature;
    float rainfall;
    float wind_speed;
} Weather;

// Crops Structure
typedef struct Crops {
    char cropType[20];
    char grownthStage[20];
    float expectedYield;
} Crops;

// Smart Equipment Structure
typedef struct smartEquipment {
    char name[30];
    float fuel_level;
    char operational_status[20];
    char activity_schedule[50];
} smartEquipment;

// Sensor Structure
typedef struct Sensor {
    float soil_nutrients;
    float pH_level;
    int pest_activity;
} Sensor;

// Field Structure
typedef struct Field {
    char GPS_coordinates[50];
    float soil_health;
    float moisture_level;
    Crops *crops;             // yeh pointer hai dynamic array of crops ka.
    smartEquipment *equipment; // yeh pointer hai dynamic array of equipment
    Sensor *sensors;          // Yeh pointer hai dynamic array of sensors
    int num_crops, num_equipment, num_sensors;
} Field;


typedef struct RegionalHub {
    Field *fields; // Yeh pointer hai array of fields ka
    int num_fields;
    float aggregate_yield_prediction;
} RegionalHub;


typedef struct CentralServer {
    RegionalHub *hubs; // Yeh pointer hai array of regional hubs ka
    int num_hubs;
} CentralServer;

// Function jp Field banai ga
Field* create_field(int num_crops, int num_equipment, int num_sensors) {
    Field *field = (Field *)malloc(sizeof(Field));
    if (!field) {
        perror("Memory allocation failed");
        exit(1);
    }

    // Allocate dynamic memory for crops, equipment, and sensors
    field->crops = (Crops *)malloc(num_crops * sizeof(Crops));
    field->equipment = (smartEquipment *)malloc(num_equipment * sizeof(smartEquipment));
    field->sensors = (Sensor *)malloc(num_sensors * sizeof(Sensor));

    if (!field->crops || !field->equipment || !field->sensors) {
        perror("Memory allocation failed");
        exit(1);
    }

    // Initialize the field
    strcpy(field->GPS_coordinates, "");
    field->soil_health = 0.0;
    field->moisture_level = 0.0;
    field->num_crops = num_crops;
    field->num_equipment = num_equipment;
    field->num_sensors = num_sensors;

    return field;
}

void add_crop(Crops *crop, const char *type, const char *growthStage, float yield) {
    strcpy(crop->cropType, type);
    strcpy(crop->grownthStage, growthStage);
    crop->expectedYield = yield;
}

RegionalHub* create_regional_hub(int num_fields) {
    RegionalHub *hub = (RegionalHub *)malloc(sizeof(RegionalHub));
    if (!hub) {
        perror("Memory allocation failed");
        exit(1);
    }

    hub->fields = (Field *)malloc(num_fields * sizeof(Field));
    if (!hub->fields) {
        perror("Memory allocation failed");
        exit(1);
    }

    hub->num_fields = num_fields;
    hub->aggregate_yield_prediction = 0.0;

    return hub;
}

void populate_regional_hub(RegionalHub *hub, int num_crops, int num_equipment, int num_sensors) {
    for (int i = 0; i < hub->num_fields; i++) {
        hub->fields[i] = *create_field(num_crops, num_equipment, num_sensors);

        // Example data for crops, equipment, and sensors
        add_crop(&hub->fields[i].crops[0], "Wheat", "Growing", 500.0);
        add_crop(&hub->fields[i].crops[1], "Corn", "Harvesting", 300.0);

        strcpy(hub->fields[i].equipment[0].name, "Tractor");
        hub->fields[i].equipment[0].fuel_level = 75.5;
        strcpy(hub->fields[i].equipment[0].operational_status, "Active");

        hub->fields[i].sensors[0].soil_nutrients = 4.5;
        hub->fields[i].sensors[0].pH_level = 7.0;
        hub->fields[i].sensors[0].pest_activity = 2;
    }
}

CentralServer* create_central_server(int num_hubs) {
    CentralServer *server = (CentralServer *)malloc(sizeof(CentralServer));
    if (!server) {
        perror("Memory allocation failed");
        exit(1);
    }

    server->hubs = (RegionalHub *)malloc(num_hubs * sizeof(RegionalHub));
    if (!server->hubs) {
        perror("Memory allocation failed");
        exit(1);
    }

    server->num_hubs = num_hubs;

    return server;
}

void populate_central_server(CentralServer *server, int num_fields, int num_crops, int num_equipment, int num_sensors) {
    for (int i = 0; i < server->num_hubs; i++) {
        server->hubs[i] = *create_regional_hub(num_fields);
        populate_regional_hub(&server->hubs[i], num_crops, num_equipment, num_sensors);
    }
}

void display_field(Field *field) {
    printf("GPS Coordinates: %s\n", field->GPS_coordinates);
    printf("Soil Health: %.2f\n", field->soil_health);
    printf("Moisture Level: %.2f\n", field->moisture_level);

    for (int i = 0; i < field->num_crops; i++) {
        printf("Crop %d: Type=%s, Growth Stage=%s, Expected Yield=%.2f\n",
               i + 1, field->crops[i].cropType, field->crops[i].grownthStage, field->crops[i].expectedYield);
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

void free_regional_hub(RegionalHub *hub) {
    for (int i = 0; i < hub->num_fields; i++) {
        free_field(&hub->fields[i]);
    }
    free(hub->fields);
    free(hub);
}

void free_central_server(CentralServer *server) {
    for (int i = 0; i < server->num_hubs; i++) {
        free_regional_hub(&server->hubs[i]);
    }
    free(server->hubs);
    free(server);
}

int main() {
    // Create central server
    CentralServer *server = create_central_server(1);

    // Populate central server with hubs, fields, and their components
    populate_central_server(server, 2, 2, 1, 1);

    // Display data for the first field in the first hub
    display_field(&server->hubs[0].fields[0]);

    // Free allocated memory
    free_central_server(server);

    return 0;
}



