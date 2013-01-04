#include "stdafx.h"
#include "Element.h"

Element::Element(void)
	: next(0)
	, value(0)
{
}


Element::~Element(void)
{
}

double Element::getValue()
{
	return value;
}

string Element::getKey()
{
	return key;
}

void Element::setValue(double val)
{
	value = val;
}

void Element::setKey(string k)
{
	key = k;
}

Element* Element::getNextElement()
{
	return next;
}

void Element::setNextElement(Element* el)
{
	next = el;
}