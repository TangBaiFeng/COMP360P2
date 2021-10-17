#include <string>
#include <iostream>
using namespace std;

class Employee {

    public:
    string firstName, lastName, address, phoneNumber;
    double monthlyPaymentRate;
    /**
     * @brief Construct a new Employee object
     *
     * @param x fname
     * @param y lname
     * @param z address
     * @param w phonenumber
     */
    Employee(string x, string y, string z, string w) {
        firstName = x;
        lastName = y;
        address = z;
        phoneNumber = w;
    }
    double annumPay() {
        return monthlyPaymentRate * 12;
    }

};

class Technician : public Employee {
    public:
    Technician(string x, string y, string z, string w) : Employee(x, y, z, w) {

    }
    double overtimePay;
    int overtimeHours;
    /**
     * @brief Set the Overtime object
     *
     * @param x overtime pay
     * @param y overtime hours
     */
    void setOvertime(double x, int y) {
        overtimePay = x;
        overtimeHours = y;
    }
    double annumPay() {
        return Employee::annumPay() + overtimePay * overtimeHours * monthlyPaymentRate;
    }

};
class Engineer : public Employee {
    public:
    Engineer(string x, string y, string z, string w) : Employee(x, y, z, w) {

    }
    int newProductCnt = 0;
    double annumPay() {
        return Employee::annumPay() + newProductCnt * 5000;
    }

};
class MarketingManager : public Employee {
    public:
    MarketingManager(string x, string y, string z, string w) : Employee(x, y, z, w) {

    }
    int productSoldCnt = 0.0;
    double annumPay() {
        return Employee::annumPay() * (1 + productSoldCnt / 100.0) + productSoldCnt * 5000;
    }

};

int main(int argc, char const* argv[]) {
    Employee e("Employee", "testl", "address", "919");
    Technician t("Technician", "testl", "address", "919");
    Engineer e1("Engineer", "testl", "address", "919");
    MarketingManager m("test", "testl", "address", "919");
    e.monthlyPaymentRate = 50;
    t.monthlyPaymentRate = 40;
    e1.monthlyPaymentRate = 30;
    m.monthlyPaymentRate = 20;

    t.setOvertime(1.5, 10);
    e1.newProductCnt = (1);
    m.productSoldCnt = (1);

    cout << e.annumPay() << endl;
    cout << t.annumPay() << endl;
    cout << e1.annumPay() << endl;
    cout << m.annumPay() << endl;

    int i = 1;
}



