#ifndef SCRIPTS_H_INCLUDED
#define SCRIPTS_H_INCLUDED

#include "settings.h"

/**

    -> README <-

    **Acest fisier contine mai multe scripturi ajutatoare pentru a determina
      chestii despre joc, pozitia mousului, altele..

    **Continut:
    -> show_mouse_xy():
      *Arata in timp real coordonatele cursorului




*/





void show_mouse_xy(){

    int x, y;
    char xx[30], yy[30];

    // -> Setare pentru viewport
    setviewport(50, 30, 100, 90, 1);
    clearviewport();
    setcolor(BLACK);

    while(true){


        // -> Sincronizare cu fundal
        setbkcolor(COLOR(r_fundal, g_fundal, b_fundal));
        clearviewport();

        // -> Citire coorodnate
        x = mousex();
        y = mousey();

        // -> Transformare coordonate in String
        itoa(x, xx, 10);
        itoa(y, yy, 10);

        // -> Afisare coordonate
        settextstyle(10, HORIZ_DIR, 1);
        outtextxy(3, 5, xx);
        outtextxy(3, 25, yy);

        delay(10);

    }


}


#endif // SCRIPTS_H_INCLUDED
