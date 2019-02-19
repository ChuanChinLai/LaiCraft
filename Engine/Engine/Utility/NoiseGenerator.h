#pragma once

namespace LaiEngine
{
	struct NoiseParameters
	{
		int octaves;
		int amplitude;
		int smoothness;
		int heightOffset;

		float roughness;
	};

	class NoiseGenerator
	{
	public:
		NoiseGenerator(int seed);

		void SetParameters(const NoiseParameters& params) noexcept;

		float GetHeight(int x, int z, int chunkX, int chunkZ) const noexcept;

	private:
		float GetNoise(int  n) const noexcept;
		float GetNoise(float  x, float  z) const noexcept;

		float Lerp(float a, float b, float z) const noexcept;
		float Noise(float  x, float  z) const noexcept;

		NoiseParameters m_noiseParameters;

		int m_seed;
	};
}