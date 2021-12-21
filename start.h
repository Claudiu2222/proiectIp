#ifndef START_H_INCLUDED
#define START_H_INCLUDED

//#include "scripts.h"
#include "joc.h"







bool need_back, need_play;
short int latura_p = latura - 25;
//-> Functii
void text_butoane_start(char a)
{

    //-> Buton de Back
    if (a == 1)
    {
        settextstyle(0, HORIZ_DIR, 2);
        setbkcolor(WHITE);
        char text[3][25] = {">Inapoi<",">Back<",">Retour<"};
        if(limba == 0)
            outtextxy(b_back_start.rX / 0.52, 612, text[limba]);

        if(limba == 1)
            outtextxy(b_back_start.rX / 0.46, 612, text[limba]);

        if(limba == 2)
            outtextxy(b_back_start.rX / 0.52, 612, text[limba]);

    }

    if (a == 2)
    {
        settextstyle(0, HORIZ_DIR, 2);
        setbkcolor(RED);
        char text[3][25] = {">Inapoi<",">Back<",">Retour<"};
        if(limba == 0)
            outtextxy(b_back_start.rX / 0.52, 612, text[limba]);

        if(limba == 1)
            outtextxy(b_back_start.rX / 0.46, 612, text[limba]);

        if(limba == 2)
            outtextxy(b_back_start.rX / 0.52, 612, text[limba]);
    }

    //-> Buton de Start
    if (a == 3)
    {
        settextstyle(0, HORIZ_DIR, 2);
        setbkcolor(WHITE);
        char text[3][25] = {">Start Joc<",">Start Game<",">Démarrer jeu<"};
        if(limba == 0)
            outtextxy(b_start_game.lX + 24, 612, text[limba]);

        if(limba == 1)
            outtextxy(b_start_game.lX + 17, 612, text[limba]);

        if(limba == 2)
            outtextxy(b_start_game.lX + 2, 612, text[limba]);
    }

    if (a == 4)
    {
        settextstyle(0, HORIZ_DIR, 2);
        setbkcolor(GREEN);
        char text[3][25] = {">Start Joc<",">Start Game<",">Démarrer jeu<"};
        if(limba == 0)
            outtextxy(b_start_game.lX + 24, 612, text[limba]);

        if(limba == 1)
            outtextxy(b_start_game.lX + 17, 612, text[limba]);

        if(limba == 2)
            outtextxy(b_start_game.lX + 2, 612, text[limba]);
    }
}
void desenare_culori_piese(int alegere)
{
    if(alegere == 0)
    {
        setfillstyle(SOLID_FILL,COLOR(r_player_1,g_player_1,b_player_1));
    bar(553,203,648,298);
    bar(653,203,748,298);
    bar(753,203,848,298);
    bar(553,303,648,398);

    }
    else if(alegere == 1)
    {setfillstyle(SOLID_FILL,COLOR(r_player_2,g_player_2,b_player_2));
        bar(853,203,948,298);
     bar(653,303,748,398);
      bar(753,303,848,398);
       bar(853,303,948,398);
    }
}
void casute_color()
{
    rectangle(280,290,320,310);
    rectangle(370,290,410,310);
    rectangle(460,290,500,310);
    rectangle(1005,290,1045,310);
    rectangle(1095,290,1135,310);
    rectangle(1185,290,1225,310);
    setfillstyle(SOLID_FILL,COLOR(255,0,0));
    bar(282,292,318,308);
    bar(1007,292,1043,308);



    setfillstyle(SOLID_FILL,COLOR(0,255,0));
    bar(372,292,408,308);
    bar(1097,292,1133,308);

    setfillstyle(SOLID_FILL,COLOR(0,0,255));
    bar(462,292,498,308);
    bar(1187,292,1223,308);




    afisare_butoane_culori(0,1);
    afisare_butoane_culori(1,1);
    afisare_butoane_culori(2,1);
    afisare_butoane_culori(3,1);
    afisare_butoane_culori(4,1);
    afisare_butoane_culori(5,1);
    afisare_butoane_culori(0,2);
    afisare_butoane_culori(1,2);
    afisare_butoane_culori(2,2);
    afisare_butoane_culori(3,2);
    afisare_butoane_culori(4,2);
    afisare_butoane_culori(5,2);
    desenare_culori_piese(0);
    desenare_culori_piese(1);

}
void culoare_player(int x, int y, int &r_fundal_aux, int &g_fundal_aux, int &b_fundal_aux, int alegere)
{
    rectangle(391,520,463,550);
    rectangle(604,520,676,550);
    rectangle(817,520,889,550);
    rectangle(584,600,696,700);
    setviewport(394,523,461,548,0);
    setbkcolor(COLOR(255,0,0));
    clearviewport();

    setviewport(607,523,674,548,0);
    setbkcolor(COLOR(0,255,0));
    clearviewport();

    setviewport(820,523,887,548,0);
    setbkcolor(COLOR(0,0,255));
    clearviewport();
    setviewport(0,0,1280,720,0);
    if(x >= 391 && x <= 463 && y >=490 && y<=519)
    {
        while(true)
        {

            x=mousex();
            y=mousey();
            delay(50);



            while((GetKeyState(VK_LBUTTON) & 0x80)!=0)
            {
                readimagefile("img/arrowupred.jpg",391,490,463,519);
                setcolor(COLOR(255,0,0));
                rectangle(391,490,463,519);

                setviewport(587,603,694,698,0);
                if(r_fundal_aux%255 < 254)
                    r_fundal_aux++;
                setbkcolor(COLOR(r_fundal_aux%255,g_fundal_aux%255,b_fundal_aux%255));
                clearviewport();

                afisare_butoane_culori(0,0);
                if((GetKeyState(VK_LBUTTON) & 0x80)==0)
                {
                    setviewport(0,0,1280,720,0);
                    setcolor(BLACK);
                    afisare_butoane_culori(0,0);
                    delay(2);
                    break;
                }
            }
            if((GetKeyState(VK_LBUTTON) & 0x80)==0)
            {
                setviewport(0,0,1280,720,0);
                setcolor(BLACK);
                afisare_butoane_culori(0,0);
                delay(2);
                break;
            }

        }
    }
    if(x >= 391 && x <= 463 && y >=551 && y<=579)
    {
        while(true)
        {

            x=mousex();
            y=mousey();
            delay(50);



            while((GetKeyState(VK_LBUTTON) & 0x80)!=0)
            {
                readimagefile("img/arrowdownred.jpg",391,551,463,579);
                setcolor(COLOR(255,0,0));
                rectangle(391,551,463,579);

                setviewport(587,603,694,698,0);
                if(r_fundal_aux%255 > 1)
                    r_fundal_aux--;
                setbkcolor(COLOR(r_fundal_aux%255,g_fundal_aux%255,b_fundal_aux%255));
                clearviewport();

                afisare_butoane_culori(0,0);
                if((GetKeyState(VK_LBUTTON) & 0x80)==0)
                {
                    setviewport(0,0,1280,720,0);
                    setcolor(BLACK);
                    afisare_butoane_culori(1,0);
                    delay(2);
                    break;
                }
            }
            if((GetKeyState(VK_LBUTTON) & 0x80)==0)
            {
                setviewport(0,0,1280,720,0);
                setcolor(BLACK);
                afisare_butoane_culori(1,0);
                delay(2);
                break;
            }

        }
    }
    if(x >= 604 && x <= 676 && y >=490 && y<=519)
    {
        while(true)
        {

            x=mousex();
            y=mousey();
            delay(50);



            while((GetKeyState(VK_LBUTTON) & 0x80)!=0)
            {
                readimagefile("img/arrowupred.jpg",604,490,676,519);
                setcolor(COLOR(255,0,0));
                rectangle(604,490,676,519);

                setviewport(587,603,694,698,0);
                if(g_fundal_aux%255 < 254)
                    g_fundal_aux++;
                setbkcolor(COLOR(r_fundal_aux%255,g_fundal_aux%255,b_fundal_aux %255));
                clearviewport();

                afisare_butoane_culori(0,0);
                if((GetKeyState(VK_LBUTTON) & 0x80)==0)
                {
                    setviewport(0,0,1280,720,0);
                    setcolor(BLACK);
                    afisare_butoane_culori(2,0);
                    delay(2);
                    break;
                }
            }
            if((GetKeyState(VK_LBUTTON) & 0x80)==0)
            {
                setviewport(0,0,1280,720,0);
                setcolor(BLACK);
                afisare_butoane_culori(2,0);
                delay(2);
                break;
            }

        }
    }
    if(x >= 604 && x <= 676 && y >=551 && y<=579)
    {
        while(true)
        {

            x=mousex();
            y=mousey();
            delay(50);



            while((GetKeyState(VK_LBUTTON) & 0x80)!=0)
            {
                readimagefile("img/arrowdownred.jpg",604,551,676,579);
                setcolor(COLOR(255,0,0));
                rectangle(604,551,676,579);

                setviewport(587,603,694,698,0);
                if(g_fundal_aux%255 > 1)
                    g_fundal_aux--;
                setbkcolor(COLOR(r_fundal_aux%255,g_fundal_aux%255,b_fundal_aux%255));
                clearviewport();

                afisare_butoane_culori(0,0);
                if((GetKeyState(VK_LBUTTON) & 0x80)==0)
                {
                    setviewport(0,0,1280,720,0);
                    setcolor(BLACK);
                    afisare_butoane_culori(3,0);
                    delay(2);
                    break;
                }
            }
            if((GetKeyState(VK_LBUTTON) & 0x80)==0)
            {
                setviewport(0,0,1280,720,0);
                setcolor(BLACK);
                afisare_butoane_culori(3,0);
                delay(2);
                break;
            }

        }
    }
    if(x >= 817 && x <= 889 && y >=490 && y<=519)
    {
        while(true)
        {

            x=mousex();
            y=mousey();
            delay(50);



            while((GetKeyState(VK_LBUTTON) & 0x80)!=0)
            {
                readimagefile("img/arrowupred.jpg",817,490,889,519);
                setcolor(COLOR(255,0,0));
                rectangle(817,490,889,519);

                setviewport(587,603,694,698,0);
                if(b_fundal_aux%255 < 254)
                    b_fundal_aux++;
                setbkcolor(COLOR(r_fundal_aux%255,g_fundal_aux%255,b_fundal_aux%255));
                clearviewport();

                afisare_butoane_culori(0,0);
                if((GetKeyState(VK_LBUTTON) & 0x80)==0)
                {
                    setviewport(0,0,1280,720,0);
                    setcolor(BLACK);
                    afisare_butoane_culori(4,0);
                    delay(2);
                    break;
                }
            }
            if((GetKeyState(VK_LBUTTON) & 0x80)==0)
            {
                setviewport(0,0,1280,720,0);
                setcolor(BLACK);
                afisare_butoane_culori(4,0);
                delay(2);
                break;
            }

        }
    }
    if(x >= 817 && x <= 889 && y >=551 && y<=579)
    {
        while(true)
        {

            x=mousex();
            y=mousey();
            delay(50);



            while((GetKeyState(VK_LBUTTON) & 0x80)!=0)
            {
                readimagefile("img/arrowdownred.jpg",817,551,889,579);
                setcolor(COLOR(255,0,0));
                rectangle(817,551,889,579);

                setviewport(587,603,694,698,0);
                if(b_fundal_aux%255 > 1)
                    b_fundal_aux--;
                setbkcolor(COLOR(r_fundal_aux%255,g_fundal_aux%255,b_fundal_aux%255));
                clearviewport();

                afisare_butoane_culori(0,0);
                if((GetKeyState(VK_LBUTTON) & 0x80)==0)
                {
                    setviewport(0,0,1280,720,0);
                    setcolor(BLACK);
                    afisare_butoane_culori(5,0);
                    delay(2);
                    break;
                }
            }
            if((GetKeyState(VK_LBUTTON) & 0x80)==0)
            {
                setviewport(0,0,1280,720,0);
                setcolor(BLACK);
                afisare_butoane_culori(5,0);
                delay(2);
                break;
            }

        }
    }
}

