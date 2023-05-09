#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void insert(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        struct Node *lastNode = (*head)->prev;
        lastNode->next = newNode;
        newNode->prev = lastNode;
        newNode->next = *head;
        (*head)->prev = newNode;
    }

    printf("%d insertado en la lista!\n", value);
}

void delete(struct Node **head, int value) {
    if (*head == NULL) {
        printf("La lista está vacía\n");
        return;
    }

    struct Node *currentNode = *head;
    do {
        if (currentNode->data == value) {
            if (*head == currentNode) {  // Si el elemento a eliminar es el primer nodo
                *head = (*head)->next;
            }
            currentNode->prev->next = currentNode->next;
            currentNode->next->prev = currentNode->prev;
            free(currentNode);
            printf("%d eliminado de la lista!\n", value);
            return;
        }
        currentNode = currentNode->next;
    } while (currentNode != *head);

    printf("%d no se encuentra en la lista\n", value);
}

void displayList(struct Node *head) {
    if (head == NULL) {
        printf("La lista está vacía\n");
        return;
    }

    struct Node *currentNode = head;
    do {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    } while (currentNode != head);
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int option, value;

    do {
        printf("Bienvenido, va a realizar una operación\n");
        printf("1.- Insertar un elemento de la lista\n");
        printf("2.- Eliminar un elemento de la lista\n");
        printf("3.- Imprimir la lista\n");
        printf("4.- Salir\n");

        printf("Ingrese la opción: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Ingrese el valor: ");
                scanf("%d", &value);
                insert(&head, value);
                break;
            case 2:
                printf("Ingrese el valor: ");
                scanf("%d", &value);
                delete(&head, value);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Opción inválida!\n");
        }
    } while (1);

    return 0;
}

