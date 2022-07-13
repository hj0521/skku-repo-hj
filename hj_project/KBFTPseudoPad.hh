#include "KBPadPlane.hh"
#include "KBTpcHit.hh"
#include "TF1.h"
#include "KBRun.hh"
#include "KBParameterContainer.hh"

typedef vector<KBHit*> KBTPCHits;

class KBFTPseudoPlane : pulbic KBPadPlane 
{
	public :
		KBFTPseudoPlane();
		virtual ~KBFTPseudoPlane() {};

		virtual bool Init();

	private :
		

}
