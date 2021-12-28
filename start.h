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
void desenare_culori_piese(int alegere) //deseneaza patratele pt fiecare player in meniul de start
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
    {
        setfillstyle(SOLID_FILL,COLOR(r_player_2,g_player_2,b_player_2));
        bar(853,203,948,298);
        bar(653,303,748,398);
        bar(753,303,848,398);
        bar(853,303,948,398);
    }
}
void casute_color() // asta teoretic face toate patrulaterele de la butoane, afiseaza toate imaginile pt sageti (la butoane)
{
    setlinestyle(SOLID_LINE,0,5);
     desenare_culori_piese(0);
    desenare_culori_piese(1);
    rectangle(280,290,320,310);
    rectangle(370,290,410,310);
    rectangle(460,290,500,310);
    rectangle(1005,290,1045,310);
    rectangle(1095,290,1135,310);
    rectangle(1185,290,1225,310);
    line(b_color[1][1].rX,b_color[1][1].lY,b_color[1][3].lX,b_color[1][3].lY);
    line(b_color[1][3].rX,b_color[1][3].lY,b_color[1][5].lX,b_color[1][5].lY);
    line(b_color[1][2].rX,b_color[1][2].rY,b_color[1][4].lX,b_color[1][4].rY);
    line(b_color[1][4].rX,b_color[1][4].rY,b_color[1][6].lX,b_color[1][6].rY);
     line(b_color[2][1].rX,b_color[2][1].lY,b_color[2][3].lX,b_color[2][3].lY);
    line(b_color[2][3].rX,b_color[2][3].lY,b_color[2][5].lX,b_color[2][5].lY);
    line(b_color[2][2].rX,b_color[2][2].rY,b_color[2][4].lX,b_color[2][4].rY);
    line(b_color[2][4].rX,b_color[2][4].rY,b_color[2][6].lX,b_color[2][6].rY);
    line(b_color[1][3].rX,b_color[1][3].lY,b_color[1][5].lX,b_color[1][5].lY);
    line(b_color[1][1].rX,b_color[1][1].lY,b_color[1][4].lX,b_color[1][4].rY);
    line(b_color[1][3].rX,b_color[1][3].lY,b_color[1][6].lX,b_color[1][6].rY);
    line(b_color[1][2].rX,b_color[1][2].rY,b_color[1][3].lX,b_color[1][3].lY);
    line(b_color[1][4].rX,b_color[1][4].rY,b_color[1][5].lX,b_color[2][5].lY);
    line(b_color[2][1].rX,b_color[2][1].lY,b_color[2][4].lX,b_color[2][4].rY);
    line(b_color[2][3].rX,b_color[2][3].lY,b_color[2][6].lX,b_color[2][6].rY);
    line(b_color[2][2].rX,b_color[2][2].rY,b_color[2][3].lX,b_color[2][3].lY);
    line(b_color[2][4].rX,b_color[2][4].rY,b_color[2][5].lX,b_color[2][5].lY);

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



}
void init_coord_butoane_culori()  // folosesc o fct sa memorez coordonatele pt cele 2 seturi de butoane de culori ( ma ajuta in functia urmatoare
                                 // sa scriu mai putine linii de cod ( pot face  1 functie pt ambele seturi de butoane, in loc de 2 separate)
{
    b_color[1][1].lX=280;
    b_color[1][1].lY=270;
    b_color[1][1].rX=320;
    b_color[1][1].rY=289;
    b_color[1][2].lX=280; //280,311,320,330
    b_color[1][2].lY=311;
    b_color[1][2].rX=320;
    b_color[1][2].rY=330;
    b_color[1][3].lX=370; // 370,270,410,289
    b_color[1][3].lY=270;
    b_color[1][3].rX=410;
    b_color[1][3].rY=289;
    b_color[1][4].lX=370; // 370,311,410,330
    b_color[1][4].lY=311;
    b_color[1][4].rX=410;
    b_color[1][4].rY=330;
    b_color[1][5].lX=460; // 460,270,500,289
    b_color[1][5].lY=270;
    b_color[1][5].rX=500;
    b_color[1][5].rY=289;
    b_color[1][6].lX=460; // 460,311,500,330
    b_color[1][6].lY=311;
    b_color[1][6].rX=500;
    b_color[1][6].rY=330;
    b_color[2][1].lX=1005; // 1005,270,1045,289
    b_color[2][1].lY=270;
    b_color[2][1].rX=1045;
    b_color[2][1].rY=289;
    b_color[2][2].lX=1005; // 1005,311,1045,330
    b_color[2][2].lY=311;
    b_color[2][2].rX=1045;
    b_color[2][2].rY=330;
    b_color[2][3].lX=1095; // 1095,270,1135,289
    b_color[2][3].lY=270;
    b_color[2][3].rX=1135;
    b_color[2][3].rY=289;
    b_color[2][4].lX=1095; // 1095,311,1135,330
    b_color[2][4].lY=311;
    b_color[2][4].rX=1135;
    b_color[2][4].rY=330;
    b_color[2][5].lX=1185; // 1185,270,1225,289
    b_color[2][5].lY=270;
    b_color[2][5].rX=1225;
    b_color[2][5].rY=289;
    b_color[2][6].lX=1185; //1185,311,1225,330
    b_color[2][6].lY=311;
    b_color[2][6].rX=1225;
    b_color[2][6].rY=330;

}
void culoare_player(int x, int y, int &r_fundal_aux, int &g_fundal_aux, int &b_fundal_aux, int k) // k = alege setul de butoane 1 sau 2
{                                                                                               // si schimba culorile
                                                                            // in fisier.h am adaugat si o functie ce scrie in alt fisier txt
                                                                            //culorile playerilor ( pt a fi salvate si reutilizate)
                                                                            // aceasta functie de scriere gasita in fisier.h se apeleaza la
                                                                            //apasarea butonului start sau back

    if(x >= b_color[k][1].lX && x <= b_color[k][1].rX && y >=b_color[k][1].lY && y<=b_color[k][1].rY)
    {
        while(true)
        {

            x=mousex();
            y=mousey();




            while((GetKeyState(VK_LBUTTON) & 0x80)!=0)
            {
                delay(15);
                readimagefile("img/arrowupred.jpg",b_color[k][1].lX,b_color[k][1].lY,b_color[k][1].rX,b_color[k][1].rY);
                setcolor(COLOR(255,0,0));
                rectangle(b_color[k][1].lX,b_color[k][1].lY,b_color[k][1].rX,b_color[k][1].rY);


                if(r_fundal_aux%255 < 254)
                    r_fundal_aux++;
                desenare_culori_piese(k-1);



                if((GetKeyState(VK_LBUTTON) & 0x80)==0)
                {

                    setcolor(BLACK);
                    afisare_butoane_culori(0,k);
                    delay(2);
                    break;
                }
            }
            if((GetKeyState(VK_LBUTTON) & 0x80)==0)
            {
                setcolor(BLACK);
                afisare_butoane_culori(0,k);
                delay(2);
                break;
            }

        }
    }
    if(x >= b_color[k][2].lX && x <= b_color[k][2].rX && y >=b_color[k][2].lY && y<=b_color[k][2].rY)
    {
        while(true)
        {

            x=mousex();
            y=mousey();




            while((GetKeyState(VK_LBUTTON) & 0x80)!=0)
            {
                delay(15);
                readimagefile("img/arrowdownred.jpg",b_color[k][2].lX,b_color[k][2].lY,b_color[k][2].rX,b_color[k][2].rY);
                setcolor(COLOR(255,0,0));
                rectangle(b_color[k][2].lX,b_color[k][2].lY,b_color[k][2].rX,b_color[k][2].rY);


                if(r_fundal_aux%255 > 1)
                    r_fundal_aux--;
                desenare_culori_piese(k-1);

                if((GetKeyState(VK_LBUTTON) & 0x80)==0)
                {

                    setcolor(BLACK);
                    afisare_butoane_culori(1,k);
                    delay(2);
                    break;
                }
            }
            if((GetKeyState(VK_LBUTTON) & 0x80)==0)
            {

                setcolor(BLACK);
                afisare_butoane_culori(1,k);
                delay(2);
                break;
            }

        }
    }
    if(x >= b_color[k][3].lX && x <= b_color[k][3].rX && y >=b_color[k][3].lY && y<=b_color[k][3].rY)
    {
        while(true)
        {

            x=mousex();
            y=mousey();




            while((GetKeyState(VK_LBUTTON) & 0x80)!=0)
            {
                delay(15);
                readimagefile("img/arrowupred.jpg",b_color[k][3].lX,b_color[k][3].lY,b_color[k][3].rX,b_color[k][3].rY);
                setcolor(COLOR(255,0,0));
                rectangle(b_color[k][3].lX,b_color[k][3].lY,b_color[k][3].rX,b_color[k][3].rY);


                if(g_fundal_aux%255 < 254)
                    g_fundal_aux++;
                desenare_culori_piese(k-1);


                if((GetKeyState(VK_LBUTTON) & 0x80)==0)
                {

                    setcolor(BLACK);
                    afisare_butoane_culori(2,k);
                    delay(2);
                    break;
                }
            }
            if((GetKeyState(VK_LBUTTON) & 0x80)==0)
            {

                setcolor(BLACK);
                afisare_butoane_culori(2,k);
                delay(2);
                break;
            }

        }
    }
    if(x >= b_color[k][4].lX && x <= b_color[k][4].rX && y >=b_color[k][4].lY && y<=b_color[k][4].rY)
    {
        while(true)
        {

            x=mousex();
            y=mousey();




            while((GetKeyState(VK_LBUTTON) & 0x80)!=0)
            {delay(15);
                readimagefile("img/arrowdownred.jpg",b_color[k][4].lX,b_color[k][4].lY,b_color[k][4].rX,b_color[k][4].rY);
                setcolor(COLOR(255,0,0));
                rectangle(b_color[k][4].lX,b_color[k][4].lY,b_color[k][4].rX,b_color[k][4].rY);
                if(g_fundal_aux%255 > 1)
                    g_fundal_aux--;
                desenare_culori_piese(k-1);

                if((GetKeyState(VK_LBUTTON) & 0x80)==0)
                {

                    setcolor(BLACK);
                    afisare_butoane_culori(3,k);
                    delay(2);
                    break;
                }
            }
            if((GetKeyState(VK_LBUTTON) & 0x80)==0)
            {

                setcolor(BLACK);
                afisare_butoane_culori(3,k);
                delay(2);
                break;
            }

        }
    }
      if(x >= b_color[k][5].lX && x <= b_color[k][5].rX && y >=b_color[k][5].lY && y<=b_color[k][5].rY)
    {
        while(true)
        {

            x=mousex();
            y=mousey();




            while((GetKeyState(VK_LBUTTON) & 0x80)!=0)
            {delay(15);
                readimagefile("img/arrowupred.jpg",b_color[k][5].lX,b_color[k][5].lY,b_color[k][5].rX,b_color[k][5].rY);
                setcolor(COLOR(255,0,0));
                rectangle(b_color[k][5].lX,b_color[k][5].lY,b_color[k][5].rX,b_color[k][5].rY);
                if(b_fundal_aux%255 < 254)
                    b_fundal_aux++;
                desenare_culori_piese(k-1);

                if((GetKeyState(VK_LBUTTON) & 0x80)==0)
                {

                    setcolor(BLACK);
                    afisare_butoane_culori(4,k);
                    delay(2);
                    break;
                }
            }
            if((GetKeyState(VK_LBUTTON) & 0x80)==0)
            {

                setcolor(BLACK);
                afisare_butoane_culori(4,k);
                delay(2);
                break;
            }

        }
    }
          if(x >= b_color[k][6].lX && x <= b_color[k][6].rX && y >=b_color[k][6].lY && y<=b_color[k][6].rY)
    {
        while(true)
        {

            x=mousex();
            y=mousey();




            while((GetKeyState(VK_LBUTTON) & 0x80)!=0)
            {delay(15);
                readimagefile("img/arrowdownred.jpg",b_color[k][6].lX,b_color[k][6].lY,b_color[k][6].rX,b_color[k][6].rY);
                setcolor(COLOR(255,0,0));
                rectangle(b_color[k][6].lX,b_color[k][6].lY,b_color[k][6].rX,b_color[k][6].rY);
                if(b_fundal_aux%255 > 1)
                    b_fundal_aux--;
                desenare_culori_piese(k-1);

                if((GetKeyState(VK_LBUTTON) & 0x80)==0)
                {

                    setcolor(BLACK);
                    afisare_butoane_culori(5,k);
                    delay(2);
                    break;
                }
            }
            if((GetKeyState(VK_LBUTTON) & 0x80)==0)
            {

                setcolor(BLACK);
                afisare_butoane_culori(5,k);
                delay(2);
                break;
            }

        }
    }
}

