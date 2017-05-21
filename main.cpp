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
    
    vector<pair<string, double> > alphaParaCadaRegla;
    double teta =10.0;
    double omega = -5.0;
    
    double x[2] = {teta,omega};
    
    Sistema *Sistema_pendulo;
    
    Sistema_pendulo = new Sistema();

    Sistema_pendulo->funcion_pertenencia(x);
    alphaParaCadaRegla = Sistema_pendulo->funcion_inferencia();
    
    for(int i=0;i<alphaParaCadaRegla.size();i++){
        cout<<"Regla"<<i<<" : "<<alphaParaCadaRegla[i].first<< " alpha "<< i << " = " << alphaParaCadaRegla[i].second <<endl;
    }
    

    return 0;
}

