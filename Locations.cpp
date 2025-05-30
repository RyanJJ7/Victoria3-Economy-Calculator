#include "Locations.h"

void locationsType::setLevel(int l) {
	level = max(l, 0);
}

void locationsType::setSubsidized(int s) {
	subsidized = max(s, 0);
}

void locationsType::setProductionMethodLevel(int ml, int i) {
	methodLevel[i] = max(ml, 0);
}

void locationsType::setBuildingThroughput(float bt) {
	buildingThroughput = bt;
}

int locationsType::getLevel() const {
	return level;
}

int locationsType::getSubsidized() const {
	return subsidized;
}

int locationsType::getProductionMethodLevel(int i) const {
	return methodLevel[i];
}

string locationsType::getArmyUnitType(int i) const {
	switch (methodLevel[i]) {
	case 1: return "Line Infantry";
	case 2: return "Skirmish Infantry";
	case 3: return "Trench Infantry";
	case 4: return "Squad Infantry";
	case 5: return "Mechanized Infantry";
	case 6: return "Cannon Artillery";
	case 7: return "Mobile Artillery";
	case 8: return "Shrapnel Artillery";
	case 9: return "Siege Artillery";
	case 10: return "Heavy Tanks";
	case 11: return "Hussars";
	case 12: return "Dragoons";
	case 13: return "Cuirassiers";
	case 14: return "Lancers";
	case 15: return "Light Tanks";
	default: return "Irregular Infantry";
	}
}

string locationsType::getNavyUnitType(int i) const {
	switch (methodLevel[i]) {
	case 1: return "Monitors";
	case 2: return "Destroyers";
	case 3: return "Torpedo Boats";
	case 4: return "Scout Cruisers";
	case 5: return "Man-o-wars";
	case 6: return "Ironclads";
	case 7: return "Dreadnoughts";
	case 8: return "Battleships";
	case 9: return "Submarines";
	case 10: return "Carriers";
	default: return "Frigates";
	}
}

string locationsType::getNewArmyUnitType(int ml) const {
	switch (ml) {
	case 1: return "Line Infantry";
	case 2: return "Skirmish Infantry";
	case 3: return "Trench Infantry";
	case 4: return "Squad Infantry";
	case 5: return "Mechanized Infantry";
	case 6: return "Cannon Artillery";
	case 7: return "Mobile Artillery";
	case 8: return "Shrapnel Artillery";
	case 9: return "Siege Artillery";
	case 10: return "Heavy Tanks";
	case 11: return "Hussars";
	case 12: return "Dragoons";
	case 13: return "Cuirassiers";
	case 14: return "Lancers";
	case 15: return "Light Tanks";
	default: return "Irregular Infantry";
	}
}

string locationsType::getNewNavyUnitType(int ml) const {
	switch (ml) {
	case 1: return "Monitors";
	case 2: return "Destroyers";
	case 3: return "Torpedo Boats";
	case 4: return "Scout Cruisers";
	case 5: return "Man-o-wars";
	case 6: return "Ironclads";
	case 7: return "Dreadnoughts";
	case 8: return "Battleships";
	case 9: return "Submarines";
	case 10: return "Carriers";
	default: return "Frigates";
	}
}

float locationsType::getBuildingThroughput() const {
	return buildingThroughput;
}