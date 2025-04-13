#include"tache.h"
void init(Personne *p){
p->im=IMG_Load("sprite.png") ;//sprite perso
p->v=IMG_Load("p.png") ;//sprite vie
	p->pos.x=100;//sprite 
	p->pos.y=500;//sprite 
	p->vitesse=5;//vitesse ly bch yebda beha
	p->acceleration=0;
	p->saut=0;
	p->score=0;
	p->vie=5;//sprite l vie aandna 1 matrice de 5 colonnes
	p->direction=0;//stable we9ef f blassa wahda

	p->spritesheet.x=0;//laffichage du perso
	p->spritesheet.y=0;//affichage perso
	p->spritesheet.w=80;//affichage du perso
	p->spritesheet.h=110;//affichage perso
	
	p->vs.x=0;//la pos du sprite vie
	p->vs.y=0;//la pos du sprite vie
	p->vs.w=97;//la pos du sprite vie
	p->vs.h=128;//la pos du sprite vie
	
}
void afficherPerso(Personne p , SDL_Surface * screen){

	SDL_BlitSurface(p.im , &p.spritesheet , screen  , &p.pos);//SDL_BlitSurface :afficher un sprite(perso) à une position donnée sur l'écran du jeu.
	//    p.im : La surface SDL contenant l'image du personnage (spritesheet).
	// &p.spritesheet : Un rectangle (SDL_Rect) définissant la partie de la spritesheet à afficher (frame actuelle de l'animation).
	// screen : La surface de destination (l'écran du jeu).
   	// &p.pos : Un rectangle (SDL_Rect) définissant où afficher le personnage à l'écran (coordonnées x et y).



	SDL_BlitSurface(p.v , &p.vs , screen  , NULL);//SDL_BlitSurface :afficher un sprite (vie)à une position donnée sur l'écran du jeu.
	//    p.v : La surface SDL contenant l'image du vie (spritesheet).
	// &p.vs : Un rectangle (SDL_Rect) définissant la partie de la spritesheet à afficher (frame actuelle de l'animation).
	// screen : La surface de destination (l'écran du jeu).
   	// NULL : indique que la surface doit être affichée aux coordonnées par défaut (probablement (0,0))..
}
void afficherPerso2(Personne p , SDL_Surface * screen, SDL_Rect v2){

	SDL_BlitSurface(p.im , &p.spritesheet , screen  , &p.pos);
	SDL_BlitSurface(p.v , &p.vs , screen  ,&v2);
	//&v2 : Un rectangle (SDL_Rect) qui remplace NULL et définit où afficher l'élément visuel (p.v).
}

void movePerso( Personne *p , Uint32 dt ){
 double dx= 0.5 * p->acceleration * dt * dt + p->vitesse * dt ; //dx=distance yemcheha pr la vitesse:mouvement uniformément accéléré (cinématique)
switch(p->direction){
             //droite
case 2:
	p->pos.x+=dx ;//nzidou f x lel dis
	break;
case 1: //gauche
	p->pos.x-=dx;
	break;
}
if (p->pos.x<=0)
p->pos.x=0;//Empêche le personnage de sortir de l’écran à gauche (x < 0).
}




void animerPerso ( Personne *p){
if (p->spritesheet.x<125){//Si le découpage de la spritesheet (x) n’a pas encore atteint 120 pixels :
	p->spritesheet.x+=p->spritesheet.w ;}// Passe à la frame suivante.
else {p->spritesheet.x=0 ;}//Sinon (else), on revient à la première frame 
p->spritesheet.y=p->direction*p->spritesheet.h;//Change la ligne de la spritesheet en fonction de la direction (1 = gauche, 2 = droite).

p->vs.x=(p->vie-1)*p->vs.w;//Ajuste la position de la barre de vie en fonction du nombre de vies restantes (

}



void saut_Personnage ( Personne *p, Uint32 dt, int posx_absolu, int posy_absolu){	
	int c = 200; // Hauteur du saut
    float a = -0.004; //Facteur qui donne une trajectoire parabolique (effet de gravité).
    
if(p->saut==1){	//Calcul du déplacement horizontal 
	 double dx= 0.5 * p->acceleration * dt * dt + p->vitesse * dt ;
	         p->pos.y = a * (p->pos.x ) * (p->pos.x) + c;//Équation d'une parabole pour simuler un saut réaliste.
	                     if(p->pos.y<=200)
	                     p->pos.y=200;          // Empêche le personnage de descendre en dessous de y=200.
}

//hot sprite okhra 
if (p->saut==0){
	p->pos.y=500;} //Si le personnage ne saute pas (saut=0), sa position verticale est fixée à y=500
//Position normale au sol (quand le saut est fini).y=500
}





void initialiser_backmenu(background * back)//laposition du background
{
	back->img=IMG_Load("back.jpeg");
	back->pos.x=0;//emplacement x 
	back->pos.y=0;//emplacement y
	back->pos.h=1400;//largeur
	back->pos.w=1000;//hauteur
	
}




void afficher_back(SDL_Surface *screen,background back)//affichage background
{
	SDL_BlitSurface(back.img , NULL , screen  , &back.pos); //affichage ; tjrs blitsurface pour l affichage
}
void libererBack(background *back)//liberer background pour eviter les erruers de segumentations
{
		SDL_FreeSurface(back->img);
		
}


