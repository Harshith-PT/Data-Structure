#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct node* insertEnd(struct node *head, int data) {
    struct node *temp = createNode(data);

    if (head == NULL)
        return temp;

    struct node *p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
    return head;
}


void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


void sortList(struct node *head) {
    struct node *i, *j;
    int temp;

    if (head == NULL)
        return;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


struct node* reverseList(struct node *head) {
    struct node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


struct node* concatenate(struct node *head1, struct node *head2) {
    if (head1 == NULL)
        return head2;

    struct node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}


int main() {
    struct node *list1 = NULL, *list2 = NULL;


    list1 = insertEnd(list1, 3);
    list1 = insertEnd(list1, 1);
    list1 = insertEnd(list1, 5);


    list2 = insertEnd(list2, 4);
    list2 = insertEnd(list2, 2);

    printf("List 1:\n");
    display(list1);

    printf("List 2:\n");
    display(list2);


    sortList(list1);
    printf("\nSorted List 1:\n");
    display(list1);


    list1 = reverseList(list1);
    printf("\nReversed List 1:\n");
    display(list1);


    list1 = concatenate(list1, list2);
    printf("\nConcatenated List:\n");
    display(list1);

    return 0;
}

