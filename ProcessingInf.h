#pragma once
#include <iomanip>	
#include "constructBuilder.h"
#include "libaryFunction.h"


//============ create input and output for subject =================
istream& operator >> (istream& is, subject& sb) {
	cout << "ID subject: "; getline(is, sb.idSubject);
	cout << "Name subject: "; getline(is, sb.nameSubject);
	cout << "Credit subject: "; is >> sb.creditSubject;

	cin.ignore();
	return is;
}

ostream& operator << (ostream& os, subject& sb) {
	os << "\t" << setw(9) << sb.idSubject;
	os << right << setw(18) << sb.creditSubject;
	os << right << setw(len(sb.nameSubject) + 15) << sb.nameSubject << endl;
	

	return os;
}

//============ create input and output for class =================
istream& operator >> (istream& is, classSubject& classSb) {
	cout << "ID class: "; getline(is, classSb.idClass);
	cout << "ID group: "; getline(is, classSb.idGroup);
	cout << "Name subject: "; getline(is, classSb.idSubject);
	cout << "Term: "; getline(is, classSb.term);
	cout << "Name mentor: "; getline(is, classSb.nameMentor);

	return is;
}

ostream& operator << (ostream& os, classSubject& classSb) {
	os << classSb.idGroup;
	os << "\t" << setw(4) << classSb.idClass;
	os << "\t" << setw(6) << classSb.idSubject;
	os << "\t\t" << setw(3) << classSb.numberOfStudent;
	os << "\t" << setw(len(classSb.term) + 5) << classSb.term;
	os << "\t" << setw(len(classSb.nameMentor) + 1) << classSb.nameMentor << endl;

	return os;
}

//============ create input and output for data on each class =================
istream& operator >> (istream& is, studentInClass& stInClass) {
	cout << "MSSV: "; getline(is, stInClass.mssv);
	cout << "Mark: "; is >> stInClass.mark;
	cout << "Evaluation: "; getline(is, stInClass.evaluation);

	return is;
}

ostream& operator << (ostream& os, studentInClass& stInClass) {
	os << "MSSV: " << stInClass.mssv << endl;
	os << "Mark: " << stInClass.mark << endl;
	os << "Evaluation: " << stInClass.evaluation << endl;

	return os;
}

//============ create input and output for student =================
istream& operator >> (istream& is, student& st) {
	cout << "MSSV: "; getline(is, st.mssv);
	cout << "Full name of student: "; getline(is, st.fullName);
	cout << "Gender: "; getline(is, st.gender);
	cout << "Phone: "; getline(is, st.phone);
	cout << "Major: "; getline(is, st.major);

	return is;
}

ostream& operator << (ostream& os, student& st) {
	os << right << setw(1) << st.mssv;
	os << right << setw(len(st.fullName) + 3) << st.fullName;
	os << right << "\t" << setw(len(st.phone) + 2) << st.phone;
	os << right << "\t" << setw(len(st.gender)) << st.gender;
	os << right << "\t" << setw(len(st.major) + 1) << st.major;
	os << right << "\t" << setw(4);
	for (int i = 0; i < st.listSb.amount; i++) {
		os << st.listSb.subject[i].idSubject << ",";
	}
	os << "\n";
	
	return os;
}

//create function 

void createNewSubject() {
	ShowCur(3);
	int numberOfSubject;
	gotoXY(1, 4);
	cout << "Amout of subject: "; cin >> numberOfSubject;
	cin.ignore();
	subject temp;
	for (int i = 0; i < numberOfSubject; i++) {
		cout << "===== Subject " << i + 1 << " =====" << endl;
		cin >> temp;
		if (checkIdSubject(temp.idSubject) != -1) {
			cout << "Your subject have been existed" << endl;
			continue;
		}
		listSb.subject[listSb.amount++] = temp;
		if (i == 1) {
			cleanInput();
			gotoXY(0, 4);
		}
	}
	cout << "SUCCESFUL";
}

void createNewClass() {
	gotoXY(0, 4);
	int numberOfClass;
	cout << "Amout of class want to creating: "; cin >> numberOfClass;
	cin.ignore();
	classSubject temp;
	for (int i = 0; i < numberOfClass; i++) {
		cout << "===== Class " << i + 1 << " =====" << endl;
		cin >> temp;
		if (checkIdClass(temp.idClass) != -1) {
			cout << "Your class have been existed" << endl;
			continue;
		}
		
		listClassSb.classSubject[listClassSb.amount] = new classSubject;
		*listClassSb.classSubject[listClassSb.amount++] = temp;
		
		cleanInput();
		gotoXY(0, 4);
	}
	cout << "SUCCESFUL";
}

