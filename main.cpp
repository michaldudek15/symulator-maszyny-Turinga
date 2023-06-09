// Michał Dudek
// Maja Flaczek
#include "maszynaTuringa.h"

int main() {

    wyczyscKonsole();

    cout << magenta << bold;
    cout << "witaj w symulatorze maszyny Turinga!\n";
    cout << resetColor;

    poczatek:
    cout << green;
    cout << "wybierz opcje wczytania danych do maszyny:\n\n";
    cout << resetColor;
    cout << blue;
    cout<< "[1] wczytaj dane z wejscia konsolowego \n"
        << "[2] wczytaj dane z pliku \n"
        << "[3] wyjdz z programu \n";

    cout << resetColor;

    // wybor opcji wczytania danych
    int wybor;
    cin >> wybor;

    // inicjalizacja maszyny
    MaszynaTuringa maszyna;
    string regula;

    if (wybor == 1) {

        { // ustawienie tasmy poczatkowej z konsoli
            cout << yellow;
            cout << "podaj tasme startowa: " << endl;
            cout << resetColor;

            string tasma;
            cin >> tasma;
            cin.ignore();
            maszyna.ustawTasme (tasma);
        }

        cout << yellow;
        cout << "\npodawaj w kolejnych liniach reguly przejsc maszyny Turinga:" << endl;
        cout << resetColor;
        cout << "[przykladowa regula: q0 . -> q0 0 R]" << endl;
        cout << yellow;
        cout << "linia z napisem";
        cout << green << bold;
        cout << " START ";
        cout << resetColor;
        cout << yellow;
        cout << "zakonczy wczytywanie" << endl;
        cout << resetColor;

        while (true) { // wczytanie kolejnych regul z konsoli
            getline (cin, regula);
            if (regula == "START") break;
            istringstream inputStream (regula);
            maszyna.zaladujReguly(inputStream);
        }

    }
    else if (wybor == 2) {
        cout << yellow;
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
    else if (wybor == 3) return 0;

    else cerr << "niepoprawny znak wyboru" << endl;

    start:
    wyczyscKonsole();
    cout << green;
    cout << "wczytana maszyna:\n" << endl;
    cout << resetColor;
    cout << blue;
    cout << maszyna;
    cout << resetColor;


    cout << green;
    cout << "\nczy uruchomic wczytana maszyne?\n";
    cout << resetColor;
    cout << blue;
    cout << "[1] tak" <<
    endl << "[2] nie, wczytaj jeszcze raz" <<
    endl << "[3] zmien tasme startowa" <<
    endl << "[4] wyjscie z programu" << endl;
    cout << resetColor;
    cin >> wybor;

    if (wybor == 1) maszyna.uruchom();

    else if (wybor == 2) {
        wyczyscKonsole();
        goto poczatek;
    }

    else if (wybor == 3) {
        string nowaTasma;
        cout << "podaj tasme startowa: ";
        cin >> nowaTasma;
        maszyna.ustawTasme(nowaTasma);
        maszyna.zresetujMaszyne();
        goto start;
    }

    else if (wybor == 4) return 0;

    else cerr << "niepoprawny wybor" << endl;


    cout << blue;
    cout << "[1] wyswietl historie w konsoli" <<
    endl << "[2] zapisz historie do pliku" <<
    endl << "[3] uruchom te sama maszyne ponownie z inna tasma startowa" <<
    endl << "[4] uruchom ponownie program" <<
    endl << "[5] wyjdz z programu" << endl;
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
        string nowaTasma;
        cout << "podaj tasme startowa: ";
        cin >> nowaTasma;
        maszyna.ustawTasme(nowaTasma);
        maszyna.zresetujMaszyne();
        goto start;
    }

    else if (wybor == 4) {
        wyczyscKonsole();
        goto poczatek;
    }

    else if (wybor == 5) return 0;

    else cerr << "niepoprawny wybor" << endl;

    return 0;
}