#include "KBFTDetector.hh"
#include "KBFTPseudoPad.hh"

KBFTDetector::KBFTDetector()
:KBTpc("FT","Foward detector")
{
}

bool KBFTDetector::Init()
{
	BuildDetectorPlane();
	return true;
}

bool KBFTDetector::BuildDetectorPlane()
{
	KBPadPlane *padplane = nullptr;

	padplane = new KBFTPseudoPad();

	padplane -> Init();

	//AddPlane(padplane);

	return true;
	

}
