/**
 * @file CRhombus.cpp
 * @author Luca Grosso (grossolu@icloud.com)
 * @brief Abstract Derivate Class of rhombus. Implmentation of functions.
 * @date 2024-05-21
 * 
 * 
 */

#include<iostream> 
#include<cmath>
#include "CRhombus.h"

/// @brief default constructor 
Rhombus::Rhombus() 
{

	cout << "Rhombus - constructor - default" << endl;

	Init();

}

/// @brief constructor 
/// @param dL diagonal (longer)
/// @param dS diagonal (shorter)
Rhombus::Rhombus(float dL, float dS) 
{

	Init();

	cout << "Rhombus - constructor" << endl;

	if (dL <= 0. || dS <= 0.) {
		WarningMessage("constructor: diagonals should be > 0"); 
		SetDim(0,0);
	}
	else
		SetDim(dL,dS);

}

/// @brief constructor with format
/// @param dL diagonal (longer)
/// @param dS diagonal (shorter)
/// @param sf struct of type Format
Rhombus::Rhombus(float dL, float dS, Format sf):Quadrilateral(sf) 
{

	Init();

	cout << "Rhombus - constructor with format" << endl;

	if (dL <= 0. || dS <= 0.) {
		WarningMessage("constructor with format: diagonals should be > 0"); 
		SetDim(0,0);
	}
	else
		SetDim(dL,dS);

}

/// @brief destructor 
Rhombus::~Rhombus() 
{

	cout << "Rhombus - destructor" << endl;
	Reset();

}

/// @brief copy constructor 
/// @param r reference to the object that should be copied 
Rhombus::Rhombus(const Rhombus &r):Quadrilateral(*r.shapef) 
{ 

	cout << "Rhombus - copy constructor" << endl;

	Init(r);
	
}

/// @brief overload of operator = 
/// @param r reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Rhombus& Rhombus::operator=(const Rhombus &r) 
{ 

	cout << "Rhombus - operator =" << endl;

	Init(r);
	
	return *this;
	
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same width and the same length and the same format
bool Rhombus::operator==(const Rhombus &r)
{ 

	if (r.diagL == diagL && r.diagS == diagS && r.shapef->fill == shapef->fill && r.shapef->outline == shapef->outline)
		return true;
		
	return false;

}

/// @brief default initialization of the object
void Rhombus::Init() 
{
	
	SetDim(0,0);
	
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Rhombus::Init(const Rhombus &r) 
{
	
	Init();
	SetDim(r.diagL,r.diagS);
	*shapef=*r.shapef;
	
}

/// @brief total reset of the object  
void Rhombus::Reset() 
{
	
	SetDim(0,0);
	
}


/// @brief set longer diagonal of the object
/// @param d diagonal 
void Rhombus::SetDiagL(float d) 
{

	if (d < 0.) {
		WarningMessage("SetDiagL: diagonal should be > 0");
		return;
	}

	SetDim(d,diagS);

} 

/// @brief set shorter diagonal of the object
/// @param d diagonal 
void Rhombus::SetDiagS(float d) 
{

	if (d < 0.) {
		WarningMessage("SetDiagS: diagonal should be > 0");
		return;
	}

	SetDim(diagL,d);

}


/// @brief get longer diagonal of the object
/// @return longer diagonal 
float Rhombus::GetDiagL() 
{

	return diagL;

}

/// @brief get shorter diagonal of the object
/// @return shorter diagonal 
float Rhombus::GetDiagS() 
{

	return diagS;

}

/// @brief get side of the object
/// @return side 
float Rhombus::GetSide() 
{

	return sqrt(diagL*diagL/(float)4 + diagS*diagS/(float)4);

}



/// @brief set the diagonals of the object
/// @param dL longer diagonal  
/// @param dS shorter diagonal
void Rhombus::SetDim(float dL, float dS) 
{

	float side = 0;
	
	diagL = dL;
	diagS = dS;  
	
	side = GetSide();
	Quadrilateral::SetSides(side,side,side,side);
	
	return;
}

/// @brief get the diagonals of the object
/// @param dL larger diagonal 
/// @param dS shorter diagonal
void Rhombus::GetDim(float &dL, float &dS) 
{

	dL = diagL;
	dS = diagS; 
	
	return;
}

/// @brief computes the area of the object
/// @return the area 
float Rhombus::Area() 
{
	
	return (diagL*diagS/(float)2);

}


/// @brief write an error message 
/// @param string message to be printed
void Rhombus::ErrorMessage(const char *string) 
{
	
	cout << endl << "ERROR -- Rhombus --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Rhombus::WarningMessage(const char *string) 
{
	
	cout << endl << "WARNING -- Rhombus --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void Rhombus::Dump() 
{

	cout << endl;
	cout << "---Rhombus---" << endl; 
	cout << endl;
	
	cout << "Longer diagonal = " << diagL << endl;
	cout << "Shorter diagonal = " << diagS << endl; 
	cout << "Side = " << GetSide() << endl;
	
	Quadrilateral::Dump();
	
	cout << endl;

}


/// @brief to draw a rhombus
void Rhombus::Drawing() 
{
	
	cout << "Sto disegnando un rombo di diagonale minore " << diagS << " e diagonale maggiore " << diagL;
	cout << " con colore di riempimento " << shapef->fill << " e colore dei bordi " << shapef->outline << endl;

}
