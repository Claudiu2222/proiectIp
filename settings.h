#ifndef SETTINGS
#define SETTINGS
#include "fisier.h"

void afisMenu();
void buton_muzica(int alegere);
void selectare_buton_muzica(int x, int y, bool &muzica_on);
void afisare_text_settings(int alegere)
{
    if(alegere == 0)
    {
        setbkcolor(COLOR(r_fundal, g_fundal, b_fundal));
        settextstyle(0, HORIZ_DIR, 8);
        char text[3][11] = {"Setari","Settings","Paramètres"};
        if(limba == 0)
            outtextxy((rezX / 2) - 260+ 60, 20, text[limba]);
        if(limba == 1)
            outtextxy((rezX / 2) - 260, 20, text[limba]);
        if(limba == 2)
            outtextxy((rezX / 2) - 260 - 70, 20, text[limba]);
    }
    else if(alegere == 1)
    {
        settextstyle(0, HORIZ_DIR, 2);
        char b_b_text[3][9] = {">Inapoi<",">Back<",">Retour<"};

        if(limba == 0)
            outtextxy((b_settings_back.lX + b_settings_back.rX) / 2 - (lungime / 4) + 11 - 14, (b_settings_back.rY + b_settings_back.lY) / 2 - (inaltime / 8) + 4, b_b_text[limba]);
        if(limba == 1)
            outtextxy((b_settings_back.lX + b_settings_back.rX) / 2 - (lungime / 4) + 11, (b_settings_back.rY + b_settings_back.lY) / 2 - (inaltime / 8) + 4, b_b_text[limba]);
        if(limba == 2)
            outtextxy((b_settings_back.lX + b_settings_back.rX) / 2 - (lungime / 4) + 11 - 14, (b_settings_back.rY + b_settings_back.lY) / 2 - (inaltime / 8) + 4, b_b_text[limba]);
    }
    else if(alegere == 2)
    {
        setbkcolor(COLOR(r_fundal, g_fundal, b_fundal));
        settextstyle(0, HORIZ_DIR, 5);
        char text[3][9] = {"Limba","Language","Langue"};
        if(limba == 0)
            outtextxy((rezX / 2) - 170 + 70, 110, text[limba]);
        if(limba == 1)
            outtextxy((rezX / 2) - 170, 110, text[limba]);
        if(limba == 2)
            outtextxy((rezX / 2) - 170 + 50, 110, text[limba]);

    }
    else if(alegere == 3)
    {


        settextstyle(0, HORIZ_DIR, 2);
        char b_a_text[3][12] = {">Aplica<",">Apply<",">Appliquer<"};

        if(limba == 0)
            outtextxy((b_settings_apply.lX + b_settings_apply.rX) / 2 - (lungime / 4) + 11 - 14, (b_settings_apply.rY + b_settings_apply.lY) / 2 - (inaltime / 8) + 4, b_a_text[limba]);
        if(limba == 1)
            outtextxy((b_settings_apply.lX + b_settings_apply.rX) / 2 - (lungime / 4) + 11 - 10, (b_settings_apply.rY + b_settings_apply.lY) / 2 - (inaltime / 8) + 4, b_a_text[limba]);
        if(limba == 2)
            outtextxy((b_settings_apply.lX + b_settings_apply.rX) / 2 - (lungime / 4) + 11 - 37, (b_settings_apply.rY + b_settings_apply.lY) / 2 - (inaltime / 8) + 4, b_a_text[limba]);
    }
    else if(alegere == 4)
    {
         setbkcolor(COLOR(r_fundal, g_fundal, b_fundal));
        settextstyle(0, HORIZ_DIR, 5);
        char text[3][11] = {"Fundal","Background","Fond"};
        if(limba == 0)
            outtextxy((rezX / 2) - 170 + 60, 400, text[limba]);
        if(limba == 1)
            outtextxy((rezX / 2) - 190, 400, text[limba]);
        if(limba == 2)
            outtextxy((rezX / 2) - 170 + 90, 400, text[limba]);
    }
}





