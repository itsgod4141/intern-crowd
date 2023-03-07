#include <bits/stdc++.h>

using namespace std;

// for registration
void registerUser(string username, string password) {
    ofstream userFile;
    userFile.open("users.txt" + username + ".txt");
    userFile << password;
    userFile.close();
    cout << "Registration successfull!" << endl;
}



// for checing if there is a user
bool userExists(string username) {
    ifstream userFile;
    userFile.open("users.txt" + username + ".txt");
    if (userFile) {
        userFile.close();
        return true;
    } else {
        return false;
    }
}

// login
void loginUser(string username, string password) {
    ifstream userFile;
    userFile.open("users.txt" + username + ".txt");
    string storedPassword;
    getline(userFile, storedPassword);
    userFile.close();
    if (password == storedPassword) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Incorrect password." << endl;
    }
}

int main() {
    string username, password;
    int choice;

    do {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter username: ";
                cin >> username;
                if (userExists(username)) {
                    cout << "User already exists." << endl;
                } else {
                    cout << "Enter password: ";
                    cin >> password;
                    registerUser(username, password);
                }
                break;
            case 2:
                cout << "Enter username: ";
                cin >> username;
                if (!userExists(username)) {
                    cout << "User does not exist." << endl;
                } else {
                    cout << "Enter password: ";
                    cin >> password;
                    loginUser(username, password);
                }
                break;
            case 3:
                cout << "Exiting............." << endl;
                break;
            default:
                cout << "Incorrect Choice" << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}


