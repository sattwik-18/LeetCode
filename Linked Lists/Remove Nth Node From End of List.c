/*
LeetCode #19 - Remove Nth Node From End of List

Topic: Linked List, Two Pointers

Approach:
- Create a dummy node before the head
- Move the fast pointer n+1 steps ahead
- Move both slow and fast pointers together
- When fast reaches the end, slow points to the node before the target
- Remove the target node by updating links

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
};
struct node* removeNthFromEnd(struct node* head, int n) {
  struct node dummy;
  dummy.next=head;  
  struct node *slow=&dummy;
    struct node *fast=&dummy;
    for(int i=0;i<=n;i++){
      fast=fast->next;
    }
    while(fast!=NULL){
      slow=slow->next;
      fast=fast->next;
    }
    slow->next=slow->next->next;
    return dummy.next;
}
int main(){
  struct node *head=NULL, *temp=NULL, *newnode=NULL;
  int n;
  printf("Enter size of list:");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter element %d: ",i+1);
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL){
      head=newnode;
      temp=newnode;
    }
    else{
      temp->next=newnode;
      temp=newnode;
    }
  }
  int r;
  printf("Enter index from last to remove:");
  scanf("%d",&r);
  struct node *res = removeNthFromEnd(head,r);
  temp=res;
  while(temp!=NULL){
    printf("%d\n",temp->data);
    temp=temp->next;
  }
}
