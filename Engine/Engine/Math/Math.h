#pragma once

float BilinearInterpolation(float bottomLeft, float topLeft, float bottomRight, float topRight,
	float xMin, float xMax,
	float zMin, float zMax,
	float xToCalc, float yToCalc);


float SmoothInterpolation(float bottomLeft, float topLeft, float bottomRight, float topRight,
	int xMin, int xMax,
	int zMin, int zMax,
	int x, int z);


namespace LaiEngine
{
	namespace Math
	{
		extern float EPSILON; 

		int Ceil(const float val);
		int Floor(const float val);
		int Round(const float val);
	}
}