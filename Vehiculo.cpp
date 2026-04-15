#include <iostream>
#include <string>

using namespace std;


class Vehiculo {
private:
    string marca;
    string modelo;
    int anio;

public:
    // constructores
    Vehiculo() : marca("Sin marca"), modelo("Sin modelo"), anio(2022) {}
    
    Vehiculo(string _marca, string _modelo, int _anio) {
        setMarca(_marca);
        setModelo(_modelo);
        setAnio(_anio);
    }

    void setMarca(string m) { if (!m.empty()) marca = m; }
    void setModelo(string mod) { if (!mod.empty()) modelo = mod; }
    void setAnio(int a) { if (a > 1885) anio = a; }

    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    int getAnio() const { return anio; }

    void mostrarDatos() const {
        cout << "Vehiculo: " << marca << " " << modelo << " (" << anio << ")" << endl;
    }

   
    virtual void encender() const {
        cout << "El auto esta encendido." << endl;
    }

    virtual ~Vehiculo() {} 
};

//sub clase automovil
class Auto : public Vehiculo {
private:
    int numPuertas;

public:
    Auto() : Vehiculo(), numPuertas(4) {}

    Auto(string m, string mod, int a, int puertas) : Vehiculo(m, mod, a) {
        setNumPuertas(puertas);
    }

    void setNumPuertas(int p) { if (p > 0) numPuertas = p; }
    int getNumPuertas() const { return numPuertas; }

    
    void encender() const override {
        cout << "[Auto] Al presionar el boton de encendido se puede sentir el V8." << endl;
    }

    
    void abrirCajuela() const {
        cout << "[Auto] La cajuela se ha abierto..." << endl;
    }
};

//sub clase moto
class Motocicleta : public Vehiculo {
private:
    int cilindrada;

public:
    Motocicleta() : Vehiculo(), cilindrada(150) {}

    Motocicleta(string m, string mod, int a, int cc) : Vehiculo(m, mod, a) {
        setCilindrada(cc);
    }

    void setCilindrada(int cc) { if (cc > 0) cilindrada = cc; }
    int getCilindrada() const { return cilindrada; }

    
    void encender() const override {
        cout << "[Moto] Presionando boton de encendido... El motor de " << cilindrada << "cc ruge." << endl;
    }

    // metodo adicional
    void hacerCaballito() const {
        cout << "[Moto] La motocicleta se levanta en una rueda! (Haciendo un caballito)" << endl;
    }
};


int main() {
    
    Auto miAuto("Mustang", "MACH", 1970, 4);
    Motocicleta miMoto("Ducati", "Panigale", 2023, 1100);

    
    cout << "--- PRUEBA DE AUTO ---" << endl;
    miAuto.mostrarDatos();
    cout << "Puertas: " << miAuto.getNumPuertas() << endl;
    
    
    miAuto.encender(); 
    
    
    miAuto.abrirCajuela();

    cout << "\n----------------------------\n" << endl;

    cout << "--- PRUEBA DE MOTOCICLETA ---" << endl;
    miMoto.mostrarDatos();
    cout << "Cilindrada: " << miMoto.getCilindrada() << "cc" << endl;
    
    
    miMoto.encender(); 
    
    
    miMoto.hacerCaballito();

    return 0;
}
