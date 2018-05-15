
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
 *   This file generates all possible moves.
 *
 *   First, we generate all pseudo-legal moves
 *   and then we filter out the illegal ones.
 *
 */

#ifndef MOVEGEN_HPP
#define MOVEGEN_HPP

#include "bitboard.hpp"
#include "types.hpp"

#include <math.h>
#include <array>

using namespace std;

array<u64, 64> north_mask;
array<u64, 64> south_mask;
array<u64, 64> east_mask;
array<u64, 64> west_mask;

array<u64, 64> north_east_mask;
array<u64, 64> south_east_mask;
array<u64, 64> north_west_mask;
array<u64, 64> south_west_mask;

void init_north_mask()
{
    for(int rank=0; rank<8; ++rank)
    {
        for(int file=0; file<8; ++file)
        {
            u64 base = pow(2, 8*rank + file);
            base <<= 8;
            u64 mask=0;
            for(int i=rank; i<8; ++i)
            {
                mask += base;
                base <<= 8;
            }
            north_mask[8*rank+file] = mask;
        }
    }
}

void init_south_mask()
{
    for(int rank=0; rank<8; ++rank)
    {
        for(int file=0; file<8; ++file)
        {
            u64 base = pow(2, 8*rank + file);
            base >>= 8;
            u64 mask=0;
            for(int i=rank; i>0; --i)
            {
                mask += base;
                base >>= 8;
            }
            south_mask[8*rank+file] = mask;
        }
    }
}

void init_east_mask()
{
    for(int rank=0; rank<8; ++rank)
    {
        for(int file=0; file<8; ++file)
        {
            u64 base = pow(2, 8*rank + file);
            base <<= 1;
            u64 mask=0;
            for(int i=file+1; i<8; ++i)
            {
                mask += base;
                base <<= 1;
            }
            east_mask[8*rank+file] = mask;
        }
    }
}

void init_west_mask()
{
    for(int rank=0; rank<8; ++rank)
    {
        for(int file=0; file<8; ++file)
        {
            u64 base = pow(2, 8*rank + file);
            base >>= 1;
            u64 mask=0;
            for(int i=0; i<file; ++i)
            {
                mask += base;
                base >>= 1;
            }
            west_mask[8*rank+file] = mask;
        }
    }
}
    
void init_north_east_mask()
{
}

void init_south_east_mask()
{
}

void init_north_west_mask()
{
}

void init_south_west_mask()
{
}

void init_masks()
{
    init_north_mask();
    init_south_mask();
    init_east_mask();
    init_west_mask();
    
    init_north_east_mask();
    init_south_east_mask();
    init_north_west_mask();
    init_south_west_mask();
}

#endif // MOVEGEN_HPP

