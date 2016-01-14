#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <functional>

using namespace std;

void        calcParams ( unsigned & quality, double & price );
long double calcCost   ( unsigned   quality, unsigned amount );

int main()
{
	unsigned quality;
	double   price;
	double   cash;
	unsigned quantity = 0;
	
	calcParams( quality, price );

	while(true)
	{
		cout << "Podaj ilość gotówki (ujemna by wyjść):" << endl;
		cin >> cash;
	
		if( cash < 0 )
			return 0;	
		
		quantity = 0;

		long double totalCost   = 0;
		unsigned    prevWolumen = 0;
		long double unitCost    = 0;

		while( totalCost < cash )
		{
			prevWolumen = quantity;
			quantity   += 10;
			unitCost    = calcCost( quality, quantity );
			totalCost   = unitCost * quantity;	
		}
		
		quantity = prevWolumen;

		cout << "Ilość:  " << quantity << endl;
		cout << "Cena:   " << price << endl;
		cout << "Jakość: " << quality << endl;

	}

	return 0;
}

long double calcCost( unsigned quality, unsigned amount )
{
	const long divider = 130000;
	const long offset  = 65000;
	
	long x = quality;
	long y = amount - offset;

	if( y < 0 )
		y = -y;

	return 13.47 + (0.0618182 + (0.000528505 + (0.0000123155 + (7.881216494259816e-8 +
	       1.1592739463427665e-10 * (-80 + x)) * (-20 + x)) * (-60 + x)) * (-1 + x)) * (-100 + x)
               + y * (1.0/(double)divider) - 0.4;
}

void calcParams ( unsigned & quality, double & price )
{
	ifstream in ("data");

	std::map<double, unsigned, greater<double> > qMap;
	std::map<double, double, greater<double> >   pMap;

	std::string str;

	double   cashStart;
	double   cashEnd;
	double   ratio;
	unsigned q;
	double   p;

	while( !in.eof() )
	{
		{
			getline(in, str);
			std::stringstream stream (str);

			stream >> cashStart;
			stream >> cashEnd;
		}

		{
			getline(in,str);
			std::stringstream stream (str);
			stream >> q;
		}

		{
			getline(in, str);
			std::stringstream stream (str);
			stream >> p;
		}

		ratio = cashEnd/cashStart;

		qMap[ratio] = q;

		pMap[ratio] = p;
	}

	std::map<double, unsigned, greater<double> >::iterator qit = qMap.begin();
	std::map<double, double, greater<double> >::iterator   pit = pMap.begin();

	unsigned qSum = 0;
	double   pSum = 0.0;

	for(int i = 0; i<10; ++i)
	{
		qSum += qit->second;
		pSum += pit->second;

		++qit;
		++pit;
	}

	quality = qSum/10.0;
	price   = pSum/10.0;

}
