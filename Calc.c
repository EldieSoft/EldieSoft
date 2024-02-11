/*Basic Calculator program for me to get back into C
 * Will clean up later, for now just a pet project
 *
 *Pick a number between 1 and 5, and the magical computer box will do the coresponding operation.
 *
 *1 = add, 2 = sub, 3 = mul, 4 = div, 5 = square
 *
 * Big Bosco 2/9/24
 *
 * Version 1.0.0
 * 
*/ 

#include <stdio.h>
#include <stdlib.h>

int get_operation()//function to get operation
{
	int operation;
	printf("What is your operation?\n1: ADD\t 2: SUB\t 3: MUL\t 4: DIV\t5: SQR\t 0: CLOSE\n");
	scanf("%d", &operation);
	return operation;
}
float add()//function to add two numbers
{
	float num1, num2;
	printf("What do you want to add?\n");
	scanf("%f%f", &num1, &num2);
	printf("Adding: %.2f and %.2f\n", num1, num2);
	return num1 + num2;	
}
float sub()//function to subtract one number from another
{
	float num1, num2;
	printf("What do you want to subtract?\n");
	scanf("%f%f", &num1, &num2);
	printf("Subtracting: %.2f and %.2f\n", num1, num2);
	return num1 - num2;
}
float divide()//doesn't follow the theme, but 'div' is already a function name in stdlib.h
{//also, function to divide 2 numbers
	float num1, num2;
	printf("What do you want to divide?\n");
	scanf("%f%f", &num1, &num2);
	printf("Dividing: %.2f and %.2f\n", num1, num2);
	return num1 / num2;
}
float mul()//function to multiply 2 numbers
{
	float num1, num2;
	printf("What do you want to multiply?\n");
	scanf("%f%f", &num1, &num2);
	printf("Multiplying: %.2f and %.2f\n", num1, num2);
	return num1 * num2;
}
float sqr()//function to square number
{
	float num;
	printf("What do you want to square?\n");
	scanf("%f",&num);
	printf("Squaring: %.2f\n",num);
	return num * num;
}
float cub()//function to cube number
{
	float num;
	printf("What do you want to cube?\n");
	scanf("%f",num);
	printf("Cubing: %.2f\n",num);
	return num * num * num;
}
 
int main()
{
	system("clear");
	int opp; float numberino;
	opp = (int)get_operation();
	printf("%d\n" ,opp);
	while (opp != 0)
	{
		switch (opp)
		{
			case 1:
				numberino = add();
				break;
			case 2:
				numberino = sub();
				break;
			case 3:
				numberino = mul();
				break;
			case 4:
				numberino = divide();
				break;
			case 5:
				numberino = sqr();
				break;
			default:
				printf("ERROR\n");
				numberino = 0;
				break;
		}
		printf("%.2f\n", numberino);
		opp = (int)get_operation();
	}
	printf("Goodbye\n");
	return 0;
}
