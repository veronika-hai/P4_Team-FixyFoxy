# P4_Team-FixyFoxy

Das ist der Prototyp von Team 3 aus dem 4. Semester Interactive Media Design - Hochschule Darmstadt. 

Inventarliste:
Die Anzahl der hier aufgelisteten Geräte und des Inventars gibt die Menge für die mindeste Anzahl an Geräten an, die benötigt werden um unseren Prototypen aufzubauen.
1x Arduino UNO
1x RC522 RFID-Modul
7x DuPont Jumper-Kabel (male to female) für die Verdrahtung von Arduino und Reader
1x MFRC522-Chip oder MIFARE® Karte
1x Raspberry Pi 3B+
1x Laptop, den man über eine Remotedesktopverbindung mit dem Raspberry Pi verbindet oder Raspberry Pi-Bildschirm mit HDMI-Kabel
1x USB-Kabel für die Verbindung zwischen Arduino & Raspberry Pi
1x Netzteil für Raspberry
1x Netzteil Laptop, falls dieser anstelle des Bildschirmes verwendet wird


Betriebsanleitung: 
Um unseren Prototypen aufbauen zu können sind die Komponenten aus der Inventarliste notwendig.   
Zuerst steckt man mit den 7 DuPont Jumper-Kabeln das RFID-Modul an den Arduino an. (Steckplan siehe Datei: "Schaltplan_Chip-Reader.PNG")

Nun kann man sich um den Raspberry Pi kümmern. Um die Stromversorgung zu gewährleisten, muss man zuerst das Netzteil einstecken. Um den Arduino auch mit Strom zu versorgen, kann man mit dem USB-Kabel den Raspberry mit dem Arduino verbinden, dies hilft auch später bei der seriellen Verbindung.  

Um bei dem Raspberry auch die Befehle, die man eintippt, und später die Bilder zu sehen, kann man entweder einen Bildschirm mit einem HDMI-Kabel anschließen oder eine Remotedesktopverbindung mit einem Laptop/Computer starten. Dafür einfach mit einer geeigneten App die interne IP-Adresse des Raspberry, den Benutzernamen (meistens einfach pi) und das Passwort eingeben und sich verbinden.  

Danach kann man sich um das Starten des Codes kümmern. Wenn man unser Repository öffnet, findet man dort eine prototyp.ino-Datei für den Arduino, die passende RFID-Bibliothek, eine serial1.py-Datei für den Raspberry und ein Beispielbild. Öffnet man nun das Terminal auf dem Raspberry Pi und navigiert zum Ordner, in dem der Code liegt, so kann man dort „python serial1.py” ausführen.  Dies startet die serielle Verbindung zwischen Raspberry und Arduino und ermöglicht die Datenübertragung. Nun sollte man beim Einscannen eines RFID-Chips die ID im Terminal sehen und ein Bild öffnet sich.  

Sollte es bei der seriellen Verbindung Probleme geben, schaut man am besten im Arduino-IDE unter „Werkzeuge” ob das richtige Board und der richtige Port ausgewählt ist. Im Python-Code sollte man auf denselben Port verweisen! 
Sollte kein Bild auftauchen, laden Sie sich noch einen Image Viewer auf dem Raspberry runter. 
