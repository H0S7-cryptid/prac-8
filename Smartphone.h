#ifndef SMARTPHONE
#define SMARTPHONE

#include "Price.h"

using namespace std;

class Smartphone {
private:
	string model;
	Manufacturer manufacturer;
	Color color;
	short ram;
	short storage;
	Manufacturer cpu;
	Os os;
	Protection protection;
	float display;
	short ncams;
	Price price;
public:
	// Конструкторы класса
	Smartphone();
	Smartphone(string model, double price, Manufacturer manufacturer, Color color, float display, short ram,
		short storage, Manufacturer cpu, Os os, short ncams, Protection protection, Mtype currency);

	// Оператор присваивания
	Smartphone& operator=(const Smartphone& other);

	// Геттеры
	string getModel() const;
	Color getColor() const;
	Manufacturer getCPU() const;
	float getDisplay() const;
	Manufacturer getManufacturer() const;
	Os getOS() const;
	Price getPrice() const;
	short getRAM() const;
	short getStorage() const;
	Protection getProtection() const;
	short getNCams() const;

	// Вывод информации о телефоне в поток
	void Print() const;

	// Установка цены, с возможностью перевода 
	void setPrice(double c, Mtype def = RUB);
};

#endif
