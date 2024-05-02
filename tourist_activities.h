#pragma once

#include <time.h>


struct  TouristActivities
{
	char name[255]{};
	char country[100]{};
	char place[100]{};
	time_t start;
	time_t finish;
};

TouristActivities* getEvents(char filePath[]);
time_t dateToTimeT(const char* dateStr);