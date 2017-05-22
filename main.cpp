/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: laure
 *
 * Created on 17 mai 2017, 17:09
 */

#include <cstdlib>
#include<iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Sistema.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    

    double teta =17.0;
    double omega = -85.0;
    
    double resultat;
    
    double x[2] = {teta,omega};
    
    Sistema *Sistema_pendulo;
    
    Sistema_pendulo = new Sistema();

    Sistema_pendulo->funcion_pertenencia(x);
    Sistema_pendulo->funcion_inferencia();
    Sistema_pendulo->funcion_borrosificacion();
    resultat=Sistema_pendulo->funcion_deborrosificacion();
    
    
    cout <<resultat<<endl;

    return 0;
}

