
//réaliser par
// hasna zouhri 
//fatima zehra raji
//meryam lachgar



	
	//-----------------------------------------------bibliotheque------------------------------------------------------------------------
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <windows.h>
	#include <time.h>
	#include <conio.h>
	#include <string.h>
	#include <unistd.h>
	//-----------------------------------------------------------les_couleur et type de ecriture ------------------------------------------------------------
	 
	 
	 #define ANSI_COLOR_RED     "\x1b[31m"
	 #define ANSI_COLOR_RESET   "\x1b[0m"
     #define ANSI_COLOR_GREEN   "\x1b[32m"

	 #define VIOLET "\x1B[35m"
	#define BOLD "\x1B[1m"   // Séquence de contrôle ANSI pour le texte en gras
	#define PINK "\x1B[95;1m"   // Rose (Magenta vif en gras)
	#define BLUE "\x1B[94;1m"   // Bleu vif en gras
	#define GREEN "\x1B[92;1m"  // Vert vif en gras
	#define YELLOW "\x1B[93;1m" // Jaune vif en gras
	#define CYAN "\x1B[96;1m"   // Cyan vif en gras
	#define WHITE "\x1B[97;1m"  // Blanc vif en gras
	
	#define RED "\x1B[91;1m"    // Rouge vif en gras
	#define ORANGE "\x1B[38;5;208;1m" // Orange vif en gras
	
	#define BOLD "\x1B[1m"      // Texte gras
	#define RESET "\x1B[0m"     // Réinitialiser la couleur
	
	#define ANSI_COLOR_MAGENTA "\x1b[35m"
	#define ITALIC "\x1B[3m"  // Séquence de contrôle ANSI pour l'italique
	#define RESET "\x1B[0m"   // Réinitialiser la mise en forme
	
	//-------------------------------------------déclaration des variables---------------------------------------- 
	
	int animation;
	int t1[5], t2[5], score = 0;
	int number[5] = {0};
	char nom[30],nom1[30];
	int i, j, n, l,k,K;
	int malplacer = 0, bienplacer = 0;
	int position, tentative = 0;
	int test = 0;
	int *p3, *p2;
	int niveau;
	int input;
	int L;
	
	
/*-------------------------------AJOUTER LE SON -------------------------------------------------------------------------------------*/	
	
	void jouerNote(int frequence,int duree) {
	Beep(frequence,duree);
	Sleep(100);

}
	

	   // effacer l'écran
	void clear() {
	    #ifdef _WIN32
	        system("cls");
	    #else
	        system("clear");
	    #endif
	}
	 
	 
	 //dessiner animation-----------------------------------------------------------------------------------------------------------------------------
	 
	void draw_animation(int pourcentage) {
	        clear();
	        printf("\n\n\n\n\                                                     \033[37mLoading game:\n\n\n\n\n\n\n\n          \033[33m[");
	        for (int i = 0; i < pourcentage; i++) {
	            printf("\033[33m=");
	        }
	        for (int i = pourcentage; i < 100; i++) {
	            printf(" ");
	        }
	        printf("]\n\n\n                                                          \033[37m%d%%\n",pourcentage);
	        fflush(stdout);
	
	    }
	    
	    // retarder l'affichage ---------------------------------------------------------------------------------------------------------------------------
	void sleep_nanoseconds(int nanoseconds) {
	    struct timespec ts;
	    ts.tv_sec = 0;
	    ts.tv_nsec = nanoseconds;
	    nanosleep(&ts, NULL);
	
	}
	// la viteese et maniere d'affichage d'écriture-------------------------------------------------------------------------------------------------------------
	
	void typewriter(const char *string) {
	    int length = strlen(string);
	
	    for (int i = 0; i < length; i++) {
	        putchar(string[i]);
	        fflush(stdout);
	        sleep_nanoseconds(90000000);
	    }
	}
	 
/*------------------------------------------------------mode de chrgement--------------------------------------------------------------------------------------*/

	 
	void charger_game() {
	    for (int i = 0; i <= 100; i++) {
	    draw_animation(i);}
	    clear();
	    printf("\n\n\n\n\n\n\n\n\n\n                                              ");
	    typewriter("\033[37m<Game loaded successfully!>");
	    sleep_nanoseconds(90000000);
	    printf("\n\n\n\n\n\n\n");
	}
	
