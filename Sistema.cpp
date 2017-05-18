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
void  Sistema::funcion_pertenencia(string nombre,double u) {
    vector<string> conjunto;
    vector<pair<string, double> > salida;
    double a,b,c,coef1,coef2;

    if(u<-50){
        conjunto.push_back("NG");
    }else if(u <-25){
        conjunto.push_back("NG");
        conjunto.push_back("NP");
    }else if(u <0){
        conjunto.push_back("NP");
        conjunto.push_back("Z");  
    }else if(u <25){
        conjunto.push_back("Z");
        conjunto.push_back("PP");        
    }else if(u <50){
        conjunto.push_back("PP");
        conjunto.push_back("PG");           
    }else{
        conjunto.push_back("PG");
    }
    for(int i=0; i<conjunto.size();i++){    
        if(conjunto[i]== "NG"){ 
            a = -100.0;
            b = -50.0;
            c = -25.0;
            if(u <= b && u >= a){
               salida.push_back(std::make_pair(conjunto[i],1));
            }else if (u <= c && u >= b){
               coef1=((0-1)/(c-b));
               coef2=1-coef1*b;
               salida.push_back(std::make_pair(conjunto[i],coef1*u+coef2));
            }
        }else if ( conjunto[i] =="NP"){  
            a = -50.0;
            b = -25.0;
            c=0.0;
            if(u <= b && u >= a){
               coef1=((1-0)/(b-a));
               coef2=0-coef1*a;
            }else if (u <= c && u >= b){
               coef1=((0-1)/(c-b));
               coef2=1-coef1*b;
            }
            salida.push_back(std::make_pair(conjunto[i],coef1*u+coef2));
        }else if (conjunto[i] == "Z"){  
            a = -25.0;
            b = 0.0;
            c = 25.0;
            if(u <= b && u >= a){
               coef1=((1-0)/(b-a));
               coef2=0-coef1*a;
            }else if (u <= c && u >= b){
               coef1=((0-1)/(c-b));
               coef2=1-coef1*b;
            }
            salida.push_back(std::make_pair(conjunto[i],coef1*u+coef2));
        }else if (conjunto[i]== "PP"){  
            a = 0.0;
            b = 25.0;
            c = 50.0;
            if(u <= b && u >= a){
               coef1=((1-0)/(b-a));
               coef2=0-coef1*a;
            }else if (u <= c && u >= b){
               coef1=((0-1)/(c-b));
               coef2=1-coef1*b;
            }
            salida.push_back(std::make_pair(conjunto[i],coef1*u+coef2));
        } else if (conjunto[i] == "PG"){ 
            a = 25.0;
            b = 50.0;
            c = 100.0;
            if(u <= b && u >= a){
               coef1=((1-0)/(b-a));
               coef2=0-coef1*a;
               salida.push_back(std::make_pair(conjunto[i],coef1*u+coef2));
            }else if (u <= c && u >= b){
               salida.push_back(std::make_pair(conjunto[i],1));
            }
        }
    }

    if(nombre == "teta"){
        setInclusionTeta(salida);
    }else if (nombre == "omega"){
        setInclusionOmega(salida);
    }

}


void Sistema::funcion_borrosificacion() {//Singleton
    
}

vector<pair<string, double> > Sistema::funcion_inferencia(){ // regla del minimo
    vector<pair<string, double> > alphaParaCadaRegla; // REGLE, alpha
    int nb=0;
    for(int i=0;i<inclusionTeta.size();i++){
        for(int j=0;j<inclusionOmega.size();j++){
            if(inclusionTeta[i].second<inclusionOmega[j].second){
                alphaParaCadaRegla.push_back(std::make_pair("R "+inclusionTeta[i].first+" "+inclusionOmega[j].first,inclusionTeta[i].second));
            }else{
                alphaParaCadaRegla.push_back(std::make_pair("R "+inclusionTeta[i].first+" "+inclusionOmega[j].first,inclusionOmega[j].second));
            }
            nb++;
        }
    }

    return alphaParaCadaRegla;
    
}
void Sistema::funcion_deborrosificacion() {
}
void Sistema::funcion_fam(string teta, string omega) {
    if(teta == Z && omega == Z){
        this->_fuerza = Z;
    }else if(teta == PP && omega == NP){
        this->_fuerza = NP;
    }
}

vector<pair<string, double> >  Sistema::getInclusionTeta(){
    return this->inclusionTeta;
}

vector<pair<string, double> >  Sistema::getInclusionOmega(){
    return this->inclusionOmega;
}

void Sistema::setInclusionTeta(vector<pair<string, double> > teta){
    this->inclusionTeta = teta;
}

void Sistema::setInclusionOmega(vector<pair<string, double> > omega){
    this->inclusionOmega = omega;
}