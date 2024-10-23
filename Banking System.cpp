#include <iostream>
using namespace std;
// Creating Bank Class
class Bank_account {
private:
    int account_number;
    double Balance;

public:
    void set_Bank_Account_Data(int acc_number, double A_Balance) {
        account_number = acc_number;
        Balance = A_Balance;
    }

    void Display_BankAccount_Data() {
        cout << "Here is customer Bank Account Data " << endl;
        cout << "-----------------------------------" << endl;
        cout << "Account Number :" << account_number << endl;
        cout << "Account Balance :" << Balance << endl;
    }
};

class Customer {
private:
    string Customer_name;
    int Phone_Number;
    int cnic;
    Bank_account bank_account[2];

public:
    Customer() {
        Customer_name = "";
        Phone_Number = 0;
        cnic = 0;
    }

    Customer(string name, int p_number, int CNIC) {
        Customer_name = name;
        Phone_Number = p_number;
        cnic = CNIC;
    }

    void SET_CUSTOMER_DATA(string C_Name, int C_Phone_num, int C_CNIC) {
        Customer_name = C_Name;
        Phone_Number = C_Phone_num;
        cnic = C_CNIC;
    }

    void Display_Customer_Data() {
        cout << "Here customer Data" << endl;
        cout << "-----------------------\n";
        cout << "Name :" << Customer_name << endl;
        cout << "Phone Number :" << Phone_Number << endl;
        cout << "CNIC :" << cnic << endl;
    }

    void Set_bank_account_data(int index, int A_number, double A_Balance) {
        if (index >= 0 && index < 2) {
            bank_account[index].set_Bank_Account_Data(A_number, A_Balance);
        }
    }

    void Display_BankAccounts() {
        for (int i = 0; i < 2; ++i) {
            bank_account[i].Display_BankAccount_Data();
        }
    }
};

class Bank {
private:
    string Name;
    string Location;
    Customer customers[2];

public:
    Bank(string B_Name, string B_Location) {
        Name = B_Name;
        Location = B_Location;
    }

    void set_customer_data(int index, string name, int phone, int cnic) {
        if (index >= 0 && index < 2) {
            customers[index].SET_CUSTOMER_DATA(name, phone, cnic);
        }
    }

    void set_bank_account_data(int customer_index, int account_index, int account_number, double balance) {
        if (customer_index >= 0 && customer_index < 2) {
            customers[customer_index].Set_bank_account_data(account_index, account_number, balance);
        }
    }

    void Display_Bank_Data() {
        cout << "Here Customer Bank Data " << endl;
        cout << "-----------------------" << endl;
        cout << "Bank Name :" << Name << endl;
        cout << "Bank Location :" << Location << endl;
        for (int i = 0; i < 2; ++i) {
            cout << "Customer " << (i + 1) << " Data:" << endl;
            customers[i].Display_Customer_Data();
            customers[i].Display_BankAccounts();
        }
    }
};

int main() {
    Bank bank("UBL", "GT-Road");
    
    // Set customer data
    bank.set_customer_data(0, "Muhammad", 313484, 2342);
    bank.set_customer_data(1, "Ali", 321405, 876872687);

    // Set bank account data
    bank.set_bank_account_data(0, 0, 123123, 5000);
    bank.set_bank_account_data(0, 1, 234234, 3000);
    bank.set_bank_account_data(1, 0, 345345, 4000);
    bank.set_bank_account_data(1, 1, 456456, 6000);

    // Display Data
    bank.Display_Bank_Data();

    return 0;
}
