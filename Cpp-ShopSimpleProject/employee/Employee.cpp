#include "../shop/Shop.cpp"

class Employee : virtual  public Shop{
protected:
    char *employeeName;
    string employeeId;
    string phoneNumber;
    int salary;
public:
    Employee():employeeId("Unknown"), phoneNumber("Unknown"), salary(0){
        employeeName = new char[20];
        strcpy(employeeName,"");
    }

    Employee(char *employeeName, string employeeId, string phoneNumber, int salary)
    :phoneNumber(phoneNumber),employeeId(employeeId),salary(salary){
        int len1;

        len1 = strlen(employeeName);
        employeeName = new char [len1+1]; 
        strcpy(this->employeeName, employeeName);
    }

    void set_Employee(){
        fstream employee_file;
        employee_file.open("employee/emp_db.txt",ios::app);
        employee_file << "Employee List Info" <<endl;
        cout <<"Enter Employee Name: " <<endl;
        cin.getline(employeeName,20);
        employee_file << "Name: " << employeeName <<endl;

        cout <<"Enter Employee ID: " <<endl;
        cin >> employeeId;
        employee_file << "ID: " << employeeId <<endl;

        cout <<"Enter PhoneNumber: " <<endl;
        cin >> phoneNumber;
        employee_file << "Phone Number: " << phoneNumber <<endl;

        cout <<"Enter Employee Salary: " <<endl;
        cin >> salary;
        employee_file << "Salary: " << salary <<endl;    
        cout <<endl;
        employee_file.close();
    }
    

    void display(){
        cout <<"Employee Name: " << employeeName <<endl;
        cout <<"Employee ID: " << employeeId <<endl;
        cout <<"Employee Phone Number: " << phoneNumber <<endl;
        cout <<"Employee Salary: " << salary <<endl;
    }

    ~Employee(){
        delete [] employeeName;
    }
};