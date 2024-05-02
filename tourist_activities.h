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
void printEvent(TouristActivities& event);
void printEvents(TouristActivities* events, rsize_t size);
void sortEventsByName(TouristActivities* activities, size_t count);
int compare(const void* a, const void* b);
void searchEventsByDate(TouristActivities* activities, size_t count, const char* date);