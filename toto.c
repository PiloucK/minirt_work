#include <stdio.h>
#include <stdlib.h>

#define SIZE(X) (sizeof(X)/sizeof((X[0])))


// DEFINITION DES TYPES CONNUS

typedef enum {
    TYPE_SQUARE,
    TYPE_RECTANGL,
    TYPE_CIRCLE,
} Type;

// CREATION DE STRUCTURES AVEC HERITAGE INSPIRE DU C++

typedef struct {
    // LE PB C'EST QU'EN C ON NE PEUT PAS DONNER LA TAILLE DE STOCKAGE D'UN ENUM
    // C'EST DONC UN IN PAR DÉFAUT, TOUTES LES VALEURS POSSIBLE FERAIT INITIALISER UN TROP GRAND TABLEAU
    // Type type;
    // DONC IL FAUT RESTER NON TYPÉ, EVENTUELLEMENT UTILISER DES ENUM
    char type;
} Object;

typedef struct {
    Object object;
    int centerX, centerY;
    int radius;
} Circle;

typedef struct {
    Object object;
    int top, left;
    int large;
} Square;

typedef struct {
    Square square;
    int height;
} Rectangle;

// POTOTYPE DE FONCTION GÉNÉRIQUE D'IMPRESSION D'UN OBJET DE N'IMPORTE QUEL TYPE
// AVEC FONCTION DE inflate NON IMPLÉMENTÉ
typedef int (*PrintFunction)(Object * object, int inflat);

// TABLEAU DES POINTEURS DE FONCTIONS
PrintFunction printArray[256];

// FONCTIONS D'AFFICHAGES DÉDIÉES
int printArray_rafl(Object * object, int inflat) {
    printf("RAFL type:%d\n", object->type);
    return 0;   // indique une erreure
}
int printArray_square(Object * object, int inflat) {
    Square * square = (Square *)object;
    printf("SQUARE top:%d left:%d large:%d\n", square->top, square->left, square->large);
    return 1;
}
int printArray_rectangle(Object * object, int inflat) {
    Rectangle * rect = (Rectangle *)object;
    printf("RECT top:%d left:%d large:%d height:%d\n", rect->square.top, rect->square.left, rect->square.large, rect->height);
    return 1;
}
int printArray_circle(Object * object, int inflat) {
    Circle * circle = (Circle *)object;
    printf("CIRCLE top:%d left:%d large:%d\n", circle->centerX, circle->centerY, circle->radius);
    return 1;
}

// FONCTIONS D'INSTANCIATION DÉDIÉES
Square * newSquare(int top, int left, int large) {
    Square * square = malloc(sizeof(Square));
    square->object.type = TYPE_SQUARE;
    square->top = top;
    square->left = left;
    square->large = large;
    return square;
}

Rectangle * newRect(int top, int left, int large, int height) {
    Rectangle * rect = malloc(sizeof(Rectangle));
    rect->square.object.type = TYPE_RECTANGL;
    rect->square.top = top;
    rect->square.left = left;
    rect->square.large = large;
    rect->height = height;
    return rect;
}

// INITALISATION DU TABLEAU, TOUTES LES CASES NON UTILISÉES SONT INITIALISÉES AVEC UN RAFL
void printArray_init() {
    for (int i=0; i<SIZE(printArray); ++i) {
        printArray[i] = printArray_rafl;
    }
    printArray[TYPE_SQUARE] = printArray_square;
    printArray[TYPE_RECTANGL] = printArray_rectangle;
    printArray[TYPE_CIRCLE] = printArray_circle;
}

// AFFICHAGE DE N'IMPORTE QUEL TYPE D'OBJECT EN UTILISANT LE TABLEAU
int printArray_run(Object * object, int inflat) {
    return (*printArray[object->type])(object, inflat);
}

int main(int arc, char ** argv) {

    printArray_init();

    // CREATION D'OBJET ET AFFICHAGE
    Square * object = newSquare(12, 23, 34);
    printArray_run((Object*)object, 45);
    // CRÉATION D'OBJET ET AFFICHAGE EN UNE LIGHE
    printArray_run((Object*)newRect(12, 23, 34, 45), 56);
    
    // PATCH D'UN OBJET POUR CRÉER UN TYPE INCONNU
    object->object.type = 18;
    printArray_run((Object*)object, 45);
    
    return 2;
}