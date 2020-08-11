#ifndef XMLWRITER_H 	  			 	 
#define XMLWRITER_H

#include "XMLEntity.h"
#include <stack>
#include <istream>
#include "StringUtils.h"

class CXMLWriter{
    private:
		std::ostream& Output;
		std::stack<SXMLEntity> Buffer;
    public:
        CXMLWriter(std::ostream &os);
        ~CXMLWriter();
        
        bool Flush();
        bool WriteEntity(const SXMLEntity &entity);
};

#endif
                                      