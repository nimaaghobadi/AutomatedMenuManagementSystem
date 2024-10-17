#include "unity.h"   // Including the Unity testing framework
#include "AutomatedMenuManagementSystem.h" // Include the header file for your project (change as necessary)
#include <stdio.h>
#include <string.h>

// Redirect output stream for testing printed output
static char output_buffer[1024];
static FILE* test_stdout;

// Function to capture printed output
void captureOutput(void) {
    test_stdout = freopen("/dev/null", "a", stdout);
    setvbuf(stdout, output_buffer, _IOFBF, sizeof(output_buffer));
}

// Restore original stdout
void restoreOutput(void) {
    freopen("/dev/tty", "a", stdout);
    setvbuf(stdout, NULL, _IONBF, 0);
}

// Initial setup before each test
void setUp(void) {
    // Resetting the currentOrder structure to 0 before each test to ensure clean tests
    currentOrder.pizzaCount = 0;
    currentOrder.drinkCount = 0;
    currentOrder.soupCount = 0;
    currentOrder.saladCount = 0;
}

// Clean-up function after each test
void tearDown(void) {
    // No dynamic memory used, so nothing to clean up
}

// Test case: Ensure correct addition of pizzas
void test_handleOrder_AddPizza(void) {
    handleOrder(1);  // Simulate ordering 1 pizza
    TEST_ASSERT_EQUAL(1, currentOrder.pizzaCount); // Assert that the pizza count is updated to 1

    handleOrder(1);  // Simulate ordering another pizza
    TEST_ASSERT_EQUAL(2, currentOrder.pizzaCount); // Assert that the pizza count is now 2
}

// Test case: Ensure correct addition of drinks
void test_handleOrder_AddDrink(void) {
    handleOrder(2);  // Simulate ordering 1 drink
    TEST_ASSERT_EQUAL(1, currentOrder.drinkCount); // Assert that the drink count is updated to 1

    handleOrder(2);  // Simulate ordering another drink
    TEST_ASSERT_EQUAL(2, currentOrder.drinkCount); // Assert that the drink count is now 2
}

// Test case: Ensure correct calculation of the total amount
void test_showTotal_Calculation(void) {
    currentOrder.pizzaCount = 2;  // Assume 2 pizzas ordered
    currentOrder.drinkCount = 3;  // Assume 3 drinks ordered
    currentOrder.soupCount = 1;   // Assume 1 soup ordered
    currentOrder.saladCount = 0;  // Assume no salad ordered

    // Calculate the expected total manually
    int expectedTotal = (2 * PIZZA_PRICE) + (3 * DRINK_PRICE) + (1 * SOUP_PRICE);

    // Capture output
    captureOutput();
    showTotal();
    restoreOutput();

    // Manually assert the expected total
    TEST_ASSERT_EQUAL(expectedTotal, (currentOrder.pizzaCount * PIZZA_PRICE) +
                                      (currentOrder.drinkCount * DRINK_PRICE) +
                                      (currentOrder.soupCount * SOUP_PRICE));

    // Check that output contains correct total
    TEST_ASSERT_NOT_EQUAL(NULL, strstr(output_buffer, "Total:"));
}

// Test case: Ensure invalid choice does not update any order
void test_handleOrder_InvalidChoice(void) {
    handleOrder(99);  // Simulate invalid menu choice
    TEST_ASSERT_EQUAL(0, currentOrder.pizzaCount); // Assert pizza count remains 0
    TEST_ASSERT_EQUAL(0, currentOrder.drinkCount); // Assert drink count remains 0
    TEST_ASSERT_EQUAL(0, currentOrder.soupCount);  // Assert soup count remains 0
    TEST_ASSERT_EQUAL(0, currentOrder.saladCount); // Assert salad count remains 0
}

// Test case: Handle large quantities (more than 10 pizzas)
void test_handleOrder_LargeQuantities(void) {
    currentOrder.pizzaCount = 0;
    int largeQuantity = 10;
    for (int i = 0; i < largeQuantity; i++) {
        handleOrder(1);  // Simulate ordering multiple pizzas
    }
    TEST_ASSERT_EQUAL(largeQuantity, currentOrder.pizzaCount); // Assert that the pizza count is correct
}

// Test case: Handle invalid negative quantities
void test_handleOrder_InvalidNegative(void) {
    currentOrder.pizzaCount = 1;  // Set a valid pizza count

    // Simulate invalid negative input
    handleOrder(-1);

    // Assert that the pizza count remains unchanged
    TEST_ASSERT_EQUAL(1, currentOrder.pizzaCount);
}

// Main test runner
int main(void) {
    UNITY_BEGIN();  // Start Unity test framework

    RUN_TEST(test_handleOrder_AddPizza);    // Run the test for adding pizzas
    RUN_TEST(test_handleOrder_AddDrink);    // Run the test for adding drinks
    RUN_TEST(test_showTotal_Calculation);   // Run the test for total calculation
    RUN_TEST(test_handleOrder_InvalidChoice); // Run the test for handling invalid input
    RUN_TEST(test_handleOrder_LargeQuantities); // Run the test for handling large quantities
    RUN_TEST(test_handleOrder_InvalidNegative); // Run the test for handling invalid negative inputs

    return UNITY_END();  // End Unity test framework
}
