#pragma once

/*!
 * \file
 * \brief Definicja klasy Drone
 * 
 * Plik zawiera definicję klasy Drone
 */

#include "cuboid.hh"
#include "matrix3x3.hh"
#include "prism.hh"
#include <unistd.h>
#include "../inc/lacze_do_gnuplota.hh"


/*!
 * Drone zawiera: kąt, id, odległość do przebycia, macierz rotacji
 * oryginalne rotory, ich kopie, oryginalny kadłub, jego kopię,
 *łącze do gnu plota i rysowaną scieżkę.
 */
class Drone {

    int id;
    double angle;
    std::vector <Vector3D> pathr;
    PzG::LaczeDoGNUPlota  &Lacze;
    Cuboid org;
    Cuboid cpy;
    Prism orgw[4];
    Prism cpyw[4];
    Matrix3x3 rot;
    Vector3D path;
    

    public:

/*! 
* Konstruktor parametryczny klasy Surface
*/
    Drone(int id,PzG::LaczeDoGNUPlota  &Lacze, Vector3D position);
/*! 
* Metoda odpowiedzialna za zapis 
*/
    void save();
/*! 
* Metoda odpowiedzialna za sterowanie dronem
*/
    void manipulate();
/*! 
* Metoda odpowiedzialna za przesunięcie drona
*/
    void move(double path);
/*! 
* Metoda odpowiedzialna za obrót drona
*/
    void rotate(double angle);
/*! 
* Metoda odpowiedzialna za obrót rotorów
*/
    void rotatew();
/*! 
* Metoda odpowiedzialna za lot pionowy drona
*/
    void verticalmove(double path);
/*! 
* Metoda odpowiedzialna za wyznaczenie ścieżki drona
*/
    void calculatepath(double path, double angle1);

};