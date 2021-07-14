# Wie man sich seriell mit dem Arduino verbindet und Daten empfangen und ausgeben kann
# source: https://codingworld.io/project/den-arduino-mit-dem-raspberry-pi-verbinden-seriell

# Wie man ein Bild anzeigen kann je nachdem, welche ID eingelesen wird
# source: https://www.tutorialspoint.com/working-with-images-in-python

import serial # Python Serial Bibliothek - hilft serielle Verbindungen herzustellen
# Serial Bib Doku: https://pythonhosted.org/pyserial/shortintro.html#opening-serial-ports

import time   # Python Time Bibliothek - hilft beim Umgang mit zeitbezogenem Code
# Time Doku: https://www.programiz.com/python-programming/time
# Time.sleep Eintrag: https://www.tutorialspoint.com/python/time_sleep.htm

from PIL import Image # Python Pillow ist eine Image Bibliothek - hilft beim Laden und Anzeigen von Bildern
# Pillow Doku: https://pillow.readthedocs.io/en/stable/reference/Image.html

hamster = Image.open('hamster.jpeg') # laed das Bild 
katze = Image.open ('katze.jpeg')
hund = Image.open ('hund.jpeg')

verbindung = serial.Serial('/dev/ttyACM0', 9600) # serial.Serial gibt den Pfad zum Arduino an und die Datenrate
verbindung.isOpen()       # oeffnet den seriellen Port
time.sleep(1)             # unterbricht die Ausfuehrung fuer 1 Sekunde - Arduino braucht beim Starten der Verbindung laenger

verbindung.write('text')  # seriell werden Daten in einem String uebergeben 
try:                      # solange das Programm laeuft fuehre die Zeilen 17-19 aus
    while True: 
        antwort = verbindung.readline() #jede empfangene Zeile wird in "antwort" gespeichert - liest nur ganze Zeilen!
        # str(antwort) 
        print(antwort)    # gibt die empfangenen Zeilen aus
      
        if 'c4abe59c' in antwort:  # wenn dieser String in der ID vom Arduino vorkommt
            print('hallo hamster') 
            hamster.show()             # zeig das Bild
            
        if '5430e09c' in antwort:
            print('hallo katze') 
            katze.show()

        if '34ddf39c' in antwort:
            print('hallo hund') 
            hund.show()
                    
except KeyboardInterrupt: # hat Programm durch Strg/Ctrl+C geschlossen 
    verbindung.close()    # schliesst Port wieder
    

