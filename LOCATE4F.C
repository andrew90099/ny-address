
/*
locate4fc  Takes in a address number and finds the nearest side street
By............. Andrew Messer
Last Update.... Nov 23, 1992
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ARRAY_ADJUSTMENT -1;    /* Matches users table with array table */

struct
{
	char avenue_name[25];
	int key_number;
} data_list[30];

/* Function find_address changes street address to nearest side street
aveune  is the aveune which contains the address
streetnum
*/
void interactive_mode(void);
void find_address(float house_num, int aveune_index);
void help_table(void);
void error_mess1(void);
void error_mess2(void);
int load_table(void);
void help_table2(void);

int size=0;

int main(int argc, char *argv[])
{

	float house_num;
	int aveune_index;       /* match index data structure with user input */
	int record_size;        /* number records in data base */

	size = load_table();

	if(argc > 1)         /* If the user entered data at the comand line */
	{
		if(*argv[1]=='?')  /* If the user wants help show the look up table */
		{
		help_table();
		printf("\nThe correct usage for locate3 [aveune] [house number]\n");
		exit(0);           /* no errors entered */
		}
		record_size = 1 + size;
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

			record_size = 1 + size;
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
	printf(" \n" );
	help_table2();
}
void help_table2(void)
{
	int record_size;
	int count;
/*   record_size = ( sizeof( data_list)/sizeof( LIST)  ); */
	 record_size = 1 + size;
	printf("           PRESS THE NUMBER OF THE AVENUE YOU WANT         \n" );
	for( count= 0; count < record_size; count++)
	{
	printf("[%d] %s  %d  ",
	count+1, data_list[count].avenue_name, data_list[count].key_number);
 /* printf("%d    %s     \n  ",
	 count+1, data_list[count].avenue_name); */

	}

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
			printf("%s %d",data_list[12].avenue_name, data_list[12].key_number);
}

int load_table(void)
{
	FILE  *fp;
	int counter;   /* data table counter */
	int dc;
	if((fp = fopen( "table.dat", "r" )) == NULL)
	{
		printf(" Avenue table not found\n please make sure");
		printf(" that table.dat in the same directory");
		exit(5);  /* Exit program due to missing data table */
	}
	for(counter = 0;  ;  counter++)
	{
	dc= fscanf( fp, "%25s%3d\n", data_list[counter].avenue_name,
	&data_list[counter].key_number);
	  if(dc !=2)
		{

		if(dc == EOF )
		{
		break;
		}
	   printf("Warning: the last record read was incomplete. \n");
	   }
	/* fflush(fp); */
	}

   fclose(fp);
	 return( counter);
}
