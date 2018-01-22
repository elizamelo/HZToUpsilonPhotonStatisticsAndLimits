
#ifndef ROO_DCB_SHAPE
#define ROO_DCB_SHAPE

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"

class RooRealVar;
 
class RooDCBShape : public RooAbsPdf {
public:
  RooDCBShape() {} ; 
  RooDCBShape(const char *name, const char *title,
	      RooAbsReal& _m,
	      RooAbsReal& _m0,
	      RooAbsReal& _sigma,
	      RooAbsReal& _alphaL,
	      RooAbsReal& _alphaR,
	      RooAbsReal& _nL,
	      RooAbsReal& _nR);
  RooDCBShape(const RooDCBShape& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooDCBShape(*this,newname); }
  inline virtual ~RooDCBShape() { }

  virtual Int_t getAnalyticalIntegral(RooArgSet& allVars, RooArgSet& analVars, const char* rangeName=0) const ;
  virtual Double_t analyticalIntegral(Int_t code, const char* rangeName=0) const ;

protected:

  RooRealProxy m ;
  RooRealProxy m0 ;
  RooRealProxy sigma ;
  RooRealProxy alphaL ;
  RooRealProxy alphaR ;
  RooRealProxy nL ;
  RooRealProxy nR ;
  
  Double_t ApproxErf(Double_t arg) const; 
  Double_t evaluate() const ;

private:

  ClassDef(RooDCBShape,1) // Your description goes here...
};
 
#endif
