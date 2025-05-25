#include "Smartphone.h"
#include "Price.h"

Smartphone::Smartphone() {
	model = "";
	manufacturer = UNDEFM;
	display = 1;
	storage = 1;
	os = UNDEFO;
	price.setPrice(0);
	price.setCurrency(USD);
	color = UNDEFC;
	ram = 1;
	cpu = UNDEFM;
	protection = UNDEFP;
	ncams = 0;
}

Smartphone::Smartphone(string model, double price, Manufacturer manufacturer,
	Color color, float display, short ram,
	short storage, Manufacturer cpu, Os os, short ncams, Protection protection) {
	this->model = model;
	this->price. = price;
	this->manufacturer = manufacturer;
	this->color = color;
	this->display = display;
	this->ram = ram;
	this->storage = storage;
	this->cpu = cpu;
	this->os = os;
	this->protection = protection;
	this->ncams = ncams;
}

Smartphone& Smartphone::operator=(const Smartphone& other) {
	if (this != &other) {
		model = other.model;
		price = other.price;
		manufacturer = other.manufacturer;
		color = other.color;
		display = other.display;
		ram = other.ram;
		storage = other.storage;
		cpu = other.cpu;
		os = other.os;
		ncams = other.ncams;
		protection = other.protection;
	}
	return *this;
}

string Smartphone::getModel() const {
	return model;
}

Color Smartphone::getColor() const {
	return color;
}

Manufacturer Smartphone::Smartphone::getCPU() const {
	return cpu;
}

float Smartphone::getDisplay() const {
	return display;
}

Manufacturer Smartphone::getManufacturer() const {
	return manufacturer;
}

Os Smartphone::getOS() const {
	return os;
}

Price Smartphone::getPrice() const {
	return price;
}

short Smartphone::getRAM() const {
	return ram;
}

short Smartphone::getStorage() const {
	return storage;
}

Protection Smartphone::getProtection() const {
	return protection;
}

short Smartphone::getNCams() const {
	return ncams;
}

void Smartphone::setPrice(double c, Mtype def = USD) {
	price.setPrice(c);
	price.setCurrency(def);
}

void Smartphone::Print() const {
	cout << ManufacturerNames[manufacturer] << endl;
	cout << model << endl;
	cout << "Price: " << price.getAmount() << MtypeNames[price.getCurrency()] << endl;
	cout << "Color: " << ColorNames[color] << endl;
	cout << "Display: " << display << endl;
	cout << "OS: " << OsNames[os] << std::endl;
	cout << ram << "Gb RAM, " << storage << " GB storage" << endl;
	cout << "CPU: " << ManufacturerNames[cpu] << endl;
	std::cout << "Protection: " << ProtHave[protection] << std::endl;
	std::cout << "Number of Cameras: " << ncams << endl;
	cout << endl;
}
