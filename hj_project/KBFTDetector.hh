#include "KBTpc.hh"

class KBFTDetector : public KBTpc
{
	public :
		KBFTDetector();
		virtual ~KBFTDetector() {};

		virtual bool Init();
		virtual bool BuildGeometry() {};
		virtual KBVector3::Axis GetEFieldAxis() {};
		virtual TVector3 GetEField(TVector3 pos) {};
		virtual KBPadPlane *GetDriftPlane(TVector3 pos) {};	
	private : 
		virtual bool BuildDetectorPlane();


};
