#include <iostream>
#include <string>

using namespace std;

struct Student {
	string firstName, lastName, year, section, course;
	
	Student* next;
	Student* prev;
};

void MainMenu(int & choice);
Student* AddStudentInfo();
void CheckStudentList(Student* head, Student* temp);
void DeleteStudentInfo(Student* head, int position);

int main() {
	int choice, counter = 0, positionToDelete;
	int position = 1;
	Student* head = NULL,* tail = NULL,* temp = NULL;
	
	do {
		MainMenu(choice);

		switch(choice) {
			case 1:
				temp = AddStudentInfo();
	             if(counter) {
					temp->prev = tail;
					temp->next = NULL;

					tail->next = temp;
					tail = temp;
				} else {
					head = temp;
					
					head->prev = NULL;
					head->next = NULL;

					tail = head;
				}

				counter++;
				break;
			case 2:
				CheckStudentList(head, temp);
				break;
			case 3:
				cout << "Enter position to delete: ";
	            cin >> positionToDelete;

				DeleteStudentInfo(head, positionToDelete);
			    break;
			case 4:
				return 0;
			default:
				cout << "Wrong Input!";
				break;
			}
	    } while(true);
		return 0;
}

void MainMenu(int & choice)  {
	cout << "\tMENU\n"
		 << "[1] Add Student\n"
		 << "[2] Check Student List\n"
		 << "[3] Delete Student\n"
		 << "[4] Exit\n"
		 << "Enter choice: ";
	cin >> choice;
		 system("cls");
}

Student* AddStudentInfo() {
	Student* studentInfo;
	studentInfo = new Student;
	
	cout << "------Student Info------" << endl;
	cout << "First Name of the Student: ";
	cin >> studentInfo->firstName;
	cout << "Last Name of the Student: ";
	cin >> studentInfo->lastName;
	cout << "Year of the Student: ";
	cin >> studentInfo->year;
	cout << "Course of the Student: ";
	cin >> studentInfo->course;
	cout << "Section of the Student: ";
	cin >> studentInfo->section;
	
	return studentInfo;
}

void CheckStudentList(Student* head, Student* temp) {
	cout << "------Check Student List------" << endl;
	temp = head;
	if(temp){
	    do{
	        cout << "First Name: " << temp->firstName << endl;
			cout << "Last Name: " << temp->lastName << endl;
			cout << "Year: " << temp->year << endl;
			cout << "Course: " << temp->course << endl;
			cout << "Section: " << temp->section << endl;
			cout << "-----------" << endl;
			
	        if(!temp->next != NULL)
	        break;

	        temp = temp->next;
		}while(true);
	} else {
	    cout << "No student records found.";
	}
}

void DeleteStudentInfo(Student* head, int position) {
	Student* current = head;
	Student* previous = NULL;
	
	int currentPosition = 1;
	
	while(current != NULL && currentPosition != position) {
		previous = current;
		current = current->next;
		currentPosition++;
	}
	
	if(current == NULL) {
		cout << "Student at position " << position << " is not found." << endl;
	}
	
	if(previous == NULL) {
		head = current->next;
	} else {
		previous->next = current->next;
	}
	
	delete current;
}
