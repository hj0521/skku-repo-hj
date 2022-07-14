#include "KBFTDetector.hh"
#include "KBFTPseudoPad.hh"
#include "KBPadPlane.hh"

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
	KBFTPseudoPad * test = new KBFTPseudoPad();

	padplane -> Init();

	//padplane -> Init();

	//AddPlane(padplane);

	return true;
	

}
