#include "Bibliotekos.h"
#include "class.h"

int main()
{
	vector<Mokiniai> sarasas;
	vector<int> givert = { 0 };
	Mokiniai moksl;
	int sansas = 0;
	int laikinas = 0;
	sansas = moksl.Pagrindinis();
	while (sansas != 0) {
		try {
			if (sansas < 0 or sansas > 5) {
				throw 404;
			};
			while (sansas == 1) {
				cin >> moksl;
				sarasas.push_back(moksl);
				moksl.TrintiPazymius();
				system("CLS");
				cout << "   Mokinys pridetas   " << endl;
				cout << endl << " 1 = Prideti kita mokini : " << endl;
				cout << " 2 = Grizti i pagrindini : " << endl;
				cin >> laikinas;
				if (laikinas == 2) { system("CLS"); sansas = moksl.Pagrindinis(); };
				system("CLS");
			};
			while (sansas == 2) {
				cout << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis(Vid.)" << endl;
				cout << "---------------------------------------------" << endl;
				for (int i = 0; i < sarasas.size(); i++) { cout << sarasas[i]; }
				cout << "---------------------------------------------" << endl;
				cout << endl << "1 = Grizti i pagrindini" << endl;
				cin >> laikinas;
				if (laikinas == 1) { system("CLS"); sansas = moksl.Pagrindinis(); };
			};
			while (sansas == 3) {
				cout << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis(Med.)" << endl;
				cout << "---------------------------------------------" << endl;
				for (int i = 0; i < sarasas.size(); i++) { sarasas[i].SpausdintiMediana(); }
				cout << "---------------------------------------------" << endl;
				cout << endl << "1 = Grizti i pagrindini" << endl;
				cin >> laikinas;
				if (laikinas == 1) { system("CLS"); sansas = moksl.Pagrindinis(); };
			};
			while (sansas == 4) {
				static int checked = 0;
				if (checked == 0) {
					ifstream datafile;
					datafile.open("kursiokai.txt");
					string str = "null", fvardas = "null", fpavarde = "null";
					double rez = 0;
					string arr[50];
					getline(datafile, str);
					int counter = wordnum(str);
					while (datafile.peek() != EOF) {
						getline(datafile, str);
						stringstream ss(str);
						for (int i = 0; i < counter; i++) {
							ss >> arr[i];
							if (i == 0) { fvardas = arr[i]; }
							else if (i == 1) { fpavarde = arr[i]; }
							else if (i > 1 and i + 1 < counter) { givert.push_back(stoi(arr[i])); }
							else if (i + 1 == counter) { rez = stoi(arr[i]); }
						};
						Mokiniai fmoksl(fvardas, fpavarde, givert, rez);
						sarasas.push_back(fmoksl);
						givert.clear();
					};
					checked++;
					sort(sarasas.begin(), sarasas.end(), [](const Mokiniai& lhs, const Mokiniai& rhs) {return lhs.vardas < rhs.vardas; });
				};
				
				cout << "Pavarde" << setw(13) << "Vardas" << setw(25) << "Galutinis(vid/med)" << setw(15) << endl;
				cout << "---------------------------------------------" << endl;
				for (int i = 0; i < sarasas.size(); i++) { sarasas[i].SpausdintiFaila(); }
				cout << endl << "1 = Grizti i pagrindini" << endl;
				cin >> laikinas;
				if (laikinas == 1) { system("CLS"); sansas = moksl.Pagrindinis(); };
			}
			while (sansas == 5) { sansas = 0; };
		}
		catch (int ExceptionERR) {
			cout << "ERROR 404: Menu option does not exist" << endl;
			system("pause");
			system("CLS");
			sansas = moksl.Pagrindinis();
		};

	};
	return 0;
};


