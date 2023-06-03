// Michał Dudek
// Maja Flaczek
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct RegulaPrzejscia {
    string aktualnyStan;
    string aktualnySymbol;

    string nastepnyStan;
    string nowySymbol;
    char kierunekPrzejscia;
};

class MaszynaTuringa {
private:
    vector<RegulaPrzejscia> reguly;
    vector<string> tasma;
    int glowica = 0;
    string aktualnyStan = "q0";

public:
    void wyswietl (int indeks);
    void uruchom ();
    void zapiszInputDoPliku ();
    void zapiszOutputDoPliku ();

};

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


    return 0;
}
