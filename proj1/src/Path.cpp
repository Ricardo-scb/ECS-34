#include "Path.h" 	  			 	 
#include <cstdlib>
#include <unistd.h>
#include <vector>
#include "StringUtils.h"

struct CPath::SImplementation{
    // Your code goes here
	std::string DPath;

};

CPath::CPath() : DImplementation(std::make_unique< SImplementation >()) {
	// Your code goes here
	// pointer towards other data members 
}

CPath::CPath(const CPath &path) : DImplementation(std::make_unique< SImplementation >()){
    // Your code goes here
	DImplementation->DPath = path.DImplementation->DPath;
}

CPath::CPath(const std::string &path): DImplementation(std::make_unique< SImplementation >()) {
    // Your code goes here
	DImplementation->DPath = path;
}

CPath::~CPath(){
    // Your code goes here
	// destructor dont need to implemmnet something 
}

CPath &CPath::operator=(const CPath &path){
	// Dimplementation points to DPath data member and assigns it to
	DImplementation->DPath = path.DImplementation->DPath;
	return this*;

}

CPath CPath::operator+(const CPath &path) const{
	// need to add '/' for one of the cases
	if (IsAbsolute()) {
		return path;
	}
	else {
		CPath addition;
		addition.DImplementation->DPath + '/' + path.DImplementation->DPath;
	}
	return addition;
}

bool CPath::operator==(const CPath &path) const{
	return DImplementation->DPath == path.DImplementation->DPath;
}
}

bool CPath::operator!=(const CPath &path) const{
	return DImplementation->DPath != path.DImplementation->DPath;
}

CPath CPath::Directory() const{
    // Your code goes here
	return CPath;
}

std::string CPath::BaseName() const{
	// directory + basename should just be the same thing 
    // Your code goes here
	return ""; 
}

std::string CPath::Extension() const{
    // Your code goes here
}

bool CPath::IsAbsolute() const{
    // Your code goes here
	if (DImplementation->DPath.empty()) {
		return false;
	}
	std::cout << "In File" << __FILE__ << " @ line " << __FILE__ << std::endl;
	return DImplementation->DPath[0] == '/';
}

std::string CPath::ToString() const{
	return DImplementation;
}

CPath::operator std::string() const{
    // Your code goes here
}

CPath CPath::AbsolutePath() const{
    // Your code goes here
	
}

CPath CPath::CommonPath(const CPath &path) const{
    // Your code goes here
}

CPath CPath::NormalizePath() const{
    // Your code goes here
}

CPath CPath::RelativePathTo(const CPath &path) const{
    // Your code goes here
}

// Helper function provided to get the current working directory
std::string CPath::GetCWD(){
    std::vector< char > CurrentPathName;

    CurrentPathName.resize(1024);
    while(NULL == getcwd(CurrentPathName.data(), CurrentPathName.size())){
        CurrentPathName.resize(CurrentPathName.size() * 2);
    }
    return CurrentPathName.data();
}

// Helper funciton provided to get the home directory
std::string CPath::GetHome(){
    return std::getenv("HOME");
}

CPath CPath::AbsolutePath(const CPath &path){
    // Your code goes here
}

CPath CPath::CurrentPath(){
    // Your code goes here
}

CPath CPath::CommonPath(const CPath &path1, const CPath &path2){
    // Your code goes here
}

CPath CPath::ExpandUserPath(const CPath &path){
    // Your code goes here
}

CPath CPath::HomePath(){
    // Your code goes here
}

CPath CPath::NormalizePath(const CPath &path){
    // Your code goes here
}

CPath CPath::RelativePath(const CPath &path, const CPath &startpath){
    // Your code goes here
}
