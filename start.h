#ifndef START_H_INCLUDED
#define START_H_INCLUDED

#include "scripts.h"
#include "joc.h"







//-> Variabile
bool need_stop = false,
     need_back = false;



//-> Functii
void text_butoane_start(char a){

    //-> Buton de Back
    if (a == 1){
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

    if (a == 2){
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
    if (a == 3){
        settextstyle(0, HORIZ_DIR, 2);
        setbkcolor(WHITE);
        char text[3][25] = {">Start Joc<",">Start Game<",">D�marrer jeu<"};
        if(limba == 0)
            outtextxy(b_start_game.lX + 24, 612, text[limba]);

        if(limba == 1)
            outtextxy(b_start_game.lX + 17, 612, text[limba]);

        if(limba == 2)
            outtextxy(b_start_game.lX + 2, 612, text[limba]);
    }

    if (a == 4){
        settextstyle(0, HORIZ_DIR, 2);
        setbkcolor(GREEN);
        char text[3][25] = {">Start Joc<",">Start Game<",">D�marrer jeu<"};
        if(limba == 0)
            outtextxy(b_start_game.lX + 24, 612, text[limba]);

        if(limba == 1)
            outtextxy(b_start_game.lX + 17, 612, text[limba]);

        if(limba == 2)
            outtextxy(b_start_game.lX + 2, 612, text[limba]);
    }
}



void buton_back_start(int x, int y){


    if(x < b_back_start.lX && x > b_back_start.rX && y > b_back_start.lY && y < b_back_start.rY){

        //-> Highlight buton
        setfillstyle(SOLID_FILL, RED);
        bar(b_back_start.rX+1, b_back_start.lY, b_back_start.lX, b_back_start.rY);
        text_butoane_start(2);

        while(true){

            x = mousex();
            y = mousey();

            if ((GetKeyState(VK_LBUTTON) & 0x80)!=0){
                    setbkcolor(COLOR(r_fundal, g_fundal, b_fundal));
                    clearviewport();
                    need_back = true;
                    need_stop = true;

                    break;
            }

            if(!(x < b_back_start.lX && x > b_back_start.rX && y > b_back_start.lY && y < b_back_start.rY)){
                //-> Revenire normal
                setfillstyle(SOLID_FILL, WHITE);
                bar(b_back_start.rX+1, b_back_start.lY, b_back_start.lX, b_back_start.rY);
                text_butoane_start(1);
                break;
            }

        }
    }

}


void buton_start_game(int x, int y){

    if(x > b_start_game.lX && x < b_start_game.rX && y > b_start_game.lY && y < b_start_game.rY){

        //-> Highlight Buton
        setfillstyle(SOLID_FILL, GREEN);
        bar(b_start_game.lX+1, b_start_game.lY, b_start_game.rX, b_start_game.rY);
        text_butoane_start(4);

        while(true){

            x = mousex();
            y = mousey();


            if ((GetKeyState(VK_LBUTTON) & 0x80)!=0){
                    setbkcolor(COLOR(r_fundal, g_fundal, b_fundal));
                    clearviewport();
                    start_joc();
                    break;
            }


            if(!(x > b_start_game.lX && x < b_start_game.rX && y > b_start_game.lY && y < b_start_game.rY)){
                //-> Revenire normal
                setfillstyle(SOLID_FILL, WHITE);
                bar(b_start_game.lX+1, b_start_game.lY, b_start_game.rX, b_start_game.rY);
                text_butoane_start(3);
                break;
            }

        }
    }


}


void mod_de_joc(){




}


//-> Main Core la Fisier
void sectiune_start(){

    //-> Coordonate cursor
    int x, y;

    //-> Sincronizare fundal
    clearviewport();
    setbkcolor(COLOR(r_fundal, g_fundal, b_fundal));
    clearviewport();


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
    {char text[3][25] = {"Mod de Joc", "Game Mode", "Mode de jeu"};
    if(limba == 0)
        outtextxy(b_back_start.rX + 26, 170, text[limba]);

    if(limba == 1)
        outtextxy(b_back_start.rX + 34, 170, text[limba]);

    if(limba == 2)
        outtextxy(b_back_start.rX + 22, 170, text[limba]);}

    // ** Player vs Player
    readimagefile("img/pvp.jpg", b_back_start.rX + 18, 195, b_back_start.rX + 21 + 156, 293);
    setcolor(YELLOW);
    rectangle(b_back_start.rX + 18 - 2, 195 - 2, b_back_start.rX + 21 + 156 + 2, 295);
    setcolor(BLACK);


    // ** Player vs AI
    readimagefile("img/pvpc_gray.jpg", b_back_start.rX + 18, 313, b_back_start.rX + 21 + 156, 411);
    rectangle(b_back_start.rX + 18 - 2, 313 - 2, b_back_start.rX + 21 + 156 + 2, 413);
    setcolor(BLACK);






    while(!need_stop){


            //show_mouse_xy();

            //-> Citire coordonate
            x = mousex();
            y = mousey();

            //-> Buton Back
            buton_back_start(x, y);


            //-> Buton Start
            buton_start_game(x, y);

            //-> Selectie mod de Joc


            delay(1);
    }

    //-> Back
    if (need_back){
        need_stop = false;
        need_back = false;
        afisMenu();
    }


}


#endif // START_H_INCLUDED