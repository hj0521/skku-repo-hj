#include "KBPadPlane.hh"
#include "KBTpcHit.hh"
#include "TF1.h"
#include "KBFTPseudoPad.hh"

using namespace std;
using namespace TMath;

KBFTPseudoPad::KBFTPseudoPad()
:KBPadPlane("FTPseudoPlane","FT-PseudoPlane")
{
}

bool KBFTPseudoPad::Init()
{
	TObjArray * fInPadArray = new TObjArray();

	Int_t layerN = 3;
	Int_t row = 100;
	Int_t column = 100;

	Double_t pad_size_x = 10;
	Double_t pad_size_y = 10;

	for(int layer = 0; i < layerN; layer++)
	{
		for(int row =0;row<RowNum;row++ ){
			KBPad *pad = new KBPad();
      		Double_t posI = row*(fPadWidth + fPadGap);
      		Double_t posJ =  layer*(fPadHeight + fPadGap);

			pad -> SetPlaneID(fPlaneID);
      		pad -> SetPadID(padID);

      		pad -> SetAsAdID(asadID);
      		pad -> SetAGETID(agetID);
      		pad -> SetChannelID(channelID);
      		pad -> SetPosition(posPad);
      		pad -> SetSectionRowLayer(0, row, layer);


			auto neighborIndex = PadNeighborIndex(layer, row, padID);
      		for(int index = 0; index<neighborIndex.size(); index++){
        		KBPad *padNeighbor = (KBPad *) fChannelArray -> At(neighborIndex[index]);
        		padNeighbor -> AddNeighborPad(pad);
        		pad -> AddNeighborPad(padNeighbor);
			}	

			fChannelArray->Add(pad);

			fNPadsTotal++;
			padID++;
			channelID++;
		}
	}	

	int nPads = fChannelArray->GetEntriesFast();

	for (Int_t iPad =0; iPad<nPads;iPad++){
		KBPad *pad = (KBPad *) fChannelArray -> At(iPad);
		pad -> SetPadID(iPad);

		int layerID = pad ->GetLayer();
		int rowID = pad -> GetRow();

		std::vector<int> key;
		key.push_back(pad ->GetSection());
		key.push_back(pad->GetRow());
		key.push_back(pad -> GetLayer());

		fPadMap.insert(std::pair<std::vector<int>, int>(key,iPad));
	}

	return true;
}

Int_t KBFTPseudoPad::FindPadID(int section, int row, int layer){
	if (section <0 || section>= fNumSections) return -1;

	Int_t nLayers = fNRowsInLayer[section].size();
  	if (layer < 0 || layer >= nLayers) return -1;

	if (row <  0 || row >= fNRowsInLayer[section][layer]) return -1;
	
	std::vector<Int_t> key;

	key.push_back(section);
	key.push_back(row);
	key.push_back(layer);

	Int_t id = fPadMap[key];

	return id;

}

Int_t KBFTPseudoPad::FindPadID(Double_t i, Double_t j){
	Int_t section = FindSection(i,j);
	if (section ==-1) return -1;

	
}