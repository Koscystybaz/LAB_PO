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

nlohmann::json ModelARX::Serialize() const
{
	return 
	{
		{"Type", "ModelARX"},
		{"A", a},
		{"B", b},
		{"K", k},
		{"NOISE", noise},
		{"IN", std::vector<double>(in.begin(), in.end())},
		{"OUT", std::vector<double>(out.begin(), out.end())}
	};
}

void ModelARX::Deserialize(const nlohmann::json& json)
{
	a = json.at("A").get<std::vector<double>>();
	b = json.at("B").get<std::vector<double>>();
	k = json.at("K").get<unsigned int>();
	noise = json.at("NOISE").get<double>();

    auto in_vec = json.at("IN").get<std::vector<double>>();
	in = std::deque<double>(in_vec.begin(), in_vec.end());

	auto out_vec = json.at("OUT").get<std::vector<double>>();
	out = std::deque<double>(out_vec.begin(), out_vec.end());

}

double ModelARX::GetLastInput() const
{
	return in.back();
}