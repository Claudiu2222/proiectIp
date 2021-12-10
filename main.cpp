#include <winbgim.h>
#include <graphics.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <windows.h>
#include <mmsystem.h>

#include "meniu.h"

int main()
{
    incarcare_date();
    initwindow(rezX, rezY, "BonoL");
    afisMenu();
    if (need_exit) closegraph();
    return 0;
}
