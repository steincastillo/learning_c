/*
 * clab
 * 
 * Copyright 2016 Stein Castillo <stein_castillo@yahoo.com>
 *  
 * 
 */


#include <stdio.h>

//define data structures
struct variables
{
	int integer;
	float decimal;
	char character;
};

//function definition
int addition (int a, int b){
	//declare and initialize local variables
	int sum;
	sum = a + b;
	return sum;
}

//void function definition
void salute(){
	printf("I salute you\n");
}

int main()
{
	int i = -1;
	int input =-1;
	
	printf("value of i: %d\n", i);
	i++;
	printf("value of i: %d\n", i);
	i=i+1;
	printf("value of i: %d\n", i);
	
	//for loop sample
	for (i=0; i<10; i++)
	{
		printf("Counter: %d\n", i);
	}
	
	//while loop sample
	while(input !=0)
	{
		printf("Enteran integer. (0: exit):");
		scanf("%d,", &input);
		printf("Number: %d\n", input);
	}
	
	//Data Structures
	//Declare a structure of type variables
	struct variables var;
	
	//initialize struct var
	var.integer = 2;
	var.decimal = 2.5;
	var.character = 'a';
	
	//print structure values
	printf("Structure integer: %d\n", var.integer);
	printf("Structure float: %f\n", var.decimal);
	printf("Structure character: %c\n", var.character);
	
	//calling a function
	var.integer = addition(3,4);
	printf("Addition function: %d\n", var.integer);
	salute();
	
	
	return 0;
}

