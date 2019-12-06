#include<iostream>
#include<random>
#include<string>
#include"PQueue.h"
#include"PatientRecord.h"
using namespace std;
bool ER_Registration(char, int&, PQueue<PatientRecord>&);
void Register_Patient(PQueue<PatientRecord>&);
int main()
{
	PQueue<PatientRecord>patient_queue;
	bool ragistrating = true;
	char choice;
	int counter = 0;
	while (ragistrating)
	{
		cout << "Please select one of the following:" << endl;
		cout << "+--------------------------------+" << endl;
		cout << "| " << "1. Register a Patient" << "          |" << endl;
		cout << "| " << "2. Display Patients Queue" << "      |" << endl;
		cout << "| " << "3. Remove a Patient From Queue" << " |" << endl;
		cout << "| " << "4. Close the Registration" << "      |" << endl;
		cout << "+--------------------------------+" << endl;
		cin >> choice;
		ragistrating = ER_Registration(choice, counter, patient_queue);
	}
	return 0;
}
bool ER_Registration(char choice, int& counter, PQueue<PatientRecord>& patient_queue)
{
	bool success = true;
	switch (choice)
	{
	case '1':
	{
		Register_Patient(patient_queue);
		counter++;
		break;
	}
	case '2':
	{
		patient_queue.displayQueue();
		cout << "== " << "Currently " << counter << " Patients in the Queue ==" << endl;
		break;
	}
	case'3':
	{
		if (!patient_queue.isEmpty())
		{
			patient_queue.dequeue();
			counter--;
		}
		else
			cout << "Currently there is no patient in the queue." << endl;
		break;
	}
	case'4':
	{
		cout << "Registration is closed. Exit the program." << endl;
		success = false;
		break;
	}
	default:
	{
		cout << "Bad Input." << endl;
		break;
	}
	}
	return success;

}
void Register_Patient(PQueue<PatientRecord>& patient_queue)
{
	PatientRecord patient;
	string last_name, first_name, date, symptom;
	int priority_number;
	getchar();
	cout << "Please enter patient`s last name:" << endl;
	getline(cin, last_name);
	cout << "Please enter patient`s first name:" << endl;
	getline(cin, first_name);
	cout << "Please enter patient`s date of birth:" << endl;
	cout << "(in the form of mm-dd-yyyy)" << endl;
	getline(cin, date);
	cout << "Plaese enter patient`s symptom:" << endl;
	getline(cin, symptom);
	cout << "Please enter patient`s priority number:" << endl;
	cin >> priority_number;
	patient.set_date_birth(date);
	patient.set_first_name(first_name);
	patient.set_last_name(last_name);
	patient.set_symptom(symptom);
	patient.set_priority_number(priority_number);
	patient_queue.enqueue(patient);
}
