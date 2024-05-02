


#include <iostream>
#include <windows.h>
#include <fstream>
#include "tourist_activities.h"
using namespace std;



int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    //C:\\Users\\FedoTT\\source\\repos\\TOPAcademyLearning\\FestiveEvents\\perechen.xlsx    
    char path[] = { "perechen.csv" };
    TouristActivities* asdf = getEvents(path);    

}

