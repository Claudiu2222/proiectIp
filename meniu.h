#ifndef MENIU
#define MENIU
#include "coordonate.h"
#include "settings.h"

#define NEGRU 0, 0, 0

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
        char b_st_text[3][13] = {">Setari<",">Settings<",">Param�tres<"};
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

    int x, y;

    while(true)
    {
        x = mousex();
        y = mousey();
        delay(2);



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



                afisare_text_meniu(1);


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
    setlinestyle(SOLID_LINE,0,5 );
    clearviewport();
    setbkcolor(COLOR(r_fundal, g_fundal, b_fundal));

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



    meniu_selectie();

}
/* ---TODO---


void buton_muzica(int alegere)
{

}*/

#endif // MENIU