void createNewStudent() {
	cleanInput();
	gotoXY(0, 4);
	int numberOfStudent;
	cout << "Amout of student: "; cin >> numberOfStudent;
	cin.ignore();
	for (int i = 0; i < numberOfStudent; i++) {
		if (i == 2) {
			cleanInput();
			gotoXY(0, 4);
		}
		cout << "===== Student " << i + 1 << " =====" << endl;
		cin >> listSt.student[listSt.amount++];
		if (findIdStudent(listSt.student[listSt.amount].mssv) != -1) {
			listSt.amount -= 1;
			cout << "Your student have been existed" << endl;
		}
	}
}

//print function

void printAllSubject() {
	cleanShow();
	gotoXY(44, 4);
	cout << left << setw(4) << "STT" << right << setw(16) << "ID SUBJECT" << right << setw(16) << "CREDIT" << "\t" << right << setw(14) << "NAME SUBJECT" << endl;
	for (int i = 0; i < listSb.amount; i++) {
		gotoXY(44, whereY());
		cout << i + 1;
		cout << listSb.subject[i];
	}
}

void printAllClass() {
	cleanShow();
	gotoXY(44, 4);
	cout << left << setw(4) << "ID GROUP" << right << setw(12) << "ID CLASS" << right << setw(13) << "ID SUBJECT" << right << setw(12) << "STUDENT" << right << setw(8) << "TERM" << right << setw(19) << "NAME MENTOR" << endl;
	gotoXY(44, whereY());
	for (int i = 0; i < listClassSb.amount; i++) {
		gotoXY(44, whereY());
		cout << *listClassSb.classSubject[i];
	}
}

/*
void printStudentInClass(int selection = NULL) {
	if (selection == 2) {
		cout << "ERROR" << endl;
	}
	else {
		for (int i = 0; i < listClassSb.amount; i++) {
			cout << "===== Class " << listClassSb.classSubject[i]->idClass << " =====" << endl;
			for (int j = 0; j < listSt.amount; j++) {
				for (int t = 0; t < listSt.student[j].amoutOfSubject; t++) {
					if (_stricmp(listSt.student[j].listClassSb.classSubject[t]->idClass.c_str(), listClassSb.classSubject[i]->idClass.c_str()) == 0) {
						cout << listSt.student[j].mssv << ": " << listSt.student[j].fullName << endl;
					}
				}
			}
		}
	}
}
*/

void printStudentInClass() {
	cleanShow();
	gotoXY(44, 5);
	cout << left << setw(4) << "ID CLASS" << right << setw(10) << "MSSV" << right << setw(14) << "NAME" << right << setw(22) << "MARK" << right << setw(22) << "EVALUATION" << endl;
	cout << "\n";
	for (int i = 0; i < listClassSb.amount; i++) {
		gotoXY(44, whereY());
		cout << listClassSb.classSubject[i]->idClass;
		for (nodeStudentInClass* check = listClassSb.classSubject[i]->lsStClass.pFirstStudent; check != NULL; check = check->pSt) {
			gotoXY(58, whereY());
			int number = findIdStudent(check->data.mssv);
			cout << check->data.mssv;
			gotoXY(72, whereY());
			cout << listSt.student[number].fullName;
			gotoXY(94, whereY());
			cout << check->data.mark;
			gotoXY(110, whereY());
			cout << check->data.evaluation << endl;
		}
		cout << "\n";
		for (int i = 0; i < 80; i++) {
			gotoXY(44 + i, whereY());
			cout << char(205);
		}
		cout << "\n";
	}
}

void printAllStudent() {
	cleanShow();
	gotoXY(42, 4);
	cout << "MSSV" << right << setw(16) << "FULL NAME" << right << setw(17) << "PHONE" << right << setw(15) << "GENDER" << right << setw(8) << "MAJOR" << right << setw(15) << "LIST SUBJECT" << endl;
	for (int i = 0; i < listSt.amount; i++) {
		gotoXY(42, whereY());
		cout << listSt.student[i];
	}
}

//============ config for student in class =================
void deleteClass() {
	string tempIdClass;

	cleanInput();
	gotoXY(0, 4);
	ShowCur(4);

	cout << "ID class: "; getline(cin, tempIdClass);

	int number = checkIdClass(tempIdClass);

	for (int i = number; i < listClassSb.amount; i++) {
		if (i != listClassSb.amount - 1) {
			listClassSb.classSubject[i] = listClassSb.classSubject[i + 1];
		}
	}
	listClassSb.amount -= 1;
	cout << "SUCCESFUL";
}

