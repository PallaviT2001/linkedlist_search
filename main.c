#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
int count = 0;

struct node* creationandinsertion(struct node* head, int* count) {
    struct node* newnode, *temp = NULL;
    int choice = 1;

    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (!newnode) {
            printf("Memory allocation failed\n");
            return head;
        }
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Press 1 to continue and 0 to exit: ");
        scanf("%d", &choice);
    }
    return head;
}
void display(struct node* head) {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
        count++;
    }
    printf("NULL\n");
}

void searchbyvalue(struct node* head) {
    int value, position = 0, found = 0;
    printf("Enter the value to search: ");
    scanf("%d", &value);

    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d\n", value, position);
            found = 1;
        }
        temp = temp->next;
        position++;
    }
    if (!found) {
        printf("Value %d not found in the list\n", value);
    }
}

void searchbyposition(struct node* head) {
    int position, current_position = 0;
    printf("Enter the position to search: ");
    scanf("%d", &position);

    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }

    struct node* temp = head;
    while (temp != NULL) {
        if (current_position == position) {
            printf("Value at position %d is %d\n", position, temp->data);
            return;
        }
        temp = temp->next;
        current_position++;
    }
    printf("Position %d exceeds the length of the list\n", position);
}

int main() {
    int choice = 1, option;

    while (choice) {
        printf("******* Select an operation ********\n");
        printf("1. Linked list creation\n");
        printf("2. Display\n");
        printf("3. Search by value\n");
        printf("4. Search by position\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            head = creationandinsertion(head, &count);
            break;
        case 2:
            display(head);
            break;
        case 3:
            searchbyvalue(head);
            break;
        case 4:
            searchbyposition(head);
            break;
        case 5:
            printf("Exiting\n");
            exit(0);
        default:
            printf("Invalid choice, try again\n");
        }
    }
    return 0;
}
