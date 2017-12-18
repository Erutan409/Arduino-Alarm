#include <AlarmController.h>

AlarmController::AlarmController(Relay *relay) {
	this->_relay = relay;
}

Alarm &AlarmController::addAlarm(Alarm alarm) {
	this->_alarms.push_back(alarm);

	return this->_alarms.back();
}

bool AlarmController::removeAlarm(Alarm *alarm) {
	Alarm_vector *alarms = &this->_alarms;

	for (int i = 0; i < (*alarms).size(); i++) {
		Alarm *current = &(*alarms).at(i);

		if (alarm == current) {
			(*alarms).erase((*alarms).begin() + i);
			return true;
		}
	}
	
	return false;
}

unsigned int AlarmController::getAlarmSize(void) {
	return this->_alarms.size();
}