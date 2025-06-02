#ifndef BUILDINGS_H
#define BUILDINGS_H
#include <string>
using namespace std;

const int PSIZE = 14;

class buildingsType {
private:
	string name;
	int construction;
	int infrastructure;
	float throughput[7];
	float wage;
	int location;
	int method;
	int size;

public:
	void setBuilding(string);
	void setConstructionCost(int);
	void setInfrastructureUsage(int);
	void setThroughput(float, int);
	void setBaseWage(float);
	void setBuildingLocation(int);
	void setProductionMethod(int);
	void setSize(int);

	string getBuilding() const;
	int getConstructionCost() const;
	int getInfrastructureUsage(int) const;
	float getThroughput(int) const;
	float getBaseWage() const;
	float getWage(int[], int[][2], int[][2], int[][2], int[][2], int[][2], int) const;
	int getBuildingLocation() const;
	int getProductionMethod() const;
	int getSize() const;

	bool subsistence() const;
	bool buildable() const;
	bool hasEOS() const;
	bool autoSubsidized() const;
};
#endif
