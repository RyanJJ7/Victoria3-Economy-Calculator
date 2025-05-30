#include "Goods.h"

void goodsType::setGood(string n) {
	name = n;
}

void goodsType::setBasePrice(int p) {
	price = p;
}

void goodsType::setSellOrders(float s) {
	sell = max(s, float(0));
}

void goodsType::setBuyOrders(float b) {
	buy = max(b, float(0));
}

void goodsType::setProduction(float p) {
	production = max(p, float(0));
}

void goodsType::setConsumption(float c) {
	consumption = max(c, float(0));
}

void goodsType::setMilitaryConsumption() {
	milConsumption = 0;
}

void goodsType::setMilitaryConsumption(float mc) {
	milConsumption += mc;
}

void goodsType::setMobilizedConsumption(bool mobilization[ASIZE][2], float& consumption, float& percentage, int i) const {
	if (mobilization[1][i]) {
		if (name == "Grain") consumption += 0.5;
		else if (militaryGood()) percentage += 0.25;
	}
	if (mobilization[2][i]) {
		if (name == "Groceries") consumption += 1;
		else if (militaryGood()) percentage += 0.25;
	}
	if (mobilization[3][i]) {
		if (name == "Meat" || name == "Wine") consumption += 1;
		else if (militaryGood()) percentage += 0.25;
	}
	if (mobilization[4][i] && name == "Sugar") consumption += 1;
	if (mobilization[5][i] && name == "Tobacco") consumption += 0.5;
	if (mobilization[6][i] && name == "Liquor") consumption += 0.5;
	if (mobilization[7][i] && name == "Opium") consumption += 0.5;
	if (mobilization[8][i] && name == "Automobiles") consumption += 0.5;
	if (mobilization[9][i] && name == "Engines") consumption += 0.5;
	if (mobilization[10][i]) {
		if (name == "Automobiles") consumption += 1;
		else if (name == "Oil") consumption += 0.5;
	}
	if (mobilization[11][i]) {
		if (name == "Fabric") consumption += 2;
		else if (name == "Oil") consumption += 0.5;
	}
	if (mobilization[12][i]) {
		if (name == "Aeroplanes") consumption += 1;
		else if (name == "Oil") consumption += 0.5;
	}
	if (mobilization[13][i] && (name == "Ammunition" || name == "Small Arms")) consumption += 1;
	if (mobilization[14][i] && name == "Fertilizer") consumption += 2;
	if (mobilization[15][i] && name == "Oil") consumption += 1;
	if (mobilization[16][i]) {
		if (name == "Fabric") consumption += 1;
		else if (name == "Liquor") consumption += 2;
	}
	if (mobilization[17][i]) {
		if (name == "Opium") consumption += 2;
		else if (name == "Tools") consumption += 1;
	}
}

void goodsType::setPopConsumption(float pc) {
	popConsumption = max(pc, float(0));
}

void goodsType::setLocalPopConsumption(float lpc) {
	localPopConsumption = max(lpc, float(0));
}

void goodsType::setImports(float i) {
	imports = max(i, float(0));
}

void goodsType::setThroughput(float t) {
	throughput = t;
}

void goodsType::setObsession(float o) {
	if (o < 0) o = 0;
	else if (o > 1) o = 1;
	obsession = o;
	if (taboo > 1 - obsession) taboo = 1 - obsession;
}

void goodsType::setTaboo(float t) {
	if (t < 0) t = 0;
	else if (t > 1) t = 1;
	taboo = t;
	if (obsession > 1 - taboo) obsession = 1 - taboo;
}

void goodsType::setLocalObsession(float lo) {
	if (lo < 0) lo = 0;
	else if (lo > 1) lo = 1;
	localObsession = lo;
	if (localTaboo > 1 - localObsession) localTaboo = 1 - localObsession;
}

void goodsType::setLocalTaboo(float lt) {
	if (lt < 0) lt = 0;
	else if (lt > 1) lt = 1;
	localTaboo = lt;
	if (localObsession > 1 - localTaboo) localObsession = 1 - localTaboo;
}

