#include <stdio.h>
#include <string.h>

#define MAX_VEHICLES 50

enum VehicleType {
    CAR = 1,
    BIKE = 2
};

enum RentalStatus {
    AVAILABLE = 1,
    RENTED = 2
};

union VehicleDetail {

    int seats;          
    int engineCapacity;
};

struct Vehicle {
    int id;
    char name[50];
    char brand[50];
    enum VehicleType type;
    enum RentalStatus status;
    union VehicleDetail detail;
};

void addVehicle(struct Vehicle vehicles[], int *count);
void displayAllVehicles(const struct Vehicle vehicles[], int count);
void searchVehicle(const struct Vehicle vehicles[], int count);
void rentVehicle(struct Vehicle vehicles[], int count);
void returnVehicle(struct Vehicle vehicles[], int count);
void displayAvailableVehicles(const struct Vehicle vehicles[], int count);
int findVehicleIndexById(const struct Vehicle vehicles[], int count, int id);
void printVehicleRecord(const struct Vehicle *v);

int main() {
    struct Vehicle vehicles[MAX_VEHICLES];
    int vehicleCount = 0;
    int choice;

    do {
        printf("\n===== VEHICLE RENTAL MANAGEMENT SYSTEM =====\n");
        printf("1. Add Vehicle\n");
        printf("2. Display All Vehicles\n");
        printf("3. Search Vehicle\n");
        printf("4. Rent Vehicle\n");
        printf("5. Return Vehicle\n");
        printf("6. Display Available Vehicles\n");
        printf("7. Exit\n");
        printf("\nEnter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            // Clear invalid input buffer
            while (getchar() != '\n');
            printf("Invalid input! Please enter a number between 1 and 7.\n");
            continue;
        }

        switch (choice) {
            case 1:
                addVehicle(vehicles, &vehicleCount);
                break;
            case 2:
                displayAllVehicles(vehicles, vehicleCount);
                break;
            case 3:
                searchVehicle(vehicles, vehicleCount);
                break;
            case 4:
                rentVehicle(vehicles, vehicleCount);
                break;
            case 5:
                returnVehicle(vehicles, vehicleCount);
                break;
            case 6:
                displayAvailableVehicles(vehicles, vehicleCount);
                break;
            case 7:
                printf("Exiting Vehicle Rental Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option (1-7).\n");
        }
    } while (choice != 7);

    return 0;
}

int findVehicleIndexById(const struct Vehicle vehicles[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (vehicles[i].id == id) {
            return i;
        }
    }
    return -1;
}

void printVehicleRecord(const struct Vehicle *v) {
    printf("ID: %-5d | Name: %-12s | Brand: %-10s | ", v->id, v->name, v->brand);
    
    if (v->type == CAR) {
        printf("Type: Car  | Seats: %-4d | ", v->detail.seats);
    } else if (v->type == BIKE) {
        printf("Type: Bike | Engine: %dcc | ", v->detail.engineCapacity);
    }

    if (v->status == AVAILABLE) {
        printf("Status: Available\n");
    } else {
        printf("Status: Rented\n");
    }
}

void addVehicle(struct Vehicle vehicles[], int *count) {
    if (*count >= MAX_VEHICLES) {
        printf("\nError: Vehicle storage limit (%d) reached!\n", MAX_VEHICLES);
        return;
    }

    struct Vehicle newVehicle;
    int typeChoice;

    printf("\nEnter Vehicle ID: ");
    scanf("%d", &newVehicle.id);

    if (findVehicleIndexById(vehicles, *count, newVehicle.id) != -1) {
        printf("Error: A vehicle with ID %d already exists!\n", newVehicle.id);
        return;
    }

    printf("Enter Vehicle Name: ");
    scanf(" %49[^\n]", newVehicle.name);

    printf("Enter Brand: ");
    scanf(" %49[^\n]", newVehicle.brand);

    printf("Select Vehicle Type:\n");
    printf("1. Car\n");
    printf("2. Bike\n");
    printf("Enter choice: ");
    scanf("%d", &typeChoice);

    if (typeChoice == CAR) {
        newVehicle.type = CAR;
        printf("Enter Number of Seats: ");
        scanf("%d", &newVehicle.detail.seats);
    } else if (typeChoice == BIKE) {
        newVehicle.type = BIKE;
        printf("Enter Engine Capacity (in cc): ");
        scanf("%d", &newVehicle.detail.engineCapacity);
    } else {
        printf("Invalid vehicle type! Vehicle addition cancelled.\n");
        return;
    }

    newVehicle.status = AVAILABLE;
    vehicles[*count] = newVehicle;
    (*count)++;

    printf("\nVehicle Added Successfully!\n");
}

void displayAllVehicles(const struct Vehicle vehicles[], int count) {
    if (count == 0) {
        printf("\nNo vehicles registered in the system.\n");
        return;
    }

    printf("\n--- ALL REGISTERED VEHICLES ---\n");
    for (int i = 0; i < count; i++) {
        printVehicleRecord(&vehicles[i]);
    }
}

void searchVehicle(const struct Vehicle vehicles[], int count) {
    if (count == 0) {
        printf("\nNo vehicles registered in the system.\n");
        return;
    }

    int id;
    printf("\nEnter Vehicle ID to search: ");
    scanf("%d", &id);

    int index = findVehicleIndexById(vehicles, count, id);
    if (index == -1) {
        printf("Vehicle with ID %d not found.\n", id);
    } else {
        printf("\n--- VEHICLE FOUND ---\n");
        printVehicleRecord(&vehicles[index]);
    }
}

