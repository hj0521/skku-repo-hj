#include "KBPadPlane.hh"
#include "KBTpcHit.hh"
#include "TF1.h"
#include "KBRun.hh"
#include "KBParameterContainer.hh"

typedef vector<KBHit*> KBTPCHits;

class KBFTPseudoPad : pulbic KBPadPlane 
{
	public :
		KBFTPseudoPad();
		virtual ~KBFTPseudoPad() {};

		virtual bool Init();

	virtual Int_t FindPadID(Int_t section, Int_t row, Int_t layer);
    virtual Int_t FindPadID(Double_t i, Double_t j);

    virtual Double_t PadDisplacement() const;
  
    virtual bool IsInBoundary(Double_t i, Double_t j);
	
	virtual double GetPadWidth()  const { return fPadWidth;}
    virtual double GetPadHeight()  const { return fPadHeight;}
    virtual double GetPadGap()  const { return fPadGap;}
	
	
	private :
	    std::vector<Int_t> PadNeighborIndex(Int_t layer, Int_t Row, Int_t PadID);
		Int_t RowNum = 32;
		Int_t fNumSections = 1;
		Int_t ColumnNum = 8;
		Double_t fPadWidth = 1.9; // [mm]       // 2.625 old pad type
		Double_t fPadHeight = 11.9; // [mm]     // 12    old pad type
		Double_t fPadGap = 0.1; // [mm]         // 0.5   old pad type
		Double_t fBasePadPos = 100.; // [mm]



}
