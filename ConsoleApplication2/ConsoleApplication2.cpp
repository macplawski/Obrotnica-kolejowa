#include <iostream>

struct wagon
{
	int id;
	wagon *next;
	wagon();
};

wagon::wagon()
{
	next = 0;
}

struct tor
{
	int suma;
	wagon *first;
	tor *next;
	tor *previous;
	void dodaj_wagon(int id);
	tor();
};

tor::tor()
{
	first = 0;
	next = 0;
	previous = 0;
}

struct obrotnica
{
	tor *pierwszy;
	wagon *nowy;
	void dodaj_tor(int ile);
	obrotnica();
};

obrotnica::obrotnica()
{
	pierwszy = 0;
	nowy = 0;
}

void obrotnica::dodaj_tor(int ile)
{
	tor *path = new tor;
	path->suma = ile;
	if (pierwszy == 0)
	{
		pierwszy = path;
		path->next = pierwszy;
		path->previous = pierwszy;
	}
	else
	{
		tor *temp = pierwszy;
		while ((temp->next) != (pierwszy))
		{
			temp = temp->next;
		}
		temp->next = path;
		path->previous = temp;
		path->next = pierwszy;
		pierwszy->previous = path;
	}
}

void tor::dodaj_wagon(int id)
{
	wagon *nowa = new wagon;
	nowa->id = id;
	if (first == 0)
	{
		first = nowa;
		nowa->next = 0;
	}
	else
	{
		wagon *temp = first;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = nowa;
		nowa->next = 0;
	}
}

using namespace std;
int main()
{
	int t, a, b, c, d, ile_wagon = 0;
	char znak;
	obrotnica *obrot = new obrotnica;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a;
		int c = 0;
		if (a == 0)
		{
			obrot->dodaj_tor(a);
		}
		else
		{
			obrot->dodaj_tor(a);
			for (int j = 0; j < a; j++)
			{
				cin >> b;
				tor *temp = obrot->pierwszy;
				while ((temp->next) != (obrot->pierwszy))					
				{
					temp = temp->next;
				}
				temp->dodaj_wagon(b);
			}
		}
	}
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> znak;
		cin >> d;
		if (znak == 'z')
		{
			tor *temp = obrot->pierwszy;
			while (d--)
			{
				temp = temp->next;
			}
			obrot->pierwszy = temp;
		}
		else if (znak == 'o')
		{
			tor *temp = obrot->pierwszy;
			while (d--)
			{
				temp = temp->previous;
			}
			obrot->pierwszy = temp;
		}
		else if (znak == 'w')	
		{
			while (((d--)>0) && (obrot->pierwszy->suma > 0) && (ile_wagon < 10) && (ile_wagon >= 0))
			{
				if (ile_wagon == 0)
				{
					wagon *temp = obrot->pierwszy->first;
					obrot->pierwszy->first = obrot->pierwszy->first->next;
					obrot->nowy = temp;
					temp->next = 0;
					obrot->pierwszy->suma -= 1;
					ile_wagon += 1;
				}
				else
				{
					wagon *temp = obrot->nowy;
					obrot->nowy = obrot->pierwszy->first;
					obrot->pierwszy->first = obrot->pierwszy->first->next;
					obrot->nowy->next = temp;
					obrot->pierwszy->suma -= 1;
					ile_wagon += 1;
						
				}
			}
		}
		else if (znak == 'j')		
		{
			while ((d--) && (ile_wagon > 0) && (ile_wagon <= 10))
			{
				if (ile_wagon == 1)
				{
					wagon *temp = obrot->pierwszy->first;
					obrot->pierwszy->first = obrot->nowy;
					obrot->nowy = 0;
					obrot->pierwszy->first->next = temp;
					ile_wagon -= 1;
					obrot->pierwszy->suma += 1;
				}
				else
				{
					wagon *temp = obrot->nowy;
					obrot->nowy = obrot->nowy->next;
					temp->next = obrot->pierwszy->first;
					obrot->pierwszy->first = temp;
					ile_wagon -= 1;
					obrot->pierwszy->suma += 1;
				}
			}
		}
	}
	cout << ile_wagon << " ";
	wagon *temp = obrot->nowy;
	while (ile_wagon--)
	{
		cout<<temp->id<<" ";
		temp = temp->next;
	}
	cout << endl;
		tor *tempt = obrot->pierwszy;
	for (int i = 0; i < t; i++)
	{
		cout << tempt->suma<<" ";
		wagon *temp = tempt->first;
		while(tempt->suma>0)
		{
			cout << temp->id<<" ";
			temp = temp->next;
			tempt->suma -= 1;
		}
		tempt = tempt->next;
		cout << endl;
	}
	return 0;
}