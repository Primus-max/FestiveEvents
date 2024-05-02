#include "tourist_activities.h"
#include <iostream>
#include <fstream>
using namespace std;

TouristActivities* getEvents(char filePath[]) {
    
    ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        cout << "�� ������� ������� ����";
        return nullptr;
    }      

    char junkBuf[1024];
    inputFile.getline(junkBuf, 1024);
    TouristActivities* activitieses;
    TouristActivities activities;

    while (!inputFile.eof()) {
        inputFile.getline(junkBuf, 1024, ',');
        inputFile.getline(activities.name, sizeof(activities.name), ',');
        inputFile.getline(junkBuf, 1024, ',');
        inputFile.getline(junkBuf, 1024, ',');
        inputFile.getline(activities.country, sizeof(activities.country), ',');
        inputFile.getline(activities.place, sizeof(activities.place), ',');

        char start[100];
        char finish[5000];
        char finishLine[5000]{};
        inputFile.getline(finishLine, sizeof(finishLine));
        char* lastComma = strrchr(finishLine, ',');
        if (lastComma) {
            int len = strlen(lastComma + 1);
            if (len > sizeof(finish)) {
                strncpy_s(finish, sizeof(finish), lastComma + 1 + (len - sizeof(finish)), _TRUNCATE);
            }
            else {
                strncpy_s(finish, sizeof(finish), lastComma + 1, _TRUNCATE);
            }
            *lastComma = '\0';
            char* secondLastComma = strrchr(finishLine, ',');
            if (secondLastComma) {
                len = strlen(secondLastComma + 1);
                if (len > sizeof(start)) {
                    strncpy_s(start, sizeof(start), secondLastComma + 1 + (len - sizeof(start)), _TRUNCATE);
                }
                else {
                    strncpy_s(start, sizeof(start), secondLastComma + 1, _TRUNCATE);
                }
            }
        }
        activities.finish = 345345;
        cout << finish << endl;
        cout << start << endl;
    }

    return nullptr;
}