//---------------------------------------------------------
/**
//    @file		rhombus.cpp
//    @brief	Implementation file for class rhombus
//    @author	Nicolò Busi S5209833
*/
//---------------------------------------------------------

constexpr auto DEFAULT_VALUE = 0;;
constexpr auto SQUARE = 2;;
constexpr auto HALF = 0.5;;

#include "rhombus.h"


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>



//////////////////////////////////////////////////////////////////////////////
// fpi
// memory debug, place after includes

#ifdef DBGMEM_CRT
#undef new
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif // DBGMEM_CRT


/************************** GLOBAL FUNCTIONS AND VARIABLES ******************/

///////////////////////////////////////////////////////////////////////////
// Print operator
ostream& operator << (ostream& o, rhombus& X)
{

	return o;
}

///////////////////////////////////////////////////////////////////////////
istream& operator >> (istream& i, rhombus& X)
{

	return i;
}

/************************** MEMBER FUNCTIONS AND VARIABLES ******************/

///////////////////////////////////////////////////////////////////////////
// Default Constructor

/// @brief default constructor 
rhombus::rhombus()
{
	cout << "Rhombus - Constructor - Default" << endl;
	Init();
	
}

///////////////////////////////////////////////////////////////////////////
// Constructor

/// @brief constructor which also check if the value entered is >= 0
/// @param dH diagH of the rhombus
/// @param dV diagV of the rhombus
rhombus:: rhombus(float dH, float dV) {

	diagH = DEFAULT_VALUE;
	diagV = DEFAULT_VALUE;

	cout << "Rhombus - Constructot" << endl;

	if (dH <= DEFAULT_VALUE) 
		ErrorMessage("WARNING: Rhombus - constructor : diagH should be > 0");
	else
		diagH = dH;
	
	if (dV <= DEFAULT_VALUE)
		ErrorMessage("WARNING: Rhombus - constructor : diagV should be > 0");
	else
		diagV = dV;
		
	}


///////////////////////////////////////////////////////////////////////////
// Copy Constructor

/// @brief copy constructor 
/// @param reference to the object that should be copied 
rhombus::rhombus(rhombus& X)
{
	cout << "Rhombus - Copy Constructor" << endl;
	Init(X);
}

///////////////////////////////////////////////////////////////////////////
// Destructor

/// @brief destructor 
rhombus::~rhombus()
{
	cout << "Rhombus - Destructor" << endl;
	Reset();
}

///////////////////////////////////////////////////////////////////////////
// Init default initializer

/// @brief init default initializer of the object
void rhombus::Init()
{
	diagH = DEFAULT_VALUE;
	diagV = DEFAULT_VALUE;
}

///////////////////////////////////////////////////////////////////////////
// Init copy initializer

/// @brief init copy initializer of the object
/// @param reference to the object that should be copied 
void rhombus::Init(rhombus& X)
{
	Reset();
	diagH = X.diagH;
	diagV = X.diagV;
}

///////////////////////////////////////////////////////////////////////////
// Object eraser

/// @brief object's eraser
void rhombus::Reset()
{
	diagH = DEFAULT_VALUE;
	diagV = DEFAULT_VALUE;
}

///////////////////////////////////////////////////////////////////////////
// Overloading of assignment operator

/// @brief overload of operator = 
/// @param reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator
rhombus& rhombus::operator =(rhombus& X)
{
	Reset();
	Init(X);
	return *this;
}

///////////////////////////////////////////////////////////////////////////
// Overloading of comparison operator

/// @brief overload of operator == 
/// @param reference to the object on the right side of the operator 
/// @return true if the two objects have the same diagH and the same diagV
bool rhombus::operator ==( rhombus& X)
{
	if (X.diagH == diagH && X.diagV == diagV)
		return true;

	return false;
}

///////////////////////////////////////////////////////////////////////////
// Error messaging routine

/// @brief warning routine
/// @param warning string printed on the screen

void rhombus::ErrorMessage(const char* string)
{
	printf("%s\n", string);
}

///////////////////////////////////////////////////////////////////////////
// Debug routine

/// @brief It shows the programm status
void rhombus::Dump()
{
	cout << "Diagonale Maggiore = " << diagH << endl;
	cout << "Diagonale Minore = " << diagV << endl;
	cout << "Lato = " << Side(diagH, diagV) << endl;
}

/************************** ACCESS FUNCTIONS ******************/

/// @brief set the side of the object
/// @param dH diagH
/// @param dV diagV
/// @return side
double rhombus::Side(float dH, float dV) {
	
	return sqrt(pow(dH/2, SQUARE) + pow(dV/2, SQUARE));

}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief set diagH and diagV of the object
/// @param dH diagH 
/// @param dV diagV
void rhombus::SetDim(float dH, float dV) {

	SetDiagH(dH);
	SetDiagV(dV);

}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief set diagH of the object
/// @param dV diagH
void rhombus::SetDiagH(float dH) {

	if (dH < DEFAULT_VALUE) {
		ErrorMessage("Rhombus - SetDiagH: diagH should be > 0");
		return;
	}

	diagH = dH;
	
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief set diagV of the object
/// @param dV diagV
void rhombus::SetDiagV(float dV) {

	if (dV < DEFAULT_VALUE) {
		ErrorMessage("Rhombus - SetDiagH: diagH should be > 0");
		return;
	}

	diagV = dV;
}
///////////////////////////////////////////////////////////////////////////
// 


/// @brief get diagH and diagVof the object
/// @param dH diagH
/// @param dV diagV
void rhombus::GetDim(float& dH, float& dV) {
	
	dH = diagH;
	dV = diagV;

	return;
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief get diagH of the object
/// @return diagH 
float rhombus::GetDiagH() {
	return diagH;
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief get diagV of the object
/// @return diagV 
float rhombus::GetDiagV() {
	return diagV;
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief get the side of the object
/// @return side 
double rhombus::GetSide() {
	return Side(diagH, diagV);
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief get the area of the object
/// @return area of the rhombus
float rhombus::GetArea() {
	return diagH * diagV * HALF;
}
///////////////////////////////////////////////////////////////////////////
// 

/// @brief get the perimeter of the object
/// @return perimeter of the rhombus
double rhombus::GetPerimeter() {
	return 4 * Side(diagH, diagV);
}
///////////////////////////////////////////////////////////////////////////
// 
