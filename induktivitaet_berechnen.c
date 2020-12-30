// Programm zur Berechnung der Selbstinduktivität einer zylinderförmigen Luftspule im Vakuum
// Autor: Fabian Prestros
// Datum: 30.12.2020
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

double einlesen_double(char koef)
{
	int chk = 0;
	double zahl = 0;

	do													// In einer Schleife einlesen, bis eine korrekte Zahl eingelesen wurde
	{
		printf("%c = ", koef);
		chk = scanf_s("%lf", &zahl);
		while (getchar() != '\n');						// Tastaturpuffer leeren.
		if (chk == 0)									// Fehlermeldung, wenn scanf_s meldet, dass keine Ganze Zahl eingegeben wurde
			printf("Bite geben Sie eine Zahl ein!\n");
	} while (chk == 0);									// Schleifendurchlauf, bis kein Fehler mehr vorliegt.

	return zahl;
}

unsigned int einlesen_int(char koef)
{
	int chk = 0;
	unsigned int zahl = 0;

	do													// In einer Schleife einlesen, bis eine korrekte Zahl eingelesen wurde
	{
		printf("%c = ", koef);
		chk = scanf_s("%d", &zahl);
		while (getchar() != '\n');						// Tastaturpuffer leeren.
		if (chk == 0)									// Fehlermeldung, wenn scanf_s meldet, dass keine Ganze Zahl eingegeben wurde
			printf("Bite geben Sie eine ganze Zahl ein!\n");
	} while (chk == 0);									// Schleifendurchlauf, bis kein Fehler mehr vorliegt.

	return zahl;
}

double induktivitaet_berechnen(double d, double l, unsigned int N)
{
	double L = 0;
	double r = 0;

	r = d / 2;

	// Selbstinduktivitätsformel laut H. A. Wheeler: Simple Inductance Formulas for Radio Coils. In: Proceedings of the Institute of Radio Engineers. Band 16, Nr. 10, 1928, S. 1398–1400
	L = ((4 * PI * 1E-7) * pow(N * r, 2) * PI) / (l + 0.9 * r);

	return L;
}

int main()
{
	double d = 0;
	double l = 0;
	unsigned int N = 0;
	double L = 0;

	printf("Bitte Spulenlänge l und Durchmesser d in mm eingeben (Windungszahl n ist dimensionslos):\n");
	d = einlesen_double('d');
	l = einlesen_double('l');
	N = einlesen_int('N');
	L = induktivitaet_berechnen(d, l, N);

	if (l < (0.4 * d))
		printf("Warnung: Diese Formel hat f\x81r l < 0.4*d mehr als 1%% Fehler!\n");

	printf("L = %.2lf nH\n", L * 1E6);
}