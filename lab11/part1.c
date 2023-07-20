#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Order {
    char customerName[100];
    int orderID;
    char items[100];
    char orderTime[100];
    struct Order* next;
} Order;

Order* enqueue(Order* queue, char* customerName, int orderID, char* items, char* orderTime) {
    Order* newOrder = (Order*)malloc(sizeof(Order));
    
    strcpy(newOrder->customerName, customerName);
    newOrder->orderID = orderID;
    strcpy(newOrder->items, items);
    strcpy(newOrder->orderTime, orderTime);
    newOrder->next = NULL;

    if (queue == NULL) {
        return newOrder;
    }

    Order* current = queue;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newOrder;
    return queue;
}

Order* dequeue(Order* queue) {
    if (queue == NULL) {
        printf("Queue is empty.\n");
        return NULL;
    }

    Order* dequeuedOrder = queue;
    queue = queue->next;
    dequeuedOrder->next = NULL;

    printf("Dequeued: Order ID: %d, Customer Name: %s, Items: %s\n", dequeuedOrder->orderID, dequeuedOrder->customerName, dequeuedOrder->items);

    free(dequeuedOrder);
    return queue;
}

void display(Order* queue) {
    if (queue == NULL) {
        printf("No orders in the queue.\n");
        return;
    }

    if (queue->next != NULL) {
        display(queue->next);
    }

    printf("- Order ID: %d, Customer Name: %s, Items: %s\n", queue->orderID, queue->customerName, queue->items);
}


void updateOrder(Order* queue, int orderID, char* newItems) {
    Order* current = queue;
    while (current != NULL) {
        if (current->orderID == orderID) {
            strcpy(current->items, newItems);
            return;
        }
    }

    printf("Order ID %d not found.\n", orderID);
}

void freeQueue(Order* queue) {
    Order* current = queue;
    while (current != NULL) {
        Order* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Order* queue = NULL;

    printf("\nEnqueue Operation:\n");
    queue = enqueue(queue, "Barış Ozcan", 101, "Burger, Fries, Coke", "10:30 AM");
    printf("Enqueued: Order ID: %d, Customer Name: %s, Items: %s\n", queue->orderID, queue->customerName, queue->items);

    printf("\nDisplay Orders by Order Time:\n");
    display(queue);

    printf("\nEnqueue Operation:\n");
    queue = enqueue(queue, "Zehra Bilici", 102, "Pizza, Salad, Ice Cream", "11:45 AM");
    printf("Enqueued: Order ID: %d, Customer Name: %s, Items: %s\n", queue->next->orderID, queue->next->customerName, queue->next->items);
    printf("\nDisplay Orders by Order Time:\n");
    display(queue);

    printf("\nEnqueue Operation:\n");
    queue = enqueue(queue, "Mehmet Burak Koca", 103, "Steak, Mashed Potatoes, Salad", "12:15 PM");
    printf("Enqueued: Order ID: %d, Customer Name: %s, Items: %s\n", queue->next->next->orderID, queue->next->next->customerName, queue->next->next->items);
    printf("\nDisplay Orders by Order Time:\n");
    display(queue);


    printf("\nDequeue Operation:\n");
    printf("Dequeued Orders Older than Threshold Time:\n");
    queue = dequeue(queue);

    printf("\nDisplay Orders by Order Time:\n");
    display(queue);

    printf("\nDisplay Orders by Customer Name:\n");
    display(queue);

    printf("\nUpdate Order:\n");
    updateOrder(queue, 102, "Pizza, Salad, Coke");
    printf("Updated Order: Order ID: %d, Customer Name: %s, Items: %s\n", queue->orderID, queue->customerName, queue->items);
    printf("\nDisplay Orders by Order Time:\n");
    display(queue);

    freeQueue(queue);
    printf("\n\n\n");
    return 0;
}
