/* *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013 Paul Holden et al. (See AUTHORS)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * */

#ifndef BAKGE_GRAPHICS_SHAPES_CONE_H
#define BAKGE_GRAPHICS_SHAPES_CONE_H

#include <bakge/Bakge.h>

namespace bakge
{

class Cone : public Shape
{
    math::Scalar BaseRadius;
    math::Scalar TopRadius;
    int Slices;
    int Stacks;


public:

    Cone();
    ~Cone();

    BGE_INL void SetRadii(math::Scalar Base, math::Scalar Top)
    {
        BaseRadius = Base;
        TopRadius = Top;
    }

    BGE_INL void SetSlicesAndStacks(int NumSlices, int NumStacks)
    {
        Slices = NumSlices;
        Stacks = NumStacks;
    }

    Result Draw() const;

}; /* Cone */

} /* bakge */

#endif /* BAKGE_GRAPHICS_SHAPES_CONE_H */