#include "KBPadPlane.hh"
#include "KBTpcHit.hh"
#include "TF1.h"
#include "KBRun.hh"
#include "KBParameterContainer.hh"

typedef vector<KBHit*> KBTPCHits;

class KBFTPseudoPad : public KBPadPlane 
{
	public :
		KBFTPseudoPad();
		virtual ~KBFTPseudoPad() {};

		virtual bool Init();

	private :
		

};
