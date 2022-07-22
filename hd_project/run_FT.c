void run_FT(const char *name = "g4event")
{
	auto run = KBRun::GetRun();
	run -> SetIOFile(Form("out_%s_LH.mc",name),Form("out_%s_LH.conv",name));
	run -> AddDetector(new LHTpc());
	run -> AddDetector(new KBFTDetector());
	//run -> AddDetector(new ATTPCm());


	run -> AddParameterContainer("input/kbpar_sim.conf");
	//run -> AddParameterContainer("input/kbpar_tpc.conf");


	//digitization of TPC
	auto drift = new LHDriftElectronTask();
	drift -> SetPadPersistency(true);
	drift -> SetDetID(10); // TPC
	run -> Add(drift);
	
	auto electronics = new LHElectronicsTask();
	run -> Add(electronics);

	//pulse shape analysis
	auto psa = new KBPSATask();
	psa -> SetInputBranchName("TPCPad");
	psa -> SetOutputBranchName("TPCHit");
	psa -> SetHitPersistency(true);
	psa -> SetPSA(new KBPSAFastFit());
	run -> Add(psa);
	
	
	//FT Step & Hit reconstruction
	auto fthit = new FTHit();
	auto ftreco = new FTHitRecoTask();	
	ftreco -> SetDetID(40); // FT
	ftreco -> SetLayerN(3);
	ftreco -> SetRecoHist( ftreco -> GetLayerN(), 200, 0, 200, 1000, -500, 500, 1000, -500, 500);
	ftreco -> SetLimitTimePos(3,50);
	run -> Add(ftreco);	

	//TPC track reconstruction
	auto htfTask = new LHHelixTrackFindingTask();
	htfTask -> SetHitBranchName("TPCHit");
	//htfTask -> SetHitBranchName_FT("FTHit");
	htfTask -> SetTrackletBranchName("Tracklet");
	run->Add(htfTask);
			
	auto gfTask = new LHGenfitTask();
		
	gfTask->SetDetID(10); //TPC
	gfTask->SetDetID(40); //FT
		
	run->Add(gfTask);


	
	
	run -> Init();
	run -> Print();
	run -> Run();

}
