/*
 * sac_calc.c
 * 
 * Copyright 2016 Stein Castillo <stein_castillo@yahoo.com>
 * 
 *
 * 
 * 
 */

#include <stdio.h>

//Define data structures
struct parameters
{
	float depth;
	float time;
	float psi;
	float tsize;
	float rpressure;
};

struct SAC_P
{
	float tbase;
	float tgas;
	float ata;
	float psiminute;
	float sac;
	float rmv;
};

//Function prototypes
void printheader();

int main()
{
	//declare and initialize dive parameters
	struct parameters dive;
	dive.depth = 0;
	dive.time = 0;
	dive.psi = 0;
	dive.tsize = 0;
	dive.rpressure = 0;
	
	struct SAC_P sacr;
	sacr.tbase = 0;
	sacr.tgas = 0;
	sacr.ata = 0;
	sacr.psiminute = 0;
	sacr.sac = 0;
	sacr.rmv = 0;
	
	printheader();
	
	//get dive parameters
	printf("Average depth [feet]: ");
	scanf("%f", &dive.depth);
	printf("Dive time [min]: ");
	scanf("%f", &dive.time);
	printf("PSI used [PSI]: ");
	scanf("%f", &dive.psi);
	printf("Tanks size [cFt]: ");
	scanf("%f", &dive.tsize);
	printf("Rated pressure [PSI]: ");
	scanf("%f", &dive.rpressure);
	printf("Calculating... \n");
	
	//calculate results
	sacr.tbase = dive.tsize/dive.rpressure;	//Tanks baseline
	sacr.tgas = dive.psi*sacr.tbase;		//Total gas
	sacr.ata = (dive.depth/33)+1;			//Gas consumed
	sacr.psiminute = dive.psi/dive.time;	//Absolute atmosphere
	sacr.sac = sacr.psiminute/sacr.ata;		//Surface air consumption rate
	sacr.rmv = sacr.sac*sacr.tbase;			//Respiratory minute volume
	
	//print results
	printf("\n*** RESULTS ***\n");
	printf("Total Gas [cFt]: %3.1f\n", sacr.tgas);
	printf("Absolute atmosphere [ATA]: %3.1f\n", sacr.ata);
	printf("Surface air consumption [SAC]: %3.1f [PSI/min]\n", sacr.sac);
	printf("Respiratory minute volume [RMV] %3.2f, [cFt/min]\n", sacr.rmv);
			
	return 0;
}


void printheader()
{
	printf("*************************\n");
	printf("*                       *\n");
	printf("*  SAC RATE CALCULATOR  *\n");
	printf("*          v1.0         *\n");
	printf("*                       *\n");
	printf("*************************\n");

}