/*-----------------------------------------------fonction pour l'affichare les quelques caracteres comme é et aussi couleur-------------------------------------*/

	// FONCTION DES COULEURS :
	// #R: ROUGE / #B: BLEU /   #V: VERT /    #C: BLEU CIEL /    #W: BLANC/    #J: JAUNE/    #S: ROSE/   #G: GRIS/  #P: remplissage blue
	
	
	void asci_printf(char Chaine[]) {
	    int t,i,k;
	    t = strlen(Chaine);
	    i = 0;
	    while (i < t) {
	        if (Chaine[i] == '#' && Chaine[i + 1] == 'R') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	        else if (Chaine[i] == '#' && Chaine[i + 1] == 'B') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	        else if (Chaine[i] == '#' && Chaine[i + 1] == 'V') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	        else if (Chaine[i] == '#' && Chaine[i + 1] == 'C') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	        else if (Chaine[i] == '#' && Chaine[i + 1] == 'W') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	        else if (Chaine[i] == '#' && Chaine[i + 1] == 'G') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	        else if (Chaine[i] == '#' && Chaine[i + 1] == 'J') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	        else if (Chaine[i] == '#' && Chaine[i + 1] == 'S') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	        else if (Chaine[i] == '#' && Chaine[i + 1] == 'P') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 16);
	
	        if (Chaine[i] == '#') i += 2;
	        k = i;
	        while (Chaine[k] != '#' && k < t) {
	            if (Chaine[k] == '@') printf("%c", 130); // Codes ascii pour les caracteres speaciaux
	            else if (Chaine[k] == '%') printf("%c", 136);
	            else if (Chaine[k] == 'é') printf("%c", 138);
	            else if (Chaine[k] == '&') printf("%c", 220);
	            else if (Chaine[k] == '~') printf("%c", 178);
	            else if (Chaine[k] == '|') printf("%c", 3);
	            else printf("%c", Chaine[k]);
	            k++;
	        }
	        i = k;
	    }
	}
	
	
/*--------------------------------------------------------------gerer l'espace d'affichage------------------------------------------------------------------------*/



	void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
	
	
	
	
	// POUR l'affichage d'acceuil :-------------------------------------------------------------------------------------------------------------------
	
	
	
	void Welcome(int r){
		gotoXY(35, 8); 
		 typewriter("\033[33mDeveloppeurs : FATIMA EZZAHRA RAJI |  HASNA ZOUHRI | MERYEM LACHGAR \033[37m");
	    sleep_nanoseconds(90000000);
	    system("cls");
	    gotoXY(1, 5); 
	    asci_printf("#W La date d'aujourd'hui est :  #W");
	    asci_printf("#W");
	    // Pour afficher la date et l'heure avec une commande CMD
	    system(" Date /t  && Time /t ") ;
	    asci_printf("#J");
	    // Message d'acceuil Avec animation :
	    if(r==1) {
	        
	        printf("\t\t\t\t");
	        for ( animation = 0; animation < 50; animation++) {
	            printf("%c", 178);
	            Sleep(40);
	
	        }
	        printf("\n");
	        for ( animation = 0; animation < 6; animation++) {
	            if(animation!=3) {
	                printf("\t\t\t\t%c\t\t\t\t\t\t %c \n", 178,178);
	            }
	            else {
	               asci_printf("\t\t\t\t~           #J|||#J WELCOME TO THE GAME #J|||#J\t\t ~\n");
	                asci_printf("\t\t\t\t~\t            #JMASTER MIND #J\t\t ~\n");
	                Sleep(70);
	            }
	        }
	        printf("\t\t\t\t");
	        for ( animation = 0; animation < 50; animation++) {
	            printf("%c", 178);
	            Sleep(40);
	        }
	        printf("\n");
	    }
	    // Message d'acceuil Sans animation :
	    if(r==0) {
	        asci_printf("#V");
	        printf("\t\t\t\t");
	        for ( animation = 0; animation < 50; animation++) {
	            printf("%c", 178);
	
	        }
	        printf("\n");
	        for ( animation = 0; animation < 6; animation++) {
	            if(animation!=3) {
	                printf("\t\t\t\t%c\t\t\t\t\t\t %c \n", 178,178);
	            }
	            else {
	                asci_printf("\t\t\t\t~           #R|||#W WELCOME TO THE GAME #R|||#V\t\t ~\n");
	                asci_printf("\t\t\t\t~\t            #WMASTER MIND #V\t\t ~\n");
	            }
	        }
	        printf("\t\t\t\t");
	        for ( animation = 0; animation < 50; animation++) {
	            printf("%c", 178);
	        }
	        printf("\n");
	    }
	}
	
