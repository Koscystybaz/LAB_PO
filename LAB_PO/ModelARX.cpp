#include <numeric>
#include <iostream>
#include <fstream>
#include <sstream>
#include "ModelARX.h"

ModelARX::ModelARX(std::vector<double> a, std::vector<double> b, unsigned int k, double power) : a(a), b(b), k(k), noise(power)
{
	in.resize(b.size() + k, 0.0);
	out.resize(a.size(), 0.0);
}

ModelARX::ModelARX(const std::string& path)
{
	this->Deserialise(path);
	in.resize(b.size() + k, 0.0);
	out.resize(a.size(), 0.0);
}

ModelARX::~ModelARX()
{
	// Destruktor nie wymaga dodatkowych dzia³añ
}

double ModelARX::Symuluj(double input)
{
	this->in.push_front(input);

	double ar = -std::inner_product(a.begin(), a.end(), out.begin(), 0.0); // iloczyny wspó³cznników AR i przesz³ych wartoœci wyjœciowych
	double x = std::inner_product(b.begin(), b.end(), in.begin() + k, 0.0); // iloczyny wspó³cznników X i przesz³ych wartoœci wejœciowych

	double output = ar + x + this->GenerateNoise(); // wyjœcie modelu ARX

	this->out.push_front(output);
	this->in.pop_back();
	this->out.pop_back();
	return output;
}

void ModelARX::Serialise(const std::string& path) const
{
	nlohmann::json json;
	json["A"] = this->a;
	json["B"] = this->b;
	json["K"] = this->k;
	json["NOISE"] = this->noise;

	std::ofstream file(path);
	if (!file) throw std::runtime_error("Nie mo¿na otworzyæ pliku do zapisu");
	file << json.dump(4);
}

ModelARX ModelARX::Deserialise(const std::string& path)
{
	std::ifstream file(path);
	if (!file) throw std::runtime_error("Nie mo¿na otworzyæ pliku do odczytu: " + path);

	nlohmann::json json;
	file >> json;

	std::vector<double> a = json["A"].get<std::vector<double>>();
	std::vector<double> b = json["B"].get<std::vector<double>>();
	unsigned int k = json["K"].get<unsigned int>();
	double noise = json["NOISE"].get<double>();

	return ModelARX(a, b, k, noise);
}

double ModelARX::GetLastInput() const
{
	return in.back();
}