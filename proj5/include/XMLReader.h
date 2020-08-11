#ifndef XMLREADER_H 	  			 	 
#define XMLREADER_H

#include "XMLEntity.h"
#include <istream>
#include <expat.h>
#include <queue>

class CXMLReader{
    private:
		std::istream &DInput;
		XML_Parser DParser;
		SXMLEntity Entity;
		std::queue<SXMLEntity> Entities;
		static void XMLCallbackStart(void* data, const XML_Char* el, const XML_Char** attr);
		static void XMLCallbackEnd(void* data, const XML_Char* el);
		static void XMLCallbackHandler(void* userData, const XML_Char* s, int len);
    public:
        CXMLReader(std::istream &is);
        ~CXMLReader();
        
        bool End();
        bool ReadEntity(SXMLEntity &entity, bool skipcdata = false);
};

#endif
