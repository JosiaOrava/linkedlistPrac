#include "stdio.h"
#include "stdlib.h"


struct Node {
    int data;
    struct Node* next;
};


struct Node* sortList(struct Node* pNode){
    // If zero or one element in list return
    if(pNode == NULL || pNode->next == NULL) return pNode;
    
    struct Node* sorted = NULL;
    sorted = (struct Node*)malloc(sizeof(struct Node));
    while(pNode != NULL){
        struct Node* tmp = pNode;
        pNode = pNode->next;
        if(sorted == NULL || tmp->data < sorted->data){
            // If sorted is empty put tmp as the first
            // If tmp data is smaller make it first
            tmp->next = sorted;
            sorted = tmp;  
        } else {
            struct Node* p = sorted;
            while(p != NULL) {
                if(p->next == NULL || tmp->data < p->next->data){
                    tmp->next = p->next;
                    p->next = tmp;
                    break;
                }
                p = p->next;
            }
        }
    }
    return sorted;
}

void printList(struct Node* head){
    struct Node* curr = head;
    while(curr != NULL){
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}


int main(){
    struct Node* n1 = NULL;
    struct Node* n2 = NULL;
    struct Node* n3 = NULL;
    struct Node* n4 = NULL;
    struct Node* n5 = NULL;
    struct Node* n6 = NULL;
    struct Node* n7 = NULL;
    struct Node* n8 = NULL;
    struct Node* n9 = NULL;
    struct Node* n10 = NULL;



    n1 = (struct Node*)malloc(sizeof(struct Node));
    n2 = (struct Node*)malloc(sizeof(struct Node));
    n3 = (struct Node*)malloc(sizeof(struct Node));
    n4 = (struct Node*)malloc(sizeof(struct Node));
    n5 = (struct Node*)malloc(sizeof(struct Node));
    n6 = (struct Node*)malloc(sizeof(struct Node));
    n7 = (struct Node*)malloc(sizeof(struct Node));
    n8 = (struct Node*)malloc(sizeof(struct Node));
    n9 = (struct Node*)malloc(sizeof(struct Node));
    n10 = (struct Node*)malloc(sizeof(struct Node));

    n1->data = 5;
    n1->next = n2;
    
    n2->data = 2;
    n2->next = n3;

    n3->data = 8;
    n3->next = n4;

    n4->data = 11;
    n4->next = n5;

    n5->data = 4;
    n5->next = n6;

    n6->data = 7;
    n6->next = n7;

    n7->data = 6;
    n7->next = n8;

    n8->data = 1;
    n8->next = n9;

    n9->data = 3;
    n9->next = n10;

    n10->data = 2;
    n10->next = NULL;

    
    struct Node* sorted = NULL;
    sorted = (struct Node*)malloc(sizeof(struct Node));
    sorted = sortList(n1);
    printf("sorted");
    printList(sorted);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    free(n7);
    free(n8);
    free(n9);
    free(n10);
    free(sorted); 


    return 0;
}
