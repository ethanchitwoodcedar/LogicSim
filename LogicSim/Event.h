#pragma once
#include <string>
using namespace std;

class Event {
public:
	Event(int key, int time, int value) {
		this->value = value;
		this->time = time;
		this->key = key;
	}
	int getKey() const { return key; }
	int getValue() const { return value; }
	int getTime() const { return time; }
private:
	int key;
	int time;
	int value;
};