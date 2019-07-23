/*
locate1.c  Takes in a address number and finds the nearest side street
By............. Andrew Messer
Last Update.... Oct 19, 1992
*/
#include <stdio.h>
#include <string.h>
#include <dos.h>
#include <graph.h>
struct videoconfig vc;

#include <conio.h>
/* Function convt changes street address to nearest side street
aveune  is the aveune which contains the address
streetnum
*/
/*  ออออออออออออออออออออออ GOBAL ARRAY อออออออออออออออออออออออออออออ  */

char fill_3[] =  {0,32,0,0,0,2,0,0};                 /* 3% fill patteren */
char fill_6[] =  {32,0,2,0,128,0,8,0};               /* 6.25% fill patteren */
char fill_12[] = {32,2,128,8,32,2,128,8};           /* 12.5% fill patteren */
char fill_25[] = {68,17,68,17,68,17,68,17};         /* 25%   fill patteren */
char fill_37[] = {146,41,148,73,164,73,146,73};     /* 37.5% fill patteren */
char fill_50[] = {85,170,85,170,85,170,85,170};     /* 50%   fill patteren */
char fill_62[] = {109,214,107,182,91,182,109,182};  /* 62.5 fill patteren */
char fill_75[] = {187,238,187,238,187,238,187,238}; /* 75% fill patteren */
/* char fill_87[] = {255,128,128,128,255,4,4,4};  brick fill patteren */
char fill_87[] = {223,253,127,247,223,253,127,247}; /*  87.5% fill patteren */


/*  ออออออออออออออออออออออ GOBAL DECLARATIONS ออออออออออออออออออออออ  */
char ch;
float sx = 0, sy = 0;                     /* screen display coordinates */
float x_res = 0, y_res = 0 ;              /* dimensions of screen */
int C0 = 0, C1 = 1, C2 = 2, C3 = 3, C4 = 4, C5 = 5, C6 = 6, C7 =7, C8= 8,
C9 = 9, C10 = 10, C11 = 11, C12 = 12, C13 = 13, C14 = 14, C15 = 15,
mode_flag = 0;
float sx1=0, sy1 = 0, sx2 = 0, sy2 = 0;

/*  ออออออออออออออออออออออ FUNCTION PROTOTYPES ออออออออออออออออออออออ  */

void quit_pgm(void);
void graphics_setup(void);
void coords(void);
void convt(int aveune, int streetnum, float streetf);
void display(void);
void draw_border(int startx, int starty, int endx, int endy);
void goto_xy(int x, int y);
void cls(int row1, int col1, int row2, int col2 );
main()
{
	float streetf;
	int aveune, street, count;
	char ch;


graphics_setup();                         /* establish graphics mode */
_getvideoconfig(&vc);                     /* initialize video table */




	  /* cls(0, 0, 24, 79); */
		goto_xy(0,0);
		display();
_setcolor(C7); _setfillmask(fill_25);
sx = 0; sy = 24; coords(); sx1 = sx; sy1 = sy;
sx = 639; sy = 454; coords(); sx2 = sx; sy2 =sy;
_rectangle(_GFILLINTERIOR, sx1, sy1, sx2, sy2);     /*  DRAW BACKGROUND */

		do
		{
		draw_border(1, 17, 76, 23);
		goto_xy(3, 19);
		printf("Enter the aveune of the address: ");
		goto_xy(3, 20);
		scanf("%d", &aveune);
		goto_xy(40, 19);
		printf(" Now Enter the address number");
		goto_xy(43, 20);
		scanf("%f", &streetf);
		street=streetf/10;       /* kill last figure by converson float-int  */
		convt(aveune,street, streetf);
		goto_xy(20, 22);
		printf("PRESS ANY KEY TO GO ON OR Q TO QUIT");
		ch = getch();
		ch= tolower(ch);
		cls(17, 0, 24, 79);
		}while(ch != 'q');
		quit_pgm();                   /* end the program gracefully */
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
	printf("       ษออออออออออออออออออออออออออออออหออออออออออออออออออออออออออออออป\n");
	printf("       บ AVENUE of ADDRESS  press #   บ   AVENUE of ADDRESS  press # บ\n" );
	printf("       ฬออออออออออออออออออออออออออออออฮออออออออออออออออออออออออออออออน\n" );
	printf("       บ FIRST   AVENUE       1       บ     AVENUE B           13    บ\n" );
	printf("       บ SECOND  AVENUE       2       บ     AVENUE C           14    บ\n" );
	printf("       บ THIRD   AVENUE       3       บ     AVENUE D           15    บ\n" );
	printf("       บ FOURTH  AVENUE       4       บ     AMSTERDAM AVENUE   16    บ\n" );
	printf("       บ FIFTH   AVENUE       5       บ     COLUMBUS  AVENUE   17    บ\n" );
	printf("       บ SIXTH   AVENUE       6       บ     AUBUBON   AVENUE   18    บ\n" );
	printf("       บ SEVETH  AVENUE       7       บ     BROADWAY           19    บ\n" );
	printf("       บ EIXTH   AVENUE       8       บ     LEXINGTON AVENUE   20    บ\n" );
	printf("       บ NINTH   AVENUE       9       บ     PARK AVENUE        21    บ\n" );
	printf("       บ TENTH   AVENUE       10      บ     PARK AVENUE SO.    22    บ\n" );
	printf("       บ 11TH    AVENUE       11      บ     MADISON   AVENUE   23    บ\n" );
	printf("       บ AVENUE  A            12      บ     WEST END  AVENUE   24    บ\n" );
	printf("       บ                              บ                              บ\n" );
	printf("       ศออออออออออออออออออออออออออออออสออออออออออออออออออออออออออออออผ\n ");
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
  r.h.bh = 0;  /* blank line is black   3 is blue*/
  int86(0x10, &r, &r);
}

