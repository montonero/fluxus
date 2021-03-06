// Copyright (C) 2005 Dave Griffiths
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

#include "Allocator.h"
#include <set>

using namespace std;

set<void *> mem;

int count = 0;

void alloc_hook(void *ptr, size_t n)
{
    ::count++;
    mem.insert(ptr);

    if (::count>1000)
    {
        std::cerr<<mem.size()<<endl;
        ::count=0;
    }
}

void dealloc_hook(void *ptr, size_t n)
{
    mem.erase(ptr);
    //std::cerr<<"--"<<mem.size()<<endl;
}
