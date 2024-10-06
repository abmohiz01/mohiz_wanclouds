#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store person data
typedef struct {
    char name[50];
    int id;
} Person;

// Constructing Doubly Linked List Node 
typedef struct Node {
    Person person;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(char* name, int id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->person.name, name);
    newNode->person.id = id;
    newNode->prev = NULL;
    newNode->next = NULL;
    printf("Log: Created node with ID %d and Name %s.\n", id, name);
    return newNode;
}

// Insert node at the end of the list
void insert(Node** head, char* name, int id) {
    Node* newNode = createNode(name, id);
    if (*head == NULL) {
        *head = newNode;
        printf("Log: Inserted node with ID %d as the head.\n", id);
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("Log: Inserted node with ID %d at the end of the list.\n", id);
}

//Will Delete the node by ID
void delete(Node** head, int id) {
    if (*head == NULL) {
        printf("Log: List is empty, nothing to delete.\n");
        return;
    }

    Node* temp = *head;
    while (temp != NULL && temp->person.id != id) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Log: Node with ID %d not found.\n", id);
        return; // ID not found
    }

    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    
    if (temp == *head) *head = temp->next;  // If head is removed
    free(temp);
    printf("Log: Deleted node with ID %d.\n", id);
}

// Sort the list by ID (simple bubble sort)
void sort(Node** head) {
    if (*head == NULL) {
        printf("Log: List is empty, nothing to sort.\n");
        return;
    }

    Node* i;
    Node* j;
    for (i = *head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->person.id > j->person.id) {
                // Swap the person data
                Person temp = i->person;
                i->person = j->person;
                j->person = temp;
            }
        }
    }
    printf("Log: List sorted by ID.\n");
}


void display(Node* head) {
    if (head == NULL) {
        printf("Log: List is empty.\n");
        return;
    }
    
    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d(%s)", temp->person.id, temp->person.name);
        if (temp->next != NULL) {
            printf("->");
        }
        temp = temp->next;
    }
    printf("->NULL\n");
}


int main() {
    Node* head = NULL;
    int choice, id;
    char name[50];

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Sort\n4. Display\n5. Exit\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                insert(&head, name, id);
                break;
            case 2:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                delete(&head, id);
                break;
            case 3:
                sort(&head);
                break;
            case 4:
                display(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
