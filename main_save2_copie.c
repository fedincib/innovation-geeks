#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "enigme2_copie.h"
#include <time.h>
/**!
* @file<main_save2_copie.c>
* @brief main  général comportant le fonctionnement de toutes les fonctions relatives à l'énigme avec fichier
* @author yasmine_marzouk
* @version 1.0
* @date 20:04:2021
*/


/**!
* @file<main_save2_copie.c>
*/
int main()
{
  enigme e;
  int x;
  char pause;
  SDL_Surface *ecran;
  SDL_Surface *ima=NULL;
  SDL_Rect pos;
  pos.x=500;
  pos.y=400;
  ecran = SDL_SetVideoMode(1301, 788, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
  e=init_enigme( ecran);
  e= lire_fichier(&e);
  affiche_enigme(ecran, e);
  x=resolution(&e,ecran);
  printf("x=%d",x);
  SDL_Quit;
return 0;
}

