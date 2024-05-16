Exercise - 6
/*DATE  :
  AUTHOR: */
  AIM   : Write a Program to implement Sliding window protocol for Selective repeat.

PROGRAM:

 #include<stdio.h>
#include<conio.h>
void main()
{
char sender[50],receiver[50];
int i,winsize;
printf("\n ENTER THE WINDOWS SIZE : ");
scanf("%d",&winsize);
 printf("\n SENDER WINDOW IS EXPANDED TO STORE MESSAGE OR WINDOW \n");
 printf("\n ENTER THE DATA TO BE SENT: ");
fflush(stdin);
gets(sender);
for(i=0;i<winsize;i++)
receiver[i]=sender[i];
receiver[i]=NULL;
 printf("\n MESSAGE SEND BY THE SENDER:\n");
 puts(sender);
 printf("\n WINDOW SIZE OF RECEIVER IS EXPANDED\n");
 printf("\n ACKNOWLEDGEMENT FROM RECEIVER \n");
for(i=0;i<winsize;i++);
printf("\n ACK:%d",i);
 printf("\n MESSAGE RECEIVED BY RECEIVER IS : ");
 puts(receiver);
 printf("\n WINDOW SIZE OF RECEIVER IS SHRINKED \n");
getch();
}

OUTPUT:

ENTER THE WINDOWS SIZE: 5
SENDER WINDOW IS EXPANDED TO STORE MESSAGE OR WINDOW
ENTER THE DATA TO BE SENT: hai
MESSAGE SEND BY THE SENDER: hai
WINDOW SIZE OF RECEIVER IS EXPANDED
ACKNOWLEDGEMENT FROM RECEIVER
ACK:5
MESSAGE RECEIVED BY RECEIVER IS: hai
WINDOW SIZE OF RECEIVER IS
