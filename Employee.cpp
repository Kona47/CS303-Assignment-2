#include <iostream>
#include "Employee.h"
using namespace std;

int main() {
  Professional Kona("Kona", 10000);
  cout << "Professional Kona makes $" << Kona.calculateWeeklySalary() << " a week" << endl;
  cout << "Health Care Contributions: " << Kona.calculateHealthCareContributions() << endl;
  cout << "Vacation Days: " << Kona.calculateVacationDays() << endl;
  
  Nonprofessional Kona2("Kona", 50, 40);
  cout << "\nNonprofessional Kona makes $" << Kona2.calculateWeeklySalary() << " a week" << endl;
  cout << "Health Care Contributions: " << Kona2.calculateHealthCareContributions() << endl;
  cout << "Vacation Days Per Week: " << Kona2.calculateVacationDays() << endl;
}