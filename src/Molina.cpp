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

#include "bitboard.hpp"
#include "types.hpp"

#include <ctime>

using namespace std;

int main()
{
    clock_t begin=clock();

    init_bitboard();
    init_masks();

    double init_time = (clock()-begin)/(double)CLOCKS_PER_SEC;
    cout << "Initialization time: " << init_time << endl;

    //print_bitboard();

    return 0;
}
