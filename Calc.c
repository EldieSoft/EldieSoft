/*Basic Command Line Calculator built in C
 *
 *Pick a number between 1 and 3, and the magical computer box will do the coresponding operation.
 *
 *1 = add/sub, 2 = mul/div, 3 = exponent
 *
 * Big Bosco 2/13/24
 *
 * Version 1.2
 * 
*/ 

#include <stdio.h>
#include <stdlib.h>

int get_operation_type()//function to get operation
{
	int operation;
	printf("What is your operation?\n1: ADD/SUB\t 2: MULT/DIV\t 3: EXP\t 0: CLOSE\n");
	scanf("%d", &operation);
	return operation;
}

//mathematical functions
float add(float num1, float num2)//function to add two numbers
{
	printf("%.2f + %.2f = ", num1, num2);
	return num1 + num2;	
}
float sub(float num1, float num2)//function to subtract one number from another
{
	printf("%.2f - %.2f = ", num1, num2);
	return num1 - num2;
}
float divide(float num1, float num2)//doesn't follow the theme, but 'div' is already a function name in stdlib.h
{//also, function to divide 2 numbers
	printf("%.2f / %.2f = ", num1, num2);
	return num1 / num2;
}
float mul(float num1, float num2)//function to multiply 2 numbers
{
	printf("%.2f * %.2f = ", num1, num2);
	return num1 * num2;
}
float expon(float num, int times)//function to exponent?
{
	float e = 1.0; int i;
	printf("%.2f to the power of %d = ", num, times);
	for (i = 0; i < times; i++)
	{
		e *= num;
	}
	return e;
}

//finding operation functions, (as in add vs sub, mult vs divide etc.)
float add_or_sub()
{
	float num1, num2, end_prod; int choice;
	printf("Pick two numbers:\n");
	scanf("%f%f",&num1,&num2);
	printf("ADD or SUB? (1 for ADD, 2 for SUB)\n");
	scanf("%d",&choice);
	switch (choice)
	{
		case 1:
			end_prod = add(num1, num2);
			break;
		case 2:
			end_prod = sub(num1, num2);
			break;
		default:
			printf("ERROR\n");
			end_prod = 0;
			break;
	}
	return end_prod;
}
float mul_or_div()
{
	float num1, num2, end_prod; int choice;
	printf("Pick two numbers\n");
	scanf("%f%f", &num1, &num2);
	printf("MUL or DIV? (1 for MUL, 2 for DIV)\n");
	scanf("%d", &choice);
	switch (choice)
	{
		case 1:
			end_prod = mul(num1, num2);
			break;
		case 2:
			end_prod = divide(num1, num2);
			break;
		default:
			printf("ERROR\n");
			end_prod = 0;
			break;
	}
	return end_prod;
}
float exponent_mayhem()
{
	float num, end_prod; int times;
	printf("Pick a number\n");
	scanf("%f", &num);
	printf("%.2f to the power of what?\n", num);
	scanf("%d", &times);
	end_prod = expon(num, times);
}

int main()
{
	system("clear");
	int opp; float numberino;
	opp = (int)get_operation_type();
	printf("%d\n" ,opp);
	while (opp != 0)
	{
		switch (opp)
		{
			case 1:
				numberino = add_or_sub();
				break;
			case 2:
				numberino = mul_or_div();
				break;
			case 3:
				numberino = exponent_mayhem();
				break;
			default:
				printf("ERROR\n");
				numberino = 0;
				break;
		}
		printf("%.2f\n", numberino);
		opp = (int)get_operation_type();
	}
	printf("Goodbye\n");
	return 0;
}
