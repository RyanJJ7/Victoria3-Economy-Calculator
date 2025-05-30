#include "ProductionMethods.h"

void productionMethodsType::setProductionMethod(int pm, string name) {
	ofstream outFile;
	fs::create_directories("C:\\Users\\RyanJ\\OneDrive\\Desktop\\Vicky3\\Vicky3 Programs\\Production Methods\\ProductionMethod");
	outFile.open("C:\\Users\\RyanJ\\OneDrive\\Desktop\\Vicky3\\Vicky3 Programs\\Production Methods\\ProductionMethod\\name[" + to_string(pm) + "].txt");
	outFile << name;
	outFile.close();
}

void productionMethodsType::setSize(int pm, int size) {
	ofstream outFile;
	fs::create_directories("C:\\Users\\RyanJ\\OneDrive\\Desktop\\Vicky3\\Vicky3 Programs\\Production Methods\\Size");
	outFile.open("C:\\Users\\RyanJ\\OneDrive\\Desktop\\Vicky3\\Vicky3 Programs\\Production Methods\\Size\\size[" + to_string(pm) + "].txt");
	outFile << size;
	outFile.close();
}

void productionMethodsType::setMilitaryConsumption(int pm, float milConsumption, int i, int j) {
	ofstream outFile;
	fs::create_directories("C:\\Users\\RyanJ\\OneDrive\\Desktop\\Vicky3\\Vicky3 Programs\\Production Methods\\\\MilitaryConsumption\\milConsumption[i][j][" + to_string(j) + "]\\milConsumption[i][" + to_string(i) + "][" + to_string(j) + "]");
	outFile.open("C:\\Users\\RyanJ\\OneDrive\\Desktop\\Vicky3\\Vicky3 Programs\\Production Methods\\MilitaryConsumption\\milConsumption[i][j][" + to_string(j) + "]\\milConsumption[i][" + to_string(i) + "][" + to_string(j) + "]\\milConsumption[" + to_string(pm) + "][" + to_string(i) + "][" + to_string(j) + "].txt");
	outFile << milConsumption;
	outFile.close();
}

void productionMethodsType::setInputGood(int pm, float input, int i, int j) {
	ofstream outFile;
	fs::create_directories("C:\\Users\\RyanJ\\OneDrive\\Desktop\\Vicky3\\Vicky3 Programs\\Production Methods\\\\InputGood\\input[i][j][" + to_string(j) + "]\\input[i][" + to_string(i) + "][" + to_string(j) + "]");
	outFile.open("C:\\Users\\RyanJ\\OneDrive\\Desktop\\Vicky3\\Vicky3 Programs\\Production Methods\\InputGood\\input[i][j][" + to_string(j) + "]\\input[i][" + to_string(i) + "][" + to_string(j) + "]\\input[" + to_string(pm) + "][" + to_string(i) + "][" + to_string(j) + "].txt");
	outFile << input;
	outFile.close();
}

void productionMethodsType::setOutputGood(int pm, float output, int i, int j) {
	ofstream outFile;
	fs::create_directories("C:\\Users\\RyanJ\\OneDrive\\Desktop\\Vicky3\\Vicky3 Programs\\Production Methods\\\\OutputGood\\output[i][j][" + to_string(j) + "]\\output[i][" + to_string(i) + "][" + to_string(j) + "]");
	outFile.open("C:\\Users\\RyanJ\\OneDrive\\Desktop\\Vicky3\\Vicky3 Programs\\Production Methods\\OutputGood\\output[i][j][" + to_string(j) + "]\\output[i][" + to_string(i) + "][" + to_string(j) + "]\\output[" + to_string(pm) + "][" + to_string(i) + "][" + to_string(j) + "].txt");
	outFile << output;
	outFile.close();
}

void productionMethodsType::setProfession(int pm, int profession, int i, int j) {
	ofstream outFile;
	fs::create_directories("C:\\Users\\RyanJ\\OneDrive\\Desktop\\Vicky3\\Vicky3 Programs\\Production Methods\\\\Profession\\profession[i][j][" + to_string(j) + "]\\profession[i][" + to_string(i) + "][" + to_string(j) + "]");
	outFile.open("C:\\Users\\RyanJ\\OneDrive\\Desktop\\Vicky3\\Vicky3 Programs\\Production Methods\\Profession\\profession[i][j][" + to_string(j) + "]\\profession[i][" + to_string(i) + "][" + to_string(j) + "]\\profession[" + to_string(pm) + "][" + to_string(i) + "][" + to_string(j) + "].txt");
	outFile << profession;
	outFile.close();
}

