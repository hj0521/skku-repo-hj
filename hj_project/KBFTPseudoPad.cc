#include "KBPadPlane.hh"
#include "KBTpcHit.hh"
#include "TF1.h"
#include "KBFTPseudoPlane.hh"

using namespace std;
using namespace TMath;

KBFTPseudoPlane::KBFTPseudoPlane()
:KBPadPlane("FTPseudoPlane","FT-PseudoPlane")
{
}

bool KBFTPseudoPlane::Init()
{
	TObjArray * fInPadArray = new TObjArray();

	int layerN = 3;
	int row = 100;
	int column = 100;

	double pad_size_x = 10;
	double pad_size_y = 10;

	for(int i = 0; i < layerN; i++)
	{
			
	}	

	return true;
}