/*--------------------------------------------------LECTURE DES NOMS DES Joueurs--------------------------------------------------------------------------------*/
	
	void nom_joeur() {
	gotoXY(38,8);
	printf(ITALIC"Joueur 1 \n"RESET);
	gotoXY(40, 9);
    printf("Entrer votre nom : ");
    gotoXY(41, 11);
    scanf("%s", nom);
    gotoXY(42,13);
    printf(ITALIC"Joueur 2 \n"RESET);
    gotoXY(43, 14);
    printf("Entrer votre nom :  ");
    gotoXY(44,15 );
    printf("\n");
    gotoXY(44,16 );
    scanf("%s", nom1);
    gotoXY(45,18 );
    printf("\n");
     gotoXY(45,19 );
    printf(BOLD"%s \033[31mvs \033[37m %s\n"RESET, nom, nom1);
	}
	
	/*--------------------------------gérer les élémnts distinct aléatoires  par ordinateur entre 0 et 9----------------------------------------------------*/
	
	
	
	
	void detecterprogramme1(int *T, int n) {
	    for (int i = 0; i < n; i++) {
	        T[i] = rand() % 10; 
	        // Vérifie que le nombre n'est pas déjà présent dans le tableau
	        for (int j = 0; j < i; j++) {
	            if (T[j] == T[i]) {
	                // Si le nombre est déjà présent, génère un nouveau nombre
	                i--;
	                break;  }}}}
	                
	 //gérer les élémnts aléatoires  par ordinateur entre 0 et 9 pas necessaire les éléments distincts
	         
	void detecterprogramme2(int t1[5]) {
	    srand(time(NULL));
	
	    // Générer deux chiffres différents
	    int premierChiffre = rand() % 10;
	    int deuxiemeChiffre;
	
	    do {
	        deuxiemeChiffre = rand() % 10;
	    } while (deuxiemeChiffre == premierChiffre);
	
	    // Placer ces deux chiffres dans le tableau
	    t1[0] = premierChiffre;
	    t1[1] = deuxiemeChiffre;
	
	    // Générer les autres chiffres
	    for (int i = 2; i < 5; i++) {
	        // Il y a une probabilité de 1/2 d'ajouter un chiffre déjà existant pour assurer la répétition
	        if (rand() % 2 == 0) {
	            t1[i] = premierChiffre;
	        } else {
	            t1[i] = deuxiemeChiffre;
	        }}}
	        
	        
//------------------------------------------------------------------------------------------------------------------------------------------------------------	 
	 
	    //détecter si les élémnts d'un tableau entrer par utilisateur est distincte ou non si ditincts réecrire le tableau
		 
       	void detecter(int T[], int n) {
        for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
        if (T[i] == T[j]) {
        gotoXY(40, 21);
        asci_printf("Certains éléments ne sont pas distincts. Veuillez en saisir de nouveaux :\n");
		 // Saisie de nouveaux éléments
        for (int k = 0; k < n; k++) {
       	gotoXY(40+k, 22+k);
        printf(YELLOW"Saisir un nombre | %d| = "RESET, k + 1);
        scanf("%d", &T[k]);
                }
       // Recherche d'autres éléments identiques dans le nouveau tableau
                detecter(T, n);
                return; }}} }
                
                
                
  /*-------------------------------  FONCTION DE JOCKER  --------------------------------------------------------------------------------------*/      
                
      void jocker() {
  	        if ((tentative >= 9 && tentative <= 16) && (test == 0)) {
            printf(RED"Faites attention, vous avez une aide <joker> à partir de cette tentative.\n"RESET);
            puts("Voulez-vous utiliser un joker dans cette tentative ? (si oui tapez 1 si non taper enter )");
            scanf("%d", &n);
            if (n == 1) {
                printf(CYAN"...<<<Choisissez la position du nombre que vous voulez afficher >>>...\n"RESET);
                scanf("%d", &position);

                if (position < 1 || position > 5) {
                    puts("Position inexistante. Veuillez entrer une position entre 1 et 5.");
                } else {
                    printf("Le chiffre secret de votre position est :[%d]\n", t1[position - 1]);
                    test = 1;  // Marquer le joker comme utilisé
                    tentative = tentative + 3;
                }}}}              

  



