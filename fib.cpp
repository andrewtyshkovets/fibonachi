#include "fib.h"
#include <iostream>

using namespace std;

void fib() {}

int addArr(int* m, int* n, int len1, int len2) {
	int len3;
	if (len1 > len2) {
		len3 = len1;
	}
	else {
		len3 = len2;
	}
	for (int i = 0; i < len3; i++)
	{
		m[i] = m[i] + n[i];
		if (m[i] >= 1000) {
			m[i] = m[i] - 1000;
			m[i + 1] = m[i + 1] + 1;
		}
	}
	if (m[len3] > 0) {
		len3++;
	}
	return len3;
}
int mulArr(int* m, int* n, int len1, int len2) {
	int len3 = len1 + len2;
	int* mult = new int[len3];
	for (int i = 0; i < len3; i++)
	{
		mult[i] = 0;
	}

	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			mult[i + j] = mult[i + j] + m[i] * n[j];
		}
	}
	int temp = 0;
	for (int i = 0; i < len3 - 1; i++)
	{

		if (mult[i] >= 1000) {
			temp = mult[i] / 1000;
			mult[i] = mult[i] % 1000;
			mult[i + 1] = mult[i + 1] + temp;
		}

	}
	for (int i = 0; i < len3; i++)
	{
		m[i] = mult[i];

	}
	int count = 0;
	for (int i = len3; i > 0; i--)
	{
		if (m[i] == 0) {
			count++;
		}
		else break;
	}
	len3 = len3 - count + 1;
	return len3;
}
void fib(int t1, int t2, int n)
{
	int* mas = new int[50000];
	mas[0] = t1;
	int* mas1 = new int[50000];
	mas1[0] = t2;
	int* mas2 = new int[50000];
	int mult = 1;
	int summ = 1;
	int tempo = 0;
	for (int i = 1; i < 50000; i++)
	{
		mas[i] = 0;
		mas1[i] = 0;
		mas2[i] = 0;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < summ; j++)
		{
			mas2[j] = mas1[j];
		}
		mult = mulArr(mas1, mas1, mult, mult);;

		summ = addArr(mas, mas1, summ, mult);
		for (int j = 0; j < summ; j++)
		{
			tempo = mas2[j];
			mas1[j] = mas[j];
			mas[j] = tempo;
		}
	}
	cout << "You have entered " << t1 << " " << t2 << " " << n << endl;
	cout << "result is: ";
	for (int i = 0; i < summ; i++) {
		printf("%0.3d\ ", mas1[i]);
	}
}


int main() {
	int t1 = 0;
	int t2 = 1;
	int z = 6;

	fib(t1, t2, z);


	return 0;
}