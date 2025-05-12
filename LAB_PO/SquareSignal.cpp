#include "SquareSignal.h"

SquareSignal::SquareSignal(double frequency, double amplitude, double fill) : frequency(frequency), amplitude(amplitude), fill(fill)
{

}

double SquareSignal::Generate(int sample)
{
	double period = 1.0 / frequency;
	double phase = std::fmod(sample, period) / period;

	return (phase < fill) ? amplitude : -amplitude;
}

void SquareSignal::Serialize(const std::string& path) const
{
	nlohmann::json json;
	json["Amplitude"] = amplitude;
	json["Frequency"] = frequency;
	json["Fill"] = fill;

	std::ofstream file(path);
	if (file.is_open()) {
		file << json.dump(4);
		file.close();
	}
}