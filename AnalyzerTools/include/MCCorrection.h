#ifndef MCCorrection_h
#define MCCorrection_h

#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

#include "TFile.h"
#include "TString.h"
#include "TRegexp.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH3F.h"
#include "TGraph.h"
#include "TGraphAsymmErrors.h"

#include "TDirectoryHelper.h"
#include "TRandom3.h"

using namespace std;

class MCCorrection{

public:

  MCCorrection();
  ~MCCorrection();

  TDirectory *histDir;
  void ReadHistograms();

  bool IsData;
  void SetIsData(bool b);

  bool IgnoreNoHist;

  double MomentumReweight_SF(TString flag, double P_beam_inst, int sys);
  std::map< TString, TH1D* > map_hist_MomentumReweight;

  double dEdx_scaled(double MC_dEdx, double slope_fraction = 1.);
  double Use_Other_Mod_Box_Params(double dEdx, double Efield, double alpha_new, double beta_new, double calib_const_ratio);
  double Use_Abbey_Recom_Params(double dEdx, double Efield, double calib_const_ratio);
  TString sce = "on";
  TH3F *xneg;
  TH3F *yneg;
  TH3F *zneg;
  TH3F *xpos;
  TH3F *ypos;
  TH3F *zpos;
  std::vector<TH3F*> pos_hists, neg_hists;
  double SCE_Corrected_E(double x, double y, double z);

};

#endif