void imagini_mod_de_joc(int alegere)
{
       // ** Player vs Player

    setcolor(BLACK);
    readimagefile("img/pvp_gray.jpg", b_back_start.rX + 18, 195, b_back_start.rX + 21 + 156, 293);
    rectangle(b_back_start.rX + 18 - 2, 195 - 2, b_back_start.rX + 21 + 156 + 2, 295);

    readimagefile("img/easy_gray.jpg", 68, 431, 138, 481);
    rectangle(68 - 2, 431 - 2, 138 + 2, 481+2);
    readimagefile("img/hard_gray.jpg", 157, 431, 227, 481);
    rectangle(157 - 2, 431 - 2, 227 + 2, 481+2);



    // ** Player vs AI
    readimagefile("img/pvpc_gray.jpg", b_back_start.rX + 18, 313, b_back_start.rX + 21 + 156, 411);
    rectangle(b_back_start.rX + 18 - 2, 313 - 2, b_back_start.rX + 21 + 156 + 2, 413);
setcolor(YELLOW);
 if(alegere == 1)
 {
    readimagefile("img/pvp.jpg", b_back_start.rX + 18, 195, b_back_start.rX + 21 + 156, 293);
    rectangle(b_back_start.rX + 18 - 2, 195 - 2, b_back_start.rX + 21 + 156 + 2, 295);

 }
 else if (alegere == 2)
 {

    readimagefile("img/pvpc.jpg", b_back_start.rX + 18, 313, b_back_start.rX + 21 + 156, 411);
    rectangle(b_back_start.rX + 16, 311, b_back_start.rX + 23 + 156, 413);

    readimagefile("img/easy.jpg", 68, 431, 138, 481);

    readimagefile("img/hard.jpg", 157, 431, 227, 481);
    if(dificultate == 1)
    { setcolor(YELLOW);
        rectangle(68 - 2, 431 - 2, 138 + 2, 481 + 2);
    setcolor(BLACK);
        rectangle(157 - 2, 431 - 2, 227 + 2, 481 + 2);
    }
    else if (dificultate == 2)
    {
        setcolor(YELLOW);
        rectangle(157 - 2, 431 - 2, 227 + 2, 481 + 2);

    setcolor(BLACK);
        rectangle(68 - 2, 431 - 2, 138 + 2, 481 + 2);
    }
 }
 setcolor(BLACK);
 }

