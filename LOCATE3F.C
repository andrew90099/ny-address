/*
locate3.c  Takes in a address number and finds the nearest side street
By............. Andrew Messer
Last Update.... Nov 11, 1992
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ARRAY_ADJUSTMENT -1;    /* Matches users table with array table */

typedef struct
{
	char avenue_name[25];
	int key_number;
} LIST;

/* Function find_address changes street address to nearest side street
aveune  is the aveune which contains the address
streetnum
*/
void interactive_mode(void);
void find_address(float house_num, int aveune_index);
void help_table(void);
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
			{"Lexington Avenue ", 22},
			{"Park Avenue",      34},
			{"Park Avenue South", 8},
			{"Madison Avenue",   27},
			{"West Avenue",      59},
			};


int main(int argc, char *argv[])
{
	float house_num;
	int aveune_index;       /* match index data structure with user input */
	int record_size;        /* number records in data base */

	if(argc > 1)         /* If the user entered data at the comand line */
	{
		if(*argv[1]=='?')  /* If the user wants help show the look up table */
		{
		help_table();
		printf("\nThe correct usage for locate3 [aveune] [house number]\n");
		exit(0);           /* no errors entered */
		}
		record_size = 1 + ( sizeof( data_list)/sizeof( LIST)  );
		if(argc > 3)       /* catch wrong number of agruments */
		{
			error_mess1();
			exit(1);    /* error at command line */
		}
		aveune_index = ( atoi( argv[1] ) );  /* Get the avenue data */
		house_num = ( atof( argv[2] ) );  /* Get the house number data */
		if( ! (aveune_index >= 0 && aveune_index < record_size))
		{
			error_mess2();
			exit(2);
		}
		find_address(house_num,  aveune_index);


		exit(0);      /* No errors entered */

	}

		interactive_mode();   /* Used only with no command line arguments */
		return(0);

}

void interactive_mode(void)
{
	float house_num;
	int aveune_index;       /* match index data structure with user input */
	int  error_flag1= 0;    /* Error flag  for data entry set at no error */
	int record_size;

			record_size = 1 + ( sizeof( data_list)/sizeof( LIST)  );
			help_table();          /* look up help table for data entry */

			/* To following do loop check for in valid aveune data */
			do
			{
				if(error_flag1 == 1)          /* Catches wrong Aveune data */
				 {
					 error_mess2();
				 }


				printf("Enter the aveune of the address\n");
				scanf("%d", &aveune_index);
				printf("Now Enter the house number\n");
				scanf("%f", &house_num);
				error_flag1= 1;     /* set error flag */
				/* loop until valid data is entered  */
			}while( ! (aveune_index >= 0 && aveune_index < record_size));
			error_flag1 = 0;   /* reset error flag to no error */

			find_address(house_num,  aveune_index);

}



void find_address(float house_num, int aveune_index)
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
void help_table(void)
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
			printf("You entered invalid aveune data\n");
			printf("Please look at the help table\n");
			help_table();
}

