#ifndef ALARM_H
#define ALARM_H

#include <Arduino.h>
#include <Relay.h>

class Alarm {

	public:
		Alarm(Relay *relay, unsigned int relayPin);
		uint32_t *activate(void);
		unsigned long *deactivate(void);
		unsigned long *toggle(void);
		uint32_t *lastMillis(void);
		bool state(void);

	private:
		Relay *_relay;
		unsigned int _relayNum;
		unsigned long _lastActionMillis;

		void _setLastActionMillis(void);

};

#endif // !ALARMCONTROLLER_H
