#ifndef MENIU
#define MENIU
#include "coordonate.h"
#include "settings.h"
#include "start.h"

#define NEGRU 0, 0, 0
bool was_music_set = false;
bool need_info = false;
void buton_muzica_info(int alegere)
{
    setcolor(BLACK);
    if(alegere == 0)
    {
        readimagefile("img/volume-mute.jpg",b_muzica.lX, b_muzica.lY, b_muzica.rX, b_muzica.rY);
        rectangle(b_muzica.lX-3, b_muzica.lY-3, b_muzica.rX+3, b_muzica.rY+3);

    }
    else if (alegere == 1)
    {
        readimagefile("img/speaker.jpg",b_muzica.lX, b_muzica.lY, b_muzica.rX, b_muzica.rY);
        rectangle(b_muzica.lX-3, b_muzica.lY-3, b_muzica.rX+3, b_muzica.rY+3);
    }
    else if(alegere == 2)
    {
        readimagefile("img/question_mark.jpg",b_muzica.lX, b_muzica.lY, b_muzica.rX, b_muzica.rY);
        rectangle(b_muzica.lX-3, b_muzica.lY-3, b_muzica.rX+3, b_muzica.rY+3);
    }

}
void muzica_set(int alegere)
{


    if (muzica_on == true)
    {
        PlaySound(TEXT("music.wav"), NULL, SND_ASYNC); // <- Eroare la compilare, -lwinmm pentru rezolvare, cel putin pt [Silvian]

    }
    else if(muzica_on == false)
    {
        PlaySound(NULL,NULL,SND_ASYNC);

    }
}

