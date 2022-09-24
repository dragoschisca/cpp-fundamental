 #include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <string>
#include <cstring>
#include <cstdlib>


using namespace std;

struct info
{
  char nume[20], prenume[20], pictura[30], patria[30];
  int an;
  float pret;
};

int i, j;

void citire(info k[], int &nr)
{
  fstream f("galerie.txt");

  f >> nr;

  for (i = 1; i <= nr; i++)
  {
    f >> k[i].prenume;
    f >> k[i].nume;
    f >> k[i].pictura;
    f >> k[i].an;
    f >> k[i].pret;
    f >> k[i].patria;
  }
}

void afisare()
{
  cout << "Nr:";
  cout << setw(15) << "Prenume:";
  cout << setw(15) << "Nume: ";
  cout << setw(15) << "Lucrarea:";
  cout << setw(15) << "Anul:";
  cout << setw(15) << "Pretul:";
  cout << setw(15) << "Patria:" << endl;

}

void afisare(info k[], int & nr)
{
  afisare();
  fstream f("galerie.txt");

  f >> nr;

  for (i = 1; i <= nr; i++) {
    cout << i;
    cout << setw(15) << k[i].prenume;
    cout << setw(15) << k[i].nume;
    cout << setw(15) << k[i].pictura;
    cout << setw(15) << k[i].an;
    cout << setw(13) << k[i].pret << "M$ ";
    cout << setw(15) << k[i].patria << endl;
  }
}

void save(info k[], int nr, fstream & h)
{
  ofstream f("galerie.txt");

  f.close();

  h << nr;

  for (i = 1; i <= nr; i++) {
    h << endl << k[i].prenume << " ";
    h << k[i].nume << " ";
    h << k[i].pictura << " ";
    h << k[i].an << " ";
    h << k[i].pret << " ";
    h << k[i].patria << " ";
  }
}
void afisinfo(info k[])
{
    cout << setw(15) << setfill(' ') << k[i].prenume << " ";
    cout << setw(13) << k[i].nume << " ";
    cout << setw(13) << k[i].pictura << " ";
    cout << setw(15) << k[i].pret << " ";
    cout << setw(15) << k[i].an << " ";
    cout << setw(13) << k[i].patria << " " << endl;
}

//----------------------------------------------MODIFICAREA STRUCTURII UNUI FISIER
void adaugare(info k[], int &nr)
{
  fstream f("galerie.txt");

    nr++;

  cout << "Introduceti datele pentru linia noua:" << endl;
  cout << "Prenumele: ";
  cin >> k[nr].prenume;
  cout << "Numele: ";
  cin >> k[nr].nume;
  cout << "Pictura: ";
  cin >> k[nr].pictura;
  cout << "Anul finalizarii: ";
  cin >> k[nr].an;
  cout << "Pretul crearii: ";
  cin >> k[nr].pret;
  cout << "Patria autorului: ";
  cin >> k[nr].patria;

  save(k, nr, f);
}
void insertsave(info k[], int nr, fstream &h)
{
  fstream f("galerie.txt");

  f << nr;

  for (i = 1; i <= nr; i++) {
    f << endl << k[i].prenume << " ";
    f << k[i].nume << " ";
    f << k[i].pictura << " ";
    f << k[i].an << " ";
    f << k[i].pret << " ";
    f << k[i].patria << " ";
  }
}
void inserare(info k[], int &nr)
{
  fstream h("inserare.in");

  int nr2;

  h >> nr2;

  nr = nr + nr2;

  for (i = nr+1 - nr2; i <= nr; i++)
    {
    h >> k[i].prenume;
    h >> k[i].nume;
    h >> k[i].pictura;
    h >> k[i].an;
    h >> k[i].pret;
    h >> k[i].patria;
  }

  insertsave(k, nr, h);
  afisare(k, nr);
}
void excludere(info k[], int nr)
{
  bool removed = false;
  afisare(k, nr);
  fstream f("galerie.txt");

  char numele[20];
  cout << "Introduceti numele autorului care trebuie exclus: ";
  cin >> numele;
  cout << endl;

  for (i = 0; i < nr; i++) {
    if (removed) {
      k[i] = k[i + 1];
    }

    if (strcmp(k[i].nume, numele) == 0) {
      removed = true;
      k[i] = k[i + 1];
    }
  }

  nr--;
  save(k, nr, f);
}

