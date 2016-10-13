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
#include <string>

using namespace std;

const string alphanum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{   
    long double nbReelChoisi, partieEntiereNb, 
                produitIntermediaire, partieDecimaleNb, produit, resteReel;
    
    long long int quotient, quotientIntermediaire;
    
    int base, resteEntier, precision;
    int nbIteration = 0;
    string resultatEntier, resultatDecimal, resultat;
    
    cout << "Entrez un nombre réel" << endl;
    cin >> nbReelChoisi;
    
    quotientIntermediaire = partieEntiereNb = (long long)nbReelChoisi;
    produitIntermediaire = partieDecimaleNb = nbReelChoisi - (long long)nbReelChoisi;
            
    cout << "Entrez une base" << endl;
    cin >> base;
    
    cout << "Entrez une precision" << endl;
    cin >> precision;
    
    // pour la partie entière
    do
    {
    quotient = quotientIntermediaire / base;
    resteEntier = quotientIntermediaire % base;
    quotientIntermediaire = quotient;
    resultatEntier = alphanum[resteEntier] + resultatEntier;
    
    }
    while(quotient);
    
    // pour la partie fractionnaire
    do
    {
        produit = produitIntermediaire * base;
        resteReel = (int)produit;
        produitIntermediaire = produit - int(produit);
        resultatDecimal = resultatDecimal + alphanum[resteReel];   
        ++nbIteration;
    }
    while(nbIteration < precision);
    
    resultat = resultatEntier + "." + resultatDecimal;
            
    /*
    function fdec2NewBase(decimalNumber){
     *  var i=0;
     *  var id=0;
     *  var convertedNumber = "";
     *  while(decimalNumber !=0 & i<=Precision) {
     *  decimalNumber *=Base;
     *  id = Math.floor(d);
     *  convertedNumber = convertedNumber+Digits.substr(id&(Base-1),1);
     * i++; }
     * return convertedNumber;
        }
     */
    
    
    
    
    cout << endl << nbReelChoisi << " en base " 
         << base << " s'ecrit " << resultat << endl;

   return EXIT_SUCCESS;
}
