#pragma once
#include <random>
#include <iostream>
class MT
{
public:
	MT(const MT&) = delete; //Deletes the default copy constructor
	MT& operator=(const MT&) = delete; //Deletes the overloading assignemen
	MT(MT&) = delete; //Move constructor
	static MT& getInstance();//Getter for the Mersene-Twister generator
	static std::mt19937& getGenerator(); //Getter for the random generator
	static double rand_unif(); //Random number following a uniform law
	static double rand_norm(); //Random number following a normal law
private:
	MT(); //Private constructor to prevent initialization
	~MT(); //Destructor to suppress the generator at the end of the programm
	std::mt19937 generator; //The generator
	static MT Mersene_generator; //A Mersene generator
};