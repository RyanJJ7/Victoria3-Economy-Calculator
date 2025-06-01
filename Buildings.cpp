#include "Buildings.h"

void buildingsType::setBuilding(string n) {
	name = n;
}

void buildingsType::setConstructionCost(int c) {
	construction = c;
}

void buildingsType::setInfrastructureUsage(int i) {
	infrastructure = i;
}

void buildingsType::setThroughput(float t, int i) {
	throughput[i] = t;
}

void buildingsType::setBaseWage(float w) {
	wage = max(w, float(0));
}

void buildingsType::setBuildingLocation(int l) {
	location = l;
}

void buildingsType::setProductionMethod(int m) {
	method = m;
}

void buildingsType::setSize(int s) {
	size = s;
}

string buildingsType::getBuilding() const {
	return name;
}

int buildingsType::getConstructionCost() const {
	return construction;
}

int buildingsType::getInfrastructureUsage(int l) const {
	return infrastructure * l;
}

float buildingsType::getThroughput(int i) const {
	return throughput[i];
}

float buildingsType::getBaseWage() const {
	return wage;
}

float buildingsType::getWage(int undiscriminated[PSIZE][2], int discriminated[PSIZE][2], int i) const {
	return wage * (0.2 * (undiscriminated[0][i] + discriminated[0][i] * 0.66)
				+ (undiscriminated[1][i] + discriminated[1][i] * 0.66)
				+ 1.5 * ((undiscriminated[2][i] + discriminated[2][i] * 0.66)
				+ (undiscriminated[3][i] + discriminated[3][i] * 0.66)
				+ (undiscriminated[4][i] + discriminated[4][i] * 0.66))
				+ 2 * ((undiscriminated[5][i] + discriminated[5][i] * 0.66)
				+ (undiscriminated[6][i] + discriminated[6][i] * 0.66))
				+ 3 * ((undiscriminated[7][i] + discriminated[7][i] * 0.66)
				+ (undiscriminated[8][i] + discriminated[8][i] * 0.66))
				+ 4 * ((undiscriminated[9][i] + discriminated[9][i] * 0.66)
				+ (undiscriminated[10][i] + discriminated[10][i] * 0.66))
				+ 5 * (undiscriminated[11][i] + discriminated[11][i] * 0.66)
				+ 6 * ((undiscriminated[12][i] + discriminated[12][i] * 0.66)
				+ (undiscriminated[13][i] + discriminated[13][i] * 0.66))) / 52;
}

int buildingsType::getBuildingLocation() const {
	return location;
}

int buildingsType::getProductionMethod() const {
	return method;
}

int buildingsType::getSize() const {
	return size;
}

bool buildingsType::subsistence() const {
	if (name == "Subsistence Farms" || name == "Subsistence Orchards" || name == "Subsistence Pastures" || name == "Subsistence Fishing Villages" || name == "Subsistence Rice Paddies") return true;
	return false;
}

bool buildingsType::buildable() const {
	if (name == "Urban Center" || name == "Gold Fields" || subsistence()) return false;
	return true;
}

bool buildingsType::hasEOS() const {
	if (subsistence() || name == "Barracks" || name == "Naval Base" || name == "Port" || name == "Skyscraper" || name == "Canals" || name == "Construction Sector") return false;
	return true;
}

bool buildingsType::autoSubsidized() const {
	if (!hasEOS() || name == "Government Administration" || name == "University") return true;
	return false;
}
