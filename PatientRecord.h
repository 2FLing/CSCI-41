#pragma once
#pragma once
#ifndef _PATIENTRECORD
#define _PATIENTRECORD
#include<string>
#include<iostream>
using namespace std;
class PatientRecord
{
private:
	string last_name;
	string first_name;
	string date_birth;
	string symptom;
	int priority_number;
public:
	PatientRecord();
	void set_last_name(string);
	void set_first_name(string);
	void set_date_birth(string);
	void set_symptom(string);
	void set_priority_number(int);
	bool operator>=(PatientRecord);
	friend ostream& operator<<(ostream&, PatientRecord);
};
PatientRecord::PatientRecord()
{
	last_name = "none";
	first_name = "none";
	date_birth = "none";
	symptom = "none";
	priority_number = 0;
}
void PatientRecord::set_last_name(string name)
{
	last_name = name;
}
void PatientRecord::set_first_name(string name)
{
	first_name = name;
}
void PatientRecord::set_date_birth(string birth_date)
{
	date_birth = birth_date;
}
void PatientRecord::set_symptom(string name)
{
	symptom = name;
}
void PatientRecord::set_priority_number(int number)
{
	priority_number = number;
}
bool PatientRecord::operator>=(PatientRecord patient2)
{
	bool larger = false;
	if (this->priority_number >= patient2.priority_number)
		larger = true;
	return larger;
}
ostream& operator<<(ostream& os, PatientRecord patient)
{
	os << "=====" << "Priority Number " << patient.priority_number << " =====" << endl;
	os << "Last Name: " << patient.last_name << endl;
	os << "First Name: " << patient.first_name << endl;
	os << "The date of Birth: " << patient.date_birth << endl;
	os << "The Symptom: " << patient.symptom << endl;
	return os;
}
#endif

