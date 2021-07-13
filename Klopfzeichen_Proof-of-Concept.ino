/*Der Proof of Concept ist dafür da zu überprüfen, 
 * ob ein Klopfzeichen dem zuvor in einem Array abgespeicherten Klopfzeichen 
 * in Anzahl der Klopfer und Stärke des Schwellenwerts entspricht.
 * Quelle: https://youtu.be/-TQpgyTgcQ8 */

const int outputPin = 6; //hier könnte eine LED angeschlossen werden
const int knockSensor = A0;
const int thresholdHIGH = 20; 
const int thresholdLOW = 10;

const int secretKnockLength = 5;

/*
 * 0 -> leiser Klopfer
 * 1 -> lauter Klopfer
 */
const int secretKnock[secretKnockLength] = {1,1,0,0,1};

int secretCounter = 0;
int sensorReading = 0;

void setup() {
  pinMode(outputPin, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  sensorReading = analogRead(knockSensor);

//Lauter Klopfer
if(sensorReading >= thresholdHIGH)
{
    if(secretKnock[secretCounter] == 1)
    {
        secretCounter++;
        Serial.println("Correct");
        
    }
    else
    {
        secretCounter = 0;
        Serial.println("WRONG!!!");
    }

    delay(100);
}

//Leiser Klopfer
else if(sensorReading >= thresholdLOW)
{
    if(secretKnock[secretCounter] == 0)
    {
        secretCounter++;
        Serial.println("Correct");
    }
    else
    {
        secretCounter = 0;
        Serial.println("WRONG!!!");
    }

    delay(100);
}

if(secretCounter == (secretKnockLength))
{
    Serial.println("Yeah you made it!");

    digitalWrite(outputPin, HIGH);//schaltet die LED ein
    delay(3000);
    digitalWrite(outputPin, LOW);//schaltet die LED aus
    secretCounter = 0;
}

}
