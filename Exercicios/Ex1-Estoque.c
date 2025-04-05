#include <stdio.h>    // Entrada/saída padrão
#include <stdlib.h>   // Funções utilitárias
#include <string.h>   // Manipulação de strings

// Constantes
#define MAX_ITEMS 100    // Número máximo de itens no inventário
#define NAME_LENGTH 50   // Tamanho máximo do nome do item


typedef struct {
    int id;                 // Identificador único do item
    char name[NAME_LENGTH]; // Nome do item
    int quantity;           // Quantidade em estoque
    float price;            // Preço do item
} Item;

// Variáveis globais
Item inventory[MAX_ITEMS];  // Array para armazenar itens
int itemCount = 0;          // Contador de itens no inventário


// Function prototypes
void displayMenu();     // Mostra o menu principal
void addItem();         // Adiciona um novo item
void listItems();       // Lista todos os itens
void searchItem();      // Busca um item específico
void deleteItem();      // Remove um item
void clearBuffer();     // Limpa o buffer de entrada

int main() {
    int choice;

    while (1) { // Loop infinito até que o usuário escolha sair
        displayMenu();
        printf("Enter your choice: ");

        // Verifica se a entrada é válida
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearBuffer();
            continue;
        }
        // Menu de opções
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
// Exibe o menu principal
void displayMenu() {
    printf("\n=== Inventory Management System ===\n");
    printf("1. Add Item\n");
    printf("2. List Items\n");
    printf("3. Search Item\n");
    printf("4. Delete Item\n");
    printf("5. Exit\n");
}
// Verifica se o inventário está cheio
void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    Item newItem;
    newItem.id = itemCount + 1;
    // Entrada de dados do item
    printf("Enter item name: ");
    clearBuffer();
    fgets(newItem.name, NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0'; // Remove newline character

     // Validação de entrada para quantidade
    printf("Enter item quantity: ");
    if (scanf("%d", &newItem.quantity) != 1) {
        printf("Invalid input. Quantity must be a number.\n");
        clearBuffer();
        return;
    }

    // Validação de entrada para preço
    printf("Enter item price: $ ");
    if (scanf("%.2f", &newItem.price) != 1) {
        printf("Invalid input. Price must be a number.\n");
        clearBuffer();
        return;
    }
    // Adiciona o item ao inventário
    inventory[itemCount++] = newItem;
    printf("Item added successfully!\n");
}
// Verifica se há itens no inventário
void listItems() {
    if (itemCount == 0) {
        printf("No items in the inventory.\n");
        return;
    }
     // Imprime todos os itens
    printf("\n=== Inventory List ===\n");
    for (int i = 0; i < itemCount; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: $ %.2f\n",
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}
// Verifica se há itens no inventário
void searchItem() {
    if (itemCount == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    int searchId;
    printf("Enter the ID of the item to search: ");

    // Validação de entrada
    if (scanf("%d", &searchId) != 1) {
        printf("Invalid input. ID must be a number.\n");
        clearBuffer();
        return;
    }
    // Busca o item por ID
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == searchId) {
            printf("Item found: ID: %d, Name: %s, Quantity: %d, Price: $ %.2f\n",
                   inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Item with ID %d not found.\n", searchId);
}
// Verifica se há itens no inventário
void deleteItem() {
    if (itemCount == 0) {
        printf("No items in the inventory.\n");
        return;
    }
    // Validação de entrada
    int deleteId;
    printf("Enter the ID of the item to delete: ");
    if (scanf("%d", &deleteId) != 1) {
        printf("Invalid input. ID must be a number.\n");
        clearBuffer();
        return;
    }
    // Encontra e remove o item
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == deleteId) {
            for (int j = i; j < itemCount - 1; j++) { // Desloca os itens para preencher o espaço vazio
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item with ID %d deleted successfully.\n", deleteId);
            return;
        }
    }
    printf("Item with ID %d not found.\n", deleteId);
}
// Limpa caracteres restantes no buffer de entrada
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
    
