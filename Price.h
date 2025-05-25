#pragma once
#include "NEEDED_LIB.h"

enum Mtype { USD = 0, EUR, RUB };
std::map <Mtype, std::string> MtypeName = {
	{USD, "USD"},
	{EUR, "EUR"},
	{RUB, "RUB"}
};

class Price {
private:
	double price;
	Mtype currency;
	void doPrice(double price);
public:
	Price(double a, const Mtype& c);
	void setPrice(double price);
	void setCurrency(Mtype mtype = USD);
	double getAmount() const;
	Mtype getCurrency() const;
	Price convertTo(const Mtype& newCurrency, double exchangeRate) const;
	void print() const;
};
