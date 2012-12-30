#include "stdafx.h"

#include "HashContainer.h"

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Hello world! \n");

	HashContainer hash;

	hash.insert("abr", 1.1);
	hash.insert("abb", 1.1);
	hash.insert("abc", 1.1);
	hash.insert("cba", 1.1);
	hash.insert("asd", 1.2);
	hash.insert("czx", 1.2);
	hash.insert("dg", 1.2);
	hash.insert("cbrta", 1.2);
	hash.insert("dgfsdf", 1.2);
	hash.insert("cbrsas", 1.2);
	
	hash.insert("ytj", 1.2);
	hash.insert("c123ba", 1.2);
	hash.insert("b", 1.2);
	hash.insert("af", 1.2);
	hash.insert("ju", 1.2);
	hash.insert("il.", 1.2);
	hash.insert("123", 1.2);
	hash.insert("c46ba", 1.2);
	hash.insert("sv", 1.2);
	hash.insert(".l", 1.2);
	
	hash.insert("sdf", 1.2);
	hash.insert("oli", 1.2);
	hash.insert("d", 1.2);
	hash.insert("yuj", 1.2);
	hash.insert("56", 1.2);
	hash.insert("sdfb", 1.2);
	hash.insert("'[0'", 1.2);
	hash.insert("12ew", 1.2);
	hash.insert("dfbg", 1.2);
	hash.insert("opjioj", 1.2);

	hash.insert("[;", 1.2);
	hash.insert("afddsf", 1.2);
	hash.insert("yer6ye65uuj", 1.2);
	hash.insert("xcvxzcv", 1.2);
	hash.insert("wer2", 1.2);
	hash.insert("'[fwef'", 1.2);
	hash.insert("hjuj", 1.2);
	hash.insert("olpo", 1.2);
	hash.insert("45645", 1.2);
	hash.insert("45asd5", 1.2);



	hash.debugPrint();

	getchar();
	return 0;
}