void selectare_mod_de_joc(int x, int y )
{//     readimagefile("img/pvp.jpg", b_back_start.rX + 18, 195, b_back_start.rX + 21 + 156, 293);
      if(x >=b_back_start.rX +18&& x <= b_back_start.rX + 177 && y >= 195 && y <= 293)
        {

            while(true)
            {
                delay(2);

                x=mousex();
                y=mousey();


                setcolor(COLOR(255, 145, 0));
                rectangle(b_back_start.rX + 18 - 2, 195 - 2, b_back_start.rX + 21 + 156 + 2, 295);
                if((GetKeyState(VK_LBUTTON) & 0x80)!=0)
                {
                    delay(70);
                    mod_joc = 1;
                    imagini_mod_de_joc(mod_joc);

                    break;
                }
                delay(2);
                if (!(x >=b_back_start.rX +18&& x <= b_back_start.rX + 177 && y >= 195 && y <= 293))
                {
                    if(mod_joc == 2)
                    setcolor(BLACK);
                    else
                     setcolor(YELLOW);
            rectangle(b_back_start.rX + 18 - 2, 195 - 2, b_back_start.rX + 21 + 156 + 2, 295);

                    break;
                }

            }
        }
        /*    readimagefile("img/pvpc_gray.jpg", b_back_start.rX + 18, 313, b_back_start.rX + 21 + 156, 411);
    rectangle(b_back_start.rX + 18 - 2, 313 - 2, b_back_start.rX + 21 + 156 + 2, 413);*/
        if(x >=b_back_start.rX +18&& x <= b_back_start.rX + 177 && y >= 313 && y <= 411)
        {

            while(true)
            {
                delay(2);

                x=mousex();
                y=mousey();


                setcolor(COLOR(255, 145, 0));
                 rectangle(b_back_start.rX + 18 - 2, 313 - 2, b_back_start.rX + 21 + 156 + 2, 413);
                if((GetKeyState(VK_LBUTTON) & 0x80)!=0)
                {
                    delay(70);
                    mod_joc = 2;
                    imagini_mod_de_joc(mod_joc);

                    break;
                }
                delay(2);
                if (!(x >=b_back_start.rX +18&& x <= b_back_start.rX + 177 && y >= 313 && y <= 411))
                {
                    if(mod_joc == 1)
                    setcolor(BLACK);
                    else
                     setcolor(YELLOW);
          rectangle(b_back_start.rX + 18 - 2, 313 - 2, b_back_start.rX + 21 + 156 + 2, 413);

                    break;
                }

            }
        }
        if(mod_joc == 2)
        {
             if(x >=68&& x <= 138 && y >= 431 && y <= 481)
        {
            /*readimagefile("img/easy.jpg", 68, 431, 138, 481);

    readimagefile("img/hard.jpg", 157, 431, 227, 481);*/

            while(true)
            {
                delay(2);

                x=mousex();
                y=mousey();


                setcolor(COLOR(255, 145, 0));
                 rectangle(68- 2, 431 - 2, 138 + 2, 481 + 2);
                if((GetKeyState(VK_LBUTTON) & 0x80)!=0)
                {
                    delay(70);
                    dificultate = 1;
                    imagini_mod_de_joc(mod_joc);

                    break;
                }
                delay(2);
                if (!(x >=68&& x <= 138 && y >= 431 && y <= 481))
                {
                    if(dificultate == 2)
                    setcolor(BLACK);
                    else
                     setcolor(YELLOW);
          rectangle(68- 2, 431 - 2, 138 + 2, 481 + 2);

                    break;
                }

            }
        }
        if(x >=157&& x <= 227 && y >= 431 && y <= 481)
        {
            /*readimagefile("img/easy.jpg", 68, 431, 138, 481);

    readimagefile("img/hard.jpg", 157, 431, 227, 481);*/

            while(true)
            {
                delay(2);

                x=mousex();
                y=mousey();


                setcolor(COLOR(255, 145, 0));
                 rectangle(157- 2, 431 - 2, 227 + 2, 481 + 2);
                if((GetKeyState(VK_LBUTTON) & 0x80)!=0)
                {
                    delay(70);
                    dificultate = 2;
                    imagini_mod_de_joc(mod_joc);

                    break;
                }
                delay(2);
                if (!(x >=157&& x <= 227 && y >= 431 && y <= 481))
                {
                    if(dificultate == 1)
                    setcolor(BLACK);
                    else
                     setcolor(YELLOW);
          rectangle(157- 2, 431 - 2, 227 + 2, 481 + 2);

                    break;
                }

            }
        }
        }
        setcolor(BLACK);

}
void buton_back_start(int x, int y, int alegere)
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


    imagini_mod_de_joc(mod_joc);

    init_coord_butoane_culori();

    casute_color();

    while(need_back == false && need_play == false)
    {

       // show_mouse_xy();

        //-> Citire coordonate
        x = mousex();
        y = mousey();

        //-> Buton Back
        buton_back_start(x, y,0);
        culoare_player(x,y,r_player_1,g_player_1,b_player_1,1);
        culoare_player(x,y,r_player_2,g_player_2,b_player_2,2);
        selectare_mod_de_joc(x,y);
        //-> Buton Start
        buton_start_game(x, y);

        //-> Selectie mod de Joc


        delay(1);
    }

    //-> Back
    delay(100);
    if(need_back == true)
    {
        scriere_date_player();
        afisMenu();
    }
    if(need_play == true && mod_joc == 1)
    {
        scriere_date_player();
        start_joc_pvp();

    }
    else if(need_play == true && mod_joc == 2 && dificultate == 1)
    {
        scriere_date_player();
        // start_joc_pvpc ez

    }
    else if(need_play == true && mod_joc == 2 && dificultate == 2)
    {
        scriere_date_player();
        // start_joc_pvpc hARD

    }


}


#endif // START_H_INCLUDED
