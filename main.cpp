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
    Sistema *Sistema_pendulo;
    
    Sistema_pendulo = new Sistema();
    cout << "hello"<< endl;
    
    cout <<"salida : "<< Sistema_pendulo->funcion_pertenencia("PP",10)<<endl;
    return 0;
}

