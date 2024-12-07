#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("Ds trong , k the xoa.\n");
        return;
    }

    if (position < 0) {
        printf("Vi tri k hop le.\n");
        return;
    }

    Node* temp = *head;

    if (position == 0) { 
        *head = temp->next;
        free(temp);
        return;
    }

    Node* prev = NULL;
    int currentIndex = 0;

    while (temp != NULL && currentIndex < position) {
        prev = temp;
        temp = temp->next;
        currentIndex++;
    }

    if (temp == NULL) {
        printf("Vi tri ngoai pham vi.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}


void printList(Node* head) {
    Node* current = head;
    printf("ds hien tai: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int n, position, value;

    printf("Nhap so phan tu ban dau: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &value);
        Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    printList(head);

    printf("Nhap vi tri can xoa: ");
    scanf("%d", &position);
    deleteAtPosition(&head, position);
    printList(head);

    freeList(head);
    return 0;
}

