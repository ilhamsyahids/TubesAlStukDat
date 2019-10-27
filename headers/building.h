//==============================================//
//                                              //
//                   Building                   //
//                                              //
//----------------------------------------------//
// File : building.h */                         //
//----------------------------------------------//
// Definisi ADT Building                        //
// Building menjadi tempat semua aksi terjadi   //
// di dalam game                                //
//==============================================//

#ifndef _BUILDING_H
#define _BUILDING_H

///////////////////////////
//        INCLUDE        //
///////////////////////////
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "point.h"

////////////////////////////////////
//     Definisi elemen Building   //
////////////////////////////////////
typedef struct
{
    int kind;                   /* [1..4] Menandakan jenis bangunan */
                                /*  1 = Castle
                                    2 = Tower
                                    3 = Fort
                                    4 = Village */
    int player;                 /* [0..2] Menandakan player mana yang memiliki bangunan */
                                /* 0 = No Player
                                    1 = Player 1
                                    2 = Player 2 */
    int level;                  /* [0..4] Level dari bangunan */
    int soldierCount;           /* Jumlah pasukan yang ada di bangunan */
    int soldierAddValue;        /* A = Nilai penambahan pasukan */
    int maximumSoldierAddCount; /* M = Batas atas jumlah penambahan pasukan di bangunan */
    int soldierAddCount;        /* Menandakan berapa banyak pasukan yang telah ditambah */
    boolean hasDefense;         /* Boolean untuk menandakan apakah bangunan dilindungi */
    boolean hasAttacked;
    POINT position; /* Posisi bangunan dalam map */
} Building;

///////////////////////////
//        SELECTOR       //
///////////////////////////
int BuildingKind(Building B);
/** Mengembalikan kind building */

int BuildingPlayer(Building B);
/* Mengembalikan player building */

int BuildingLevel(Building B);
/* Mengembalikan Level building */

int BuildingSoldierCount(Building B);
/* Mengembalikan SoldierCount building */

int BuildingSoldierAddValue(Building B);
/* Mengembalikan SoldierAddValue building */

int BuildingMaximumSoldierAddCount(Building B);
/* Mengembalikan MaximumSoldierAddCount building */

int BuildingSoldierAddCount(Building B);
/* Mengembalikan Soldier Count building */

boolean BuildingHasDefense(Building B);
/* Mengembalikan apakah building memiliki defense */

boolean BuildingHasAttacked(Building B);
/* Mengembalikan apakah building sudah menyerang pada turn tersebut*/

POINT BuildingPosition(Building B);
/* Mengembalikan posisi building */

///////////////////////////
//       PROTOTYPE       //
///////////////////////////
int BuildingGetU(int kind);
/* Mengirimkan nilai U untuk kind tertentu */

int BuildingGetA(int kind, int level);
/* Mengirimkan nilai A untuk kind dan level tertentu */

int BuildingGetM(int kind, int level);
/* Mengirimkan nilai M untuk kind dan level tertentu */

boolean BuildingGetP(int kind, int level);
/* Mengirimkan nilai P untuk kind dan level tertentu */

char *BuildingGetName(int kind);
/* Mengirimkan nama building dengan kind tertentu */

///////////////////////////
//       CONSTRUCTOR     //
///////////////////////////
Building BuildingCreate(int kind, int player, POINT position);
/* Mengirimkan building yang sudah diset kind, player, dan positionnya */

Building BuildingCreateDummy();
/* Mengirimkan building dummy dengan kind 0 */

void BuildingInitialize(Building *B);
/* I.S. Atribut B yang telah diset hanya kind, player, dan position */
/* F.S. Atribut Elemen B lengkap dengan spesifikasi */
/* level = 0
   soldierCount = U
   soldierAddValue = A
   maximumSoldierCount = M
   isDefended = P
*/
/* Proses : Melakukan setup sesuai kind */

void BuildingResetStatus(Building *B);
/* I.S Building telah terisinisialisasi sembarang */
/* F.S HasAttacked building diset menjadi false */

void BuildingRefreshStatus(Building *B);
/* I.S Building telah terisinisialisasi sembarang */
/* F.S Atribut soldierAddValue soldierAddCount soldierMaximumAddValue hasAttacked hasDefense
        diset ulang sesuai level */


///////////////////////////
//        PREDIKAT       //
///////////////////////////
boolean IsBuildingEmpty(Building B);
/* Mengirimkan apakah pasukan di markas kosong */

boolean CanBuildingAddPasukan(Building B);
/* Mengirimkan apakah pasukan di bangunan masih dapat ditambah */
/* soldierAddCount < maximumSoldierAddCount */

boolean IsBuildingLevelMax(Building B);
/* Mengirimkan apakah level bangunan sudah maximum (4) */

boolean CanBuildingAttack(Building B);
/* Mengirimkan apakah building dapat menyerang */

boolean BuildingHasDefense(Building B);
/* Mengirimkan apakah building memiliki defense */

///////////////////////////
//       PRIMITIVES      //
///////////////////////////
void BuildingIncreasePasukan(Building *B, int value);
/* I.S. Jumlah pasukan bangunan ke-index BL sudah terdefinisi */
/* F.S. Jumlah pasukan bertambah sesuai parameter value */
/* Proses: Menambahkan value pada soldierCount dari Building */
/* Jika jumlah akhir melebihi jumlah pasukan yang dapat ditampung,
   soldierCount akan sama dengan M */

void BuildingDecreasePasukan(Building *B, int value);
/* I.S. Jumlah pasukan bangunan ke-index BL sudah terdefinisi */
/* F.S. Jumlah pasukan berkurang sesuai parameter value */
/* Proses: Mengurangkan value pada soldierCount dari Building */
/* Jika jumlah akhir kurang dari 0, soldierCount akan menjadi 0 */

void BuildingChangePlayer(Building *B);
/* I.S. Bangunan ke-index BL terdefinisi milik salah satu player */
/* F.S. Bangunan ke-index BL berubah kepemilikan menjadi player yang lain */
/* Proses: Mengganti nilai atribut player pada Building dan kembali inisialisasi Building. */

void BuildingLevelUp(Building *B);
/* I.S. Bangunan ke-index BL sudah terdefinisi*/
/* F.S. Atribut building akan menjadi sbb: */
/* Level bertambah 1 dan soldierCount berkurang sebesar M/2 */
/* Atau : Level tetap karena sudah maksimum atau soldierCount kurang (berikan prompt) */
/* Proses: Mengecek apakah levelup bisa dilakukan, jika bisa FS1 jika tidak FS2 */

//////////////////////////////////
//      BUILDING OPERATIONS     //
//////////////////////////////////
void BuildingPrintInfo(Building B);
/* Mencetak isi info Building B ke layar */
/* I.S. B terdefinisi */
/* F.S. B tercetak ke layar dengan format:
<Nama Bangunan> <(Posisi)> <Jumlah Pasukan> <Level>
*/

#endif
