# MTEPforES

Miscellaneous Tag Enhancement Plugin for EuroScope (MTEPlugin)

## Tag Item Types and Behaviours

1. **GS(KPH) with trend indicator** - ground speed in kph, with accel(A) and decel(L) indicator.
2. **RMK/STS indicator** - shows a **\*** if RMK/ or STS/ is found in flight plan remarks.
3. **Vertical speed (4-digit FPM)** - vertical speed in xxxx, will not display if vs<=100 fpm.
4. **Climb/Descend/Level indicator** - combination of climb, descent, level flight indicator.
5. **Actual altitude (m)** - uses QNH altitude below transition level and STD altitude above.
6. **Cleared flight level (m/FL)** - shows Chinese metric RVSM levels if matches, or FLxxx, otherwise calculated meters.
    + The color will be set by *Symbology Settings->Datablock->Redundant* if a new flight level is cleared but not confirmed.
7. **Final flight level (ICAO)** - shows Chinese metric RVSM levels if matches (Sxxx), otherwise flight Level (Fxxx).
8. **Similar callsign indicator** - shows **SC** if similar callsigns in tracked flights are detected.
    + Considers Chinese/English crews and ignores those text-only. Enter *\*EN* in scratch pad to distinguish Chinese airlines speaking English.
    + The color is set by *Symbology Settings->Datablock->Information*.
9. **RFL unit indicator** - shows **#** if final altitude of tracked aircraft does not match Chinese metric RVSM levels.
10. **RVSM indicator** - shows **V** for VFR flights, **A SPACE** if aircraft has RVSM capability, **X** if not.
11. **COMM ESTB indicator** - shows a **C** when tracking. Use **Set COMM ESTB** function to cancel this **C**.
    + The color is set by *Symbology Settings->Datablock->Redundant*.
12. **RECAT-CN** - Re-categorization (Chinese) for H(eavy) aircrafts. Only includes **-B -C**.
13. **Route validity** - route checker item, see detail below.
14. **Tracked DUPE warning** - squawk DUPE warning only for aircrafts tracked by myself.
    + The color is set by *Symbology Settings->Datablock->Information*.
15. **Departure sequence** - departure sequence item, see detail below.
16. **Radar vector indicator** - shows **RV** for tracked aircraft with heading assigned.
    + The color is set by *Symbology Settings->Datablock->Information*.
17. **Cleared flight level (m)** - shows Chinese metric RVSM levels if matches, otherwise calculated meters.
    + Similar to item 6, but won't show ILS/VA or Fxxx. More useful in a Sweatbox simulator session.
18. **Reconnected indicator** - shows **r** if reconnected.
    + The color is set by *Symbology Settings->Datablock->Information*.

## Tag Item Functions

1. **Set COMM ESTB** - establish communication and extinguishes **COMM ESTB indicator**.
2. **Open CFL popup menu** - Chinese metric RVSM altitudes. Includes ILS/VA/NONE options.
3. **Open CFL popup edit** - Chinese metric RVSM altitudes.
4. **Open RFL popup menu** - Chinese metric RVSM altitudes.
   + CFL popup edit supports (standalone or in-menu): ***xxx*** for metric RVSM levels, ***Fxxx*** for FLxxx, ***550.*** for 550m, ***F4500.*** for 4500ft, etc. Enter ***0*** to clear CFL.
   + RFL popup edit (in-menu) supports: ***xxx*** for metric, ***Fxxx*** for FLxxx. Enter ***0*** to reset RFL to the final altitude in flight plan.
   + Enter a ***F*** or ***M*** (case-insensitive) will force all altitude displays for this aircraft in imperial or metric unit, only for tracekd aircrafts.
5. **Open similar callsign list** - shows a list of all callsigns that are similar to the current one.
   + Selecting one will toggle native ***.find*** command, available only with the newest Euroscope version (v3.2a r33).
6. **Show route checker info** - route checker function, see detail below.
7. **Set departure sequence** - departure sequence function, see detail below.
8. **Open assigned speed popup list** - open IAS or MACH assign list based on current altitude. IAS for 7500m/FL246 and below, MACH for above.
9. **Restore assigned data** - restore previously assigned data for reconnected flights and start tracking.
   + Only available if previously tracked by myself. Assigned data includes: *communication type, heading/DCT point, cleared altitude, final altitude, speed/Mach, rate, squawk, scratch pad*.

## Custom Cursor Settings

You may turn the default mouse arrow into a cross to simulate real-world radar screens. This only works with the original DLL file name (MTEPlugin.dll) and the newest Euroscope version (v3.2a r33).

