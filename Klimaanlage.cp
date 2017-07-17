int TMP36 = A0; //Der Sensor soll am analogen Pin A0 angeschlossen werden. Wir nennen den Pin ab jetzt "TMP36"
int sensorwert; // Variablendeklaration des Sensorwertes
int temperatur = 0; //Unter der Variablen "temperatur" wird später der Temperaturwert abgespeichert.
int t=500; // Messung wird im Abstand von 500ms durchgeführt.

int taster=8; //Das Wort „taster“ steht jetzt für den Wert 8.
int tasterstatus=0; //Das Wort „tasterstatus“ steht jetzt zunächst für den Wert 0.

int LEDrot=6; //Das Wort „LEDrot“ steht jetzt für den Wert 6.
int LEDgruen=7; //Das Wort „LEDgrün“ steht jetzt für den Wert 7.
int LEDblau=9; //Das Wort „LEDblau“ steht jetzt für den Wert 9.

void setup() //  Das Setup beginnt
{
    Serial.begin(9600); //Im Setup beginnt die serielle Kommunikation, damit die Temperatur an den serial monitor übertragen wird.
    pinMode(LEDrot,OUTPUT); // //Der Pin mit der LED (Pin 6) ist jetzt ein Ausgang
    pinMode(LEDgruen,OUTPUT); // //Der Pin mit der LED (Pin 7) ist jetzt ein Ausgang
    pinMode(LEDblau,OUTPUT); // //Der Pin mit der LED (Pin 9) ist jetzt ein Ausgang
    pinMode(taster, INPUT); // Der Pin mit dem Taster ist jetzt ein Eingang
}


void loop() // Hauptprogramm beginnt
{
    sensorwert=analogRead(TMP36); //Auslesen des Sensorwertes.
    temperatur= map(sensorwert, 0, 410, -50, 150); //Umwandeln des Sensorwertes mit Hilfe des "map" Befehls.
    delay(t); // Nach jeder Messung ist je eine kleine Pause mit der Dauer „t“ in Millisekunden.
    Serial.print(temperatur); //Nun wird der Wert „temperatur“ über die serielle Kommunikation an den PC gesendet. Durch öffnen des seriellen Monitors in der Arduino-Software kann die Temperatur abgelesen werden.
    Serial.println(" Grad Celsius"); // Im seriellen Monitor wird hinter der Temperatur die Einheit eingeblendet.
    
    tasterstatus=digitalRead(taster); //Hier wird der Pin7 ausgelesen
    
    int Wunschtemperatur=20 ; //Initialisierung von Wunschtemperatur (20°C)
    
    if (tasterstatus == HIGH)//Verarbeitung: Wenn der Taster gedrückt ist
    {
        
        
        if (temperatur < Wunschtemperatur) // Wenn gemessene Temperatur < Wunschtemperatur (Heizen)
        { digitalWrite(LEDrot,HIGH); // rote LED leuchtet
            
            digitalWrite(LEDgruen, LOW); // grüne LED ausschalten
            digitalWrite(LEDblau, LOW);  // blaue LED ausschalten
        }
        else if (temperatur > Wunschtemperatur) // Wenn gemessene Temperatur > Wunschtemperatur (Kühlen)
        { digitalWrite(LEDblau,HIGH); // blaue LED leuchtet
            
            digitalWrite(LEDgruen, LOW); // grüne LED ausschalten
            digitalWrite(LEDrot, LOW);  // rote LED ausschalten
        }
        else if (temperatur == Wunschtemperatur) // Wenn Temperatur = Wunschtemperatur
        { digitalWrite(LEDgruen,HIGH); //grüne LED leuchtet
            
            digitalWrite(LEDrot, LOW); // grote LED ausschalten
            digitalWrite(LEDblau, LOW);  // blaue LED ausschalten
        }
        else
        {
            digitalWrite(LEDrot, LOW);  // blaue LED ausschalten
            digitalWrite(LEDgruen, LOW); // grüne LED ausschalten
            digitalWrite(LEDblau, LOW);  // rote LED ausschalten
        }
        
    }
    
}
