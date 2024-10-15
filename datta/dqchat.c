#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node* next;
};

// Global pointers for front and rear of the queue
struct node* front = NULL;
struct node* rear = NULL;

// Function to check if the queue is empty
int isempty() {
    return front == NULL; // Return 1 if empty, else 0
}

// Function to enqueue an item
void enqueue() {
    int val;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data part:\n");
    scanf("%d", &val);
    newnode->data = val;
    newnode->next = NULL;

    // If the queue is empty, both front and rear will point to the new node
    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode; // Link the new node at the end of the queue
        rear = newnode;       // Update rear to point to the new node
    }
}

// Function to dequeue an item
int dequeue() {
    if (isempty()) {
        printf("Queue is underflow\n");
        return -1; // Indicate underflow
    }

    struct node* temp = front; // Temporary pointer to the front node
    int item = front->data;     // Get the data to return
    front = front->next;        // Move front to the next node

    // If front becomes NULL, also update rear to NULL
    if (front == NULL) {
        rear = NULL;
    }

    free(temp); // Free the old front node
    return item; // Return the dequeued item
}

// Function to peek at the front item
int peek() {
    if (isempty()) {
        printf("Queue is empty\n");
        return -1; // Indicate empty queue
    }
    return front->data; // Return the data at the front
}

// Function to display the queue
void display() {
    if (isempty()) {
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = front; // Start from the front
    while (temp != NULL) {
        printf("%d\t", temp->data); // Print the data
        temp = temp->next;          // Move to the next node
    }
    printf("\n"); // New line after displaying all elements
}

// Main function to test the queue implementation
int main() {
    int ch;
    do {
        printf("Enter your choice:\n");
        printf("1. IsEmpty\n2. Enqueue\n3. Dequeue\n4. Peek\n5. Exit\n6. Display\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                if (isempty())
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;
            case 2:
                enqueue();
                break;
            case 3: {
                int value = dequeue();
                if (value != -1) // Only print if not underflow
                    printf("Dequeued value: %d\n", value);
                break;
            }
            case 4: {
                int value = peek();
                if (value != -1) // Only print if queue is not empty
                    printf("Front value: %d\n", value);
                break;
            }
            case 5:
                printf("Exiting...\n");
                break;
            case 6:
                printf("Queue elements: ");
                display();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (ch != 5);

    // Free memory
    while (!isempty()) {
        dequeue();
    }
    
    return 0;
}
