#pragma once

#include "Price.h"

using namespace std;

enum Manufacturer { Apple = 0, Samsung, Xiaomi, Oppo, Honor, Huawei, UNDEFM = -1 };
enum Color { Black = 0, White, Red, Violet, Gray, LightPink, Pink, UNDEFC = -1 };
enum Os { iOS = 0, Android, UNDEFO = -1 };
enum Protection { YES = 1, NO = -1, UNDEFP = 0 };

map <Manufacturer, string> ManufacturerNames = {
	{Apple, "Apple"},
	{Samsung, "Samsung"},
	{Xiaomi, "Xiaomi"},
	{Oppo, "Oppo"},
	{Honor, "Honor"},
	{Huawei, "Huawei"}
};
map <Color, string> ColorNames = {
	{Black, "Black"},
	{White, "White"},
	{Red, "Red"},
	{Violet, "Violet"},
	{Gray, "Gray"},
	{LightPink, "LightPink"},
	{Pink, "Pink"}
};
map <Os, string> OsNames = {
	{iOS, "iOS"},
	{Android, "Android"}
};
map <Protection, string> ProtHave = {
	{YES, "YES"},
	{ NO, "NO" }
};


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
	Smartphone();
	Smartphone(string model, double price, Manufacturer manufacturer,
		Color color, float display, short ram,
		short storage, Manufacturer cpu, Os os, short ncams, Protection protection);
	Smartphone& operator=(const Smartphone& other);
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
	void Print() const;
	void setPrice(double c, Mtype def = USD);
};
