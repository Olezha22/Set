#include "set.h"
#include <string>


int digits(int n)
{
	std::string nStr = std::to_string(n);
	Set<char> chars;

	for (char& i : nStr)
	{
		chars.addIfNotContains(i);
	}
	return chars.getSize();
}

void task31(char chars[]) 
{
	Set<char> set1;
	set1.addIfNotContains(chars, 11);
	set1.print();
}

void task32(char chars[])
{
	Set<char> set1;
	set1.add(chars, 11);
	set1.repeatedChars(true);
	set1.print();
}

void task33(char chars[])
{
	Set<char> set1;
	set1.add(chars, 11);
	set1.repeatedChars(false);
	set1.print();
}


void eratosthenes(int n) {
	Set<int> num;
	for (int i = 2; i <= n; ++i) {
		num.add(i);
	}

	
	for (int j = 2; j * j <= n; ++j) {
		if (num.contain(j)) {
			for (int k = j * j; k <= n; k += j) {
				num.remove(k);
			}
		}
	}

	num.print();
}

std::ostream& operator<<(std::ostream& os, const Product& product) {
	switch (product) {
	case Product::Bread:   os << "Bread"; break;
	case Product::Butter:  os << "Butter"; break;
	case Product::Milk:    os << "Milk"; break;
	case Product::Cheese:  os << "Cheese"; break;
	case Product::Meat:    os << "Meat"; break;
	case Product::Fish:    os << "Fish"; break;
	case Product::Salt:    os << "Salt"; break;
	case Product::Sugar:   os << "Sugar"; break;
	case Product::Tea:     os << "Tea"; break;
	case Product::Coffee:  os << "Coffee"; break;
	case Product::Water:   os << "Water"; break;
	default:               os << "Unknown"; break;
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const Name& name) {
	switch (name) {
	case Name::Oleksa:     os << "Oleksa"; break;
	case Name::Yuliya:     os << "Yuliya"; break;
	case Name::Kateryna:   os << "Kateryna"; break;
	case Name::Vitaliy:    os << "Vitaliy"; break;
	case Name::Artemiy:    os << "Artemiy"; break;
	case Name::Markiyan:   os << "Markiyan"; break;
	case Name::Vladyslav:  os << "Vladyslav"; break;
	case Name::Oleh:       os << "Oleh"; break;
	case Name::Kseniya:    os << "Kseniya"; break;
	case Name::Olga:       os << "Olga"; break;
	case Name::Sofiya:     os << "Sofiya"; break;
	case Name::Andriy:     os << "Andriy"; break;
	case Name::Ivan:       os << "Ivan"; break;
	case Name::Yuriy:      os << "Yuriy"; break;
	case Name::Taras:      os << "Taras"; break;
	case Name::Kostyantyn: os << "Kostyantyn"; break;
	case Name::Halyna:     os << "Halyna"; break;
	case Name::Vasyl:      os << "Vasyl"; break;
	case Name::Solomiya:   os << "Solomiya"; break;
	case Name::Mykola:     os << "Mykola"; break;
	case Name::Iryna:      os << "Iryna"; break;
	default:                os << "Unknown"; break;
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const City& city) {
	switch (city) {
	case City::Kyiv: return os << "Kyiv";
	case City::Lviv: return os << "Lviv";
	case City::Kharkiv: return os << "Kharkiv";
	case City::Dnipro: return os << "Dnipro";
	case City::Odesa: return os << "Odesa";
	case City::Ternopil: return os << "Ternopil";
	case City::Uzhgorod: return os << "Uzhgorod";
	case City::Lutsk: return os << "Lutsk";
	case City::Rivne: return os << "Rivne";
	case City::Ivano_Frankivsk: return os << "Ivano-Frankivsk";
	case City::Zhytomyr: return os << "Zhytomyr";
	case City::Sumy: return os << "Sumy";
	case City::Donetsk: return os << "Donetsk";
	case City::Luhansk: return os << "Luhansk";
	case City::Zaporizhzhia: return os << "Zaporizhzhia";
	case City::Simferopol: return os << "Simferopol";
	case City::Chernivtsi: return os << "Chernivtsi";
	case City::Khmelnytskyi: return os << "Khmelnytskyi";
	case City::Vinnytsia: return os << "Vinnytsia";
	case City::Cherkasy: return os << "Cherkasy";
	case City::Poltava: return os << "Poltava";
	case City::Chernihiv: return os << "Chernihiv";
	case City::Kropyvnytskyi: return os << "Kropyvnytskyi";
	case City::Mykolaiv: return os << "Mykolaiv";
	case City::Kherson: return os << "Kherson";
	default: return os;
	}
}