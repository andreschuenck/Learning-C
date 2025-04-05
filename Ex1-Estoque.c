#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

// Function prototypes
void displayMenu();
void addItem();
void listItems();
void searchItem();
void deleteItem();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                listItems();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                deleteItem();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=== Inventory Management System ===\n");
    printf("1. Add Item\n");
    printf("2. List Items\n");
    printf("3. Search Item\n");
    printf("4. Delete Item\n");
    printf("5. Exit\n");
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    Item newItem;
    newItem.id = itemCount + 1;

    printf("Enter item name: ");
    clearBuffer();
    fgets(newItem.name, NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0'; // Remove newline character

    printf("Enter item quantity: ");
    if (scanf("%d", &newItem.quantity) != 1) {
        printf("Invalid input. Quantity must be a number.\n");
        clearBuffer();
        return;
    }

    printf("Enter item price: ");
    if (scanf("%f", &newItem.price) != 1) {
        printf("Invalid input. Price must be a number.\n");
        clearBuffer();
        return;
    }

    inventory[itemCount++] = newItem;
    printf("Item added successfully!\n");
}

void listItems() {
    if (itemCount == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    printf("\n=== Inventory List ===\n");
    for (int i = 0; i < itemCount; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchItem() {
    if (itemCount == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    int searchId;
    printf("Enter the ID of the item to search: ");
    if (scanf("%d", &searchId) != 1) {
        printf("Invalid input. ID must be a number.\n");
        clearBuffer();
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == searchId) {
            printf("Item found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                   inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Item with ID %d not found.\n", searchId);
}

void deleteItem() {
    if (itemCount == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    int deleteId;
    printf("Enter the ID of the item to delete: ");
    if (scanf("%d", &deleteId) != 1) {
        printf("Invalid input. ID must be a number.\n");
        clearBuffer();
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == deleteId) {
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item with ID %d deleted successfully.\n", deleteId);
            return;
        }
    }
    printf("Item with ID %d not found.\n", deleteId);
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
    
