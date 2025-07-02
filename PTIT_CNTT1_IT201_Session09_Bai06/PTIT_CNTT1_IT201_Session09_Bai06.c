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
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void deleteHead(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong, khong co phan tu de xoa.\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Da xoa phan tu dau tien.\n");
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
    int value;

    printf("Nhap 5 so nguyen de tao danh sach:\n");
    for (int i = 0; i < 5; i++) {
        printf("Nhap so thu %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Danh sach truoc khi xoa:\n");
    printList(head);

    deleteHead(&head);

    printf("Danh sach sau khi xoa phan tu dau:\n");
    printList(head);

    freeList(head);
    return 0;
}
