#pragma once
#include <string>
using namespace std;

class Event {
public:
	Event(string wireName, int time, int value) {
		this->value = value;
		this->time = time;
		this->wireName = wireName;
	}
	string getName() const { return wireName; }
	int getValue() const { return value; }
	int getTime() const { return time; }
private:
	string wireName;
	int time;
	int value;
};