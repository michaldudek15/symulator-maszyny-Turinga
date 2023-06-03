// Michał Dudek
// Maja Flaczek
#include "maszynaTuringa.h"

int main() {

#if __linux__
    cout << "wykryty system operacyjny: linux" << endl;
    const string systemOperacyjny = "linux";
#elif _WIN32
    cout << "wykryty system operacyjny: windows" << endl;
    const string systemOperacyjny = "windows";
#elif __APPLE__
    cout << "wykryty system operacyjny: macos" << endl;
    const string systemOperacyjny = "macos";
#else
    cout << "nie rozpoznano systemu operacyjnego" << endl;
    const string systemOperacyjny = "nieznany";
#endif

    powrot:
    system("clear");
    cout<< "[1] wczytaj dane z wejscia konsolowego \n"
        << "[2] wczytaj dane z pliku \n";

    // wybor opcji wczytania danych
    int wybor;
    cin >> wybor;

    // inicjalizacja maszyny
    MaszynaTuringa maszyna;
    string regula;

    if (wybor == 1) {

        { // ustawienie tasmy poczatkowej z konsoli
            cout << "podaj tasme startowa: " << endl;
            string tasma;
            cin >> tasma;
            cin.ignore();
            maszyna.ustawTasme (tasma);
        }

        cout << "podawaj w kolejnych liniach reguly przejsc maszyny Turinga" << endl;
        cout << "przykladowa regula: q0 . -> q0 0 R" << endl;
        cout << "linia z napisem START zakonczy wczytywanie" << endl;

        while (true) { // wczytanie kolejnych regul z konsoli
            getline (cin, regula);
            if (regula == "START") break;
            istringstream inputStream (regula);
            maszyna.zaladujReguly(inputStream);
        }

    }
    else if (wybor == 2) {
        cout << "podaj sciezke do pliku z danymi wejsciowymi" << endl;

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

    system("clear");
    cout << "wczytana maszyna:\n" << endl;
    cout << maszyna;

    cout << "\nczy uruchomic wczytana maszyne?\n" << endl << "[1] tak" << endl << "[2] nie, wczytaj jeszcze raz" << endl << "[3] wyjscie z programu" << endl;
    cin >> wybor;

    if (wybor == 1) {
        maszyna.uruchom();
    }
    else if (wybor == 2) {
        system("clear");
        goto powrot;
    }
    else if (wybor == 3) {
        return 0;
    }
    else {
        cerr << "niepoprawny wybor" << endl;
    }

    cout << "[1] wyswietl historie w konsoli" << endl << "[2] zapisz historie do pliku" << endl << "[3] wyjdz z programu" << endl;
    cin >> wybor;

    if (wybor == 1) {
        system("clear");
        maszyna.getHistoria();
    }

    else if (wybor == 2) {
        cout << "podaj nazwe pliku: ";
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