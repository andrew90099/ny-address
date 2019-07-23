/*
locate1.c  Takes in a address number and finds the nearest side street
By............. Andrew Messer
Last Update.... Oct 14, 1992
*/
#include <stdio.h>
#include <string.h>

/* Function convt changes street address to nearest side street
aveune  is the aveune which contains the address
streetnum
*/
void convt(int aveune, int streetnum, float streetf);
void display(void);
main()
{
	float streetf;
	int aveune, street, count;
		display();
		printf("Enter the aveune of the address\n");
		scanf("%d", &aveune);
		printf("Now Enter the address number\n");
		scanf("%f", &streetf);
		street=streetf/10;       /* kill last figure by converson float-int  */
		convt(aveune,street, streetf);

}

void convt(int aveune, int streetnum, float streetf)
{
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
			if(streetf <= 108)
			{
				printf("%4.0f 5th Avenue is closest to %dth Street \n",
				streetf, (streetnum/2) + 11);
			}
			if(streetf <= 200 && streetf > 108)
			{
				printf("%4.0f 5th Avenue is closest to %dth Street \n",
				streetf, (streetnum/2) + 13);
			}
			if(streetf <= 400 && streetf > 200)
			{
				printf("%4.0f 5th Avenue is closest to %dth Street \n",
				streetf, (streetnum/2) + 16);
			}
			if(streetf <= 600 && streetf > 400)
			{
				printf("%4.0f 5th Avenue is closest to %dth Street \n",
				streetf, (streetnum/2) + 18);
			}
			if(streetf <= 775 && streetf > 600)
			{
				printf("%4.0f 5th Avenue is closest to %dth Street \n",
				streetf, (streetnum/2) + 20);
			}
			if(streetf <= 1286 && streetf > 775)
			{
				printf("%4.0f 5th Avenue is closest to %dth Street \n",
				streetf, streetnum - 18);
			}
			if(streetf <= 1494 && streetf > 1286)
			{
				printf("%4.0f 5th Avenue is closest to %dth Street \n",
				streetf, (streetnum/2) + 20);
			}

			break;

		case 6:
			printf("%4.0f 6th Avenue of the Americas is closest to %dth Street \n",
			streetf, (streetnum/2) - 12);
			break;


		case 7:
			if(streetf <= 1800)
			{
			printf("%4.0f 7th Avenue is closest to %dth Street\n",
			streetf, (streetnum/2) + 12);
			}
			if(streetf >1800)
			{
			printf("%4.0f 7th Avenue is closest to %dth Street\n",
			streetf, (streetnum/2) + 20);
			}
			break;

		case 8:
			printf("%4.0f 8th Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 9);
			break;

		case 9:
			printf("%4.0f 9th Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 13);
			break;

		case 10:
			printf("%4.0f 10th Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 14);
			break;

		case 11:
			printf("%4.0f 11th Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 15);
			break;

		case 12:
			printf("%4.0f Avenue A is closest to %dth Street \n",
			streetf, (streetnum/2) + 3);
			break;

		case 13:
			printf("%4.0f Avenue B is closest to %dth Street \n",
			streetf, (streetnum/2) + 3);
			break;

		case 14:
			printf("%4.0f Avenue C is closest to %dth Street \n",
			streetf, (streetnum/2) + 3);
			break;

		case 15:
			printf("%4.0f Avenue D is closest to %dth Street \n",
			streetf, (streetnum/2) + 3);
			break;

		case 16:
			printf("%4.0f Amsterdam Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 59);
			break;

		case 17:
			printf("%4.0f 9th Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 13);
			break;

		case 18:
			printf("%4.0f Audubon Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 165);
			break;

		case 19:
			if(streetf <=753)
			{
			printf("This is a street name \n");
			printf("%4.0f Broadway is closest to %dth Street \n",
			streetf, (streetnum/2) -29);
			}
			if(streetf >753 &&  streetf <= 846)
			{
			printf("%4.0f Broadway is closest to %dth Street \n",
			streetf, (streetnum/2) - 29);
			}
			if(streetf >846 &&  streetf <= 953)
			{
			printf("%4.0f Broadway is closest to %dth Street \n",
			streetf, (streetnum/2) - 25);
			}
			if(streetf >953 )
			{
			printf("%4.0f Broadway is closest to %dth Street \n",
			streetf, (streetnum/2) - 31);
			}
		  break;

		case 20:
			printf("%4.0f Lexington Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 22);
			break;

		case 21:
			printf("%4.0f Park Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 34);
			break;

		case 22:
			printf("%4.0f Park Avenue South is closest to %dth Street \n",
			streetf, (streetnum/2) + 8);
			break;

		case 23:
			printf("%4.0f Madison Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 27);
			break;

		case 24:
			printf("%4.0f West Avenue is closest to %dth Street \n",
			streetf, (streetnum/2) + 59);
			break;


	}

}

void display(void)
{

	printf("º AVENUE of ADDRESS  press #   º   AVENUE of ADDRESS  press # º\n" );
	printf("º                              º                              º\n" );
	printf("º FIRST   AVENUE       1       º     AVENUE B           13    º\n" );
	printf("º SECOND  AVENUE       2       º     AVENUE C           14    º\n" );
	printf("º THIRD   AVENUE       3       º     AVENUE D           15    º\n" );
	printf("º FOURTH  AVENUE       4       º     AMSTERDAM AVENUE   16    º\n" );
	printf("º FIFTH   AVENUE       5       º     COLUMBUS  AVENUE   17    º\n" );
	printf("º SIXTH   AVENUE       6       º     AUBUBON   AVENUE   18    º\n" );
	printf("º SEVETH  AVENUE       7       º     BROADWAY           19    º\n" );
	printf("º EIXTH   AVENUE       8       º     LEXINGTON AVENUE   20    º\n" );
	printf("º NINTH   AVENUE       9       º     PARK AVENUE        21    º\n" );
	printf("º TENTH   AVENUE       10      º     PARK AVENUE SO.    22    º\n" );
	printf("º 11TH    AVENUE       11      º     MADISON   AVENUE   23    º\n" );
	printf("º AVENUE  A            12      º     WEST END  AVENUE   24    º\n" );
	printf("º                              º                              º\n" );
}
