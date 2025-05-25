#include "Price.h"

Price::Price(double a = 0.0, const Mtype& c = USD) : price(a), currency(c) {
    setPrice(a);
    currency = c;
}

void Price::doPrice(double price) {
    if (price > 4000000 || price < 0) throw std::exception("Incorrect price value!");
    this->price = 0;
}

void Price::setPrice(double price) {
    try {
        doPrice(price);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return;
    }
    this->price = price;
}

void Price::setCurrency(Mtype mtype) {
    currency = mtype;
}

double Price::getAmount() const {
    return price;
}

Mtype Price::getCurrency() const {
    return currency;
}

Price Price::convertTo(const Mtype& newCurrency, double exchangeRate) const {
    return Price(price * exchangeRate, newCurrency);
}

void Price::print() const {
    std::cout << price << " " << MtypeName[currency] << std::endl;
}