Enter **.MTEP CURSOR ON** (case-insensitive) in your command line at the bottom of the screen to activate the cursor feature.

Enter **.MTEP CURSOR OFF** to de-activate.

This setting will be saved in your EuroScope plugin settings.

## Route Checker

This module will automatically check route validity. Requires a CSV file in the format below:

Dep|Arr|Name|EvenOdd|AltList|MinAlt|Route|Remarks
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|ZBAA/ZBAD|ZSSS/ZSPD|test|SE/SO/FE/FO|S81/S89/S107/F350/F450|9800|ELKUR .... SASAN|test only

+ ***Dep, Arr*** can be a list seperated by "/".
+ ***Name*** no need to explain.
+ ***EvenOdd*** should be a combination of SE(metric, even) SO(metric, odd) FE(imperial, even) FO(imperial, odd). No seperation mark is required.
+ ***AltList*** means level restriction, which can also be a list seperated by "/".
  + Only exact altitudes will be valid. When ***AltList*** is not empty, ***EvenOdd*** will be deprecated.
  + For metric altitudes, use Sxxx, e.g. S81 for 8100m, S107 for 10700m.
  + For imperial flight levels, use Fxxx, e.g. F350 for FL350.
+ ***MinAlt*** should be in feet. If the flight plan final altitude is lower than given value, it should be an invalid flight plan.
+ ***Route*** is not necessarily the full route but can be partial. One DEP and ARR pair can have multiple routes with different restrictions.
+ ***Remarks*** no need to explain.

CSV files with incorrect column names or not in the given order, will not be loaded. Empty cells are accepted. However it's still possible to cause unpredicted issues if any cells doesn't follow the rules above.

You need to use a command line to load the CSV file: **.MTEP RC PATH** (case-insensitive). **PATH** should be replace by the CSV file path and file name.

+ If you use relative path, please note it's based on working directory.
+ Or you can insert **@** to the front of the path to make it relative to the DLL file. This only works with the original DLL file name (MTEPlugin.dll).
+ The file setting will be saved in your EuroScope plugin settings.

Tag item type **Route validity** shows:

+ **Y** - both route and final altitude is valid.
+ **L** - route is valid but final altitude is not.
+ **X** - route is not valid.
+ **?** - no route is found for this DEP-ARR.
+ shows nothing when clearance received flag is set or route checker is not configured.
+ The color of **L X** is set by *Symbology Settings->Datablock->Redundant*.

Tag item function **Show route checker info**: Displays a *MTEP-Route* message in chat list and shows route information for current DEP-ARR if seleted flight plan is invalid.

Command line function: **.MTEP RC DDDD AAAA** will display the valid routes from DDDD to AAAA and copy to clipboard.

## Departure Sequence

This module is a simplified version of my [Departure-List-Sequencing-PlugIn](https://github.com/KingfuChan/Departure-List-Sequencing-PlugIn-for-EuroScope) with different display method, no synchronization, but consistent with default EuroScope groud state.

Tag item type **Departure sequence** shows:

+ **two digits number 01~99** - the sequence of the flight.
+ **--** - indicating a reconnected flight. The color is set by *Symbology Settings->Datablock->Information*.

Tag item function **Set departure sequence** is used to:

+ initiate a sequence - if no previous sequence at all.
+ edit a sequence - if the flight has a active sequence.
+ re-activate a sequence - if the flight has just reconnected.
+ delete a sequence - entering 0 in the popup edit.

There are 3 ways to remove a flight from the queue:

+ entering 0 in popup edit.
+ set any of the ground states (NSTS, STUP, PUSH, TAXI, DEPA).
+ setting clearance flag for flights without a ground state (NSTS).

There are 2 ways to re-activate reconnected flights and restoring previous sequence:

+ resetting previous ground state.
+ use **Set departure sequence** for NSTS flights.

Command line function: **.MTEP DS RESET** will completely reset the module.

## Other Command Line Features

1. **.MTEP FR24 ICAO / .MTEP VARI ICAO** - opens [Flightradar24](https://www.flightradar24.com/) / [飞常准ADS-B](https://flightadsb.variflight.com/) in web browser and centers the map on the given **ICAO** airport. Only works with airports within sector file.
2. **.MTEP TR RESET** - resets tracked recorder. Use this command if **Similar callsign indicator/COMM ESTB indicator/Tracked DUPE warning** is not working properly. Note that it also deletes all saved data for reconnected flights.
3. **.MTEP TR 1/2/3** - set auto retrack mode: (1) no auto retrack; (2) auto retrack, no notifications; (3) auto retrack, notified through *MTEP-Recorder* message. This setting will be saved in your EuroScope plugin settings.