void afisare_butoane_settings( char tip)
{
    if(tip == 'A')
    {
        setcolor(BLACK);

        rectangle(b_settings_apply.lX+1, b_settings_apply.lY, b_settings_apply.rX-1, b_settings_apply.rY);
        setfillstyle(SOLID_FILL, WHITE);
        bar(b_settings_apply.lX+1,b_settings_apply.lY+1, b_settings_apply.rX, b_settings_apply.rY);

        settextstyle(0, HORIZ_DIR, 2);
        char b_e_text[3][12] = {">Aplica<",">Apply<",">Appliquer<"};
        setbkcolor(WHITE);
        if(limba == 0)
            outtextxy((b_settings_apply.lX + b_settings_apply.rX) / 2 - (lungime / 4) + 11 - 14, (b_settings_apply.rY + b_settings_apply.lY) / 2 - (inaltime / 8) + 4, b_e_text[limba]);
        if(limba == 1)
            outtextxy((b_settings_apply.lX + b_settings_apply.rX) / 2 - (lungime / 4) + 11 - 10, (b_settings_apply.rY + b_settings_apply.lY) / 2 - (inaltime / 8) + 4, b_e_text[limba]);
        if(limba == 2)
            outtextxy((b_settings_apply.lX + b_settings_apply.rX) / 2 - (lungime / 4) + 11 - 37, (b_settings_apply.rY + b_settings_apply.lY) / 2 - (inaltime / 8) + 4, b_e_text[limba]);
        setbkcolor(COLOR(r_fundal,g_fundal,b_fundal));



    }
    else if(tip == 'B')
    {

        setcolor(BLACK);

        rectangle(b_settings_back.lX, b_settings_back.lY, b_settings_back.rX, b_settings_back.rY);
        setfillstyle(SOLID_FILL, WHITE);
        bar(b_settings_back.lX+1, b_settings_back.lY+1, b_settings_back.rX, b_settings_back.rY);

        settextstyle(0, HORIZ_DIR, 2);
        char b_e_text[3][9] = {">Inapoi<",">Back<",">Retour<"};
        setbkcolor(WHITE);
        if(limba == 0)
            outtextxy((b_settings_back.lX + b_settings_back.rX) / 2 - (lungime / 4) + 11 - 14, (b_settings_back.rY + b_settings_back.lY) / 2 - (inaltime / 8) + 4, b_e_text[limba]);
        if(limba == 1)
            outtextxy((b_settings_back.lX + b_settings_back.rX) / 2 - (lungime / 4) + 11, (b_settings_back.rY + b_settings_back.lY) / 2 - (inaltime / 8) + 4, b_e_text[limba]);
        if(limba == 2)
            outtextxy((b_settings_back.lX + b_settings_back.rX) / 2 - (lungime / 4) + 11 - 14, (b_settings_back.rY + b_settings_back.lY) / 2 - (inaltime / 8) + 4, b_e_text[limba]);
        setbkcolor(COLOR(r_fundal,g_fundal,b_fundal));



    }
}
void selectare_steag(int alegere)
{
    readimagefile("img/ro_gray.jpg",100,200,400,350);
    readimagefile("img/us_gray.jpg",490,200,790,350);
    readimagefile("img/fr_gray.jpg",880,200,1180,350);

    setcolor(BLACK);
    rectangle(98,198,402,352);
    rectangle(488,198,792,352);
    rectangle(878,198,1182,352);

    if(alegere == 0)
    {

        readimagefile("img/ro.jpg",100,200,400,350);
        rectangle(98,198,402,352);
    }
    else if(alegere == 1)
    {
        readimagefile("img/us.jpg",490,200,790,350);
        rectangle(488,198,792,352);
    }
    else if(alegere == 2)
    {

        readimagefile("img/fr.jpg",880,200,1180,350);
        rectangle(878,198,1182,352);

    }



}

void afisare_butoane_culori(int alegere, int alegere_2)
{
if(alegere_2 == 0)
{if(alegere == 0)
    {
        readimagefile("img/arrowup.jpg",391,490,463,519);
        rectangle(391,490,463,519);
    }
    else if(alegere == 1)
    {
        readimagefile("img/arrowdown.jpg",391,551,463,579);
        rectangle(391,551,463,579);
    }
    else if (alegere == 2)
    {
        readimagefile("img/arrowup.jpg",604,490,676,519);
        rectangle(604,490,676,519);
    }
    else if(alegere == 3)
    {
        readimagefile("img/arrowdown.jpg",604,551,676,579);
        rectangle(604,551,676,579);
    }
    else if(alegere == 4)
    {
        readimagefile("img/arrowup.jpg",817,490,889,519);
        rectangle(817,490,889,519);
    }
    else if (alegere == 5)
    {
        readimagefile("img/arrowdown.jpg",817,551,889,579);
        rectangle(817,551,889,579);
    }
}
else if(alegere_2 == 1)
{
    if(alegere == 0)
    {
        readimagefile("img/arrowup.jpg",280,270,320,289);
        rectangle(280,270,320,289);
    }
    else if(alegere == 1)
    {
        readimagefile("img/arrowdown.jpg",280,311,320,330);
        rectangle(280,311,320,330);
    }
    else if (alegere == 2)
    {
        readimagefile("img/arrowup.jpg",370,270,410,289);
        rectangle(370,270,410,289);
    }
    else if(alegere == 3)
    {
        readimagefile("img/arrowdown.jpg",370,311,410,330);
        rectangle(370,311,410,330);
    }
    else if(alegere == 4)
    {
        readimagefile("img/arrowup.jpg",460,270,500,289);
        rectangle(460,270,500,289);
    }
    else if (alegere == 5)
    {
        readimagefile("img/arrowdown.jpg",460,311,500,330);
        rectangle(460,311,500,330);
    }
}
else if(alegere_2 == 2)
{
    if(alegere == 0)
    {
        readimagefile("img/arrowup.jpg",1005,270,1045,289);
        rectangle(1005,270,1045,289);
    }
    else if(alegere == 1)
    {
        readimagefile("img/arrowdown.jpg",1005,311,1045,330);
        rectangle(1005,311,1045,330);
    }
    else if (alegere == 2)
    {
        readimagefile("img/arrowup.jpg",1095,270,1135,289);
        rectangle(1095,270,1135,289);
    }
    else if(alegere == 3)
    {
        readimagefile("img/arrowdown.jpg",1095,311,1135,330);
        rectangle(1095,311,1135,330);
    }
    else if(alegere == 4)
    {
        readimagefile("img/arrowup.jpg",1185,270,1225,289);
        rectangle(1185,270,1225,289);
    }
    else if (alegere == 5)
    {
        readimagefile("img/arrowdown.jpg",1185,311,1225,330);
        rectangle(1185,311,1225,330);
    }
}
/*rectangle(1005,290,1045,310);
    rectangle(1095,290,1135,310);
    rectangle(1185,290,1225,310);*/


}

