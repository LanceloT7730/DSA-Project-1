#include <iostream>
#include<cmath>

using namespace std;

class Child {
    int age;
    string name;
public:
    Child *nextChild;

    Child() {
        nextChild = nullptr;
    }

    int getAge() {
        return age;
    }

    void setAge(int &age) {
        this->age = age;
    }

    string getName() {
        return name;
    }

    void setName(string &name) {
        this->name = name;
    }
};

class Spouse {
    int age;
    string name;
    int num_children;

    Child *childHead;

    void insertChildAtFront(int age, string name) {
//i=0; i<num_children
        auto *newChild = new Child;
        newChild->setAge(age);
        newChild->setName(name);
        newChild->nextChild = childHead;
        childHead = newChild;
    }

public:
    Spouse() {
        cout << "Enter the number of childs" << endl;
        cin >> num_children;
        if (num_children <= 0) num_children = 0;
        else {
            childHead = nullptr;
            childrenDetails(num_children);
        }
    }

    int getAge() {
        return age;
    }

    auto getChildHead() {
        return childHead;
    }

    unsigned int get_child_num() {
        return num_children;
    }

    void setAge(int &age) {
        this->age = age;
    }

    string getName() {
        return name;
    }

    void setName(string &name) {
        this->name = name;
    }


    void childrenDetails(int lim_num_children) {
        int i = 1;

        while (i <= lim_num_children) {
            cout << "Enter the child " << i << " name->";
            string child_name;
            cin >> child_name;

            cout << "Enter the child " << i << " age->";
            int child_age = 0;
            cin >> child_age;
            insertChildAtFront(child_age, child_name);
            i++;
        }

    }

    void printChildrenDetails() {
        Child *temp = childHead;
        int i = num_children;
        while (temp) {
            cout << "Child " << i << " name is " << temp->getName()
                 << " and this child's age is " << temp->getAge() << endl;

            temp = temp->nextChild;
            i--;
        }
    }

    ~Spouse() {
        Child *currChild = childHead;
        while (currChild) {
            childHead = currChild->nextChild;
            delete currChild;
            currChild = childHead;
        }
    }

};

struct Employee {
    bool isSpouseAvailable;
    string employee_name, designation, email;
    int employee_id, age;
    Employee *nextEmployee;

    Employee() {
        cout << "Enter 1 if employee is married, 0 otherwise" << endl;
        cin >> isSpouseAvailable;
        spouseLink = nullptr;
        if (isSpouseAvailable) {
            spouseLink = new Spouse;
            spouseDetails();
        }
    }

    ~Employee() {
        delete spouseLink;
    }


    void printChildrenDetails() {
        spouseLink->printChildrenDetails();
    }


private:
    Spouse *spouseLink;

    void spouseDetails() {
        cout << "Enter the spouse's name->";
        string spouse_name;
        cin >> spouse_name;
        spouseLink->setName(spouse_name);

        cout << "Enter the spouse's age->";
        int spouse_age = 0;
        cin >> spouse_age;
        spouseLink->setAge(spouse_age);
    }

};

struct List {
    List() {
        head = nullptr;
    }

    void insertEmployeeAtFront(string employee_name, string designation,
                               string email, int employee_id, int age) {

        Employee *newEmployee = new Employee;
        newEmployee->employee_name = employee_name;
        newEmployee->designation = designation;
        newEmployee->email = email;
        newEmployee->employee_id = employee_id;
        newEmployee->age = age;

        newEmployee->nextEmployee = head;
        head = newEmployee;
    }

    void printAllEmpChildDetails() {
        Employee *curr = head;
        while (curr) {
            curr->printChildrenDetails();
            curr = curr->nextEmployee;
        }
    }

private:
    Employee *head;
};

int main() {
    List list1;
    list1.insertEmployeeAtFront("Tim", "designation1", "Example1@gmail.com", 210045, 23);
    list1.insertEmployeeAtFront("Kruz", "designation2", "Example2@gmail.com", 210046, 25);
    list1.insertEmployeeAtFront("Kevin", "designation3", "Example3@gmail.com", 210047, 27);

    list1.printAllEmpChildDetails();


    return 0;
}
