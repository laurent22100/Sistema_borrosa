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

#include <string>
using namespace std;
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
    void funcion_pertenencia();
    void funcion_borrosificacion(); // TIPO SINGLETON
    void funcion_deborrosificacion();// MEDIA DE CENTROS
    void funcion_fam(string teta, string omega) ;
private:
    string _fuerza;
    

};

#endif /* SISTEMA_H */