void culoare_fundal(int x, int y, int &r_fundal_aux, int &g_fundal_aux, int &b_fundal_aux)
{ rectangle(391,520,463,550);
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
                    setbkcolor(COLOR(r_fundal_aux%255,g_fundal_aux%255 ,b_fundal_aux%255));
                    clearviewport();

                    afisare_butoane_culori(0,0);
                  if((GetKeyState(VK_LBUTTON) & 0x80)==0)
                    {setviewport(0,0,1280,720,0);
                setcolor(BLACK);
                afisare_butoane_culori(0,0);
                delay(2);
                break;
                    }
                }
                if((GetKeyState(VK_LBUTTON) & 0x80)==0)
                    {setviewport(0,0,1280,720,0);
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
                    {setviewport(0,0,1280,720,0);
                setcolor(BLACK);
                afisare_butoane_culori(1,0);
                delay(2);
                break;
                    }
                }
                if((GetKeyState(VK_LBUTTON) & 0x80)==0)
                    {setviewport(0,0,1280,720,0);
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
                    {setviewport(0,0,1280,720,0);
                setcolor(BLACK);
                afisare_butoane_culori(2,0);
                delay(2);
                break;
                    }
                }
                if((GetKeyState(VK_LBUTTON) & 0x80)==0)
                    {setviewport(0,0,1280,720,0);
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
                    {setviewport(0,0,1280,720,0);
                setcolor(BLACK);
                afisare_butoane_culori(3,0);
                delay(2);
                break;
                    }
                }
                if((GetKeyState(VK_LBUTTON) & 0x80)==0)
                    {setviewport(0,0,1280,720,0);
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
                    {setviewport(0,0,1280,720,0);
                setcolor(BLACK);
                afisare_butoane_culori(4,0);
                delay(2);
                break;
                    }
                }
                if((GetKeyState(VK_LBUTTON) & 0x80)==0)
                    {setviewport(0,0,1280,720,0);
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
                    {setviewport(0,0,1280,720,0);
                setcolor(BLACK);
                afisare_butoane_culori(5,0);
                delay(2);
                break;
                    }
                }
                if((GetKeyState(VK_LBUTTON) & 0x80)==0)
                    {setviewport(0,0,1280,720,0);
                setcolor(BLACK);
                afisare_butoane_culori(5,0);
                delay(2);
                break;
                    }

            }
        }
}
void selectare_limba(int x, int y, int &limba_aux)
{
      if(x >=100 && x <= 400 && y >= 200 && y <= 350)
        {

            while(true)
            {
                delay(2);

                x=mousex();
                y=mousey();


                setcolor(COLOR(255, 145, 0));
                rectangle(98,198,402,352);
                if((GetKeyState(VK_LBUTTON) & 0x80)!=0)
                {
                    delay(70);
                    limba_aux = 0;
                    selectare_steag(0);

                    break;
                }
                delay(2);
                if (!(x >=100 && x <= 400 && y >= 200 && y <= 350))
                {
                    setcolor(BLACK);
                    rectangle(98,198,402,352);

                    break;
                }

            }
        }
        if(x >=490 && x <= 790 && y >= 200 && y <= 350)
        {

            while(true)
            {
                delay(2);

                x=mousex();
                y=mousey();


                setcolor(COLOR(255, 145, 0));
                rectangle(488,198,792,352);
                if((GetKeyState(VK_LBUTTON) & 0x80)!=0)
                {
                    delay(70);
                    limba_aux = 1;

                    selectare_steag(1);

                    break;
                }
                delay(2);
                if (!(x >=490 && x <= 790 && y >= 200 && y <= 350))
                {
                    setcolor(BLACK);
                    rectangle(488,198,792,352);

                    break;
                }

            }
        }
        if(x >=880 && x <= 1180 && y >= 200 && y <= 350)
        {

            while(true)
            {
                delay(2);

                x=mousex();
                y=mousey();


                setcolor(COLOR(255, 145, 0));
                rectangle(878,198,1182,352);
                if((GetKeyState(VK_LBUTTON) & 0x80)!=0)
                {
                    delay(70);
                    limba_aux = 2;

                    selectare_steag(2);

                    break;
                }
                delay(2);
                if (!(x >=880 && x <= 1180 && y >= 200 && y <= 350))
                {
                    setcolor(BLACK);
                    rectangle(878,198,1182,352);
                    break;
                }

            }
        }
}
void buton_apply(int x, int y, int limba_aux,int r_fundal_aux, int g_fundal_aux, int b_fundal_aux, bool &_apply)
{
        if(x <= b_settings_apply.lX && x >= b_settings_apply.rX && y >= b_settings_apply.lY && y <= b_settings_apply.rY)
        {

            while(true)
            {
                delay(2);

                x=mousex();
                y=mousey();

                setfillstyle(SOLID_FILL, RED);
                bar(b_settings_apply.lX+1,b_settings_apply.lY+1, b_settings_apply.rX, b_settings_apply.rY);
                setbkcolor(RED);
                afisare_text_settings(3);
                if((GetKeyState(VK_LBUTTON) & 0x80)!=0)
                {

                    setfillstyle(SOLID_FILL, WHITE);
                    setbkcolor(WHITE);
                    limba = limba_aux;
                    r_fundal = r_fundal_aux;
                    g_fundal = g_fundal_aux;
                    b_fundal = b_fundal_aux;
                    scriere_date();
                    _apply = 1;
                    break;
                }
                if (!(x <= b_settings_apply.lX && x >= b_settings_apply.rX && y >= b_settings_apply.lY && y <= b_settings_apply.rY))
                    {
                    afisare_butoane_settings('A');
                    break;
                }

            }




        }

}
void buton_back(int x,int y, bool &_back)
{
      if(x >= b_settings_back.lX && x <= b_settings_back.rX && y >= b_settings_back.lY && y <= b_settings_back.rY)
        {

            while(true)
            {
                delay(2);

                x=mousex();
                y=mousey();
                setfillstyle(SOLID_FILL, RED);
                bar(b_settings_back.lX+1, b_settings_back.lY+1, b_settings_back.rX, b_settings_back.rY);
                setbkcolor(RED);
                afisare_text_settings(1);
                if((GetKeyState(VK_LBUTTON) & 0x80)!=0)
                {
                    _back = 1;
                    setfillstyle(SOLID_FILL, WHITE);
                    setbkcolor(WHITE);
                    break;
                }
                if (!(x >= b_settings_back.lX && x <= b_settings_back.rX && y >= b_settings_back.lY && y <= b_settings_back.rY))
                        {
                    afisare_butoane_settings('B');
                    break;
                }

            }




        }
}
void sectiune_settings()
{
    int limba_aux = limba;
    bool _back = 0, _apply = 0;
    int b_fundal_aux = b_fundal, r_fundal_aux = r_fundal, g_fundal_aux = g_fundal;


    setbkcolor(COLOR(r_fundal, g_fundal, b_fundal));
    clearviewport();
    afisare_butoane_settings('B') ;
    afisare_butoane_settings('A');
    selectare_steag(limba);

    afisare_butoane_culori(0,0);
    afisare_butoane_culori(1,0);
    afisare_butoane_culori(2,0);
    afisare_butoane_culori(3,0);
    afisare_butoane_culori(4,0);
    afisare_butoane_culori(5,0);
    afisare_text_settings(2);
    afisare_text_settings(0);
    afisare_text_settings(4);
    buton_muzica(muzica_on);
    int x = mousex();
    int y = mousey();


    while(_back == 0 && _apply == 0)
    {
        delay(2);

        x = mousex();

        y = mousey();


       culoare_fundal(x,y,r_fundal_aux,g_fundal_aux,b_fundal_aux);
        selectare_buton_muzica(x, y, muzica_on);
        selectare_limba(x,y,limba_aux);

        buton_apply(x, y,  limba_aux, r_fundal_aux, g_fundal_aux, b_fundal_aux, _apply);


       buton_back( x,y, _back);

    }
    delay(100);
    if(_back == 1)
        afisMenu();
    if (_apply == 1)
        sectiune_settings();


}



#endif // SETTINGS
