#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void szubienica(int);
void dopisywanie(int);
void dopisywanieANG(int);
void dopisywanieDE(int);



int main()
{
    //MENU GLOWNE
    int jezyk=0;
    int menu1=0;
    printf("                   HANGMAN\n \n \n");
    printf("Please select your language - pick a number and press ""enter""\n Polski - wcisnij 1 \n English - press 2\n Deutsch - drücken Sie 3\n\n\n\n");
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
        int flag;
        flag=0;
    menu:
        printf("Witaj w grze ""Wiselec"" \n");
        printf("Wpisz numer z listy i wcisnij klawisz ""Enter"" aby kontynuowac\n\n");
        printf("1- Instrukcja\n");
        printf("2- Gra\n");
        printf("3- Dodawanie nowych slow do kategorii\n");
        scanf("%d", &menu1);
        printf("\n");
   while(menu1!=1 && menu1!=2 && menu1!=3)
        {
            printf("Zla opcja, prosze wybierz numer z listy\n");
            scanf("%d", &menu1);
       
            
        }

        

        while(menu1==1)
        {
        printf("\n");
        printf("Wisielec  – gra polegająca na odgadywaniu słów. Gracz stara się odgadnąć litery słowa losowo wybranego przez program.\n Za każdym razem, gdy mu się to uda, program wstawia literę w odpowiednie miejsce; w przeciwnym wypadku program dodaje +1 do liczby popelnionych bledow.\n Jezeli gracz odgadnie haslo zanim liczba bledow wyniesie 5 wygrywa.\n Wszystkie slowa skladaja sie wylacznie z malych liter.\n Dostepne sa 2 kola ratunkowe - aby je wybrac wpisz odpowiadajacy mu numer \n Kolo 1 - zmniejsza liczbe popelnionych bledow o 1. \n Kolo 2 - Wyswietla pierwsza literke slowa (jezeli literka sie powtarza, wyswietla kazde jej powtorzenie)\n Gra daje mozliwosc dodawania nowych slow do istniejacych kategorii.\n Uprzejmie prosze, dodawaj slowa z rozsadkiem, zeby nie zepsuc sobie zabawy.\n Raczej nikt nie spodziewa sie \"orangutana\" w kategorii \"przedmioty codziennego uzytku\" :)\n");
        printf("\n Wcisnij ""Enter"" aby kontynuowac\n\n");
        
        getchar();
        getchar();

        printf("Witaj w grze ""Wiselec"" \n");
        printf("Wpisz numer z listy i wcisnij klawisz ""Enter"" aby kontynuowac\n");
        printf("1- Instrukcja\n");
        printf("2- Gra\n");
        printf("3-Dodawanie nowych slow do kategorii\n");
        scanf("%d", &menu1);
        }
        printf("\n\n\n\n\n\n");
     
        if(menu1==3)
        {
                int kategoria1=0;
                printf("Wybierz numer kategorii do ktorej chcesz dodac slowo:");
                printf("Dostepne kategorie:\n1-zwierzeta\n2-przedmioty uzytku codziennego\n");
                scanf("%d", &kategoria1);
                getchar();
                    while(kategoria1!=1 && kategoria1!=2)
                    {
                        printf("Blednie wybrana kategoria, prosze, wybierz sposrod dostepnych\n");
                        printf("Dostepne kategorie:\n1-zwierzeta\n2-przedmioty uzytku codziennego\n");
                        printf("Wybierz numer kategorii do ktorej chcesz dodac slowo:");
                        scanf("%d", &kategoria1);
                        getchar();
                    }

            dopisywanie(kategoria1);
            goto menu;
            
        }
        if(menu1==2)
{       


        //GRA 
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
        char literkabyla[100]={0}; // tabela z literkami juz wpisanymi przez uzytkownika.
        int literkabylaindeks=0; // indeks do tabeli z literkami juz wpisywanymi przez uzytkownika

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
                printf("Niestety! Maksymalna liczba bledow :( Poszukiwane slowo to - %sKoniec gry.\n", slowo);
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
                printf("Korzystasz z kola ratunkowego 1 ! Dodatkowa szansa! Liczba bledow to %d \n\n", lbledow-1);
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
                while(n!=plliter) // PETLA SPRAWDZAJACA CZY DANA LITERKA JUZ WYSTEPOWALA LUB BYLA PODANA PRZEZ UZYTKOWNIKA
                {
                    for(int spr=0; spr!=literkabylaindeks; spr++)
                    {
                        if(literka==literkabyla[spr])
                        {
                            printf("Juz wybrales ta literke! Wybierz inna!\n");
                        scanf("%c", &literka);
                        getchar();

                        }
                    }
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
                printf("Blad! Liczba bledow=%d\n\n\n", lbledow);
                szubienica(lbledow);
                printf("\n\n\n\n\n");
            }

        i=0;
        bb=0;

              if(lliter<=0)
        {
            printf("Brawo! Wygrales/Wygralas! Poszukiwane slowo to - %s -\n Koniec gry :)\n", zakslowo);
            return 0;
        }

        literkabyla[literkabylaindeks]=literka;
        literkabylaindeks++;
        }
  
 }

    }






    if(jezyk==2) // JEZYK ANGIELSKI
    {//MENU
        int flag;
        flag=0;
    menuang:
        printf("Welcome to ""The Hangman"" game"" \n");
        printf("Select a number from the list and press \"Enter\" to continue\n\n");
        printf("1- How to\n");
        printf("2- Game\n");
        printf("3- Add a new word\n");
        scanf("%d", &menu1);
        printf("\n");
   while(menu1!=1 && menu1!=2 && menu1!=3)
        {
            printf("There is no such option, please pick again\n");
            scanf("%d", &menu1);
       
            
        }

        

        while(menu1==1)
        {
        printf("\n");
        printf("The game is about guessing a randomly picked word. The player tries to guess the correct word letter by letter, making as little mistakes as possbile.\n Each time the player succeeds a letter is revealed ; Otherwise, the game adds +1 to the mistake counter.\n If the player guesses the whole word correctly before making 5 mistakes - he/she wins.\n All of the words contain only lower-case letters.\n There are 2 lifelines available - You can pick them by typing the proper number.  \n Lifeline 1 - it reduces the mistake counter by 1. \n Lifeline 2 - it reveales the first letter of the word (if the letter appeares multiple times this lifeline shows it's every occurance)\n There's an option of adding new words to already existing categories.\n But please, be carefull when adding a new word - not to ruin Your experience. \n Nobody expects an \"orangutan\" in \"common items\" category :) \n");
        printf("\n Press enter to continue\n\n");
        
        getchar();
        getchar();

      printf("Welcome to ""The Hangman"" game"" \n");
        printf("Select a number from the list and press \"Enter\" to continue\n\n");
        printf("1- How to\n");
        printf("2- Game\n");
        printf("3- Add a new word\n");
        scanf("%d", &menu1);
        }
        printf("\n\n\n\n\n\n");
     
        if(menu1==3)
        {
                int kategoria1=0;
                printf("Choose a category:");
                printf("Available categories:\n1-animals\n2-common items\n");
                scanf("%d", &kategoria1);
                getchar();
                    while(kategoria1!=1 && kategoria1!=2)
                    {
                        printf("Please, pick an existing category.\n");
                        printf("Available categories:\n1-animals\n2-common items\n");
                        scanf("%d", &kategoria1);
                        getchar();
                    }

            dopisywanieANG(kategoria1);
            goto menuang;
        }


if(menu1==2)
{


              //GRA 
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
        char literkabyla[100]={0}; // tabela z literkami juz wpisanymi przez uzytkownika.
        int literkabylaindeks=0; // indeks do tabeli z literkami juz wpisywanymi przez uzytkownika

        printf("Choose a category!\n");
        printf("Categories:\n 1-Animals\n 2-Common items \n\n\n\n\n");
        scanf("%d", &kategoria);

         
            // otwarcie pliku z kategoria 1
        if(kategoria==1)
        {
        FILE* fp=NULL; 
        char words[100]; 
        int w=0, ran=0;
        srand(time(NULL));
        fp = fopen("animals.txt", "r+");
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
        fp = fopen("items.txt", "r+");
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
            printf("There is no such category, please choose a proper one\n");
            printf("Categories:\n 1-Animals\n 2-Common items \n");
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
        
        printf("Number of letters to guess %d \n", lliter );

        while(lliter!=0 || lbledow!=5)
        {
            if(lbledow==5)
            {
                printf("Sorry! Too many mistakes :( The word to guess was  - %s Game over.\n", slowo);
                return 0;
            }
            printf("Word to guess %s \n", zakslowo);
        printf("Pick a letter! \n");
        literka=0;
        scanf("%c", &literka);
        getchar();


        if(literka=='1') // kolo ratunkowe 1- zmniejsza liczbe bledow o 1
        {
            if(kolo1==0)
            {
                printf("You're using the first Lifeline! The mistake counter is now: %d \n\n", lbledow-1);
                lbledow--;
                kolo1++;
            }
            else
            {
                printf("You've already used that lifeline, I'm sorry :( \n \n \n \n");
            }

        }
          if(literka=='2') // kolo ratunkowe 2- odkrywa pierwsza literke (jesli sie powtarza to odkrywa wszystkie te literki w slowie)
        {
            if(kolo2==0)
            {
                printf("You're using the second lifeline! The first letter is revealed :) \n\n");
                kolo2++;
            }
            else
            {
                printf("You've already used that lifeline, I'm sorry :( \n \n \n \n");
            }

        }
                while(n!=plliter) // PETLA SPRAWDZAJACA CZY DANA LITERKA JUZ WYSTEPOWALA LUB BYLA PODANA PRZEZ UZYTKOWNIKA
                {
                    for(int spr=0; spr!=literkabylaindeks; spr++)
                    {
                        if(literka==literkabyla[spr])
                        {
                            printf("You've already picked that letter! Pick another one\n");
                        scanf("%c", &literka);
                        getchar();

                        }
                    }
                    while(literka==zakslowo[n])
                    {
                     printf("You've already picked that letter! Pick another one");
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
                printf("Mistake! Your mistake counter=%d\n\n\n", lbledow);
                szubienica(lbledow);
                printf("\n\n\n\n\n");
            }

        i=0;
        bb=0;

              if(lliter<=0)
        {
            printf("Congratulations! You've won! The word we were looking for is - %s -\n Game over :)\n", zakslowo);
            return 0;
        }

        literkabyla[literkabylaindeks]=literka;
        literkabylaindeks++;
        }
            }
 }

    if(jezyk==3) // JEZYK NIEMIECKI
    {
        //MENU
        int flag;
        flag=0;
    menuDE:
        printf("Willkommen beim Spiel "" Henker "" \n");
        printf("Geben Sie die Nummer aus der Liste ein und drücken Sie die „Enter“-Taste, um fortzufahren\n\n");
        printf("1- Anweisung\n");
        printf("2- Spiel\n");
        printf("3- Hinzufügen neuer Wörter zu einer Kategorie\n");
        scanf("%d", &menu1);
        printf("\n");
   while(menu1!=1 && menu1!=2 && menu1!=3)
        {
            printf("Falsche Option, bitte wählen Sie eine Nummer aus der Liste aus\n");
            scanf("%d", &menu1);
       
            
        }

        

        while(menu1==1)
        {
        printf("\n");
        printf("Hangman - ein Wortratespiel. Der Spieler versucht, die Buchstaben eines vom Programm zufällig ausgewählten Wortes zu erraten.\n N Jedes Mal, wenn es ihm gelingt, setzt das Programm den Buchstaben an die richtige Stelle; andernfalls addiert das Programm +1 zur Anzahl der gemachten Fehler. \n Wenn der Spieler das Passwort errät, bevor die Anzahl der Fehler 5 beträgt, gewinnt er. \n Alle Wörter bestehen nur aus Kleinbuchstaben. \n Es gibt 2 Rettungsringe - Um sie auszuwählen, geben Sie die entsprechende Zahl ein \n Kreis 1 - reduziert die Anzahl der Fehler um 1. \n Kreis 2 - Zeigt den ersten Buchstaben eines Wortes an (wenn sich der Buchstabe wiederholt, zeigt es jede Wiederholung an) \n Das Spiel gibt Ihnen die Möglichkeit, neue Wörter zu den bestehenden Kategorien hinzuzufügen. \n Bitte fügen Sie Wörter mit Bedacht hinzu, um Ihnen nicht den Spaß zu verderben. \n");
        printf("\n Drücken Sie "" Enter "", um fortzufahren\n\n");
        
        getchar();
        getchar();

        printf("Willkommen beim Spiel "" Henker "" \n");
        printf("Geben Sie die Nummer aus der Liste ein und drücken Sie die „Enter“-Taste, um fortzufahren\n\n");
        printf("1- Anweisung\n");
        printf("2- Spiel\n");
        printf("3- Hinzufügen neuer Wörter zu einer Kategorie\n");
        scanf("%d", &menu1);
        }
        printf("\n\n\n\n\n\n");
     
        if(menu1==3)
        {
                int kategoria1=0;
                printf("Wählen Sie die Kategorienummer aus, der Sie das Wort hinzufügen möchten:");
                printf("Verfügbare Kategorien: \n1-Tiere \n2-Alltagsartikel\n");
                scanf("%d", &kategoria1);
                getchar();
                    while(kategoria1!=1 && kategoria1!=2)
                    {
                        printf("Falsche Kategorie ausgewählt, bitte wählen Sie aus den verfügbaren aus\n");
                        printf("Verfügbare Kategorien: \n1-Tiere \n2-Alltagsartikel\n");
                        scanf("%d", &kategoria1);
                        getchar();
                    }

            dopisywanieDE(kategoria1);
            goto menuDE;
            
        }
        if(menu1==2)
{       


        //GRA
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
        char literkabyla[100]={0}; // tabela z literkami juz wpisanymi przez uzytkownika.
        int literkabylaindeks=0; // indeks do tabeli z literkami juz wpisywanymi przez uzytkownika

        printf("Kategorien wählen!\n");
        printf("Kategorien: \n 1-Tiere \n 2-Alltagsartikel \n\n\n\n\n");
        scanf("%d", &kategoria);

         
            // otwarcie pliku z kategoria 1
        if(kategoria==1)
        {
        FILE* fp=NULL; 
        char words[100]; 
        int w=0, ran=0;
        srand(time(NULL));
        fp = fopen("tiere.txt", "r+");
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
        fp = fopen("produkte.txt", "r+");
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
            printf("Falsche Kategorie ausgewählt, bitte wählen Sie aus den verfügbaren Optionen\n");
            printf("Kategorien: \n 1-Tiere \n 2-Alltagsartikel \n");
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
        
        printf("Die Anzahl der Buchstaben des zu erratenden Wortes %d \n", lliter );

        while(lliter!=0 || lbledow!=5)
        {
            if(lbledow==5)
            {
                printf("Bedauerlicherweise! Maximale Anzahl an Fehlern :( Das Suchwort ist %s Game End.\n", slowo);
                return 0;
            }
            printf("Ein Wort zum Raten %s \n", zakslowo);
        printf("Geben Sie den Buchstaben ein! \n");
        literka=0;
        scanf("%c", &literka);
        getchar();


        if(literka=='1') // kolo ratunkowe 1- zmniejsza liczbe bledow o 1
        {
            if(kolo1==0)
            {
                printf("Sie verwenden Rettungsring 1! Eine zusätzliche Chance! Die Anzahl der Fehler ist %d \n\n", lbledow-1);
                lbledow--;
                kolo1++;
            }
            else
            {
                printf("Es tut mir leid, Sie haben den Rettungsring bereits benutzt \n \n \n \n");
            }

        }
          if(literka=='2') // kolo ratunkowe 2- odkrywa pierwsza literke (jesli sie powtarza to odkrywa wszystkie te literki w slowie)
        {
            if(kolo2==0)
            {
                printf("Sie benutzen die 2 Rettungsringe! Wir enthüllen den ersten Buchstaben! \n\n");
                kolo2++;
            }
            else
            {
                printf("Es tut mir leid, Sie haben den Rettungsring bereits benutzt  \n \n \n \n");
            }

        }
                while(n!=plliter) // PETLA SPRAWDZAJACA CZY DANA LITERKA JUZ WYSTEPOWALA LUB BYLA PODANA PRZEZ UZYTKOWNIKA
                {
                    for(int spr=0; spr!=literkabylaindeks; spr++)
                    {
                        if(literka==literkabyla[spr])
                        {
                            printf("Sie haben diesen Buchstaben bereits ausgewählt! Wählen Sie einen anderen!\n");
                        scanf("%c", &literka);
                        getchar();

                        }
                    }
                    while(literka==zakslowo[n])
                    {
                     printf("Sie haben diesen Buchstaben bereits ausgewählt! Wählen Sie einen anderen!");
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
                printf("Blad! Liczba bledow=%d\n\n\n", lbledow);
                szubienica(lbledow);
                printf("\n\n\n\n\n");
            }

        i=0;
        bb=0;

              if(lliter<=0)
        {
            printf("Weiter so! Sie haben gewonnen! Das Suchwort ist %s.\n Game ende :)", zakslowo);
            return 0;
        }

        literkabyla[literkabylaindeks]=literka;
        literkabylaindeks++;
        }
  
 }

    }







}



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

void dopisywanie(int kategoria1)
{
    if(kategoria1==1)
    {
    FILE* fp =NULL;
    fp=fopen("zwierzeta.txt", "a");
    char slowo[100]={0};
    printf("Podaj nowe slowo. Aby zakonczyc wpisywanie podaj #\n");
    while ((fscanf(stdin,"%99s",slowo) ==1) && (slowo[0]!= '#') )
    fprintf(fp,"%s",slowo);
    fprintf(fp, "\n");
    printf("Dziekuje, slowo zostalo dodane :)\n\n\n\n");
    fclose(fp);
    }
    if(kategoria1==2)
    {
        FILE* fp =NULL;
    fp=fopen("przedmioty.txt", "a");
    char slowo[100]={0};
    printf("Podaj nowe slowo. Aby zakonczyc wpisywanie podaj #\n");
    while ((fscanf(stdin,"%99s",slowo) ==1) && (slowo[0]!= '#') )
    fprintf(fp,"%s",slowo);
    fprintf(fp,"/n");
    printf("Dziekuje, slowo zostalo dodane :)\n\n\n\n");
    fclose(fp);

    }
   

}

void dopisywanieANG (int kategoria1)
{
    if(kategoria1==1)
    {
    FILE* fp =NULL;
    fp=fopen("animals.txt", "a");
    char slowo[100]={0};
    printf("Insert a new word. To finish inerting write #\n");
    while ((fscanf(stdin,"%99s",slowo) ==1) && (slowo[0]!= '#') )
    fprintf(fp,"%s",slowo);
    fprintf(fp, "\n");
    printf("Thank You, the word has been added :)\n\n\n\n");
    fclose(fp);
    }
    if(kategoria1==2)
    {
        FILE* fp =NULL;
    fp=fopen("items.txt", "a");
    char slowo[100]={0};
    printf("PInsert a new word. To finish inerting write #\n");
    while ((fscanf(stdin,"%99s",slowo) ==1) && (slowo[0]!= '#') )
    fprintf(fp,"%s",slowo);
    fprintf(fp,"/n");
    printf("Thank You, the word has been added :)\n\n\n\n");
    fclose(fp);

    }
   


}

void dopisywanieDE (int kategoria1)
{
    if(kategoria1==1)
    {
    FILE* fp =NULL;
    fp=fopen("tiere.txt", "a");
    char slowo[100]={0};
    printf("Fügen Sie ein neues Wort ein. Um die Inertisierung abzuschließen, schreiben Sie #\n");
    while ((fscanf(stdin,"%99s",slowo) ==1) && (slowo[0]!= '#') )
    fprintf(fp,"%s",slowo);
    fprintf(fp, "\n");
    printf("Danke, das Wort wurde hinzugefügt\n\n\n\n");
    fclose(fp);
    }
    if(kategoria1==2)
    {
        FILE* fp =NULL;
    fp=fopen("produkte.txt", "a");
    char slowo[100]={0};
    printf("Fügen Sie ein neues Wort ein. Um die Inertisierung abzuschließen, schreiben Sie #\n");
    while ((fscanf(stdin,"%99s",slowo) ==1) && (slowo[0]!= '#') )
    fprintf(fp,"%s",slowo);
    fprintf(fp,"/n");
    printf("Danke, das Wort wurde hinzugefügt\n\n\n\n");
    fclose(fp);

    }
   

}
