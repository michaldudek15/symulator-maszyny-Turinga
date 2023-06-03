#include "maszynaTuringa.h"

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