#ifndef ALARM_H
#define ALARM_H

#include <Arduino.h>
#include <Relay.h>

class Alarm {

	public:
		Alarm(Relay *relay, unsigned int relayPin);
		unsigned long *activate(void);
		unsigned long *deactivate(void);
		unsigned long *toggle(void);
		unsigned long *lastMillis(void);
		bool state(void);

	private:
		Relay *_relay;
		unsigned int _relayNum;
		unsigned long _lastActionMillis;

		void _setLastActionMillis(void);

};

#endif // !ALARMCONTROLLER_H
