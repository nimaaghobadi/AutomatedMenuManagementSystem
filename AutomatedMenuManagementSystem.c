// Restaurant Menu App
#include <stdio.h>
//#include <stdio.h>
 
#define PIZZA_PRICE 17
#define DRINK_PRICE 1
#define SOUP_PRICE 8
#define SALAD_PRICE 10  // Defining default prices for the menu items

// Structure to store orders
typedef struct {
    int pizzaCount;  // Number of pizzas ordered
    int drinkCount;  // Number of drinks ordered
    int soupCount;   // Number of soups ordered
    int saladCount;  // Number of salads ordered
} Order; // Creating a structure named 'Order' to track the quantities ordered

Order currentOrder = {0, 0, 0, 0};  // Initializing the order structure with zero quantities

// Function prototypes
void showMenu(); // Function to display the menu
void handleOrder(int choice); // Function to handle the order based on user choice
void showTotal(); // Function to display the final invoice

int main() {
    int choice; // Variable to store user input

    while (1) { // Loop to allow user interaction until they choose to exit
        showMenu(); // Display the menu
        printf("Your choice: ");
        scanf("%d", &choice); // Get user input

        if (choice == 5) {
            showTotal(); // If the user chooses 5, display the final invoice
            break; // Exit the loop
        } else {
            handleOrder(choice); // Handle the order based on user's choice
        }
    }

    return 0; // Exit the program
}

// Function to display the restaurant menu
void showMenu() {
    printf("\n--- Restaurant Menu ---\n");
    printf("1. Order Pizza (%d $)\n", PIZZA_PRICE);
    printf("2. Order Drink (%d $)\n", DRINK_PRICE);
    printf("3. Order Soup (%d $)\n", SOUP_PRICE);
    printf("4. Order Salad (%d $)\n", SALAD_PRICE);
    printf("5. Total Amount and Exit\n"); // Option to exit and view total amount
}

// Function to handle the user's order based on their choice
void handleOrder(int choice) {
    int quantity; // Variable for the number of items

    switch (choice) { // Update the quantities based on user's choice
        case 1:
            printf("How many pizzas would you like to order? ");
            scanf("%d", &quantity);
            currentOrder.pizzaCount += quantity; // Update pizza count
            break;
        case 2:
            printf("How many drinks would you like to order? ");
            scanf("%d", &quantity);
            currentOrder.drinkCount += quantity; // Update drink count
            break;
        case 3:
            printf("How many soups would you like to order? ");
            scanf("%d", &quantity);
            currentOrder.soupCount += quantity; // Update soup count
            break;
        case 4:
            printf("How many salads would you like to order? ");
            scanf("%d", &quantity);
            currentOrder.saladCount += quantity; // Update salad count
            break;
        default:
            printf("Invalid choice! Please try again.\n"); // Handle invalid input
    }
}

// Function to calculate and display the final bill based on orders
void showTotal() {
    int total = (currentOrder.pizzaCount * PIZZA_PRICE) +
                (currentOrder.drinkCount * DRINK_PRICE) +
                (currentOrder.soupCount * SOUP_PRICE) +
                (currentOrder.saladCount * SALAD_PRICE); // Calculate total amount

    printf("\n--- Final Invoice ---\n"); // Displaying the invoice

    if (total == 0) {
        printf("No food ordered!\n"); // Display message if no food has been ordered
    } else {
        // Display quantities and totals for each ordered item
        printf("Pizza: %d Quantity and Total: %d $\n", currentOrder.pizzaCount, currentOrder.pizzaCount * PIZZA_PRICE);
        printf("Drink: %d Quantity and Total: %d $\n", currentOrder.drinkCount, currentOrder.drinkCount * DRINK_PRICE);
        printf("Soup: %d Quantity and Total: %d $\n", currentOrder.soupCount, currentOrder.soupCount * SOUP_PRICE);
        printf("Salad: %d Quantity and Total: %d $\n", currentOrder.saladCount, currentOrder.saladCount * SALAD_PRICE);
        printf("\nTotal: %d $\n", total); // Display total amount
        printf("Thank you for your order!\n"); // Thank customer for their order
    }
}
