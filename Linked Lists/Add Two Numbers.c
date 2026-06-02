/*
LeetCode #2 - Add Two Numbers

Topic: Linked List

Approach:
- Traverse both lists simultaneously
- Add corresponding digits with carry
- Create result list on the fly

Time Complexity: O(max(n,m))
Space Complexity: O(max(n,m))
*/

#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
};
struct node *add(struct node *l1,struct node *l2)
{
  struct node *head=NULL, *temp=NULL, *newnode=NULL;
  int sum,carry=0,digit;
  while(l1!=NULL || l2!=NULL || carry!=0)
  {
    sum=carry;
    if(l1!=NULL){
      sum=sum+l1->data;
      l1=l1->next;
    }
    if(l2!=NULL){
      sum=sum+l2->data;
      l2=l2->next;
    }
    digit=sum%10;
    carry=sum/10;

    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=digit;
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
  return head;
}
int main()
{
  struct node *head1 = NULL, *temp1 = NULL, *newnode1 = NULL;
  struct node *head2 = NULL, *temp2 = NULL, *newnode2 = NULL;
  int i,n1,n2;
  printf("Enter size of 1st linked list:");
  scanf("%d",&n1);
  for(i=0;i<n1;i++)
  {
    newnode1=(struct node *)malloc(sizeof(struct node));
    printf("Enter element %d:",i+1);
    scanf("%d",&newnode1->data);
    newnode1->next=NULL;
    if(head1==NULL)
    {
      head1=newnode1;
      temp1=newnode1;
    }
    else{
      temp1->next=newnode1;
      temp1=newnode1;
    }
  }
  printf("Enter size of 2nd linked list:");
  scanf("%d",&n2);
  for(i=0;i<n2;i++)
  {
    newnode2=(struct node *)malloc(sizeof(struct node));
    printf("Enter element %d:",i+1);
    scanf("%d",&newnode2->data);
    newnode2->next=NULL;
    if(head2==NULL)
    {
      head2=newnode2;
      temp2=newnode2;
    }
    else{
      temp2->next=newnode2;
      temp2=newnode2;
    }
  }
  struct node *result, *temp;
  result= add(head1,head2);
  temp=result;
  while(temp!=NULL){
    printf("%d\n",temp->data);
    temp=temp->next;
  }
  return 0;
}
