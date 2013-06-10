#ifndef MODEL_H
#define MODEL_H
#include<SharedContext.h>
#include"Human.h"
#include<Random.h>
#include<ostream>
//#include"Commodity.h"

class Model
{
public:
    static const int NUM_INITIAL_AGENTS = 100;
    static Model * instance();
    double generateNeedCommodityThreshold();
    double generateWantCommodityThreshold();
    double generateSalary();
	int generateMake();
	double generateMps();
	double generateLifeProb();
	double generateConsume();
    void startSimulation();
	repast::SharedContext<Human>& getActors();
    void printCommodityStats(std::ostream & os) const;

private:
    void createInitialAgents();
	repast::SharedContext<Human> actors;
    repast::NumberGenerator *commodityNeedThresholdDistro;
    repast::NumberGenerator *commodityWantThresholdDistro;
    repast::NumberGenerator *salaryDistro;
	repast::NumberGenerator *makeDistro;	
	repast::NumberGenerator *deathChildDistro;
	repast::NumberGenerator *mpsDistro;
	repast::NumberGenerator *consumeDistro;
    static Model * theInstance;
	Model();
};
#endif



/*
    ...somewhere, Russell needs to generate a random commodity threshold!

    he writes this code!

    Model::instance()->generateCommodityThreshold();
*/
