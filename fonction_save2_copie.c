#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "enigme2_copie.h"
#include <time.h>
/**!
* @file<fonction_save2_copie.c>
* @brief developpement des fonctions
* @author yasmine_marzouk
* @version 1.0
* @date 20:04:2021
*/
///initialisation d'un enigme:
/**
* @brief initialisation d'un enigme
* @param ecran pour l'ecran 
* @return enigme
*/
enigme init_enigme(SDL_Surface *ecran)
{ FILE* f=NULL;
enigme e;
e.im=SDL_LoadBMP("mystere_back_akber.bmp");
e.pos.x=0;
e.pos.y=0;
e.pos_q.x=200;
e.pos_q.y=150;
e.pos_q.h=150;
e.pos_q.w=400;
e.pos_r1.x=75;
e.pos_r1.y=350;
e.pos_r1.h=150;
e.pos_r1.w=300;
e.pos_r2.x=425;
e.pos_r2.y=500;
e.pos_r2.h=150;
e.pos_r2.w=300;
e.pos_r3.x=825;
e.pos_r3.y=650;
e.pos_r3.h=150;
e.pos_r3.w=300;
f=fopen("enigme2_copie.txt","r");
return e;
}


///affichage d'un enigme

/**
* @brief affichage d'un enigme
* @param ecran et enigme pour l'affichage de la question et ses rponses
* @return nothing
*/
void affiche_enigme(SDL_Surface *ecran,enigme e)
{
 FILE* f=NULL;
SDL_Surface *texte;
SDL_Surface *texte1;
SDL_Surface *texte_a;
SDL_Surface *texte_b;
SDL_Surface *texte_c;
TTF_Font *police=NULL;
TTF_Font *police_a=NULL;
SDL_Rect position_texte,position_texte_a,position_texte_b,position_texte_c;
char pause;
char ch[100],ch1[100],ch2[100],ch3[100],ch4[100];
SDL_Color rose={255,0,128};
SDL_Color vert={128,128,0};
SDL_Color bleu={64,128,128};
SDL_Color beje={88,88,44};
SDL_Color blanc={255,255,255};
SDL_Color rouge={187,0,0};
sprintf(ch,"%s",e.question);
sprintf(ch1,"%s",e.a);
sprintf(ch2,"%s",e.b);
sprintf(ch3,"%s",e.c);
sprintf(ch4,"%s",e.cr);
TTF_Init();
police=TTF_OpenFont("angelina.TTF",50);

//question
texte=TTF_RenderText_Blended(police,ch,rose);
SDL_BlitSurface(e.im, NULL, ecran, &e.pos);
SDL_BlitSurface(texte, NULL, ecran, &e.pos_q);
SDL_Flip(ecran);

//Proposition a
texte=TTF_RenderText_Blended(police,ch1,blanc);
SDL_BlitSurface(texte, NULL, ecran, &e.pos_r1);
SDL_Flip(ecran);

//Proposition b
texte=TTF_RenderText_Blended(police,ch2,blanc);
SDL_BlitSurface(texte, NULL, ecran, &e.pos_r2);
SDL_Flip(ecran);

//Proposition c
texte=TTF_RenderText_Blended(police,ch3,blanc);
SDL_BlitSurface(texte, NULL, ecran, &e.pos_r3);
SDL_Flip(ecran);
SDL_FreeSurface(texte);
SDL_FreeSurface(e.im);
TTF_CloseFont(police);
TTF_Quit();
}



///lire fichier

/**
* @brief lecture d'un enigme du fichier
* @param  pointeur sur l'enigme choisi aléatoirement (questions et sesreponses)
* @return enigme
*/

enigme lire_fichier(enigme*e)
{FILE* f=NULL;
    char snum;
    char T[200]="";
    char ch[200]="";
    char *token;
    int trouve=0;
    int i=0, caractere_actu,l=0;
    srand(time(NULL)); 
    int nombre = 0;
    const int MIN = 1, MAX = 5;
    nombre = (rand() % (MAX + 1 - MIN)) + MIN; 
    f = fopen("enigme2_copie.txt", "r");
    fseek(f,0, SEEK_SET);
    snum=nombre+'0';

    while (fgets(T,300, f)!=NULL)
    {
       i=0;
        if(T[0]==snum)
        {

            token = strtok(T,";");
            while( token != NULL )
            {
                if(i==0)
                {
                    e->question=token;
                    i++;
                }


                else if(i==1)
                {
                    e->a=token;

                    i++;
                }
                else if(i==2)
                {
                    e->b=token;
                    i++;
                }
                else if(i==3)
                {
                    e->c=token;
                    i++;
                }
                else if(i==4)
                {
                    e->cr=token;

                }


                token = strtok(NULL, ";");
            }
	



  
return (*e);

         
     }

   }

    fclose(f);

}

///résolution

/**
* @brief résolution d'un enigme choisi à partir fichier
* @param   ecran et pointeur sur l'enigme choisi aléatoirement 
* @return 0 si la réponse est correcte et -1 sinon
*/

int resolution(enigme *e,SDL_Surface *ecran)
{
int continuer=1,val;
char reponse;
SDL_Surface *ima=NULL;
SDL_Surface *ima2=NULL;
SDL_Rect pos,pos2;
pos.x=500;
pos.y=400;
char ch[20];
SDL_Event event;
sprintf(ch,"%s",e->cr);
printf("ch=%s",ch);
while(continuer==1)
{      
 SDL_PollEvent(&event);
 switch(event.type)
{	case SDL_QUIT:
	continuer=0;
	break;
	case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
        case SDLK_a:
            reponse='a';
continuer=0;

            break;
        case SDLK_b:
            reponse='b';
continuer=0;
            break;
        case SDLK_c:
            reponse='c';
continuer=0;
            break; 

          
        }

        break;


	
}
}
printf("ch[3]=%c",ch[3]);
if(ch[3]==reponse)
{

ima=SDL_LoadBMP("win_png_n.bmp");
//ima=SDL_LoadBMP("win_f_1_2.bmp");
//ima=IMG_Load("rrr.png");
SDL_BlitSurface(ima,NULL,ecran,&pos);
SDL_Flip(ecran);
SDL_Delay(1000);
SDL_FreeSurface(ima);
printf("Vous avez gagné!!");
return 0;
}

else
{

ima2=SDL_LoadBMP("lose_png_n.bmp");
//ima2=SDL_LoadBMP("lose_f_1_2.bbmp.bmp");
SDL_BlitSurface(ima2,NULL,ecran,&pos);
SDL_Flip(ecran);
SDL_Delay(1000);
SDL_FreeSurface(ima2);
printf("Vous avez perdu!!");
return -1;
}

}








