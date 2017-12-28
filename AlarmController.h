#ifndef ALARM_H
#define ALARM_H

#include <Arduino.h>
#include <Relay.h>

class Alarm {

	public:
		Alarm(Relay *relay, uint8_t relayPin);
		uint32_t *activate(void);
		uint32_t *deactivate(void);
		uint32_t *toggle(void);
		uint32_t *lastMillis(void);
		bool state(void);

	private:
		Relay *_relay;
		int8_t _relayNum;
		uint32_t _lastActionMillis;

		void _setLastActionMillis(void);

};

#endif // !ALARMCONTROLLER_H
