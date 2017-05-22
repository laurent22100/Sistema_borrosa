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

void  Sistema::funcion_pertenencia(double x[2]) {
    vector<string> conjunto;
    vector<pair<string, double> > salida;
    double a,b,c,coef1,coef2;
    for(int k=0; k<2;k++){
        if(x[k]<centro1){
            conjunto.push_back("NG");
        }else if(x[k] <centro2){
            conjunto.push_back("NG");
            conjunto.push_back("NP");
        }else if(x[k] <centro3){
            conjunto.push_back("NP");
            conjunto.push_back("Z");  
        }else if(x[k] <centro4){
            conjunto.push_back("Z");
            conjunto.push_back("PP");       
        }else if(x[k] <centro5){
            conjunto.push_back("PP");
            conjunto.push_back("PG");    
        }else{
            conjunto.push_back("PG");
        }     
            
        for(int i=0; i<conjunto.size();i++){    
            if(conjunto[i]== "NG"){ 
                a = -100.0;
                b = centro1;
                c = centro2;
                if(x[k] <= b && x[k] >= a){
                   salida.push_back(std::make_pair(conjunto[i],1));
                }else if (x[k] <= c && x[k] >= b){
                   coef1=((0-1)/(c-b));
                   coef2=1-coef1*b;
                   salida.push_back(std::make_pair(conjunto[i],coef1*x[k]+coef2));
                }
            }else if ( conjunto[i] =="NP"){  
                a = centro1;
                b = centro2;
                c = centro3;
                if(x[k] <= b && x[k] >= a){
                   coef1=((1-0)/(b-a));
                   coef2=0-coef1*a;
                }else if (x[k] <= c && x[k] >= b){
                   coef1=((0-1)/(c-b));
                   coef2=1-coef1*b;
                }
                salida.push_back(std::make_pair(conjunto[i],coef1*x[k]+coef2));
            }else if (conjunto[i] == "Z"){  
                a = centro2;
                b = centro3;
                c = centro4;
                if(x[k] <= b && x[k] >= a){
                   coef1=((1-0)/(b-a));
                   coef2=0-coef1*a;
                }else if (x[k] <= c && x[k] >= b){
                   coef1=((0-1)/(c-b));
                   coef2=1-coef1*b;
                }
                salida.push_back(std::make_pair(conjunto[i],coef1*x[k]+coef2));
            }else if (conjunto[i]== "PP"){  
                a = centro3;
                b = centro4;
                c = centro5;
                if(x[k] <= b && x[k] >= a){
                   coef1=((1-0)/(b-a));
                   coef2=0-coef1*a;
                }else if (x[k] <= c && x[k] >= b){
                   coef1=((0-1)/(c-b));
                   coef2=1-coef1*b;
                }
                salida.push_back(std::make_pair(conjunto[i],coef1*x[k]+coef2));
            } else if (conjunto[i] == "PG"){ 
                a = centro4;
                b = centro5;
                c = 100.0;
                if(x[k] <= b && x[k] >= a){
                   coef1=((1-0)/(b-a));
                   coef2=0-coef1*a;
                   salida.push_back(std::make_pair(conjunto[i],coef1*x[k]+coef2));
                }else if (x[k] <= c && x[k] >= b){
                   salida.push_back(std::make_pair(conjunto[i],1));
                }
            }
        }
        if(k == 0){
            setInclusionTeta(salida);
        }else if (k == 1){
            setInclusionOmega(salida);
        }
        salida.clear();
        conjunto.clear();

    }
}

void Sistema::funcion_borrosificacion() {//Singleton
    for(int i=0;i<alphaParaCadaRegla.size();i++){
        cout<<"Regla "<<alphaParaCadaRegla[i].first<<" : ";
        // tener el centro del conjunto de que responde a las reglas
        centro_Y_alpha.push_back(std::make_pair(funcion_fam(alphaParaCadaRegla[i].first),alphaParaCadaRegla[i].second ));
        cout<<" // Centro : "<<centro_Y_alpha[i].first<< " //Alpha_"<< i << " = " << centro_Y_alpha[i].second <<endl;
    }   
}

