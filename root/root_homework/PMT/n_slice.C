#include<TCanvas.h>
#include<TProfile.h>
#include<TF1.h>
#include <TMath.h>

Double_t xl[20000];
Double_t yl[20000];
Double_t zl[20000];

void n_slice(Int_t norder=200,char s[]="Decay Distribution")
{

  
  TTree *dataPMT = new TTree("data of PMT","i-xyz");
  Long64_t numPMT = dataPMT->ReadFile("PMTPos_InBallPhoCath.txt","i:x:y:z");
  Float_t i,x,y,z;
  dataPMT->SetBranchAddress("i",&i);
  dataPMT->SetBranchAddress("x",&x);
  dataPMT->SetBranchAddress("y",&y);
  dataPMT->SetBranchAddress("z",&z);
  for(int k=0;k<numPMT;k++)
    {
      dataPMT->GetEntry(k);
      xl[k]=x;
      yl[k]=y;
      zl[k]=z;
    }

  TH1F *hist =new TH1F(s,"",170,8,25);
  TFile *fp =TFile::Open("data.root");
  TTree *tree =(TTree*) fp->Get("t");
  Int_t total_entry=tree->GetEntries();
  Int_t mid=TMath::Floor(total_entry/norder);

  for(in=0;in<norder;in++)
    {
      hist->Fill(one_fit(mid*in,mid*(in+1),tree,numPMT));
    }
		
  TCanvas *c1 =new TCanvas("c1","c1");
  hist->Draw();
  
  //TFile out("my_data.root","UPDATE");
  //hist->Write();
  //out.Close();
}



Double_t one_fit(Int_t left,Int_t right,TTree *it,Int_t numPMT)
{
  Double_t max=0,min=28;
  TProfile *tp =new TProfile("","",100,6,28,0,10000);
  TH1F *h =new TH1F("","",numPMT,0,numPMT);
  Double_t d,xx,yy,zz;
  TVector3 v0(10000,0,0),v;
  Int_t N,sn,nb;
  it->SetBranchAddress("xx",&xx);
  it->SetBranchAddress("yy",&yy);
  it->SetBranchAddress("zz",&zz);
  it->SetBranchAddress("snPMT",&sn);
  it->SetBranchAddress("N",&N);
  for(Int_t in=left;in<right;in++)
    {
      it->GetEntry(in);
      h->Fill(sn);
    }
  for(in=0;in<numPMT;in++)
    {
      v.SetXYZ(xl[in],yl[in],zl[in]);
      d=(v-v0).Mag()/1000;
      nb=h->GetBinContent(in);
      tp->Fill(d,nb);
      if(d>max) max=d;
      if(d<min) min=d;
    }
  TF1 f("","[0]/(x*x)*TMath::Exp(-x/[1])",8,28);
  f.SetParameters(20,20);
  tp->Fit(&f,"","",min,max);
  Double_t decay;
  decay=f.GetParameter(1);
  printf("the fitting decay Distance is : %f m\n",decay);
  return decay;
}
