#pragma once
#include "Bibliotekos.h"

class Mokiniai {
private:
	string pavarde;
	vector<int> pazymiai;
	double galutinis;
public:
	string vardas;
	Mokiniai();
	Mokiniai(const Mokiniai& p1);
	Mokiniai(string, string, vector<int>, double);
	~Mokiniai();
	int Pagrindinis();
	void TrintiPazymius();
	void SpausdintiMediana();
	void SpausdintiFaila();

	friend istream& operator >>(istream& input, Mokiniai& x);
	friend ostream& operator <<(ostream& output, const Mokiniai& x);
};

int wordnum(string);