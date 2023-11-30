/*This is a fun piece of code that I made for my sister over Thanksgiving.
  When compiled, it takes an integer, called "interval," and makes the 
  robot dance that many times.                                          
  EldieSoft, Nov 29, 2023
*/
#include <stdio.h>

void dance_bot(int interval)
{
	int i,j;
	printf("Dance-Bot initiate:");
	for (i = 0; i < interval; i++)
	{
		for (j = 0; j <= 3; j++)
		{	
			printf("\n");
			printf("  |  \n");
			printf("[0_0]\n");
			if (j % 2 == 0)
			{
				printf("-[I]|\n");
			}
			else
			{
				printf("|[I]-\n");
			}
			printf(" | | \n");
		}
		printf("Dance Cycle: %d\n",(i + 1));
		
	}
	printf("Dance terminated: Dance-Bot power down.\n");
}

int main()
{
	int interval;
	printf("How many times must the robot dance?\n");
	scanf("%d",&interval);
	dance_bot(interval); //for debugging
	return 0;
}
