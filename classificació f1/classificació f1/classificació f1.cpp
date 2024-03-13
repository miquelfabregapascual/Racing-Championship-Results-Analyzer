
#include <fstream>  // Para ifstream
#include <iostream> // Para cout
#include <vector>
#include <algorithm>
using namespace std;
void muestra_vector(const vector<string>& v, vector<int> puntuacio);
int  convertir(const vector<int>&);
int main()
{
    string fitxer;
    ifstream fich;
    cout << "El nom del fitxer:";
    cin >> fitxer;
    string valor;
    vector<string> dades;
   
    fich.open(fitxer);
    if (!fich.is_open())
    {
        cout << "Error al abrir Pilots_class_Fi.txt\n";
        exit(EXIT_FAILURE);
    }
    //while (!fich.eof()) {
    //    fich>>valor;
    //    cout << valor;
    //}
    int numeros;
    fich >> numeros;
    int numpilots;
    fich >> numpilots;
    vector<string> datos;
    datos.reserve(numpilots);
    vector<int> puntuacio,punts;

    cout << "numero de voltes" << numeros <<endl;
    cout << "numero de pilots" << numpilots<< endl;

    for (int i = 0; i < numpilots; i++) {
        string valor;
        fich >> valor;
        datos.push_back(valor);
        puntuacio.clear();
        for (int a = 0; a < numeros; a++) {
            int valor2;
            fich >> valor2;
            puntuacio.push_back(valor2);
        }
         punts.push_back(convertir(puntuacio));


    }

    for (int i = 0; i < punts.size()-1; i++) {
        // Comparaciones
        for (int j = 0; j < punts.size() - i-1; j++) {
             //Intercambiar los elementos
            if (punts[j] < punts[j + 1]) {
                swap(punts[j], punts[j + 1]);
                swap(datos[j], datos[j + 1]);

           }
       }
    }

   // sort(punts.begin(), punts.end());
    muestra_vector(datos,punts);
}



int  convertir(const vector<int>& v)
{
   
    int convercio[] = { 0,10,8,6,5,4,3,2,1 };
    int total=0;
   
    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= 8) {
            total += convercio[v[i]];
        }
    }
    //sort(v[0], v[v.size()]);
     return total;
     
}




void muestra_vector(const vector<string>& v, vector<int> puntuacio)
{
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " " << puntuacio[i];
       
        cout <<endl;
    }

}

