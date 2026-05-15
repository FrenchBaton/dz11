#include<iostream>
using namespace std;

//struct Point
//{
//	int x;
//	int y;
//};

struct Fraction
{
	int numberator;
	int denominator;
};

int main() {
	const char* path = "data.bin";
	const char* mode = "ab+";

	unsigned int n = 1;
	cout << "counts: ";
	cin >> n;
	//if(n > 0){}
	Fraction* arr = new Fraction[n];
	for (int i = 0; i < n; i++) {
		cout << "numb: ";
		cin >> arr[i].numberator;
		cout << "denom: ";
		cin >> arr[i].denominator;
	}

	FILE* file;
	if (fopen_s(&file, path, mode) == 0) {
		fwrite(&arr, sizeof(Fraction), n, file);
		fseek(file, 0, SEEK_SET);
		Fraction* temp = new Fraction[n];
		fread(&temp, sizeof(Fraction), n, file);
		for (int i = 0; i < n; i++) {
			cout << temp[i].numberator << "/" << temp[i].denominator << "\n";
		}
		delete[] temp;
		fclose(file);
	}
	remove(path);
	delete[] arr;

	return 0;
}