void buton_back_start(int x, int y, int alegere)  // am adaugat o alegere ca sa pot folosi functia si in joc.h, fara sa o rescriu (economisim niste spatiu :D )
{


    if(x < b_back_start.lX && x > b_back_start.rX && y > b_back_start.lY && y < b_back_start.rY)
    {

        //-> Highlight buton
        setfillstyle(SOLID_FILL, RED);
        bar(b_back_start.rX+1, b_back_start.lY, b_back_start.lX, b_back_start.rY);
        text_butoane_start(2);

        while(true)
        {

            x = mousex();
            y = mousey();

            if ((GetKeyState(VK_LBUTTON) & 0x80)!=0)
            {
                setbkcolor(COLOR(r_fundal, g_fundal, b_fundal));
                clearviewport();
                if(alegere == 0)
                    need_back = true;
                else if (alegere == 1)
                    game_back = true;


                break;
            }

            if(!(x < b_back_start.lX && x > b_back_start.rX && y > b_back_start.lY && y < b_back_start.rY))
            {
                //-> Revenire normal
                setfillstyle(SOLID_FILL, WHITE);
                bar(b_back_start.rX+1, b_back_start.lY, b_back_start.lX, b_back_start.rY);
                text_butoane_start(1);
                break;
            }

        }
    }

}

