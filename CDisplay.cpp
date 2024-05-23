/**
 * @file CDisplay.cpp
 * @author Luca Grosso (grossolu@icloud.com)
 * @brief 
 * @date 2024-05-23
 * 
 * 
 */
#include "CDisplay.h"

/// @brief Basic Constructor
Display::Display()
{
    cout<<"Costruttore di default Display"<<endl;

    Init();
}

/// @brief Costrunctor by copy
/// @param o object to be copied
Display::Display(const Display &o)
{
    cout<<"Costruttore di copia Display"<<endl;

    Init(o);
}

/// @brief destructor deallocate every object
Display::~Display()
{
    cout<<"Distruttore di Display"<<endl;

    RemoveAll();
}

/// @brief overload of operator =
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Display& Display::operator=(const Display &o)
{
    Init(o);

    return *this;
}

/// @brief overload of operator == 
/// @param o reference to the object on the right side of the operator 
/// @return always false 
bool Display::operator==(const Display &o)
{
    return false;
}

/// @brief default initialization of the object. Format is all black by default
void Display::Init()	
{
    for (int i=0; i<MAX_SHAPES; i++)
        Shapes_Array[i]=NULL;
}			

/// @brief initialization of the object as a copy of an object
/// @param o reference to the object that should be copied 
void Display::Init(const Display &o)	
{
    for (int i=0; i<MAX_SHAPES; i++)
        Shapes_Array[i]=o.Shapes_Array[i];
}		

/// @brief print of all the object in the array
void Display::GetAll()
{
    for (int i=0; i<MAX_SHAPES; i++)
    {
        cout << i << " - ";
        if (Shapes_Array[i]==NULL)
        {
            cout << "Empty shape" << endl;
            continue;
        }
        Shapes_Array[i]->Drawing();
    }
}

/// @brief function to ask the user which shape does he wants
/// @return Choice of the shape
int Display::Shape_Request()
{
    int scelta=0;
    cout << "Quale forma vuoi inserire?" << endl;
    cout << "1 - Rettangolo" << endl << "2 - Rombo" << endl;
    scanf("%d",&scelta);
    return(scelta);
}

/// @brief Add a shape in the array, if no place is available tells the user by a warning
void Display::AddShape()
{
    for (int i=0; i<MAX_SHAPES; i++)
    {
        if (Shapes_Array[i]==NULL)
        {
            int scelta=Shape_Request();
            switch (scelta)
            {
            case 1:     //RETTANGOLO
                Add_Rectangle(i);
                break;
            case 2:     //ROMBO
                Add_Rhombus(i);
                break;
            default:    //ERROR
                WarningMessage("Scelta non valida");
                break;
            }
            return;
        }
    }
    WarningMessage("Display Pieno");
}

/// @brief create a new rectangle object
void Display::Add_Rectangle(int index)
{
    Rectangle* NewRect;
    NewRect=new(Rectangle);
    Shapes_Array[index]=NewRect;
    float base=0,altezza=0; 
    int fill=0, outline=0;

    cout<< "Inserire base rettangolo: "<<endl;
    scanf("%f",&base);
    NewRect->SetWidth(base);

    cout<< "Inserire altezza rettangolo: "<<endl;
    scanf("%f",&altezza);
    NewRect->SetHeight(altezza);

    cout << "Colori: 0-NERO     1-BIANCO    2-ROSSO     3-VERDE     4-BLU" << endl;
    cout<< "Inserire sfondo rettangolo: "<<endl;
    scanf("%d",&fill);
    NewRect->SetFill((Color)fill);

    cout<< "Inserire bordo rettangolo: "<<endl;
    scanf("%d",&outline);
    NewRect->SetOutline((Color)outline);
}

/// @brief create a new rhombus object
void Display::Add_Rhombus(int index)
{
    Rhombus* NewRomb;
    NewRomb=new(Rhombus);
    Shapes_Array[index]=NewRomb;
    float diagL=0,diagS=0; 
    int fill=0, outline=0;

    cout<< "Inserire diagonale maggiore rombo: "<<endl;
    scanf("%f",&diagL);
    NewRomb->SetDiagL(diagL);

    cout<< "Inserire diagonale minore rombo: "<<endl;
    scanf("%f",&diagS);
    NewRomb->SetDiagS(diagS);

    cout << "Colori: 0-NERO     1-BIANCO    2-ROSSO     3-VERDE     4-BLU" << endl;
    cout<< "Inserire sfondo rombo: "<<endl;
    scanf("%d",&fill);
    NewRomb->SetFill((Color)fill);

    cout<< "Inserire bordo rombo: "<<endl;
    scanf("%d",&outline);
    NewRomb->SetOutline((Color)outline);
}

/// @brief remove the shape at the position inicated by index
/// @param index index of the array
void Display::RemoveShape(int index)
{
    if (Shapes_Array[index]==NULL)
    {
        WarningMessage("FORMA NON ESISTENTE");
        return;
    }
    delete(Shapes_Array[index]);
    Shapes_Array[index]=NULL;
}

/// @brief remove all shapes from the display
void Display::RemoveAll()
{
    for (int i=0; i<MAX_SHAPES; i++)
    {
        if (Shapes_Array[i]==NULL)
            continue;
        delete(Shapes_Array[i]);
        Shapes_Array[i]=NULL;
    }
}

/// @brief write an error message 
/// @param string message to be printed
void Display::ErrorMessage(const char *string) 
{
	cout << endl << "ERROR -- Display --";
	cout << string << endl;
}

/// @brief write a warning message 
/// @param string message to be printed
void Display::WarningMessage(const char *string)
{
	cout << endl << "WARNING -- Display --";
	cout << string << endl;
}

/// @brief for debugging: all about the object
void Display::Dump()
{
    cout<< "----------DISPLAY----------"<< endl;
    cout<< "Contenuto";
    GetAll();
}
