#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <typeinfo>
#include <iomanip>
#include "clients.h"





using namespace std;

static string const nomFichier_client("./data/clients.txt");

int num_client(){
    ifstream fichier(nomFichier_client.c_str());
    int nb_clients=0;
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
         nb_clients++;
      }
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }
   return nb_clients;
}

void addClient(){

    ofstream monFlux(nomFichier_client.c_str(),ios::app);
    string line_temp[4]={};
    string label_client[4]={"code","name","age","salaire"};
    string line_client="";
    line_temp[0]=to_string(num_client());
    for(int i=1;i<=3;i++){

         if(i==3){
            cout<<"type the "<<label_client[i]<<endl;
            cin>>line_temp[i];
            if((stof(line_temp[i])<20000.0 || stof(line_temp[i])>500000.0)){
                 //do;
            while(cout<<"enter a new price, salary is between 20000 and 500000"<<endl,cin>>line_temp[i],(stof(line_temp[i])<20000.0 || stof(line_temp[i])>500000.0));//{
                //cout<<"enter a new price, price is between 100 and 50000"<<endl;
                 //cin>>line_temp[i];
            //}
            }
           
        }
        else if(i==2){
            cout<<"type the "<<label_client[i]<<endl;
            cin>>line_temp[i];
            if((stoi(line_temp[i])<0)){
                while(stoi(line_temp[i])<0){
                cout<<"enter an age more than 0"<<endl;
                 cin>>line_temp[i];
                }
            }
            
        }
        else{
            cout<<"type the "<<label_client[i]<<endl;
            cin>>line_temp[i];
        }
        

    }
    
    cout<<endl;
    for(int i=0;i<=3;i++){
        i!=3?line_client+=line_temp[i]+"#":line_client+=line_temp[i];
        //cout<<line_temp[i]<<" #"<<i<<endl;
    }
    

    if(monFlux)    
    {
        monFlux << line_client << endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }


    cout<<"(1) new client added \U0001F600 \a"<<endl;



}
void line_Client(string s){

    ofstream monFlux(nomFichier_client.c_str());

    
    if(monFlux)    
    {
        monFlux<<s<<endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

    cout<<"(1)  client updated \U0001F600 \a"<<endl;



}
string string_Client(int s){

    
    string line_temp[4]={};
    string label_client[4]={"code","name","age","salaire"};
    string line_client="";
    line_temp[0]=to_string(s);
    for(int i=1;i<=3;i++){

         if(i==3){
            cout<<"type the "<<label_client[i]<<endl;
            cin>>line_temp[i];
            if((stof(line_temp[i])<20000.0 || stof(line_temp[i])>500000.0)){
                 //do;
            while(cout<<"enter a new price, salary is between 20000 and 500000"<<endl,cin>>line_temp[i],(stof(line_temp[i])<20000.0 || stof(line_temp[i])>500000.0));//{
                //cout<<"enter a new price, price is between 100 and 50000"<<endl;
                 //cin>>line_temp[i];
            //}
            }
           
        }
        else if(i==2){
            cout<<"type the "<<label_client[i]<<endl;
            cin>>line_temp[i];
            if((stoi(line_temp[i])<0)){
                while(stoi(line_temp[i])<0){
                cout<<"enter an age more than 0"<<endl;
                 cin>>line_temp[i];
                }
            }
            
        }
        else{
            cout<<"type the "<<label_client[i]<<endl;
            cin>>line_temp[i];
        }
        

    }
    
    cout<<endl;
    for(int i=0;i<=3;i++){
        i!=3?line_client+=line_temp[i]+"#":line_client+=line_temp[i];
        //cout<<line_temp[i]<<" #"<<i<<endl;
    }
    


    //cout<<line_client<<endl;
    return line_client;


}

void showClient(){
    ifstream fichier(nomFichier_client.c_str());
    
    //cout <<left;
    cout <<setw(10) << "Code|" << setw(10) << "Name|" << setw(10) << "Age|"<< setw(10) << "Salary|"<< '\n' <<endl;
    if(fichier){
      //L'ouverture s'est bien passée, on peut donc lire

      string ligne; //Une variable pour stocker les lignes lues

      while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
      {
         //cout << ligne << endl;
         string delimiter="#";
         vector <string> bk_prt = split_client(ligne,delimiter);
         //cout << left;
         cout <<setw(10)<< bk_prt[0]+"|"<<setw(10) << bk_prt[1]+"|" <<setw(10)<< bk_prt[2]+"|"<<setw(10)<< bk_prt[3]+"|"
        <<"\U0001F9D1"<< '\n' <<endl;
         //Et on l'affiche dans la console
         //Ou alors on fait quelque chose avec cette ligne
         //À vous de voir
      }
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }
}

vector<string> split_client(string s, string delimiter) {
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




void updateClient(){
    int command;
    cout<<"enter the code of the client you want to modify"<<endl;
    cin>> command;

    int cnt = num_client();
    int compt=0;
    string new_bk;
    string nw_line="";
    string bk_prt ="";

    if(command > cnt-1){
        cout<<"the identifier is not recognized";
    }else{
        new_bk = string_Client(command);
        ifstream fichier(nomFichier_client.c_str());
    
    //cout <<left;
    if(fichier){
      //L'ouverture s'est bien passée, on peut donc lire

      string ligne; //Une variable pour stocker les lignes lues

      while(getline(fichier, ligne) ) //Tant qu'on n'est pas à la fin, on lit
      {
         if(compt==command){
            bk_prt+=new_bk+"\n";
            compt++;
         }else{
            bk_prt+=ligne+"\n";
            compt++;
        }
         
         
         
      }
   }
   else
   {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   } 
        
        line_Client(bk_prt);
    }

     

}


void deleteClient(){
    int command;
    cout<<"enter the code of the client you want to delete"<<endl;
    cin>> command;

    int cnt = num_client();
    int compt=0;
    string new_bk;
    string nw_line="";
    string bk_prt ="";

    if(command > cnt-1){
        cout<<"the identifier is not recognized";
    }else{
        //new_bk = string_Client(command);
        ifstream fichier(nomFichier_client.c_str());
    
    //cout <<left;
    if(fichier){
      //L'ouverture s'est bien passée, on peut donc lire

      string ligne; //Une variable pour stocker les lignes lues

      while(getline(fichier, ligne) ) //Tant qu'on n'est pas à la fin, on lit
      {
         if(compt==command){
            //bk_prt+=new_bk+"\n";  just the part i comment to make the delete
            compt++;
         }else{
            bk_prt+=ligne+"\n";
            compt++;
        }
         
         
         
      }
   }
   else
   {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   } 
        
        line_Client(bk_prt);
    }

     

}
/*
void sortAuthor(){

    ifstream fichier(nomFichier.c_str());
    
    //cout <<left;
    vector <Client> vsa_bk={};
    cout <<setw(10) << "Code|" << setw(10) << "Author|" << setw(10) << "Title|"<< setw(10) << "Stock|" 
    << setw(10) << "Price|"<< setw(10) << "Year|"<< setw(10) << "Category|"<< '\n' <<endl;
    if(fichier){
      //L'ouverture s'est bien passée, on peut donc lire

      string ligne; //Une variable pour stocker les lignes lues

      while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
      {
         //cout << ligne << endl;
         string delimiter="#";
         vector <string> bk_prt = split(ligne,delimiter);
         Client temp;
         temp.code=stoi(bk_prt[0]);
         temp.author=bk_prt[1];
         temp.title=bk_prt[2];
         temp.stock=stoi(bk_prt[3]);
         temp.price=stof(bk_prt[4]);
         temp.year=stoi(bk_prt[5]);
         temp.category=fantasy;


        vsa_bk.push_back(temp);

         
      }
   }
   else{
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    //cout<<vsa_bk.size()<<endl;
}

    Category getCategoryFromString(string sv)
{
    if (sv == "fantasy")   return fantasy;
    if (sv == "horror")   return horror;
    if (sv == "comedy")   return comedy;

    return {};
}
*/

/*
    bool is_number(string s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}
*/