void editClass() {
	gotoXY(0, 4);
	string tempIdClass;
	cout << "Enter your ID class: "; getline(cin, tempIdClass);

	int number = checkIdClass(tempIdClass);
	if (number == -1) {
		cout << "Cannot find out your ID class" << endl;
		return;
	}
	while (true) {
		cleanMenu();
		ShowCur(4);
		box(13, 19, 14, 2, 7, " MENU EDIT CLASS", NULL);
		menu(7, 22, 3, listMenuEditClass);
		gotoXY(0, 5);

		switch (chosen) {
		case 0: { //id subject
			string tempReplace;
			cout << "Enter your ID subject replace: "; getline(cin, tempReplace);
			tempReplace = upcase(tempReplace);
			listClassSb.classSubject[number]->idSubject = tempReplace;
			break;
		}
		case 1: {//name mentor
			string tempReplace;
			cout << "Enter your name mentor replace: "; getline(cin, tempReplace);
			tempReplace = upcase(tempReplace, 2);
			listClassSb.classSubject[number]->nameMentor = tempReplace;
			break;
		}
		case 2: {
			return;
		}
		}
		cout << "SUCCESFUL";
		cleanInput();
	}
}

void findClass() {
	cleanInput();
	gotoXY(0, 4);
	ShowCur(4);
	string tempIdClass;
	cout << "ID Subject: "; getline(cin, tempIdClass);

	int number = checkIdClass(tempIdClass);

	if (number == -1) {
		cout << "Cannot find your ID class" << endl;
		return;
	}

	gotoXY(44, 4);
	cout << left << setw(4) << "ID GROUP" << right << setw(12) << "ID CLASS" << right << setw(13) << "ID SUBJECT" << right << setw(12) << "STUDENT" << right << setw(8) << "TERM" << right << setw(19) << "NAME MENTOR" << endl;
	gotoXY(44, whereY());
	
	cout << *listClassSb.classSubject[number];
}

void addStudentInClass() {
	string tempIdClass;

	cleanInput();
	gotoXY(0, 4);
	ShowCur(4);

	cout << "ID class: "; getline(cin, tempIdClass);

	int numberCl = checkIdClass(tempIdClass);
	if (numberCl == -1) {
		cout << "Cannot find the ID class" << endl;
		return;
	}

	int numberOfStudent;
	cout << "Amout of student: "; cin >> numberOfStudent;
	cin.ignore();

	for (int i = 0; i < numberOfStudent; i++) {
		
		cleanInput();
		gotoXY(0, 4);

		cout << "====== STUDENT " << i + 1 << "======" << endl;

		studentInClass tempStClass;
		cout << "ID student: "; getline(cin, tempStClass.mssv);

		int numberSt = findIdStudent(tempStClass.mssv);
		if (numberSt == -1) {
			cout << "Cannot find the ID student" << endl;
			continue;
		}

		for (nodeStudentInClass* checkSt = listClassSb.classSubject[numberCl]->lsStClass.pFirstStudent; checkSt != NULL; checkSt = checkSt->pSt) {
			if (_stricmp(tempStClass.mssv.c_str(), checkSt->data.mssv.c_str()) == 0) {
				cout << "The student have been existed in this class" << endl;
				continue;
			}
		}

		do {
			cout << "Mark: "; cin >> tempStClass.mark;
			cin.ignore();

			if (tempStClass.mark >= 9 && tempStClass.mark <= 10)	tempStClass.evaluation = "GIOI";
			else if (tempStClass.mark < 9 && tempStClass.mark >= 7)	tempStClass.evaluation = "TOT";
			else if (tempStClass.mark < 7 && tempStClass.mark >= 5)	tempStClass.evaluation = "KHA";
			else if (tempStClass.mark < 5 && tempStClass.mark >= 0)	tempStClass.evaluation = "TRUNG BINH";
			else cout << "Your input is error" << endl;

		} while (tempStClass.mark > 10 || tempStClass.mark < 0);

		addToListStudentInClass(listClassSb.classSubject[numberCl]->lsStClass, tempStClass);
		listClassSb.classSubject[numberCl]->numberOfStudent += 1;
	}
	cout << "SUCCESFUL";
}

