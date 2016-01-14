#include<iostream>

using namespace std;

int main()
{
	cout<<"podaj ilość gotówki"<<endl;
	double kasa;
	double koszt_jednostkowy=9.83;
	cin>>kasa;
	cout<<"cena: 22"<<endl;
	cout<<"jakość: 55"<<endl;
	double wolumen=kasa/koszt_jednostkowy;
	cout<<"wolumen: "<<wolumen<<endl;

	return 0;
}
