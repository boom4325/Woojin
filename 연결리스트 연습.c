#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

void print(ListNode* head) {
    ListNode* p = head;

    while (p != NULL) {
        printf("%d->", p->data);
        p = p->link;
    }
    printf("\n");
}

ListNode* alternate(ListNode* head1, ListNode* head2) {
    ListNode* p1, * p2, * np;
    ListNode* newhead;

    newhead = NULL;
    np = NULL;
    p1 = head1;
    p2 = head2;

    while (p1 != NULL && p2 != NULL) {
        if (newhead == NULL) {
            if (p1->data < p2->data) {
                newhead = p1;
                np = newhead;
                p1 = p1->link;
            }
            else if (p1->data > p2->data) {
                newhead = p2;
                np = newhead;
                p2 = p2->link;
            }
        }
        else {
            if (p1->data < p2->data) {
                np->link = p1;
                np = p1;
                p1 = p1->link;
            }
            else if (p1->data > p2->data) {
                np->link = p2;
                np = p2;
                p2 = p2->link;
            }
        }
        np->link = NULL;
        print(newhead);
    }
    if (p1 != NULL) {
        np->link = p1;
    }
    else if (p2 != NULL) {
        np->link = p2;
    }
    return newhead;
}

void main() {
    ListNode* head1, * head2;
    head1 = NULL;
    head2 = NULL;

    ListNode* p1;
    p1 = (ListNode*)malloc(sizeof(ListNode));
    p1->data = 1;
    p1->link = NULL;
    head1 = p1;

    ListNode* p2;
    p2 = (ListNode*)malloc(sizeof(ListNode));
    p2->data = 3;
    p2->link = NULL;
    p1->link = p2;

    ListNode* p3;
    p3 = (ListNode*)malloc(sizeof(ListNode));
    p3->data = 4;
    p3->link = NULL;
    p2->link = p3;

    ListNode* p4;
    p4 = (ListNode*)malloc(sizeof(ListNode));
    p4->data = 2;
    p4->link = NULL;
    head2 = p4;

    ListNode* p5;
    p5 = (ListNode*)malloc(sizeof(ListNode));
    p5->data = 5;
    p5->link = NULL;
    p4->link = p5;

    print(head1); 

    print(head2); 

    print(alternate(head1, head2));

}
