/*
 * zonecollection.h
 *
 * Class definition for the Sudoku ZoneCollection class
 *
 * (c) Richard Oak 2016
 */

/* ************************************************************************* */

#pragma once

#include <memory>   // std::unique_ptr
#include <vector>   // std::vector

#include "zone/izone.h"  // IZone

namespace Sudoku
{ 

/* ************************************************************************* */

using ZoneCollection = std::vector<std::unique_ptr<IZone>>;

/* ************************************************************************* */

}