void goodsType::setDefault(bool d, int i) {
	bold[i] = d;
}

void goodsType::setWeight(float w, int i) {
	weight[i] = w;
}

void goodsType::setMinSS(float min, int i) {
	minSupplyShare[i] = min;
}

void goodsType::setMaxSS(float max, int i) {
	maxSupplyShare[i] = max;
}

void goodsType::setInput(int i) {
	input[i] = 0;
}

void goodsType::setOutput(int i) {
	output[i] = 0;
}

void goodsType::setInput(float in, int i) {
	input[i] += in;
}

void goodsType::setOutput(float out, int i) {
	output[i] += out;
}

void goodsType::setInputOutput(int i) {
	if (input[i] < 0) {
		output[i] -= input[i];
		input[i] = 0;
	}
	if (output[i] < 0) {
		input[i] -= output[i];
		output[i] = 0;
	}
}

string goodsType::getGood() const {
	return name;
}

float goodsType::getSellOrders() const {
	return sell;
}

float goodsType::getBuyOrders() const {
	return buy;
}

float goodsType::getProduction() const {
	return production;
}

float goodsType::getConsumption() const {
	return consumption;
}

float goodsType::getMilitaryConsumption() const {
	return milConsumption;
}

float goodsType::getPopConsumption() const {
	return popConsumption;
}

float goodsType::getPopConsumption(float purchaseWeight) const {
	return trunc(popConsumption * purchaseWeight * 1000) / 1000;
}

float goodsType::getPopConsumptionChange(float purchaseWeight) const {
	return trunc((getPopConsumption(purchaseWeight) - popConsumption) * 10) / 10;
}

float goodsType::getLocalPopConsumption() const {
	return localPopConsumption;
}

float goodsType::getLocalPopConsumption(float purchaseWeight) const {
	return trunc(localPopConsumption * purchaseWeight * 1000) / 1000;
}

float goodsType::getLocalPopConsumptionChange(float purchaseWeight) const {
	return trunc((getLocalPopConsumption(purchaseWeight) - localPopConsumption) * 10) / 10;
}

float goodsType::getImports() const {
	return imports;
}

float goodsType::getThroughput() const {
	return throughput;
}

float goodsType::getObsession() const {
	return obsession;
}

float goodsType::getTaboo() const {
	return taboo;
}

float goodsType::getWeight(float gdp, int i) const {
	float obsessionWeight = max(weight[i], float(1)) * 2;
	float tabooWeight = weight[i] * 0.5;
	if (localGood()) return 0.25 * (1 - gdp) + weight[i] * (1 - (obsession + taboo)) + obsessionWeight * obsession + tabooWeight * taboo;

	return weight[i] * (1 - (obsession + taboo)) + obsessionWeight * obsession + tabooWeight * taboo;
}

float goodsType::getLocalObsession() const {
	return localObsession;
}

float goodsType::getLocalTaboo() const {
	return localTaboo;
}

float goodsType::getLocalWeight(float gdp, int i) const {
	float obsessionWeight = max(weight[i], float(1)) * 2;
	float tabooWeight = weight[i] * 0.5;
	if (localGood()) return 0.25 * (1 - gdp) + weight[i] * (1 - (localObsession + localTaboo)) + obsessionWeight * localObsession + tabooWeight * localTaboo;

	return weight[i] * (1 - (localObsession + localTaboo)) + obsessionWeight * localObsession + tabooWeight * localTaboo;
}

float goodsType::getInput(int i) const {
	return input[i];
}

float goodsType::getOutput(int i) const {
	return output[i];
}

int goodsType::getBalance() const {
	return sell - buy;
}

int goodsType::getBalance(float output) const {
	return output - buy;
}

int goodsType::getBalancePrediction(float purchaseWeight) const {
	return getBalance() - getPopConsumptionChange(purchaseWeight);
}

int goodsType::getBalancePrediction(float output, float purchaseWeight) const {
	return getBalance(output) - getPopConsumptionChange(purchaseWeight);
}

