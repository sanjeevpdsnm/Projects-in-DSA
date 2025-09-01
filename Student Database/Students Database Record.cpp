#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Students {
public:
    int numberOfStudents = 0;
    vector<string> name;
    vector<string> Enrollment;
    vector<double> cgpa;
    int ch;

    void choice() {
        cout << "\n1. Add Records\n2. View Records\n3. Delete Records\n4. Search Records\n5. Exit\nEnter your choice : ";
        cin >> ch;
        if (ch == 1) {
            stdRecords();
        } else if (ch == 2) {
            displayRecords();
        } else if (ch == 3) {
            deleteRecords();
        } else if (ch == 4) {
            searchRecords();
        } else if (ch == 5) {
            cout << "Exiting program...\n";
            return;
        } else {
            cout << "Invalid choice!\n";
        }
        choice();
    }

    void stdRecords() {
        cout << "\nNumber of Students : ";
        cin >> numberOfStudents;
        cin.ignore();

        for (int i = 0; i < numberOfStudents; i++) {
            string n, eroll;
            double grade;

            cout << "\nEnter Name of Student : ";
            getline(cin, n);

            cout << "Enter Enrollment of Student : ";
            cin >> eroll;

            cout << "Enter CGPA of Student : ";
            cin >> grade;
            cin.ignore();

            name.push_back(n);
            Enrollment.push_back(eroll);
            cgpa.push_back(grade);
        }
        cout << "\nData entered Successfully.\n";
    }

    void displayRecords() {
        if (name.empty()) {
            cout << "\nNo records found!\n";
            return;
        }

        string yn;
        cout << "\nDo you want all Records(Type \"All\")\nOr particular Enrollment record(Type \"E\"): ";
        cin >> yn;

        if (yn == "All") {
            cout << "\nName\tEnrollment\tCGPA\n";
            for (int i = 0; i < name.size(); i++) {
                cout << name[i] << "\t" << Enrollment[i] << "\t" << cgpa[i] << endl;
            }
        } else {
            string rollNo;
            cout << "Enter the Enrollment Number : ";
            cin >> rollNo;

            bool found = false;
            for (int i = 0; i < name.size(); i++) {
                if (Enrollment[i] == rollNo) {
                    cout << name[i] << "\t" << Enrollment[i] << "\t" << cgpa[i] << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Data Not Found!!\n";
            }
        }
    }


    void deleteRecords() {
        string yn;
        cout << "Delete all Records? Type \"All\"\nOr particular Enrollment Type \"E\" : ";
        cin >> yn;

        if (yn == "All" || yn == "ALL" || yn == "all") {
            name.clear();
            Enrollment.clear();
            cgpa.clear();
            numberOfStudents = 0;
            cout << "All Data is deleted successfully.\n";
        } else if (yn == "E" || yn == "e") {
            string Eroll;
            cout << "Enter the Enrollment Number to be deleted : ";
            cin >> Eroll;

            bool found = false;
            for (int i = 0; i < numberOfStudents; i++) {
                if (Enrollment[i] == Eroll) {
                    name.erase(name.begin() + i);
                    Enrollment.erase(Enrollment.begin() + i);
                    cgpa.erase(cgpa.begin() + i);
                    numberOfStudents--;
                    cout << "Record with Enrollment " << Eroll << " deleted successfully.\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Enrollment not found!\n";
            }
        }
    }

    void searchRecords() {
        string Eroll;
        cout << "Enter the Enrollment number to be searched : ";
        cin >> Eroll;

        bool found = false;
        for (int i = 0; i < numberOfStudents; i++) {
            if (Enrollment[i] == Eroll) {
                cout << "Name\t\tEnrollment\tCGPA\n";
                cout << name[i] << "\t\t" << Enrollment[i] << "\t" << cgpa[i] << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Record not found!!\n";
        }
    }
};

int main() {
    Students s;
    s.choice();
}