/* graphics pattern tool box  */


/*  ออออออออออออออออออออออออ MAIN ROUTINE อออออออออออออออออออออออออออ  */



/* _setfillmask(NULL); _setcolor(C0); */







/*  ออออออออออออออออออออออ  Sub: Exit Program  ออออออออออออออออออออออออ */

void quit_pgm(void)
{
	_clearscreen(_GCLEARSCREEN); _setvideomode(_DEFAULTMODE);
}

/*  ออออออออออออออออออออออ  Sub: Card compatibility ออออออออออออออออออออ */

void graphics_setup(void)
{
  VGA_mode:
  if (_setvideomode(_VRES16COLOR) == 0)  {goto EGA_ECD_mode;}
	else
	{
					 x_res = 640; y_res = 480; C0 = 0; C1 = 1; C2 = 2;
					 C3 = 3; C4 = 4; C5 = 5; C6 = 6; C7 =7; C8= 8; C9 = 9;
					 C10 = 10; C11 = 11; C12 = 12; C13 = 13; C14 = 14; C15 = 15;
					 mode_flag = 1;
					 _settextcolor(C3);
					 return;
	}

	EGA_ECD_mode:
	if (_setvideomode(_ERESCOLOR) == 0)  {goto EGA_SCD_mode;}
	else
	{
					 x_res = 640; y_res = 350; C0 = 0; C1 = 1; C2 = 2;
					 C3 = 3; C4 = 4; C5 = 5; C6 = 6; C7 =7; C8= 8; C9 = 9;
					 C10 = 10; C11 = 11; C12 = 12; C13 = 13; C14 = 14; C15 = 15;
					 mode_flag = 2;
					 _settextcolor(7); _settextposition(25,1);
					 _outtext("640x350 16 color EGA mode. ");
					 return;
	}

	EGA_SCD_mode:
	if (_setvideomode(_HRES16COLOR) == 0)  {goto CGA_mode;}
	else
	{
					 x_res = 640; y_res = 200; C0 = 0; C1 = 1; C2 = 2;
					 C3 = 3; C4 = 4; C5 = 5; C6 = 6; C7 =7; C8= 8; C9 = 9;
					 C10 = 10; C11 = 11; C12 = 12; C13 = 13; C14 = 14; C15 = 15;
					 mode_flag = 3;
					 _settextcolor(7); _settextposition(25,1);
					 _outtext("640x200 16 color EGA mode. ");
					 return;
	}

	CGA_mode:
	if (_setvideomode(_MRES4COLOR) == 0)  {goto abort_message;}
	else
	{
					 x_res = 320; y_res = 200; C0 = 0; C1 = 1; C2 = 2;
					 C3 = 3; C4 = 4; C5 = 5; C6 = 6; C7 =7; C8= 8; C9 = 9;
					 C10 = 10; C11 = 11; C12 = 12; C13 = 13; C14 = 14; C15 = 15;
					 mode_flag = 4;
					 _settextcolor(1); _settextposition(25,1);
					 _outtext("320x200 4 color CGA mode. ");
					 return;
	}

	abort_message:
	printf("\n\nUnable to proceed. \n");
	printf("Requires VGA or EGA or CGA adapter \n");
	printf("   With the appropriate monitor. \n");
	printf("Please refer to your user's guide. \n\n" );
	exit(0);
}

/*  ออออออออออออออออออออออ  Subroutine: coords() ออออออออออออออออออออ */

void coords(void)
{
	sx = sx*(x_res/640);
	sy = sy*(y_res/480);
	return;
}
/*  ออออออออออออออออออออออ End of Program!!!  ออออออออออออออออออออ */


