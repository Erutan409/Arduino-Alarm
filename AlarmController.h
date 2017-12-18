#ifndef ALARMCONTROLLER_H
#define ALARMCONTROLLER_H

#include <Arduino.h>
#include <Relay.h>
#include <StandardCplusplus.h>
#include <vector>

using namespace std;

typedef vector<struct Alarm> Alarm_vector;

struct Alarm {

	public:
		Alarm(unsigned int pin) {this->_pin = pin;};
		Alarm &pattern(void) {return *this;};
		unsigned int *getPin(void) {return &this->_pin;}

	private:
		unsigned int _pin;

};

class AlarmController {

	public:
		AlarmController(Relay *relay);
		Alarm &addAlarm(Alarm alarm);
		bool removeAlarm(Alarm *alarm);
		unsigned int getAlarmSize(void);

	private:
		Relay *_relay;
		Alarm_vector _alarms;


};

#endif // !ALARMCONTROLLER_H
