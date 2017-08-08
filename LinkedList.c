#include <stdio.h>
#include <stdlib.h>

struct node
{
 int data;
 struct node* link;
};

struct node* root=NULL;
//root=(struct node*)malloc(sizeof(struct node));

//--------------------------------------------------------
void append() //function to append a element at the end of linked list
{
 struct node* temp;
 temp=(struct node*)malloc(sizeof(struct node));
 printf("enter node data:");
 scanf("%d", &temp->data);
 temp->link=NULL;
  if (root == NULL)
  {
   root=temp;   //for the first element in linked list.
  }
  else
  {
   struct node* p;
   p= root;
   while (p->link!=NULL)//to insert at the end of linked list.
   {
    p=p->link;
   }
   p->link=temp;
  }
}
//----------------------------------------------------------
int lenght() // counting the number of elements in the list
{
 int count=0;
 struct node* temp;
 temp=root;
  while(temp!=NULL)
  {
   count++;
   temp = temp->link;
  }
 return count;
}
//----------------------------------------------------------
void addatbegin()
{
 struct node* temp;
 temp=(struct node*)malloc(sizeof(struct node));
 printf("Enter the node data:");
 scanf("%d",&temp->data);
 temp->link=NULL;
   if(root==NULL)
   {
     root=temp;
   }
   else
   {
     temp->link= root;//right side connection first for replacing the address
     root=temp;//left side connection second for entering the data..if you do this first you loose the whole data in linked list
   }
 
}
//----------------------------------------------------------
void display()//for printing the final Linklist
{
    struct node *temp;
    temp=root;
    while(temp!=NULL)
    {
    printf("  %d  ",temp->data);
    temp=temp->link;
    }
}
//----------------------------------------------------------
int main()
{
 int a,b,i,c;
 printf("Welcome to Linked List \n");
 printf("How many elements you wish to enter: \n");
 scanf("%d",&b);  //taking elements for the linked list
  for(i=1;i<=b;i++)
   {
     append();  //entering the elements at the end of list
   }
 printf("Do you wanna enter more elements? Yes(1)/No(0)");
 scanf("%d",&a);
   if(a==1)
    {
     // append(); for entering a new element at the end/into the list
      printf("Where would you like to enter the element in the Linked List: \n");
      printf("1.At the Begining \n");
      printf("2.At the End \n");
      scanf("%d",&c);
      switch(c)
      {
      case 1: addatbegin();
              display();
              break;
      case 2: append();
              display();
              break;
    /**  case 3: append()
              display();
              break;  
    **/
      }
    }
   else
    {
      printf("Thankyou for using Linked list \n");
      printf("Display the Linked list: \n");
      display();
    }
}