//-----------------------------------------------PRELUCRARI RELATIVE
void decupare(info k[], int nr)
{
  fstream f("galerie.txt");
  int aleg, aleg2;

  afisare(k, nr);

  cout << endl << endl;

  cout << "Introduceti numarul liniei care va fi schimbata: ";
  cin >> aleg;
  cout << endl;

  cout << "Alegeti ce doriti sa decupati: " << endl;

  cout << "Prenumele--------1" << endl;
  cout << "Numele-----------2" << endl;
  cout << "Pictura----------3" << endl;
  cout << "Patria-----------4" << endl;
  cout << "Alegeti o optiune: ";
  cin >> aleg2;
  cout << endl;

  switch (aleg2) {

 int pozitie;
 int nr2;

  case 1:

  cout << "Introduceti numarul de caractere care vor fi decupate de la dreapta la stanga: ";
 cin >> pozitie;

     nr2 = strlen(k[aleg].prenume);

    strcpy(k[aleg].prenume + nr2 - pozitie,k[aleg].prenume + nr2 + pozitie);
     afisare(k,nr);
    break;

  case 2:

 cout << "Introduceti numarul de caractere care vor fi decupate de la dreapta la stanga: ";
 cin >> pozitie;

     nr2 = strlen(k[aleg].nume);

    strcpy(k[aleg].nume + nr2 - pozitie,k[aleg].nume + nr2 + pozitie);
     afisare(k,nr);
    break;

  case 3:

 cout << "Introduceti numarul de caractere care vor fi decupate de la dreapta la stanga: ";
 cin >> pozitie;

     nr2 = strlen(k[aleg].pictura);

    strcpy(k[aleg].pictura+ nr2 - pozitie,k[aleg].pictura + nr2 + pozitie);
     afisare(k,nr);
    break;

  case 4:
      cout << "Introduceti numarul de caractere care vor fi decupate de la dreapta la stanga: ";
 cin >> pozitie;

     nr2 = strlen(k[aleg].patria);

    strcpy(k[aleg].patria + nr2 - pozitie,k[aleg].patria + nr2 + pozitie);
     afisare(k,nr);
    break;

  }
  save(k, nr, f);
  system("cls");
  afisare(k, nr);

}

void actualizare(info k[], int nr)
{

  fstream f("galerie.txt");
  int aleg, aleg2;

  afisare(k, nr);

  cout << endl << endl;

  cout << "Introduceti numarul liniei care va fi schimbata: ";
  cin >> aleg;
  cout << endl;

  cout << "Alegeti ce doriti sa actualizati: " << endl;

  cout << "Prenumele--------1" << endl;
  cout << "Numele-----------2" << endl;
  cout << "Pictura----------3" << endl;
  cout << "Anul-------------4" << endl;
  cout << "Pretul-----------5" << endl;
  cout << "Patria-----------6" << endl;
  cout << "Ati ales: ";
  cin >> aleg2;
  cout << endl;

  switch (aleg2)
  {
    char nou[20];
    int n;

  case 1:

    cout << "Introduceti prenumele nou al autorului: ";
    cin >> nou;

    strcpy(k[aleg].prenume, nou);

    break;

  case 2:

    cout << "Introduceti numele nou al autorului: ";
    cin >> nou;

    strcpy(k[aleg].nume, nou);

    break;

  case 3:

    cout << "Introduceti numele tabloului nou al autorului: ";
    cin >> nou;

    strcpy(k[aleg].pictura, nou);

    break;

  case 4:

    cout << "Introduceti anul nou al tabloului: ";
    cin >> n;

    k[aleg].an = n;

    break;

  case 5:

    cout << "Introduceti pretul nou al tabloului: ";
    cin >> n;

    k[aleg].pret = n;

    break;

  case 6:

    cout << "Introduceti patria noua a pictorului: ";
    cin >> n;

    strcpy(k[aleg].patria, nou);

    break;
  }

  save(k, nr, f);
  system("cls");
  afisare(k, nr);
}

