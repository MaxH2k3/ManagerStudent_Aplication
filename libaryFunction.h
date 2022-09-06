#pragma once
#include <iostream>
#include <string>
using namespace std;

//function canculate the length of string
int len(string str) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}


/*hàm viết hoa
str: your string you want to upcase;
number: that is a number of character you want upcase
NOTE: default is upcase all
*/
string upcase(string str, int number = NULL) {
    if (number == 2) {
        int i = 1;
        if (str[0] >= 'a' && str[0] <= 'z') str[0] -= 32;
        while (str[i] != '\0') {
            if (str[i] == ' ' && str[i + 1] >= 'a' && str[i + 1] <= 'z') str[i + 1] -= 32;
            i++;
        }
    }

    else {
        number = len(str);
        for (int i = 0; i < number; i++) {
            if (str[i] >= 'a' && str[i] <= 'z') str[i] = str[i] - 32;
        }
    }

    return str;
}


/*hàm viết thường
str: your string you want to lowcase;
number: that is a number of character you want lowcase
NOTE: default is lowcase all
*/
string lowcase(string str, int number = NULL) {
    if (number == NULL) {
        number = len(str);
    }

    for (int i = 0; i < number; i++)    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }
    return str;
}

/* hàm tạo một danh sách học sinh mới
* st: an attribute for user input to create new student
*/
nodeStudentInClass* createNodeStudent(studentInClass stClass) {
    nodeStudentInClass* p = new nodeStudentInClass;
    p->data = stClass;
    p->pSt = NULL;
    return p;
}

/* hàm thêm sau một danh sách học sinh
* listSt: a list to save data
* st: an attribute for user input to create new student
*/
void addToListStudentInClass(listStudentInClass &listStClass, studentInClass stClass) {
    nodeStudentInClass* p = createNodeStudent(stClass);
    if (listStClass.pFirstStudent == NULL)  {
        listStClass.pFirstStudent = listStClass.pEndStudent = p;
    }
    else {
        listStClass.pEndStudent->pSt = p;
        listStClass.pEndStudent = p;
    }
}

void deleteStudentInClass(listStudentInClass &listStClass, string idStudent) {
    nodeStudentInClass *temp = listStClass.pFirstStudent;
    for (nodeStudentInClass* check = listStClass.pFirstStudent; check != NULL; check = check->pSt) {
        if (_stricmp(check->data.mssv.c_str(), idStudent.c_str()) == 0) {
            temp->pSt = check->pSt;
            delete check;
            check = temp;
            if (temp->pSt == NULL) {
                listStClass.pEndStudent = temp;
                return;
            }
            //return;
        }
        temp = check;
    }
}

/* hàm kiểm tra mã số sinh viên có trong các danh sách hiện có
*  
*/
int findIdStudent(string tempId) {
    for (int i = 0; i < listSt.amount; i++) {
        if (_stricmp(tempId.c_str(), listSt.student[i].mssv.c_str()) == 0) {
            return i;
            }
        }
    return -1;
}

int checkIdClass(string tempId) {
    for (int i = 0; i < listClassSb.amount; i++) {
        if (_stricmp(tempId.c_str(), listClassSb.classSubject[i]->idClass.c_str()) == 0) {
            return i;
        }
    }
    return -1;
}

int checkIdSubject(string tempId) {
    for (int i = 0; i < listSb.amount; i++) {
        if (_stricmp(tempId.c_str(), listSb.subject[i].idSubject.c_str()) == 0) {
            return i;
        }
    }
    return -1;
}

/* hàm xóa vùng input data
*/
void cleanInput() {
    gotoXY(0, 4);
    for (int i = 1; i < 15; i++) {
        for (int j = 0; j < 37; j++) {
            cout << " ";
        }
        if (i != 14)
        cout << "\n";
    }
}

/* hàm xóa vùng menu
*/
void cleanMenu() {
    gotoXY(0, 19);
    for (int i = 1; i < 19; i++) {
        for (int j = 1; j < 41; j++) {
            cout << " ";
        }
        if (i != 18)
        cout << "\n";
    }
}

/* hàm xóa vùng show information
*/
void cleanShow() {
    gotoXY(42, 4);
    for (int i = 1; i < 34; i++) {
        gotoXY(42, whereY());
        for (int j = 1; j < 89; j++) {
            cout << " ";
        }
        if (i != 33)
            cout << "\n";
    }
}

byte checkSubjectInStudent(string tempSubject) {
    for (int j = 0; j < listSt.amount; j++) {
        for (int t = 0; t < listSt.student[j].listSb.amount; t++) {
            if (_stricmp(listSt.student[j].listSb.subject[t].idSubject.c_str(), tempSubject.c_str()) == 0) {
                return j;
            }
        }
    }
    return -1;
}




