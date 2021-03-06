// -*- C++ -*-
//
// 
/**\class rhoHelper.h rhoHelper.cc
 Description: 
*/
//
// Original Author:  Vladimir Cherepanov 
//         Created:  Mon Sep 4 13:49:02 CET 2017
//
//

#ifndef rhoHelper_h
#define rhoHelper_h


#include <vector>
#include "TLorentzVector.h"
#include "TComplex.h"
#include "TMatrixT.h"
#include "TVectorT.h"
#include "TMatrixTSym.h"
#include <string.h>
#include <vector>
#include "TLorentzVector.h"
using namespace std;


class rhoHelper {
 
 public:
  rhoHelper();
  rhoHelper(vector<TLorentzVector> TauRhoandProd);
  rhoHelper(vector<TLorentzVector> TauRhoandProd, TLorentzVector RefernceFrame);
  ~rhoHelper();
  void Configure(vector<TLorentzVector> TauRhoandProd);
  void Configure(vector<TLorentzVector> TauRhoandProd, TLorentzVector RefernceFrame);
  bool isConfigured();
  void Setup(vector<TLorentzVector> TauRhoandProd, TLorentzVector ReferenceFrame );
  void Initialize(TLorentzVector t, TLorentzVector mu);
  std::vector<TLorentzVector> getBoosted(){return TauRhoandProd_RF;}
  TLorentzVector Boost(TLorentzVector pB, TLorentzVector frame);

  //====================
  double getCosthetaRho(); 
  double getSinthetaRho();
  double getSinbetaRho();
  double getCosbetaRho();
  double getUltrarel_cospsiLF();
  double getSinpsiLF();
  double DPF_cosalpha(); 
  double DPF_sinalpha(); 

  TVector3 nL();
  TVector3 nT();
  TVector3 nPerp();
  TVector3 ns();
  TLorentzVector sLV();

  double getOmegaRho();
  double getOmegaRhoBar();

 private:
  double mpi;
  double mpi0;
  double mtau;
  double coscab;
  double mrho;
  bool debug;

  vector<TLorentzVector> TauRhoandProd_RF;
  TLorentzVector TauLV;
  TLorentzVector TauRhoPi;
  TLorentzVector TauRhoPi0;
  TLorentzVector ProductLV;
  TLorentzVector DPF_TauRhoPi;
  TLorentzVector DPF_TauRhoPi0;
  TLorentzVector InvisibleLV;
  TLorentzVector DPF_TauLV;
  TLorentzVector DPF_InvisibleLV;
  bool isValid_;
  TMatrixT<double> convertToMatrix(TVectorT<double> V);
};
#endif
