/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sistema.cpp
 * Author: laure
 * 
 * Created on 17 mai 2017, 17:39
 */

#include "Sistema.h"

Sistema::Sistema() {
    this->_fuerza = "NULL";
}

Sistema::Sistema(const Sistema& orig) {
}

Sistema::~Sistema() {
}


void Sistema::funcion_borrosificacion() {
}
void Sistema::funcion_deborrosificacion() {
}
void Sistema::funcion_pertenencia() {
}
void Sistema::funcion_fam(string teta, string omega) {
    if(teta == Z && omega == Z){
        this->_fuerza = Z;
    }
}