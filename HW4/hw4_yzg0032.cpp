//Yueyi Gao
//yzg0032
//hw4_yzg0032.cpp
//Source:class note and sample code in homework4.pdf
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdlib>

using namespace std;

const int MAX_SIZE = 100;

int readfile(int inputArray[], ifstream &instream);
int sort(int inputArray1[], int inputArray1_size,
	int inputArray2[], int inputArray2_size, int outputArray[]);
void writefile(int outputArray[], int outputArray_size);
int main() {
	ifstream inStream1, inStream2;
	int iArray1[MAX_SIZE];
	int iArray1_size;
	int iArray2[MAX_SIZE];
	int iArray2_size;
	int iArray3[MAX_SIZE];
	int iArray3_size;

	cout << "*** Welcome to Yueyi Gao's sorting program ***" << endl;
	cout << "Enter the first input file name: ";
	string input1;
	cin >> input1;
	inStream1.open((char*)input1.c_str());
	if (inStream1.fail()) {
		cout << "Input file opening failed." << endl;
		exit(1);
	}
	iArray1_size = readfile(iArray1, inStream1);
	inStream1.close();

	cout << "The list of " << iArray1_size  << " numbers in file "
		 << input1 << " is: "<<endl;
	for (int i = 0; i < iArray1_size; i++) {
		cout << iArray1[i]<<endl; 
	}
	

	cout <<endl<< "Enter the second input file name: ";
	string input2;
	cin >> input2;
	inStream2.open((char*)input2.c_str());
	if (inStream2.fail()) {
		cout << "Input file opening failed." << endl;
		exit(1);
	}
	iArray2_size = readfile(iArray2, inStream2);
	inStream2.close();

	cout << "The list of " << iArray2_size << " numbers in file "
		<< input2 << " is: " << endl;
	for (int i = 0; i < iArray2_size; i++) {
		cout << iArray2[i] << endl;
	}

	iArray3_size = sort(iArray1, iArray1_size,
		iArray2, iArray2_size, iArray3);
	cout <<endl<< "The sorted list of "<<iArray3_size<<" numbers is: ";
	for (int i = 0; i < iArray3_size; i++) {
		cout << iArray3[i] << " ";
	}
	cout<<endl;
	writefile(iArray3, iArray3_size);
}

int readfile(int inputArray[],ifstream &instream) {
	int index=0;
	instream >> inputArray[index];
	
	while (!instream.eof()) {
		index++;
		instream >> inputArray[index];
	}
	return index+1;
}

int sort(int inputArray1[], int inputArray1_size,
	int inputArray2[], int inputArray2_size, int outputArray[]) {
	int i = 0, j = 0, k = 0;
	while (i < inputArray1_size && j < inputArray2_size) {
		if (inputArray1[i]< inputArray2[j]) {
			outputArray[k] = inputArray1[i];
			k++;
			i++;
		}
		else {
			outputArray[k] = inputArray2[j];
			k++;
			j++;
		}
	}
	while (i < inputArray1_size) {
		outputArray[k] = inputArray1[i];
		k++;
		i++;
	}
	while (i < inputArray2_size) {
		outputArray[k] = inputArray2[j];
		k++;
		j++;
	}
	return k; 
}

void writefile(int outputArray[], int outputArray_size) {
	ofstream output;
	output.open("output.txt");
	for (int i = 0; i < outputArray_size; i++) {
		output << outputArray[i] << endl;
	}
	output.close();
}
