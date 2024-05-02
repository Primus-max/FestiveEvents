


#include <iostream>
#include <windows.h>
#include <fstream>
#include "tourist_activities.h"
using namespace std;



int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
        
    char path[] = { "perechen.csv" };
    TouristActivities* events = getEvents(path);       

    printEvents(events, 15);
}

