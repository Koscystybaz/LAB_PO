#include "WhiteNoise.h"

WhiteNoise::WhiteNoise(double mean, double deviation) : distribution(mean, deviation)
{
	generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
}

double WhiteNoise::Generate(int sample)
{
	return distribution(generator);
}

void WhiteNoise::Serialize(const std::string& path) const
{
	nlohmann::json json;
	json["Mean"] = distribution.mean();
	json["Deviation"] = distribution.stddev();

	std::ofstream file(path);
	if (file.is_open())
	{
		file << json.dump(4);
		file.close();
	}
}