void afisare_text_info(int alegere)
{
    if(alegere == 0)
    {
        setbkcolor(COLOR(r_fundal, g_fundal, b_fundal));
        settextstyle(0, HORIZ_DIR, 8);
        char text[3][8] = {"Ajutor","Help","Aider"};
        if(limba == 0)
            outtextxy((rezX / 2) - 260+ 70, 20, text[limba]);
        if(limba == 1)
            outtextxy((rezX / 2) - 260+ 130, 20, text[limba]);
        if(limba == 2)
            outtextxy((rezX / 2) - 260 + 110, 20, text[limba]);
    }
    else if(alegere == 1)
    {
        settextstyle(0, HORIZ_DIR, 2);


        if(limba == 0)
        {
            outtextxy(37, 137,"Bonol este un joc de doi jucatori jucat pe o tabla de patrate 4×4. Fiecare jucator are ");
            outtextxy(37, 157,"un tetromino în forma de L de 3×2. La fiecare tura, un jucator trebuie mai intai sa-si ");

            outtextxy(37, 177,"mute piesa L si apoi poate muta optional oricare dintre piesele neutre. Jocul este   ");
            outtextxy(37, 197,"castigat lasand adversarul in imposibilitatea de a-si muta piesa L intr-o noua pozitie. ");
            outtextxy(37, 217,"Piesele nu se pot suprapune sau acoperi alte piese. La mutarea piesei L, aceasta este  ");
            outtextxy(37, 237,"ridicata si apoi plasata in patrate goale oriunde pe tabla. Acesta poate fi rotit sau ");
            outtextxy(37, 257,"chiar rasturnat in acest sens; singura regula este ca trebuie sa se termine intr-o");
            outtextxy(37, 277,"pozitie diferita de pozitia pe care a inceput-o acoperind astfel cel putin un patrat");
            outtextxy(37, 297,"pe care nu l-a acoperit anterior. Pentru a muta o piesa neutra, un jucator pur si     ");
            outtextxy(37, 317,"simplu o ridica apoi o plaseaza intr-un patrat gol oriunde pe tabla.");
        }
        if(limba == 1)
        {
            outtextxy(37, 137,"The L game is a two-player game played on a board of 4×4 squares. Each player has a 3×2 ");
            outtextxy(37, 157,"L-shaped tetromino, and there are two 1×1 neutral pieces. On each turn, a player must ");

            outtextxy(37, 177,"first move their L piece, and then may optionally move either one of the neutral pieces. ");
            outtextxy(37, 197,"The game is won by leaving the opponent unable to move their L piece to a new position. ");
            outtextxy(37, 217,"Pieces may not overlap or cover other pieces. On moving the L piece, it is picked up and ");
            outtextxy(37, 237,"then placed in empty squares anywhere on the board. It may be rotated or even flipped ");
            outtextxy(37, 257,"over in doing so; the only rule is that it must end in a different position from the  ");
            outtextxy(37, 277,"position  it started—thus covering at least one square it did not previously cover. ");
            outtextxy(37, 297,"To move a neutral piece, a player simply picks it up then places it in an empty square");
            outtextxy(37, 317,"anywhere on the board. ");
        }
        if(limba == 2)
        {
            outtextxy(37, 137,"Le jeu L est un jeu à deux joueurs joué sur un plateau de 4×4 cases. Chaque joueur a un  ");
            outtextxy(37, 157,"tétromino en forme de L 3×2 et il y a deux pièces neutres 1×1. À chaque tour, un  ");

            outtextxy(37, 177,"joueur doit d'abord déplacer sa pièce L, puis peut éventuellement déplacer l'une des   ");
            outtextxy(37, 197,"pièces neutres. Le jeu est gagné en laissant l'adversaire incapable de déplacer sa pièce   ");
            outtextxy(37, 217,"L vers une nouvelle position. Les pièces ne doivent pas se chevaucher ou couvrir  ");
            outtextxy(37, 237,"d'autres pièces. En déplaçant la pièce L, elle est ramassée puis placée dans des cases ");
            outtextxy(37, 257,"vides n'importe où sur le plateau. Il peut être tourné ou même retourné en le faisant; ");
            outtextxy(37, 277,"la seule règle est qu'il doit se terminer dans une position différente de celle où il a");
            outtextxy(37, 297,"commencé, couvrant ainsi au moins une case qu'il ne couvrait pas auparavant. Pour  ");
            outtextxy(37, 317,"déplacer une pièce neutre, un joueur la ramasse simplement puis la place dans une ");
            outtextxy(37, 337,"case vide n'importe où sur le plateau.");
        }
    }
    else if(alegere == 2)
    {
        settextstyle(0, HORIZ_DIR, 5);
        char text[3][13] = {"Controale","Controls","Contrôles"};
        char text_butoane_mouse[3][3][70] =
        {
            {"Left Mouse Button - Muta Piesa","Middle Mouse Button - Sari peste miscare banut","Right Mouse Button - Selecteaza/muta banut"},
            {"Left Mouse Button - Move the piece","Middle Mouse Button - Skip coin move","Right Mouse Button - Select/move the coin"},
            {"Left Mouse Button - Déplacer la pièce","Middle Mouse Button - Ignorer le mouvement des pièces","Right Mouse Button - Sélectionner/déplacer la pièce"},
        };
        if(limba == 0)
        {
            outtextxy(460, 380, text[limba]);
            settextstyle(0, HORIZ_DIR, 2);
            outtextxy(430, 430, text_butoane_mouse[limba][0]);
            outtextxy(300, 470, text_butoane_mouse[limba][1]);
            outtextxy(350, 510, text_butoane_mouse[limba][2]);
        }
        if(limba == 1)
        {
            outtextxy(480, 380, text[limba]);
            settextstyle(0, HORIZ_DIR, 2);
            outtextxy(400, 430, text_butoane_mouse[limba][0]);
            outtextxy(380, 470, text_butoane_mouse[limba][1]);
            outtextxy(350, 510, text_butoane_mouse[limba][2]);
        }
        if(limba == 2)
        {
            outtextxy(460, 380, text[limba]);
            settextstyle(0, HORIZ_DIR, 2);
            outtextxy(380, 430, text_butoane_mouse[limba][0]);
            outtextxy(280, 470, text_butoane_mouse[limba][1]);
            outtextxy(285, 510, text_butoane_mouse[limba][2]);
        }
    }

}

void pagina_info()
{

    bool _back = 0;

    setbkcolor(COLOR(r_fundal, g_fundal, b_fundal));
    clearviewport();

    int x = mousex();
    int y = mousey();

    afisare_butoane_settings('B');
    afisare_text_info(0);
    afisare_text_info(1);
    afisare_text_info(2);
    while(_back == 0)
    {
        delay(2);

        x = mousex();

        y = mousey();



        buton_back( x,y, _back);

    }
    delay(100);
    if(_back == 1)
        afisMenu();



}