void filtrupret(info k[], int nr)
{
    int filtru1, filtru2;

    cout << endl << endl;
cout << "Introduceti preturile intre care ar trebui sa se afle tabloul: " << endl;

        cout << "Pret minim: ";
        cin >> filtru1;

        cout << "Pret maxim: ";
        cin >> filtru2;

          cout << endl;
        cout << "Rezultatele filtrarii: " << endl;

        afisare();

        for(i = 1; i <= nr; i++)
        {
            if(filtru1 <= k[i].pret && k[i].pret <= filtru2)
                {
    cout << i;
    cout << setw(17) << setfill(' ') << k[i].prenume << " ";
    cout << setw(13) << k[i].nume << " ";
    cout << setw(13) << k[i].pictura << " ";
    cout << setw(15) << k[i].pret << " ";
    cout << setw(15) << k[i].an << " ";
    cout << setw(13) << k[i].patria << " " << endl;
                }
        }
    }
void filtruan(info k[], int nr)
{
    int filtru1, filtru2;

    cout << endl << endl;
cout << "Introduceti anii intre care ar trebui sa se afle tabloul: " << endl;

        cout << "Anul minim: ";
        cin >> filtru1;

        cout << "Anul maxim: ";
        cin >> filtru2;

        cout << endl;
        cout << "Rezultatele filtrarii: " << endl;

        afisare();

        for(i = 1; i <= nr; i++)
        {
            if(filtru1 <= k[i].an && k[i].an <= filtru2)
                {
    cout << i;
    cout << setw(17) << setfill(' ') << k[i].prenume << " ";
    cout << setw(13) << k[i].nume << " ";
    cout << setw(13) << k[i].pictura << " ";
    cout << setw(15) << k[i].pret << " ";
    cout << setw(15) << k[i].an << " ";
    cout << setw(13) << k[i].patria << " " << endl;
                }
        }
    }

void cautarepret(info k[], int nr)
{
    int pretul;

    cout << endl << endl;
    cout << "Introduceti pretul care il cautati: ";
    cin >> pretul;


    cout << endl;
        cout << "Rezultatele cautarii: " << endl;
    afisare();

    for(i = 1; i <= nr; i++)
        {
            if(k[i].pret == pretul)
                {
    cout << i;
    cout << setw(17) << k[i].prenume << " ";
    cout << setw(13) << k[i].nume << " ";
    cout << setw(13) << k[i].pictura << " ";
    cout << setw(15) << k[i].pret << " ";
    cout << setw(15) << k[i].an << " ";
    cout << setw(13) << k[i].patria << " " << endl;
                }
        }
    }
void cautarean(info k[], int nr)
{
    int anul;

    cout << "Introduceti anul care il cautati:";
    cin >> anul;

     cout << endl;
        cout << "Rezultatele cautarii: " << endl;

    afisare();

    for(i = 1; i <= nr; i++)
        {
            if(k[i].an == anul)
                {
    cout << i;
    cout << setw(17) << k[i].prenume << " ";
    cout << setw(13) << k[i].nume << " ";
    cout << setw(13) << k[i].pictura << " ";
    cout << setw(15) << k[i].an << " ";
    cout << setw(15) << k[i].pret << " ";
    cout << setw(13) << k[i].patria << " " << endl;
                }
        }
}
void cautarepatrie(info k[], int nr)
{
    char patrie[15];

    cout << "Introduceti patria pictorului care il cautati: ";
    cin >> patrie;

     cout << endl;
        cout << "Rezultatele cautarii: " << endl;

    afisare();

    for(i = 1; i <= nr; i++)
        {
            if(strcmp(k[i].patria,patrie) == 0)
                {
    cout << i;
    cout << setw(17) << k[i].prenume << " ";
    cout << setw(13) << k[i].nume << " ";
    cout << setw(13) << k[i].pictura << " ";
    cout << setw(15) << k[i].an << " ";
    cout << setw(15) << k[i].pret << " ";
    cout << setw(13) << k[i].patria << " " << endl;
                }
        }
}