void desenare_piese_jucatori()
{

    int i,j;
    setlinestyle(SOLID_LINE,0,5 );
    setcolor(WHITE);
    clearviewport();
    for (i=1; i<=4; i++)
        for (j=1; j<=2; j++)
            rectangle(550+latura_p*(i-1),200+latura_p*(j-1),550+latura_p*i,200+latura_p*j);
    setcolor(BLACK);



}
void buton_start_game(int x, int y)
{

    if(x > b_start_game.lX && x < b_start_game.rX && y > b_start_game.lY && y < b_start_game.rY)
    {

        //-> Highlight Buton
        setfillstyle(SOLID_FILL, GREEN);
        bar(b_start_game.lX+1, b_start_game.lY, b_start_game.rX, b_start_game.rY);
        text_butoane_start(4);

        while(true)
        {

            x = mousex();
            y = mousey();


            if ((GetKeyState(VK_LBUTTON) & 0x80)!=0)
            {
                setbkcolor(COLOR(r_fundal, g_fundal, b_fundal));
                clearviewport();
                need_play = true;

                break;
            }


            if(!(x > b_start_game.lX && x < b_start_game.rX && y > b_start_game.lY && y < b_start_game.rY))
            {
                //-> Revenire normal
                setfillstyle(SOLID_FILL, WHITE);
                bar(b_start_game.lX+1, b_start_game.lY, b_start_game.rX, b_start_game.rY);
                text_butoane_start(3);
                break;
            }

        }
    }


}


