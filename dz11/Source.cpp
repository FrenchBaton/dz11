#include<iostream>
using namespace std;

const char* PATH = "data.bin";
const char* MODE = "ab+";

struct Fraction
{
	int numberator;
	int denominator;
};

void writeFractionsCounts(unsigned int& n) {
	do {
		cout << "counts of fractions: ";
		cin >> n;
	} while (n == 0);
}

Fraction* writeFractions(unsigned int& n) {
	writeFractionsCounts(n);
	Fraction* fr = new Fraction[n];
	for (int i = 0; i < n; i++) {
		cout << "numb: ";
		cin >> fr[i].numberator;
		cout << "denom: ";
		cin >> fr[i].denominator;
	}
	return fr;
}

void showFractions(Fraction*& arr, const unsigned int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i].numberator << "/" << arr[i].denominator << "\n";
	}
}

void fileFuncShow(FILE*& file, Fraction*& arr, const unsigned int n) {
	if (fopen_s(&file, PATH, MODE) == 0) {
		Fraction* temp = new Fraction[n];
		fread(&temp, sizeof(Fraction), n, file);
		showFractions(temp, n);
		delete[] temp;
	}
}

void fileFuncWrite(FILE*& file, Fraction*& arr, const unsigned int n) {
	if (fopen_s(&file, PATH, MODE) == 0) {
		fwrite(&arr, sizeof(Fraction), n, file);
		fseek(file, 0, SEEK_SET);
	}
}

void end(FILE*& file, Fraction*& arr) {
	if (fopen_s(&file, PATH, MODE) == 0) {
		fclose(file);
	}
	remove(PATH);
	delete[] arr;
}

int main() {
	FILE* file;
	Fraction* arr;
	unsigned int n = 0;

	arr = writeFractions(n);
	fileFuncWrite(file, arr, n);
	cout << "\n";
	fileFuncShow(file, arr, n);

	showFractions(arr, n);
	
	
	end(file, arr);

	return 0;
}