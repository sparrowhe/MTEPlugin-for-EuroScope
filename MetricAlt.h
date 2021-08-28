// MetricAlt.h

#pragma once

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include <map>
#include <string>

using namespace std;

namespace MetricAlt {
	const map<int, int> m_mtof = { // meter to feet map
	{  300, 1000},
	{  600, 2000},
	{  900, 3000},
	{ 1200, 3900},
	{ 1500, 4900},
	{ 1800, 5900},
	{ 2100, 6900},
	{ 2400, 7900},
	{ 2700, 8900},
	{ 3000, 9800},
	{ 3300,10800},
	{ 3600,11800},
	{ 3900,12800},
	{ 4200,13800},
	{ 4500,14800},
	{ 4800,15700},
	{ 5100,16700},
	{ 5400,17700},
	{ 5700,18700},
	{ 6000,19700},
	{ 6300,20700},
	{ 6600,21700},
	{ 6900,22600},
	{ 7200,23600},
	{ 7500,24600},
	{ 7800,25600},
	{ 8100,26600},
	{ 8400,27600},
	{ 8900,29100},
	{ 9200,30100},
	{ 9500,31100},
	{ 9800,32100},
	{10100,33100},
	{10400,34100},
	{10700,35100},
	{11000,36100},
	{11300,37100},
	{11600,38100},
	{11900,39100},
	{12200,40100},
	{12500,41100},
	{13100,43000},
	{13700,44900},
	{14300,46900},
	{14900,48900},
	{15500,50900},
	};
	const map<int, int> m_ftom = {  // feet to meter map
	{ 1000,  300},
	{ 2000,  600},
	{ 3000,  900},
	{ 3900, 1200},
	{ 4900, 1500},
	{ 5900, 1800},
	{ 6900, 2100},
	{ 7900, 2400},
	{ 8900, 2700},
	{ 9800, 3000},
	{10800, 3300},
	{11800, 3600},
	{12800, 3900},
	{13800, 4200},
	{14800, 4500},
	{15700, 4800},
	{16700, 5100},
	{17700, 5400},
	{18700, 5700},
	{19700, 6000},
	{20700, 6300},
	{21700, 6600},
	{22600, 6900},
	{23600, 7200},
	{24600, 7500},
	{25600, 7800},
	{26600, 8100},
	{27600, 8400},
	{29100, 8900},
	{30100, 9200},
	{31100, 9500},
	{32100, 9800},
	{33100,10100},
	{34100,10400},
	{35100,10700},
	{36100,11000},
	{37100,11300},
	{38100,11600},
	{39100,11900},
	{40100,12200},
	{41100,12500},
	{43000,13100},
	{44900,13700},
	{46900,14300},
	{48900,14900},
	{50900,15500},
	};
	int MtoFeet(const int meter);
	int FeettoM(const int feet);
	int LvlMtoFeet(const int meter);
	int LvlFeettoM(const int feet);
	bool RflFeettoM(const int feet, int& meter);
	string LvlFeetEvenOdd(const int feet); // for RouteChecker
}