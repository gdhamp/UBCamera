//
// LEDs are connected in order from pin 2 to pin 49
//
// Camera has Focus on pin 52 and shutter on pin 53
//
// 

#define FOCUS 52
#define SHUTTER 53
bool firstTime;
void setup()
{
	int i;

	firstTime = true;

	for(i=2; i<50; i++)
	{
  		pinMode(i, OUTPUT);
		digitalWrite(i, LOW);
	}
	
	pinMode(FOCUS, OUTPUT);
	digitalWrite(FOCUS, HIGH);
	
	pinMode(SHUTTER, OUTPUT);
	digitalWrite(SHUTTER, HIGH);
}

// the loop function runs over and over again forever
void loop()
{
	int i;

	for(i=2; i<50; i++)
  	{
		// turn on LED
		digitalWrite(i, HIGH);
		delay(2000);

		// tell camera to focus
		digitalWrite(FOCUS, LOW);
		delay(2000);

		// triggerr the camera's shutter
		digitalWrite(SHUTTER, LOW);
		delay(1000);

	
		// deactivate both focus and shutter
		digitalWrite(FOCUS, HIGH);
		digitalWrite(SHUTTER, HIGH);

		// turn LED off
		digitalWrite(i, LOW);
	}
}