void mod_de_joc()
{




}


//-> Main Core la Fisier
void sectiune_start()
{
    delay(2);
    //-> Coordonate cursor
    int x, y;

    //-> Variabile
    need_back = false;
    need_play = false;

    //-> Sincronizare fundal
    clearviewport();
    setbkcolor(COLOR(r_fundal, g_fundal, b_fundal));
    clearviewport();
    desenare_piese_jucatori();

    //-> Titlu pagina
    settextstyle(0, HORIZ_DIR, 5);
    char text[3][25] = {"Configurare Joc","Game Setup","Configuration du jeu"};
    if(limba == 0)
        outtextxy(rezX / 3.75, 20, text[limba]);

    if(limba == 1)
        outtextxy(rezX / 2.91, 20, text[limba]);

    if(limba == 2)
        outtextxy(rezX / 5.31, 20, text[limba]);

    ///-> Initializare butoane:
    // ** Buton Back
    rectangle(b_back_start.lX, b_back_start.lY - 2, b_back_start.rX, b_back_start.rY + 1);
    setfillstyle(SOLID_FILL, WHITE);
    bar(b_back_start.rX+1, b_back_start.lY, b_back_start.lX, b_back_start.rY);
    text_butoane_start(1);

    // ** Buton Start
    rectangle(b_start_game.lX, b_start_game.lY - 2, b_start_game.rX, b_start_game.rY + 1);
    setfillstyle(SOLID_FILL, WHITE);
    bar(b_start_game.lX+1, b_start_game.lY, b_start_game.rX, b_start_game.rY);
    text_butoane_start(3);

    // ** Mod de Joc
    settextstyle(0, HORIZ_DIR, 2);
    setbkcolor(COLOR(r_fundal, g_fundal, b_fundal));
    {
        char text[3][25] = {"Mod de Joc", "Game Mode", "Mode de jeu"};
        if(limba == 0)
            outtextxy(b_back_start.rX + 26, 170, text[limba]);

        if(limba == 1)
            outtextxy(b_back_start.rX + 34, 170, text[limba]);

        if(limba == 2)
            outtextxy(b_back_start.rX + 22, 170, text[limba]);
    }

    // ** Player vs Player
    readimagefile("img/pvp.jpg", b_back_start.rX + 18, 195, b_back_start.rX + 21 + 156, 293);
    setcolor(YELLOW);
    rectangle(b_back_start.rX + 18 - 2, 195 - 2, b_back_start.rX + 21 + 156 + 2, 295);
    setcolor(BLACK);


    // ** Player vs AI
    readimagefile("img/pvpc_gray.jpg", b_back_start.rX + 18, 313, b_back_start.rX + 21 + 156, 411);
    rectangle(b_back_start.rX + 18 - 2, 313 - 2, b_back_start.rX + 21 + 156 + 2, 413);
    setcolor(BLACK);


    casute_color();




    while(need_back == false && need_play == false)
    {


        //show_mouse_xy();

        //-> Citire coordonate
        x = mousex();
        y = mousey();

        //-> Buton Back
        buton_back_start(x, y,0);
        show_mouse_xy();

        //-> Buton Start
        buton_start_game(x, y);

        //-> Selectie mod de Joc


        delay(1);
    }

    //-> Back
    delay(100);
    if(need_back == true)
        {scriere_date_player();
            afisMenu();}
    if(need_play == true)
        {scriere_date_player();
            start_joc_pvp();

        }


}


#endif // START_H_INCLUDED
