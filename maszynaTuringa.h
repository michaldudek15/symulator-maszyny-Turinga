#include <iostream>
#include <vector>
#include <sstream>
#include <chrono>
#include <fstream>
#include <thread>
#include <cstdlib>

using namespace std;

void wyczyscKonsole();

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
    int glowica;
    string aktualnyStan;
    string historia;

public:
    void wyswietl (int indeks, string aktualnyStan, char aktualnySymbol);
    void zaladujReguly (istringstream &inputStream);
    void uruchom ();
    void zapiszDoHistorii (string doZapisu);
    void zapiszOutputDoPliku (string sciezka);

    void ustawTasme (const string& tasmaPoczatkowa);
    void dodajRegule (const RegulaPrzejscia& regula);

    void getHistoria ();

    MaszynaTuringa();
    friend std::ostream& operator << (std::ostream& os, const MaszynaTuringa& maszyna);
};