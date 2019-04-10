/* You are required to develop a program that will operate on an ATM machine for a
bank. Your program should allow bank customers to manage their PIN. The PIN is a
4-digit number.
Author: Emily Murphy
Date: 13/11/2016
Operating System: Mac OSX
Compiler: CodeBlocks
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

int main()

{
    char choice; // users choice from the menu
    int Wrong_PIN = 0; //used to count how many times pin was entered wrong
    int Right_PIN = 0; //used to count how many times pin was entered right
    int Pin[SIZE]={1,2,3,4};	//users default PIN
	int UsersPin_1[SIZE]={1,2,3,4}; //users entry for option 1
    int NewPIN[SIZE]; //users new pin
	int NewPIN2[SIZE]; //verifying users new pin
    int CounterDigits=0;//check if user entered correct pin in option 1
    int CounterDigits_2=0;// checks if the users input is right in option 2
    int c; //preventing character inputs

    do
    {

        //show menu
        printf("\n1.Enter PIN and verify correct \n");
        printf("2.Change PIN \n");
        printf("3.Display the number of times the PIN was entered (i) Successfully (ii) Incorrectly \n");
        printf("4.Exit Program \n");
        printf("Enter your choice\n");
        scanf("%c",&choice);

        while ((c = getchar()) != '\n' && c != '\n') { } //skips characters till newline



            if(choice=='1') //option one to enter pin and verify correct
            {
                printf("Enter your PIN: ");

                for(int i=0;i<SIZE;i++)
                {

                    scanf("%1d",&UsersPin_1[i]);//read in users input

                }//END FOR

                for(int i=0;i<SIZE;i++)
                {

                    if(Pin[i]==UsersPin_1[i])
                    {
                        CounterDigits++;
                    }//end if

                }//END for

                    if(CounterDigits==4)//check if its correct
                    {
                        getchar();
                        printf("Correct PIN\n");
                        Right_PIN++;
                    }
                    else
                    {
                        printf("Wrong PIN\n");
                        Wrong_PIN++;
                    }//end nested if else

            }//end if choice 1

            if(choice=='2') //option 2 to change pin and enter new pin again
            {
                printf("\n Enter New PIN: ");

                for(int i=0;i<SIZE;i++)//enters users input
                {
                    scanf("%1d",&NewPIN[i]);
                }//endfor

                printf("\n Enter New PIN again: ");

                for(int i=0;i<SIZE;i++)//enters user input again
                {
                    scanf("%1d",&NewPIN2[i]);
                }//endfor
                while ((c = getchar()) != '\n' && c != '\n') { }//skips characters till newline

                for(int i=0;i<SIZE;i++)
				{

					if(NewPIN[i]==NewPIN2[i])
					{
						CounterDigits_2++;
					}

				}//endfor

                    if(CounterDigits_2==4)//check if its correct

                    {

                        printf(" \nYour PIN has been changed successfully\n");

                        for(int i=0;i<SIZE;i++)
                        {
                            Pin[i]=NewPIN[i];
                        }

                    }
                    else
                    {
                        printf("\nInvalid input, Please choose again\n");
                    }//end if else

            } // end if choice 2


            if(choice=='3')//option three to check how many times pin was entered wrong/right
            {
                printf("\nYou entered your PIN successfully %d times\n",Right_PIN);
                printf("\nYou entered your PIN incorrectly %d times\n",Wrong_PIN);
            }//end if choice 3


            if(choice=='4') // option four to end program
            {
                return(0);//ends program
            }//end if choice 4

            CounterDigits=0;//resets the counter
            CounterDigits_2=0;//resets the counter

        }//end do
        while(choice==1||2||3||4);//loops until 4 is entered

}//end main
