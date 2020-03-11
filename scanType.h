#ifndef _SCANTYPE_H_
#define _SCANTYPE_H_
//   SCANNER TOKENDATA
struct TokenData {
     int tokenclass;   // token class
     int linenum;      // line number where token found
     char *tokenstr;   // literal string for token for use
     char *tokenstrVal;   // literal string for token value for use
     char *tokencharVal;   // literal string for token value for use
     char cvalue;    // Character value, if any
     int idValue;      // location in array of values of variable
     int numValue;  // value of number if number is integer
     int boolValue; // Value of boolean
};
#endif
