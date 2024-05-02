#include "tourist_activities.h"
#include <fstream>
#include <iostream>
using namespace std;

TouristActivities* getEvents(char filePath[]) {

	ifstream inputFile(filePath);

	if (!inputFile.is_open()) {
		cout << "Íå óäàëîñü îòêðûòü ôàéë";
		return nullptr;
	}

	char junkBuf[1024];
	inputFile.getline(junkBuf, 1024);
	TouristActivities activitieses[15]; // ÎÑÒÎÐÎÆÍÎ ÕÀÐÄÊÎÄ!
	TouristActivities activities;
	int counter = 0;
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
		activities.start = dateToTimeT(start);
		activities.finish = dateToTimeT(finish);

		activitieses[counter++] = activities;

	}

	return activitieses;
}

time_t dateToTimeT(const char* dateStr) {
	struct tm timeStruct = {};
	sscanf_s(dateStr, "%d-%d-%d", &timeStruct.tm_year, &timeStruct.tm_mon, &timeStruct.tm_mday);

	timeStruct.tm_year -= 1900;
	timeStruct.tm_mon -= 1;
	time_t time = mktime(&timeStruct);

	return time;
}

void printEvent(TouristActivities& event)
{
	cout << event.name << endl;
	cout << event.country << endl;
	cout << event.place << endl;
	cout << event.start << endl;
	cout << event.finish << endl;

	cout << "----------------------------------------" << endl;
}

void printEvents(TouristActivities* events, rsize_t size){
	for (size_t i = 0; i < size; i++)
		printEvent(events[i]);	
}

int compare(const void* a, const void* b) {
	return strcmp(((TouristActivities*)a)->name, ((TouristActivities*)b)->name);
}

void sortEventsByName(TouristActivities* activities, size_t count) {
	qsort(activities, count, sizeof(TouristActivities), compare);
}

void searchEventsByDate(TouristActivities* activities, size_t count, const char* date) {
	time_t targetDate = dateToTimeT(date);
	for (size_t i = 0; i < count; ++i) {
		if (activities[i].start <= targetDate && targetDate <= activities[i].finish) {
			cout << "Searched event by date" << "**************" << endl;
			printEvent(activities[i]);
		}
	}
}