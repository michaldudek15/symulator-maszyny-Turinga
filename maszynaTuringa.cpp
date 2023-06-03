#include "maszynaTuringa.h"

void MaszynaTuringa::zaladujReguly(istringstream &inputStream) {
    RegulaPrzejscia nowaRegula;
    string smietnik;
    getline (inputStream, nowaRegula.aktualnyStan, ' ');
    inputStream >> nowaRegula.aktualnySymbol;
    inputStream.ignore();
    getline (inputStream, smietnik, ' ');
    getline (inputStream, nowaRegula.nastepnyStan, ' ');
    inputStream >> nowaRegula.nowySymbol;
    inputStream.ignore();
    inputStream >> nowaRegula.kierunekPrzejscia;
    inputStream.ignore();
    dodajRegule (nowaRegula);

}

void MaszynaTuringa::uruchom() {
    if (tasma.empty()) {
        cerr << "tasma jest pusta" << endl;
        return;
    }

    cout << "tasma poczatkowa: " << tasma << endl;

    while (aktualnyStan != "STOP") {
        RegulaPrzejscia* aktualnaRegula = nullptr;

        for (auto& regula : reguly) {
            if (regula.aktualnyStan == aktualnyStan && regula.aktualnySymbol == tasma[glowica]) {
                aktualnaRegula = &regula;
                break;
            }
        }

        if (aktualnaRegula != nullptr) {
            aktualnyStan = aktualnaRegula->nastepnyStan;
            tasma[glowica] = aktualnaRegula->nowySymbol;

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
                cerr << "blad w przejsciach" << endl;
                break;
            }

            if (glowica < 0) {
                tasma = "." + tasma;
                glowica = 0;
            }
            else if (glowica >= tasma.length()) {
                tasma = tasma + ".";
            }

        }
        else {
            cerr << "koniec dzialania maszyny" << endl;
            break;
        }

        cout << "aktualna tasma: " << tasma << endl;
    }

}

void MaszynaTuringa::ustawTasme(const string& tasmaPoczatkowa) {
    tasma = tasmaPoczatkowa;
}

void MaszynaTuringa::dodajRegule (const RegulaPrzejscia& regula) {
    reguly.push_back(regula);
}

MaszynaTuringa::MaszynaTuringa() {
    reguly.clear();
}

ostream& operator << (ostream& os, const MaszynaTuringa& maszyna) {
    os << "tasma: " << maszyna.tasma << endl;
    for (const auto& regula : maszyna.reguly) {
        os << regula.aktualnyStan << "\t" << regula.aktualnySymbol << "\t->\t"<< regula.nastepnyStan << "\t"
           << regula.nowySymbol << "\t" << regula.kierunekPrzejscia<< endl;
    }
    return os;
}