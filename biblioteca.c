//
// Created by uniflusantos on 17/10/2023.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "biblioteca.h"

void limpa_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
