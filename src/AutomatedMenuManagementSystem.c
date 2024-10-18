// Automated Menu Management System
#include <stdio.h> // Standard library for input/output functions (e.g., printf, scanf)
#include "AutomatedMenuManagementSystem.h" // Custom header file containing declarations

// Structure to track ordered quantities
Order currentOrder = {0, 0, 0, 0}; // Initializing order counts to zero
// Function declarations
void showMenu();        // Displays the menu
void handleOrder(int);  // Processes the user's choice
void showTotal();       // Displays the total cost

int main() {
    int choice; // Variable to store the user's menu selection
    while (1) { // Infinite loop until user chooses to exit
        showMenu(); // Show the menu to the user
        printf("Your choice: ");
        scanf("%d", &choice); // Get user input

        if (choice == 5) { // If the user selects option 5 (exit)
            showTotal();    // Show the total bill
            break;          // Exit the loop
        } else {
            handleOrder(choice); // Process the selected menu option
        }
    }
    return 0; // End the program
}

// Function to display the menu options
void showMenu() {
    printf("\n--- Restaurant Menu ---\n");
    printf("1. Order Pizza (%d $)\n", PIZZA_PRICE); // Display pizza price
    printf("2. Order Drink (%d $)\n", DRINK_PRICE); // Display drink price
    printf("3. Order Soup (%d $)\n", SOUP_PRICE);   // Display soup price
    printf("4. Order Salad (%d $)\n", SALAD_PRICE); // Display salad price
    printf("5. Total Amount and Exit\n");           // Option to view total and exit
}

// Function to handle the user's choice and update order counts
void handleOrder(int choice) {
    int quantity; // Variable for quantity of items
    switch (choice) { // Process each menu item based on choice
        case 1: // If pizza is selected
            printf("How many pizzas would you like to order? ");
            scanf("%d", &quantity); // Get quantity
            if (quantity < 0) {     // Check for negative quantity
                printf("Invalid quantity! Please enter a positive number.\n");
                return;
            }
            currentOrder.pizzaCount += quantity; // Update pizza count
            break;
        case 2: // If drink is selected
            printf("How many drinks would you like to order? ");
            scanf("%d", &quantity); // Get quantity
            if (quantity < 0) {
                printf("Invalid quantity! Please enter a positive number.\n");
                return;
            }
            currentOrder.drinkCount += quantity; // Update drink count
            break;
        case 3: // If soup is selected
            printf("How many soups would you like to order? ");
            scanf("%d", &quantity); // Get quantity
            if (quantity < 0) {
                printf("Invalid quantity! Please enter a positive number.\n");
                return;
            }
            currentOrder.soupCount += quantity; // Update soup count
            break;
        case 4: // If salad is selected
            printf("How many salads would you like to order? ");
            scanf("%d", &quantity); // Get quantity
            if (quantity < 0) {
                printf("Invalid quantity! Please enter a positive number.\n");
                return;
            }
            currentOrder.saladCount += quantity; // Update salad count
            break;
        default:
            printf("Invalid choice! Please try again.\n"); // Handle invalid input
    }
}

// Function to display the final total and itemized bill
void showTotal() {
    int total = (currentOrder.pizzaCount * PIZZA_PRICE) + 
                (currentOrder.drinkCount * DRINK_PRICE) + 
                (currentOrder.soupCount * SOUP_PRICE) + 
                (currentOrder.saladCount * SALAD_PRICE); // Calculate total cost

    printf("\n--- Final Invoice ---\n");
    if (total == 0) { // If no items were ordered
        printf("No food ordered!\n");
    } else {
        // Display quantity and total cost for each item
        printf("Pizza: %d Quantity and Total: %d $\n", currentOrder.pizzaCount, currentOrder.pizzaCount * PIZZA_PRICE);
        printf("Drink: %d Quantity and Total: %d $\n", currentOrder.drinkCount, currentOrder.drinkCount * DRINK_PRICE);
        printf("Soup: %d Quantity and Total: %d $\n", currentOrder.soupCount, currentOrder.soupCount * SOUP_PRICE);
        printf("Salad: %d Quantity and Total: %d $\n", currentOrder.saladCount, currentOrder.saladCount * SALAD_PRICE);
        printf("\nTotal: %d $\n", total); // Display the total cost
        printf("Thank you for your order!\n"); // Thank the user
    }
}
