#include"Commodity.h"
#include<cstdlib>
void Commodity::consume()
{
	totalAmountInSystem-=amtCons;
}

void Commodity::produce(float quantity)
{
	totalAmountInSystem+=quantity;
}

static Commodity & Commodity::getCommNum(int num)
{
	return & theCommodities[num];
}

Commodity::Commodity()//Determine consumption rate, set 
{
	totalAmountInSystem=0;
	srand(time(0));
	amtCons=(rand()%5)+1;
	//Random consumption
}

float Commodity::getAmtCons()
{
	return amtCons;
}