int goodsType::getStateBalance() const {
	return production - consumption;
}

int goodsType::getStateBalance(float output) const {
	return output - consumption;
}

int goodsType::getStateBalancePrediction(float purchaseWeight) const {
	return getStateBalance() - getLocalPopConsumptionChange(purchaseWeight);
}

int goodsType::getStateBalancePrediction(float output, float purchaseWeight) const {
	return getStateBalance(output) - getLocalPopConsumptionChange(purchaseWeight);
}

float goodsType::getMarketShare(int i) const {
	if (weight[i] == 0)
		return 0;
	return max(sell - (buy - popConsumption) / 2, float(0));
}

float goodsType::getMarketShare(float output, int i) const {
	if (weight[i] == 0)
		return 0;
	return max(output - (buy - popConsumption) / 2, float(0));
}

float goodsType::getLocalMarketShare(float output, int i) const {
	return getMarketShare(output - production + sell, i);
}

float goodsType::getMarketShare(float input, float output, int i) const {
	if (weight[i] == 0)
		return 0;
	return max(sell + output - (buy + input - popConsumption) / 2, float(0));
}

float goodsType::getPurchaseWeight(float msSum, float gdp, int i) const {
	float supplyShare = minSupplyShare[i];
	if (msSum == 0) {
		if (bold[i]) supplyShare = 1;
	}
	else supplyShare = max(getMarketShare(i) / msSum, minSupplyShare[i]);

	return getWeight(gdp, i) * min(supplyShare, maxSupplyShare[i]);
}

float goodsType::getPurchaseWeight(float output, float msSum, float gdp, int i) const {
	float supplyShare = minSupplyShare[i];
	if (msSum == 0) {
		if (bold[i]) supplyShare = 1;
	}
	else supplyShare = max(getMarketShare(output, i) / msSum, minSupplyShare[i]);

	return getWeight(gdp, i) * min(supplyShare, maxSupplyShare[i]);
}

float goodsType::getPurchaseWeightLocalOutput(float output, float msSum, float gdp, int i) const {
	float supplyShare = minSupplyShare[i];
	if (msSum == 0) {
		if (bold[i]) supplyShare = 1;
	}
	else supplyShare = max(getLocalMarketShare(output, i) / msSum, minSupplyShare[i]);

	return getWeight(gdp, i) * min(supplyShare, maxSupplyShare[i]);
}

float goodsType::getPurchaseWeight(float input, float output, float msSum, float gdp, int i) const {
	float supplyShare = minSupplyShare[i];
	if (msSum == 0) {
		if (bold[i]) supplyShare = 1;
	}
	else supplyShare = max(getMarketShare(input, output, i) / msSum, minSupplyShare[i]);

	return getWeight(gdp, i) * min(supplyShare, maxSupplyShare[i]);
}

float goodsType::getLocalPurchaseWeight(float msSum, float gdp, int i) const {
	float supplyShare = minSupplyShare[i];
	if (msSum == 0) {
		if (bold[i]) supplyShare = 1;
	}
	else supplyShare = max(getMarketShare(i) / msSum, minSupplyShare[i]);

	return getLocalWeight(gdp, i) * min(supplyShare, maxSupplyShare[i]);
}

float goodsType::getLocalPurchaseWeight(float output, float msSum, float gdp, int i) const {
	float supplyShare = minSupplyShare[i];
	if (msSum == 0) {
		if (bold[i]) supplyShare = 1;
	}
	else supplyShare = max(getLocalMarketShare(output, i) / msSum, minSupplyShare[i]);

	return getLocalWeight(gdp, i) * min(supplyShare, maxSupplyShare[i]);
}

float goodsType::getLocalPurchaseWeight(float input, float output, float msSum, float gdp, int i) const {
	float supplyShare = minSupplyShare[i];
	if (msSum == 0) {
		if (bold[i]) supplyShare = 1;
	}
	else supplyShare = max(getMarketShare(input, output, i) / msSum, minSupplyShare[i]);

	return getLocalWeight(gdp, i) * min(supplyShare, maxSupplyShare[i]);
}

