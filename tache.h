#ifndef TACHE_H_INCLUDED
#define TACHE_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
typedef struct{
int score;
int vie;
SDL_Surface *im,*v; //chargement   ( v::image vie  , img:sprit)
SDL_Rect  pos,  spritesheet,vs; //init la pos    
float   vitesse_j ;//vitesse jump
double acceleration, vitesse; //virgule flottante + precision   ; la vitesse hiya la vitesse intiale + acceleration(vitesse ly bch yzidha)
int direction;//gauche droite 
int saut;//haut 
}Personne;
typedef struct
{
	SDL_Surface *img;
	SDL_Rect pos;
}background ;


void init(Personne  *p);//declarer perso
void afficherPerso(Personne p , SDL_Surface * screen);//afficher le personnage 1 sur l'écran
void afficherPerso2(Personne p , SDL_Surface * screen,SDL_Rect v2);//afficher le personnage 2 sur l'écran
void movePerso( Personne *p ,  Uint32 dt);//(temps écoulé, souvent en millisecondes).
void animerPerso ( Personne *p);//gérer l'animation du personnage (changement de sprites, effets visuels, etc.).
void saut_Personnage ( Personne *P, Uint32 dt, int posx_absolu, int posy_absolu);//un temps dt, et des coordonnées absolues 
void initialiser_backmenu(background * back);//initialise probablement l'arrière-plan du menu (chargement d'image, position, etc.).
void afficher_back(SDL_Surface *screen,background back);//affichage du back
void libererBack(background *back);//liberation pour eviter les erruers de segumentation

#endif
