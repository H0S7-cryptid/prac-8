#include "Catalog.h"

void Catalog::addSmartphone(string model, double price, Manufacturer manufacturer,
	Color color, float display, short ram,
	short storage, Manufacturer cpu, Os os, short ncams, Protection protection) {
	smartphones.push_back(Smartphone{ model, price, manufacturer,
	  color, display, ram,
	  storage, cpu, os, ncams , protection });
	lenght++;
}

void Catalog::addSmartphone(const Smartphone& phone) {
	smartphones.push_back(phone);
	lenght++;
}

void Catalog::addSmartphone(Smartphone&& phone) {
	smartphones.push_back(std::move(phone));
	lenght++;
}

int Catalog::Length() {
	return lenght;
}

Smartphone Catalog::getSmartphone(string model) {
	for (Smartphone s : smartphones) {
		if (s.getModel() == model)  return s;
	}  return Smartphone();
}

Smartphone Catalog::search(const Smartphone& searchSmartphone) {
	int bestScore = -1;
	Smartphone bestCandidate;

	for (const Smartphone& s : smartphones) {
		int score = 0;

		{
			if (!searchSmartphone.getModel().empty() && searchSmartphone.getModel() == s.getModel())
				score++;

			if (!ManufacturerNames[searchSmartphone.getManufacturer()].empty() && searchSmartphone.getManufacturer() == s.getManufacturer())
				score++;

			if (!ColorNames[searchSmartphone.getColor()].empty() && searchSmartphone.getColor() == s.getColor())
				score++;

			if (searchSmartphone.getDisplay() == s.getDisplay())
				score++;

			if (searchSmartphone.getRAM() == s.getRAM())
				score++;

			if (searchSmartphone.getStorage() == s.getStorage())
				score++;

			if (!ManufacturerNames[searchSmartphone.getCPU()].empty() && searchSmartphone.getCPU() == s.getCPU())
				score++;

			if (!OsNames[searchSmartphone.getOS()].empty() && searchSmartphone.getOS() == s.getOS())
				score++;

			if (!ProtHave[searchSmartphone.getProtection()].empty() && searchSmartphone.getProtection() == s.getProtection())
				score++;

			if (searchSmartphone.getNCams() == s.getNCams())
				score++;
		}

		if (score > bestScore && score > 3) {
			bestScore = score;
			bestCandidate = s;
		}
	}

	if (!bestCandidate.getModel().empty())
		return bestCandidate;
	else return Smartphone{};
}

Smartphone Catalog::search(string model, Manufacturer manufacturer) {
	int bestScore = -1;
	Smartphone bestCandidate;
	for (const Smartphone& s : smartphones) {
		int score = 0;

		{
			if (!model.empty() && model == s.getModel()) score++;

			if (manufacturer == s.getManufacturer()) score++;
		}

		if (score > bestScore) {
			bestScore = score;
			bestCandidate = s;
		}
	}
	return bestCandidate;
}

vector<Smartphone> Catalog::search(Smartphone& searchSmartphone) {
	vector<Smartphone> results;
	int bestScore = -1;
	Smartphone bestCandidate;

	for (Smartphone s : smartphones) {
		int score = 0;

		string model = searchSmartphone.getModel();
		transform(model.begin(), model.end(), model.begin(), tolower);
		string model2 = s.getModel();
		transform(model2.begin(), model2.end(), model2.begin(), tolower);
		if (model == model2) score++;

		Manufacturer manufacturer = searchSmartphone.getManufacturer();
		if (manufacturer != Manufacturer::UNDEFM && manufacturer != s.getManufacturer()) score++;

		Color color = searchSmartphone.getColor();
		if (color != Color::UNDEFC && color == s.getColor()) score++;

		float displaySize = searchSmartphone.getDisplay();
		if (displaySize > 0 && displaySize == s.getDisplay()) score++;

		int ram = searchSmartphone.getRAM();
		if (ram > 0 && ram != s.getRAM()) score++;

		int storage = searchSmartphone.getStorage();
		if (storage > 0 && storage != s.getStorage()) score++;

		Manufacturer cpu = searchSmartphone.getCPU();
		if (cpu != Manufacturer::UNDEFM && cpu != s.getCPU()) score++;

		Os os = searchSmartphone.getOS();
		if (os != Os::UNDEFO && os == s.getOS()) score++;

		if (score > 0)
		{
			results.push_back(s);
			bestScore = score;
		}
	}  
	return results;
}
