 🕹️ Modular 2D player character in C using SDL2 with state-based animations: idle, walk (left/right), jump, and attack. Uses sprite sheet handling and clean structure for easy integration into SDL-based game engines or prototypes.






🕹️ 2D SDL Character Animation
🔧 Key Files

  . main.c

  . tache.c / tache.h

  . sprite.png

  .  Makefile


🏗️ Compilation

      make

▶️ Execution

    ./prog

            Controls:

                  → : move right
              
                  ← : move left
              
                  ↑ : move up
              
                  ↓ : move down




  🧱 Dependencies

      sudo apt-get install libsdl1.2-dev libsdl-image1.2-dev libsdl-ttf2.0-dev libsdl-mixer1.2-dev



  🗂️ Makefile
  
      prog: tache.o main.o
      	gcc tache.o main.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer
      
      main.o: main.c
      	gcc -c main.c
      
      tache.o: tache.c
      	gcc -c tache.c








  🖼️ Spritesheet Info
Row	       |          Action
---------------------------
0	         |         Idle (standing)
1	         |         Walking left
2	         |         Walking right
3	         |         Jump
4	         |         Attack
