#include<stdbool.h>
#ifndef _UI_H_
#define _UI_H_

#define MAXX 200
#define MAXY 90

#define MAX_INTENSITY 13
#define MIN_INTENSITY 2

typedef struct{
    char char_val;
    int intensity;
}cell;

extern cell matrix[MAXX][MAXY];

bool init_ui();
void cleanup_ui();
void show_matrix();

#endif