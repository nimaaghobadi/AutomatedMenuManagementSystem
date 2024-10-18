// Automated Menu Management System Header File
// The following lines prevent multiple inclusions of the same header file
#ifndef AUTOMATED_MENU_MANAGEMENT_SYSTEM_H
#define AUTOMATED_MENU_MANAGEMENT_SYSTEM_H

// Defining constants for the prices of the menu items
#define PIZZA_PRICE 17  // Price of one pizza in dollars
#define DRINK_PRICE 1   // Price of one drink in dollars
#define SOUP_PRICE 8    // Price of one soup in dollars
#define SALAD_PRICE 10  // Price of one salad in dollars

// Defining a structure to hold the number of items ordered
typedef struct {
    int pizzaCount;  // Number of pizzas ordered
    int drinkCount;  // Number of drinks ordered
    int soupCount;   // Number of soups ordered
    int saladCount;  // Number of salads ordered
} Order;

// External declaration of the global 'currentOrder' variable
extern Order currentOrder; // This ensures that the same instance of 'currentOrder' is shared across multiple files

// Function prototypes for the operations in the system
void showMenu();              // Function to display the menu
void handleOrder(int choice);  // Function to handle orders based on user input
void showTotal();              // Function to display the total bill

#endif // AUTOMATED_MENU_MANAGEMENT_SYSTEM_H
