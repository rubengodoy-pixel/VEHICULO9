#include <iostream>
#include <string>

using namespace std;


class Persona {
private:
    string nombre;
    int edad;
    string correo;

public:
    // constructores
    Persona() : nombre("Sin nombre"), edad(0), correo("sin@correo.com") {}
    
    Persona(string n, int e, string c) {
        setNombre(n);
        setEdad(e);
        setCorreo(c);
    }

    // Setters con validación
    void setNombre(string n) {
        if (!n.empty()) nombre = n;
        else nombre = "Nombre Inválido";
    }

    void setEdad(int e) {
        if (e >= 0) edad = e;
        else edad = 0; // evitar edad negativa
    }

    void setCorreo(string c) {
        if (!c.empty()) correo = c;
        else correo = "correo@ejemplo.com";
    }

    // Getters
    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    string getCorreo() const { return correo; }

    
    void mostrarInformacion() const {
        cout << "Nombre: " << nombre << " | Edad: " << edad 
             << " | Correo: " << correo << endl;
    }

    
    virtual void realizarActividad() const {
        cout << nombre << " esta realizando una actividad general." << endl;
    }

    virtual ~Persona() {} 
};


class Alumno : public Persona {
private:
    string carrera;
    int semestre;

public:
    Alumno() : Persona(), carrera("N/A"), semestre(1) {}

    Alumno(string n, int e, string c, string car, int sem) : Persona(n, e, c) {
        setCarrera(car);
        setSemestre(sem);
    }

    void setCarrera(string car) {
        if (!car.empty()) carrera = car;
        else carrera = "Indefinida";
    }

    void setSemestre(int sem) {
        if (sem >= 1 && sem <= 12) semestre = sem;
        else semestre = 1;
    }

    string getCarrera() const { return carrera; }
    int getSemestre() const { return semestre; }

    
    void realizarActividad() const override {
        cout << "[Actividad Alumno]: " << getNombre() << " esta asistiendo a clases de " << carrera << "." << endl;
    }

    void estudiar() const {
        cout << getNombre() << " esta sobreviviendo al semestre " << semestre << "." << endl;
    }
};


class Docente : public Persona {
private:
    string materia;
    int horasClase;

public:
    Docente() : Persona(), materia("N/A"), horasClase(0) {}

    Docente(string n, int e, string c, string mat, int hrs) : Persona(n, e, c) {
        setMateria(mat);
        setHorasClase(hrs);
    }

    void setMateria(string mat) {
        if (!mat.empty()) materia = mat;
        else materia = "Sin asignar";
    }

    void setHorasClase(int hrs) {
        if (hrs >= 0) horasClase = hrs;
        else horasClase = 0;
    }

    string getMateria() const { return materia; }
    int getHorasClase() const { return horasClase; }

    
    void realizarActividad() const override {
        cout << "[Actividad Docente]: " << getNombre() << " esta preparando el material de " << materia << "." << endl;
    }

    void impartirClase() const {
        cout << "El profesor " << getNombre() << " esta impartiendo " << horasClase << " horas de clase." << endl;
    }
};


int main() {
    cout << "=== SISTEMA DE GESTION INSTITUCIONAL ===" << endl << endl;

    
    Alumno alumno1("Ruben Godoy", 21, "ruben.godoy@cestys.edu.mx", "Ingenieria Mecatronica", 4);
    Docente docente1("Leonardo Lomeli", 28, "leonardo.david@cetys.edu.mx", "Lenguajes de Programacion", 20);

    
    cout << "INFORMACION DEL ALUMNO:" << endl;
    alumno1.mostrarInformacion();
    cout << "Carrera: " << alumno1.getCarrera() << " | Semestre: " << alumno1.getSemestre() << endl;
    alumno1.realizarActividad();
    alumno1.estudiar();

    cout << "\n----------------------------------------\n" << endl;

    cout << "INFORMACION DEL DOCENTE:" << endl;
    docente1.mostrarInformacion();
    cout << "Materia: " << docente1.getMateria() << " | Horas: " << docente1.getHorasClase() << endl;
    docente1.realizarActividad();
    docente1.impartirClase();

  
    cout << "\n----------------------------------------\n" << endl;
    cout << "PRUEBA DE VALIDACION (Datos erroneos):" << endl;
    Alumno alumno2("", -5, "error@test.com", "", 99);
    alumno2.mostrarInformacion(); // muestra valores por defecto o erroneos 

    return 0;
}