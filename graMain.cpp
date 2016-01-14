#include<iostream>

using namespace std;

long double calcCost( unsigned quality, unsigned amount );

int main()
{
	double kasa;
	int i=0;
	double koszt_jednostkowy[]={9.83,//kasa ~ 300000
								9.49,//kasa ~ 510000
								9.44,//900000
								9.85,//1700000
								10.95//3270000
								};
	unsigned wolumen = 0;
	unsigned quality = 55;

	while(true)
	{
		cout<<"podaj ilość gotówki"<<endl;
		cin>>kasa;
		
		if(kasa<400000)
			i=0;
		else if(kasa<700000)
			i=1;
		else if(kasa<1300000)
			i=2;
		else if(kasa<2485000)
			i=3;
		else
			i=4;
		
		cout << "cena: 22" << endl;
		cout << "jakość: " << quality << endl;

		long double totalCost = 0;
		unsigned prevWolumen = 0;
		long double unitCost;

		while( totalCost < kasa )
		{
			prevWolumen = wolumen;
			wolumen += 10;
			unitCost = calcCost( quality, wolumen );
			totalCost = unitCost * wolumen;	
		}

		// wolumen=kasa/koszt_jednostkowy[i];
		
		wolumen = prevWolumen;

		cout << "unitCost: " << unitCost << endl;

		cout << "wolumen: " << wolumen << endl;
	}

	return 0;
}

long double calcCost( unsigned quality, unsigned amount )
{
	const long divider = 130000;
	const long offset  = 65000;

	const long double a1   = 3.09674 * 1e-11;
	const long double a2   = 7.67286 * 1e-8;
	const long double a3   = 0.000015697;
	const long double a4   = 0.000263867;
	const long double a5   = 0.0618182;
	const long double a6   = 13.05;

	const long b1      = 21;
	const long b2      = 81;
	const long b3      = 41;
	const long b4      = 1;
	const long b5      = 100;

	long x = quality;

	long y = amount - offset;

	if( y < 0 )
		y = -y;


	return ( ( ( ( a1 * (x-b1) + a2 ) * (x-b2) + a3) * (x-b3) + a4 ) * (x-b4) + a5) * (x-b5) + a6 + y * (1.0/(double)divider);
}
