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
double Sistema::funcion_pertenencia(string conjunto, double u) {
    double a,b,c,coef1,coef2,salida;
        if(conjunto== "NG"){ 
            a = -100.0;
            b = -50.0;
            c = -25.0;
            if(u <= b && u >= a){
               salida = 1;
            }else if (u <= c && u >= b){
               coef1=((0-1)/(c-b));
               coef2=1-coef1*b;
               salida = coef1*u+coef2;
            }
        }else if ( conjunto =="NP"){  
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
            salida = coef1*u+coef2;
        }else if (conjunto == "Z"){  
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
            salida = coef1*u+coef2;
        }else if (conjunto== "PP"){  
            a = 0.0;
            b = 25.0;
            c = 50.0;
            if(u <= b && u >= a){
               coef1=((1-0)/(b-a));
               coef2=0-coef1*a;
               cout<<"eee";
            }else if (u <= c && u >= b){
               coef1=((0-1)/(c-b));
               coef2=1-coef1*b;
            }
            salida = coef1*u+coef2;
        } else if (conjunto == "PG"){ 
            a = 25.0;
            b = 50.0;
            c = 100.0;
            if(u <= b && u >= a){
               coef1=((1-0)/(b-a));
               coef2=0-coef1*a;
               salida = coef1*u+coef2;
            }else if (u <= c && u >= b){
               salida = 1;
            }
        }
      
      return salida;

}
void Sistema::funcion_borrosificacion() {//Singleton
    
}
void Sistema::funcion_inferencia() { // Regla del minimo
    
}
void Sistema::funcion_deborrosificacion() {
}
void Sistema::funcion_fam(string teta, string omega) {
    if(teta == Z && omega == Z){
        this->_fuerza = Z;
    }
}