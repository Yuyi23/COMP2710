//Yueyi Gao
//yzg0032
//hw2_yzg0032.cpp
//Calculate how many month to pay off the loan.
//I received no help at all.
#include<iostream>
#include<cmath>

using namespace std;

int main() {
   double amount, rate, payment, mRate, interest, principal;
   double totalInterest = 0;
   int month = 0;
   cout << "Loan Amount: ";
   cin >> amount;
   cout << "Interest Rate (% per year): ";
   cin >> rate;
   cout << "Monthly Payments: ";
   cin >> payment;
   cout << "******************************************************\n";
   cout << "\tAmortization Table\n";
   cout << "******************************************************\n";
   mRate = rate / 12;
   cout.precision(2);
   cout << "Month\tBalance\tPayment\tRate\tInterest\tPrincipal"<< endl;
   cout << fixed << month << "\t$" << amount << " N/A\tN/A\tN/A\t\tN/A" << endl;
   while (amount > payment) {
      interest = amount * (mRate / 100);
      principal = payment - interest;
      amount = amount - principal;
      month++;
      totalInterest += interest;
      cout << fixed << month << "\t$" << amount << "\t$" << payment;
      cout.precision(1);
      cout << fixed << "\t" << mRate;
      cout.precision(2);
      cout << fixed << "\t$" << interest << "\t\t$" << principal << endl;
   }
   month++;
   interest = amount * (mRate / 100);
   payment = interest + amount;
   cout << fixed << month << "\t$0.00" << "\t$" << payment;
   cout.precision(1);
   cout << fixed << "\t" << mRate;
   cout.precision(2);
   cout << fixed << "\t$" << interest << "\t\t$" << amount << endl;
   cout << "******************************************************\n\n";
   totalInterest = totalInterest + interest;
   cout << "It takes " << month << " months to pay off the loan."<<endl;
   cout << "Total interest paid is: $" << totalInterest << endl;
   return 0;
}
