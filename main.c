#include "tache.h"
#define GRAVITY 10 //pour le saut (gravité de la terre =10)

int main() {
    Uint32 dt, t_prev;  // pour représenter le temps en millisecondes.

			//t_prev : Stocke l’horodatage (timestamp) du cycle précédent de la boucle de je[utiliser pour Récupère le temps]
    double dx;//distance parcourue par le temps

    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO);//Cela active la gestion de la vidéo, du timer et de l'audio.
    int boucle = 1, saut = 0;  // si boucle=1 le jeu continue de s’exécute snn s arrete
				//si saut=0   → Pas de saut.  snn (=1) en plein saut
    SDL_Surface *screen, *b;     //SDL_Surface *screen:Représente la fenêtre principale du jeu.
				//SDL_Surface *b :Surface pour l’image d’arrière-plan.

    
    background back;//variable de type back(utliser pour afficher la background)
    SDL_Event event;//gérer les événements
    Personne p;//perso1
    Personne p2;//perso2
    int multi = 0; // Variable pour contrôler l'affichage du 2ème joueur  si(=1 -> 2joueurs)
    SDL_Rect v2;//: Définit la position initiale du deuxième joueur (p2).
    v2.x = 1200;//la position du perso2
    v2.y = 0;//la position du perso2
    
    b = IMG_Load("back.jpeg");//charge une image en mémoire et l'associe à la variable b

    // Initialize SDL video mode
    screen = SDL_SetVideoMode(1350, 700, 32, SDL_HWSURFACE | SDL_SRCALPHA | SDL_DOUBLEBUF);

    // Initialize background
    initialiser_backmenu(&back);

    // Initialize characters
    init(&p);
    init(&p2);

    while (boucle) {
        t_prev = SDL_GetTicks();// le temps écoulé en millisecondes depuis le début du programme
        SDL_PollEvent(&event);//détecte si un événement a eu lieu (touche enfoncée, relâchée, fermeture de la fenêtre, etc.).
        
        switch (event.type) {//Gestion des événements(chaque case hiya event ) 
            case SDL_QUIT://ken khrajt men jeu bouclee=0
                boucle = 0;
                break;
            case SDL_KEYDOWN://sdl keydown ki tebda nezla aal les btns 
                switch (event.key.keysym.sym) {//l event ly bch ysir selon le btn ly bch tenzel alih
                    case SDLK_p:  // Seule touche pour activer/désactiver le multi-joueur
                        multi = !multi;
                        break;
                    case SDLK_LEFT://ken nzelna aal touche left pour perso 1 bch temchi aal lysar
                        p.direction = 1;
                        break;
                    case SDLK_q://ken nzelna aal touche q  
                        if (multi == 1)//pour perso2
                            p2.direction = 1;//bch temchi aal lysar
                        break;
                    case SDLK_RIGHT://ken nzelna aal touche right(perso1)
                        p.direction = 2;//nemchiw aal ymin
                        break;
                    case SDLK_d://ken nzelna aal touche d
                        if (multi == 1)//pour perso2
                            p2.direction = 2;//nemchiw aal ymin
                        break;
                    case SDLK_UP://ken nzelna aal touche up (perso1)
                        p.saut = 1;//naamlou saut
                        break;
                    case SDLK_z://ken nzelna aal touche z
                        if (multi == 1)//pour perso2
                            p2.saut = 1;//naamlou saut
                        break;
                    case SDLK_SPACE://ken nzelna aal touche espace (perso1)
                        p.direction = 3; //yaamel attack
                        break;
                    case SDLK_x://ken nzelna aal touche x
                        if (multi == 1)//pour perso2
                            p2.direction = 3;//yaamel attack
                        break;
                    case SDLK_e://ken nzelna aal touche e pour perso1
                        p.vitesse += 5; //la vitesse bch tzid
                        printf("%f\n", p.vitesse);
                        break;
                    case SDLK_c://ken nzelna aal touche c 
                        if (multi == 1) {//pour perso1
                            p2.vitesse += 5;////la vitesse bch tzid     
                            printf("%f\n", p2.vitesse);
                        }
                        break;
                    case SDLK_l://ken nzelna aal touche c pour perso1 vie bch tnkos
                        p.vie--;
                        break;
                    case SDLK_w:////ken nzelna aal touche c pour perso2 vie bch tnkos
                        p2.vie--;
                        break;
                }
                break;
            case SDL_KEYUP://kenek makch nezla aala hatta btn maysir chay
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        p.direction = 0;
                        break;
                    case SDLK_q:
                        p2.direction = 0;
                        break;
                    case SDLK_RIGHT:
                        p.direction = 0;
                        break;
                    case SDLK_d:
                        p2.direction = 0;
                        break;
                    case SDLK_UP:
                        p.saut = 0;
                        break;
                    case SDLK_z:
                        p2.saut = 0;
                        break;
                    case SDLK_SPACE:
                        p.direction = 0;
                        break;
                    case SDLK_x:
                        p2.direction = 0;
                        break;
                    case SDLK_e:
                        p.vitesse = 0;
                        break;
                    case SDLK_c:
                        p2.vitesse = 0;
                        break;
                }
                break;
        }

        // Player 1 movement
        if (p.direction == 1) {//Le joueur 1 va vers la gauche.
            p.acceleration += 0.5;
        }
        if (p.direction == 2) {//Le joueur 1 va vers la droite
            p.acceleration += 0.5;
        }
        if (p.saut == 1) {//le personnage 1 est en train de sauter.
            saut_Personnage(&p, dt, p.pos.x, p.pos.y);// applique la physique du saut
        }

        // Player 2 movement (only if multi is enabled)
        if (multi == 1) {
            if (p2.direction == 1) {//Le joueur 2 va vers la gauche.
                p2.acceleration += 0.5;//l’accélération augmente de 0.5,(expl :Une voiture ne passe pas immédiatement de 0 km/h à 100 km/h, elle accélère progressivement.)
            }
            if (p2.direction == 2) {//Le joueur 2 va vers la droite
                p2.acceleration += 0.5;
            }
            if (p2.saut == 1) {//le personnage 2 est en train de sauter
                saut_Personnage(&p2, dt, p2.pos.x, p2.pos.y);// applique la physique du saut
            }
        }
       
        SDL_Delay(4);//ralentit la boucle de 4 millisecondes
        dt = SDL_GetTicks() - t_prev;//calcule le temps écoulé depuis la dernière itération
        movePerso(&p, dt);//met à jour la position du joueur en fonction du temps écoulé.

        // Player 1 physics
        p.acceleration -= 0.025;//Quand le joueur relâche la touche de déplacement, on réduit progressivement l’accélération pour simuler l’inertie.

				//Cela évite que le joueur s’arrête brutalement, donnant un effet plus réaliste.
        if (p.acceleration <= 0)
            p.acceleration = 0;
        if (p.acceleration >= 0.7)
            p.acceleration = 0.7;

				//L’accélération est bloquée entre 0 et 0.7 pour éviter que le personnage aille trop vite ou continue à glisser 					indéfiniment.

        p.vitesse_j += GRAVITY;			// → La vitesse verticale augmente avec la gravité.
        p.pos.y += p.vitesse_j;// → Le personnage tombe de plus en plus vite.
        if (p.pos.y >= 500) {//Si le personnage touche le sol (Y = 500), on :
            p.pos.y = 500;//Le fixe à Y = 500 pour qu'il ne tombe pas plus bas.
            p.vitesse_j = 10;//pour de garder un mouvement fluide après un saut
        }

        // Player 2 physics (only if multi is enabled)
        if (multi == 1) {
            movePerso(&p2, dt);
            p2.acceleration -= 0.025;
            if (p2.acceleration <= 0)
                p2.acceleration = 0;
            if (p2.acceleration >= 0.7)
                p2.acceleration = 0.7;

            p2.vitesse_j += GRAVITY;
            p2.pos.y += p2.vitesse_j;
            if (p2.pos.y >= 500) {
                p2.pos.y = 500;
                p2.vitesse_j = 10;
            }
            animerPerso(&p2);
        }

        animerPerso(&p);

        // Clear the screen and draw background
        SDL_FillRect(screen, NULL, 0);//Elle remplit tout l'écran (screen) avec la couleur noire  bch htot fou9ha l bac
        SDL_BlitSurface(b, NULL, screen, NULL);//affichage back
        
        // Draw characters
        afficherPerso(p, screen);
        if (multi == 1) {
            afficherPerso2(p2, screen, v2);
        }

        // Flip buffers
        SDL_Flip(screen);//Mise à jour de l'écran (SDL_Flip)
        SDL_Delay(100);//fait une pause de 100 millisecondes avant de continuer.

			//Cela évite que le jeu tourne trop vite et consomme trop de CPU.
    }

    // Free surfaces
    SDL_FreeSurface(screen);//Évite les fuites de mémoire en libérant la surface après utilisation.(liberation)
    libererBack(&back);//libeartion du back
    SDL_Quit();//quitter le jeu
    return 0;
}
