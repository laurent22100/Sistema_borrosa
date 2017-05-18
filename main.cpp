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
    
    double teta =10.0;
    double omega = -5.0;
    
    Sistema *Sistema_pendulo;
    
    Sistema_pendulo = new Sistema();

    vector<pair<string, double> > inclusionTeta;
    vector<pair<string, double> > inclusionOmega;
    
    Sistema_pendulo->funcion_pertenencia("teta",10);
    Sistema_pendulo->funcion_pertenencia("omega",-5);
    
    vector<pair<string, double> > alphaParaCadaRegla;
    
    alphaParaCadaRegla = Sistema_pendulo->funcion_inferencia();
    for(int i=0;i<alphaParaCadaRegla.size();i++){
        cout<<"Regla : "<<alphaParaCadaRegla[i].first<< " alpha "<< i << " = " << alphaParaCadaRegla[i].second <<endl;
    }
    

    return 0;
}

