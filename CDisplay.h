/**
 * @file CDisplay.h
 * @author Luca Grosso (grossolu@icloud.com)
 * @brief Declaration of Display class and basic functions
 * @date 2024-05-23
 * 
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream> 
#include "CRhombus.h"
#include "CRectangle.h"
#include "CQuadrilateral.h"
#define MAX_SHAPES 50

using namespace std;

/// @class Display
/// @brief display that shows shapes by printing their infos
class Display {
private:
    /// @brief array that contains shapes
    Quadrilateral* Shapes_Array[MAX_SHAPES];

    /// @name PRIVATE FUNCTIONS TO MANAGE THE ARRAY 
	/// @{
    int Shape_Request();
    void Add_Rectangle(int index);
    void Add_Rhombus(int index);
	/// @}

public:
    /// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Display();
	Display(const Display &o);
	virtual ~Display();
	/// @}
	
	/// @name OPERATORS
	/// @{
	Display& operator=(const Display &o); 
	bool operator==(const Display &o);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const Display &o);										
	/// @}

    /// @name BASIC FUNCTIONS
    /// @{
    void GetAll();
    void AddShape();
    void RemoveShape(int index);
    void RemoveAll();
    /// @}

    /// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}


};

#endif
