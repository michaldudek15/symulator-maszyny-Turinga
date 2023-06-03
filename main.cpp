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
    string regula, smietnik;

    if (wybor == 1) {

        { // ustawienie tasmy poczatkowej
            cout << "podaj tasme startowa: " << endl;
            string tasma;
            cin >> tasma;
            cin.ignore();
            maszyna.ustawTasme (tasma);
        }


        while (true) {
            getline (cin, regula);
            if (regula == "START") break;

            istringstream inputStream (regula);

            { // dodanie reguly
                RegulaPrzejscia nowaRegula;

                getline (inputStream, nowaRegula.aktualnyStan, ' ');
                inputStream >> nowaRegula.aktualnySymbol;
                inputStream.ignore();
                getline (inputStream, smietnik, ' ');
                getline (inputStream, nowaRegula.nastepnyStan, ' ');
                inputStream >> nowaRegula.nowySymbol;
                inputStream.ignore();
                inputStream >> nowaRegula.kierunekPrzejscia;
                inputStream.ignore();

                maszyna.dodajRegule (nowaRegula);
            }


        }

        cout << maszyna;
        maszyna.wyswietl(2);

    }
    else if (wybor == 2) {

    }
    else {
        cerr << "niepoprawny znak wyboru" << endl;
    }


    return 0;
}
