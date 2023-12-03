 #include <stdio.h>
#include <string.h>

// Country Listing


#define MAX_Country_SIZE 100

// Define the data structure for a Country (assuming it has a name)
struct Country {
    char name[50];
};

struct Country CountryList[MAX_Country_SIZE];
int top = -1; // Initialize the top of the stack

// Function to push a Country onto the stack
void push() {
    if (top >= MAX_Country_SIZE - 1) {
        printf("Stack is full. Cannot push more Countrys.\n");
    } else {
        struct Country newCountry;
        printf("Enter the name of the Country: ");
        scanf("%s", newCountry.name);
        top++;
        CountryList[top] = newCountry;
        printf("Country '%s' pushed onto the stack.\n", newCountry.name);
    }
}

// Function to pop a Country from the stack
void pop() {
    if (top < 0) {
        printf("Stack is empty. Cannot pop Countrys.\n");
    } else {
        printf("Popping Country '%s' from the stack.\n", CountryList[top].name);
        top--;
    }
}

// Function to search for a Country by name
void search() {
    if (top < 0) {
        printf("Stack is empty. No Countrys to search.\n");
    } else {
        char searchName[50];
        printf("Enter the name to search for: ");
        scanf("%s", searchName);
        int found = 0;
        for (int i = top; i >= 0; i--) {
            if (strcmp(CountryList[i].name, searchName) == 0) {
                printf("Country '%s' found at position %d.\n", searchName, i);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Country '%s' not found in the stack.\n", searchName);
        }
    }
}

// Function to display the list of Countrys
void display() {
    if (top < 0) {
        printf("Stack is empty. No Countrys to display.\n");
    } else {
        printf("List of Countrys in the stack:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d. %s\n", i + 1, CountryList[i].name);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Push a Country\n");
        printf("2. Pop a Country\n");
        printf("3. Search for a Country by name\n");
        printf("4. Display the list of Countrys\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                search();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}