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

void RecursiveSine::Serialise(const std::string& path) const
{
    nlohmann::json json;
    json["Type"] = "RecursiveSine";
    json["Amplitude"] = amplitude;
    json["Omega"] = omega;
    json["LastSample1"] = lastSample1;
    json["LastSample2"] = lastSample2;
    json["FirstIteration"] = firstIteration;

    std::ofstream file(path);
    if (!file) throw std::runtime_error("Nie mo¿na otworzyæ pliku do zapisu");
    file << json.dump(4);
    file.close();
}

void RecursiveSine::Deserialise(const std::string& path)
{
    std::ifstream file(path);
    if (!file) throw std::runtime_error("Nie mo¿na otworzyæ pliku do odczytu");

    nlohmann::json json;
    file >> json;
    if (json["Type"] != "RecursiveSine")
        throw std::runtime_error("Nieprawid³owy typ sygna³u");
    amplitude = json["Amplitude"].get<double>();
    omega = json["Omega"].get<double>();
    lastSample1 = json["LastSample1"].get<double>();
    lastSample2 = json["LastSample2"].get<double>();
    firstIteration = json["FirstIteration"].get<bool>();
    file.close();
}