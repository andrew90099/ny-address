/*
locate3.c  Takes in a address number and finds the nearest side street
By............. Andrew Messer
Last Update.... Nov 11, 1992
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ARRAY_ADJUSTMENT -1;    /* Matches users table with array table */

typedef struct
{
	char avenue_name[25];
	int key_number;
} LIST;

/* Function convt changes street address to nearest side street
aveune  is the aveune which contains the address
streetnum
*/
void convt(float house_num, int aveune_index);
void display(void);
void error_mess1(void);
void error_mess2(void);

	LIST data_list[] =
		{
			{"First Avenue",      3},
			{"Second Avenue",     3},
			{"Third Avenue",     10},
			{"Forth Avenue",      8},
			{"Sixth Avenue",    -12},
			{"Eight Avenue",      9},
			{"Ninth Avenue",     13},
			{"Tenth Avenue",     14},
			{"Eleventh Avenue",  15},
			{"Avenue A",          3},
			{"Avenue B",          3},
			{"Avenue C",          3},
			{"Avenue D",          3},
			{"Amsterdam Avenue", 59},
			{"Columbus Avenue",  60},
			{"Audubon Ave",     165},
			{"Lexington Avenue", 22},
			{"Park Avenue",      34},
			{"Park Avenue South", 8},
			{"Madison Avenue",   27},
			{"West Avenue",      59},
			};


int main(int argc, char *argv[])
{

	float house_num;
	char ch;                 /* User contral exiting of program */
	int aveune_index;       /* match index data structure with user input */
	int  error_flag1= 0;    /* Error flag  for data entry set at no error */

	if(argc > 1)         /* If the user entered data at the comand line */
	{
		if(*argv[1]=='?')  /* If the user wants help show the look up table */
		{
		display();
		printf("\nThe correct usage for locate3 [aveune] [house number]\n");
		exit(0);           /* no errors entered */
		}
		if(argc > 3)       /* catch wrong number of agruments */
		{
			error_mess1();
			exit(1);    /* error at command line */
		}
		aveune_index = ( atoi( argv[1] ) );  /* Get the avenue data */
		house_num = ( atof( argv[2] ) );  /* Get the house number data */
		convt(house_num,  aveune_index);


		exit(0);      /* No errors entered */

	}



		do                  /* program loop ends when user types q or Q*/
		{
		display();          /* look up help table for data entry */
		do                 /* data entry do loop to catch for errors */
		{
		if(error_flag1 == 1)          /* Catches wrong Aveune data */
		{
			error_mess2();
		}


		printf("Enter the aveune of the address\n");
		scanf("%d", &aveune_index);          /* int value of aveune */
		printf("Now Enter the house number\n");
		scanf("%f", &house_num);          /* floating point value of house # */
		error_flag1= 1;    /* set error flag if loop is run twice */
		}while( ! (aveune_index >= 0 && aveune_index < 21));   /* check for valid data */
		error_flag1 = 0;   /* reset error flag to no error */

convt(house_num,  aveune_index);

		printf("\nPRESS ANY KEY TO GO ON OR Q TO QUIT--->\n ");
		ch = getch();       /* Answer from the user */
		ch= tolower(ch);    /* Puts everthing into lower case */
		}while(ch != 'q');      /* program ends is user type a q */


		return(0);

}

void convt(float house_num, int aveune_index)
{
int streetnum;
	aveune_index = aveune_index + ARRAY_ADJUSTMENT;
	streetnum=house_num/10; /* kill last figure by type converson float->int */
	printf("%4.0f %s is closest to ",house_num,
	data_list[aveune_index].avenue_name);
	printf("%dth street \n",
	((streetnum/2)+ data_list[aveune_index].key_number));


}
/*         THIS FUNCTION DISPLAYS A LOOK UP TABLE FOR DATA ENTRY */
void display(void)
{

	printf("           PRESS THE NUMBER OF THE AVENUE YOU WANT             \n" );
	printf("                                                               \n" );
	printf("  FIRST   AVENUE       1             AVENUE B           11     \n" );
	printf("  SECOND  AVENUE       2             AVENUE C           12     \n" );
	printf("  THIRD   AVENUE       3             AVENUE D           13     \n" );
	printf("  FOURTH  AVENUE       4             AMSTERDAM AVENUE   14     \n" );
	printf("  SIXTH   AVENUE       5             COLUMBUS  AVENUE   15     \n" );
	printf("  EIGHT   AVENUE       6             AUBUBON   AVENUE   16     \n" );
	printf("  NINTH   AVENUE       7             LEXINGTON AVENUE   17     \n" );
	printf("  TENTH   AVENUE       8             PARK AVENUE        18     \n" );
	printf("  11TH    AVENUE       9             PARK AVENUE SO.    19     \n" );
	printf("  AVENUE  A           10             MADISON   AVENUE   20     \n" );
	printf("                   WEST END  AVENUE   21                       \n" );
	printf("                                                               \n" );
}


void error_mess1(void)
{
			printf("Wrong number of command line data items\n");
			printf("The correct usage for locate3 [aveune] [house number]\n");
			printf("If you need more help type in locate3 [?] \n");
			printf("Or you may just type locate3 for interactive program\n");

}

void error_mess2(void)
{
			printf("You entered the wrong aveune data\n");
			printf("Please look at the help table\n");
			display();
}
