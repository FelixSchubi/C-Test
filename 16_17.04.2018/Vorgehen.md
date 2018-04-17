# Ohne Test
Im Moment muss nach jedem mal noch neu compiliert werden, da die create() Funktion nicht geht und dadurch die Pointer nicht auf NULL gesetzt werden und ein Speicherzugriffsfehler entsteht. <br>
Als Standart .c Datei ohne zusätzliche Tests.<br>
<a href="https://github.com/FelixSchubi/C-Test/tree/master/16.04.2018/Database">Hier!<a> <br>

- Bei begin.h durfte die Funktion nicht den gleichen Namen haben wie die Datei?  ??Warum nur hier?? 
- Das "User Interface" funktioniert soweit wieder
- Man kann mehrere Studenten eingeben
- Bei show() wird angezeigt dass die Liste leer ist 
- Bei delete() wird, egal was eingegeben wird, // Segmentation fault:11 // angezeigt

// Es wird eine process_node.c erstellt! Es wird versucht nur eine Node zu erstellen, auf welche jeder zugreifen kann.
Fehlermeldung: <br>
<img src="../Bilder/ArchitectureFailed.png">
  
# Mit Test
Die Funktionen werden hier erneut benutzt; nur diesmal wird das Framework CUnit zum Testen der Funktionen verwendet. <br>
<a href="https://github.com/FelixSchubi/C-Test/tree/master/16.04.2018/DatabaseTest">Hier!<a> <br>
  
### Schritte
- https://stackoverflow.com/questions/5128664/how-to-split-a-c-program-into-multiple-files <br>
Ist es notwendig drei Dateien zu erstellen? bzw. zwei eine .h & .c ??
