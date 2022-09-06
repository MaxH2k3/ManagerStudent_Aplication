#pragma once
#include <iostream>
#include "source.h"
#include <string.h>

using namespace std;
#define MAX 1000

char listMenuTitle[][MAX] = {"SUBJECT", "CLASS", "STUDENT","PRINT DATA", "EXIT"};
char listMenuSubject[][MAX] = { "Create Subject", "Edit Subject", "Find Subject","Delete Subject", "Back" };
char listMenuClass[][MAX] = { "Create Class", "Edit Class", "Find Class","Transfer Student", "Add new Student", "Delete Class", "Back"};
char listMenuPrint[][MAX] = { "Print all subject", "Print all class", "Print all student","Print student in class", "Back"};
char listMenuStudent[][MAX] = { "Create Student", "Find Student", "Delete Student","Add subject", "Delete Subject", "Back"};
char listMenuEditClass[][MAX] = { "Edit ID", "Edit name mentor", "Back" };
char listMenuEditSubject[][MAX] = { "Edit ID", "Edit Name", "Edit Credit", "Back"};

//int chosen;

void box(int x, int y, int width, int height, int lineColor, string str, int textColor) {
    //set up text color
    if (textColor == NULL) {
        SetColor(7);
        gotoXY(x + (width - str.size() + 1) / 2, y + 1);
        cout << str;
    }
    else {
        SetColor(textColor);
        gotoXY(x + (width - str.size() + 1) / 2, y + 1);
        cout << str;
    }
    //set up color on the line box
    SetColor(lineColor);
    for (int box_x = x; box_x <= x + width; box_x++) {
        gotoXY(box_x, y);
        cout << char(196);
    }
    for (int box_x = x; box_x <= x + width; box_x++) {
        gotoXY(box_x, y + height);
        cout << char(196);
    }

    for (int box_y = y; box_y <= y + height; box_y++) {
        gotoXY(x, box_y);
        cout << char(179);
    }
    for (int box_y = y; box_y <= y + height; box_y++) {
        gotoXY(x + width, box_y);
        cout << char(179);
    }

    gotoXY(x, y); cout << char(218);
    gotoXY(x + width, y); cout << char(191);
    gotoXY(x, y + height); cout << char(192);
    gotoXY(x + width, y + height); cout << char(217);
}



void create_light(int positionX, int positionY, int width, int height, int backgroundColor, string str) {
    textcolor(backgroundColor * 16 + 7);
    for (int i = positionY + 1; i < height + positionY; i++) {
        for (int j = positionX + 1; j < width + positionX; j++) {
            gotoXY(j, i);
            cout << " ";
        }
    }
    //print out string agin
    SetColor(7);
    gotoXY(positionX + (width - str.size() + 1) / 2, positionY + 1);
    cout << str;
    textcolor(7);
}

void menu(int box_x, int box_y, int amountOfElement, char listMenu[][MAX]) {
    ShowCur(0);
    //properties menu
    int nameMenu = 0; //number of array name menu
    int width = 25;
    int height = 2;
    int lineColor = 9; //light on line box
    int backgroundColor = 12; //light inside box
    string str;
    //
    for (int i = 0; i < amountOfElement; i++) {
        box(box_x, box_y + (i + i), width, height, lineColor, listMenu[i], NULL);
        if (i != 0) {
            gotoXY(box_x, box_y + (i + i)); cout << char(195);
            gotoXY(box_x + width, box_y + (i + i)); cout << char(180);
        }
    }

    //control lighting inside menu
    int light_x = box_x;
    int light_y = box_y;
    int light_oldX = light_x;
    int light_oldY = light_y;
    string old_str = listMenu[nameMenu];
    bool flag = true;
    while (true) {
        //operation
        if (flag == true) {
            //reset box color
            create_light(light_oldX, light_oldY, width, height, 0, old_str);
            light_oldX = light_x;
            light_oldY = light_y;
            old_str = listMenu[nameMenu];
            //
            create_light(light_x, light_y, width, height, backgroundColor, listMenu[nameMenu]);
            flag = false;
        }

        if (_kbhit() == true) {
            char userControl = _getch();
            if (userControl == -32) {
                flag = true;
                userControl = _getch();
                if (userControl == 72) {
                    if (light_y != box_y) {
                        light_y -= 2; //up
                        nameMenu -= 1;
                    }
                    else {
                        light_y = box_y + height * (amountOfElement - 1);
                        nameMenu = 3;
                    }
                }
                else if (userControl == 80) {
                    if (light_y != box_y + height * (amountOfElement - 1)) {
                        light_y += 2;   //down
                        nameMenu += 1;
                    }
                    else {
                        light_y = box_y;
                        nameMenu = 0;
                    }
                }
            }
            else if (userControl == 13) {
                chosen = (light_y - box_y) / 2;
                break;
            }
        }
    }
}










