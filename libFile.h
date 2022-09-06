#pragma once
#include "libaryFunction.h"

//============ create read and write for subject =================
void addSubjectToFile() {
	//khai báo file
	fstream fp;
	fp.open("listSubjects.txt", ios_base::out);
	//nhập file
	for (int i = 0; i < listSb.amount; i++)	{
		listSb.subject[i].idSubject = lowcase(listSb.subject[i].idSubject);
		fp << listSb.subject[i].idSubject;
		fp << ",";
		
		listSb.subject[i].nameSubject = lowcase(listSb.subject[i].nameSubject);
		fp << listSb.subject[i].nameSubject;
		fp << ",";

		fp << listSb.subject[i].creditSubject;

		if (i != listSb.amount - 1) fp << '\n';
	}
	fp.close();
}

void importSubjectFromFile() {
	//khai báo file
	fstream fp;
	fp.open("listSubjects.txt", ios_base::in);
	//đọc file
	while(!fp.eof()) {
		subject temp;
		
		getline(fp, temp.idSubject, ',');
		temp.idSubject = upcase(temp.idSubject);

		getline(fp, temp.nameSubject, ',');
		temp.nameSubject = upcase(temp.nameSubject, 2);

		fp >> temp.creditSubject;

		fp.ignore();

		//gán gái trị import cho array subject
		listSb.subject[listSb.amount++] = temp;
	}
	fp.close();
}

//============ create read and write for class =================
void addClassToFile() {
	//khai báo file
	fstream fp;
	fp.open("listClass.txt", ios_base::out);
	//đọc file
	for (int i = 0; i < listClassSb.amount; i++)	{
		listClassSb.classSubject[i]->idClass = lowcase(listClassSb.classSubject[i]->idClass);
		fp << listClassSb.classSubject[i]->idClass;
		fp << ",";

		listClassSb.classSubject[i]->idGroup = lowcase(listClassSb.classSubject[i]->idGroup);
		fp << listClassSb.classSubject[i]->idGroup;
		fp << ",";

		listClassSb.classSubject[i]->idSubject = lowcase(listClassSb.classSubject[i]->idSubject);
		fp << listClassSb.classSubject[i]->idSubject;
		fp << ",";

		listClassSb.classSubject[i]->term = lowcase(listClassSb.classSubject[i]->term);
		fp << listClassSb.classSubject[i]->term;
		fp << ",";

		listClassSb.classSubject[i]->nameMentor = lowcase(listClassSb.classSubject[i]->nameMentor);
		fp << listClassSb.classSubject[i]->nameMentor;
		fp << ",";

		fp << listClassSb.classSubject[i]->numberOfStudent;

		if (i != listClassSb.amount - 1)	fp << '\n';
	}
	fp.close();
}

void importCLassFromFile() {
	//khai báo file
	fstream fp;
	fp.open("listClass.txt", ios_base::in);
	//đọc file
	while (!fp.eof())	{
		classSubject temp;

		getline(fp, temp.idClass, ',');
		temp.idClass = upcase(temp.idClass);

		getline(fp, temp.idGroup, ',');
		temp.idGroup = upcase(temp.idGroup);

		getline(fp, temp.idSubject, ',');
		temp.idSubject = upcase(temp.idSubject);

		getline(fp, temp.term, ',');
		temp.term = upcase(temp.term);

		getline(fp, temp.nameMentor, ',');
		temp.nameMentor = upcase(temp.nameMentor, 2);

		fp >> temp.numberOfStudent;

		fp.ignore();

		//gán giá trị đã lấy được
		listClassSb.classSubject[listClassSb.amount] = new classSubject;
		*listClassSb.classSubject[listClassSb.amount++] = temp;
	}
	fp.close();
}

//============ create read and write for data on each class =================
void addListStudentInClass() {
	fstream fp;
	fp.open("ListStudentInClass.txt", ios_base::out);
	for (int i = 0; i < listClassSb.amount; i++) {
		for (nodeStudentInClass* check = listClassSb.classSubject[i]->lsStClass.pFirstStudent; check != NULL; check = check->pSt) {
			check->data.mssv = lowcase(check->data.mssv);
			fp << check->data.mssv;
			fp << ",";

			fp << check->data.mark;
			fp << ",";

			check->data.evaluation = lowcase(check->data.evaluation);
			fp << check->data.evaluation;

			if (check != listClassSb.classSubject[listClassSb.amount - 1]->lsStClass.pEndStudent) fp << '\n';
		}
	}
	fp.close();
}

void importListStudentInClass() {
	fstream fp;
	fp.open("listStudentInClass.txt", ios_base::in);
	while (!fp.eof())	{
		for (int i = 0; i < listClassSb.amount; i++) {
			for (int j = 0; j < listClassSb.classSubject[i]->numberOfStudent; j++) {
				studentInClass temp;

				getline(fp, temp.mssv, ',');
				temp.mssv = upcase(temp.mssv);

				fp >> temp.mark;
				fp.ignore();

				getline(fp, temp.evaluation, '\n');
				temp.evaluation = upcase(temp.evaluation);
				
				addToListStudentInClass(listClassSb.classSubject[i]->lsStClass, temp);
			}
		}
	}
	fp.close();
}

