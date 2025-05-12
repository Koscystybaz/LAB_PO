#include "SineSignal.h"


SineSignal::SineSignal(double amplitude, double frequency) 
	: amplitude(amplitude), frequency(frequency), previousSample(0.0), previousPreviousSample(0.0), lastSample(-1.0)
{
	previousSample = amplitude * std::sin(2 * M_PI * frequency * 1);
	lastSample = 1.0;
}

double SineSignal::Generate(int sample)
{
	if (sample < 0)
	{
		return 0.0;
	}
	if (sample == 0)
	{
		return previousPreviousSample;
	}
	if (sample == 1)
	{
		return previousSample;
	}
	
	double currentSample = 2 * M_PI * frequency;
	double nextSample = std::cos(currentSample * previousSample - previousPreviousSample);
	previousPreviousSample = previousSample;
	previousSample = nextSample;
	return nextSample;	
}

void SineSignal::Serialize(const std::string& path) const
{
	nlohmann::json json;
	json["Amplitude"] = amplitude;
	json["Frequency"] = frequency;
	json["PreviousSample"] = previousSample;
	json["PreviousPreviousSample"] = previousPreviousSample;
	json["LastSample"] = lastSample;

	std::ofstream file(path);
	if (file.is_open()) {
		file << json.dump(4);
		file.close();
	}
}