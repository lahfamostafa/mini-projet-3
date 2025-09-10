#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void print_face (int expression){
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t ___________\n");
    switch(expression) {
        case 1: // Happy
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t|  ^     ^  |\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t|   \\___/   |\n");
            break;
        case 2: // Sad
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t|  -     -  |\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t|    / \\    |\n");
            break;
        case 3: // Question
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t|  ?     ?  |??\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t|    ___    |\n");
            break;
        case 4: // Neutral
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t|  -     -  |\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t|    ___    |\n");
            break;
        default: // welcome
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t|  °     -  |\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t|    ___    |\n");
            break;
    }
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t -----------\n");


}


int main()
{
    char *positif[]={"happy", "good", "great", "fantastic", "awesome",
                    "love", "excellent", "nice", "wonderful", "amazing"};

    char *negatif[]={"sad", "bad", "terrible", "horrible", "awful",
                    "hate", "worst", "angry", "pain", "disappointing"};

    char *neutre[]={"ok", "fine", "average", "normal", "usual",
                    "medium", "passable", "so-so", "fair", "regular"};

    char *welcome[]={"hello","hi","good morning","good night"};

    char phrasesP [20][200] = {"I'm really happy for you." , "I'm so glad to hear that everything is going well." , "That's fantastic!" ,
                            "Wow, that's amazing!","It's great to see you so happy and motivated."};

    char phrasesN [20][200] = {"I hope things get better soon.","Oh no, that's really unfortunate. Let me know if I can help.",
                            "I understand how difficult this must be for you. Stay strong.","That's really disappointing.",
                            "I feel bad that you had to go through that. It's not easy."};

    char phrasesNeu [20][200] = {"Okay, I see what you mean. Thanks for letting me know.","Alright, I understand. Let's move on from here.",
                                "That makes sense. Thanks for explaining it to me.","I hear you. It's good to know how things are.",
                                "Fair enough, I get your point. Let's keep going."};

    char phrasesW [20][200] = { "Welcome!","Hello and welcome!","A warm welcome to you.","It’s great to have you here.","Welcome back!",
                                "So happy to have you with us today!"};
    //char *tabRand[];
    char phrase[200];
    char *mot;
    char *tabMots[20];
    int i,j,repondu,index,compteur ;


    srand(time(NULL));

    printf("\t\t\t\t\t\t=======================================\n\n");
    printf("\t\t\t\t\t\t  W E L C O M E   T O   C H A T  B O T\n\n");
    printf("\t\t\t\t\t\t=======================================\n\n");

    while(1){
        compteur = 0;

        printf("You : ");
        fgets(phrase,sizeof(phrase),stdin);
        phrase[strcspn(phrase,"\n")]= '\0'; //pour enleve le \n

        if(strcmp(phrase, "exit")==0){
            printf("Good bey ! \n");
            break;
        }
        mot = strtok(phrase , " "); // pour decouper la frase en mots

        while(mot != NULL && compteur < 20){
            tabMots[compteur++] = mot;
            mot = strtok(NULL," ");
        }
        repondu = 0;

        for (i = 0 ; i < compteur ; i++){
            for(j = 0 ; j < 10 ; j++){
                if(strcmp(tabMots[i],positif[j])==0){
                    index = rand()%5;
                    printf("Bot : %s\n\n",phrasesP[index]);
                    print_face(1);
                    repondu = 1;
                    break;
                }
            }

            for(j = 0 ; j < 4 ; j++){
                if(strcmp(tabMots[i],welcome[j])==0){
                    index = rand()%6;
                    printf("Bot : %s\n\n",phrasesW[index]);
                    print_face(5);
                    repondu = 1;
                    break;
                }
            }

            for(j = 0 ; j < 10 ; j++){
                if(strcmp(tabMots[i],neutre[j])==0){
                    index = rand()%5;
                    printf("Bot : %s\n\n",phrasesNeu[index]);
                    print_face(4);
                    repondu = 1;
                    break;
                }
            }

            for(j = 0 ; j < 10 ; j++){
                if(strcmp(tabMots[i],negatif[j])==0){
                    index = rand()%5;
                    printf("Bot : %s\n\n",phrasesN[index]);
                    print_face(2);
                    repondu = 1;
                    break;
                }
            }
                if(repondu)
                    break;


            }
            if(!repondu){
                    printf("Bot : I don't know how to respond to that.\n\n");
                    print_face(3);
                }
        }

    return 0;
}
