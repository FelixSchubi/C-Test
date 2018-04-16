# Database

## Anwendung

Es sollen folgende Funktionen möglich sein:
 1. In main() soll nach den Funktionen gefragt werden
    - Mit Hilfe einer while Schleife soll eine Art UI geschaffen werden
 2. Eine Node soll ersellt werden  / "struct node" !Geht nicht als Funktion! /
    - Enthalten sein sollen:
    - Name
    - Vorname
    - Matrikelnummer
 3. Zu Beginn sollen alle werte auf NULL gesetzt werden / create() /
 4. Die Werte müssen eingescannt werden / insertValues()  / -->
  41.  Es soll ein Studen hinzugefügt werden / add() / 
 5. Die Studenten sollen angezeigt werden / show() /
 51. Wenn die Liste leer ist wird gefragt, ob ein Student hinzugefügt werden soll? / askForAdd() /
 6. Wenn man den Namen eines Studenten eingibt soll dieser gelöscht werden / delete() /
 7. Anzahl der Studenten soll angezeigt werden / amount() /
 8. Programm soll beendet werden / stop() /

## Test
Wie sollen obige Funktionen getestet werden? Zu..
1. CU_PASS("mainFunc() gestartet") bei erfolgreichem Start.
Die globale Variable secTest wird beim Start auf 0 gesetzt.
2. Wie struct Node getestet werden soll ist noch unklar?
3. Wenn die create() Funktion gestartet wird, bekommt die globe Variable "test" den Wert 1. Durch folgenden Test in der mainFunc() Funktion wird sichergestellt, ob eine Veränderung der Variable Test auf 1 stattgefunden hat. Zusätzlich wird überprüft, ob der Pointer front den Wert NULL besitzt: </br>
<b>if (test = 1){</br>
        CU_ASSERT_PTR_NULL(front);</br>
        CU_PASS("create()function");</br>
       }</br>
    else {</br>
        CU_FAIL("create() fail");</br>
    }</br> </b>
4. Durch folgende Tests wird sichergestellt, dass die Namensfelder nicht leer sein dürfen und die Matrikelnummer nicht einfach eine 0 sein darf : </br>
<b>
CU_ASSERT_STRING_NOT_EQUAL("", name );
    CU_ASSERT_STRING_NOT_EQUAL("", vname );
    CU_ASSERT_NOT_EQUAL(0, matr); </b>