void rentVehicle(struct Vehicle vehicles[], int count) {
    if (count == 0) {
        printf("\nNo vehicles registered in the system.\n");
        return;
    }

    int id;
    printf("\nEnter Vehicle ID to rent: ");
    scanf("%d", &id);

    int index = findVehicleIndexById(vehicles, count, id);
    if (index == -1) {
        printf("Vehicle with ID %d not found.\n", id);
    } else if (vehicles[index].status == RENTED) {
        printf("Error: Vehicle '%s' (ID: %d) is already rented!\n", vehicles[index].name, id);
    } else {
        vehicles[index].status = RENTED;
        printf("Vehicle '%s' (ID: %d) has been rented successfully!\n", vehicles[index].name, id);
    }
}

void returnVehicle(struct Vehicle vehicles[], int count) {
    if (count == 0) {
        printf("\nNo vehicles registered in the system.\n");
        return;
    }

    int id;
    printf("\nEnter Vehicle ID to return: ");
    scanf("%d", &id);

    int index = findVehicleIndexById(vehicles, count, id);
    if (index == -1) {
        printf("Vehicle with ID %d not found.\n", id);
    } else if (vehicles[index].status == AVAILABLE) {
        printf("Error: Vehicle '%s' (ID: %d) is already available (not rented)!\n", vehicles[index].name, id);
    } else {
        vehicles[index].status = AVAILABLE;
        printf("Vehicle '%s' (ID: %d) has been returned and is now available!\n", vehicles[index].name, id);
    }
}

void displayAvailableVehicles(const struct Vehicle vehicles[], int count) {
    int availableCount = 0;

    printf("\n--- AVAILABLE VEHICLES ---\n");
    for (int i = 0; i < count; i++) {
        if (vehicles[i].status == AVAILABLE) {
            printVehicleRecord(&vehicles[i]);
            availableCount++;
        }
    }

    if (availableCount == 0) {
        printf("No vehicles are currently available for rent.\n");
    }
}



OUTPUT:

===== VEHICLE RENTAL MANAGEMENT SYSTEM =====
1. Add Vehicle
2. Display All Vehicles
3. Search Vehicle
4. Rent Vehicle
5. Return Vehicle
6. Display Available Vehicles
7. Exit

Enter your choice: 1

Enter Vehicle ID: 101
Enter Vehicle Name: Swift
Enter Brand: Maruti
Select Vehicle Type:
1. Car
2. Bike
Enter choice: 1
Enter Number of Seats: 5

Vehicle Added Successfully!

===== VEHICLE RENTAL MANAGEMENT SYSTEM =====
1. Add Vehicle
2. Display All Vehicles
3. Search Vehicle
4. Rent Vehicle
5. Return Vehicle
6. Display Available Vehicles
7. Exit

Enter your choice: 1

Enter Vehicle ID: 102
Enter Vehicle Name: Duke 390
Enter Brand: KTM
Select Vehicle Type:
1. Car
2. Bike
Enter choice: 2
Enter Engine Capacity (in cc): 390

Vehicle Added Successfully!

===== VEHICLE RENTAL MANAGEMENT SYSTEM =====
1. Add Vehicle
2. Display All Vehicles
3. Search Vehicle
4. Rent Vehicle
5. Return Vehicle
6. Display Available Vehicles
7. Exit

Enter your choice: 2

--- ALL REGISTERED VEHICLES ---
ID: 101   | Name: Swift        | Brand: Maruti     | Type: Car  | Seats: 5    | Status: Available
ID: 102   | Name: Duke 390     | Brand: KTM        | Type: Bike | Engine: 390cc | Status: Available

===== VEHICLE RENTAL MANAGEMENT SYSTEM =====
1. Add Vehicle
2. Display All Vehicles
3. Search Vehicle
4. Rent Vehicle
5. Return Vehicle
6. Display Available Vehicles
7. Exit

Enter your choice: 4

Enter Vehicle ID to rent: 101
Vehicle 'Swift' (ID: 101) has been rented successfully!

===== VEHICLE RENTAL MANAGEMENT SYSTEM =====
1. Add Vehicle
2. Display All Vehicles
3. Search Vehicle
4. Rent Vehicle
5. Return Vehicle
6. Display Available Vehicles
7. Exit

Enter your choice: 6

--- AVAILABLE VEHICLES ---
ID: 102   | Name: Duke 390     | Brand: KTM        | Type: Bike | Engine: 390cc | Status: Available

===== VEHICLE RENTAL MANAGEMENT SYSTEM =====
1. Add Vehicle
2. Display All Vehicles
3. Search Vehicle
4. Rent Vehicle
5. Return Vehicle
6. Display Available Vehicles
7. Exit

Enter your choice: 5

Enter Vehicle ID to return: 101
Vehicle 'Swift' (ID: 101) has been returned and is now available!

===== VEHICLE RENTAL MANAGEMENT SYSTEM =====
1. Add Vehicle
2. Display All Vehicles
3. Search Vehicle
4. Rent Vehicle
5. Return Vehicle
6. Display Available Vehicles
7. Exit

Enter your choice: 7
Exiting Vehicle Rental Management System. Goodbye!