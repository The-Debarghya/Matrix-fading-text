#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<unistd.h>
#include"ui.h"

#define NUM_DRIPS 2500000
#define PROB_DRIP_SPAWN 0.9999
#define PROB_DIM 0.9999
#define PROB_CHANGE 0.95
#define RANDOM_PRINTABLE_CHARACTER (33+(rand()%80))
//#define RANDOM_PRINTABLE_CHARACTER (48+(rand()%2))

typedef struct{

    int x, y;
    bool live;
    bool bright;

}drip;

cell matrix[MAXX][MAXY];
drip drips[NUM_DRIPS];


void init_drips(){

    for(int i=0; i< NUM_DRIPS; i++){
        drips[i].live = false;
    }

}

double rand01(){
    return (double)(rand()/RAND_MAX);
}

void matrix_init(){

    for(int x=0; x< MAXX; x++){
        for(int y=0; y<MAXY; y++){

            matrix[x][y].char_val = 0;
            matrix[x][y].intensity = 0;

        }
    }

    init_drips();
}

void fade_n_change_matrix(){

    for(int x=0; x< MAXX; x++){
        for(int y=0; y<MAXY; y++){

            if(rand01() < PROB_CHANGE || matrix[x][y].char_val == 0){
                matrix[x][y].char_val = RANDOM_PRINTABLE_CHARACTER;
            }

            if(rand01()<PROB_DIM){
                if( matrix[x][y].intensity > 0){
                    matrix[x][y].intensity--;
                }
            }            

        }
    }
}

void try_add_drips(){

    for(int i=0; i< NUM_DRIPS; i++){
        if(drips[i].live == false){
            drips[i].live = true;
            drips[i].x = rand()%MAXX;
            drips[i].y = 0;
            drips[i].bright = rand()%2;
            return;
        }
    }
}

void update_drips(){

   for(int i=0; i< NUM_DRIPS; i++){
       if(drips[i].live){
           if(drips[i].bright){
               matrix[drips[i].x][drips[i].y].intensity = MAX_INTENSITY;

           }
           else{
               matrix[drips[i].x][drips[i].y].intensity = MIN_INTENSITY;
           }
           if(++drips[i].y >= MAXY){
               drips[i].live = false;

           }
       }
   } 
}

void matrix_update(){

    if(rand01() < PROB_DRIP_SPAWN){

        try_add_drips();
    }
    update_drips();

    fade_n_change_matrix();
}