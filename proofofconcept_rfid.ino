#include <SPI.h> // Serielle Schnittstelle - SPI-Bibiothek 
#include <MFRC522.h> // RFID Bibliothek 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); // RFID-Empfänger benennen

void setup()
{
Serial.begin(9600); // Serielle Verbindung starten (Monitor)
SPI.begin(); // SPI-Verbindung aufbauen
mfrc522.PCD_Init(); // Initialisierung des RFID-Empfängers
}

void loop()
{
  
if ( ! mfrc522.PICC_IsNewCardPresent()) // Wenn keine Karte in Reichweite ist...
{
return; // wiederholt es sich von Anfang an 
}

if ( ! mfrc522.PICC_ReadCardSerial()) // Wenn kein RFID-Sender ausgewählt wurde...
{
return; // wiederholt es sich von Anfang an 
}

long code=0; // Als neue Variable fügen wir „code“ hinzu, unter welcher später die ID ausgegeben wird. Statt int benutzen wir jetzt den Zahlenbereich „long“, weil sich dann eine größere Zahl speichern lässt.

for (byte i = 0; i < mfrc522.uid.size; i++)
{
code=((code+mfrc522.uid.uidByte[i])*10); // Nun werden wie auch vorher die vier Blöcke ausgelesen und in jedem Durchlauf wird der Code mit dem Faktor 10 „gestreckt“.
}

Serial.print("Die ID lautet:"); // Zum Schluss wird der Zahlencode als ID ausgegeben.
Serial.println(code);
}
