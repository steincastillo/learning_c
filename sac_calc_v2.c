/*
 * sac_calc.c
 * 
 * Copyright 2016 Stein Castillo <stein_castillo@yahoo.com>
 * 
 */

#include <stdio.h>
#define TRUE 1
#define ERR_MSG "Please enter a valid number...\n"



//
//Function prototypes
//
void printheader();
float get_data(char msg[]);

///////////////////////////////////
//
// MAIN LOOP
//
///////////////////////////////////

int main()
{
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
	
    /////////////
	//Get dive parameters
	/////////////
    
    dive.depth = get_data("Average depth [feet]: ");    //Average depth
    dive.time = get_data("Dive time [min]: ");          //Dive Time
    dive.psi = get_data("PSI used [PSI]: ");            //PSI Used
    dive.tsize = get_data("Tank size [cFt]: ");         //Tank Size
    dive.rpressure = get_data("Rated pressure [PSI]: ");//Rated Pressure
	
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
	printf("Total Gas: %3.1f [cFt]\n", sacr.tgas);
	printf("Absolute atmosphere [ATA]: %3.1f\n", sacr.ata);
	printf("Surface air consumption [SAC]: %3.1f [PSI/min]\n", sacr.sac);
	printf("Respiratory minute volume [RMV] %3.2f [cFt/min]\n", sacr.rmv);
    printf("\n");
    
	return 0;
}

/////////////////////////////////////
//
// FUNCTIONS
//
/////////////////////////////////////
void printheader(void)
{
	printf("*************************\n");
	printf("*                       *\n");
	printf("*  SAC RATE CALCULATOR  *\n");
	printf("*          v1.1         *\n");
	printf("*                       *\n");
	printf("*************************\n");

}

float get_data(char msg[35])
{
    float value = 0;
    char input[25];
    
    while (TRUE)
    {
        printf(msg);
        fgets (input, 25, stdin);
        if (sscanf (input, "%f", &value) == 1) break;
        printf (ERR_MSG);
    };
    return value;
}
        
