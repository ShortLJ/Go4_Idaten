
//-------------------------------------------------------------
//        Go4 Release Package v3.03-05 (build 30305)
//                      05-June-2008
//---------------------------------------------------------------
//   The GSI Online Offline Object Oriented (Go4) Project
//   Experiment Data Processing at EE department, GSI
//---------------------------------------------------------------
//
//Copyright (C) 2000- Gesellschaft f. Schwerionenforschung, GSI
//                    Planckstr. 1, 64291 Darmstadt, Germany
//Contact:            http://go4.gsi.de
//----------------------------------------------------------------
//This software can be used under the license agreements as stated
//in Go4License.txt file which is part of the distribution.
//----------------------------------------------------------------
#ifndef TUNPACKPROCESSOR_H
#define TUNPACKPROCESSOR_H

#define WR_TIME_STAMP     1   // white rabbit time stamp is head of data
#ifdef WR_TIME_STAMP
#endif // WR_TIME_STAMP

#define MAX_SPEZIAL 1000000000

#ifdef WR_TIME_STAMP
#define SUB_SYSTEM_ID      0x0100
#define TS__ID_L16         0x03e1
#define TS__ID_M16         0x04e1
#define TS__ID_H16         0x05e1
#define TS__ID_X16         0x06e1
#endif // WR_TIME_STAMP

#define STATISTIC 200000

#define DUMP_BAD_EVENT 1

#define COARSE_CT_RANGE  0x800  // 11 bits

#define MAX_SSY        1                // maximum number of sub-systems (readout pcs in nxm system)
#define MAX_SFP        4
#define MAX_TAM        7                // maximum febex/tamex per sfp

#define MAX_CHA_old_INPUT 33                // A) maximum physical input channels per module. must be modulo 4
#define MAX_CHA_old       MAX_CHA_old_INPUT * 2 // B) leading egdes + trailing edges + qtc trailing edges
#define MAX_CHA_phy 16
#define MAX_CHA_tam MAX_CHA_phy *2 +1 // last for TTS
//////////////
//#define MAX_CHA_old_INPUT  32                // A) maximum physical input channels per module. must be modulo 4
//#define MAX_CHA_old        MAX_CHA_old_INPUT * 2 // B) leading egdes + trailing edges + qtc trailing edges

// it seems that only "leading" edge bit is set for 0-47 channels
// therefore "MAX_CHA_old_INPUT 48" and only "MAX_CHA_old_INPUT * 1"   
// this has changed to previous version and comments A) and B) are wrong
// so called 17th channel should would appear according to chahit as
// channel nr 48, therefore 49 channels in total

//#define N_DEEP_AN      4                // deep analysis for first N_DEEP_AN channels specified below.
// must be even nr.

#define N_DEEP_AN      0  // JAM 7-june-2022: no deep correlations when we use tree output

#define MAX_CHA_old_AN    24                // total nr. of channels analyzed. must be modulo 4
//#define MAX_CHA_old_AN    64                // total nr. of channels analyzed. must be modulo 4
#define MAX_HITS       1                // max. number of hits per channel accepted
//#define MAX_HITS      10                // max. number of hits per channel accepted

// select 64 channels to be analyzed
// test index:   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63
//               |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
#define SSY_ID { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}//, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

#define SFP_ID { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}//, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }

// test index:   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63
//               |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
// test index:   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63
//               |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
#define TAM_ID { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0}//, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } 
#define CHA_ID { 1,34, 2,35,21,54,22,55, 3,36, 4,37, 0, 1, 0,21, 0, 3, 1,21,21, 3, 3, 1}//, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } // regular


//#define N_CAL_EVT               (ULong64_t) 200000
#define N_CAL_EVT               (ULong64_t) 36*50000

#define N_PHY_TREND_PRINT       (ULong64_t) 1000000

//#define N_DELTA_T   400000
#define N_DELTA_T   1000*1000
#define N_BIN       100000
#define N_TIM       10000

#define N_TR_BINS   100000  
#define N_COARSE    30

#define CYCLE_TIME    (Double_t) 5000

//#define TRIG_WIN_SIZE      200     // in clock cycles 
#define HITPAT_CT_RANGE    20

#define N_BIN_T    600
#define RESET_VAL -100000

#include "TGo4EventProcessor.h"

//#include "TTamex_FullEvent.h"

class TTamex_FullParam;
class TTamex_FullEvent;
class TGo4Fitter;

class TTamex_FullProc : public TGo4EventProcessor {
	public:
		TTamex_FullProc() ;
		TTamex_FullProc(const char* name);
		virtual ~TTamex_FullProc() ;

		Bool_t BuildEvent(TGo4EventElement* target); // event processing function

	private:
		TGo4MbsEvent  *fInput; //!
		TTamex_FullEvent* fOutput; //!

