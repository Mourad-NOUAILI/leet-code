#include<bits/stdc++.h>

void read_file(std::fstream f){
    std::string line;
    while (std::getline(f,line)){
        std::cout<<line<<'\n';
    }
    f.close();
}


int main(){
    // Creation du nom logique
    std::fstream my_file("test.txt");

    // Test de l'existance du fichier
    if(!my_file){
        std::cout<<"File does not exist\n";
        return 0;
    }

    // écriture 
    my_file<<"ok1\nok2\n";
    my_file.close();

    // Re-ouverture du fichier en lecture
    my_file.open("test.txt",std::ios::in);
    read_file(my_file);
    
    return 0;
}