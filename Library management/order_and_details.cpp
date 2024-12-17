#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <typeinfo>
#include <iomanip>
#include "order_and_details.h"

using namespace std;

static string const nomFichier_orders("./data/oders.txt");
static string const nomFichier_details("./data/order_details.txt");
static string const nomFichier_2("./data/books.txt");



void save_detail(){
    string ln_details="";
    string ln_orders="";
    int nb_order=num_orders();
    int nb_detail=0;
    int prix_bk=0;
    int prix_total=0;
    int prix_tot_or=0;

    ofstream monFlux_orders(nomFichier_orders.c_str(),ios::app);
    ofstream monFlux_details(nomFichier_details.c_str(),ios::app);


    sv_dtl:
    cout<<"enter the reference of the book you want to buy"<<endl;
    int ref_bk;
    cin>>ref_bk;
    prix_bk=getPriceBook(ref_bk);
    cout<<"enter the quantity"<<endl;
    int qty;
    cin>>qty;
    prix_total=qty*prix_bk;
    prix_tot_or+=prix_total;
    ln_details+=to_string(ref_bk)+"@"+to_string(qty)+"@"+to_string(prix_total);
    cout<<"would you want to add a new book? y/n"<<endl;
    char ch;
    cin >>ch;
    if(ch=='y'){goto sv_dtl; nb_detail++;}else{}

    cout<<"enter the reference of the client";
    int ref_client;
    cin>>ref_client;

    ln_orders=to_string(nb_order)+"#"+to_string(ref_client)+"#"+ln_details+"#"+to_string(nb_detail)+"#"+to_string(prix_tot_or);

   if(monFlux_orders)    
    {
        monFlux_orders << ln_orders << endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier. 1" << endl;
    }
    if(monFlux_details)    
    {
        monFlux_details << ln_details << endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier.2" << endl;
    }
    

}

int num_orders(){
    ifstream fichier(nomFichier_orders.c_str());
    int nb_orders=0;
    if(fichier)
   {
      //L'ouverture s'est bien passée, on peut donc lire

      string ligne; //Une variable pour stocker les lignes lues
      

      while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
      {
         //cout << ligne << endl;
         //Et on l'affiche dans la console
         //Ou alors on fait quelque chose avec cette ligne
         //À vous de voir
         nb_orders++;
      }
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture.3" << endl;
   }
   return nb_orders;
}

int getPriceBook(int s){
    ifstream fichier(nomFichier_2.c_str());
    int final=0;
 

    if(fichier){
      //L'ouverture s'est bien passée, on peut donc lire

      string ligne; //Une variable pour stocker les lignes lues
      int j=0;
      
      

      while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
      {
         //cout << ligne << endl;
         string delimiter="#";
         vector <string> bk_prt = split_book_2(ligne,delimiter);
         //cout << left;
         if(j==s+1){
            final=stoi(bk_prt[4]);
            break;
         }
         else{

         }
         
         j++;
      }
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture.4" << endl;
   }
   return final;
}

vector<string> split_book_2(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}