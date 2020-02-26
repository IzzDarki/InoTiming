#include <Arduino.h>

#include <IOStream.h>
#include <MillisTimer.h>

ino::MillisTimer Timer(500);

void setup()
{
	ino::out.begin(9600);
}

void loop()
{
	if (Timer.Cycle())
		ino::out << "New cycle - millis: " << millis() << ino::endl;
}
