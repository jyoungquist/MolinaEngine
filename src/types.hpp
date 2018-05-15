
/*
 * This file is part of Molina.
 * 
 * Molina is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version
 * 3 of the License, or (at your option) any later version.
 *
 * Molina is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/*
 *   This file defines commonly used data types
 */

#ifndef TYPES_HPP
#define TYPES_HPP

#include <array>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

// White pieces
int wPawn   = 0;
int wRook   = 1;
int wKnight = 2;
int wBishop = 3;
int wQueen  = 4;
int wKing   = 5;

// Black pieces
int bPawn   = 6;
int bRook   = 7;
int bKnight = 8;
int bBishop = 9;
int bQueen  = 10;
int bKing   = 11;

int none    = 12;

//enum piece {pawn, rook, knight, bishop, queen, king};

//enum piece {wPawn, wRook, wKnight, wBishop, wQueen, wKing,
//            bPawn, bRook, bKnight, bBishop, bQueen, bKing};

enum rank {rank_1 = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'11111111,
           rank_2 = 0b00000000'00000000'00000000'00000000'00000000'00000000'11111111'00000000,
           rank_3 = 0b00000000'00000000'00000000'00000000'00000000'11111111'00000000'00000000,
           rank_4 = 0b00000000'00000000'00000000'00000000'11111111'00000000'00000000'00000000,
           rank_5 = 0b00000000'00000000'00000000'11111111'00000000'00000000'00000000'00000000,
           rank_6 = 0b00000000'00000000'11111111'00000000'00000000'00000000'00000000'00000000,
           rank_7 = 0b00000000'11111111'00000000'00000000'00000000'00000000'00000000'00000000,
           rank_8 = 0b11111111'00000000'00000000'00000000'00000000'00000000'00000000'00000000};

// TODO: Do these need to be reversed?
enum file {file_a = 0b10000000'10000000'10000000'10000000'10000000'10000000'10000000'10000000,
           file_b = 0b01000000'01000000'01000000'01000000'01000000'01000000'01000000'01000000,
           file_c = 0b00100000'00100000'00100000'00100000'00100000'00100000'00100000'00100000,
           file_d = 0b00010000'00010000'00010000'00010000'00010000'00010000'00010000'00010000,
           file_e = 0b00001000'00001000'00001000'00001000'00001000'00001000'00001000'00001000,
           file_f = 0b00000100'00000100'00000100'00000100'00000100'00000100'00000100'00000100,
           file_g = 0b00000010'00000010'00000010'00000010'00000010'00000010'00000010'00000010,
           file_h = 0b00000001'00000001'00000001'00000001'00000001'00000001'00000001'00000001};

typedef unsigned long long int u64;
typedef array<int, 2> square; // convention: {rank, file}


/********************************
 ****  Some helper functions ****
 ********************************/
void print_u64(u64 board)
{
    string s = bitset<64>(board).to_string();
    reverse(s.begin(), s.end());
    
    for(int rank=7; rank>=0; --rank)
    {
        cout << rank+1 << "| ";
        for(int file=0; file<8; ++file)
        {
            cout << s[8*rank + file] << " ";
        }
        cout << endl;
    }
    cout << "  ----------------\n";
    cout << "   A B C D E F G H\n\n";
}

#endif // TYPES_HPP

