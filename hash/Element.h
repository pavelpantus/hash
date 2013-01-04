#pragma once

#include <string>

using namespace std;

class Element
{
public:
	Element(void);
	~Element(void);

	double getValue();
	string getKey();
	Element* getNextElement();

	void setValue(double val);
	void setKey(string k);
	void setNextElement(Element* el);
private:
	string key;
	double value;
	Element* next;
};

