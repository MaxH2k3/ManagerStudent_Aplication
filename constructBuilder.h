#pragma once
#include <iostream>
#include <string>

using namespace std;

#define MAX 100 

//building for subject
typedef struct subject {
	string idSubject; //mã môn học (ví dụ là mae, prf,...)
	string nameSubject; //tên môn họn (ví dụ là software engineering,...)
	int creditSubject; //số tín chỉ môn học
} subject;

typedef struct listSubject {
	subject subject[MAX];
	int amount = 0;
} listSubject;
// =====================================

//building for list student on each class
typedef struct studentInClass {
	string mssv; //mã số sinh viên
	int mark; //điểm của sinh viên có trong lớp
	string evaluation; //xếp loại môn học đó của sinh viên
} studentInClass;

typedef struct nodeStudentInClass nodeStudentInClass;

struct nodeStudentInClass {
	studentInClass data; //dữ liệu của một học sinh
	nodeStudentInClass* pSt; //con trỏ của struct học sinh
};

typedef struct listStudentInClass {
	nodeStudentInClass* pFirstStudent = NULL;
	nodeStudentInClass* pEndStudent = NULL;
}listStudentInClass;
// =====================================
//building for class
typedef struct classSubject {
	string idClass; //mã lớp (ví dụ là mae101, mae201,...)
	string idGroup; //nhóm lớp (ví dụ là SE1729, SE1723,...)
	string idSubject;
	string term; //học kỳ tên gì (ví dụ là fall2022, summer2021,...)
	string nameMentor; //tên giáo viên đứng lớp
	int numberOfStudent = 0; //số lượng sinh viên trong mỗi lớp
	listStudentInClass lsStClass; //danh sách sinh viên của từng lớp
} classSubject;

typedef struct listClassSubject {
	classSubject* classSubject[MAX];
	int amount = 0;
} listClassSubject;
// =====================================
//building for student
typedef struct student {
	string mssv;
	string fullName;
	string gender;
	string phone;
	string major;
	//int amoutOfSubject = 0;
	listSubject listSb; // danh sách các lớp học đã tham gia của sinh viên
} student;

typedef struct listStudent {
	student student[MAX]; //danh sách tất cả sinh viên
	int amount = 0; //số lượng sinh viên hiện có
} listStudent;
// =====================================



//assign variable
listStudent listSt; //danh sách học sinh
listSubject listSb;	//danh sách môn học
listClassSubject listClassSb; //danh sách lớp học
listStudentInClass listStInClass; //danh sách học của từng lớp

