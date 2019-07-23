/*
locate1.c  Takes in a address number and finds the nearest side street
By............. Andrew Messer
Last Update.... Oct 22, 1992
*/
#include <stdio.h>
#include <string.h>
#include <dos.h>
#include <conio.h>
/* Function convt changes street address to nearest side street
aveune  is the aveune which contains the address
streetnum
*/
void convt(int aveune, int streetnum, float streetf);
void display(void);
void cursor_on(void);
void draw_border(int startx, int starty, int endx, int endy);
void goto_xy(int x, int y);
void cls(int row1, int col1, int row2, int col2 );
void command_line(void);
int main(int argc, char *argv[])
{
	float streetf;
	int aveune, street, count;
	 char ch;
	if(*argv[1]=='?')
	{
		command_line();
		cursor_on();        /* make sure that dam cusor is on */
		exit(2);

	}

		cls(0, 0, 24, 79);
		goto_xy(0,0);
		display();
		do
		{
		draw_border(1, 17, 76, 23);
		goto_xy(3, 19);
		printf("Enter the aveune : ");
		goto_xy(5, 20);
		printf("±±±±±±±±±±±±±");
		goto_xy(11, 20);
		scanf("%d", &aveune);
		goto_xy(40, 19);
		printf(" Now Enter the House number");
		goto_xy(44, 20);
		printf("±±±±±±±±±±±±±±");
		goto_xy(50, 20);
		scanf("%f", &streetf);
		street=streetf/10;       /* kill last figure by converson float-int  */
		convt(aveune,street, streetf);
		goto_xy(20, 22);
		printf("PRESS ANY KEY TO GO ON OR Q TO QUIT");
		ch = getch();
		ch= tolower(ch);
		cls(17, 0, 24, 79);
		}while(ch != 'q');
cls(0, 0, 24, 79);
goto_xy(0, 0);
cursor_on();        /* make sure that dam cusor is on */
return(1);
}

void convt(int aveune, int streetnum, float streetf)
{
	goto_xy(3, 21);
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
	printf("       ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍËÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»\n");
	printf("       º AVENUE of ADDRESS  press #   º   AVENUE of ADDRESS  press # º\n" );
	printf("       ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÎÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹\n" );
	printf("       º FIRST   AVENUE       1       º     AVENUE B           13    º\n" );
	printf("       º SECOND  AVENUE       2       º     AVENUE C           14    º\n" );
	printf("       º THIRD   AVENUE       3       º     AVENUE D           15    º\n" );
	printf("       º FOURTH  AVENUE       4       º     AMSTERDAM AVENUE   16    º\n" );
	printf("       º FIFTH   AVENUE       5       º     COLUMBUS  AVENUE   17    º\n" );
	printf("       º SIXTH   AVENUE       6       º     AUBUBON   AVENUE   18    º\n" );
	printf("       º SEVETH  AVENUE       7       º     BROADWAY           19    º\n" );
	printf("       º EIXTH   AVENUE       8       º     LEXINGTON AVENUE   20    º\n" );
	printf("       º NINTH   AVENUE       9       º     PARK AVENUE        21    º\n" );
	printf("       º TENTH   AVENUE       10      º     PARK AVENUE SO.    22    º\n" );
	printf("       º 11TH    AVENUE       11      º     MADISON   AVENUE   23    º\n" );
	printf("       º AVENUE  A            12      º     WEST END  AVENUE   24    º\n" );
	printf("       º                              º                              º\n" );
	printf("       ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÊÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼\n ");
}

/* Draw a border around the menu. */
void draw_border(int startx, int starty, int endx, int endy)
{
  register int i;

  /* draw vertical lines */
  for(i=starty+1; i<endy; i++) {
	  goto_xy(startx, i);
	  putchar(186);
	  goto_xy(endx, i);
	  putchar(186);
  }

  /* draw horizontal lines */
  for(i=startx+1; i<endx; i++) {
	 goto_xy(i, starty);
	 putchar(205);
	 goto_xy(i, endy);
	 putchar(205);
  }

  /* draw the corners */
  goto_xy(startx, starty); putchar(201);
  goto_xy(startx, endy); putchar(200);
  goto_xy(endx, starty); putchar(187);
  goto_xy(endx, endy); putchar(188);

}

void goto_xy(int x, int y)
{
  union REGS r;

  r.h.ah = 2; /* cursor addressing function */
  r.h.dl = x; /* column coordinate */
  r.h.dh = y; /* row coordinate */
  r.h.bh = 0; /* video page */
  int86(0x10, &r, &r);
}

void cls(int row1, int col1, int row2, int col2)
{
  union REGS r;

  r.h.ah = 6; /* screen scroll code */
  r.h.al = 0; /* clear screen code */
  r.h.ch = row1; /* start row */
  r.h.cl = col1; /* start column */
  r.h.dh = row2; /* end row */
  r.h.dl = col2; /* end column */
  r.h.bh = 0;  /* blank line is black */
  int86(0x10, &r, &r);
}

void command_line(void)
{
cls(0,0,24,79);
goto_xy(0,7);
printf("\n");
printf("            ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\n");
printf("            ²²²²²²²²²²²²²²²²²²²²²²LOCATE²²²²²²²²²²²²²²²²²²²²²²²\n");
printf("            ²²²²²²²²²²²²²²²²²²²²²²²²BY²²²²²²²²²²²²²²²²²²²²²²²²²\n");
printf("            ²²²²²²²²²²²²²²²²²²²ANDREW MESSER²²²²²²²²²²²²²²²²²²²\n");
printf("            ²²²²²²²²²²²²²²²²²OCT 19, 1992 1.5²²²²²²²²²²²²²²²²²²\n");
printf("            ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\n");

}

 /* Turn that dam cursor back on  */
void cursor_on(void)
{
union REGS r;
r.x.ax = 1;  /* show the cursor */
int86(0x33, &r, &r);
}
