#include "KBFTDetector.hh"

KBFTDetector::KBFTDetector()
:KBTpc("FT","Foward detector")
{
}

bool KBFTDetector::Init()
{
	return true;
}

bool KBFTDetector::BuildDetectorPlane()
{
	KBPadPlane *padplane = nullptr;

	padplane = new KBFTPseudoPad();

	padplane -> SetPlaneID(0);
	padplane -> SetPlaneK(0);
	padplane -> Init();

	AddPlane(padplane);

	return true;
	

}
