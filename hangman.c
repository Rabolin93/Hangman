#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void szubienica(int bledy)
{
//SZUBIENICA PROTOTYP
    if(bledy==1)
    {
    printf("__________\n");
    printf("|        |\n");
    printf("¯¯¯¯¯¯¯¯¯¯");
    }

    if(bledy==2)
{
    printf("     |     \n");
    printf("     |     \n");
    printf("     |     \n");
    printf("     |     \n");
    printf("     |     \n");
    printf("__________\n");
    printf("|        |\n");
    printf("¯¯¯¯¯¯¯¯¯¯");
}
    if(bledy==3)
    {
    printf("      ______\n");
    printf("     |     |\n");
    printf("     |     |\n");
    printf("     |     \n");
    printf("     |     \n");
    printf("     |     \n");
    printf("__________\n");
    printf("|        |\n");
    printf("¯¯¯¯¯¯¯¯¯¯");
    }
        if(bledy==4)
    {
    printf("      ______\n");
    printf("     |     |\n");
    printf("     |     |\n");
    printf("     |    (¯)\n");
    printf("     |     \n");
    printf("     |     \n");
    printf("__________\n");
    printf("|        |\n");
    printf("¯¯¯¯¯¯¯¯¯¯");
    }
        if(bledy==5)
    {
    printf("      ______\n");
    printf("     |     |\n");
    printf("     |     |\n");
    printf("     |    (¯)\n");
    printf("     |     |\n");
    printf("     |    / \\ \n");
    printf("__________\n");
    printf("|        |\n");
    printf("¯¯¯¯¯¯¯¯¯¯");

    }
}




