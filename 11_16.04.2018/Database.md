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
  41.  Es soll ein Student hinzugefügt werden / add() / 
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
3. Wenn die create() Funktion gestartet wird, bekommt die globe Variable "test" den Wert 1. Durch folgenden Test in der mainFunc() Funktion nach aufrufen von create wird sichergestellt, ob eine Veränderung der Variable Test auf 1 stattgefunden hat. Zusätzlich wird überprüft, ob der Pointer front den Wert NULL besitzt: </br></br>
<b>if (test = 1){</br>
        CU_ASSERT_PTR_NULL(front);</br>
        CU_PASS("create()function");</br>
       }</br>
    else {</br>
        CU_FAIL("create() fail");</br>
    }</br> </b></br>
4. Durch folgende Tests wird sichergestellt, dass die Namensfelder nicht leer sein dürfen und die Matrikelnummer nicht einfach eine 0 sein darf : </br>
<b></br>``` bash
CU_ASSERT_STRING_NOT_EQUAL("", name );
    CU_ASSERT_STRING_NOT_EQUAL("", vname );
    CU_ASSERT_NOT_EQUAL(0, matr); ```</b></br></br>
5. Bei der add() Funktion wird folgendes getestet:
<br></br>``` bash
<b>CU_ASSERT_STRING_EQUAL_FATAL(front->Na, na);
    CU_ASSERT_STRING_EQUAL_FATAL(rear->Vo, front->Vo); </b>``` </br><br>
Hier wird verglichen, ob die eingegebenen Werte auch mit denen der Pointer übereinstimmen. Falls dies nicht der Fall sein sollte bricht das Programm sofort ab. Dies erfolgt durch das "FATAL" am Ende des Funktionsaufrufs: CU_ASSERT_STRING_EQUAL_<b>FATAL</b>(front->Vo, vo); </br>
Zusatz:<br>
<b>askForAdd()</b>-> Wenn die Studentendatenbank leer ist und man die Funktion show() oder delete() aufruft, gibt es die Möglichkeit einen Studenten hinzuzufügen, wenn man eine Frage beantwortet. In dem Fall, dass weder ja noch nein eingegeben wurde, gibt es mit <br>
        <b>    CU_ASSERT_FALSE("Weder Ja noch Nein eingegeben"); </b><br>
    einen Vermerk und der Nutzer wird erneut gefragt. 
6. Zu Beginn wird geprüft, ob ob der front Pointer tatsächlich NULL ist; <br>
<b>CU_ASSERT_PTR_NULL_FATAL(front); </b>
 <br>
Wenn dies der Fall ist => askForAdd() - siehe 5

