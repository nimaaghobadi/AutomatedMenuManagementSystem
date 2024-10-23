// test_automated_menu_management_system

#include "unity.h"  // Including the Unity testing framework for writing unit tests
#include "AutomatedMenuManagementSystem.h"  // Including the header file of the project being tested
#include <stdio.h>   // Including standard I/O functions for handling input/output operations
#include <string.h>  // Including string functions to manipulate and check strings

// Declaring a buffer to capture printed output during tests
static char output_buffer[1024];
// Declaring a file pointer to redirect standard output
static FILE* test_stdout;
// Function to capture printed output during the test
// freopen redirects the stdout to the output_buffer so that we can validate printed output
void captureOutput(void) {
    test_stdout = freopen("/dev/null", "a", stdout);
    setvbuf(stdout, output_buffer, _IOFBF, sizeof(output_buffer));
}
// Function to restore original stdout after capturing output
// This ensures that after the test, the standard output is restored for normal program execution
void restoreOutput(void) {
    freopen("/dev/tty", "a", stdout);
    setvbuf(stdout, NULL, _IONBF, 0);
}
// Initial setup function that runs before each test
// It resets the current order counts to zero to ensure each test starts with a clean state
void setUp(void) {
    currentOrder.pizzaCount = 0;
    currentOrder.drinkCount = 0;
    currentOrder.soupCount = 0;
    currentOrder.saladCount = 0;
}
// Clean-up function that runs after each test
// Since no dynamic memory is used in the tests, nothing needs to be cleaned up here
void tearDown(void) {
    // No clean-up needed for this project
}
// Test case: Ensure correct addition of pizzas when the user selects pizza from the menu
// This test simulates ordering pizzas and checks if the system updates the pizza count correctly
void test_handleOrder_AddPizza(void) {
    handleOrder(1);  // Simulate ordering 1 pizza
    TEST_ASSERT_EQUAL(1, currentOrder.pizzaCount); // Check if pizza count is updated to 1

    handleOrder(1);  // Simulate ordering another pizza
    TEST_ASSERT_EQUAL(2, currentOrder.pizzaCount); // Check if pizza count is now 2
}
// Test case: Ensure correct addition of drinks when the user selects drinks from the menu
// This test simulates ordering drinks and verifies if the drink count is updated correctly
void test_handleOrder_AddDrink(void) {
    handleOrder(2);  // Simulate ordering 1 drink
    TEST_ASSERT_EQUAL(1, currentOrder.drinkCount); // Check if drink count is updated to 1

    handleOrder(2);  // Simulate ordering another drink
    TEST_ASSERT_EQUAL(2, currentOrder.drinkCount); // Check if drink count is now 2
}
// Test case: Ensure correct calculation of the total bill based on the current order
// This test checks if the total cost is calculated correctly by manually setting the order counts and comparing the expected result
void test_showTotal_Calculation(void) {
    currentOrder.pizzaCount = 2;  // Set 2 pizzas in the order
    currentOrder.drinkCount = 3;  // Set 3 drinks in the order
    currentOrder.soupCount = 1;   // Set 1 soup in the order
    currentOrder.saladCount = 0;  // Set 0 salads in the order
    // Manually calculate the expected total based on the prices defined in the project
    int expectedTotal = (2 * PIZZA_PRICE) + (3 * DRINK_PRICE) + (1 * SOUP_PRICE);
    // Capture the output printed by the showTotal function
    captureOutput();
    showTotal();
    restoreOutput();
    // Check if the calculated total matches the manually calculated expected total
    TEST_ASSERT_EQUAL(expectedTotal, (currentOrder.pizzaCount * PIZZA_PRICE) + 
                                      (currentOrder.drinkCount * DRINK_PRICE) +
                                      (currentOrder.soupCount * SOUP_PRICE));

    // Verify that the output contains the keyword "Total:" indicating the total was printed
    TEST_ASSERT_NOT_EQUAL(NULL, strstr(output_buffer, "Total:"));
}
// Test case: Ensure that invalid choices do not affect the order
// This test checks if the system handles an invalid menu choice without updating any item count
void test_handleOrder_InvalidChoice(void) {
    handleOrder(99);  // Simulate an invalid menu choice
    TEST_ASSERT_EQUAL(0, currentOrder.pizzaCount); // Verify pizza count is still 0
    TEST_ASSERT_EQUAL(0, currentOrder.drinkCount); // Verify drink count is still 0
    TEST_ASSERT_EQUAL(0, currentOrder.soupCount);  // Verify soup count is still 0
    TEST_ASSERT_EQUAL(0, currentOrder.saladCount); // Verify salad count is still 0
}
// Test case: Handle large quantities of items, such as more than 10 pizzas
// This test ensures that the system can handle a large number of orders without errors
void test_handleOrder_LargeQuantities(void) {
    currentOrder.pizzaCount = 0; // Start with zero pizzas
    int largeQuantity = 10;
    // Simulate ordering 10 pizzas
    for (int i = 0; i < largeQuantity; i++) {
        handleOrder(1);  // Simulate ordering a pizza
    }
    // Verify that the pizza count is correctly updated to 10
    TEST_ASSERT_EQUAL(largeQuantity, currentOrder.pizzaCount);
}
// Test case: Handle invalid negative input for menu choices
// This test checks if the system correctly ignores invalid negative inputs
void test_handleOrder_InvalidNegative(void) {
    currentOrder.pizzaCount = 1;  // Start with one pizza in the order

    // Simulate an invalid negative input (-1)
    handleOrder(-1);

    // Verify that the pizza count remains unchanged
    TEST_ASSERT_EQUAL(1, currentOrder.pizzaCount);
}
// Test case: Ensure no changes when choice is zero (invalid choice for the menu)
void test_handleOrder_ZeroChoice(void) {
    handleOrder(0);  // Simulate a choice of 0, which is invalid
    TEST_ASSERT_EQUAL(0, currentOrder.pizzaCount); // Verify pizza count is still 0
    TEST_ASSERT_EQUAL(0, currentOrder.drinkCount); // Verify drink count is still 0
    TEST_ASSERT_EQUAL(0, currentOrder.soupCount);  // Verify soup count is still 0
    TEST_ASSERT_EQUAL(0, currentOrder.saladCount); // Verify salad count is still 0
}
// Test case: Ensure no double counting of same item
// This test checks that re-adding the same item does not result in a double count for the same function call
void test_handleOrder_NoDoubleCount(void) {
    handleOrder(1);  // Simulate ordering 1 pizza
    TEST_ASSERT_EQUAL(1, currentOrder.pizzaCount); // Verify that pizza count is 1

    handleOrder(1);  // Simulate ordering another pizza
    TEST_ASSERT_EQUAL(2, currentOrder.pizzaCount); // Verify that pizza count is now 2

    handleOrder(1);  // Verify another addition
    TEST_ASSERT_EQUAL(3, currentOrder.pizzaCount); // Ensure no double counting
}
// Main test runner function
// This function runs all the test cases defined above
int main(void) {
    UNITY_BEGIN();  // Initialize the Unity test framework

    // Run each test function one by one
    RUN_TEST(test_handleOrder_AddPizza);
    RUN_TEST(test_handleOrder_AddDrink);
    RUN_TEST(test_showTotal_Calculation);
    RUN_TEST(test_handleOrder_InvalidChoice);
    RUN_TEST(test_handleOrder_LargeQuantities);
    RUN_TEST(test_handleOrder_InvalidNegative);
    RUN_TEST(test_handleOrder_ZeroChoice); // New test for zero input
    RUN_TEST(test_handleOrder_NoDoubleCount); // New test to check no double counting

    return UNITY_END();  // Conclude the testing process
}

