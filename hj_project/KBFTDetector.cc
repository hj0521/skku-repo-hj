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
	cout << "test..... " << endl;
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