		TTamex_FullParam* fPar;

		Bool_t fCalibrationDone;// flag if calibration is ready

		TH1   *h_box[MAX_SSY][MAX_SFP][MAX_TAM][MAX_CHA_old];  // box histogram in SFP id / TAMEX id / CHANNEL nr coordinates

		TH1   *h_err_box[MAX_SSY][MAX_SFP][MAX_TAM][MAX_CHA_old];  // box histogram in SFP id / TAMEX id / CHANNEL nr coordinates

		TH1   *h_tim[MAX_CHA_old_AN];                          // box histogram in test channel coordinates

		TH1   *h_sum[MAX_CHA_old_AN];                          // sum histogram in test channel coordinates
		TH1   *h_tim_2[MAX_SSY][MAX_SFP][MAX_TAM][MAX_CHA_tam];
		TH1   *h_cct[MAX_SSY][MAX_SFP][MAX_TAM][MAX_CHA_tam];
		TH1   *h_sum_2[MAX_SSY][MAX_SFP][MAX_TAM][MAX_CHA_tam];  // sum histogram in SFP id / TAMEX id / CHANNEL nr coordinates

		TH2   *h_raw_tim_corr[N_DEEP_AN>>1];               // raw time correlatian ch1-ch0, ch3-ch2, ...

		TH1   *h_cal_tim_diff[MAX_CHA_old_AN][MAX_CHA_old_AN];     // calibrated channel time differences

		TH1   *h_cal_tim_diff_wic[MAX_CHA_old_AN][MAX_CHA_old_AN]; // calibrated chan. time diff. 
		TH1   *h_cal_tim_diff_woc[MAX_CHA_old_AN][MAX_CHA_old_AN]; // with a (wic) and without (woc)
																   // clock 
		TH1   *h_coarse_diff[MAX_CHA_old_AN][MAX_CHA_old_AN];      // coarse ctr differences

		TH1   *h_hitpat[MAX_CHA_old_AN];                       // test channel hit pattern

		TH1   *h_coarse[MAX_CHA_old_AN];                       // coarse ctr distribution

		TH1   *h_cal_tim_diff_te[MAX_CHA_old_AN][MAX_CHA_old_AN]; // calibrated channel time differences

		TH1   *h_cal_tim_diff_tr_av[MAX_CHA_old_AN][MAX_CHA_old_AN]; //

		TH1   *h_cal_tim_diff_tr_av_bc[MAX_CHA_old_AN][MAX_CHA_old_AN]; // ... base line corrected      

		TH1   *h_cal_tim_diff_tr_rms[MAX_CHA_old_AN][MAX_CHA_old_AN]; //

		TH2   *h_7_5_vs_11_9; 

		TH1   *h_p_sum_ab;
		TH2   *h_p_tota_vs_a;
		TH2   *h_p_totb_vs_b;
		TH2   *h_p_diff_ba_sum_ab;                

		TH2 *h2_PCHA_STOT[MAX_SSY][MAX_SFP][MAX_TAM];
		TH2 *h2_PCHA_FTOT[MAX_SSY][MAX_SFP][MAX_TAM];

		TH1 *h1_STOT[MAX_SSY][MAX_SFP][MAX_TAM][MAX_CHA_phy];
		TH1 *h1_FTOT[MAX_SSY][MAX_SFP][MAX_TAM][MAX_CHA_phy];
		TH2 *h2_STOT_FTOT[MAX_SSY][MAX_SFP][MAX_TAM][MAX_CHA_phy];
		TH1 *h1_FTle_TTS[MAX_SSY][MAX_SFP][MAX_TAM][MAX_CHA_phy];

		TH1 *h1_Multiplicity[MAX_SSY][MAX_SFP][MAX_TAM][MAX_CHA_tam][3]; // 0 for trailing, 1 for leading, 2 for TOT


		TGo4Picture      *fPicture;

		ClassDef(TTamex_FullProc,1)
};

static  UInt_t l_err_catch = 0;
static  UInt_t l_prev_err_catch = 0;
static  UInt_t l_err_ssy [MAX_CHA_old];
static  UInt_t l_err_sfp [MAX_CHA_old];
static  UInt_t l_err_tam [MAX_CHA_old];
static  UInt_t l_err_cha [MAX_CHA_old];
static  UInt_t l_prev_err_ssy [MAX_CHA_old];
static  UInt_t l_prev_err_sfp [MAX_CHA_old];
static  UInt_t l_prev_err_tam [MAX_CHA_old];
static  UInt_t l_prev_err_cha [MAX_CHA_old];
static  UInt_t l_num_err;
static  UInt_t l_prev_num_err;

#endif //TUNPACKPROCESSOR_H


//----------------------------END OF GO4 SOURCE FILE ---------------------
