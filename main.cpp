#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include "modul.h"

using namespace std;

int main()
{
  int alegere;
  int nr;
  info mod[1000];
  char num[20];

  do {
    system("color 7c");

    cout << endl;
    cout << " __________________________MENIU____________________________ " << endl;
    cout << "|...........................................................|" << endl;
    cout << "|A) Afisarea informatiei in forma tabelara-----------------1|" << endl;
    cout << "|B) Modificarea structurii unui fisier---------------------2|" << endl;
    cout << "|C) Prelucrari relative sirurilor de caractere-------------3|" << endl;
    cout << "|D) Sortari ale elementelor structurilor unidimensionale---4|" << endl;
    cout << "|E) Prelucrari statistice ale datelor de intrare-----------5|" << endl;
    cout << "|F) Extrageri de informatie--------------------------------6|" << endl;
    cout << "|() Iesire-------------------------------------------------0|" << endl;
    cout << "|...........................................................|" << endl;
    cout << "|___________________________________________________________|" << endl;
    cout << endl;

    alegere = getch();
    citire(mod, nr);
    system("cls");

    //CHISCA DRAGOS NICOLAE         GRUPA AAW 2012

    switch (alegere) {
    case '1':
      afisare(mod, nr);
      getch();
      break;
    case '2':
      cout << " ________________________________" << endl;
      cout << "|Adaugarea unei linii noi-------1|" << endl;
      cout << "|Inserarea unei linii noi-------2|" << endl;
      cout << "|Eliminarea unei linii----------3|" << endl;
      cout << "|________________________________|" << endl;
      cout << endl;

      alegere = getch();

      switch (alegere) {
      case '1':adaugare(mod, nr);
        break;
      case '2':inserare(mod, nr);
        break;
      case '3':excludere(mod, nr);
        break;
      }

      break;

    case '3':
      cout << " _____________________________________________________ " << endl;
      cout << "|Decuparea unui subsir dintr-un sir de caractere-----1|" << endl;
      cout << "|Actualizarea unui element din fisier----------------2|" << endl;
      cout << "|Prelucrarea datelor din fisier----------------------3|" << endl;
      cout << "|_____________________________________________________|" << endl;
      cout << endl;

      alegere = getch();

      switch (alegere) {
      case '1':decupare(mod, nr);
        break;
      case '2':actualizare(mod, nr);
        break;
      case '3': cout << " ____________________________________" << endl;
                cout << "|Filtrarea datelor din fisier-------1|" << endl;
                cout << "|Cautarea unor date in fisier-------2|" << endl;
                cout << "|____________________________________|" << endl;

                alegere = getch();

            switch(alegere)
            {
            case '1': cout << " ____________________________________" << endl;
                      cout << "|Filtrarea datelor dupa pret--------1|" << endl;
                      cout << "|Filtrarea datelor dupa ani---------2|" << endl;
                      cout << "|____________________________________|" << endl;

                    alegere = getch();

                      switch(alegere)
                      {
                          case '1': filtrupret(mod, nr);
                           break;
                          case '2': filtruan(mod, nr);
                           break;
                      }
                break;


            case '2': cout << " ________________________________________________" << endl;
                      cout << "|Cautarea dupa pretul tabloului-----------------1|" << endl;
                      cout << "|Cautarea dupa anul finisarii-------------------2|" << endl;
                      cout << "|Cautarea dupa patria pictorului----------------3|" << endl;
                      cout << "|Cautarea dupa numele pictorului----------------4|" << endl;
                      cout << "|________________________________________________|" << endl;

                      alegere = getch();

                    switch(alegere)
                    {
                        case '1': cautarepret(mod, nr);
                         break;
                        case '2': cautarean(mod, nr);
                         break;
                        case '3': cautarepatrie(mod, nr);
                         break;
                        case '4': cautarenume(mod, nr);
                         break;
                    }

                    break;
            }
      }

      break;

    case '4':
      cout << " __________________________________________ " << endl;
      cout << "|Alegeti cum doriti sa sortati elementele: |" << endl;
      cout << "|Dupa numele autorului--------------------1|" << endl;
      cout << "|Dupa anul finisarii lucrarii-------------2|" << endl;
      cout << "|Dupa pretul tabloului--------------------3|" << endl;
      cout << "|Dupa patria autorului--------------------4|" << endl;
      cout << "|__________________________________________|" << endl;
      cout << endl;

      alegere = getch();

      switch (alegere) {
      case '1':
        cout << " ___________________________________________________ " << endl;
        cout << "|Ati ales sortarea dupa nume, cum doriti sa sortati:|" << endl;
        cout << "|Sortati crescator---------------------------------1|" << endl;
        cout << "|Sortati descrescator------------------------------2|" << endl;
        cout << "|___________________________________________________|" << endl;
        cout << endl;
        alegere = getch();

        switch (alegere) {
        case '1':sortcresnume(mod, nr, "nume");
          break;
        case '2':sortdescresnume(mod, nr, "nume");
          break;
        }

        break;

      case '2':
        cout << " ___________________________________________________ " << endl;
        cout << "|Ati ales sortarea dupa an, cum doriti sa sortati:  |" << endl;
        cout << "|Sortati crescator---------------------------------1|" << endl;
        cout << "|Sortati descrescator------------------------------2|" << endl;
        cout << "|___________________________________________________|" << endl;
        cout << endl;
        alegere = getch();

        switch (alegere) {
        case '1':sortarean1(mod, nr);
          break;
        case '2':sortarean2(mod, nr);
          break;
        }

        break;

      case '3':
        cout << " ___________________________________________________ " << endl;
        cout << "|Ati ales sortarea dupa pret, cum doriti sa sortati:|" << endl;
        cout << "|Sortati crescator---------------------------------1|" << endl;
        cout << "|Sortati descrescator------------------------------2|" << endl;
        cout << "|___________________________________________________|" << endl;
        cout << endl;

        alegere = getch();

        switch (alegere) {
        case '1':sortarepret1(mod, nr);
          break;
        case '2':sortarepret2(mod, nr);
          break;
        }

        break;

      case '4':
        cout << " ______________________________________________________ " << endl;
        cout << "|Ati ales sortarea dupa patrie, cum doriti sa sortati: |" << endl;
        cout << "|Sortati crescator------------------------------------1|" << endl;
        cout << "|Sortati descrescator---------------------------------2|" << endl;
        cout << "|______________________________________________________|" << endl;
        cout << endl;

        alegere = getch();

        switch (alegere) {
        case '1':sortarepatria1(mod, nr, "nume");
          break;
        case '2':sortarepatria2(mod, nr, "nume");
          break;
        }

        break;
      }
      break;

    case '5':
      cout << " ________________________________________________________" << endl;
      cout << "|Determinarea valorilor extremale dintr-o multime-------1|" << endl;
      cout << "|Determinarea valorii medii a unui sir------------------2|" << endl;
      cout << "|Afisarea continutului unui fiser textual---------------3|" << endl;
      cout << "|________________________________________________________|" << endl;
      cout << endl;

      alegere = getch();

      switch (alegere) {
      case '1':
        cout << " ____________________________" << endl;
        cout << "|Dupa vechime:               |" << endl;
        cout << "|Cea mai veche opera--------1|" << endl;
        cout << "|Cea mai tanara opera-------2|" << endl;
        cout << "|Dupa pret:                  |" << endl;
        cout << "|Cea mai scumpa opera-------3|" << endl;
        cout << "|Cea mai ieftina opera------4|" << endl;
        cout << "|____________________________|" << endl;
        cout << endl;

        alegere = getch();

        switch (alegere) {
        case '1':veche(mod, nr);
          break;
        case '2':tanara(mod, nr);
          break;
        case '3':scumpa(mod, nr);
          break;
        case '4':ieftina(mod, nr);
          break;

        }

        break;

      case '2':
        cout << " ______________________________________________________ " << endl;
        cout << "|Pretul mediu al tablourilor expuse la expozitie------1|" << endl;
        cout << "|Varsta medie a tablourilor expuse la expozitie-------2|" << endl;
        cout << "|______________________________________________________|" << endl;
        cout << endl;

        alegere = getch();

        switch (alegere) {
        case '1':mediupret(mod, nr);
          break;
        case '2':anmediu(mod, nr);
          break;
        }

        break;

      case '3':afisare(mod, nr);
        break;

      }
      break;

    case '6':fisier(mod, nr);
      break;
    }

  } while (alegere != '0');

  return 0;
}
