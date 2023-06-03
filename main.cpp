// Michał Dudek
// Maja Flaczek
#include "maszynaTuringa.h"

int main() {

    powrot:
    wyczyscKonsole();

    cout << green;
    cout<< "[1] wczytaj dane z wejscia konsolowego \n"
        << "[2] wczytaj dane z pliku \n";
    cout << resetColor;

    // wybor opcji wczytania danych
    int wybor;
    cin >> wybor;

    // inicjalizacja maszyny
    MaszynaTuringa maszyna;
    string regula;

    if (wybor == 1) {

        { // ustawienie tasmy poczatkowej z konsoli
            cout << green;
            cout << "podaj tasme startowa: " << endl;
            cout << resetColor;

            string tasma;
            cin >> tasma;
            cin.ignore();
            maszyna.ustawTasme (tasma);
        }

        cout << green;
        cout << "\npodawaj w kolejnych liniach reguly przejsc maszyny Turinga" << endl;
        cout << "przykladowa regula: q0 . -> q0 0 R" << endl;
        cout << "linia z napisem START zakonczy wczytywanie" << endl;
        cout << resetColor;

        while (true) { // wczytanie kolejnych regul z konsoli
            getline (cin, regula);
            if (regula == "START") break;
            istringstream inputStream (regula);
            maszyna.zaladujReguly(inputStream);
        }

    }
    else if (wybor == 2) {
        cout << green;
        cout << "podaj sciezke do pliku z danymi wejsciowymi" << endl;
        cout << resetColor;

        string sciezka;
        cin >> sciezka;

        ifstream plik(sciezka);

        if (plik.is_open()) {

            { // wczytanie tasmy poczatkowej z pliku
                string tasma;
                getline (plik, tasma);
                maszyna.ustawTasme(tasma);
            }


            while (getline (plik, regula)) { // wczytanie kolejnych regul z pliku
                istringstream inputStream(regula);
                maszyna.zaladujReguly(inputStream);
            }
        }

    }
    else {
        cerr << "niepoprawny znak wyboru" << endl;
    }

    wyczyscKonsole();
    cout << green;
    cout << "wczytana maszyna:\n" << endl;
    cout << resetColor;

    cout << blue;
    cout << maszyna;
    cout << resetColor;

    cout << green;
    cout << "\nczy uruchomic wczytana maszyne?\n" << endl << "[1] tak" << endl << "[2] nie, wczytaj jeszcze raz" << endl << "[3] wyjscie z programu" << endl;
    cout << resetColor;
    cin >> wybor;

    if (wybor == 1) {
        maszyna.uruchom();
    }
    else if (wybor == 2) {
        wyczyscKonsole();
        goto powrot;
    }
    else if (wybor == 3) {
        return 0;
    }
    else {
        cerr << "niepoprawny wybor" << endl;
    }

    cout << green;
    cout << "[1] wyswietl historie w konsoli" << endl << "[2] zapisz historie do pliku" << endl << "[3] wyjdz z programu" << endl;
    cout << resetColor;

    cin >> wybor;

    if (wybor == 1) {
        wyczyscKonsole();
        cout << maszyna.getHistoria();
    }

    else if (wybor == 2) {
        cout << green;
        cout << "podaj nazwe pliku: ";
        cout << resetColor;
        string sciezka;
        cin >> sciezka;
        maszyna.zapiszOutputDoPliku(sciezka);
    }

    else if (wybor == 3) {
        return 0;
    }

    else {
        cerr << "niepoprawny wybor" << endl;
    }

    return 0;
}