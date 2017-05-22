/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sistema.h
 * Author: laure
 *
 * Created on 17 mai 2017, 17:39
 */

#ifndef SISTEMA_H
#define SISTEMA_H

#include <cstdlib>
#include<iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Sistema.h"
#include <vector>
#include <math.h>

#define centro1 -62.5
#define centro2 -25
#define centro3 0
#define centro4 25
#define centro5 62.5

using namespace std;



class Sistema {
public:
    Sistema();
    Sistema(const Sistema& orig);
    virtual ~Sistema();
    void funcion_pertenencia(double x[]); // (O de inclusion) Triangular 
    void funcion_borrosificacion(); // TIPO SINGLETON
    void funcion_inferencia(); // regla del minimo
    double funcion_deborrosificacion();// MEDIA DE CENTROS
    double funcion_fam(string teta_omega) ;//lista de las reglas
    
    
    
    vector<pair<string, double> > getInclusionTeta(void);
    vector<pair<string, double> > getInclusionOmega(void);
    void setInclusionOmega(vector<pair<string, double> >);
    void setInclusionTeta(vector<pair<string, double> >);
    vector<pair<string, double> > getAlphaParaCadaRegla(void);
    void setAlphaParaCadaRegla(vector<pair<string, double> >);
    
private:
    string _fuerza;
    vector<pair<double, double> > centro_Y_alpha;
    vector<pair<string, double> > inclusionTeta;
    vector<pair<string, double> > inclusionOmega;
    vector<pair<string, double> > alphaParaCadaRegla; // REGLE, alpha
};

#endif /* SISTEMA_H */

