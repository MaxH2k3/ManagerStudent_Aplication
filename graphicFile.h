#pragma once
#include "source.h";

using namespace std;

void title1() {
    //khai báo file
    fstream fp;

    fp.open("S:\\projectC++\\ManagerStudent\\ManagerStudent(new)\\ManagerStudent(new)\\graphic\\title1.txt", ios_base::in);
    //đọc file
    string ch;
    int y = 13;
    while (!fp.eof()) {
        gotoXY(40, y);
        getline(fp, ch, '\n');
        cout << ch;
        cout << "\n";
        y++;
    }
    fp.close();
}

void title2() {
    //khai báo file
    fstream fp;

    fp.open("S:\\projectC++\\ManagerStudent\\ManagerStudent(new)\\ManagerStudent(new)\\graphic\\title2.txt", ios_base::in);
    //đọc file
    string ch;
    int y = 1;
    while (!fp.eof()) {
        gotoXY(5, y);
        if (y < 16) {
            textcolor(y);
        }
        else {
            textcolor(y - 15);
        }
        getline(fp, ch, '\n');
        cout << ch;
        cout << "\n";
        y++;
    }
    fp.close();
    textcolor(7);
}

void title3() {
    //khai báo file
    fstream fp;

    fp.open("S:\\projectC++\\ManagerStudent\\ManagerStudent(new)\\ManagerStudent(new)\\graphic\\title3.txt", ios_base::in);
    //đọc file
    string ch;
    int y = 31;
    while (!fp.eof()) {
        gotoXY(18, y);
        if (y > 30 && y < 33) {
            textcolor(2);
        }
        else if (y > 32 && y < 35) {
            textcolor(3);
        }
        else textcolor(6);
        getline(fp, ch, '\n');
        cout << ch;
        cout << "\n";
        y++;
    }
    fp.close();
    textcolor(7);
}

void title4() {
    //khai báo file
    fstream fp;

    fp.open("S:\\projectC++\\ManagerStudent\\ManagerStudent(new)\\ManagerStudent(new)\\graphic\\title4.txt", ios_base::in);
    //đọc file
    string ch;
    int y = 0;
    while (!fp.eof()) {
        textcolor(3);
        gotoXY(60, y);
        getline(fp, ch, '\n');
        cout << ch;
        cout << "\n";
        y++;
    }
    fp.close();
    textcolor(7);
}

void title5() {
    //khai báo file
    fstream fp;

    fp.open("S:\\projectC++\\ManagerStudent\\ManagerStudent(new)\\ManagerStudent(new)\\graphic\\title5.txt", ios_base::in);
    //đọc file
    string ch;
    int y = 20;
    while (!fp.eof()) {
        if (y > 25) textcolor(11);
        gotoXY(82, y);
        getline(fp, ch, '\n');
        cout << ch;
        cout << "\n";
        y++;
    }
    fp.close();
    textcolor(7);
}

void graphicTitle() {
    title1();
    title2();
    title3();
    title4();
    title5();
    gotoXY(46, 17);
    cout << "HELLO GUY, NICE TO MEET YOU";
    gotoXY(45, 18);
    cout << "This app is just a free";
    gotoXY(45, 19);
    cout << "functional trial version. So,";
    gotoXY(45, 20);
    cout << "it is exist some fault.";
    gotoXY(45, 23);
    cout << "GOOD LUCK";
    ShowCur(0);
    getchar(); 
}

//======================================

void createLine1() {
    for (int i = 0; i < 37; i++) {
        gotoXY(40, i);
        cout << char(186);
    }
}

void createLine2() {
    for (int i = 0; i < 40; i++) {
        gotoXY(i, 18);
        cout << char(205);
    }
    cout << char(185);
}

void createLine3() {
    textcolor(14);
    for (int i = 55; i < 120; i++) {
        gotoXY(i, 3);
        cout << char(176);
    }
    textcolor(7);

    box(9, 0, 17, 2, 11, "INPUT DATA", 10);
    box(76, 0, 23, 2, 7, "SHOW INFORMATION", 14);
}

void createLine() {
    createLine1();
    createLine2();
    createLine3();
}

