# NetBeans IDE
https://netbeans.org/ </br>
Als neue Entwicklungsumgebung wird zum Testen die NetBeans IDE verwendet. </br>
Außerdem wird das Addon für die Sprachen C und C++ <a href="https://netbeans.org/features/cpp/index.html">hinzugefügt<a>. 
## Struktur
Der Aufbau eines Projekts sieht wie folgt aus: </br>
<img src="https://github.com/FelixSchubi/C-Test/blob/master/NetBeans/Dokumentation/Struktur.jpg"> </br></br>
In den Header Files können, wie der Name schon sagt alle header Dateien abgelegt werden. </br>
In meinem Fall sind hier alle Funktionen drin, welche für das Programm benötigt werden; </br>
<img src="https://github.com/FelixSchubi/C-Test/blob/master/NetBeans/Dokumentation/HeaderFiles.png"> </br></br>
Die Resource Files hatten bis jetzt noch keine Bedeutung für mich, weshalb sie in meinem Beilspiel leer sind. </br>
Nun zu den Source Files; </br>
<img src="https://github.com/FelixSchubi/C-Test/blob/master/NetBeans/Dokumentation/SourceFiles.png"> </br></br>
Wie man auf dem Bild erkennen kann handelt es sich bei der Source File in meinem Fall, um das Hauptprogramm das alle Funktionen aus den Header Files nutzt. (Ohne Jegliche Tests) </br>

Im Ordner Important Files ist die Makefile (Bedeutung für mich noch nicht ganz klar)! </br>
Und zum Schluss der Ordner Test Files, in dem man verschiedene CUnit Tests anlegen kann; </br>
<img src="https://github.com/FelixSchubi/C-Test/blob/master/NetBeans/Dokumentation/TestFiles.png"> </br>
Diese erstellt man entweder vollständig selbt oder man nutzt die von NetBeans zur Verfügung gestellte Möglichkeit: </br>
<img src="https://github.com/FelixSchubi/C-Test/blob/master/NetBeans/Dokumentation/CreateTest.png" height="250px"> </br>
Das ist natürlich nicht nur bei einer einzelnen Header Datein möglich sonder auch bei der Source File!

### Issues

Wenn man die Header Files in der Source- und den Test Files einbindet bekommt man folgende Fehlermeldung: </br>
<img src="https://github.com/FelixSchubi/C-Test/blob/master/NetBeans/Dokumentation/Fehler.png" height="300px"> </br>
</br>
### Problem Handling
Um das Problem vorrübergehend zu lösen wird während den Tests der Funktionsaufruf auskommentiert.</br>
Wenn man nur das Programm selbst starten will stört es nicht wenn der Test normal bestehen bleibt. </br>
</br>
Für die bessere Übersicht wird für jede Funktion eine eigene Suite erstellt in der sie getestet wird.


