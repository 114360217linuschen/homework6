/* Fig. 10.3: fig10_03.c
   The card shuffling and dealing program using structures */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

   /* card structure definition */
struct card {
    const char* face;   /* pointer to face string  */
    const char* suit;   /* pointer to suit string  */
}; /* end struct card */

typedef struct card Card;    /* new type name for struct card */

/* function prototypes */
void fillDeck(Card* const wDeck,
    const char* wFace[],
    const char* wSuit[]);
void shuffle(Card* const wDeck);
void deal(const Card* const wDeck);

int main(void)
{
    Card deck[52];   /* define array of 52 Cards */

    /* initialize array of pointers to face strings */
    const char* face[] = { "Ace", "Deuce", "Three", "Four", "Five",
                           "Six", "Seven", "Eight", "Nine", "Ten",
                           "Jack", "Queen", "King" };

    /* initialize array of pointers to suit strings */
    const char* suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

    srand((unsigned)time(NULL));  /* randomize */

    fillDeck(deck, face, suit);    /* load the deck with Cards   */
    shuffle(deck);                 /* put Cards in random order  */
    deal(deck);                    /* deal all 52 Cards          */

    return 0;   /* indicates successful termination */
}

/* place strings into Card structures */
void fillDeck(Card* const wDeck,
    const char* wFace[],
    const char* wSuit[])
{
    int i;   /* counter */

    /* loop through wDeck */
    for (i = 0; i <= 51; i++) {
        wDeck[i].face = wFace[i % 13];
        wDeck[i].suit = wSuit[i / 13];
    }
} /* end function fillDeck */

/* shuffle cards */
void shuffle(Card* const wDeck)
{
    int i;       /* counter */
    int j;       /* variable to hold random value between 0-51 */
    Card temp;   /* temporary structure for swapping Cards */

    /* loop through wDeck randomly swapping Cards */
    for (i = 0; i <= 51; i++) {
        j = rand() % 52;

        temp = wDeck[i];
        wDeck[i] = wDeck[j];
        wDeck[j] = temp;
    }
} /* end function shuffle */

/* deal cards */
void deal(const Card* const wDeck)
{
    int i;   /* counter */

    /* loop through wDeck */
    for (i = 0; i <= 51; i++) {
        printf("%5s of %-8s", wDeck[i].face, wDeck[i].suit);

        /* 每列顯示 4 張牌 */
        if ((i + 1) % 4 == 0)
            printf("\n");
        else
            printf("\t");
    }
} /* end function deal */
