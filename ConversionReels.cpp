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
    
    int base, resteEntier, precision, negatif = 0, nbIteration = 0;
    string resultatEntier, resultatDecimal, resultat;
    
    cout << "Entrez un nombre reel : " ;
    cin >> nbReelChoisi;

    if (nbReelChoisi < 0) 
    {
        nbReelChoisi = -nbReelChoisi;
        negatif = 1;
    }
    
    quotientIntermediaire = partieEntiereNb = (long long)nbReelChoisi;
    produitIntermediaire = partieDecimaleNb = nbReelChoisi - (long long)nbReelChoisi;
            
    cout << endl << "Entrez une base (de 2 a 36) : ";
    cin >> base;
    
    cout << endl << "Entrez une precision : ";
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
        resteReel = int(produit);
        produitIntermediaire = produit - int(produit);
        resultatDecimal += alphanum[resteReel];   
        ++nbIteration;
    }
    while(nbIteration < precision);
    
    if(!precision)
    {
        resultat = resultatEntier;
    }
    else
    {
        resultat = resultatEntier + "." + resultatDecimal;
    }
    
    cout << endl << (negatif? "-" :"") << nbReelChoisi << " en base " 
         << base << " s'ecrit : " << (negatif ? "-" :"") << resultat 
         << " avec " << precision << " chiffre" << (precision >= 1 ? "s" : "") 
         << " apres la virgule" << endl;

   return 0;
}