void selectare_buton_muzica_info(int x, int y, bool &muzica_on, short alegere)
{
    if(x >=b_muzica.lX && x <= b_muzica.rX && y >= b_muzica.lY && y <= b_muzica.rY)
    {

        while(true)
        {
            delay(2);

            x=mousex();
            y=mousey();


            setcolor(COLOR(255, 145, 0));
            rectangle(b_muzica.lX-3, b_muzica.lY-3, b_muzica.rX+3, b_muzica.rY+3);
            if((GetKeyState(VK_LBUTTON) & 0x80)!=0)
            {
                delay(70);
                if(alegere == 1)
                {
                    if(muzica_on == true)
                    {

                        muzica_on = false;
                        buton_muzica_info(muzica_on);
                        muzica_set(muzica_on);


                    }
                    else
                    {

                        muzica_on = true;
                        buton_muzica_info(muzica_on);
                        muzica_set(muzica_on);


                    }
                }
                else if(alegere == 2)
                {
                    clearviewport();
                    pagina_info();
                    break;
                }

                break;
            }
            delay(2);
            if (!(x >=b_muzica.lX && x <= b_muzica.rX && y >= b_muzica.lY && y <= b_muzica.rY))
            {
                setcolor(BLACK);
                rectangle(b_muzica.lX-3, b_muzica.lY-3, b_muzica.rX+3, b_muzica.rY+3);

                break;
            }

        }
    }
}


void afisare_text_meniu(int alegere)
{
    if (alegere == 1)
    {
        settextstyle(0, HORIZ_DIR, 2);
        char b_s_text[9] = ">Start<";
        outtextxy((b_start.lX + b_start.rX) / 2 - (lungime / 4) + 4, (b_start.rY + b_start.lY) / 2 - (inaltime / 8) + 4, b_s_text);
    }
    else if(alegere == 2)
    {
        settextstyle(0, HORIZ_DIR, 2);
        char b_st_text[3][15] = {">Setari<",">Settings<",">Paramètres<"};
        if(limba == 0)
            outtextxy((b_settings.lX + b_settings.rX) / 2 - (lungime / 3) - 2 + 14, (b_settings.rY + b_settings.lY) / 2 - (inaltime / 8) + 4, b_st_text[limba]);
        if(limba == 1)
            outtextxy((b_settings.lX + b_settings.rX) / 2 - (lungime / 3) - 2, (b_settings.rY + b_settings.lY) / 2 - (inaltime / 8) + 4, b_st_text[limba]);
        if(limba == 2)
            outtextxy((b_settings.lX + b_settings.rX) / 2 - (lungime / 3) - 2 - 14, (b_settings.rY + b_settings.lY) / 2 - (inaltime / 8) + 4, b_st_text[limba]);

    }
    else if (alegere == 3)
    {
        settextstyle(0, HORIZ_DIR, 2);
        char b_e_text[3][10] = {">Iesire<",">Exit<",">Quitter<"};

        if(limba == 0)
            outtextxy((b_exit.lX + b_exit.rX) / 2 - (lungime / 4) + 11 -14, (b_exit.rY + b_exit.lY) / 2 - (inaltime / 8) + 4, b_e_text[limba]);
        if(limba == 1)
            outtextxy((b_exit.lX + b_exit.rX) / 2 - (lungime / 4) + 11, (b_exit.rY + b_exit.lY) / 2 - (inaltime / 8) + 4, b_e_text[limba]);
        if(limba == 2)
            outtextxy((b_exit.lX + b_exit.rX) / 2 - (lungime / 4) + 11 - 20, (b_exit.rY + b_exit.lY) / 2 - (inaltime / 8) + 4, b_e_text[limba]);

    }

}


