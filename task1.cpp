#include <bits/stdc++.h>
using namespace std;

struct Birthday {
    string name;
    int day;
    int month;
    int year;
};

void addBirthday(vector<Birthday>& birthdays) {
    Birthday newBirthday;
    cout << "Enter name: ";
    cin >> newBirthday.name;
    cout << "Enter day (1-31): ";
    cin >> newBirthday.day;
    cout << "Enter month (1-12): ";
    cin >> newBirthday.month;
    cout << "Enter year: ";
    cin >> newBirthday.year;
    birthdays.push_back(newBirthday);
}

void editBirthday(vector<Birthday>& birthdays) {
    string name;
    cout << "Enter name of birthday to edit: ";
    cin >> name;
    for (int i = 0; i < birthdays.size(); i++) {
        if (birthdays[i].name == name) {
            cout << "Enter new day (1-31): ";
            cin >> birthdays[i].day;
            cout << "Enter new month (1-12): ";
            cin >> birthdays[i].month;
            cout << "Enter new year: ";
            cin >> birthdays[i].year;
            return;
        }
    }
    cout << "Birthday not found.\n";
}

void displayBirthdayList(const vector<Birthday>& birthdays) {
    if (birthdays.empty()) {
        cout << "Birthday list is empty.\n";
    } else {
        cout << "Birthday list:\n";
        for (const auto& bday : birthdays) {
            cout << bday.name << ": " << bday.month << "/" << bday.day << "/" << bday.year << "\n";
        }
    }
}

void searchBirthday(const vector<Birthday>& birthdays) {
    string name;
    cout << "Enter name to search: ";
    cin >> name;
    for (const auto& bday : birthdays) {
        if (bday.name == name) {
            cout << name << "'s birthday is on " << bday.month << "/" << bday.day << "/" << bday.year << "\n";
            return;
        }
    }
    cout << "Birthday not found.\n";
}

void displayMonthlyBirthdays(const vector<Birthday>& birthdays, int month) {
    cout << "Birthdays in month " << month << ":\n";
    for (const auto& bday : birthdays) {
        if (bday.month == month) {
            cout << bday.name << ": " << bday.month << "/" << bday.day << "/" << bday.year << "\n";
        }
    }
}

int main() {
    vector<Birthday> birthdays;
    int choice, month;
    while (true) {
        cout << "\n1. Add birthday\n";
        cout << "2. Edit birthday\n";
        cout << "3. Display birthday list\n";
        cout << "4. Search birthday\n";
        cout << "5. Display monthly birthdays\n";
        cout << "6. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBirthday(birthdays);
                break;
            case 2:
                editBirthday(birthdays);
                break;
            case 3:
                displayBirthdayList(birthdays);
                break;
            case 4:
                searchBirthday(birthdays);
                break;
            case 5:
                cout << "Enter month (1-12): ";
                cin >> month;
                displayMonthlyBirthdays(birthdays, month);
                break;
            case 6:
                cout << "exit!\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }
}
