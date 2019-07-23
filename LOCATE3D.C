/*
locate3.c  Takes in a address number and finds the nearest side street
By............. Andrew Messer
Last Update.... Nov 2, 1992
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



/* Function convt changes street address to nearest side street
aveune  is the aveune which contains the address
streetnum
*/
void convt(int aveune, int streetnum, float streetf);
void display(void);




int main(int argc, char *argv[])
{
	float streetf;          /* The house number  */
	char ch;                /* User contral exiting of program */
	int aveune;             /* The aveune vaule */
	int street;             /* House number minus one last # */
	int  error_flag1= 0;    /* Error flag  for data entry set at no error */

	if(argc > 1)         /* If the user entered data at the comand line */
	{
		if(*argv[1]=='?')  /* If the user wants help show the look up table */
		{
		display();
		printf("\nThe correct usage:   locate3 [aveune] [house number]\n");
		exit(0);           /* no errors entered */
		}
		if(argc > 3)
		{
			printf("Wrong number of command line data items\n");
			printf("The correct usage for locate3 [aveune] [house number]\n");
			printf("If you need more help type in locate3 [?] \n");
			printf("Or you may just type locate3 for interactive program\n");
		exit(1);    /* error at command line */
		}
		aveune = ( atoi( argv[1] ) );  /* Get the avenue data */
		streetf = ( atof( argv[2] ) );  /* Get the house number data */
		street=streetf/10; /* kill last figure by type converson float->int */
		convt(aveune,street, streetf);   /* parameters to passed to convt */

		exit(0);      /* No errors entered */

	}



		do                  /* program loop ends when user types q or Q*/
		{
		display();          /* look up help table for data entry */
		do                 /* data entry do loop to catch for errors */
		{
		if(error_flag1 == 1)          /* Catches wrong Aveune data */
		{
			printf("You entered the wrong aveune data\n");
			printf("Please look at the help table\n");
			display();
		}


		printf("Enter the aveune of the address\n");
		scanf("%d", &aveune);                      /* int value of aveune */
		printf("Now Enter the house number\n");
		scanf("%f", &streetf);          /* floating point value of house # */
		error_flag1= 1;    /* set error flag if loop is run twice */
		}while( ! (aveune > 0 && aveune < 22));   /* check for valid data */
		error_flag1 = 0;   /* reset error flag to no error */
		street=streetf/10; /* kill last figure by type converson float->int */
		convt(aveune,street, streetf);   /* parameters to passed to convt */




		printf("\nPRESS ANY KEY TO GO ON OR Q TO QUIT--->\n ");

		scanf("%s", &ch);       /* Answer from the user */
		ch= tolower(ch);    /* Puts everthing into lower case */
		}while(ch != 'q');      /* program ends is user type a q */


		return(0);           /* A happy return - no errors encounted*/

}

void convt(int aveune, int streetnum, float streetf)
{
	/* This switch find which aveune to process  */
	switch(aveune)
	{

		case 1:
			printf("%4.0f 1st Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 3);
			break;

		case 2:
			printf("%4.0f 2nd Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 3);
			break;


		case 3:
			printf("%4.0f 3rd Avenue is closest to %dth Street\n",
			streetf, (streetnum/2) + 10);
			break;


		case 4:
			printf("%4.0f 4th Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 8);
			break;

		case 5:
		printf("%4.0f 6th Avenue of the Americas is closest to %dth Street \n",
		streetf, (streetnum/2) - 12);
		break;



		case 6:
			printf("%4.0f 8th Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 9);
			break;

		case 7:
			printf("%4.0f 9th Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 13);
			break;

		case 8:
			printf("%4.0f 10th Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 14);
			break;

		case 9:
			printf("%4.0f 11th Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 15);
			break;

		case 10:
			printf("%4.0f Avenue A is closest to %dth Street \n",
			streetf, (streetnum/2) + 3);
			break;

		case 11:
			printf("%4.0f Avenue B is closest to %dth Street \n",
			streetf, (streetnum/2) + 3);
			break;

		case 12:
			printf("%4.0f Avenue C is closest to %dth Street \n",
			streetf, (streetnum/2) + 3);
			break;

		case 13:
			printf("%4.0f Avenue D is closest to %dth Street \n",
			streetf, (streetnum/2) + 3);
			break;

		case 14:
			printf("%4.0f Amsterdam Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 59);
			break;

		case 15:
			printf("%4.0f 9th Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 13);
			break;

		case 16:
			printf("%4.0f Audubon Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 165);
			break;

		case 17:
			printf("%4.0f Lexington Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 22);
			break;

		case 18:
			printf("%4.0f Park Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 34);
			break;

		case 19:
			printf("%4.0f Park Avenue South is closest to %dth Street \n",
			streetf, (streetnum/2) + 8);
			break;

		case 20:
			printf("%4.0f Madison Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 27);
			break;

		case 21:
			printf("%4.0f West Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 59);
			break;
		default:
			printf("Error in data entry\nPlease use data in look up table\n");
			display();
			printf("CORRECT USAGE:   locate3 [aveune # or '?'] [house # ]\n");
			exit(1);             /* Error has occurred program ended */

	}

}
/*         THIS FUNCTION DISPLAYS A LOOK UP TABLE FOR DATA ENTRY */
void display(void)
{

printf("   SELECT THE CORRESPONDING NUMBER OF THE AVENUE YOU WANT \n" );
printf("                                                          \n" );
printf("  FIRST   AVENUE       1             AVENUE B           11\n" );
printf("  SECOND  AVENUE       2             AVENUE C           12\n" );
printf("  THIRD   AVENUE       3             AVENUE D           13\n" );
printf("  FOURTH  AVENUE       4             AMSTERDAM AVENUE   14\n" );
printf("  SIXTH   AVENUE       5             COLUMBUS  AVENUE   15\n" );
printf("  EIGHT   AVENUE       6             AUBUBON   AVENUE   16\n" );
printf("  NINTH   AVENUE       7             LEXINGTON AVENUE   17\n" );
printf("  TENTH   AVENUE       8             PARK      AVENUE   18\n" );
printf("  11TH    AVENUE       9             PARK AVENUE SO.    19\n" );
printf("  AVENUE  A           10             MADISON   AVENUE   20\n" );
printf("                   WEST END  AVENUE   21                  \n" );
printf("                                                          \n" );
}

