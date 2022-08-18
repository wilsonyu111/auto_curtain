#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

int getDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);

  return duration * SOUND_VELOCITY / 2;
}

float toInch(float val)
{
  return val * CM_TO_INCH;
}
