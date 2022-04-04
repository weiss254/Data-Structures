/*

*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *link;
};

struct node *front,*rear;

void initializeQueue();
int isEmpty();
int size();
void insert(int x);
int delete();
int peek();
void display();

void main(){
  int choice,x;

  initializeQueue();

  while(1){
      printf("1.Insert an element in the queue \n");
      printf("2.Delete an item in the queue\n");
      printf("3.Show size of the queue \n");
      printf("4.Display items in the queue \n");
      printf("5.Top element in the queue \n");
      printf("6.Quit \n\n");

      printf("Enter your choice:: ");
      scanf("%d",&choice);
      printf("\n");

      if (choice==6)
        break;

        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted : \n");
            scanf("%d",&x);
            insert(x);
            break;
        case 2:
            x=delete();
            printf("Element deleted is : %d \n",x);
            break;
        case 3:
            printf("Size of the queue is %d \n",size());
            break;
        case 4:
            display();
            break;
        case 5:
            printf("The element at the front is: %d \n",peek());
            break;
        default:
            printf("Invalid option \n");
            break;
        }
        printf("\n");
  }  
    
}
void initializeQueue(){
    front==NULL;
    rear==NULL;
}
int isEmpty(){
    if(front==NULL){
        return 1;
    }
    return 0;
}

int peek(){
    if(isEmpty()){
        printf("Queue underflow \n");
        exit(1);
    }
    return front->info;
}
int size(){
    int s=0;
    if(isEmpty()){
        return 0;
    }
    struct node *p=front;
    while (p!=NULL)
    {
        s++;
        p=p->link;
    }
    return s;
    
}
void insert(int x){
    struct node *temp;
    temp=(struct node *) malloc (sizeof(struct node));
    if(temp==NULL){
        printf("Memory not available \n");
        return;
    }
    temp->info=x;
    temp->link=NULL;

    if(front==NULL)
        front=temp;
    else
        rear->link=temp;
    rear=temp;
   
}
int delete(){
    struct node *temp;
    int x;
    if(isEmpty()){
        printf("Queue underflow \n");
        exit(1);
    }
    temp=front;
    x=temp->info;
    front=front->link;
    free(temp);
    return x;
}
void display(){
    struct node *p;
    p=front;
    if(isEmpty()){
        printf("Queue is empty \n");
        return;
    }
    printf("Queue is : \n\n");
    while (p!=NULL)
    {
        printf("%d ",p->info);
        p=p->link;
    }
    printf("\n\n");
    
}
