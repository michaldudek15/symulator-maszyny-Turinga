#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

struct RegulaPrzejscia {
    string aktualnyStan;
    char aktualnySymbol;

    string nastepnyStan;
    char nowySymbol;
    char kierunekPrzejscia;
};

class MaszynaTuringa {
private:
    vector<RegulaPrzejscia> reguly;
    string tasma;
    int glowica = 0;
    string aktualnyStan = "q0";

public:
    void wyswietl (int indeks);
    void zaladujReguly (istringstream &inputStream);
    void uruchom ();
    void zapiszInputDoPliku ();
    void zapiszOutputDoPliku ();

    void ustawTasme (const string& tasmaPoczatkowa);
    void dodajRegule (const RegulaPrzejscia& regula);

    MaszynaTuringa();
    friend std::ostream& operator << (std::ostream& os, const MaszynaTuringa& maszyna);
};