void transferStudent() {
	string tempIdSt, tempIdClass, tempIdClassReplace;
	studentInClass tempSt;

	cleanInput();
	gotoXY(0, 4);
	ShowCur(4);

	cout << "ID student: "; getline(cin, tempIdSt);

	cout << "ID class: "; getline(cin, tempIdClass);
	int numberClass = checkIdClass(tempIdClass);
	if (numberClass == -1) {
		cout << "The class does not exits" << endl;
		return;
	}

	for (nodeStudentInClass* checkSt = listClassSb.classSubject[numberClass]->lsStClass.pFirstStudent; checkSt != NULL; checkSt = checkSt->pSt) {
		if (_stricmp(tempIdSt.c_str(), checkSt->data.mssv.c_str()) == 0) {
			tempSt = checkSt->data;
			deleteStudentInClass(listClassSb.classSubject[numberClass]->lsStClass, checkSt->data.mssv);
			listClassSb.classSubject[numberClass]->numberOfStudent -= 1;
			break;
		}
		else if (checkSt == listClassSb.classSubject[numberClass]->lsStClass.pEndStudent) {
			cout << "The student did not existed on class" << endl;
			return;
		}
	}

	cout << "ID class replace: "; getline(cin, tempIdClassReplace);
	int numberClassReplace = checkIdClass(tempIdClassReplace);
	if (numberClassReplace == -1) {
		cout << "The class does not exits" << endl;
		return;
	}

	//check student in class replace
	for (nodeStudentInClass* checkSt = listClassSb.classSubject[numberClassReplace]->lsStClass.pFirstStudent; checkSt != NULL; checkSt = checkSt->pSt) {
		if (_stricmp(tempIdSt.c_str(), checkSt->data.mssv.c_str()) == 0) {
			cout << "The student have been existed on this class" << endl;
			return;
		}
	}

	addToListStudentInClass(listClassSb.classSubject[numberClassReplace]->lsStClass, tempSt);
	listClassSb.classSubject[numberClassReplace]->numberOfStudent += 1;

	cout << "SUCCESFUL";
}

void findStudent() {
	string tempId;

	cleanInput();
	ShowCur(4);
	gotoXY(0, 4);

	cout << "ID student: "; getline(cin, tempId);
	int number = findIdStudent(tempId);
	if (number == -1) {
		cout << "The Student did not existed" << endl;
	}

	cleanShow();
	gotoXY(42, 4);
	cout << "MSSV" << right << setw(16) << "FULL NAME" << right << setw(17) << "PHONE" << right << setw(15) << "GENDER" << right << setw(8) << "MAJOR" << right << setw(15) << "LIST SUBJECT" << endl;
	gotoXY(42, whereY());
	cout << listSt.student[number];
}

//============ config for student =================
void editSubjectForStudent(string tempId, string tempIdReplace) {
	for (int i = 0; i < listSt.amount; i++) {
		for (int j = 0; j < listSt.student[i].listSb.amount; j++) {
			if (_stricmp(tempId.c_str(), listSt.student[i].listSb.subject[j].idSubject.c_str()) == 0) {
				listSt.student[i].listSb.subject[j].idSubject = tempIdReplace;
			}
		}
	}
}

void deleteSubjectOfStudent() {
	cleanInput();
	ShowCur(4);
	gotoXY(0, 4);

	string tempSt;
	cout << "Id student: "; getline(cin, tempSt);
	int number = findIdStudent(tempSt);
	string tempSb; //biến lữu trữ id môn học cần xóa
	cout << "Id subject: "; getline(cin, tempSb);

	for (int i = 0; i < listSt.student[number].listSb.amount; i++) {
		if (_stricmp(tempSb.c_str(), listSt.student[number].listSb.subject[i].idSubject.c_str()) == 0) {
			if (i != listSt.student[number].listSb.amount - 1)
				listSt.student[number].listSb.subject[i] = listSt.student[number].listSb.subject[i + 1];
			listSt.student[number].listSb.amount -= 1;
		}
	}
	cout << "SUCCESFUL";
}

void deleteStudent() {
	cleanInput();
	ShowCur(4);
	gotoXY(0, 4);

	string tempSt;
	cout << "Id student: "; getline(cin, tempSt);
	int number = findIdStudent(tempSt);
	
	//delete student in list student
	if (number != listSt.amount - 1) {
		for (int i = number; i < listSt.amount; i++) {
			listSt.student[i] = listSt.student[i + 1];
		}
	}

	listSt.amount -= 1;
	//delete student in list class
	for (int i = 0; i < listClassSb.amount; i++) {
		for (nodeStudentInClass* check = listClassSb.classSubject[i]->lsStClass.pFirstStudent; check != NULL; check = check->pSt) {
			if (_stricmp(tempSt.c_str(), check->data.mssv.c_str()) == 0) {
				deleteStudentInClass(listClassSb.classSubject[i]->lsStClass, tempSt);
				listClassSb.classSubject[i]->numberOfStudent -= 1;
				break;
			}
		}
	}
	cout << "SUCCESFUL";
}

