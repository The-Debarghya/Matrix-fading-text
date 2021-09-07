#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
#include "ui.h"
#include<unistd.h>
#include"matrix.h"

//#define iter 300
#define REFRESH_DELAY 50000L

int main(int argc, char **argv){
    

    if(!init_ui()){
        return EXIT_FAILURE;
    }
    matrix_init();

    while(true){
        matrix_update();
        show_matrix();
        usleep(REFRESH_DELAY);

    }

    cleanup_ui();
    return EXIT_SUCCESS;
}