void productionMethodsType::setProfession(int pm, int p, int i, string t) {
	if (t == "Peasants") setProfession(pm, p, i, 0);
	else if (t == "Laborers") setProfession(pm, p, i, 1);
	else if (t == "Servicemen") setProfession(pm, p, i, 2);
	else if (t == "Machinists") setProfession(pm, p, i, 3);
	else if (t == "Clerks") setProfession(pm, p, i, 4);
	else if (t == "Farmers") setProfession(pm, p, i, 5);
	else if (t == "Shopkeepers") setProfession(pm, p, i, 6);
	else if (t == "Clergymen") setProfession(pm, p, i, 7);
	else if (t == "Engineers") setProfession(pm, p, i, 8);
	else if (t == "Bureaucrats") setProfession(pm, p, i, 9);
	else if (t == "Academics") setProfession(pm, p, i, 10);
	else if (t == "Officers") setProfession(pm, p, i, 11);
	else if (t == "Aristocrats") setProfession(pm, p, i, 12);
	else if (t == "Capitalists") setProfession(pm, p, i, 13);
}

string productionMethodsType::getProductionMethod(int pm) {
	string name;
	ifstream inFile;
	inFile.open("C:\\Users\\RyanJ\\OneDrive\\Desktop\\Vicky3\\Vicky3 Programs\\Production Methods\\ProductionMethod\\name[" + to_string(pm) + "].txt");
	getline(inFile, name);
	inFile.close();
	return name;
}

int productionMethodsType::getSize(int pm) {
	int size;
	ifstream inFile;
	inFile.open("C:\\Users\\RyanJ\\OneDrive\\Desktop\\Vicky3\\Vicky3 Programs\\Production Methods\\Size\\size[" + to_string(pm) + "].txt");
	inFile >> size;
	inFile.close();
	return size;
}

float productionMethodsType::getMilitaryConsumption(goodsType good, string building, bool mobilization[ASIZE][2], int pm, int i, int j, int k) {
	if (getProductionMethod(pm) == "Military Unit Type") {
		float milConsumption;
		ifstream inFile;
		inFile.open("C:\\Users\\RyanJ\\OneDrive\\Desktop\\Vicky3\\Vicky3 Programs\\Production Methods\\MilitaryConsumption\\milConsumption[i][j][" + to_string(j) + "]\\milConsumption[i][" + to_string(i) + "][" + to_string(j) + "]\\milConsumption[" + to_string(pm) + "][" + to_string(i) + "][" + to_string(j) + "].txt");
		inFile >> milConsumption;
		inFile.close();
		if (building == "Barracks" && mobilization[0][k]) {
			float consumption = 0;
			float percentage = 1.6;
			good.setMobilizedConsumption(mobilization, consumption, percentage, k);
			return (milConsumption + consumption) * percentage;
		}
		return milConsumption;
	}
	return 0;
}

float productionMethodsType::getInputGood(goodsType good, string building, bool mobilization[ASIZE][2], int pm, int i, int j, int k) {
	float input;
	ifstream inFile;
	inFile.open("C:\\Users\\RyanJ\\OneDrive\\Desktop\\Vicky3\\Vicky3 Programs\\Production Methods\\InputGood\\input[i][j][" + to_string(j) + "]\\input[i][" + to_string(i) + "][" + to_string(j) + "]\\input[" + to_string(pm) + "][" + to_string(i) + "][" + to_string(j) + "].txt");
	inFile >> input;
	inFile.close();
	return input + getMilitaryConsumption(good, building, mobilization, pm, i, j, k);
}

float productionMethodsType::getOutputGood(int pm, int i, int j) {
	float output;
	ifstream inFile;
	inFile.open("C:\\Users\\RyanJ\\OneDrive\\Desktop\\Vicky3\\Vicky3 Programs\\Production Methods\\OutputGood\\output[i][j][" + to_string(j) + "]\\output[i][" + to_string(i) + "][" + to_string(j) + "]\\output[" + to_string(pm) + "][" + to_string(i) + "][" + to_string(j) + "].txt");
	inFile >> output;
	inFile.close();
	return output;
}

int productionMethodsType::getProfession(int pm, int i, int j) {
	int profession;
	ifstream inFile;
	inFile.open("C:\\Users\\RyanJ\\OneDrive\\Desktop\\Vicky3\\Vicky3 Programs\\Production Methods\\Profession\\profession[i][j][" + to_string(j) + "]\\profession[i][" + to_string(i) + "][" + to_string(j) + "]\\profession[" + to_string(pm) + "][" + to_string(i) + "][" + to_string(j) + "].txt");
	inFile >> profession;
	inFile.close();
	return profession;
}