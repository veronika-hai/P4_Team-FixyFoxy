// Prototyp: Arduino schickt die ID an den Raspberry PI 
// source RFID-Chip ID auslesen: https://funduino.de/nr-18-rfid-kit 
// source Kommunikation Arduino & Raspberry PI: https://codingworld.io/project/den-arduino-mit-dem-raspberry-pi-verbinden-seriell

#include <SPI.h> // Serielle Schnittstelle - SPI-Bibiothek 
#include <MFRC522.h> // RFID Bibliothek 

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN); // RFID Bibliothek zum auslesen und verarbeiten der RFID-Daten
// Doku: https://github.com/miguelbalboa/rfid 

void setup()
{
Serial.begin(9600); // Serielle Verbindung starten
SPI.begin(); // SPI-Verbindung aufbauen
mfrc522.PCD_Init(); // Initialisierung des RFID-Scanners
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

long code= Serial.read(); // Als neue Variable fügen wir „code“ hinzu, unter welcher später die ID ausgegeben wird. Statt int benutzen wir jetzt den Zahlenbereich „long“, weil sich dann eine größere Zahl speichern lässt.
// alles was seriell empfangen wird steht in "code" und wird durch Serial.read() gelesen 

for (byte i = 0; i < mfrc522.uid.size; i++)
{
code=(mfrc522.uid.uidByte[i]); // hier werden die 4 Bytes in DEC wie vorher ausgelesen und in "code" gespeichert 
String ID = String (code, HEX); // hier wandeln wir den DEC "code" in HEX um und speichern es in einem String, der ID heißt 

Serial.print (ID);
}

Serial.println(); // damit die IDs untereinander und nicht in einer Zeile gesendet werden
delay (1000); // damit nicht 100 IDs nacheinander ankommen 
} 
