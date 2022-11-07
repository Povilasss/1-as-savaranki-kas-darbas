#include "class.h"

Mokiniai::Mokiniai() {
	vardas = "Nulis";
	pavarde = "Nulis";
	galutinis = 1;
};

Mokiniai::Mokiniai(string xvardas, string xpavarde, vector<int>xpazymiai, double xgalutinis) {
	vardas = xvardas;
	pavarde = xpavarde;
	pazymiai = xpazymiai;
	galutinis = xgalutinis;
};

Mokiniai::~Mokiniai() {
	pazymiai.clear();
};

Mokiniai::Mokiniai(const Mokiniai& p1) {
	vardas = p1.vardas;
	pavarde = p1.pavarde;
	pazymiai = p1.pazymiai;
	galutinis = p1.galutinis;
};

void Mokiniai::TrintiPazymius() {
	pazymiai.clear();
};

int Mokiniai::Pagrindinis() {
	int vest;
	cout << "              Pagrindinis               " << endl;
	cout << "----------------------------------------" << endl;
	cout << "1 = Vesti mokinio duomenis" << endl;
	cout << "2 = Nuskaityti mokinio duomenis ir isvesti vidurki" << endl;
	cout << "3 = Nuskaityti mokinio duomenis ir isvesti mediana" << endl;
	cout << "4 = Nuskaityti duomenis is failo ir surusiuoti pagal vardus " << endl;
	cout << "5 = Iseiti " << endl;
	cin >> vest;
	system("CLS");
	return vest;
};

void Mokiniai::SpausdintiMediana() {
	double math = accumulate(pazymiai.begin(), pazymiai.end(), 0.0) / pazymiai.size();
	double givert = (0.4 * math) + (0.6 * galutinis);
	nth_element(pazymiai.begin(), pazymiai.begin() + pazymiai.size() / 2, pazymiai.end());
	cout << left << setw(15) << pavarde << left << setw(15) << vardas << setprecision(2) << givert << "/" << "(" << pazymiai[pazymiai.size() / 2] << ")" << endl;
}

void Mokiniai::SpausdintiFaila() {
	double math = accumulate(pazymiai.begin(), pazymiai.end(), 0.0) / pazymiai.size();
	double givert = (0.4 * math) + (0.6 * galutinis);
	nth_element(pazymiai.begin(), pazymiai.begin() + pazymiai.size() / 2, pazymiai.end());
	cout << left << setw(15) << pavarde << left << setw(15) << vardas << setprecision(2) << givert << "/" << setprecision(2) << "(" << math << ")" << "(" << pazymiai[pazymiai.size() / 2] << ")" << endl;
};

istream& operator >> (istream& input, Mokiniai& x) {
	int vest;
	cout << "             Prideti mokini             " << endl;
	cout << "----------------------------------------" << endl;
	cout << " Mokinio vardas : ";
	cin >> x.vardas;
	cout << " Mokinio pavarde : ";
	cin >> x.pavarde;
	cout << "----------------------------------------" << endl;
	cout << "Iveskite pazymius, po kiekvieno pazymio spausti ENTER, spausti 0 norint baigti" << endl;

	cin >> vest;
	while (vest != 0) {
		if (vest == 1) {
			for (int i = 0; i < 10; i++) {
				int random = rand() % 10 + 1;
				x.pazymiai.push_back(random);
			}
			int random = rand() % 10 + 1;
			x.galutinis = random;
			return input;
		}
		else if (vest > 10 or vest < 0) {
			cout << "KLAIDA !!! , IVESKITE SKAICIU NUO 0 IKI 10 !!! " << endl;
			cin >> vest;
		}
		else {
			x.pazymiai.push_back(vest);
			cout << "---" << endl;
			cin >> vest;
		}

	};
	cout << endl << "Iveskite egzamino pazymi :";
	cin >> x.galutinis;
	system("CLS");
	cout << "Mokinio duomeys issaugoti" << endl;
	return input;
};

ostream& operator << (ostream& output, const Mokiniai& x) {
	double math = accumulate(x.pazymiai.begin(), x.pazymiai.end(), 0.0) / x.pazymiai.size();
	double givert = (0.4 * math) + (0.6 * x.galutinis);
	cout << left << setw(15) << x.pavarde << left << setw(15) << x.vardas << setprecision(2) << givert << "/" << setprecision(2) << "(" << math << ")" << endl;
	return output;
};

int wordnum(string wordnume) {
	int countinger = 0;
	string word;
	stringstream strm(wordnume);

	while (strm >> word) {
		++countinger;
	};
	return countinger;
};

