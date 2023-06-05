# SYMULATOR MASZYNY TURINGA
#### Michał Dudek, Maja Flaczek

Projekt realizuje symulację **Maszyny Turinga** w języku C++ w standardzie C++11.

## Instrukcja
Po pobraniu i rozpakowaniu folderu z projektem należy skompilować go.
Przy pomocy kompilatora GNU komenda wygląda tak:
```commandline
g++ -o maszynaTuringa.x maszynaTuringa.cpp main.cpp -std=c++11
```

### Make
Alternatywnie, można prościej skompilować projekt przy pomocy programu make.
Komenda 'make' lub 'make all' skompiluje pliki programu, a 'make clean' usunie zbędne pliki.

### Wejście
Po uruchomieniu, program przedstawi opcje wczytania danych do symulacji:

![1.png](img%2F1.png)

Wybierając opcję 1 w kolejnych liniach standardowego wejścia należy zapewnić początkową taśme oraz kolejne reguły 
działania maszyny (w podanym formacie). Wczytywanie kończy się po wczytaniu linii z napisem START.

![2.png](img%2F2.png)

Alternatywnie, wybierając opcję 2 należy podać ścieżkę do pliku tekstowego, zawierającego taśmę startową oraz kolejne reguły. 
Format pliku można sprawdzić w plikach w katalogu 'przykladoweMaszyny'.

![3.png](img%2F3.png)

### Działanie
Po wczytaniu, program wypisze taśmę startową oraz reguły podane z konsoli lub z pliku.

![4.png](img%2F4.png)

Wybranie opcji 1 spowoduje uruchomienie wizualizacji symulacji działania maszyny Turinga.

![5.png](img%2F5.png)

Po zakończeniu użytkownik może wybrać, czy historia kolejnych przebiegów dla danej taśmy startowej ma wyświetlić się na 
ekranie, czy zostać zapisana do pliku. 
Program pozwala również podmienić taśmę startową już wczytanej maszyny lub wczytać od początku inne reguły.