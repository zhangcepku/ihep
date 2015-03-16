/*****************************************************************************
 * Project: RooFit                                                           *
 *                                                                           *
  * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/

#ifndef MYPDF
#define MYPDF

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
 
class mypdf : public RooAbsPdf {
public:
  mypdf() {} ; 
  mypdf(const char *name, const char *title,
	      RooAbsReal& _x,
	      RooAbsReal& _a,
	      RooAbsReal& _b);
  mypdf(const mypdf& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new mypdf(*this,newname); }
  inline virtual ~mypdf() { }

protected:

  RooRealProxy x ;
  RooRealProxy a ;
  RooRealProxy b ;
  
  Double_t evaluate() const ;

private:

  ClassDef(mypdf,1) // Your description goes here...
};
 
#endif