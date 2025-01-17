#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

class Camion {
private:
    string marca;
    int capacitate_tone;
    int* numar_remorci;
    float consum_combustibil;
    int an_fabricatie;
    static int total_camioane;
    const string tip_combustibil;

public:
    Camion() : tip_combustibil("Motorina") {
        marca = "Necunoscut";
        capacitate_tone = 0;
        numar_remorci = new int(0);
        consum_combustibil = 0.0;
        an_fabricatie = 0;
        total_camioane++;
    }

    Camion(string marca, int capacitate) : tip_combustibil("Motorina") {
        this->marca = marca;
        this->capacitate_tone = capacitate;
        this->numar_remorci = new int(0);
        this->consum_combustibil = 0.0;
        this->an_fabricatie = 0;
        total_camioane++;
    }

    Camion(string marca, int capacitate, int remorci, float consum, int an) : tip_combustibil("Motorina") {
        this->marca = marca;
        this->capacitate_tone = capacitate;
        this->numar_remorci = new int(remorci);
        this->consum_combustibil = consum;
        this->an_fabricatie = an;
        total_camioane++;
    }

    Camion(const Camion& other) : tip_combustibil("Motorina") {
        marca = other.marca;
        capacitate_tone = other.capacitate_tone;
        numar_remorci = new int(*other.numar_remorci);
        consum_combustibil = other.consum_combustibil;
        an_fabricatie = other.an_fabricatie;
        total_camioane++;
    }

    ~Camion() {
        delete numar_remorci;
    }

    Camion& operator=(const Camion& other) {
        if (this == &other) return *this;
        delete numar_remorci;
        marca = other.marca;
        capacitate_tone = other.capacitate_tone;
        numar_remorci = new int(*other.numar_remorci);
        consum_combustibil = other.consum_combustibil;
        an_fabricatie = other.an_fabricatie;
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Camion& c) {
        out << "Marca: " << c.marca << ", Capacitate: " << c.capacitate_tone << " tone, Numar remorci: "
            << *c.numar_remorci << ", Consum: " << c.consum_combustibil << " L/100km, An fabricatie: " << c.an_fabricatie;
        return out;
    }

    friend istream& operator>>(istream& in, Camion& c) {
        cout << "Introduceti marca: ";
        in >> c.marca;
        cout << "Introduceti capacitate: ";
        in >> c.capacitate_tone;
        cout << "Introduceti numarul de remorci: ";
        in >> *c.numar_remorci;
        cout << "Introduceti consumul de combustibil: ";
        in >> c.consum_combustibil;
        cout << "Introduceti anul fabricatiei: ";
        in >> c.an_fabricatie;
        return in;
    }

    void afisareDetalii() const {
        cout << *this << endl;
    }

    
    int getCapacitateTone() const {
        return capacitate_tone;
    }
};

int Camion::total_camioane = 0;


class Flota {
private:
    vector<Camion> flota_camioane;
    string denumire;
    int total_capacitate;

public:
    Flota(string denumire = "") : denumire(denumire), total_capacitate(0) {}

    void adaugaCamion(const Camion& camion) {
        flota_camioane.push_back(camion);
        total_capacitate += camion.getCapacitateTone();
    }

    int getCapacitateTone() const {
        return total_capacitate;
    }

    void afisareFlota() const {
        cout << "Flota: " << denumire << ", Capacitate totala: " << total_capacitate << " tone" << endl;
        for (const auto& camion : flota_camioane) {
            camion.afisareDetalii();
        }
    }

    Flota& operator=(const Flota& other) {
        if (this == &other) return *this;
        flota_camioane = other.flota_camioane;
        denumire = other.denumire;
        total_capacitate = other.total_capacitate;
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Flota& f) {
        out << "Flota: " << f.denumire << ", Capacitate totala: " << f.total_capacitate << " tone\n";
        for (const auto& camion : f.flota_camioane) {
            out << camion << endl;
        }
        return out;
    }

    friend istream& operator>>(istream& in, Flota& f) {
        cout << "Introduceti denumirea flotei: ";
        in >> f.denumire;
        int n;
        cout << "Introduceti numarul de camioane: ";
        in >> n;
        f.flota_camioane.clear();
        f.total_capacitate = 0;
        for (int i = 0; i < n; ++i) {
            Camion camion;
            cout << "Camion " << i + 1 << ":\n";
            in >> camion;
            f.adaugaCamion(camion);
        }
        return in;
    }
};

class Motocicleta {
private:
    string brand;
    int putere;
    int viteza_maxima;
    string tip;

public:
    Motocicleta& operator=(const Motocicleta& other) {
        if (this != &other) {
            brand = other.brand;
            putere = other.putere;
            viteza_maxima = other.viteza_maxima;
            tip = other.tip;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Motocicleta& m) {
        os << m.brand << " " << m.putere << " " << m.viteza_maxima << " " << m.tip;
        return os;
    }

    friend istream& operator>>(istream& is, Motocicleta& m) {
        is >> m.brand >> m.putere >> m.viteza_maxima >> m.tip;
        return is;
    }
};

class Masina {
private:
    string model;
    int nr_locuri;
    float consum_mediu;
    bool electrica;

public:
    Masina() : model("Necunoscut"), nr_locuri(0), consum_mediu(0.0), electrica(false) {}

    Masina(string model, int nr_locuri, float consum_mediu, bool electrica)
        : model(model), nr_locuri(nr_locuri), consum_mediu(consum_mediu), electrica(electrica) {}

    Masina& operator=(const Masina& other) {
        if (this != &other) {
            model = other.model;
            nr_locuri = other.nr_locuri;
            consum_mediu = other.consum_mediu;
            electrica = other.electrica;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Masina& m) {
        os << m.model << " " << m.nr_locuri << " " << m.consum_mediu << " " << m.electrica;
        return os;
    }

    friend istream& operator>>(istream& is, Masina& m) {
        is >> m.model >> m.nr_locuri >> m.consum_mediu >> m.electrica;
        return is;
    }
};


int main() {
    Camion camion1("Mercedes", 10, 2, 25.5, 2020);
    Camion camion2("Volvo", 15, 1, 20.0, 2018);

    cout << "Camion 1: " << camion1 << endl;
    cout << "Camion 2: " << camion2 << endl;

    camion1 = camion2;
    cout << "Dupa atribuire, Camion 1: " << camion1 << endl;

    Masina masina1("Dacia", 5, 6.2, true);
    Masina masina2("Renault", 5, 7.8, false);

    cout << "Masina 1: " << masina1 << endl;
    cout << "Masina 2: " << masina2 << endl;

    masina1 = masina2;
    cout << "Dupa atribuire, Masina 1: " << masina1 << endl;

    Motocicleta moto1;
    cout << "Introduceti date pentru Motocicleta 1: " << endl;
    cin >> moto1;

    Motocicleta moto2;
    cout << "Introduceti date pentru Motocicleta 2: " << endl;
    cin >> moto2;

    cout << "Motocicleta 1: " << moto1 << endl;
    cout << "Motocicleta 2: " << moto2 << endl;

    Flota flota;
    cout << "Introduceti date pentru Flota: " << endl;
    cin >> flota;
    cout << "Flota: " << endl;
    flota.afisareFlota();

    return 0;
}
