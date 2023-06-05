#include "maszynaTuringa.h"

// zaleznie od wykrytego systemu operacyjnego wywoluje funkcje czyszczaca konsole
void wyczyscKonsole () {
    #if __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #elif __APPLE__
        system("clear");
    #else
        cout << "nie rozpoznano systemu operacyjnego" << endl;
    #endif
}

// zaleznie od wykrytego systemu operacyjnego wywoluje funkcje wstrzymujaca program na podany okres
void zasnij (int czas) {
    #if __linux__
        //usleep(czas);
        this_thread::sleep_for(chrono::milliseconds(czas));
    #elif _WIN32
        Sleep(czas);
    #elif __APPLE__
        this_thread::sleep_for(chrono::milliseconds(czas));
    #else
        cout << "nie rozpoznano systemu operacyjnego" << endl;
    #endif
}

// procedura umozliwiajaca wyswietlenie aktualnej tasmy z glowica oraz aktualnie realizowanej reguly
void MaszynaTuringa::wyswietl(int indeks, const string aktualnyStan, char aktualnySymbol) {

    wyczyscKonsole();
    string doZapisu = aktualnyStan;
    doZapisu += "\t";

    for (int i = 0; i < tasma.length(); i++) {

        if (i == indeks) {
            printf("\033[33m[%c]\033[0m", tasma[i]);
            cout.flush();

            doZapisu += "[";
            doZapisu += tasma[i];
            doZapisu += "]";
        }

        else {
            printf(" %c ", tasma[i]);
            cout.flush();

            doZapisu += " ";
            doZapisu += tasma[i];
            doZapisu += " ";
        }
    }
    zapiszDoHistorii(doZapisu);

    cout << endl << endl << endl;

    for (auto& regula : reguly) {
        if (regula.aktualnyStan == aktualnyStan && regula.aktualnySymbol == aktualnySymbol) {
            printf( "\033[33m%s\t%c\t->\t%s\t%c\t%c\033[0m\n", regula.aktualnyStan.c_str(), regula.aktualnySymbol,
                    regula.nastepnyStan.c_str(), regula.nowySymbol, regula.kierunekPrzejscia);
            cout.flush();

        }
        else {
            cout << regula.aktualnyStan << "\t" << regula.aktualnySymbol << "\t->\t"<< regula.nastepnyStan << "\t"
                    << regula.nowySymbol << "\t" << regula.kierunekPrzejscia << endl;
            cout.flush();
        }
    }
}

// procedura wczytujaca podane reguly do struktury z wykorzystaniem strumienia istringstream
void MaszynaTuringa::zaladujReguly(istringstream &inputStream) {
    RegulaPrzejscia nowaRegula;
    string smietnik;
    getline (inputStream, nowaRegula.aktualnyStan, ' ');
    inputStream >> nowaRegula.aktualnySymbol;
    inputStream.ignore();
    getline (inputStream, smietnik, ' '); // do smietnika wrzucam czesc lini z symbolem strzalki '->'
    getline (inputStream, nowaRegula.nastepnyStan, ' ');
    inputStream >> nowaRegula.nowySymbol;
    inputStream.ignore();
    inputStream >> nowaRegula.kierunekPrzejscia;
    inputStream.ignore();
    dodajRegule (nowaRegula);
}

// glowna procedura odpowiedzialna za poruszanie glowicy oraz zmiane stanow maszyny
void MaszynaTuringa::uruchom() {
    if (tasma.empty()) {
        cerr << "tasma jest pusta" << endl;
        return;
    }

    cout << "tasma poczatkowa: " << tasma << endl;

    while (aktualnyStan != "STOP") {
        RegulaPrzejscia* aktualnaRegula = nullptr;

        // znalezienie odpowiedniej reguly
        for (auto& regula : reguly) {
            if (regula.aktualnyStan == aktualnyStan && regula.aktualnySymbol == tasma[glowica]) {
                aktualnaRegula = &regula;
                break;
            }
        }

        if (aktualnaRegula != nullptr) {

            wyswietl(glowica, aktualnyStan, tasma[glowica]);
            zasnij(500);

            aktualnyStan = aktualnaRegula->nastepnyStan;
            tasma[glowica] = aktualnaRegula->nowySymbol;

            // ruch glowicy
            if (aktualnaRegula->kierunekPrzejscia == 'R') {
                glowica++;
            }
            else if (aktualnaRegula->kierunekPrzejscia == 'L') {
                glowica--;
            }
            else if (aktualnaRegula->kierunekPrzejscia == 'S') {
                ;
            }
            else {
                cerr << "blad w ruchu glowicy" << endl;
                break;
            }

            // przypadek wyjscia poza aktualna tasme
            if (glowica < 0) {
                tasma = "." + tasma;
                glowica = 0;
            }
            else if (glowica >= tasma.length()) {
                tasma = tasma + ".";
            }

        }
        else {
            cout << "koniec dzialania maszyny" << endl;
            break;
        }

    }

    wyswietl(glowica, aktualnyStan, tasma[glowica]);
    zasnij(500);
    cout << endl;

}

// procedura aktualizujaca zmienna historia w ktorej pamietane sa wszystkie przejscia maszyny
void MaszynaTuringa::zapiszDoHistorii(const string& doZapisu) {
    historia += doZapisu;
    historia += "\n";
}

// procedura tworzaca plik i zapisujaca do niego historie przejsc maszyny
void MaszynaTuringa::zapiszOutputDoPliku(const string& sciezka) {
    fstream plik;
    plik.open(sciezka, ios::out);
    if (!plik) {
        cerr << "blad tworzenia pliku";
    }
    else {
        plik << historia;
        plik.close();
        cout << "historia przejsc zapisana do pliku " << sciezka << endl;
    }
}

// procedura inicjalizujaca tasme
void MaszynaTuringa::ustawTasme (const string& tasmaPoczatkowa) {
    tasma = tasmaPoczatkowa;
}

// procedura dodajaca regule
void MaszynaTuringa::dodajRegule (const RegulaPrzejscia& regula) {
    reguly.push_back(regula);
}

// procedura przygotowujaca maszyne do wczytania nastepnych danych
void MaszynaTuringa::zresetujMaszyne() {
    glowica = 0;
    aktualnyStan = "q0";
    historia.clear();
}

// getter zmiennej historia
string MaszynaTuringa::getHistoria() {
    return historia;
}

// konstruktor
MaszynaTuringa::MaszynaTuringa() {
    glowica = 0;
    aktualnyStan = "q0";
    reguly.clear();
    historia.clear();
}

// przeciazenie operatora <<, aby umozliwil wyswietlanie elementow klasy MaszynaTuringa
ostream& operator << (ostream& os, const MaszynaTuringa& maszyna) {
    os << "tasma: " << maszyna.tasma << endl;
    for (const auto& regula : maszyna.reguly) {
        os << regula.aktualnyStan << "\t" << regula.aktualnySymbol << "\t->\t"<< regula.nastepnyStan << "\t"
           << regula.nowySymbol << "\t" << regula.kierunekPrzejscia<< endl;
    }
    return os;
}