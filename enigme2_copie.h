#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED

/**
* @struct enigme
* @brief structure de l'enigme
*/
typedef struct{
SDL_Surface *im;
SDL_Rect pos;
SDL_Rect pos_q;/*!<position de la question*/
SDL_Rect pos_r1;/*!<position de la réponse a*/
SDL_Rect pos_r2;/*!<position de la réponse b*/
SDL_Rect pos_r3;/*!<position de la réponse c*/
char *question;
 char *a;
 char *b;
   char *c;
char * cr;

}enigme;
enigme init_enigme(SDL_Surface *ecran);
enigme lire_fichier(enigme*e);
void affiche_enigme(SDL_Surface *ecran,enigme e);
int resolution(enigme *e,SDL_Surface *ecran);
#endif 

