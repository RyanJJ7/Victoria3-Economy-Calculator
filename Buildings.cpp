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

float buildingsType::getWage(int citizenship[2], int accepted[PSIZE][2], int citizen[PSIZE][2], int prejudice[PSIZE][2], int erasure[PSIZE][2], int hostile[PSIZE][2], int i) const {
	switch (citizenship[i]) {
	case 1:
		return wage * (0.2 * (accepted[0][i] * 1.2 + citizen[0][i] * 0.9 + prejudice[0][i] * 0.8 + erasure[0][i] * 0.7 + hostile[0][i] * 0.6)
					+ (accepted[1][i] * 1.2 + citizen[1][i] * 0.9 + prejudice[1][i] * 0.8 + erasure[1][i] * 0.7 + hostile[1][i] * 0.6)
					+ 1.5 * ((accepted[2][i] * 1.2 + citizen[2][i] * 0.9 + prejudice[2][i] * 0.8 + erasure[2][i] * 0.7 + hostile[2][i] * 0.6)
					+ (accepted[3][i] * 1.2 + citizen[3][i] * 0.9 + prejudice[3][i] * 0.8 + erasure[3][i] * 0.7 + hostile[3][i] * 0.6)
					+ (accepted[4][i] * 1.2 + citizen[4][i] * 0.9 + prejudice[4][i] * 0.8 + erasure[4][i] * 0.7 + hostile[4][i] * 0.6))
					+ 2 * (accepted[5][i] * 1.2 + citizen[5][i] * 0.9 + prejudice[5][i] * 0.8 + erasure[5][i] * 0.7 + hostile[5][i] * 0.6)
					+ 3 * ((accepted[6][i] * 1.2 + citizen[6][i] * 0.9 + prejudice[6][i] * 0.8 + erasure[6][i] * 0.7 + hostile[6][i] * 0.6)
					+ (accepted[7][i] * 1.2 + citizen[7][i] * 0.9 + prejudice[7][i] * 0.8 + erasure[7][i] * 0.7 + hostile[7][i] * 0.6)
					+ (accepted[8][i] * 1.2 + citizen[8][i] * 0.9 + prejudice[8][i] * 0.8 + erasure[8][i] * 0.7 + hostile[8][i] * 0.6))
					+ 4 * ((accepted[9][i] * 1.2 + citizen[9][i] * 0.9 + prejudice[9][i] * 0.8 + erasure[9][i] * 0.7 + hostile[9][i] * 0.6)
					+ (accepted[10][i] * 1.2 + citizen[10][i] * 0.9 + prejudice[10][i] * 0.8 + erasure[10][i] * 0.7 + hostile[10][i] * 0.6))
					+ 5 * ((accepted[11][i] * 1.2 + citizen[11][i] * 0.9 + prejudice[11][i] * 0.8 + erasure[11][i] * 0.7 + hostile[11][i] * 0.6)
					+ (accepted[12][i] * 1.2 + citizen[12][i] * 0.9 + prejudice[12][i] * 0.8 + erasure[12][i] * 0.7 + hostile[12][i] * 0.6))
					+ 6 * (accepted[13][i] * 1.2 + citizen[13][i] * 0.9 + prejudice[13][i] * 0.8 + erasure[13][i] * 0.7 + hostile[13][i] * 0.6)) / 52;
	case 2:
		return wage * (0.2 * (accepted[0][i] * 1.15 + citizen[0][i] * 1.05 + prejudice[0][i] * 0.9 + erasure[0][i] * 0.8 + hostile[0][i] * 0.7)
					+ (accepted[1][i] * 1.15 + citizen[1][i] * 1.05 + prejudice[1][i] * 0.9 + erasure[1][i] * 0.8 + hostile[1][i] * 0.7)
					+ 1.5 * ((accepted[2][i] * 1.15 + citizen[2][i] * 1.05 + prejudice[2][i] * 0.9 + erasure[2][i] * 0.8 + hostile[2][i] * 0.7)
					+ (accepted[3][i] * 1.15 + citizen[3][i] * 1.05 + prejudice[3][i] * 0.9 + erasure[3][i] * 0.8 + hostile[3][i] * 0.7)
					+ (accepted[4][i] * 1.15 + citizen[4][i] * 1.05 + prejudice[4][i] * 0.9 + erasure[4][i] * 0.8 + hostile[4][i] * 0.7))
					+ 2 * (accepted[5][i] * 1.15 + citizen[5][i] * 1.05 + prejudice[5][i] * 0.9 + erasure[5][i] * 0.8 + hostile[5][i] * 0.7)
					+ 3 * ((accepted[6][i] * 1.15 + citizen[6][i] * 1.05 + prejudice[6][i] * 0.9 + erasure[6][i] * 0.8 + hostile[6][i] * 0.7)
					+ (accepted[7][i] * 1.15 + citizen[7][i] * 1.05 + prejudice[7][i] * 0.9 + erasure[7][i] * 0.8 + hostile[7][i] * 0.7)
					+ (accepted[8][i] * 1.15 + citizen[8][i] * 1.05 + prejudice[8][i] * 0.9 + erasure[8][i] * 0.8 + hostile[8][i] * 0.7))
					+ 4 * ((accepted[9][i] * 1.15 + citizen[9][i] * 1.05 + prejudice[9][i] * 0.9 + erasure[9][i] * 0.8 + hostile[9][i] * 0.7)
					+ (accepted[10][i] * 1.15 + citizen[10][i] * 1.05 + prejudice[10][i] * 0.9 + erasure[10][i] * 0.8 + hostile[10][i] * 0.7))
					+ 5 * ((accepted[11][i] * 1.15 + citizen[11][i] * 1.05 + prejudice[11][i] * 0.9 + erasure[11][i] * 0.8 + hostile[11][i] * 0.7)
					+ (accepted[12][i] * 1.15 + citizen[12][i] * 1.05 + prejudice[12][i] * 0.9 + erasure[12][i] * 0.8 + hostile[12][i] * 0.7))
					+ 6 * (accepted[13][i] * 1.15 + citizen[13][i] * 1.05 + prejudice[13][i] * 0.9 + erasure[13][i] * 0.8 + hostile[13][i] * 0.7)) / 52;
	case 3:
		return wage * (0.2 * (accepted[0][i] * 1.05 + citizen[0][i] + prejudice[0][i] * 0.9 + erasure[0][i] * 0.8 + hostile[0][i] * 0.7)
					+ (accepted[1][i] * 1.05 + citizen[1][i] + prejudice[1][i] * 0.9 + erasure[1][i] * 0.8 + hostile[1][i] * 0.7)
					+ 1.5 * ((accepted[2][i] * 1.05 + citizen[2][i] + prejudice[2][i] * 0.9 + erasure[2][i] * 0.8 + hostile[2][i] * 0.7)
					+ (accepted[3][i] * 1.05 + citizen[3][i] + prejudice[3][i] * 0.9 + erasure[3][i] * 0.8 + hostile[3][i] * 0.7)
					+ (accepted[4][i] * 1.05 + citizen[4][i] + prejudice[4][i] * 0.9 + erasure[4][i] * 0.8 + hostile[4][i] * 0.7))
					+ 2 * (accepted[5][i] * 1.05 + citizen[5][i] + prejudice[5][i] * 0.9 + erasure[5][i] * 0.8 + hostile[5][i] * 0.7)
					+ 3 * ((accepted[6][i] * 1.05 + citizen[6][i] + prejudice[6][i] * 0.9 + erasure[6][i] * 0.8 + hostile[6][i] * 0.7)
					+ (accepted[7][i] * 1.05 + citizen[7][i] + prejudice[7][i] * 0.9 + erasure[7][i] * 0.8 + hostile[7][i] * 0.7)
					+ (accepted[8][i] * 1.05 + citizen[8][i] + prejudice[8][i] * 0.9 + erasure[8][i] * 0.8 + hostile[8][i] * 0.7))
					+ 4 * ((accepted[9][i] * 1.05 + citizen[9][i] + prejudice[9][i] * 0.9 + erasure[9][i] * 0.8 + hostile[9][i] * 0.7)
					+ (accepted[10][i] * 1.05 + citizen[10][i] + prejudice[10][i] * 0.9 + erasure[10][i] * 0.8 + hostile[10][i] * 0.7))
					+ 5 * ((accepted[11][i] * 1.05 + citizen[11][i] + prejudice[11][i] * 0.9 + erasure[11][i] * 0.8 + hostile[11][i] * 0.7)
					+ (accepted[12][i] * 1.05 + citizen[12][i] + prejudice[12][i] * 0.9 + erasure[12][i] * 0.8 + hostile[12][i] * 0.7))
					+ 6 * (accepted[13][i] * 1.05 + citizen[13][i] + prejudice[13][i] * 0.9 + erasure[13][i] * 0.8 + hostile[13][i] * 0.7)) / 52;
	case 4:
		return wage * (0.2 * (accepted[0][i] + citizen[0][i] + prejudice[0][i] * 0.95 + erasure[0][i] * 0.9 + hostile[0][i] * 0.8)
					+ (accepted[1][i] + citizen[1][i] + prejudice[1][i] * 0.95 + erasure[1][i] * 0.9 + hostile[1][i] * 0.8)
					+ 1.5 * ((accepted[2][i] + citizen[2][i] + prejudice[2][i] * 0.95 + erasure[2][i] * 0.9 + hostile[2][i] * 0.8)
					+ (accepted[3][i] + citizen[3][i] + prejudice[3][i] * 0.95 + erasure[3][i] * 0.9 + hostile[3][i] * 0.8)
					+ (accepted[4][i] + citizen[4][i] + prejudice[4][i] * 0.95 + erasure[4][i] * 0.9 + hostile[4][i] * 0.8))
					+ 2 * (accepted[5][i] + citizen[5][i] + prejudice[5][i] * 0.95 + erasure[5][i] * 0.9 + hostile[5][i] * 0.8)
					+ 3 * ((accepted[6][i] + citizen[6][i] + prejudice[6][i] * 0.95 + erasure[6][i] * 0.9 + hostile[6][i] * 0.8)
					+ (accepted[7][i] + citizen[7][i] + prejudice[7][i] * 0.95 + erasure[7][i] * 0.9 + hostile[7][i] * 0.8)
					+ (accepted[8][i] + citizen[8][i] + prejudice[8][i] * 0.95 + erasure[8][i] * 0.9 + hostile[8][i] * 0.8))
					+ 4 * ((accepted[9][i] + citizen[9][i] + prejudice[9][i] * 0.95 + erasure[9][i] * 0.9 + hostile[9][i] * 0.8)
					+ (accepted[10][i] + citizen[10][i] + prejudice[10][i] * 0.95 + erasure[10][i] * 0.9 + hostile[10][i] * 0.8))
					+ 5 * ((accepted[11][i] + citizen[11][i] + prejudice[11][i] * 0.95 + erasure[11][i] * 0.9 + hostile[11][i] * 0.8)
					+ (accepted[12][i] + citizen[12][i] + prejudice[12][i] * 0.95 + erasure[12][i] * 0.9 + hostile[12][i] * 0.8))
					+ 6 * (accepted[13][i] + citizen[13][i] + prejudice[13][i] * 0.95 + erasure[13][i] * 0.9 + hostile[13][i] * 0.8)) / 52;
	default:
		return wage * (0.2 * (accepted[0][i] * 1.25 + citizen[0][i] * 0.85 + prejudice[0][i] * 0.75 + erasure[0][i] * 0.6 + hostile[0][i] * 0.5)
					+ (accepted[1][i] * 1.25 + citizen[1][i] * 0.85 + prejudice[1][i] * 0.75 + erasure[1][i] * 0.6 + hostile[1][i] * 0.5)
					+ 1.5 * ((accepted[2][i] * 1.25 + citizen[2][i] * 0.85 + prejudice[2][i] * 0.75 + erasure[2][i] * 0.6 + hostile[2][i] * 0.5)
					+ (accepted[3][i] * 1.25 + citizen[3][i] * 0.85 + prejudice[3][i] * 0.75 + erasure[3][i] * 0.6 + hostile[3][i] * 0.5)
					+ (accepted[4][i] * 1.25 + citizen[4][i] * 0.85 + prejudice[4][i] * 0.75 + erasure[4][i] * 0.6 + hostile[4][i] * 0.5))
					+ 2 * (accepted[5][i] * 1.25 + citizen[5][i] * 0.85 + prejudice[5][i] * 0.75 + erasure[5][i] * 0.6 + hostile[5][i] * 0.5)
					+ 3 * ((accepted[6][i] * 1.25 + citizen[6][i] * 0.85 + prejudice[6][i] * 0.75 + erasure[6][i] * 0.6 + hostile[6][i] * 0.5)
					+ (accepted[7][i] * 1.25 + citizen[7][i] * 0.85 + prejudice[7][i] * 0.75 + erasure[7][i] * 0.6 + hostile[7][i] * 0.5)
					+ (accepted[8][i] * 1.25 + citizen[8][i] * 0.85 + prejudice[8][i] * 0.75 + erasure[8][i] * 0.6 + hostile[8][i] * 0.5))
					+ 4 * ((accepted[9][i] * 1.25 + citizen[9][i] * 0.85 + prejudice[9][i] * 0.75 + erasure[9][i] * 0.6 + hostile[9][i] * 0.5)
					+ (accepted[10][i] * 1.25 + citizen[10][i] * 0.85 + prejudice[10][i] * 0.75 + erasure[10][i] * 0.6 + hostile[10][i] * 0.5))
					+ 5 * ((accepted[11][i] * 1.25 + citizen[11][i] * 0.85 + prejudice[11][i] * 0.75 + erasure[11][i] * 0.6 + hostile[11][i] * 0.5)
					+ (accepted[12][i] * 1.25 + citizen[12][i] * 0.85 + prejudice[12][i] * 0.75 + erasure[12][i] * 0.6 + hostile[12][i] * 0.5))
					+ 6 * (accepted[13][i] * 1.25 + citizen[13][i] * 0.85 + prejudice[13][i] * 0.75 + erasure[13][i] * 0.6 + hostile[13][i] * 0.5)) / 52;
	}
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