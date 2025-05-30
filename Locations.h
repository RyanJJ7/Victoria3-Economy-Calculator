#ifndef LOCATIONS_H
#define LOCATIONS_H
#include <string>
using namespace std;

const int LSIZE = 4;

class locationsType {
private:
	int level;
	int subsidized;
	int methodLevel[LSIZE];
	float buildingThroughput;

public:
	void setLevel(int);
	void setSubsidized(int);
	void setProductionMethodLevel(int, int);
	void setBuildingThroughput(float);

	int getLevel() const;
	int getSubsidized() const;
	int getProductionMethodLevel(int) const;
	string getArmyUnitType(int) const;
	string getNavyUnitType(int) const;
	string getNewArmyUnitType(int) const;
	string getNewNavyUnitType(int) const;
	float getBuildingThroughput() const;
};
#endif