/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire2.2 - Convertisseur avec les réels
 Fichier     : main.cpp
 Auteur(s)   : Sébastien Saez et Adam Zouari
 Date        : 12 octobre 2016

 But         : Le but de ce laboratoire est de mettre en oeuvre un programme 
 *             permettant d'afficher des nombres réels dans la base 
 *             de notre choix (entre 2 et 36)

 Remarque(s) : On doit spécifier la précision pour ne pas tomber dans une boucle 
 *             infinie pour les cas particuliers.

 Compilateur : g++ (GCC) 6.2.1 
 -----------------------------------------------------------------------------------
 */
#include <iostream>
#include <cstdlib>

using namespace std;

const string alphanum = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

int main()
{   
    long long int nbEntierChoisi, quotientEntier, quotientIntermediaire;
    int base, reste, precision;
    int nbIteration = 0;
    string resultat;
    
    cout << "Entrez un nombre réel" << endl;
    cin >> nbEntierChoisi;
    
    quotientIntermediaire = nbEntierChoisi;
    
    cout << "Entrez une base" << endl;
    cin >> base;
    
    cout << "Entrez une precision" << endl;
    cin >> precision;
    
    // pour la partie entière
    do
    {
    quotientEntier = quotientIntermediaire / base;
    reste = quotientIntermediaire % base;
    quotientIntermediaire = quotientEntier;
    resultat = alphanum[reste] + resultat;
    
    }
    while(quotientEntier);
    
    // pour la partie fractionnaire
    do
    {
       
    }
    while(nbIteration < precision);
    
    cout << endl << nbEntierChoisi << " en base " 
         << base << " s'ecrit " << resultat << endl;

   return EXIT_SUCCESS;
}