//--------------------------------------------animation-pour-fin---------------------------------------------------------------------

    void AfficherBienJouer() {
    	printf(ANSI_COLOR_GREEN);
    gotoXY(30, 5);
    printf(" ____ ___ _____ _   _       _  ___  _   _ _____ ____    _ \n");
     gotoXY(30, 6);
    printf("| __ )_ _| ____| \\ | |     | |/ _ \\| | | | ____|  _ \\  | |\n");
     gotoXY(30, 7);
    printf("|  _ \\| ||  _| |  \\| |  _  | | | | | | | |  _| | |_) | | |\n");
     gotoXY(30, 8);
    printf("| |_) | || |___| |\\  | | |_| | |_| | |_| | |___|  _ <  |_|\n");
     gotoXY(30, 9);
    printf("|____/___|_____|_| \\_|  \\___/ \\___/ \\___/|_____|_| \\_\\ (_)\n");
     gotoXY(30, 10);
    printf(ANSI_COLOR_RESET); // Réinitialiser la couleur
	}
	
	
	void AfficherVousAvezPerdu() {
    	printf(ANSI_COLOR_RED);
    	gotoXY(30, 3);
    printf(" __     _____  _   _ ____       ___     _______ _____\n");
    gotoXY(30, 4);
    printf(" \\ \\   / / _ \\| | | / ___|     / \\ \\   / / ____|__  /\n");
    gotoXY(30, 5);
    printf("  \\ \\ / / | | | | | \\___ \\    / _ \\ \\ / /|  _|   / / \n");
    gotoXY(30, 7);
    printf("   \\ V /| |_| | |_| |___) |  / ___ \\ V / | |___ / /_ \n");
    gotoXY(30, 8);
    printf("  __\\_/ \\___/_\\___/|____/_ /_/   \\_\\_/  |_____/____|\n");
    gotoXY(30, 9);
    printf("|  _ \\| ____|  _ \\|  _ \\| | | | | |                 \n");
    gotoXY(30, 10);
    printf("| |_) |  _| | |_) | | | | | | | | |                 \n");
    gotoXY(30, 11);
    printf("|  __/| |___|  _ <| |_| | |_| | |_|                 \n");
    gotoXY(30, 12);
    printf("|_|   |_____|_| \\_\\____/ \\___/  (_)                  \n");
    gotoXY(30, 13);
    
    printf(ANSI_COLOR_RESET); // Réinitialiser la couleur
	}


/*----------------------------------------------------play son si joeur est ganier-------------------------------------------------------*/
void playSadMelody() {
    int melody[] = {392, 330, 294, 262, 220}; // Adjusted frequencies for a short sad melody
    int duration = 300; // Duration for each note

    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
        Beep(melody[i], duration);
        Sleep(100); // Pause between notes
    }
}

/*----------------------------------------------------play son si joeur est perdu-------------------------------------------------------*/
   void playHappyMelody() {
    int melody[] = {784, 880, 988, 784}; // Frequencies for a short and happy melody
    int duration = 300; // Duration for each note

    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
        Beep(melody[i], duration);
        Sleep(100); // Pause between notes
    }
}


/*----------------------------------------------------play son en debut------------------------------------------------------------------*/
void playGameStartMelody() {
    int melody[] = { 523, 587, 659, 698, 784, 880, 988, 1047 }; // Frequencies for a short and uplifting melody
    int duration = 300; // Duration for each note

    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
        Beep(melody[i], duration);
        Sleep(100); // Pause between notes
    }
}

