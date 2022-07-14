#include "KBTpc.hh"

class KBFTDetector : public KBTpc
{
	public :
		KBFTDetector();
		virtual ~KBFTDetector() {};

		virtual bool Init();
		
	private : 
		virtual bool BuildDetectorPlane();


};