//============ create read and write for student =================
void addStudentToFile() {
	fstream fp;
	fp.open("listStudents.txt", ios_base::out);

	for (int i = 0; i < listSt.amount; i++) {
		listSt.student[i].mssv = lowcase(listSt.student[i].mssv);
		fp << listSt.student[i].mssv;
		fp << ",";

		listSt.student[i].fullName = lowcase(listSt.student[i].fullName);
		fp << listSt.student[i].fullName;
		fp << ",";

		listSt.student[i].gender = lowcase(listSt.student[i].gender);
		fp << listSt.student[i].gender;
		fp << ",";

		fp << listSt.student[i].phone;
		fp << ",";

		listSt.student[i].major = lowcase(listSt.student[i].major);
		fp << listSt.student[i].major;
		fp << ",";

		fp << listSt.student[i].listSb.amount;
		if (i != listSt.amount - 1)	fp << '\n';
	}

	fp.close();
}

void importStudentFromFile() {
	fstream fp;
	fp.open("listStudents.txt", ios_base::in);

	while (!fp.eof()) {
		student temp;

		getline(fp, temp.mssv, ',');
		temp.mssv = upcase(temp.mssv);

		getline(fp, temp.fullName, ',');
		temp.fullName = upcase(temp.fullName, 2);

		getline(fp, temp.gender, ',');
		temp.gender = upcase(temp.gender, 2);

		getline(fp, temp.phone, ',');

		getline(fp, temp.major, ',');
		temp.major = upcase(temp.major);

		//fp >> temp.amoutfSubject;
		fp >> temp.listSb.amount;
		fp.ignore();
		
		listSt.student[listSt.amount++] = temp;
	}

	fp.close();
}

//another function support
/*
void importDataSubjectOfStudent() {
	fstream fp;
	fp.open("listSubjectOfStudent.txt", ios_base::in);
	
	while (!fp.eof())	{
		student tempSt;
		classSubject tempCl;
		getline(fp, tempSt.mssv, ',');
		tempSt.mssv = upcase(tempSt.mssv);
		int number = findIdStudent(tempSt.mssv);
		if (number != -1)
			for (int j = 0; j < listSt.student[number].amoutOfSubject; j++)	{
				//listSt.student[i].listClassSb->classSubject[listClassSb.amount] = new classSubject;
				if (j != listSt.student[number].amoutOfSubject - 1) {
					getline(fp, tempCl.idClass, ',');
				}
				else {
					getline(fp, tempCl.idClass);
				}
				
				//thêm dữ liệu vào từng sinh viên sau khi đã lấy mã lớp
				for (int i = 0; i < listClassSb.amount; i++)	{
					if (_stricmp(tempCl.idClass.c_str(), listClassSb.classSubject[i]->idClass.c_str()) == 0) {
						//listSt.student[i].listClassSb.classSubject[listSt.student[number].listClassSb.amount] = new listClassSubject;
						listSt.student[number].listClassSb.classSubject[listSt.student[number].listClassSb.amount++] = listClassSb.classSubject[i]; //lỗi						
					}
				}
			}
	}

	fp.close();
}
*/

//another function support
void addDataSubjectOfStudent() {
	fstream fp;
	fp.open("listSubjectOfStudent.txt", ios_base::out);

	for (int i = 0; i < listSt.amount; i++) {

		listSt.student[i].mssv = lowcase(listSt.student[i].mssv);
		fp << listSt.student[i].mssv;
		fp << ",";

		for (int j = 0; j < listSt.student[i].listSb.amount; j++) {
			listSt.student[i].listSb.subject[j].idSubject = lowcase(listSt.student[i].listSb.subject[j].idSubject);
			fp << listSt.student[i].listSb.subject[j].idSubject;
			if (j != listSt.student[i].listSb.amount - 1) fp << ",";
		}
		if (i != listSt.amount - 1) fp << '\n';
	}

	fp.close();
}

void importDataSubjectOfStudent() {
	fstream fp;
	fp.open("listSubjectOfStudent.txt", ios_base::in);

	while (!fp.eof()) {
		string tempSubject;
		string tempId;


		getline(fp, tempId, ',');

		int number = listSt.student[findIdStudent(tempId)].listSb.amount;

		for (int i = 0; i < number; i++) {
			if (i != number - 1) {
				getline(fp, tempSubject, ',');
			}
			else {
				getline(fp, tempSubject);
			}

			tempSubject = upcase(tempSubject);

			listSt.student[findIdStudent(tempId)].listSb.subject[i].idSubject = tempSubject;
		}
	}
	fp.close();
} 

void importData() {
	importSubjectFromFile();
	importCLassFromFile();
	importStudentFromFile();
	importListStudentInClass();
	importDataSubjectOfStudent();
}

void saveFile() {
	addClassToFile();
	addStudentToFile();
	addSubjectToFile();
	addListStudentInClass();
	addDataSubjectOfStudent();
}
