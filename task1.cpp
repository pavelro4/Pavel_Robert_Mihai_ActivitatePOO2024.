#include <iostream>
#include <string>
using namespace std;

struct Bloc {
    string strada;
    int numar_scari;
    int numar_apartamente;
    int an_constructie;
    string nume_administrator;

    void citesteBloc() {
        cout << "Introduceti strada (fara spatiu): ";
        cin >> strada; 
        cout << "Introduceti numarul de scari: ";
        cin >> numar_scari;
        cin.ignore();
        cout << "Introduceti numarul de apartamente: ";
        cin >> numar_apartamente;
        cin.ignore();
        cout << "Introduceti anul constructiei: ";
        cin >> an_constructie;
        cin.ignore();
        cout << "Introduceti numele administratorului (fara spatiu ): ";
        cin >> nume_administrator; 
    }


    void afiseazaBloc() const {
        cout << "Blocul de pe strada " << strada
            << ", are " << numar_scari << " scari si un numar total de "
            << numar_apartamente << " apartamente, construit in anul "
            << an_constructie << ". Administratorul este "
            << nume_administrator << "." << endl;
    }
};

int main() {
    const int numar_blocuri = 10;
    Bloc* blocuri[numar_blocuri];

    for (int i = 0; i < numar_blocuri; ++i) {
        cout << "\nCititi detaliile pentru blocul " << i + 1 << ":" << endl;
        blocuri[i] = new Bloc();
        blocuri[i]->citesteBloc();
    }

    cout << "\nDetaliile blocurilor sunt:" << endl;
    for (int i = 0; i < numar_blocuri; ++i) {
        blocuri[i]->afiseazaBloc();
    }

    for (int i = 0; i < numar_blocuri; ++i) {
        delete blocuri[i];
    }

    return 0;
}
