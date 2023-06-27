#include <iostream>
#include <map>

using namespace std;

class GroupList {
private:
    map<int, string> studentMap;
    int codeError;

public:
    GroupList() {
        codeError = -1;
    }

    void addStudent(int number, const string& name) {
        studentMap[number] = name;
    }

    string operator[](int number) {
        if (studentMap.count(number) > 0) {
            codeError = 0;
            return studentMap[number];
        }
        else {
            codeError = -1;
            return "";
        }
    }

    void operator()() {
        if (codeError == 0) {
            cout << "No error" << endl;
        }
        else {
            cout << "Error code: " << codeError << endl;
        }
    }

    friend istream& operator>>(istream& input, GroupList& groupList) {
        int number;
        string name;

        cout << "Enter number: ";
        input >> number;
        cout << "Enter name: ";
        input >> name;

        groupList.addStudent(number, name);

        return input;
    }

    friend ostream& operator<<(ostream& output, const GroupList& groupList) {
        for (const auto& student : groupList.studentMap) {
            output << "Number: " << student.first << ", Name: " << student.second << endl;
        }

        return output;
    }
};

int main() {
    GroupList groupList;

    cout << "Enter student details (number and name):" << endl;
    for (int i = 0; i < 3; ++i) {
        cin >> groupList;
    }

    cout << endl << "Student list:" << endl;
    cout << groupList;

    cout << endl << "Accessing students using indexing operator:" << endl;
    cout << "Student with number 1: " << groupList[1] << endl;
    cout << "Student with number 4: " << groupList[4] << endl;

    groupList();  // Function call

    return 0;
}