int main()
{
    //MENU GLOWNE
    int jezyk=0;
    int menu1=0;
    printf("                   HANGMAN\n \n \n");
    printf("Please select your language - pick a number and press ""enter""\n Polski - wcisnij 1 \n English - press 2\n Deutsch - drücken Sie  3\n\n\n\n");
    scanf("%d", &jezyk);
    while(jezyk!=1 && jezyk!=2 && jezyk!=3)
    {
        printf("Something went wrong, Please pick Your number again\n");
        scanf("%d", &jezyk);
        printf("\n\n\n");
    }







    if(jezyk==1) // JEZYK POLSKI
    {
        //MENU

        printf("Witaj w grze ""Wiselec"" \n");
        printf("Wpisz numer z listy i wcisnij klawisz ""Enter"" aby kontynuowac\n\n");
        printf("1- Instrukcja\n");
        printf("2- Gra\n");
        scanf("%d", &menu1);
        printf("\n");
   while(menu1!=1 && menu1!=2)
        {
            printf("Zla opcja, prosze wybierz numer z listy\n");
            scanf("%d", &menu1);
       
            
        }

        while(menu1==1)
        {
        printf("\n");
        printf("Wisielec  – gra polegająca na odgadywaniu słów. Gracz stara się odgadnąć litery słowa losowo wybranego przez program.\n Za każdym razem, gdy mu się to uda, program wstawia literę w odpowiednie miejsce; w przeciwnym wypadku program dodaje +1 do liczby popelnionych bledow.\n Jezeli gracz odgadnie haslo zanim liczba bledow wyniesie 5 wygrywa.\n Wszystkie slowa skladaja sie z wylacznie malych liter.\n Dostepne sa 2 kola ratunkowe - aby je wybrac wpisz odpowiadajacy mu numer \n Kolo 1 - zmniejsza liczbe popelnionych bledow o 1. \n Kolo 2 - Wyswietla pierwsza literke slowa (jezeli literka sie powtarza, wyswietla kazde jej powtorzenie)\n");
        printf("Wcisnij ""Enter"" aby kontynuowac\n\n");
        
        getchar();
        getchar();

        printf("Witaj w grze ""Wiselec"" \n");
        printf("Wpisz numer z listy i wcisnij klawisz ""Enter"" aby kontynuowac\n");
        printf("1- Instrukcja\n");
        printf("2- Gra\n");
        scanf("%d", &menu1);
        }
        printf("\n\n\n\n\n\n");
     

        if(menu1==2)
{       


        //GRA (prototyp)
        int kategoria=0; // do wyboru kategorii;
        char slowo[100]={0}; // tablica z losowanym slowem
        char zakslowo[100]={0}; // wylosowane slowo po zakodowaniu
        int zakliter=0; // liczba liter ktore sa zakodowane
        int lliter=0; // liczba liter pozostalych do odgadniecia
        int lbledow=0; // liczba bledow wykonanych przez gracza
        char literka=0; // literka ktora bedzie wpisywal gracz
        int i=0; // indeks
        int n=0; // indeks
        int bb=0; // bb=0 jezeli nie bylo bledu, bb = 1 jezeli byl blad
        int plliter=0; // pierwotna liczba liter
        int kolo1=0; // kolo1= 0 - kolo 1 niewykorzystane / 1 = wykorzystane
        int kolo2=0; // kolo2= 0 kolo 2 niewykorzystane / 2 = wykorzystane
        char darmowaliterka; // po wybraniu kola 2 darmowaliterka = pierwsza litera, nastepnie nastepuje sprawdzenie czy literka sie nie powtarza.

        printf("Wybierz kategorie!\n");
        printf("Kategorie:\n 1-Zwierzeta\n 2-Przedmioty uzytku codziennego \n\n\n\n\n");
        scanf("%d", &kategoria);

         
            // otwarcie pliku z kategoria 1
        if(kategoria==1)
        {
        FILE* fp=NULL; 
        char words[100]; 
        int w=0, ran=0;
        srand(time(NULL));
        fp = fopen("zwierzeta.txt", "r+");
        for(; fgets(words,sizeof(words), fp);w++)
        ;
        ran = rand() % w;
        rewind(fp);
        for(w=0; w<ran ;w++)
            fgets(words , sizeof(words), fp);

        for(int y=0; y<100; y++)
        slowo[y]=words[y];
        fclose(fp);
        getchar();
        }
        // otwarcie pliku z kategoria 2
        if(kategoria==2)
        {
        FILE* fp=NULL; 
        char words[100]; 
        int w=0, ran=0;
        srand(time(NULL));
        fp = fopen("przedmioty.txt", "r+");
        for(; fgets(words,sizeof(words), fp);w++)
        ;
        ran = rand() % w;
        rewind(fp);
        for(w=0; w<ran ;w++)
            fgets(words , sizeof(words), fp);

        for(int y=0; y<100; y++)
        slowo[y]=words[y];
        fclose(fp);
        getchar();
        }
        else
        {
            while(kategoria!=1 && kategoria!=2)
            {
            printf("Zle wybrana kategoria, prosze wybierz z dostepnych opcji\n");
            printf("Kategorie:\n 1-Zwierzeta\n 2-Przedmioty uzytku codziennego \n");
            scanf("%d", &kategoria);
            }
        }


        

        lliter=strlen(slowo)-1;
        plliter=lliter;
        while(zakliter!=lliter)
        {  
            zakslowo[zakliter]='?';
            zakliter++;
        }
        
        printf("Liczba liter slowa do odgadniecia %d \n", lliter );

        while(lliter!=0 || lbledow!=5)
        {
            if(lbledow==5)
            {
                printf("Niestety! Maksymalna liczba bledow :( Poszukiwane slowo to - %s . Koniec gry.", slowo);
                return 0;
            }
            printf("Slowo do odgadniecia %s \n", zakslowo);
        printf("Podaj literke! \n");
        literka=0;
        scanf("%c", &literka);
        getchar();


        if(literka=='1') // kolo ratunkowe 1- zmniejsza liczbe bledow o 1
        {
            if(kolo1==0)
            {
                printf("Korzystasz z kola ratunkowego 1 ! Dodatkowa szansa! Liczba bledow to %d \n\n", lbledow);
                lbledow--;
                kolo1++;
            }
            else
            {
                printf("Przykro mi, juz wykorzystales kolo ratunkowe :( \n \n \n \n");
            }

        }
          if(literka=='2') // kolo ratunkowe 2- odkrywa pierwsza literke (jesli sie powtarza to odkrywa wszystkie te literki w slowie)
        {
            if(kolo2==0)
            {
                printf("Korzystasz z kola ratunkowego 2 ! Odslaniamy pierwsza literke! :) \n\n");
                kolo2++;
            }
            else
            {
                printf("Przykro mi, juz wykorzystales to kolo ratunkowe :( \n \n \n \n");
            }

        }
                while(n!=plliter) // PETLA SPRAWDZAJACA CZY DANA LITERKA JUZ WYSTEPOWALA
                {
                    while(literka==zakslowo[n])
                    {
                     printf("Juz wybrales ta literke! Wybierz inna!");
                    scanf("%c", &literka);
                    getchar();
                    }
                n++;
                }
         n=0;
        //TERAZ PETLA KTORA SPRAWDZA CZY LITERKA JEST W TABELI
            while(i!=plliter)
            {
                 if(literka=='2') // implementacja kola 2
                    {
                        int czy=0;
                        darmowaliterka=slowo[0];
                        zakslowo[0]=darmowaliterka;
                        for(czy!=0 ; czy!=plliter ; czy++)
                        {
                            if(darmowaliterka==slowo[czy])
                            {
                            zakslowo[czy]=darmowaliterka;
                            lliter--;
                            }
                        }
                        
                         bb++;
                         
                        break;
                        
                    }
                 if(literka=='1') // implementacja kola 1
                    {
                
                        bb--;
                        break;
                    }
                    if(slowo[i]==literka)
                     {             
                        zakslowo[i]=literka;
                        bb++;
                        lliter--;
                     }
                i++;
            }
            if(bb==0 && literka!='1' && literka!='2')
            {
                lbledow++;
                printf("Blad! Liczba bledow=%d\n", lbledow);
                szubienica(lbledow);
                printf("\n\n\n\n\n\n\n");
            }

        i=0;
        bb=0;

              if(lliter<=0)
        {
            printf("Brawo! Wygrales/Wygralas! Poszukiwane slowo to - %s -\n Koniec gry :)", zakslowo);
            return 0;
        }


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
        while(n!=plliter) // PETLA SPRAWDZAJACA CZY DANA LITERKA JUZ WYSTEPOWALA
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
                szubienica(lbledow);
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