void addSubjectForStudent() {
	cleanInput();
	ShowCur(4);
	gotoXY(0, 4);

	string tempIdStudent;
	cout << "ID student: "; getline(cin, tempIdStudent);

	int number = findIdStudent(tempIdStudent);
	if (number == -1) {
		cout << "Cannot find your student" << endl;
		return;
	}

	int numberOfSubject;
	cout << "Amount of subject: "; cin >> numberOfSubject;
	cin.ignore();

	string tempSubject;
	for (int i = 0; i < numberOfSubject; i++) {
		if (i == 2) {
			cleanInput;
			gotoXY(0, 4);
		}
		cout << "ID subject: "; getline(cin, tempSubject);
		tempSubject = upcase(tempSubject);

		if (checkIdSubject(tempSubject) == -1) {
			cout << "Cannot find out the subject" << endl;
			continue;
		}
		else if (checkSubjectInStudent(tempSubject) != -1) {
			cout << "This subject have been existed" << endl;
			continue;
		}

		listSt.student[number].listSb.subject[listSt.student[number].listSb.amount++].idSubject = tempSubject;
	}
	cout << "SUCCESFUL";
}


//============ config for subject =================
void editSubject(int number, string tempId) {
	// nhập id subject thay thế
	while (true) {
		cleanMenu();
		ShowCur(4);
		box(11, 19, 20, 2, 7, " MENU EDIT SUBJECT", NULL);
		menu(7, 22, 4, listMenuEditSubject);
		gotoXY(1, 5);
		if (chosen == 0) {
			string replace;
			cout << "Id subject replace: "; getline(cin, replace);
			replace = upcase(replace);
			//xử lý
			listSb.subject[number].idSubject = replace;
			editSubjectForStudent(tempId, replace);
		}
		else if (chosen == 1) {
			string replace;
			cout << "Name subject replace: "; getline(cin, replace);
			replace = upcase(replace, 2);
			//xử lý
			listSb.subject[number].nameSubject = replace;
		}
		else if (chosen == 2) {
			int replace;
			cout << "Id replace: "; cin >> replace;
			//xử lý
			listSb.subject[number].creditSubject = replace;
		}
		else if (chosen == 3) {
			return;
		}
		cout << "SUCCESFUL";
		cleanInput();
	}
}

void deleteSubject() {
	gotoXY(0, 5);
	string temp; //biến lữu trữ id môn học cần thay thế
	cout << "Id: "; getline(cin, temp);
	//xóa trong danh sách môn học
	int number = checkIdSubject(temp);	//số thứ tự của sinh viên
	if (number != listSb.amount - 1) {
		for (int i = number; i < listSb.amount; i++) {
			listSb.subject[i] = listSb.subject[i + 1];
		}
	}
	listSb.amount -= 1;
	//xóa trong danh sách sinh viên
	for (int i = 0; i < listSt.amount; i++) {
		for (int j = 0; j < listSt.student[i].listSb.amount; j++) {
			if (_stricmp(temp.c_str(), listSt.student[i].listSb.subject[j].idSubject.c_str()) == 0) {
				if (j != listSt.student[i].listSb.amount - 1) {
					listSt.student[i].listSb.subject[j] = listSt.student[i].listSb.subject[j + 1];
				}
				listSt.student[i].listSb.amount -= 1;
			}
		}
	}
	cout << "SUCCESFUL";
}

void findSubject() {
	string tempIdSubject;
	cleanInput();
	ShowCur(4);
	gotoXY(1, 4);
	cout << "ID Subject: "; getline(cin, tempIdSubject);

	int number = checkIdSubject(tempIdSubject);

	if (number == -1) {
		cout << "Cannot find your ID subject" << endl;
		return;
	}

	gotoXY(44, 4);
	cout << left << setw(4) << "STT" << right << setw(16) << "ID SUBJECT" << right << setw(16) << "CREDIT" << "\t" << right << setw(14) << "NAME SUBJECT" << endl;
	gotoXY(44, whereY());
	cout << number + 1;
	cout << listSb.subject[number];
}

