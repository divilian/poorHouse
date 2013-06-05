#include"Model.h"
#include<Properties.h>
#include<Random.h>
#include<Schedule.h>
#include<RepastProcess.h>
#include<initialize_random.h>

using namespace std;

Model * Model::theInstance = NULL;

Model::Model()
{
    // Initialize random number distributions.
    repast::Properties theProperties("./distributions.txt");
    repast::initializeRandom(theProperties);
    commodityNeedThresholdDistro =
        repast::Random::instance()->getGenerator("commodityNeedThreshold");
    commodityWantThresholdDistro =
        repast::Random::instance()->getGenerator("commodityWantThreshold");
    salaryDistro =
        repast::Random::instance()->getGenerator("salary");
	makeDistro =
		repast::Random::instance()->getGenerator("make");
}

void Model::createInitialAgents() {

    // Create the initial generation of agents, and add them to the Context.
    // While we're at it, schedule all agents to run in 1 year's time.
    repast::ScheduleRunner &theScheduleRunner = 
        repast::RepastProcess::instance()->getScheduleRunner();
    for (int i=0; i<NUM_INITIAL_AGENTS; i++) {
        Human *newHuman = new Human();
        actors.addAgent(newHuman);
        theScheduleRunner.scheduleEvent(1, repast::Schedule::FunctorPtr(
            new repast::MethodFunctor<Human>(newHuman, &Human::step)));
    }
}

void Model::startSimulation() {

    createInitialAgents();

    repast::ScheduleRunner &theScheduleRunner = 
        repast::RepastProcess::instance()->getScheduleRunner();

    // Schedule an end point.
    theScheduleRunner.scheduleStop(2);

    // Let's DO THIS THING!!!
    theScheduleRunner.run();
}

Model * Model::instance() {
    if (theInstance == NULL) {
        theInstance = new Model();
    }
    return theInstance;
}

double Model::generateNeedCommodityThreshold() {
    return commodityNeedThresholdDistro->next();
}

double Model::generateWantCommodityThreshold() {
    return commodityWantThresholdDistro->next();
}

double Model::generateSalary() {
    return salaryDistro->next();
}

int Model::generateMake() {
	return makeDistro->next();
}
