#pragma once


/** Крaткое описание класса
 *
 *
 * File  : ClassName.h
 * Author:
 *
 * Длинное описание класса
 *
 */

 // SYSTEM INCLUDES
 //
#include <vector>

 // PROJECT INCLUDES
 //

 // LOCAL INCLUDES
 //
#include "include/CRunway.h"

class CModel
{
public:
	std::vector<CRunway*> Runways;


public:
	CModel();

	CModel(int runwayCount, int specialPlaceCount);


public:
	CRunway* GetRunways() const;
};

