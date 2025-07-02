#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong the cap phat bo nho.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void printList(Node* head) {
    printf("Danh sach lien ket: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int search(Node* head, int target) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == target)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int i, value;

    printf("Nhap 5 so nguyen de tao danh sach:\n");
    for (i = 0; i < 5; i++) {
        printf("Nhap so thu %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }

    printList(head);

    int target;
    printf("Nhap so nguyen duong can tim: ");
    scanf("%d", &target);

    if (search(head, target)) {
        printf("Tim thay %d trong danh sach.\n", target);
    } else {
        printf("Khong tim thay %d trong danh sach.\n", target);
    }

    freeList(head);

    return 0;
}
