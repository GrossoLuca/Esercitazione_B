#include<iostream>

#include "CQuadrilateral.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CDisplay.h"

const int LISTL=6; 

Quadrilateral* quadList[LISTL];

void Show() {
	
	int i; 
	
	for (i=0; i<LISTL; i++)
		quadList[i]->Drawing();
	
}


int main() 
{/*			MAIN PER TEST FORMAT
	 
	Format f1, f2;
	
	f1.fill = r;
	f1.outline = b; 
	f2.fill = g;
	f2.outline = w;
	
	
	Rectangle rectA(10,5);
	Rectangle rectB(3,7,f1);
	Rectangle rectC = rectA;

	Rhombus rhoA(6,2,f2);
	Rhombus rhoB = rhoA;
	Rhombus rhoC(4,3);
		
	quadList[0]= &rectA;
	quadList[1]= &rectB;
	quadList[2]= &rectC;
	quadList[3]= &rhoA;
	quadList[4]= &rhoB;
	quadList[5]= &rhoC;

	Show();
	
	rectA.SetFill(g);
	rhoC.SetOutline(r);
	rhoA=rhoC;
	rectB.SetFormat(f2);
	
	Show();

	return 0;
*/
//MAIN PER TEST DISPLAY

	Display pippo;
	int scelta=1;
	int index=0;
	while (scelta !=-0)
	{
		cout << endl << endl;
		cout << "Scegli cosa vuoi fare:"<<endl;
		cout << "1- VISUALIZZARE TUTTE LE FORME"<<endl;
		cout << "2- AGGIUNGERE NUOVA FORMA"<<endl;
		cout << "3- RIMUOVERE FORMA"<<endl;
		cout << "4- RIMUOVERE TUTTE LE FORME"<<endl;
		cout << "0- ESCI DAL PROGRAMMA"<<endl;
		scanf("%d",&scelta);

		switch (scelta)
		{
		case 1:
			pippo.GetAll();
			break;
		case 2:
			pippo.AddShape();
			break;
		case 3:
			cout << "Quale forma vuoi rimuovere?"<< endl;
			scanf("%d", &index);
			if (index >= 0 && index<MAX_SHAPES)
				pippo.RemoveShape(index);
			else
				cout << "Indice non valido" << endl;
			break;
		case 4:
			pippo.RemoveAll();
			break;
		default:
			break;
		}
	}
	return 0;

}
