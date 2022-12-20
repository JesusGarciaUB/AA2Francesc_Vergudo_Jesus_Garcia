#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>

using namespace std;

/// <summary>
///	En la logica tenemos los includes que se usan en multiples archivos.
/// 
/// getRandom() duvuelve un un rango de numeros y devuelve un random entre ese rango / o le puedes pasar un valor maximo y te retornara un valor entre 1 y el valor maximo
///  
/// </summary>

int getRandom(int min, int max);
int getRandom(int max);