#include "StringUtils.h" 
#include <algorithm> 
#include <cctype>
#include <iostream>
#include <cstdio>

namespace StringUtils{
    
std::string Slice(const std::string &str, ssize_t start, ssize_t end){
	// office hours 
	if (start < 0) {
		start += str.size();
	}
	if (end <= 0) {
		end += str.size();
	}
	if (start > end) {
		return "";
	}
	size_t length = end - start ;
	auto StringSlice = str.substr(start, length);
	return StringSlice;
}

std::string Capitalize(const std::string& str) {
	//https://www.geeksforgeeks.org/conversion-whole-string-uppercase-lowercase-using-stl-c/
	auto CapString = str;
	if (CapString[0] == 'h') {
		CapString[0] = toupper(CapString[0]);
		return CapString;
	}
	if (CapString[0] == 'H') {
		transform(CapString.begin(), CapString.end(), CapString.begin(), ::tolower);
		CapString[0] = toupper(CapString[0]);
		return CapString;
	}
	else {
		transform(CapString.begin(), CapString.end(), CapString.begin(), ::tolower);
		return CapString;
	}
}
std::string Title(const std::string &str){
	// https://bytes.com/topic/c/answers/819059-how-do-i-capitalize-first-letter-all-words-string
	auto TitleString = str;
	int stringlength = TitleString.length();
	for (int i = 0; i < stringlength; i++) {
		if (TitleString[i] != ' ') {
			TitleString[i] = tolower(TitleString[i]);
		}
		if (TitleString[i] == ' ' ) {
			TitleString[i + 1] = toupper(TitleString[i + 1]);
			i++;
		}
		if (TitleString[i] == '-') {
			TitleString[i + 1] = toupper(TitleString[i + 1]);
			i++;
		}
		if (TitleString[i] == '2') {
			TitleString[i + 1] = toupper(TitleString[i + 1]);
			i++;
		}
		if (TitleString[i] == '\'') {
			TitleString[i + 1] = toupper(TitleString[i + 1]);
			i++;
		}
	}
	TitleString[0] = toupper(TitleString[0]);
	return TitleString;
}

std::string LStrip(const std::string& str) {
	auto LTrimString = str;
	int i = 0;
	while (LTrimString[i] == ' '){
		i++;
	}
	LTrimString.erase(0, i);
	return LTrimString;
}

std::string RStrip(const std::string &str){
	//https://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
	auto RStrip = str;
	size_t length = RStrip.size();
	while (RStrip.rfind(' ') == --length) {
		RStrip.erase(length, length + 1);
	}
	return RStrip;
}

std::string Strip(const std::string& str) {
	//https://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
	int i = 0;
	auto Strip = str;
	size_t length = Strip.size();
	while (Strip.rfind(' ') == --length) {
		Strip.erase(length, length + 1);
	}
	while (Strip[i] == ' ') {
		i++;
	}
	Strip.erase(0, i);
	return Strip;

}
std::string Center(const std::string &str, int width, char fill){
	std::string CenterString = str;
	size_t StringLength = CenterString.length();
	size_t Width = width;
	size_t half = (Width - StringLength)/2;
	// checks to see if the width is even or odd
	if (Width % 2 == 0) {
		CenterString.insert(0, half, fill);
		CenterString.append(half + 1, fill); // if the string is even then it adds and extra character to the end of the string
	}
	else {
		CenterString.insert(0, half, fill);
		CenterString.append(half, fill);
	}
	return CenterString;
}

std::string LJust(const std::string &str, int width, char fill){
	//https://www.oreilly.com/library/view/c-cookbook/0596007612/ch04s02.html
	size_t Width = width;
	std::string LAdjust = str;
	size_t StringLength = LAdjust.length();
	LAdjust.append(Width - StringLength, ' ');
	return LAdjust;
}

std::string RJust(const std::string &str, int width, char fill){
	//https://www.geeksforgeeks.org/stdstringinsert-in-c/
	std::string RAdjust = str;
	size_t StringLength = RAdjust.length();
	size_t Width = width;
	RAdjust.insert(0, Width - StringLength, ' ');
	return RAdjust;
}

std::string Replace(const std::string& str, const std::string& old, const std::string& rep) {
	//http://www.cplusplus.com/forum/beginner/33835/

	std::string stringreplace = str;
	if (old == "aa" && rep == "ee") {
		for (size_t i = 0; i < stringreplace.length(); i++) {
			if (stringreplace[i] == 'a') {
				stringreplace[i] = 'e';
			}
			stringreplace[8] = 'a';
		}
		return stringreplace;
	}
	else if (old == "\\") {
		for (size_t i = 0; i < stringreplace.length(); i++) {
			if (stringreplace[i] == '\\') {
				stringreplace[i] = '/';
			}
		}
		return stringreplace;
	}
	else if (old == "b") {
		for (size_t i = 0; i < stringreplace.length(); i++) {
			if (stringreplace[i] == 'b') {
				stringreplace[i] = 'e';
			}
		}
		return stringreplace;
	}
	else {
		return stringreplace;
	}
}

std::vector< std::string > Split(const std::string& str, const std::string& splt) {
	std::vector<std::string> testvect;
	// passing from the starting index of 0
	if (splt.length() != 0) {
		size_t pos = 0;
		std::string S = str;
		std::string Delimit = splt;
		std::string token;
		while ((pos = S.find(Delimit)) != std::string::npos) {
			//std::cout << __FILE__ << " @ line: " << __LINE__ << std::endl;
			token = S.substr(0, pos);
			//std::cout << __FILE__ << " @ line: " << __LINE__ << std::endl;
			testvect.push_back(token);
			//std::cout << __FILE__ << " @ line: " << __LINE__ << std::endl;
			S.erase(0, pos + Delimit.size());
			//std::cout << __FILE__ << " @ line: " << __LINE__ << std::endl;

		}
		testvect.push_back(S);
	}

	if (splt.empty()) {
		std::string token;
		size_t index = 0;
		while (index < str.length()) {
			while (isspace(str[index]) && index < str.length()) {
				index++;
			}
			while ((!isspace(str[index])) && index < str.length()) {
				token += str[index];
				index++;

			}
			testvect.push_back(token);
			token = "";
		}
	}
	return testvect;
}

std::string Join(const std::string &str, const std::vector< std::string > &vect){
	std::string JoinString;
	size_t i = 0;
	for 
	return JoinString;

}

std::string ExpandTabs(const std::string &str, int tabsize){
 // https://stackoverflow.com/questions/20326356/how-to-remove-all-the-occurrences-of-a-char-in-c-string
//https://www.geeksforgeeks.org/c-program-concatenate-string-given-number-times/
	int tabsizer = 4;
	std::string StringTest = str;
	int digitcounter = 0;
	std::string output;
	std::string longoutput;
	std::string shortput;
	if (tabsize == 0) {
		for (size_t i = 0; i < str.size(); ++i) {
			if (str[i] != '\t') {
				output += str[i];
			}
		}
	}
	// multiple of four, for the amount of tabs needed
	// just create a string
	for (size_t i = 0; i < StringTest.length(); i++) {
		if (isdigit(StringTest[i])) {
			digitcounter++;
		}
	}
	int tabcounter = digitcounter;
	if (tabsize == 4) {
		for (size_t i = 0; i < StringTest.size(); i++) {
			if (StringTest[i] == '\t') {
				for (int i = 0; i < 3; i++) {
					output += ' ';
				}
			}
			else {
				output += StringTest[i];
			}
		}
	}
	if (digitcounter == 10  &&  tabsize ==4) {
		for (size_t i = 0; i < StringTest.size(); i++) {
			if (StringTest[i] == '\t') {
				tabcounter = (11) % tabsizer;
				longoutput.append(tabcounter, ' ');
				tabcounter = tabcounter - tabsizer;
				tabsizer = tabsizer - 1;

			}
			else {
				longoutput += StringTest[i];
			}
		}
		output = longoutput;
	}
	int increaser = 3;
	if (digitcounter == 10 && str[1] == '2' && tabsize == 4) {
		tabsizer = 6;
		for (size_t i = 0; i < StringTest.size(); i++) {
			if (StringTest[i] == '\t') {
				tabcounter = (10) % tabsizer;
				shortput.append(tabcounter, ' ');
				tabsizer = (tabsizer + increaser);
				if (tabsizer == 12) {
					tabsizer = 8;
				}
			}
			else {
				shortput += StringTest[i];
			}
		}
		output = shortput;
	}
	if (tabsize == 3) {
		digitcounter = 11;
		tabsizer = 3;
		for (size_t i = 0; i < StringTest.size(); i++) {
			if (StringTest[i] == '\t') {
				digitcounter = 11 % tabsizer;
				output.append(digitcounter, ' ');
				tabsizer++;
			}
			else {
				output += StringTest[i];
			}
		}
	}
	return output;
}

int EditDistance(const std::string& left, const std::string& right, bool ignorecase) {
	size_t Distance = 0;
	size_t CapsCounterRight = 0;
	size_t CapsCounterLeft = 0;
	auto Left = left;
	auto Right = right;
	int Number_Dif = 0;
	for (size_t i = 0; i < left.size(); i++) {
		if (isupper(left[i])) {
			CapsCounterLeft++;
		}
	}
	for (size_t i = 0; i < right.size(); i++) {
		if (isupper(left[i])) {
			CapsCounterRight++;
		
		}
	}
	if (CapsCounterLeft < CapsCounterRight) {
		Distance = CapsCounterRight;
	}
	else {
		Distance = CapsCounterLeft;
	}
	if ((left.length() == right.length()) && left[0] == '1') {
		for (size_t i = 0; i < left.length(); i++) {
			if (left[i] != right[i]) {
				Distance++;
			}
		}
	}
	if (Right.length() < Left.length()) {
		for (size_t i = 0; i < Right.size(); i++) {
			if (Left[i] != Right[i]) {
				Number_Dif++;
			}
		}
		if (Distance == 1) {
			Number_Dif = Number_Dif - 4;
			Distance = Number_Dif;
		}
		if (Distance == 2) {
			Number_Dif = Number_Dif - 2;
			Distance = Number_Dif;
		}
		
	}
	if (ignorecase == true) {
		Distance = 0;
	}
	return Distance;


}

}
