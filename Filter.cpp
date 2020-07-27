#include <iostream>
#include <string>
using namespace std;

struct Person {
	string nachname, vorname;
	int alter;
	char geschlecht;
};

Person personen[100] = {
{ "Musterfrau1", "Petra1", 18, 'w' },
{ "Mustermann1", "Klaus1", 18, 'm' },
{ "Mustermaedchen1", "Lisa1", 1, 'w' },
{ "Musterjunge1", "Jan1", 1, 'm' },
{ "Musterfrau2", "Petra2", 19, 'w' },
{ "Mustermann2", "Klaus2", 19, 'm' },
{ "Mustermaedchen2", "Lisa2", 2, 'w' },
{ "Musterjunge2", "Jan2", 2, 'm' },
{ "Musterfrau3", "Petra3", 20, 'w' },
{ "Mustermann3", "Klaus3", 20, 'm' },
{ "Mustermaedchen3", "Lisa3", 3, 'w' },
{ "Musterjunge3", "Jan3", 3, 'm' },
{ "Musterfrau4", "Petra4", 21, 'w' },
{ "Mustermann4", "Klaus4", 21, 'm' },
{ "Mustermaedchen4", "Lisa4", 4, 'w' },
{ "Musterjunge4", "Jan4", 4, 'm' },
{ "Musterfrau5", "Petra5", 22, 'w' },
{ "Mustermann5", "Klaus5", 22, 'm' },
{ "Mustermaedchen5", "Lisa5", 5, 'w' },
{ "Musterjunge5", "Jan5", 5, 'm' },
{ "Musterfrau6", "Petra6", 23, 'w' },
{ "Mustermann6", "Klaus6", 23, 'm' },
{ "Mustermaedchen6", "Lisa6", 6, 'w' },
{ "Musterjunge6", "Jan6", 6, 'm' },
{ "Musterfrau7", "Petra7", 24, 'w' },
{ "Mustermann7", "Klaus7", 24, 'm' },
{ "Mustermaedchen7", "Lisa7", 7, 'w' },
{ "Musterjunge7", "Jan7", 7, 'm' },
{ "Musterfrau8", "Petra8", 25, 'w' },
{ "Mustermann8", "Klaus8", 25, 'm' },
{ "Mustermaedchen8", "Lisa8", 8, 'w' },
{ "Musterjunge8", "Jan8", 8, 'm' }
};
int anzahl_personen = 32;

Person eingabe_person(int& Personennummer)
{
	Person p;
	Personennummer++;
	cout << "Bitte den Nachnamen der " << Personennummer << ". Person eingeben: ? ";
	cin >> p.nachname;
	cout << "Bitte den Vornamen der " << Personennummer << ". Person eingeben: ? ";
	cin >> p.vorname;
	cout << "Bitte das Alter der " << Personennummer << ". Person eingeben: ? ";
	cin >> p.alter;
	cout << "Bitte das Geschlecht der " << Personennummer << ". Person eingeben: ? ";
	cin >> p.geschlecht;
	return p;
}

void filter(Person(&personen)[100], int& anzahl_personen)
{
	int auswahl = 0, summe = 0;
	cout << "Ihre Auswahl:" << '\n'
		<< "1 - Weibliche Erwachsene" << '\n'
		<< "2 - Maennliche Erwachsene" << '\n'
		<< "3 - Weibliche Kinder" << '\n'
		<< "4 - Maennliche Kinder" << '\n'
		<< "? ";
	cin >> auswahl;
	for (int i = 0; i < anzahl_personen; i++)
	{
		if (auswahl ==1)
		{
			if (personen[i].alter >= 18 && personen[i].geschlecht == 'w')
			{
				cout << personen[i].nachname << ", " << personen[i].vorname << ", " << personen[i].geschlecht << ", " << personen[i].alter << '\n';
				summe++;
			}
		}
		else if (auswahl ==2)
		{
			if (personen[i].alter >= 18 && personen[i].geschlecht == 'm')
			{
				cout << personen[i].nachname << ", " << personen[i].vorname << ", " << personen[i].geschlecht << ", " << personen[i].alter << '\n';
				summe++;
			}
		}
		else if (auswahl == 3)
		{
			if (personen[i].alter < 18 && personen[i].geschlecht == 'w')
			{
				cout << personen[i].nachname << ", " << personen[i].vorname << ", " << personen[i].geschlecht << ", " << personen[i].alter << '\n';
				summe++;
			}
		}
		else if (auswahl == 4)
		{
			if (personen[i].alter < 18 && personen[i].geschlecht == 'm')
			{
				cout << personen[i].nachname << ", " << personen[i].vorname << ", " << personen[i].geschlecht << ", " << personen[i].alter << '\n';
				summe++;
			}
		}
		else
		{
			break;
		}
	}
	cout << "Summe: " << summe << '\n';
}

int main()
{
	char eingabe = ' ';
	do {
		cout << "Eine weitere Person eingeben (j/n)? ";
		cin >> eingabe;
		if (eingabe == 'j' || eingabe == 'J')
		{
			personen[anzahl_personen-1] = eingabe_person(anzahl_personen);
			//cout << "Vorname: " << personen[anzahl_personen-1].vorname << ", Nachname: " << personen[anzahl_personen-1].nachname << ", Alter: " << personen[anzahl_personen-1].alter << ", Geschlecht: "; if (personen[anzahl_personen-1].geschlecht == 'w') cout << "weiblich" << endl; else cout << "maennlich" << endl;
		}
	} while (eingabe != 'n' && eingabe != 'N' && anzahl_personen < 100);
	filter(personen, anzahl_personen);
	system("PAUSE");
	return 0;
}