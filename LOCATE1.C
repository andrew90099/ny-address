/*
locate1.c  Takes in a address number and finds the nearest side street
By............. Andrew Messer
Last Update.... Oct 13, 1992
*/
#include <stdio.h>
#include <string.h>
#include <time.h>

/* The getrandom mac uses time.h to seed a real random number generator */

#define getrandom(min, max) ((rand() % (int)(((max)+1)-(min)))+(min))

/* Function convt changes street address to nearest side street
aveune  is the aveune which contains the address
streetnum
*/
void convt(int aveune, int streetnum, float streetf);
main()
{
	float streetf;
	int aveune, street, count;
	srand( (unsigned)time(NULL) );

	for(count=0; count <= 3; count++)      /* loop to pick 4 streets */
	{

		aveune=getrandom(1,4);        /* pick any # from 1 to 4 */
		streetf=getrandom(1,2000);    /* pick any # from 1 to 2000 */
		street=streetf/10;            /* kill last figure  */
		convt(aveune,street, streetf);
	}

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


	}

}
