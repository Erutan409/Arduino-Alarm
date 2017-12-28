#include <AlarmController.h>

Alarm::Alarm(Relay *relay, uint8_t relayPin) {
	this->_relay = relay;
	this->_relayNum = (*this->_relay).getRelayByPin(relayPin);
}

uint32_t *Alarm::activate(void) {
	(*this->_relay).on(this->_relayNum).commit();
	this->_setLastActionMillis();

	return this->lastMillis();
}

uint32_t *Alarm::deactivate(void) {
	(*this->_relay).off(this->_relayNum).commit();
	this->_setLastActionMillis();

	return this->lastMillis();
}

uint32_t *Alarm::toggle(void) {
	if (this->state()) {
		return this->deactivate();
	}
	else {
		return this->activate();
	}
}

uint32_t *Alarm::lastMillis(void) {
	return &this->_lastActionMillis;
}

bool Alarm::state(void) {
	return *(*this->_relay).getState(this->_relayNum) == RELAY_ON;
}

void Alarm::_setLastActionMillis(void) {
	this->_lastActionMillis = millis();
}