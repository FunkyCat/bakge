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

#include <bakge/Bakge.h>

namespace bakge
{
namespace math
{

const Vector3 Vector3::UpVector(0, 1, 0);

Vector3::Vector3()
{
}


Vector3::Vector3(Scalar X, Scalar Y, Scalar Z)
{
    Val[0] = X;
    Val[1] = Y;
    Val[2] = Z;
}


Vector3::Vector3(Vector3 BGE_NCP Other)
{
    Val[0] = Other.Val[0];
    Val[1] = Other.Val[1];
    Val[2] = Other.Val[2];
}


Vector3::~Vector3()
{
}

Scalar& Vector3::operator[](int BGE_NCP At)
{
    return Val[At];
}


Scalar BGE_NCP Vector3::operator[](int BGE_NCP At) const
{
    return Val[At];
}


Vector3 BGE_NCP Vector3::operator+=(Vector3 BGE_NCP Other)
{
    Val[0] += Other[0];
    Val[1] += Other[1];
    Val[2] += Other[2];

    return *this;
}


Vector3 Vector3::operator+(Vector3 BGE_NCP Other)
{
    return Vector3(Val[0] + Other[0], Val[1] + Other[1], Val[2] + Other[2]);
}


Vector3 BGE_NCP Vector3::operator-=(Vector3 BGE_NCP Other)
{
    Val[0] -= Other[0];
    Val[1] -= Other[1];
    Val[2] -= Other[2];

    return *this;
}


Vector3 Vector3::operator-(Vector3 Other)
{
    return Vector3(Val[0] - Other[0], Val[1] - Other[1], Val[2] - Other[2]);
}


Vector3 BGE_NCP Vector3::operator*=(Scalar BGE_NCP Other)
{
    Val[0] *= Value;
    Val[1] *= Value;
    Val[2] *= Value;

    return *this;
}


Vector3 BGE_NCP Vector3::operator/=(Scalar BGE_NCP Value)
{
    if(ScalarCompare(Value, 0)) {
        printf("Division by 0. Cancelling operation\n");
        return *this;
    }

    Val[0] /= Value;
    Val[1] /= Value;
    Val[2] /= Value;

    return *this;
}


Vector3 Vector3::operator/(Scalar Value)
{
    if(ScalarCompare(Value, 0)) {
        printf("Division by 0. Cancelling operation\n");
        return *this;
    }

    return Vector3(Val[0] / Value, Val[1] / Value, Val[2] / Value);
}


bool BGE_NCP Vector3::operator==(Vector3 BGE_NCP Other)
{
    return ScalarCompare(Val[0], Other.Val[0])
        && ScalarCompare(Val[1], Other.Val[1])
        && ScalarCompare(Val[2], Other.Val[2]);
}


Vector3 BGE_NCP Normalize()
{
    return *this /= Length();;
}


Vector3 Vector3::Normalized() const
{
    Scalar Len = Length();
    return Vector3(Val[0] / Len, Val[1] / Len, Val[2] / Len);
}


Scalar Vector3::LengthSquared() const
{
    return Scalar(Val[0] * Val[0] + Val[1] * Val[1] + Val[2] * Val[2]);
}


Scalar Vector3::Length() const
{
    return sqrt(LengthSquared());
}


Scalar Dot(Vector3 BGE_NCP Left, Vector3 BGE_NCP Right)
{
    return Left[0] * Right[0] + Left[1] * Right[1] + Left[2] * Right[2];
}


Vector3 Cross(Vector3 BGE_NCP Left, Vector3 BGE_NCP Right)
{
    return Vector3(
        Left[1] * Right[2] - Left[2] * Right[1],
        Left[2] * Right[0] - Left[0] * Right[2],
        Left[0] * Right[1] - Left[1] * Right[0]
    );
}


Vector3 UnitVector(Scalar X, Scalar Y, Scalar Z)
{
    Scalar Len = sqrt(X * X + Y * Y + Z * Z);
    return Vector3(X / Len, Y / Len, Z / Len);
}


Vector3 Hermite(Vector3 BGE_NCP Left, Vector3 BGE_NCP tanLeft,
                                        Vector3 BGE_NCP Right,
                                        Vector3 BGE_NCP tanRight,
                                        Scalar amount)
{
	Scalar sqr = amount * amount;
	Scalar cube = sqr * amount;
	Scalar func1 = 2*cube - 3* sqr + 1;
	Scalar func2 = -2*cube + 3*sqr;
	Scalar func3 = cube - 2*sqr + amount;
	Scalar func4 = cube - sqr;

	return Vector3(
        Left[0] * func1 + Right[0] * func2 + tanLeft[0] * func3
                                            + tanRight[0] * func4,
		Left[1] * func1 + Right[1] * func2 + tanLeft[1] * func3
                                            + tanRight[1] * func4,
		Left[2] * func1 + Right[2] * func2 + tanLeft[2] * func3
                                            + tanRight[2] * func4
    );
}


Vector3 operator+(Vector3 BGE_NCP Left, Vector3 BGE_NCP Right)
{
    return Vector3(Left[0] + Right[0], Left[1] + Right[1], Left[2] + Right[2]);
}


Vector3 operator-(Vector3 BGE_NCP Left, Vector3 BGE_NCP Right)
{
    return Vector3(Left[0] - Right[0], Left[1] - Right[1], Left[2] - Right[2]);
}


Vector3 operator-(Vector3 BGE_NCP Other)
{
    return Vector3(Val[0] - Other[0], Val[1] - Other[1], Val[2] - Other[2]);
}


Vector3 operator*(Scalar BGE_NCP Value)
{
    return Vector3(Val[0] * Value, Left[1] * Value, Left[2] * Value);
}


Vector3 operator/(Vector3 BGE_NCP Left, Scalar BGE_NCP Right)
{
    return Vector3(Left[0] / Right[0], Left[1] / Right[1], Left[2] / Right[2]);
}

} /* bakge */
} /* math */
