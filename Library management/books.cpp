#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <typeinfo>
#include <iomanip>
#include "books.h"





using namespace std;

static string const nomFichier("./data/books.txt");

int num_book(){
    ifstream fichier(nomFichier.c_str());
    int nb_books=0;
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
         nb_books++;
      }
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }
   return nb_books;
}

void addBook(){

    ofstream monFlux(nomFichier.c_str(),ios::app);
    string line_temp[7]={};
    string label_book[7]={"code","author","title","stock","price","year","category"};
    string line_book="";
    line_temp[0]=to_string(num_book());
    for(int i=1;i<=6;i++){

         if(i==3){
            stock_veri:
            cout<<"type the "<<label_book[i]<<endl;
            cin>>line_temp[i];
            string j= line_temp[i];
            if((is_number(j))==false){
                cout<<"a number is needed";
                goto stock_veri;
                 //do;
            /*
                while((is_number(j))==false);//{
                cout<<"enter an integer stock"<<endl;
                cin>>line_temp[i];
            //}
            
            */
            }
           
        }
        
        else if(i==4){
            cout<<"type the "<<label_book[i]<<endl;
            cin>>line_temp[i];
            if((stof(line_temp[i])<100.0 || stof(line_temp[i])>50000.0)){
                 //do;
            while(cout<<"enter a new price, price is between 100 and 50000"<<endl,cin>>line_temp[i],(stof(line_temp[i])<100.0 || stof(line_temp[i])>50000.0));//{
                //cout<<"enter a new price, price is between 100 and 50000"<<endl;
                 //cin>>line_temp[i];
            //}
            }
           
        }
        else if(i==5){
            cout<<"type the "<<label_book[i]<<endl;
            cin>>line_temp[i];
            if((stoi(line_temp[i])<2000)){
                while(stoi(line_temp[i])<2000){
                cout<<"enter a year more than 2000"<<endl;
                 cin>>line_temp[i];
                }
            }
            
        }
        else if(i==6){
            cate_verif:
            cout<<"type the "<<label_book[i]<<endl;
            cin>>line_temp[i];
            string j=line_temp[i];
            int verif=0;
            string val_enum[3]={"fantasy","horror","comedy"};
            for(int k=0;k<=2;k++){
                if(j==val_enum[k]){
                    verif=1;
                    break;
                }
            }
            if(!verif){
                goto cate_verif;
                    /*while(!verif){
                        cout<<"choose a valid category"<<endl;
                        cin>>line_temp[i];
             }*/
                
                //cout<<"reconnu"<<j<<" " << typeid(j).name() <<endl;
            }
            
        }
        else{
            cout<<"type the "<<label_book[i]<<endl;
            cin>>line_temp[i];
        }
        

    }
    
    cout<<endl;
    for(int i=0;i<=6;i++){
        i!=6?line_book+=line_temp[i]+"#":line_book+=line_temp[i];
        //cout<<line_temp[i]<<" #"<<i<<endl;
    }
    

    if(monFlux)    
    {
        monFlux << line_book << endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }


    cout<<"(1) new book added \U0001F600 \a"<<endl;



}
void line_Book(string s){

    ofstream monFlux(nomFichier.c_str());

    
    if(monFlux)    
    {
        monFlux<<s<<endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

    cout<<"(1)  book updated \U0001F600 \a"<<endl;



}
string string_Book(int s){

    
    string line_temp[7]={};
    string label_book[7]={"code","author","title","stock","price","year","category"};
    string line_book="";
    line_temp[0]=to_string(s);
    for(int i=1;i<=6;i++){

         if(i==3){
            stock_veri:
            cout<<"type the "<<label_book[i]<<endl;
            cin>>line_temp[i];
            string j= line_temp[i];
            if((is_number(j))==false){
                cout<<"a number is needed";
                goto stock_veri;
                
            }
           
        }
        
        else if(i==4){
            cout<<"type the "<<label_book[i]<<endl;
            cin>>line_temp[i];
            if((stof(line_temp[i])<100.0 || stof(line_temp[i])>50000.0)){
                 //do;
            while(cout<<"enter a new price, price is between 100 and 50000"<<endl,cin>>line_temp[i],(stof(line_temp[i])<100.0 || stof(line_temp[i])>50000.0));//{
                //cout<<"enter a new price, price is between 100 and 50000"<<endl;
                 //cin>>line_temp[i];
            //}
            }
           
        }
        else if(i==5){
            cout<<"type the "<<label_book[i]<<endl;
            cin>>line_temp[i];
            if((stoi(line_temp[i])<2000)){
                while(stoi(line_temp[i])<2000){
                cout<<"enter a year more than 2000"<<endl;
                 cin>>line_temp[i];
                }
            }
            
        }
        else if(i==6){
            cate_verif:
            cout<<"type the "<<label_book[i]<<endl;
            cin>>line_temp[i];
            string j=line_temp[i];
            int verif=0;
            string val_enum[3]={"fantasy","horror","comedy"};
            for(int k=0;k<=2;k++){
                if(j==val_enum[k]){
                    verif=1;
                    break;
                }
            }
            if(!verif){
                goto cate_verif;
                    
            }
            
        }
        else{
            cout<<"type the "<<label_book[i]<<endl;
            cin>>line_temp[i];
        }
        

    }
    
    cout<<endl;
    for(int i=0;i<=6;i++){
        i!=6?line_book+=line_temp[i]+"#":line_book+=line_temp[i];
        //cout<<line_temp[i]<<" #"<<i<<endl;
    }
    


    //cout<<line_book<<endl;
    return line_book;


}

void showBook(){
    ifstream fichier(nomFichier.c_str());
    
    //cout <<left;
    cout <<setw(10) << "Code|" << setw(10) << "Author|" << setw(10) << "Title|"<< setw(10) << "Stock|" 
    << setw(10) << "Price|"<< setw(10) << "Year|"<< setw(10) << "Category|"<< '\n' <<endl;
    if(fichier){
      //L'ouverture s'est bien passée, on peut donc lire

      string ligne; //Une variable pour stocker les lignes lues

      while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
      {
         //cout << ligne << endl;
         string delimiter="#";
         vector <string> bk_prt = split_book(ligne,delimiter);
         //cout << left;
         cout <<setw(10)<< bk_prt[0]+"|"<<setw(10) << bk_prt[1]+"|" <<setw(10)<< bk_prt[2]+"|"<<setw(10)<< bk_prt[3]+"|"
         <<setw(10)<< bk_prt[4]+"|"<<setw(10)<< bk_prt[5]+"|"<<setw(10)<< bk_prt[6]+"|"<<"\U0001F4D6"<< '\n' <<endl;
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


vector<string> split_book(string s, string delimiter) {
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



void updateBook(){
    int command;
    cout<<"enter the code of the book you want to modify"<<endl;
    cin>> command;

    int cnt = num_book();
    int compt=0;
    string new_bk;
    string nw_line="";
    string bk_prt ="";

    if(command > cnt-1){
        cout<<"the identifier is not recognized";
    }else{
        new_bk = string_Book(command);
        ifstream fichier(nomFichier.c_str());
    
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
        
        line_Book(bk_prt);
    }

     

}


void deleteBook(){
    int command;
    cout<<"enter the code of the book you want to delete"<<endl;
    cin>> command;

    int cnt = num_book();
    int compt=0;
    string new_bk;
    string nw_line="";
    string bk_prt ="";

    if(command > cnt-1){
        cout<<"the identifier is not recognized";
    }else{
        //new_bk = string_Book(command);
        ifstream fichier(nomFichier.c_str());
    
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
        
        line_Book(bk_prt);
    }

     

}
/*
void sortAuthor(){

    ifstream fichier(nomFichier.c_str());
    
    //cout <<left;
    vector <Book> vsa_bk={};
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
         Book temp;
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


bool is_number(string s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

