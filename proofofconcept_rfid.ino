// Wie kann man die UID (HEX) von RFID-Chips in eine zusammenhängende Zahl umwandeln
// source: https://funduino.de/nr-18-rfid-kit 

#include <SPI.h> // Serielle Schnittstelle - SPI-Bibiothek 
// Die SPI-Schnittstelle ( Serial Peripheral Interface Bus ) wird für die Kommunikation zwischen mehreren Geräten über kurze Entfernungen und mit hoher Geschwindigkeit verwendet
// für Kommunikation zwischen Arduino & RFID-Scanner

#include <MFRC522.h> // RFID Bibliothek zum auslesen und verarbeiten der RFID-Daten
// Doku: https://github.com/miguelbalboa/rfid 

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); // RFID-Empfänger benennen

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


long code=0; // neue Variable, unter welcher später die ID ausgegeben wird. Statt int lieber Zahlenbereich „long“, weil sich dann eine größere Zahl speichern lässt

// die UID der Chips werden als HEX-Zahl in 4 Blöcken ausgelesen => Serial.print(mfrc522.uid.uidByte[i], HEX) ergibt  z.B. F3 F8 A6 0 
// die HEX-Zahl wandelt man also besser in eine Dezimalzahl um Serial.print(mfrc522.uid.uidByte[i], DEC) ergibt z.B. 84 48 224 156 
// trotzdem bleiben 4 Blöcke und die erschweren die Weiterverarbeitung! Denn dann muss man bei weiteren Befehlen alle Blöcke einzelnd aufzählen, anstatt eine zusammenhängende Zahl (1234567) anzugeben 

for (byte i = 0; i < mfrc522.uid.size; i++)
{
code=((code+mfrc522.uid.uidByte[i])*10); // vier Blöcke werden ausgelesen und in jedem Durchlauf wird der Code nun mit dem Faktor 10 „gestreckt“ -> dadurch wird aus der HEX-UID eine Dezimalzahl
}

Serial.print("Die ID lautet: "); // hier wird dann die umgewandelte ID ausgegeben 
Serial.println(code);
}
