#include "employee.h"
#include "hourlyEmployee.h"
#include "salaryEmployee.h"
#include <iostream>
#include <string>

using namespace std;

int main(){

    hourlyEmployee Peter;
    salaryEmployee Tracey;

    Peter.setPay(55.50);

    Peter.setHours(50);

    Tracey.setPay(50.00);

    Tracey.setBonus(500.00);

    cout << Peter.computePay() << endl;

    cout << Peter.totalPay() << endl;

    cout << Tracey.computePay() << endl;

    cout << Tracey.totalPay() << endl;


    return 0;

}