/*---------------------------------la fonction pour niveau  1----------------------------------------*/

    void jeux(FILE *fp, FILE *fb, FILE *fl) {
    
    // une fonction pour gérer les éléments par ordinateur
    srand(time(NULL));
     
     gotoXY(40, 6);
    puts("Veuillez choisir avec qui vous allez jouer:\n ");
    gotoXY(41, 8);
    puts("1.Contre l'ordinateur\n");
    gotoXY(42, 10);
    puts("2. Contre un autre joueur\n");
    gotoXY(43, 11);
    printf("\n");
	gotoXY(43, 13);
    scanf("%d", &k);
    Sleep(1000);
    system("cls");

     game:
    if (k == 1) {
       gotoXY(41,13);
       printf(ITALIC"Joueur 2"RESET"\n");
       gotoXY(43,14);
       puts("entrer votre nom :");
       gotoXY(45,16);
    	scanf("%s",nom1);
    	system("cls");
        detecterprogramme1(t1, 5); // appeler la fonction pour saisir les élémnts par ordinateur  
    } else if (k == 2) {
        nom_joeur();
	    Sleep(1000);
	    system("cls");
	       gotoXY(40, 6);
	    typewriter("\033[33mJOUEUR 1 : \033[37m");
	    sleep_nanoseconds(90000000);
	    system("cls");
	    	gotoXY(40, 6);
	    // Saisie des éléments du t1
	    for (i = 0; i < 5; i++) {
	    	gotoXY(45+i, 11+i);
	        wrong7:
	           printf(YELLOW" Le nombre |%d| : "RESET, i + 1);
	
	            char c;
	            int input = 0;
	
	            while (1) {
	                c = _getch();  // Capturer le caractère sans l'afficher
	
	                if (c == '\r') {  // Si la touche Entrée est pressée, terminer la saisie
	                    break;
	                } else if (c >= '0' && c <= '9') {
	                    input = c - '0';
	                    gotoXY(70+i, 11+i);
	                    printf("*");  // Afficher un astérisque à la place du nombre
	                    break;
	                }
	            }
	
	            t1[i] = input;
	
	            if (t1[i] < 0 || t1[i] > 9) {
	                asci_printf("#R OOPS! r@entrer le nombre#W \n \a");
	                goto wrong7;
	            }
	
	            number[i] = t1[i];
	            printf("\n");
	            
	        }
	    } 
	   Sleep(1000);
        system("cls");
        detecter(t1, 5);
        Sleep(1000);
        system("cls");
         
         
          gotoXY(45, 8);
        typewriter("\033[33mJOUEUR 2 : \033[37m"); //achier jouer 2
	    sleep_nanoseconds(900000000);
	    printf("Devinez les chiffres :\n"); 
	    system("cls");
        while (tentative < 20 && bienplacer != 5) {
        bienplacer = 0;
        malplacer = 0;
        
	    gotoXY(45, 10);
        printf(CYAN"TENTATIVE <%d>:\n"RESET, tentative + 1);

        // Saisie des éléments du tableau 2
        for (j = 0; j < 5; j++) {
	        	gotoXY(40+j, 13+j);
	           wrong: 
	            asci_printf("#B");
	            printf(YELLOW" Le nombre |%d| :"RESET, j + 1);
	            asci_printf("#W");
	            while(scanf("%d", &t2[j]) != 1) {
	                asci_printf(" #R [ S'il vous plait donnez un nombre : ] #W \n \a");
	                while(getchar() != '\n');
	                goto wrong;
	            }
	            if (t2[j] < 0 || t2[j] > 9) {
	               asci_printf("#R OOPS! r@entrer le nombre#W \n \a");
	                goto wrong;
	            }
	        }
	         detecter(t2, 5);
	        
	        
	        

        // Comparaison des tableaux
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (t1[i] == t2[j] && i == j) {
                    bienplacer++;
                } else if (t1[i] == t2[j]) {
                    malplacer++;
                }
            }
        }

        // Affichage des résultats
        gotoXY(104, 13);
        printf("Bien places : %d\n", bienplacer);
        gotoXY(104, 15);
        printf("Mal places : %d\n", malplacer);
        Sleep(3000);
        system("cls");

        // Proposer l'aide du joker dans la tentative spécifiée et si le joker n'a pas déjà été utilisé
       
        jocker();
        tentative++;

        if (bienplacer != 5 && tentative == 20) {
			playSadMelody();
        		AfficherVousAvezPerdu();
        	gotoXY(30, 15);
            printf(ITALIC"\033[35m%s,\t \033[37m"RESET, nom1);
            gotoXY(30, 16);
            asci_printf("vous avez échoué ");
             printf("\n");
           gotoXY(30, 15);
            printf(ITALIC"\033[35m%s,\t \033[37m"RESET, nom1);
            gotoXY(36, 15);
            printf(", votre score est\t 0 \033[35m%d \033[37m\n"RESET);
            gotoXY(30, 16);
            printf("le nombre secret est :");
            gotoXY(30, 18);
            for (int i = 0; i < 5; i++) {
                printf("%d", t1[i]);
            }
            printf("\n");
        }
        if (bienplacer == 5) {
        	playHappyMelody();
  		
  		AfficherBienJouer();
        	gotoXY(30, 13);
            asci_printf("Vous avez d@chiffr@ le nombre secret!");
            printf("\n");
            gotoXY(30, 14);
            score = 100 - (5 * (tentative-1));
            gotoXY(30, 15);
            printf(ITALIC"\033[35m%s,\t \033[37m"RESET, nom1);
            gotoXY(36, 15);
            printf(", votre score est \t \033[35m%d \033[37m\n"RESET, score);
            gotoXY(30, 16);

            // Mettre à jour le score dans le fichier
            fprintf(fp, " %d\n", score);
            fprintf(fb, "%s \n", nom1);
            fprintf(fl, " %d\n", score);
        }
        
    }
}

