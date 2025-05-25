#include"Catalog.h"
using namespace std;

Catalog InitializeCatalog() {
	Catalog catalog;
	Smartphone samePhoneToSearch{ "Apple 12 pro", 74999.99, Apple, White, 6, 3, 128, Apple, iOS, 3, YES };

	catalog.addSmartphone("Apple 10 pro", 29999.99, Apple, Black, 4, 3, 64, Apple, iOS, 2, NO);
	catalog.addSmartphone(samePhoneToSearch);

	return catalog;
}

int main(int argc, char* argv[]) {
	Catalog catalog = InitializeCatalog();

	Smartphone whatBuyerLikes{ "Apple 12 Pro", 0, Apple, (Color)0, 0, 0, 0, (Manufacturer)0, (Os)0, 0, (Protection)0 };

	vector<Smartphone> Selected;

	Selected = catalog.search(whatBuyerLikes);

	if (!Selected.empty())
	{
		cout << "You might like theese: " << endl;
		for (const Smartphone& item : Selected) {
			item.Print();
		}
	}
	return 0;
}
