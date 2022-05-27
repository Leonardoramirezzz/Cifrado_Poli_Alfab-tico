// CIFRADO POLI-ALFABÉTICO
#include <iostream>

using namespace std;

string abecedario = "ABCDEFGHIJKLMN/OPQRSTUVWXYZ";


int mod_ (int a, int b) {
    int q = a / b;
    int r = a - (q * b);
    if (r < 0) { q--; r = a - (q * b); }
    return r;
}

int posi(int a){
  int respuesta = a;
  if (respuesta < 0) respuesta *= -1;
  return respuesta;
}


int indice_en_abc (char a){
  int indice;
  for (int i = 0; i < 27; i++) if (abecedario[i] == a) indice = i;
  return indice;
}

char num_to_letra(int a){
  char retorno = abecedario[a];  
  return retorno;
}


void cif_pol_alf(string msj, string clave){
  string msj_cifrado;

  int j = 0;
  for (int i = 0; i < msj.length(); i++){
    if (j == clave.length()-1){
    msj_cifrado[i] = num_to_letra(mod_((indice_en_abc(msj[i]) + indice_en_abc(clave[j])), 27));
    j = 0;
    }
    
    else if (j <= clave.length()-1){
    msj_cifrado[i] = num_to_letra(mod_((indice_en_abc(msj[i]) + indice_en_abc(clave[j])), 27));
    j++;
    }
    cout << msj_cifrado[i];
  }
  
  cout << endl << endl;
}

void descif_pol_alf(string msj, string clave){
  string msj_descifrado;

  int j = 0;
  for (int i = 0; i < msj.length(); i++){
    if (j == clave.length()-1){
    msj_descifrado[i] = num_to_letra(mod_((indice_en_abc(msj[i]) - indice_en_abc(clave[j])),  27));
    j = 0;
    }
      
    else if (j <= clave.length()-1){
    msj_descifrado[i] = num_to_letra(mod_((indice_en_abc(msj[i]) - indice_en_abc(clave[j])),  27));
    j++;
    }
    else j = 0;
    cout << msj_descifrado[i];
  }
  
  cout << endl << endl;
}


int main() {
  bool run = true;
  int opcion;
  string clave;
  cout << "------------- CIFRACO POLI-ALFABÉTICO -------------" << endl << endl;
  while (true){
    cout << "Ingrese la clave para trabajar: " << endl;
    cin >> clave;
    cout << endl;
    
    while (run){
      cout << "---------------------------------" << endl;
      cout << "Ingrese: " << endl;
      cout << "1. Cifrar una mensaje." << endl;
      cout << "2. Descifrar una mensaje." << endl;
      cout << "3. Escoger otra clave." << endl;
      cout << "0. Cerrar el programa" << endl;
      cin >> opcion;
      cout << "---------------------------------" << endl;
      
      if (opcion == 1){
        cout << "Ingrese el mensaje que desea cifrar: ";
        string mensaje;
        cin >> mensaje;
        cout << "El mensaje cifrado es: ";
        cif_pol_alf(mensaje,clave);
        
      }
  
      else if (opcion == 2){
        cout << "Ingrese el mensaje que desea descifrar: ";
        string mensaje;
        cin >> mensaje;
        descif_pol_alf(mensaje, clave);
      }
  
      else if (opcion == 3){
        cout << endl; break;
      }

      else if (opcion == 0){ cout << "Programa finalizado."; return 0; }
    }
  }
  return 0;
}
