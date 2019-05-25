#include "Skocko.h"

void meni()
{
    int izbor;
    char *k, kombinacija[4];

    printf("\n\n------------------ MasterMind ------------------\n");
    printf("\n1. Generisanje nasumicne kombinacije");
    printf("\n2. Pogadjanje kombinacije");
    printf("\n3. Kraj igre\n");
    printf("\nVas izbor\n>> ");
    scanf("%d", &izbor);

    switch(izbor)
    {
    case 1:
        k = generisiKombinaciju();
        int i;
        for(i = 0; i < 4; i++)
            kombinacija[i] = k[i];
        break;
    case 2:
        if(generisano[0] == 'N')
        {
            printf("\n----------------- Kombinacija se mora prvo generisati! ---------------\n");
            break;
        }
        else
            // kombinacija = generisiKombinaciju();
            pogadjanjeKombinacije(kombinacija);
        break;
    case 3:
        exit(0);

    default:
        printf("\nNEVALIDNA OPCIJA!");
    }
}

char *generisiKombinaciju()
{
    int i, genIndeks;

    srand(time(NULL));

    printf("\n------------------ KOMBINACIJA SE GENERISE ------------------\n");
    printf("\n.............................................................\n");

    for(i = 0; i < 4; i++)
    {
        genIndeks = rand() % 6;
        generisano[i] = moguce[genIndeks];
    }

    printf("\n------------------ KOMBINACIJA GENERISANA ------------------\n");

    return generisano;
}

void pogadjanjeKombinacije(char *kombinacija)
{
    int preostaliPokusaji = 6;
    char K[4], R[4];

    printf("\n------------------ Pogadjanje kombinacije ------------------\n");
    printf("\n\n------------------ Agenda pododataka -----------------------\n");
    printf("\n   P - Pogodjeno\tN - Nije pogodjeno\tO - Omaseno mesto\n\n");
    printf("\n\n-------------------- Moguci unosi ------------------------\n");
    printf("\n   T - Tref\tK - Karo\tH - Herc");
    printf("\n   P - Pik\tZ - Zvezda\tS - Skocko\n\n");


    do
    {
        printf("\n\nUnos kombinacije\n>> ");
        scanf(" %c", &K[0]);
        scanf(" %c", &K[1]);
        scanf(" %c", &K[2]);
        scanf(" %c", &K[3]);

        // SVE U VELIKA SLOVA
        K[0] = toupper(K[0]);
        K[1] = toupper(K[1]);
        K[2] = toupper(K[2]);
        K[3] = toupper(K[3]);

        /// Skočko Karo Pik Tref
        /// Pik Karo Karo Zvezda -> N O N N

        /// provera kombinacije
        /// PRVI ZNAK
        if(K[0] == kombinacija[0])
            R[0] = 'P';
        else if(K[0] == kombinacija[1] || K[0] == kombinacija[2]
                 || K[0] == kombinacija[3])
            R[0] = 'O'; // postoji ali nije na pravom mestu
        else
            R[0] = 'N';

        /// DRUGI ZNAK
        if(K[1] == kombinacija[1])
            R[1] = 'P';
        else if(K[1] == kombinacija[0] || K[1] == kombinacija[2]
                 || K[1] == kombinacija[3])
            R[1] = 'O'; // postoji ali nije na pravom mestu
        else
            R[1] = 'N';

        /// TRECI ZNAK
        if(K[2] == kombinacija[2])
            R[2] = 'P';
        else if(K[2] == kombinacija[0] || K[2] == kombinacija[1]
                 || K[2] == kombinacija[3])
            R[2] = 'O'; // postoji ali nije na pravom mestu
        else
            R[2] = 'N';

        /// CETVRTI ZNAK
        if(K[3] == kombinacija[3])
            R[3] = 'P';
        else if(K[3] == kombinacija[1] || K[3] == kombinacija[2]
                 || K[3] == kombinacija[2])
            R[3] = 'O'; // postoji ali nije na pravom mestu
        else
            R[3] = 'N';

        printf("\nRezultat: | %c | | %c | | %c | | %c |\n", R[0], R[1], R[2], R[3]);
        printf("Preostali pokusaji: %d\n", preostaliPokusaji);
        preostaliPokusaji--;

        if(R[0] == 'P' && R[1] == 'P' && R[2] == 'P' && R[3] == 'P') {
            printf("\nPOGODILI STE KOMBINACIJU!\n");
            return;
        }
    }
    while(preostaliPokusaji >= 1);   // stavi na 1 znaci 6 pokusaja

    printf("\n------------------------ Generisana kombinacija ------------------------\n");
    printf("%c %c %c %c", generisano[0], generisano[1], generisano[2], generisano[3]);

}
