#ifndef PRODUCTIONMETHODS_H
#define PRODUCTIONMETHODS_H
#include "Goods.h"
#include <fstream>
#include <filesystem>
namespace fs = filesystem;

class productionMethodsType {
public:
	void setProductionMethod(int, string);
	void setSize(int, int);
	void setMilitaryConsumption(int, float, int, int);
	void setInputGood(int, float, int, int);
	void setOutputGood(int, float, int, int);
	void setProfession(int, int, int, int);
	void setProfession(int, int, int, string);

	string getProductionMethod(int);
	int getSize(int);
	float getMilitaryConsumption(goodsType, string, bool[][2], int, int, int, int);
	float getInputGood(goodsType, string, bool[][2], int, int, int, int);
	float getOutputGood(int, int, int);
	int getProfession(int, int, int);
};
#endif