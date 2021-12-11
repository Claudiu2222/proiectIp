#ifndef START_H_INCLUDED
#define START_H_INCLUDED

#include "scripts.h"








//-> Variabile
bool need_stop = false,
     need_back = false;



//-> Functii
void text_butoane_start(char a){

    //-> Buton de Back
    if (a == 1){
        settextstyle(10, HORIZ_DIR, 3);
        setbkcolor(WHITE);
        char text[3][25] = {"Inapoi","Back","Retour"};
        if(limba == 0)
            outtextxy(b_back_start.rX / 0.46, 609, text[limba]);

        if(limba == 1)
            outtextxy(b_back_start.rX / 0.415, 609, text[limba]);

        if(limba == 2)
            outtextxy(b_back_start.rX / 0.46, 609, text[limba]);

    }

    if (a == 2){
        settextstyle(10, HORIZ_DIR, 3);
        setbkcolor(RED);
        char text[3][25] = {"Inapoi","Back","Retour"};
        if(limba == 0)
            outtextxy(b_back_start.rX / 0.46, 609, text[limba]);

        if(limba == 1)
            outtextxy(b_back_start.rX / 0.415, 609, text[limba]);

        if(limba == 2)
            outtextxy(b_back_start.rX / 0.46, 609, text[limba]);
    }

    //-> Buton de Start
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


void buton_start_game(){


}


void mod_de_joc(){




}


//-> Main Core la Fisier
void sectiune_start(){

    //-> Coordonate cursor
    int x, y;

    //-> Sincronizare fundal
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




    while(!need_stop){



            //-> Citire coordonate
            x = mousex();
            y = mousey();

            //-> Buton Back
            buton_back_start(x, y);



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
