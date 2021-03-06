/***************************************************************************** 
 * Project: RooFit                                                           * 
 *                                                                           * 
 * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/ 

// Your description goes here... 

#include "Riostream.h" 

#include "mypdf.h" 
#include "RooAbsReal.h" 
#include "RooAbsCategory.h" 
#include <math.h> 
#include "TMath.h" 

ClassImp(mypdf) 

 mypdf::mypdf(const char *name, const char *title, 
                        RooAbsReal& _x,
                        RooAbsReal& _a,
                        RooAbsReal& _b) :
   RooAbsPdf(name,title), 
   x("x","x",this,_x),
   a("a","a",this,_a),
   b("b","b",this,_b)
 { 
 } 


 mypdf::mypdf(const mypdf& other, const char* name) :  
   RooAbsPdf(other,name), 
   x("x",this,other.x),
   a("a",this,other.a),
   b("b",this,other.b)
 { 
 } 



 Double_t mypdf::evaluate() const 
 { 
   // ENTER EXPRESSION IN TERMS OF VARIABLE ARGUMENTS HERE 
   return a*fabs(x)+b ; 
 } 