void Sistema::funcion_inferencia(){ // regla del minimo
    int nb=0;
    for(int i=0;i<inclusionTeta.size();i++){
        
        for(int j=0;j<inclusionOmega.size();j++){
            
            if(inclusionTeta[i].second<inclusionOmega[j].second){
                this->alphaParaCadaRegla.push_back(std::make_pair(inclusionTeta[i].first+"/"+inclusionOmega[j].first,inclusionTeta[i].second));
            }else{
                this->alphaParaCadaRegla.push_back(std::make_pair(inclusionTeta[i].first+"/"+inclusionOmega[j].first,inclusionOmega[j].second));
            }
            nb++;
        }
    }    
}

double Sistema::funcion_deborrosificacion() {
    double numResultado,denResultado,resultado;
    for(int i=0;i<centro_Y_alpha.size();i++){
        numResultado += centro_Y_alpha[i].second*centro_Y_alpha[i].first;
        denResultado += centro_Y_alpha[i].second;
    }
    resultado = numResultado/denResultado;
    return resultado;
}

double Sistema::funcion_fam(string teta_omega) {
    double centroConjuntoFinal;
    if(teta_omega == "NG/NG"){
        // NG;
        centroConjuntoFinal = centro1;
    }else if(teta_omega == "NG/NP"){
        // NG;
        centroConjuntoFinal = centro1;
    }else if(teta_omega == "NG/Z"){
        // NG;
        centroConjuntoFinal = centro1;
    }else if(teta_omega == "NG/PP"){
        // NP;
        centroConjuntoFinal = centro3;
    }else if(teta_omega == "NG/PG"){
        // Z;
        centroConjuntoFinal = centro4;
    }else if(teta_omega == "NP/NG"){
        // NG;
        centroConjuntoFinal = centro2;
    }else if(teta_omega == "NP/NP"){
        // NG;
        centroConjuntoFinal = centro2;
    }else if(teta_omega == "NP/Z"){
        // NG;
        centroConjuntoFinal = centro2;
    }else if(teta_omega == "NP/PP"){
        // Z;
        centroConjuntoFinal = centro3;
    }else if(teta_omega == "NP/PG"){
        // PP;
        centroConjuntoFinal = centro4;
    }else if(teta_omega == "Z/NG"){
        // NG;
        centroConjuntoFinal = centro1;
    }else if(teta_omega == "Z/NP"){
        // NP;
        centroConjuntoFinal = centro2;
    }else if(teta_omega == "Z/Z"){
        // Z;
        centroConjuntoFinal = centro3;
    }else if(teta_omega == "Z/PP"){
        // PP;
        centroConjuntoFinal = centro4;
    }else if(teta_omega == "Z/PG"){
        // PG;
        centroConjuntoFinal = centro5;
    }else if(teta_omega == "PP/NG"){
        // NP;
        centroConjuntoFinal = centro2;
    }else if(teta_omega == "PP/NP"){
        // Z;
        centroConjuntoFinal = centro3;
    }else if(teta_omega == "PP/Z"){
        // PP;
        centroConjuntoFinal = centro4;
    }else if(teta_omega == "PP/PP"){
        // PG;
        centroConjuntoFinal = centro4;
    }else if(teta_omega == "PP/PG"){
        // PG;
        centroConjuntoFinal = centro4;
    }else if(teta_omega == "PG/NG"){
        // Z;
        centroConjuntoFinal = centro2;
    }else if(teta_omega == "PG/NP"){
        // PP;
        centroConjuntoFinal = centro3;
    }else if(teta_omega == "PG/Z"){
        // PG;
        centroConjuntoFinal = centro5;
    }else if(teta_omega == "PG/PP"){
        // PG;
        centroConjuntoFinal = centro5;
    }else if(teta_omega == "PG/PG"){
        // PG;
        centroConjuntoFinal = centro5;
    }
    return centroConjuntoFinal;
}


vector<pair<string, double> >  Sistema::getInclusionTeta(){
    return this->inclusionTeta;
}

vector<pair<string, double> >  Sistema::getInclusionOmega(){
    return this->inclusionOmega;
}

vector<pair<string, double> >  Sistema::getAlphaParaCadaRegla(){
    return this->alphaParaCadaRegla;
}

void Sistema::setInclusionTeta(vector<pair<string, double> > teta){
    this->inclusionTeta = teta;
}

void Sistema::setInclusionOmega(vector<pair<string, double> > omega){
    this->inclusionOmega = omega;
}

void Sistema::setAlphaParaCadaRegla(vector<pair<string, double> > alphaParaCadaRegla){
    this->alphaParaCadaRegla = alphaParaCadaRegla;
}