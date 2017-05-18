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
using namespace std;


// Conjuntos
#define NG "NG"
#define NP "NP"
#define Z "Z"
#define PP "PP"
#define NP "NP"



class Sistema {
public:
    Sistema();
    Sistema(const Sistema& orig);
    virtual ~Sistema();
    vector<pair<string, double> > funcion_pertenencia(double u); // (O de inclusion) Triangular / u puede ser teta o omega
    void funcion_borrosificacion(); // TIPO SINGLETON
    double funcion_inferencia(double u_teta,double u_omega); // regla del minimo
    void funcion_deborrosificacion();// MEDIA DE CENTROS
    void funcion_fam(string teta, string omega) ;
private:
    string _fuerza;
    

};

#endif /* SISTEMA_H */