/*------------------------------------fonction pour niveau 2-----------------------------------------------------------*/


	void jeux1(FILE *fp, FILE *fb, FILE *fl) {
		
	   srand(time(NULL));
	  gotoXY(40, 6);
	    printf("Veuillez choisir avec qui vous allez jouer:\n");
	    gotoXY(41, 8);
	    printf("1. Contre l'ordinateur\n");
	    gotoXY(42, 10);
	    printf("2. Contre un autre joueur\n");
	    gotoXY(43, 12);
	    printf("\n");
	   	gotoXY(43, 13);
	    scanf("%d", &K);
	    Sleep(1000);
	    system("cls");
	    
	   game:
	    if (K == 1) {
	    	 gotoXY(41,13);
       printf(ITALIC"Joueur 2"RESET"\n");
       gotoXY(43,14);
       puts("entrer votre nom :");
       gotoXY(45,16);
    	scanf("%s",nom1);
    	system("cls");
	        detecterprogramme2(t1);
	    } else if (K == 2) {
	    nom_joeur();
	    Sleep(1000);
	    system("cls");
	       gotoXY(40, 6);
	    typewriter("\033[33mJOUEUR 2 : \033[37m");
	    sleep_nanoseconds(90000000);
	    system("cls");
	    	gotoXY(40, 6);
	    // Saisie des éléments du t1
	    for (i = 0; i < 5; i++) {
	      gotoXY(40+i, 13+i);
	           wrong7:
	           printf(YELLOW" Le nombre |%d| : "RESET, i + 1);
	
	            char c;
	            int input = 0;
	
	            while (1) {
	                c = _getch();  // Capturer le nombre sans l'afficher
	
	                if (c == '\r') {  // Si la touche Entrée est pressée, terminer la saisie
	                    break;
	                } else if (c >= '0' && c <= '9') {
	                    input = c - '0';
	                    gotoXY(68+i, 13+i);
	                    printf("*");  // Afficher un astérisque à la place du nombre
	                    break;
	                }
	            }
	
	            t1[i] = input;
	
	            if (t1[i] < 0 || t1[i] > 9) {
	                asci_printf("#R OOPS! r@entrer le nombre#W \n \a");
	                goto wrong7;
	            }
	
	            number[i] = t1[i];
	            printf("\n");
	            
	        }
	    } 
		
		else { 
		gotoXY(40, 6);
	       asci_printf(" #R Option invalide! \n #W Veuillez choisir 1 ou 2. \n");
	        scanf("%c", &K);
	      goto game;
	    }  
		  Sleep(1000);
        system("cls");
        Sleep(1000);
        system("cls");
	    
	    // Boucle principale
	    gotoXY(40, 8);
	    typewriter("\033[33mJOUEUR 1 : \033[37m");
	    sleep_nanoseconds(90000000);
	    system("cls");
	    while (tentative < 20 && bienplacer != 5) {
	        bienplacer = 0;
	        malplacer = 0;
	
	        // Affichage du numéro de tentative
	        asci_printf("#C");
	        gotoXY(40, 10);
	        printf(CYAN" TENTATIVE <%d>:\n " RESET, tentative + 1);
	        asci_printf("#W");
	
	        // Saisie des JOUEUR 2
	        for (j = 0; j < 5; j++) {
	        	gotoXY(40+j, 13+j);
	           wrong: 
	            asci_printf("#B");
	            printf(YELLOW" Le nombre |%d| :"RESET, j + 1);
	            asci_printf("#W");
	            while(scanf("%d", &t2[j]) != 1) {
	                asci_printf(" #R [ S'il vous plait donnez un nombre : ] #W \n \a");
	                while(getchar() != '\n');
	                goto wrong;
	            }
	            if (t2[j] < 0 || t2[j] > 9) {
	               asci_printf("#R OOPS! r@entrer le nombre#W \n \a");
	                goto wrong;
	            }
	        }
	        // Comparaison des chiffres bien placés
	        for (i = 0; i < 5; i++) {
	            for (j = 0; j < 5; j++) {
	                if (number[i] == t2[j] && i == j) {
	                    bienplacer++;
	                    t2[j] = -1;      // Marquer les chiffres bien placés
	                    number[i] = -2;  // Marquer les chiffres utilisés du t1
	                    break;           // Sortir de la boucle interne dès qu'une correspondance est trouvée
	                }
	            }
	        }
	
	        // Comparaison des chiffres mal placés
	        for (i = 0; i < 5; i++) {
	            for (j = 0; j < 5; j++) {
	                if (i != j && number[i] == t2[j]) {
	                    malplacer++;
	                    t2[j] = -4;      // Marquer les chiffres mal placés
	                    number[i] = -3;  // Marquer les chiffres utilisés du t1
	                    break;           // Sortir de la boucle interne dès qu'une correspondance est trouvée
	                }
	            }
	        }
	
	        // Réinitialiser le tableau number avec les chiffres du t1 pour la prochaine itération
	        for (i = 0; i < 5; i++) {
	            number[i] = t1[i];
	        }
	
	          // Affichage des résultats
	          gotoXY(41, 20);
	        printf("Bien places : %d\n", bienplacer);
	        gotoXY(42, 22);
	        printf("Mal places : %d\n", malplacer);
	       Sleep(4000);
	        system("cls");
	
	        // Proposer l'aide du joker dans la plage spécifiée, si le joker n'a pas déjà été utilisé
	      jocker();
	        tentative++;
			
		if (bienplacer != 5 && tentative == 20) {
			playSadMelody();
        		AfficherVousAvezPerdu();
        	gotoXY(30, 15);
            printf(ITALIC"\033[35m%s,\t \033[37m"RESET, nom1);
            gotoXY(30, 16);
            asci_printf("vous avez échoué ");
             printf("\n");
           gotoXY(30, 15);
            printf(ITALIC"\033[35m%s,\t \033[37m"RESET, nom1);
            gotoXY(36, 15);
            printf(", votre score est\t \033[35m 0 \033[37m\n"RESET);
            gotoXY(30, 16);
            printf("le nombre secret est :");
            gotoXY(30, 18);
            for (int i = 0; i < 5; i++) {
                printf("%d", t1[i]);
            }
            printf("\n");
        }

        if (bienplacer == 5) {
        	playHappyMelody();
        	AfficherBienJouer();
        gotoXY(30, 13);
            asci_printf("Vous avez d@chiffr@ le nombre secret!");
            printf("\n");
            gotoXY(30, 14);
            score = 100 - (5 * (tentative-1));
            gotoXY(30, 15);
            printf(ITALIC"\033[35m%s,\t \033[37m"RESET, nom1);
            gotoXY(36, 15);
            printf(", votre score est\t \033[35m%d \033[37m\n"RESET, score);
            gotoXY(30, 16);

            // Mettre à jour le score dans le fichier
            fprintf(fp, " %d\n", score);
            fprintf(fb, "%s \n", nom1);
            fprintf(fl, " %d\n", score);
        }}}
	
	