void meniu_selectie()
{
    if(was_music_set==false)
    {
        muzica_set(muzica_on);
        was_music_set = true;
    }
    int x, y;
    buton_muzica_info(2);
    while(true)
    {
        x = mousex();
        y = mousey();
        delay(2);

        selectare_buton_muzica_info(x,y,muzica_on,2);

        if(x >= b_start.lX && x <= b_start.rX && y >= b_start.lY && y <= b_start.rY)
        {
            while(true)
            {
                delay(2);
                x = mousex();
                y = mousey();

                setfillstyle(SOLID_FILL, RED);
                bar(b_start.lX+1, b_start.lY+1, b_start.rX, b_start.rY);
                setbkcolor(RED);

                selectare_buton_muzica_info(x,y,muzica_on,2);


                afisare_text_meniu(1);

                // Menu -> Pagina Joc
                if ((GetKeyState(VK_LBUTTON) & 0x80)!=0)
                {
                    setbkcolor(COLOR(r_fundal, g_fundal, b_fundal));
                    clearviewport();

                    sectiune_start();


                    break;
                }


                if (!(x >= b_start.lX && x <= b_start.rX && y >= b_start.lY && y <= b_start.rY))
                {
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(b_start.lX+1, b_start.lY+1, b_start.rX, b_start.rY);
                    setbkcolor(WHITE);
                    afisare_text_meniu(1);
                    break;
                }
            }
        }




        if(x >= b_settings.lX && x <= b_settings.rX && y >= b_settings.lY && y <= b_settings.rY)
        {
            while(true)
            {
                delay(2);
                x = mousex();
                y = mousey();

                setfillstyle(SOLID_FILL, RED);
                bar(b_settings.lX+1, b_settings.lY+1, b_settings.rX, b_settings.rY);
                setbkcolor(RED);


                if ((GetKeyState(VK_LBUTTON) & 0x80)!=0)
                {
                    clearviewport();
                    sectiune_settings();

                    break;
                }


                afisare_text_meniu(2);



                if (!(x >= b_settings.lX && x <= b_settings.rX && y >= b_settings.lY && y <= b_settings.rY))
                {
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(b_settings.lX+1, b_settings.lY+1, b_settings.rX, b_settings.rY);
                    setbkcolor(WHITE);

                    afisare_text_meniu(2);
                    break;
                }
            }
        }



        if(x >= b_exit.lX && x <= b_exit.rX && y >= b_exit.lY && y <= b_exit.rY)
        {
            while(true)
            {
                delay(2);
                x = mousex();
                y = mousey();

                setfillstyle(SOLID_FILL, RED);
                bar(b_exit.lX+1, b_exit.lY+1, b_exit.rX, b_exit.rY);
                setbkcolor(RED);


                afisare_text_meniu(3);



                if ((GetKeyState(VK_LBUTTON) & 0x80)!=0)
                {
                    need_exit = true;
                    break;
                }


                if (!(x >= b_exit.lX && x <= b_exit.rX && y >= b_exit.lY && y <= b_exit.rY))
                {
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(b_exit.lX+1, b_exit.lY+1, b_exit.rX, b_exit.rY);
                    setbkcolor(WHITE);

                    afisare_text_meniu(3);
                    break;
                }
            }
        }

        if (need_exit) break;

    }






}


void afisMenu()
{
    setfillstyle(SOLID_FILL, WHITE);
    setlinestyle(SOLID_LINE,0,5 );
    clearviewport();
    setbkcolor(COLOR(r_fundal, g_fundal, b_fundal));
    need_info = false;
    clearviewport();
    settextstyle(0, HORIZ_DIR, 8);
    setcolor(COLOR(NEGRU));
    char titlu[6] = "BonoL";
    outtextxy(20, 20, titlu);


    setbkcolor(WHITE);

    b_start.lX = rezX - spatiux - lungime;
    b_start.rX = rezX - spatiux;

    b_start.lY = rezY - 3*spatiuy - 3*inaltime;
    b_start.rY = b_start.lY + inaltime;

    rectangle(b_start.lX, b_start.lY, b_start.rX, b_start.rY);
    bar(b_start.lX+1, b_start.lY+1, b_start.rX, b_start.rY);


    afisare_text_meniu(1);






    b_settings.lX = rezX - spatiux - lungime;
    b_settings.rX = rezX - spatiux;

    b_settings.lY = rezY - 2*spatiuy - 2*inaltime;
    b_settings.rY = b_settings.lY + inaltime;

    rectangle(b_settings.lX, b_settings.lY, b_settings.rX, b_settings.rY);
    bar(b_settings.lX+1, b_settings.lY+1, b_settings.rX, b_settings.rY);



    afisare_text_meniu(2);





    b_exit.lX = rezX - spatiux - lungime;
    b_exit.rX = rezX - spatiux;

    b_exit.rY = rezY - spatiuy;
    b_exit.lY = b_exit.rY - inaltime;

    rectangle(b_exit.lX, b_exit.lY, b_exit.rX, b_exit.rY);
    bar(b_exit.lX+1, b_exit.lY+1, b_exit.rX, b_exit.rY);


    afisare_text_meniu(3);


    //-> Init de coordoante pt Settings si pentru Start Page
    init_coord_butoane();


    meniu_selectie();


}





#endif // MENIU