float goodsType::getMarketPricePercent() const {
	float input = buy;
	float output = sell;
	if (localGood()) {
		input = consumption;
		output = production;
	}
	float percent = -1;
	if (name == "Gold") percent = 0;
	else if (output == 0) {
		if (input == 0) percent = 0;
		else percent = 1;
	}
	else if (input != 0) {
		percent = (input - output) / min(input, output);
		if (percent < -1) percent = -1;
		else if (percent > 1) percent = 1;
	}

	return percent * 0.75;
}

float goodsType::getMarketPricePercent(float output) const {
	float input = buy;
	if (localGood()) input = consumption;
	float percent = -1;
	if (name == "Gold") percent = 0;
	else if (output == 0) {
		if (input == 0) percent = 0;
		else percent = 1;
	}
	else if (input != 0) {
		percent = (input - output) / min(input, output);
		if (percent < -1) percent = -1;
		else if (percent > 1) percent = 1;
	}

	return percent * 0.75;
}

float goodsType::getMarketPricePercent(float input, float output) const {
	if (localGood()) {
		input += consumption;
		output += production;
	}
	else {
		input += buy;
		output += sell;
	}
	float percent = -1;
	if (name == "Gold") percent = 0;
	else if (output == 0) {
		if (input == 0) percent = 0;
		else percent = 1;
	}
	else if (input != 0) {
		percent = (input - output) / min(input, output);
		if (percent < -1) percent = -1;
		else if (percent > 1) percent = 1;
	}

	return percent * 0.75;
}

float goodsType::getMarketPrice() const {
	return price * (1 + getMarketPricePercent());
}

float goodsType::getMarketPrice(float output) const {
	return price * (1 + getMarketPricePercent(output));
}

float goodsType::getMarketPrice(float input, float output) const {
	return price * (1 + getMarketPricePercent(input, output));
}

float goodsType::getMarketPricePercentPrediction(float purchaseWeight) const {
	float input = buy + getPopConsumptionChange(purchaseWeight);
	float output = sell;
	if (localGood()) {
		input = consumption + getLocalPopConsumptionChange(purchaseWeight);
		output = production;
	}
	float percent = -1;
	if (name == "Gold") percent = 0;
	else if (output == 0) {
		if (input == 0) percent = 0;
		else percent = 1;
	}
	else if (input != 0) {
		percent = (input - output) / min(input, output);
		if (percent < -1) percent = -1;
		else if (percent > 1) percent = 1;
	}

	return percent * 0.75;
}

float goodsType::getMarketPricePercentPrediction(float output, float purchaseWeight) const {
	float input = buy + getPopConsumptionChange(purchaseWeight);
	if (localGood()) input = consumption + getLocalPopConsumptionChange(purchaseWeight);
	float percent = -1;
	if (name == "Gold") percent = 0;
	else if (output == 0) {
		if (input == 0) percent = 0;
		else percent = 1;
	}
	else if (input != 0) {
		percent = (input - output) / min(input, output);
		if (percent < -1) percent = -1;
		else if (percent > 1) percent = 1;
	}

	return percent * 0.75;
}

float goodsType::getMarketPricePercentPrediction(float input, float output, float purchaseWeight) const {
	if (localGood()) {
		input += consumption + getLocalPopConsumptionChange(purchaseWeight);
		output += production;
	}
	else {
		input += buy + getPopConsumptionChange(purchaseWeight);
		output += sell;
	}
	float percent = -1;
	if (name == "Gold") percent = 0;
	else if (output == 0) {
		if (input == 0) percent = 0;
		else percent = 1;
	}
	else if (input != 0) {
		percent = (input - output) / min(input, output);
		if (percent < -1) percent = -1;
		else if (percent > 1) percent = 1;
	}

	return percent * 0.75;
}

float goodsType::getMarketPricePrediction(float purchaseWeight) const {
	return price * (1 + getMarketPricePercentPrediction(purchaseWeight));
}

