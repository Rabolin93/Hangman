#include <stdio.h>
#include <string.h>
int main()
{
    //MENU GLOWNE
    int jezyk=0;
    int menu1=0;
    printf("                   HANGMAN\n \n \n");
    printf("Please select your language\n Polski - wcisnij 1 \n English - press 2\n Deutsch - drücken Sie  3\n");
    scanf("%d", &jezyk);
    while(jezyk!=1 && jezyk!=2 && jezyk!=3)
    {
        printf("Something went wrong, Please pick Your number again\n");
        scanf("%d", &jezyk);
        printf("\n");
    }







    if(jezyk==1) // JEZYK POLSKI
    {
        //MENU

        printf("Witaj w grze ""Wiselec"" \n");
        printf("Wpisz numer z listy i wcisnij klawisz ""Enter"" aby kontynuowac\n");
        printf("1- Instrukcja\n");
        printf("2- Gra\n");
        scanf("%d", &menu1);
        printf("\n");
        while(menu1==1)
        {
        printf("\n");
        printf("Wisielec  – gra polegająca na odgadywaniu słów. Gracz stara się odgadnąć litery słowa losowo wybranego przez program.\n Za każdym razem, gdy mu się to uda, program wstawia literę w odpowiednie miejsce; w przeciwnym wypadku program dodaje +1 do liczby popelnionych bledow.\n Jezeli gracz odgadnie haslo zanim liczba bledow wyniesie 5 wygrywa.\n");
        printf("Wcisnij ""Enter"" aby kontynuowac\n\n");
        
        getchar();
        getchar();

        printf("Witaj w grze ""Wiselec"" \n");
        printf("Wpisz numer z listy i wcisnij klawisz ""Enter"" aby kontynuowac\n");
        printf("1- Instrukcja\n");
        printf("2- Gra\n");
        scanf("%d", &menu1);
        }



        //GRA (prototyp)
        char slowo[100]={0};
        char zakslowo[100]={0};
        int zakliter=0;
        int lliter=0;
        int lbledow=0;
        char literka=0;
        int i=0;
        int n=0;
        int bb=0;
        int plliter=0;
        scanf("%99s", slowo);
        getchar();

        lliter=strlen(slowo);
        plliter=lliter;
        while(zakliter!=lliter)
        {  
            zakslowo[zakliter]='x';
            zakliter++;
        }
        
        printf("Liczba liter slowa do odgadniecia- %d\n", lliter );

        while(lliter!=0 || lbledow!=5)
        {
            if(lbledow==5)
            {
                printf("Niestety! Maksymalna liczba bledow :( Koniec gry.");
                return 0;
            }
            printf("Slowo do odgadniecia -%s \n", zakslowo);
        printf("Podaj literke! \n");
        scanf("%c", &literka);
        getchar();
                while(n!=lliter) // PETLA SPRAWDZAJACA CZY DANA LITERKA JUZ WYSTEPOWALA
                {
                    while(literka==zakslowo[n])
                    {
                     printf("You've already chosen that letter! Pick another one!");
                    scanf("%c", &literka);
                    getchar();
                    }
                n++;
                }
         n=0;
        //TERAZ PETLA KTORA SPRAWDZA CZY LITERKA JEST W TABELI
            while(i!=plliter)
            {
                if(slowo[i]==literka)
                {
                    zakslowo[i]=literka;
                    bb++;
                    lliter--;
                }
                i++;
            }
            if(bb==0)
            {
                lbledow++;
                printf("Blad! Liczba bledow=%d\n", lbledow);
            }
        i=0;
        bb=0;

              if(lliter==0)
        {
            printf("Brawo! Wygrales/Wygralas!\n Koniec gry :)");
            return 0;
        }


        }
  
    }



    if(jezyk==2) // JEZYK ANGIELSKI
    {// MENU
        printf("Welcome to ""The Hangman"" game \n");
        printf("Select a number and press the ""Enter"" key to continue\n");
        printf("1- Instructions\n");
        printf("2- Game\n");
        scanf("%d", &menu1);
        printf("\n");
        while(menu1==1)
        {
        printf("\n");
        printf("The Hangman is a simple game about guessing words. The player tries to guess the word randomly selected by the computer.\n Each time he or she guesses correctly, the game replaces the ""x"" symbol with a proper letter; otherwise, the game adds 1 point to mistake counter.\n If the player guesses the whole word before the mistake counter hits 5- he or she wins the game.\n");
        printf("Press ""Enter"" key to continue\n\n");
        
        getchar();
        getchar();

        printf("Welcome to ""The Hangman"" game \n");
        printf("Select a number and press the ""Enter"" key to continue\n");
        printf("1- Instructions\n");
        printf("2- Game\n");
        scanf("%d", &menu1);
        }


        //GRA (prototyp)
        char slowo[100]={0};
        char zakslowo[100]={0};
        char tliterka[100]={0};
        int zakliter=0;
        int lliter=0;
        int lbledow=0;
        char literka=0;
        int i=0;
        int n=0;
        int bb=0;
        int plliter=0;
        scanf("%99s", slowo);
        getchar();

        lliter=strlen(slowo);
        plliter=lliter;
        while(zakliter!=lliter)
        {  
            zakslowo[zakliter]='x';
            zakliter++;
        }
        
        printf("Number of letters to left to guess- %d\n", lliter );

        while(lliter!=0 || lbledow!=5)
        {
            if(lbledow==5)
            {
                printf("Sorry! You've made too many mistakes :( Game over!");
                return 0;
            }
            printf("The word -%s \n", zakslowo);
        printf("Pick a letter! \n");
        scanf("%c", &literka);
        getchar();
        while(n!=lliter) // PETLA SPRAWDZAJACA CZY DANA LITERKA JUZ WYSTEPOWALA
        {
            while(literka==zakslowo[n])
            {
                printf("You've already chosen that letter! Pick another one!");
                scanf("%c", &literka);
                getchar();
            }
            n++;
        }
        n=0;
        
        //TERAZ PETLA KTORA SPRAWDZA CZY LITERKA JEST W TABELI
            while(i!=plliter)
            {
                if(slowo[i]==literka)
                {
                    zakslowo[i]=literka;
                    bb++;
                    lliter--;
                }
                i++;
            }
            if(bb==0)
            {
                lbledow++;
                printf("Mistake! Mistake counter=%d\n", lbledow);
            }
        i=0;
        bb=0;

              if(lliter==0)
        {
            printf("Congrats! The mystery word is  -- %s -- You've won!:)", zakslowo);
            return 0;
        }


        }
  
    }

}