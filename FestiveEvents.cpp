


#include <iostream>
#include <windows.h>
#include <fstream>
#include "tourist_activities.h"
using namespace std;



int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
        
    const size_t size = 15;
    char path[] = { "perechen.csv" };
    TouristActivities* events = getEvents(path);       

    cout << "Before" << " ----------------" << endl;
    printEvents(events, size);

    sortEventsByName(events, size);

    cout << "After" << " ----------------" << endl;
    printEvents(events, size);

    char date[12];
    cout << "Search event by date, format date like YY-mm-DD" << "" << endl;
    cin >> date;

    searchEventsByDate(events, size, date);
 }