float goodsType::getMarketPricePrediction(float output, float purchaseWeight) const {
	return price * (1 + getMarketPricePercentPrediction(output, purchaseWeight));
}

float goodsType::getMarketPricePrediction(float input, float output, float purchaseWeight) const {
	return price * (1 + getMarketPricePercentPrediction(input, output, purchaseWeight));
}

float goodsType::getLocalPrice(float mapi) const {
	float percent = -1;
	if (name == "Gold") percent = 0;
	else if (production == 0) {
		if (consumption == 0) percent = 0;
		else percent = 1;
	}
	else if (consumption != 0) {
		percent = (consumption - production) / min(consumption, production);
		if (percent < -1) percent = -1;
		else if (percent > 1) percent = 1;
	}
	percent *= 0.75;

	return mapi * getMarketPrice() + (1 - mapi) * price * (1 + percent);
}

float goodsType::getLocalPrice(float mapi, float output) const {
	float percent = -1;
	if (name == "Gold") percent = 0;
	else if (output == 0) {
		if (consumption == 0) percent = 0;
		else percent = 1;
	}
	else if (consumption != 0) {
		percent = (consumption - output) / min(consumption, output);
		if (percent < -1) percent = -1;
		else if (percent > 1) percent = 1;
	}
	percent *= 0.75;

	return mapi * getMarketPrice(output - production + sell) + (1 - mapi) * price * (1 + percent);
}

float goodsType::getLocalPrice(float mapi, float marketInput, float marketOutput) const {
	float input = marketInput + consumption;
	float output = marketOutput + production;
	float percent = -1;
	if (name == "Gold") percent = 0;
	else if (output == 0) {
		if (input == 0) percent = 0;
		else percent = 1;
	}
	else if (input != 0) {
		percent = (input - output) / min(input, output);
		if (percent < -1) percent = -1;
		else if (percent > 1) percent = 1;
	}
	percent *= 0.75;

	return mapi * getMarketPrice(marketInput, marketOutput) + (1 - mapi) * price * (1 + percent);
}

float goodsType::getLocalPriceImportsCanceled(float mapi, float marketInput, float marketOutput) const {
	float input = marketInput + consumption;
	float output = marketOutput + production;
	float percent = -1;
	if (name == "Gold") percent = 0;
	else if (output == 0) {
		if (input == 0) percent = 0;
		else percent = 1;
	}
	else if (input != 0) {
		percent = (input - output) / min(input, output);
		if (percent < -1) percent = -1;
		else if (percent > 1) percent = 1;
	}
	percent *= 0.75;

	return mapi * getMarketPrice(marketInput, marketOutput - imports) + (1 - mapi) * price * (1 + percent);
}

float goodsType::getLocalPricePercent(float mapi) const {
	return (getLocalPrice(mapi) - price) / price;
}

float goodsType::getLocalPricePercent(float mapi, float output) const {
	return (getLocalPrice(mapi, output) - price) / price;
}

float goodsType::getLocalPricePercent(float mapi, float marketInput, float marketOutput) const {
	return (getLocalPrice(mapi, marketInput, marketOutput) - price) / price;
}

float goodsType::getLocalPricePercentImportsCanceled(float mapi, float marketInput, float marketOutput) const {
	return (getLocalPriceImportsCanceled(mapi, marketInput, marketOutput) - price) / price;
}

float goodsType::getLocalPricePrediction(float mapi, float purchaseWeight, float localPurchaseWeight) const {
	float input = consumption + getLocalPopConsumptionChange(localPurchaseWeight);
	float percent = -1;
	if (name == "Gold") percent = 0;
	else if (production == 0) {
		if (input == 0) percent = 0;
		else percent = 1;
	}
	else if (input != 0) {
		percent = (input - production) / min(input, production);
		if (percent < -1) percent = -1;
		else if (percent > 1) percent = 1;
	}
	percent *= 0.75;

	return mapi * getMarketPricePrediction(purchaseWeight) + (1 - mapi) * price * (1 + percent);
}