void cautarenume(info k[], int nr)
{
    char nume[15];

    cout << "Introduceti numele pictorului care il cautati: ";
    cin >> nume;

     cout << endl;
        cout << "Rezultatele cautarii: " << endl;

    afisare();

    for(i = 1; i <= nr; i++)
        {
            if(strcmp(k[i].nume, nume) == 0)
                {
    cout << i;
    cout << setw(17) << setfill(' ') << k[i].prenume << " ";
    cout << setw(13) << k[i].nume << " ";
    cout << setw(13) << k[i].pictura << " ";
    cout << setw(15) << k[i].an << " ";
    cout << setw(13) << k[i].pret << " ";
    cout << setw(15) << k[i].patria << " " << endl;
                }
        }
}
//-------------------------------------------------SORTAREA ELEMENTELOR
void sortcresnume(info k[], int nr, char num[])
{

  fstream f("galerie.txt");
  info aux;

  for (i = 1; i <= nr; i++) {

    for (j = i + 1; j <= nr; j++)
      if (strcmp(k[i].nume, k[j].nume) < 0) {
        aux = k[i];
        k[i] = k[j];
        k[j] = aux;
      }
  }
  save(k, nr, f);
  afisare(k, nr);

}

void sortdescresnume(info k[], int nr, char num[])
{
  fstream f("galerie.txt");
  info aux;

  for (i = 1; i <= nr; i++) {

    for (j = i + 1; j <= nr; j++)
      if (strcmp(k[i].nume, k[j].nume) > 0)
        {
        aux = k[i];
        k[i] = k[j];
        k[j] = aux;
      }
  }
  save(k, nr, f);
  afisare(k, nr);

}

void sortarean1(info k[], int nr)
{
  fstream f("galerie.txt");
  info aux;

  for (i = 1; i <= nr; i++)
  {
    for (j = i + 1; j <= nr; j++)
        {
      if (k[i].an > k[j].an)
      {
        aux = k[i];
        k[i] = k[j];
        k[j] = aux;
      }
    }
  }
  save(k, nr, f);
  afisare(k, nr);
}

void sortarean2(info k[], int nr) {
  fstream f("galerie.txt");
  info aux;

  for (i = 1; i <= nr; i++)
    {
    for (j = i + 1; j <= nr; j++)
    {
      if (k[i].an < k[j].an)
      {
        aux = k[i];
        k[i] = k[j];
        k[j] = aux;
      }
    }
  }
  save(k, nr, f);
  afisare(k, nr);
}

void sortarepret1(info k[], int nr)
{
  fstream f("galerie.txt");
  info aux;

  for (i = 1; i <= nr; i++)
    {
    for (j = i + 1; j <= nr; j++)
    {
      if (k[i].pret > k[j].pret)
      {
        aux = k[i];
        k[i] = k[j];
        k[j] = aux;
      }
    }
  }
  save(k, nr, f);
  afisare(k, nr);
}

void sortarepret2(info k[], int nr)
{
  fstream f("galerie.txt");
  info aux;

  for (i = 1; i <= nr; i++)
  {
    for (j = i + 1; j <= nr; j++)
        {
      if (k[i].pret < k[j].pret)
      {
        aux = k[i];
        k[i] = k[j];
        k[j] = aux;
      }
    }
  }
  save(k, nr, f);
  afisare(k, nr);
}

