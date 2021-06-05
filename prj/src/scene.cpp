/*!
 * \file
 * \brief plik źródłowy
 * 
 * Plik zawiera wszystkie metody klasy Scene
 */
#include "scene.hh"

 /*! 
* Konstruktor bezparametryczny klasy Scene. 
* \param[in]  - brak,                
* Ustawia zakresy rysowania, tworzy płaszczyznę,
* losuje pozycje dla dronów i je roztawia   
*/
Scene::Scene(){

Lacze.ZmienTrybRys(PzG::TR_3D);

Lacze.UstawZakresX(-400, 400);
Lacze.UstawZakresY(-400, 400);
Lacze.UstawZakresZ(-400, 400);

double tab1[3]={800,800,0};
Vector3D dimground(tab1);
ground=new Surface(dimground,30);
Lacze.DodajNazwePliku(ground->getname().c_str(),PzG::RR_Ciagly, 2);
ground->save();
for (int i=0; i<NR; ++i){
double position[3]{(double)(rand()%510-200),(double)(rand()%510-200),30};
tab[i]=new Drone (i,Lacze,Vector3D(position));
tab[i]->save();
}
Lacze.Rysuj(); 
}

 /*! 
* Metoda draw     
* \param[in]  - brak,                                                 
* Rysuje w gnuplocie     
*/
void Scene::draw(){

Lacze.Rysuj();

}

 /*! 
* Metoda interface     
* \param[in]  - brak,                                                 
* odpowiedzialna za kontakt z użytkownikiem,
* posiada całe menu użytkownika    
*/
void Scene::interface(){

Vector3D vec;

std::cout<<"Program dragonfly - faza 1"<<std::endl<<std::endl;
std::cout<<"a - wybierz aktywnego drona"<<std::endl;
std::cout<<"p - zadaj parametry przelotu"<<std::endl;
std::cout<<"m - wyswietl menu"<<std::endl<<std::endl;
std::cout<<"k - koniec dzialania programu"<<std::endl<<std::endl;

    char action;
    int r=0;
    do {
    
    std::cout<<"Twoj wybor (m - menu):";
    std::cin>>action;
    switch (action){

        case 'a':
        std::cout<<"Wybor aktywnego drona"<<std::endl<<std::endl;
        std::cout<<"0 - pierwszy dron"<<std::endl;
        std::cout<<"1 - drugi dron"<<std::endl<<std::endl;

        std::cout<<"Wprowadz numer drona:";
        std::cin>>r;
            if(r<NR) {
                ;
            }
            else{
                std::cerr<<"brak drona o podanym numerze."<<std::endl;
                r=0;
            }
        break;

        case 'p':
        tab[r]->manipulate();
        break;

        case 'm':
        std::cout<<"a - wybierz aktywnego drona"<<std::endl;
        std::cout<<"p - zadaj parametry przelotu"<<std::endl;
        std::cout<<"m - wyswietl menu"<<std::endl<<std::endl;
        std::cout<<"k - koniec dzialania programu"<<std::endl<<std::endl;
        break;

        case 'k':
        std::cout<<"koniec działania programu"<<std::endl;
        break;

        default:
        break;
    }
    draw();
    std::cout<<std::endl;
  vec.vecamount(std::cout);
  std::cout<<std::endl;
    } while (action!='k');
}
 /*! 
* Destruktor bezparametryczny klasy Scene.      
* \param[in]  - brak,                                                 
* niszczy nieużywną już, dynamicznie alokowaną pamięć     
*/
Scene::~Scene()
 {
free (ground);
for(int i=0; i<NR; i++)
free (tab[i]);
 }