/*---------------------------------------------LES REGLE ET MENU---------------------------------------------------------*/	
	void GUIDE() {
		
		printf("\033[33m...<<< BIENVENUE AU MasterMind >>>...\n" );
		puts("---------------------------------------------------------------------");
		printf("\033[37m");
		asci_printf("- le jeux master-mind consiste a trouver un chiffre secret compos@ de 5 chiffres entre 0 et 9 dans 20 tentatives\n");
		asci_printf("- vous avez 2 choix, soit jouer avec un joueur ou ordinateur\n ");
		asci_printf("- vous avez le droit @galement d'utiliser un jocker (aide) a partir de tentative 10\n ");
		asci_printf("-ce jocker permet d'afficher un chiffre de vos choix\n");
		asci_printf("\033[31mattention! \033[37m\n");
		asci_printf("-utilisation du jocker vous expirer 3 tentatives en totale \n");
		asci_printf("-nous presentons egalement 2 niveaux (debutant et expert) \n");
		printf(">>> debutant \n");
		printf("dans ce niveau vous devez entrer les nommbres distincts \n");
		printf(">>> expert \n");
		printf("dans ce niveau vous avez le droit d'entrer les nombres repetes \n");
		asci_printf("-votre score depends de nombre de tentatives ou vous aurez trouv@ le code secret!");
        asci_printf("Plus vite vous trouvez le code secret,plus votre score est @lev@");
        printf("\033[33m");
		
		
	}
	
