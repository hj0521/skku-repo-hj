#include "KBPadPlane.hh"
#include "KBTpcHit.hh"
#include "TF1.h"
#include "KBFTPseudoPad.hh"

using namespace std;
using namespace TMath;

ClassImp(KBFTPseudoPad);

KBFTPseudoPad::KBFTPseudoPad()
:KBPadPlane("FT Pad","FT padname")
{
}

bool KBFTPseudoPad::Init()
{
	TObjArray * fInPadArray = new TObjArray();
	
	int padID = 0;

	int layerN = 3;
	int row = 100;
	int column = 100;

	auto FTXsize = fPar -> GetParDouble("FTLayerD");
	auto FTYsize = fPar -> GetParDouble("FTLayerD");
	auto fAxis = fPar -> GetParAxis("LHTF_refAxis",5);
	
	//double FTXsize = 950;
	//double FTYsize = 950;
	
	auto fPadWidth = FTXsize/row;
	auto fPadHeight = FTYsize/column;

	for(int i = 0; i < layerN; i++)
	{
		double pos_z = 950 + 50 * i;

		for(int j = 0; j < row; j++)
		{
			for(int k = 0; k < column; k++)
			{
				KBPad * pad = new KBPad();
				double pos_x = fPadWidth * j;
				double pos_y = fPadHeight * k;
			//	KBVector3 posPad(fAxis,pos_x,pos_y,pos_z);
				
			//	pad -> SetPosition(posPad);
				pad -> SetPadID(padID);

				padID++;
			}
		}
			
	}	

	return true;
}

