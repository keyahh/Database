#include "States.h"

States::States()
{
	for (int i = 0; i < LASTSTATE; ++i)
	{
	}
}

void States::enableState(stateEnum state)
{
	_states[state] = true;
}

void States::disableState(stateEnum state)
{
	_states[state] = false;
}

void States::toggleState(stateEnum state)
{
	_states[state] = !_states[state];
}

const bool States::checkState(stateEnum state) const
{
	return _states.at(state);
}
