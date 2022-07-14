#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int leap_year;
int start;
int mon=12;
int months=1;
struct node{

int space;
int days;
struct node* next;
};
struct node* head=NULL;


void insert_data(int x){
 struct node* newnode;


if(head==NULL)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    head=newnode;
    if(months==1||months==3||months==5||months==7||months==8||months==10||months==12)
    {
        newnode->days=31;
        newnode->space=x;
         months++;
    }


    if(months!=13)
    {
        return insert_data(newnode->space);
    }
    else{
        return 0;
    }




}
if(head!=NULL){

     newnode=(struct node*)malloc(sizeof(struct node));
     newnode->next=head;
     head=newnode;
     if(months==1||months==3||months==5||months==7||months==8||months==10||months==12)
    {
        newnode->days=31;
         newnode->space=x+(head->next->days-29)+1;
        months++;
        if(newnode->space>7)
        {
            newnode->space=newnode->space-7;
        }
        if(newnode->space==0)
        {
            newnode->space=x;
        }


    }
   else  if(months==4||months==6||months==9||months==11)
    {
        newnode->days=30;
        newnode->space=x+(head->next->days-29)+1;
        months++;
        if(newnode->space>=7)
        {
            newnode->space=newnode->space-7;
        }

    }
  else  if(months==2)
    {
        newnode->days=leap_year;
        if(leap_year==28)
        {
            newnode->space=x+(head->next->days-29)+1;
        }
        else{
            newnode->space=x+1;
        }


        months++;
        if(leap_year==29)
        {
            newnode->space=x+(head->next->days-leap_year)+1;
        }
        if(newnode->space>=7)
        {
            newnode->space=newnode->space-7;
        }


    }
    if(months!=13){


        return insert_data(newnode->space);
    }
    else{
        return 0;
    }

}

}
void display_cal(){

while(head!=NULL)
{
switch(mon){

case 1:
    printf("JANUARY\n");
    printf("------------------------------------------");
    printf("\n");
    break;
case 2:
    printf("FEBRUARY\n");
    printf("------------------------------------------");
    printf("\n");
    break;
case 3:
    printf("MARCH\n");
    printf("------------------------------------------");
    printf("\n");
    break;
case 4:
    printf("APRIL\n");
    printf("------------------------------------------");
    printf("\n");
    break;
case 5:
    printf("MAY\n");
    printf("------------------------------------------");
    printf("\n");
    break;
case 6:
    printf("JUNE\n");
    printf("------------------------------------------");
    printf("\n");
    break;
case 7:
    printf("JULY\n");
    printf("------------------------------------------");
    printf("\n");
    break;
case 8:
    printf("AUGUST\n");
    printf("------------------------------------------");
    printf("\n");
    break;
case 9:
    printf("SEPTEMBER\n");
    printf("------------------------------------------");
    printf("\n");
    break;
case 10:
    printf("OCTOBER\n");
    printf("------------------------------------------");
    printf("\n");
    break;
case 11:
    printf("NOVEMBER\n");
    printf("------------------------------------------");
    printf("\n");
    break;
case 12:
    printf("DECEMBER\n");
    printf("------------------------------------------");
    printf("\n");
    break;
default:
    printf("error");
    break;
}

    if(head->space==7)
    {
        head->space=0;
    }
    printf("MON\tTUE\tWED\tTHU\tFRI\tSAT\tSUN\n");
    for(int j=0;j<head->space;j++)
{
    printf("\t");
}

    for(int i=1;i<=head->days;i++)
    {head->space++;
    printf("%d\t",i);
        if(head->space==7)
        {
            printf("\n");
            head->space=0;
        }
    }

head=head->next;
   printf("\n\n");
mon--;
}

}

int main()
{int year;
  printf("enter the year");
  scanf("%d",&year);
   if((year%4==0)&&((year%400==0)||(year%100!=0)))
   {
        printf("%d is a leap year\n",year);
        leap_year=29;

   }
   else{

     printf("%d is not a leap year\n",year);
     leap_year=28;

   }


   printf("enter jan months start day mon-0,tue-1,wed-2,thu-3,fri-4,sat-5,sun-6 ");
   scanf("%d",&start);
   insert_data(start);
   printf("                %d  CALENDAR \n       ",year);
   printf("      WEEKS START ON MONDAY\n      ");
   display_cal();



}