void sortarepatria1(info k[], int nr, char num[])
{
  fstream f("galerie.txt");
  info aux;

  for (i = 1; i <= nr; i++)
    {
    for (j = i + 1; j <= nr; j++)
      if (strcmp(k[i].patria, k[j].patria) < 0)
        {
        aux = k[i];
        k[i] = k[j];
        k[j] = aux;
      }
  }

  save(k, nr, f);
  afisare(k, nr);

}

void sortarepatria2(info k[], int nr, char num[])
 {
  fstream f("galerie.txt");
  info aux;

  for (i = 1; i <= nr; i++)
    {

    for (j = i + 1; j <= nr; j++)
      if (strcmp(k[i].patria, k[j].patria) > 0)
        {
        aux = k[i];
        k[i] = k[j];
        k[j] = aux;
      }
  }
  save(k, nr, f);
  afisare(k, nr);

}

//------------------------------------------PRELUCRARI STATISTICE ALE DATELOR
void veche(info k[], int nr) {

  int min = 100000;

  for (i = 1; i <= nr; i++)
    {
    if (min > k[i].an)
      min = k[i].an;
  }

  for (i = 1; i <= nr; i++)
    {
    if (k[i].an == min)
      cout << "Cea mai veche opera este " << k[i].pictura << " de " << k[i].prenume << " " << k[i].nume << " pictata in " << k[i].an << " avand " << 2021 - min << " de ani " << endl;
  }
}
void tanara(info k[], int nr) {

  int max = -1;

  for (i = 1; i <= nr; i++)
    {
    if (max < k[i].an)
      max = k[i].an;
  }

  for (i = 1; i <= nr; i++)
    {
    if (k[i].an == max)
      cout << "Cea mai tanara opera este " << k[i].pictura << " de " << k[i].prenume << " " << k[i].nume << " pictata in " << k[i].an << " avand " << 2021 - max << " de ani" << endl;
  }
}

void scumpa(info k[], int nr)
{
  int pret_max = -1;

  for (i = 1; i <= nr; i++)
    {
    if (pret_max < k[i].pret)
      pret_max = k[i].pret;
  }

  for (i = 1; i <= nr; i++)
    {
    if (k[i].pret == pret_max)
      cout << "Cea mai scumpa opera este " << k[i].pictura << " de " << k[i].prenume << " " << k[i].nume << " aceasta valorand " << k[i].pret << "M$" << endl;
  }

}

void ieftina(info k[], int nr)
 {
  int pret_min = 100000;

  for (i = 1; i <= nr; i++)
    {
    if (pret_min > k[i].pret)
      pret_min = k[i].pret;
  }

  for (i = 1; i <= nr; i++)
    {
    if (k[i].pret == pret_min)
      cout << "Cea mai ieftina opera este " << k[i].pictura << " de " << k[i].prenume << " " << k[i].nume << " aceasta valorand " << k[i].pret << "M$" << endl;
  }

}

void mediupret(info k[], int nr)
{
  float suma = 0;

  for (i = 1; i <= nr; i++)
    {
    suma += k[i].pret;
  }
  cout << "Pretul mediu al tablourilor este: " << setprecision(4) << (float) suma / nr << "M$" << endl;
}

void anmediu(info k[], int nr)
{

  float ani = 0;

  for (i = 1; i <= nr; i++)
    {
    ani += k[i].an;
  }

  cout << "Varsta medie a picturilor este: " << setprecision(4) << 2021 - (float)(ani / nr) << " ani" << endl;

}

void fisier(info k[], int nr)
{
  char denumire[20];

  cout << "Introuduceti numele fisierului unde va fi extrasa informatia: ";
  cin >> denumire;

  ofstream f(denumire);

  f << nr;

  for (i = 1; i <= nr; i++)
    {
    f << endl << k[i].prenume << " ";
    f << k[i].nume << " ";
    f << k[i].pictura << " ";
    f << k[i].an << " ";
    f << k[i].pret << " ";
    f << k[i].patria << " ";
  }

}
