//Yueyi Gao
//yzg0032
//hw1_yzg0032.cpp
//The program calculates the fatal amount of diet coke
//I received no help at all.
#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
	double mouseWeight;
	double mouseSweetener;
	double humanWeight;
	double humanSweetener;
	cout << "Please input the weight of the mouse in kg\n";
	cin >> mouseWeight;
	cout << "Please input the fatal amount of sweetener for mouse in kg\n";
	cin >> mouseSweetener;
	cout << "Please input the weight of your dear friend in kg\n";
	cin >> humanWeight;
	humanSweetener = (mouseSweetener * humanWeight) / (mouseWeight * 0.001);
	cout << "The fatal amount of Coke for your friend is: ";
	cout << humanSweetener;
	cout << " kg\n";
}
