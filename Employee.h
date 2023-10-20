#pragma once
#include <string>
#include <iostream>

using namespace std;

class Employee{
protected:
    string name;
    double hours;
public:
    double WeeklySalary(){return 0;}
    double HealthCare() {return 0;}
    double VacationDays()  {return 0;}
};

class Professional : public Employee {
private:
    double monthlySalary;
    int vacationDays;

public:
    Professional(const string& eName, double salary){name = eName; monthlySalary = salary;}

    double calculateWeeklySalary(){
        return monthlySalary / 4.0;
    }

    double calculateHealthCareContributions(){
        //10% of the monthly salary goes to healthcare
        return 0.1 * monthlySalary;
    }

    double calculateVacationDays(){
        vacationDays = 14;
        return 14; // Proffesionals get 2 weeks of vacation
    }
};

class Nonprofessional : public Employee {
private:
    double hourlyRate;
    double weeklyHoursWorked;
    double vacationHours;

public:
    Nonprofessional(const string& eName, double rate, double hoursWorked) {name = eName; hourlyRate = rate; weeklyHoursWorked = hoursWorked;}

    double calculateWeeklySalary(){
        return hourlyRate * weeklyHoursWorked;
    }

    double calculateHealthCareContributions(){
        return 0.05 * (hourlyRate * weeklyHoursWorked); // Nonprofessional get 5% healthcare
    }

    double calculateVacationDays(){
        return weeklyHoursWorked / 80; //Nonprofessionals get a vacation day every 80 hours worked
    }
};







