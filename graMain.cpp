#include<iostream>

using namespace std;

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
	double wolumen;
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
		cout<<"cena: 22"<<endl;
		cout<<"jakość: 55"<<endl;
		wolumen=kasa/koszt_jednostkowy[i];
		cout<<"wolumen: "<<wolumen<<endl;
	}

	return 0;
}
