#ifndef CSVREADER_H 	  			 	 
#define CSVREADER_H

#include <istream>
#include <string>
#include <vector>
#include <csv.h>
#include<list>

class CCSVReader{
    protected:
		std::istream& in;
		struct csv_parser CSV_parsing; //needed in order to pass it in the library functions.
		std::vector<std::string> Hold; //holds the data needed 
		static void  CSVCallback1(void*callback1, size_t type, void*data); // for columns
		static void CSVCallback2(int c, void*callback2);// for rows
		std::list<std::vector<std::string>> Buffered;
    public:
        CCSVReader(std::istream &in);
        ~CCSVReader();
        
        bool End() const;// returns true if all the rows have been read from the csv
        bool ReadRow(std::vector< std::string > &row);// Returns true if the row is successfully read, one string will be put in the row per column
};

#endif
