#include "RecursiveSine.h"

RecursiveSine::RecursiveSine(double amp, double freq, double sampleFreq)
	: amplitude(amp), omega(2.0 * M_PI * freq), firstIteration(true)
{

}

double RecursiveSine::Symuluj(int t)
{
    if (firstIteration) 
    {
        firstIteration = false;
        lastSample1 = amplitude * std::sin(-omega);
        lastSample2 = 0;
        return 0;
    }

    // Recursive formula: x[n] = 2*cos(w)*x[n-1] - x[n-2]
    double cos_omega = 2.0 * std::cos(omega);
    double present = cos_omega * lastSample2 - lastSample1;

    lastSample1 = lastSample2;
    lastSample2 = present;

    return present;
}

nlohmann::json RecursiveSine::Serialize() const
{
	return {
		{"Type", "RecursiveSine"},
		{"Amplitude", amplitude},
		{"Omega", omega},
		{"LastSample1", lastSample1},
		{"LastSample2", lastSample2},
		{"FirstIteration", firstIteration}
	};
}

void RecursiveSine::Deserialize(const nlohmann::json& json)
{
	amplitude = json.at("Amplitude").get<double>();
	omega = json.at("Omega").get<double>();
	lastSample1 = json.at("LastSample1").get<double>();
	lastSample2 = json.at("LastSample2").get<double>();
	firstIteration = json.at("FirstIteration").get<bool>();
}