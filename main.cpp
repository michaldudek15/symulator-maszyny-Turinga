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

    cout<< "[1] Wczytaj dane z wejscia konsolowego \n"
        << "[2] Wczytaj dane z pliku \n";

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

        while (true) { // wczytanie kolejnych regul z konsoli
            getline (cin, regula);
            if (regula == "START") break;
            istringstream inputStream (regula);
            maszyna.zaladujReguly(inputStream);
        }

    }
    else if (wybor == 2) {
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
    cout << "wczytana maszyna: " << endl;
    cout << maszyna;

    maszyna.uruchom();
    cout << "stan maszyny po zadzialaniu: " << endl;
    cout << maszyna;

    return 0;
}