float goodsType::getLocalPricePrediction(float mapi, float output, float purchaseWeight, float localPurchaseWeight) const {
	float input = consumption + getLocalPopConsumptionChange(localPurchaseWeight);
	float percent = -1;
	if (name == "Gold") percent = 0;
	else if (output == 0) {
		if (input == 0) percent = 0;
		else percent = 1;
	}
	else if (input != 0) {
		percent = (input - output) / min(input, output);
		if (percent < -1) percent = -1;
		else if (percent > 1) percent = 1;
	}
	percent *= 0.75;

	return mapi * getMarketPricePrediction(output - production + sell, purchaseWeight) + (1 - mapi) * price * (1 + percent);
}

float goodsType::getLocalPricePrediction(float mapi, float marketInput, float marketOutput, float purchaseWeight, float localPurchaseWeight) const {
	float input = marketInput + consumption + getLocalPopConsumptionChange(localPurchaseWeight);
	float output = marketOutput + production;
	float percent = -1;
	if (name == "Gold") percent = 0;
	else if (output == 0) {
		if (input == 0) percent = 0;
		else percent = 1;
	}
	else if (input != 0) {
		percent = (input - output) / min(input, output);
		if (percent < -1) percent = -1;
		else if (percent > 1) percent = 1;
	}
	percent *= 0.75;

	return mapi * getMarketPricePrediction(marketInput, marketOutput, purchaseWeight) + (1 - mapi) * price * (1 + percent);
}

float goodsType::getLocalPricePredictionImportsCanceled(float mapi, float marketInput, float marketOutput, float purchaseWeight, float localPurchaseWeight) const {
	float input = marketInput + consumption + getLocalPopConsumptionChange(localPurchaseWeight);
	float output = marketOutput + production;
	float percent = -1;
	if (name == "Gold") percent = 0;
	else if (output == 0) {
		if (input == 0) percent = 0;
		else percent = 1;
	}
	else if (input != 0) {
		percent = (input - output) / min(input, output);
		if (percent < -1) percent = -1;
		else if (percent > 1) percent = 1;
	}
	percent *= 0.75;

	return mapi * getMarketPricePrediction(marketInput, marketOutput - imports, purchaseWeight) + (1 - mapi) * price * (1 + percent);
}

float goodsType::getLocalPricePercentPrediction(float mapi, float purchaseWeight, float localPurchaseWeight) const {
	return (getLocalPricePrediction(mapi, purchaseWeight, localPurchaseWeight) - price) / price;
}

float goodsType::getLocalPricePercentPrediction(float mapi, float output, float purchaseWeight, float localPurchaseWeight) const {
	return (getLocalPricePrediction(mapi, output, purchaseWeight, localPurchaseWeight) - price) / price;
}

float goodsType::getLocalPricePercentPrediction(float mapi, float marketInput, float marketOutput, float purchaseWeight, float localPurchaseWeight) const {
	return (getLocalPricePrediction(mapi, marketInput, marketOutput, purchaseWeight, localPurchaseWeight) - price) / price;
}

float goodsType::getLocalPricePercentPredictionImportsCanceled(float mapi, float marketInput, float marketOutput, float purchaseWeight, float localPurchaseWeight) const {
	return (getLocalPricePredictionImportsCanceled(mapi, marketInput, marketOutput, purchaseWeight, localPurchaseWeight) - price) / price;
}

bool goodsType::hasWeight() const {
	for (int i = 0; i < NSIZE; i++) {
		if (weight[i] > 0) return true;
	}
	return false;
}

bool goodsType::localGood() const {
	if (name == "Electricity" || name == "Services" || name == "Transportation") return true;
	return false;
}

bool goodsType::tradable() const {
	if (localGood() || name == "Gold") return false;
	return true;
}

bool goodsType::militaryGood() const {
	if (name == "Ammunition" || name == "Artillery" || name == "Oil" || name == "Radios" || name == "Small Arms" || name == "Tanks") return true;
	return false;
}