/*4.0 Build a linked list for n number of data (connect n number of data using pointer) */
//Code :
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

void input (int value);
struct node* head;
int main()
{
    head=NULL;
    int n,searchnum;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++){
        int num;
        printf("Enter the number : ");
        scanf("%d",&num);
        input(num);
    }
    return 0;
}
void input (int value){
    struct node* temp=(struct node*) malloc(sizeof(struct node));
    temp->data=value;
    if(head==NULL){
        head=temp;

    }
    else{
        struct node* test;
        test=head;
        while(test->next!=NULL){
            test=test->next;
        }
        test->next=temp;
}
    temp->next=NULL;
}
