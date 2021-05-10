/**
 * @file        uList.h
 * @author      Mohammad Sadequr Rahman <sadequr.rahman.rabby@gmail.com>
 * @date        7 May 2021
 * @brief       A Simple and easy to use c list library.
 *
 * 
 * @remarks     This program is distributed in the hope that it will be useful,
 *              but WITHOUT ANY WARRANTY; without even the implied warranty of
 *              MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *              GNU Lesser General Public License for more details.
 *
 *              You should have received a copy of the GNU Lesser General Public License
 *              along with this program; if not, write to the Free Software
 *              Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * @copyright   Copyright (C) 2021 Mohammad Sadequr Rahman. All rights reserved.
 */


#include <stdlib.h>
#include <stdint.h>
#include <string.h>


struct node
{
   struct node * nextNode;
   struct node * previousNode;
   void * value;
   uint16_t len;
   uint16_t index;
};