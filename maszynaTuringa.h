#include <iostream>
#include <vector>
#include <sstream>
#include <chrono>
#include <fstream>
#include <thread>
#include <cstdlib>

using namespace std;

const string red = "\033[31m";
const string green = "\033[32m";
const string yellow = "\033[33m";
const string blue = "\033[34m";
const string magenta = "\033[35m";
const string black = "\033[30m";
const string blackOnWhite = "\033[30;47m";
const string whiteOnBlack = "\033[37;40m";
const string backgroundGreen = "\033[42m";
const string bold = "\033[1m";
const string resetBold = "\033[22m";
const string resetColor = "\033[0;0m";

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