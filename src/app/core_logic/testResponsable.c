#include <stdio.h>
#include "responsable.h"
#include "../interface/interface_resp.h"

int main (void)
{
    int tPhysique = 10, tRef[10], tLogique = 0;
    float tPoids[10], tVol[10], tPrix[10];
    tLogique = chargementArticles( tRef, tPoids, tVol, tPrix, tPhysique);
    affichArticles( tRef, tPoids, tVol, tPrix, tLogique);
    return 0;
}