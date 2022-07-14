#include "KBTpc.hh"

class KBFTDetector : public KBTpc
{
	public :
		KBFTDetector();
		virtual ~KBFTDetector() {};

		virtual Init();
		
	private : 
		virtual bool BuildDetectorPlane();


};
