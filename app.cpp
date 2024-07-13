#include <iostream>
#include <vector>
using namespace std;

class BankSystem {
private:
    struct Account {
        string firstName;
        string lastName;
        float totalBalance;
        int accountNumber;
    };
    vector<Account> accounts;

public:
    void displayOpt() {
        cout << "1: Create An Account." << endl
             << "2: Show Balance." << endl
             << "3: Deposit Money." << endl
             << "4: Withdraw Money." << endl
             << "5: Close An Account." << endl;
    }

    void createAccount() {
        Account account;
        cout << "Enter First Name: ";
        cin >> account.firstName;
        cout << "Enter Last Name: ";
        cin >> account.lastName;
        cout << "Enter Initial Amount: ";
        cin >> account.totalBalance;
        account.accountNumber = accounts.size() + 1;
        accounts.push_back(account);
        cout << "Account Created" << endl
             << "First Name: " << account.firstName << endl
             << "Last Name: " << account.lastName << endl
             << "Account Number: " << account.accountNumber << endl
             << "Initial Amount: " << account.totalBalance << endl
             << "Total Balance: " << account.totalBalance << endl;
    }

    void showBalance() {
        int accountNumber;
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        for (const auto& account : accounts) {
            if (account.accountNumber == accountNumber) {
                cout << "Total Balance: " << account.totalBalance << endl;
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void deposit() {
        int accountNumber;
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        float amount;
        cout << "Enter Amount: ";
        cin >> amount;
        for (auto& account : accounts) {
            if (account.accountNumber == accountNumber) {
                account.totalBalance += amount;
                cout << "Total Balance: " << account.totalBalance << endl;
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void withdraw() {
        int accountNumber;
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        float amount;
        cout << "Enter Amount: ";
        cin >> amount;
        for (auto& account : accounts) {
            if (account.accountNumber == accountNumber) {
                if (account.totalBalance >= amount) {
                    account.totalBalance -= amount;
                    cout << "Total Balance: " << account.totalBalance << endl;
                } else {
                    cout << "Insufficient balance." << endl;
                }
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    
void closeAccount() {
  int accountNumber;
  cout << "Enter Account Number: ";
  cin >> accountNumber;
  for (auto& account : accounts) {
    if (account.accountNumber == accountNumber) {
      account.totalBalance = 0;
      cout << "Account closed successfully." << endl;
      return;
    }
  }
  cout << "Account not found." << endl;
}
        // Implement account closure logic here
    
};

int main() {
    BankSystem bankSystem;
    int choice;
    do {
        bankSystem.displayOpt();
        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                bankSystem.createAccount();
                break;
            case 2:
                bankSystem.showBalance();
                break;
            case 3:
                bankSystem.deposit();
                break;
            case 4:
                bankSystem.withdraw();
                break;
            case 5:
                bankSystem.closeAccount();
                break;
            default:
                cout << "Invalid Option" << endl;
        }
    } while (choice != 6);

    return 0;
}
