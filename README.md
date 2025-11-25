# Sorting

Machen Sie Sich mit dem gegebenen Code vertraut und implementieren Sie die folgenden Funktionen in `sort.c`:

1. `bubbleSort`: Der Algorithmus aus der Vorlesung mit early exit
2. `quickSort`: Der Algorithmus aus der Vorlesung
3. `quickSortRandom`: Nutzen Sie Zufall mithilfe der `rand`-Funktion der C-Standardbibliothek, damit der Algorithmus für vorsortierte Arrays schneller wird.

Achten Sie auf die Laufzeiten Ihrer Algorithmen! Das Laufzeitverhalten muss den in der Vorlesung besprochenen Rahmen entsprechen. Hat Ihre Implementierung eine schlechtere Laufzeitkomplexität als der Algorithmus haben sollte, wird dies als Fehler gewertet.

Bitte fügen Sie keine weiteren Ausgaben an `stdout` hinzu und verändern Sie nicht die Signaturen gegebener Funktionen, da dies die Auswertung unnötig erschwert. Für Ausgaben Ihrer Fehlerbehandlungen nutzen Sie bitte ausschließlich die Standardfehlerausgabe `stderr`. Bei Bedarf können Sie in `sort.c` private Hilfsfunktionen definieren und benötigte Header inkludieren. 

Geben Sie Ihr Resultat als Merge Request ab.

Im Repository ist eine Pipeline zur automatischen Auswertung hinterlegt. Sie wird fehlschlagen, sofern Ihre Abgabe nicht kompilierbar ist. Eine erfolgreiche Ausführung der Pipeline ist jedoch keine Garantie für eine bestimmte Punktzahl. 

Bitte achten Sie darauf, Ihren Code lesbar und verständlich zu gestalten. Nutzen Sie Kommentare, um Ihren Code zu erklären! Unleserliche und unkommentierte Abgaben werden nicht berücksichtigt. 

Achten Sie außerdem darauf, dass Ihr Code kompilierbar ist und auch mit den Flags `-Wextra -Wall` ohne Warnungen kompiliert, da die Abgabe andernfalls nicht berücksichtigt wird. 
