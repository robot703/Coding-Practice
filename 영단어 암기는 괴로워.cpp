#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// 구조체 정의
typedef struct Node {
    char name[100];
    char phone[15];
    struct Node* next;
} Node;

// 함수 선언
Node* createNode(char* name, char* phone);
void insertSorted(Node** head, char* name, char* phone);
void printList(Node* head);
char* searchPhoneNumber(Node* head, char* name);

int main() {

    FILE* file = fopen("data.txt", "r");
    if (file == NULL) {
        perror("파일을 열 수 없습니다.");
        return EXIT_FAILURE;
    }

    Node* head = NULL;
    char name[100], phone[15];

    // 파일에서 이름과 전화번호 읽기 및 연결리스트에 삽입
    while (fscanf(file, "%s %s", name, phone) != EOF) {
        insertSorted(&head, name, phone);
    }
    fclose(file);

    // 정렬된 리스트 출력
    printf("정렬된 이름과 전화번호:\n");
    printList(head);

    // 이름 입력 및 전화번호 검색
    printf("검색할 이름을 입력하세요: ");
    scanf("%s", name);

    printf("%s", name);
    char* result = searchPhoneNumber(head, name);
    if (result != NULL) {
        printf("%s의 전화번호: %s\n", name, result);
    }
    else {
        printf("이름 '%s'을(를) 찾을 수 없습니다.\n", name);
    }

    // 메모리 해제
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return EXIT_SUCCESS;
}

// 새로운 노드 생성
Node* createNode(char* name, char* phone) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = NULL;
    return newNode;
}

// 연결리스트에 이름의 오름차순으로 삽입
void insertSorted(Node** head, char* name, char* phone) {
    Node* newNode = createNode(name, phone);
    if (*head == NULL || strcmp((*head)->name, name) > 0) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
        Node* current = *head;
        while (current->next != NULL && strcmp(current->next->name, name) < 0) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// 연결리스트 출력
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->phone);
        current = current->next;
    }
}

// 이름으로 전화번호 검색
char* searchPhoneNumber(Node* head, char* name) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->phone;
        }
        current = current->next;
    }
    return NULL; // 이름을 찾지 못한 경우
}