/*--------------------------------------STOCKER-NON-et score-dans des fichier-----------------------------------------*/

	void GestionFichier() {
	    FILE *fp;
	    fp = fopen("masterrMind.txt", "a");
	
	    if (fp == NULL) {
	        printf("Erreur d'ouverture du fichier masterrMind.txt");
	        return;
	    }
	
	    FILE *fb;
	    fb = fopen("masterrMind2.txt", "a");
	
	    if (fb == NULL) {
	        printf("Erreur d'ouverture du fichier masterrMind2.txt");
	        fclose(fp);
	        return;
	    }
	
	    FILE *fl;
	    fl = fopen("master.txt", "a");
	
	    if (fl == NULL) {
	        printf("Erreur d'ouverture du fichier master.txt");
	        fclose(fp);
	        fclose(fb);
	        return;
	    }
	    //choisi niveau
	    gotoXY(40, 6);
	   	printf(ITALIC"choisi niveau "RESET);
	   	printf("\n");
	   	gotoXY(41, 8);
	   	asci_printf("#G 1 -----> d@butant \n");
	   	gotoXY(42, 10);
	   	asci_printf("#G 2 -----> exp@rt \n");
	   	asci_printf("#w");
	   	gotoXY(43, 11);
	   	printf("\n");
	   	gotoXY(43, 12);
	   	scanf("%d",&niveau);
	   	Sleep(1000);
	   	system("cls");
	   	if (niveau==1) {
	        gotoXY(40, 6);
	   	jeux(fp, fb, fl); //appeler niveau 1
		   }
		else if (niveau==2) {
			gotoXY(40, 6);
		jeux1(fp, fb, fl); //appeler niveau 2
		}
	
	
	
	    // Fermer les fichiers
	    fclose(fp);
	    fclose(fb);
	    fclose(fl);
	}
/*---------------------------------------------fonction pour best score---------------------------------------------------*/	
	void bestscore(){
	    FILE *fl;
	    fl = fopen("master.txt", "r");
	    if (fl == NULL) {
	        printf("Erreur d'ouverture du fichier");
	        return;
	    }
	
	    // Lire les caractères du fichier et les stocker dans un tableau
	    int numbers[100];  // Vous pouvez ajuster la taille selon vos besoins
	    int i = 0;
	    int num;
	
	    while (fscanf(fl, "%d", &num) == 1) {
	        numbers[i] = num;
	        i++;
	    }
	
	    // Fermer le fichier
	    fclose(fl);
	
	    // Si le fichier est vide, afficher un message approprié
	    if (i == 0) {
	        printf("Le fichier est vide. Aucun score disponible.\n");
	        return;
	    }
	
	    // Déterminer le maximum et le minimum
	    int max_value = numbers[0];
	    int min_value = numbers[0];
	
	    for (int j = 1; j < i; j++) {
	        if (numbers[j] > max_value) {
	            max_value = numbers[j];
	        }
	        if (numbers[j] < min_value) {
	            min_value = numbers[j];
	        }
	    }
	
	    // Afficher les résultats
	    	
         gotoXY(35, 22);
	          printf("\033[33m\nbest score  : %d\n", max_value);
	          printf("\033[37m");
	     gotoXY(30, 23);
		}
	    
	    
	    
	
	  int main() {
	  	playGameStartMelody();
		charger_game();
		Sleep(1000);
		system("cls");
		
		Welcome(1);
		system("cls");
		
	   do { 
	    do { 
	        gotoXY(40, 15); 
	        printf("  QUE VOULEZ-VOUS FAIRE :\n");
	        gotoXY(41, 17); 
	        printf("1 ------> Jouer\n");
	        gotoXY(41, 19); 
	        printf("2 ------> Menu\n");
	        gotoXY(41, 21); 
	        printf("3 ------> Quitter\n");
	        gotoXY(41, 23); 
	        scanf("%d", &n);
	        Sleep(800);
	        system("cls");
	
	        switch (n) {
	            case 1:
	            	
	                GestionFichier();
	                 gotoXY(35, 20);
	                bestscore();
	                break;
	
	            case 2:
	            	
	                GUIDE();  // Appeler la fonction menu pour revenir au menu principal
	                break;
	
	            case 3:
	            	
	            	printf("Merci d'avoir utilise le programme. !\n");
	                    exit(0);  // Quitter le programme proprement
	                
	                break;
	
	            default:
	            	
	                printf("Choix invalide. Veuillez saisir à nouveau.\n");
	        }
	    } while (n != 3 &&  n!=1);  // Répéter tant que l'utilisateur ne choisit pas de quitter (option 3)
	    
	    
	        
	         
	        printf("Voulez-vous jouer a nouveau ? (1 pour Oui, 0 pour Non) : ");
	        scanf("%d", &l);
	        system("cls");
	
	        tentative = 0;
	        test = 0;
	        bienplacer = 0;
	        malplacer = 0;
	    } while (l == 1);
	    
	    
	    return 0;
	}
/*-----------------------------------------------------end-------------------------------------------------------------------------------------------*/	

