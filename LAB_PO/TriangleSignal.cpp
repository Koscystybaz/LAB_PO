#include "TriangleSignal.h"

TriangleSignal::TriangleSignal(double amplitude, int period, double saturation)
: amplitude(amplitude), period(period), saturation(std::clamp(saturation, 0.0, 1.0))
{

}

double TriangleSignal::Generate(int sample)
{
	int periodSample = sample % period;
	double phase = static_cast<double>(periodSample) / period;

	if (phase < saturation)
	{
		return amplitude * (phase / saturation);
	}
	else
	{
		return amplitude * (1.0 - (phase - saturation) / (1.0 - saturation));
	}
}

void TriangleSignal::Serialize(const std::string& path) const
{
	nlohmann::json json;
	json["Amplitude"] = amplitude;
	json["Period"] = period;
	json["Saturation"] = saturation;
	
	std::ofstream file(path);
	if (file.is_open()) 
	{
		file << json.dump(4);
		file.close();
	}
}
