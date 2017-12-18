#ifndef ALARMCONTROLLER_H
#define ALARMCONTROLLER_H

#include <Arduino.h>
#include <Relay.h>
#include <StandardCplusplus.h>
#include <vector>

typedef std::vector<struct Alarm> Alarm_vector;

struct Alarm {

public:
	Alarm(unsigned int pin);
	Alarm pattern(void);

};

class AlarmController {

	public:
		AlarmController(Relay *relay);
		AlarmController &addAlarm(Alarm alarm);

	private:
		Relay *_relay;
		Alarm_vector _alarms;


};

#endif // !ALARMCONTROLLER_H
