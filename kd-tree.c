#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "kdtree.h"

typedef struct _kno {
    
    int cod_IBGE;
    char *nome;
    int cod_UF;
    char *estado;   
    char *capital;

    double latitude;
    double longitude;

    char *regiao;
    int ciafi;
    int DDD;
    int fuso_H;

    struct _kno * esq;
    struct _kno * dir;
}_knode;

typedef struct _kdtree {
    int dim;
    struct _knode *root;
    struct _kdhyperrect *rect;
    
    int (*compara)(const void *);

    //remove a kd-tree da memoria
    void (*destr)(void*);
}_karv;

static int find_nearest(struct _knode *_knode, double latitude, double longitude) {

	
}