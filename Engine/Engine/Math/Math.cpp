#include "Math.h"

#include <cmath>

float LaiEngine::Math::EPSILON = 1.0E-8;

float Clamp(float x, float lowerlimit, float upperlimit);

float SmoothStep(float edge0, float edge1, float x)
{
	// Scale, bias and saturate x to 0..1 range
	x = x * x*(3 - 2 * x);
	// Evaluate polynomial
	return (edge0 * x) + (edge1 * (1 - x));
}


float Clamp(float x, float lowerlimit, float upperlimit)
{
	if (x < lowerlimit) x = lowerlimit;
	if (x > upperlimit) x = upperlimit;

	return x;
}


float SmoothInterpolation(float bottomLeft, float topLeft, float bottomRight, float topRight, int xMin, int xMax, int zMin, int zMax, int x, int z)
{
	float width  = xMax - xMin;
	float height = zMax - zMin;
	float xValue = 1 - (x - xMin) / width;
	float zValue = 1 - (z - zMin) / height;

	//std::cout << xValue << std::endl;

	float a = SmoothStep(bottomLeft, bottomRight, xValue);
	float b = SmoothStep(topLeft, topRight, xValue);

	return SmoothStep(a, b, zValue);
}

float BilinearInterpolation(float bottomLeft, float topLeft, float bottomRight, float topRight, float xMin, float xMax, float zMin, float zMax, float x, float z)
{
	float width = xMax - xMin;
	float height = zMax - zMin;

	float xDistanceToMaxValue = xMax - x;
	float zDistanceToMaxValue = zMax - z;

	float xDistanceToMinValue = x - xMin;
	float zDistanceToMinValue = z - zMin;

	return 1.0f / (width * height) * ( 
		     bottomLeft  * xDistanceToMaxValue * zDistanceToMaxValue +
			 bottomRight * xDistanceToMinValue * zDistanceToMaxValue +
			 topLeft     * xDistanceToMaxValue * zDistanceToMinValue +
			 topRight    * xDistanceToMinValue * zDistanceToMinValue );
}

int LaiEngine::Math::Ceil(const float val)
{
	return static_cast<int>(std::ceil(val));
}

int LaiEngine::Math::Floor(const float val)
{
	return static_cast<int>(std::floor(val));
}

int LaiEngine::Math::Round(const float val)
{
	return static_cast<int>(std::round(val));
}
