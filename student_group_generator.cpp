#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

class GroupMaker {
private:
    int totalStudents;
    string students[100];
    string groups[20][5];

public:
    GroupMaker(int total) {
        totalStudents = total;
        if (totalStudents % 5 != 0) {
            cout << "Total students must be divisible by 5"<<endl;
            exit(0);
        }
    }

    
    void inputNamesAndSaveToFile(string filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "File could not be created!\n";
            exit(0);
        }

        cout << "Enter names of " << totalStudents << " students:"<<endl;
        string name;
        for (int i = 0; i < totalStudents; i++) {
            cout << "Student " << i + 1 << ": ";
            getline(cin >> ws, name); 
            if (name.empty()) {
                i--; 
                continue;
            }
            students[i] = name;
            file << name << "\n"; 
        }

        file.close();
        cout << filename << " file created with " << totalStudents << " names"<<endl;
    }

   
    void inputNamesFromFile(string filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "File open failed!\n";
            exit(0);
        }

        int i = 0;
        string name;
        while (getline(file, name) && i < totalStudents) {
            students[i] = name;
            i++;
        }
        file.close();
    }

    void shuffleStudents() {
        for (int i = totalStudents - 1; i > 0; i--) {
            int r = rand() % (i + 1);
            swap(students[i], students[r]);
        }
    }

    void makeGroups() {
        int g = 0, pos = 0;
        for (int i = 0; i < totalStudents; i++) {
            groups[g][pos] = students[i];
            pos++;
            if (pos == 5) {
                pos = 0;
                g++;
            }
        }
    }

    void printGroups() {
        cout << "===== Generated Groups ====="<<endl;
        int totalGroups = totalStudents / 5;
        for (int g = 0; g < totalGroups; g++) {
            cout << "Group " << g + 1 << ":\n";
            for (int j = 0; j < 5; j++) {
                cout << "  - " << groups[g][j] << "\n";
            }
            cout << "\n";
        }
    }
};

int main() {
    srand(time(0));

    int total;
    cout << "Enter total number of students (5 to 100, divisible by 5): ";
    cin >> total;

    if (total < 5 || total > 100 || total % 5 != 0) {
        cout << "Invalid input! Choose 5 to 100 divisible by 5."<<endl;
        return 0;
    }

    GroupMaker gm(total);

   
    gm.inputNamesAndSaveToFile("students.txt");

    gm.shuffleStudents();
    gm.makeGroups();
    gm.printGroups();

    return 0;
}
