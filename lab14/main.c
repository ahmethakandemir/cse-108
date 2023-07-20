#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Order {
    char customerName[50];
    int orderID;
    char items[100];
    time_t orderTime;
    struct Order* next;
} Order;

typedef struct {
    Order* front;
    Order* rear;
} FIFO;

typedef struct {
    Order* top;
} LIFO;

void enqueue(Order** list, char* customerName, int orderID, char* items, time_t orderTime) {
    Order* newOrder = (Order*)malloc(sizeof(Order));
    strcpy(newOrder->customerName, customerName);
    newOrder->orderID = orderID;
    strcpy(newOrder->items, items);
    newOrder->orderTime = orderTime;
    newOrder->next = NULL;

    if (*list == NULL) {
        *list = newOrder;
    } else {
        Order* temp = *list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newOrder;
    }

    printf("Order Added: Customer Name: %s, Order ID: %d, Items: %s, Order Time: %s", customerName, orderID, items, ctime(&orderTime));
}

Order* dequeue(Order** list, time_t thresholdTime) {
    Order* current = *list;
    Order* previous = NULL;
    Order* removedOrders = NULL;

    while (current != NULL) {
        if (current->orderTime < thresholdTime) {
            if (previous == NULL) {
                *list = current->next;
            } else {
                previous->next = current->next;
            }

            Order* removedOrder = current;
            current = current->next;
            removedOrder->next = removedOrders;
            removedOrders = removedOrder;
        } else {
            previous = current;
            current = current->next;
        }
    }

    Order* temp = removedOrders;
    while (temp != NULL) {
        printf("Order Removed from Queue: Customer Name: %s, Order ID: %d, Items: %s, Order Time: %s", temp->customerName, temp->orderID, temp->items, ctime(&temp->orderTime));
        temp = temp->next;
    }

    return removedOrders;
}

void serializeLIFO(LIFO* stack, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    Order* current = stack->top;
    while (current != NULL) {
        fwrite(current, sizeof(Order), 1, file);
        current = current->next;
    }

    fclose(file);

    printf("LIFO data structure serialized to a binary file.\n");
}

LIFO* deserializeLIFO(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return NULL;
    }

    LIFO* stack = (LIFO*)malloc(sizeof(LIFO));
    stack->top = NULL;

    Order* current = NULL;
    Order* previous = NULL;
    Order* order = (Order*)malloc(sizeof(Order));

    while (fread(order, sizeof(Order), 1, file) == 1) {
        current = (Order*)malloc(sizeof(Order));
        memcpy(current, order, sizeof(Order));

        if (stack->top == NULL) {
            stack->top = current;
        } else {
            current->next = stack->top;
            stack->top = current;
        }
    }

    fclose(file);
    free(order);

    printf("LIFO data structure deserialized from a binary file.\n");

    return stack;
}

void serializeFIFO(FIFO* queue, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    Order* current = queue->front;
    while (current != NULL) {
        fwrite(current, sizeof(Order), 1, file);
        current = current->next;
    }

    fclose(file);

    printf("FIFO data structure serialized to a binary file.\n");
}

FIFO* deserializeFIFO(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return NULL;
    }

    FIFO* queue = (FIFO*)malloc(sizeof(FIFO));
    queue->front = NULL;
    queue->rear = NULL;

    Order* current = NULL;
    Order* previous = NULL;
    Order* order = (Order*)malloc(sizeof(Order));

    while (fread(order, sizeof(Order), 1, file) == 1) {
        current = (Order*)malloc(sizeof(Order));
        memcpy(current, order, sizeof(Order));

        if (queue->front == NULL) {
            queue->front = current;
            queue->rear = current;
        } else {
            queue->rear->next = current;
            queue->rear = current;
        }
    }

    fclose(file);
    free(order);

    printf("FIFO data structure deserialized from a binary file.\n");

    return queue;
}

int main() {
    LIFO stack;
    stack.top = NULL;
    enqueue(&stack.top, "Ali Yilmaz", 101, "Pizza, Salad, Ice Cream", time(NULL));
    enqueue(&stack.top, "Ayse Demir", 102, "Steak, Mashed Potatoes, Salad", time(NULL));
    Order* removedOrders = dequeue(&stack.top, time(NULL));
    serializeLIFO(&stack, "lifo_data.bin");
    LIFO* deserializedLIFO = deserializeLIFO("lifo_data.bin");

    FIFO queue;
    queue.front = NULL;
    queue.rear = NULL;
    enqueue(&queue.front, "Ali Yilmaz", 101, "Pizza, Salad, Ice Cream", time(NULL));
    enqueue(&queue.front, "Ayse Demir", 102, "Steak, Mashed Potatoes, Salad", time(NULL));
    removedOrders = dequeue(&queue.front, time(NULL));
    serializeFIFO(&queue, "fifo_data.bin");
    FIFO* deserializedFIFO = deserializeFIFO("fifo_data.bin");

    return 0;
}
