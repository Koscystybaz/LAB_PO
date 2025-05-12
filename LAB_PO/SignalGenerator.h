#pragma once
#include <string>

class SignalGenerator
{
public:
	/**
	* 
	*/
	virtual ~SignalGenerator() = default;

	/**
	* 
	*/
	virtual double Generate(int sample) = 0;

	/**
	* 
	*/
	virtual void Serialize(const std::string& path) const = 0;

	/**
	*
	*/
	virtual void Deserialize(const std::string & path) = 0;

};

