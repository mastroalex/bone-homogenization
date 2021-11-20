/*************************************************************
* AceGen    7.303 MacOSX (3 Aug 21)                          *
*           Co. J. Korelc  2020           20 Nov 21 22:43:29 *
**************************************************************
User     : Full professional version
Notebook : test_homo1
Evaluation time                 : 3 s     Mode  : Optimal
Number of formulae              : 84      Method: Automatic
Subroutine                      : SKR size: 781
Subroutine                      : SPP size: 633
Total size of Mathematica  code : 1414 subexpressions
Total size of C code            : 3895 bytes */
#include "sms.h"

void SKR(double v[327],ElementSpec *es,ElementData *ed,NodeSpec **ns,NodeData **nd,double *rdata,int *idata,double *p,double **s);
void SPP(double v[327],ElementSpec *es,ElementData *ed,NodeSpec **ns,NodeData **nd,double *rdata,int *idata,double **gpost,double **npost);

int MMAInitialisationCode[]={
0,24,123,72,111,108,100,91,78,117,108,108,93,44,32,72,111,108,100,91,78,117,108,108,93,125
};



DLLEXPORT int SMTSetElSpec(ElementSpec *es,int *idata,int ic,int ng)
{ int intc,nd,i;FILE *SMSFile;
  static int pn[9]={1, 2, 3, 0, 1, 2, 3, -1, 0};
  static int dof[3]={2, 2, 2};
  static int nsto[3]={0, 0, 0};

  static int ndat[3]={0, 0, 0};

  static int esdat[1]={0};

  static char *nid[]={"D","D","D"};
  static char *gdcs[]={"E -Young","$[Nu]$ -Poisson"};
  static double defd[]={1e0,0.49e0,0e0};
  static char *gpcs[]={"Dxx","Dxy","Dyy","$[Sigma]$xx","$[Sigma]$xy","$[Sigma]$yy"};
  static char *npcs[]={"DeformedMeshX","DeformedMeshY","u","v"};
  static char *sname[]={""};
  static char *idname[]={""};
  static int idindex[1];
  static char *rdname[]={""};
  static char *cswitch[]={""};
  static int iswitch[1]={0};
  static double dswitch[1]={0e0};
  static int rdindex[1];
  static int nspecs[3];
  static double version[3]={7.303,7.303,12.3};
  static double pnweights[3]={1e0,1e0,1e0};
  static double rnodes[9]={1e0,0e0,0e0,0e0,1e0,0e0,
  0e0,0e0,1e0};
  es->ReferenceNodes=rnodes;
  if(ng==-1) es->Data=defd;
  es->id.NoDomainData=2;
  es->Code="T1LE";es->Version=version;
  es->MainTitle="";
  es->SubTitle="";
  es->SubSubTitle="";
  es->Bibliography="";
  es->id.NoDimensions=2;es->id.NoDOFGlobal=6;es->id.NoDOFCondense=0;es->id.NoNodes=3;
  es->id.NoSegmentPoints=8;es->Segments=pn;es->PostNodeWeights=pnweights;
  es->id.NoIntSwitch=0;es->IntSwitch=iswitch;es->id.LocalReKe=0;
  es->id.NoDoubleSwitch=0;es->DoubleSwitch=dswitch;
  es->id.NoCharSwitch=0;es->id.WorkingVectorSize=327;es->CharSwitch=cswitch;
  es->DOFGlobal=dof;es->NodeID=nid;es->id.NoGPostData=6;es->id.NoNPostData=4;
  es->id.SymmetricTangent=1;es->id.PostIterationCall=0;es->id.DOFScaling=0;
  es->Topology="T1";es->DomainDataNames=gdcs;es->GPostNames=gpcs;es->NPostNames=npcs;
  es->AdditionalNodes="{} & ";
  es->AdditionalGraphics="{Null,Null,Null}";
  es->MMAInitialisation=MMAInitialisationCode;
  es->MMANextStep="";
  es->MMAStepBack="";
  es->MMAPreIteration="";
  es->IDataNames=idname;es->IDataIndex=idindex;es->RDataNames=rdname;es->RDataIndex=rdindex;
  es->id.NoIData=0;es->id.NoRData=0;
  es->id.ShapeSensitivity=0; es->id.EBCSensitivity=0;es->id.SensitivityOrder=0;
  es->id.NoSensNames=0;es->SensitivityNames=sname;es->NodeSpecs=nspecs;
  es->user.SPP=SPP;es->user.SKR=SKR;

  es->id.DefaultIntegrationCode=35;
  if(ic==-1){intc=35;} else {intc=ic;};
  es->id.IntCode=intc;
  SMTMultiIntPoints(&intc,idata,&es->id.NoIntPoints,
      &es->id.NoIntPointsA,&es->id.NoIntPointsB,&es->id.NoIntPointsC,0);
  es->id.NoAdditionalData=(int)(0);
  es->id.NoTimeStorage=(int)(0);
  es->id.NoElementData=(int)(3);


  es->NoNodeStorage=nsto;es->NoNodeData=ndat;
  
  es->ExtraSensitivityData=esdat;
  if(1){
   return 0;
  }else{
   return 1;
  };
};


/******************* S U B R O U T I N E *********************/
void SKR(double v[327],ElementSpec *es,ElementData *ed,NodeSpec **ns
     ,NodeData **nd,double *rdata,int *idata,double *p,double **s)
{
int i1,i2,i48,i56;
v[21]=nd[2]->at[1];
v[20]=nd[2]->at[0];
v[19]=nd[1]->at[1];
v[18]=nd[1]->at[0];
v[11]=nd[0]->X[1];
v[28]=nd[2]->X[1]-v[11];
v[27]=nd[1]->X[1]-v[11];
v[10]=nd[0]->X[0];
v[26]=nd[2]->X[0]-v[10];
v[25]=nd[1]->X[0]-v[10];
v[29]=-(v[26]*v[27])+v[25]*v[28];
v[138]=v[29]/2e0;
v[134]=nd[0]->at[0]*v[29];
v[133]=nd[0]->at[1]*v[29];
v[63]=v[27]/v[29];
v[62]=-(v[28]/v[29]);
v[60]=-(v[25]/v[29]);
v[59]=v[26]/v[29];
v[33]=v[59]+v[60];
v[204]=0e0;
v[205]=v[33];
v[206]=0e0;
v[207]=-v[59];
v[208]=0e0;
v[209]=-v[60];
v[41]=(v[21]*v[25]-v[19]*v[26]+v[133]*v[33])/v[29];
v[32]=v[62]+v[63];
v[222]=v[138]*v[33];
v[223]=v[138]*v[32];
v[224]=-0.5e0*v[26];
v[225]=v[28]/2e0;
v[226]=v[25]/2e0;
v[227]=-0.5e0*v[27];
v[210]=v[32];
v[211]=0e0;
v[212]=-v[62];
v[213]=0e0;
v[214]=-v[63];
v[215]=0e0;
v[194]=2e0*v[33];
v[195]=2e0*v[32];
v[196]=-2e0*v[59];
v[197]=-2e0*v[62];
v[198]=-2e0*v[60];
v[199]=-2e0*v[63];
v[39]=(v[20]*v[25]-v[18]*v[26]-v[21]*v[27]+v[19]*v[28]+v[133]*v[32]+v[134]*v[33])/(2e0*v[29]);
v[38]=(-(v[20]*v[27])+v[18]*v[28]+v[134]*v[32])/v[29];
v[4]=es->Data[1];
v[46]=es->Data[0]/(2e0*(1e0+v[4]));
v[135]=2e0*v[46];
v[44]=(v[135]*v[4])/(1e0-2e0*v[4]);
v[52]=(v[38]+v[41])*v[44];
v[51]=v[135]*v[38]+v[52];
v[53]=v[135]*v[41]+v[52];
v[182]=v[32]*v[51];
v[183]=v[33]*v[53];
v[184]=-(v[51]*v[62]);
v[185]=-(v[53]*v[59]);
v[186]=-(v[51]*v[63]);
v[187]=-(v[53]*v[60]);
i1=es->id.NoIntPoints;
for(i2=1;i2<=i1;i2++){
 v[9]=es->IntPoints[3+4*(-1+i2)];
 v[136]=v[29]*v[9];
 for(i48=1;i48<=6;i48++){
  v[137]=v[193+i48]*v[46];
  v[61]=v[136]*v[203+i48];
  v[64]=v[136]*v[209+i48];
  v[67]=v[44]*(v[61]+v[64]);
  v[66]=v[135]*v[64]+v[67];
  v[68]=v[135]*v[61]+v[67];
  v[216]=v[32]*v[66];
  v[217]=v[33]*v[68];
  v[218]=-(v[62]*v[66]);
  v[219]=-(v[59]*v[68]);
  v[220]=-(v[63]*v[66]);
  v[221]=-(v[60]*v[68]);
  p[i48-1]+=v[136]*(v[181+i48]+v[137]*v[39]);
  for(i56=i48;i56<=6;i56++){
   s[i48-1][i56-1]+=v[215+i56]+v[137]*v[221+i56]*v[9];
  };/* end for */
 };/* end for */
};/* end for */
};

/******************* S U B R O U T I N E *********************/
void SPP(double v[327],ElementSpec *es,ElementData *ed,NodeSpec **ns
     ,NodeData **nd,double *rdata,int *idata,double **gpost,double **npost)
{
int i72,i76;
v[95]=nd[2]->at[1];
v[94]=nd[2]->at[0];
v[93]=nd[1]->at[1];
v[92]=nd[1]->at[0];
v[91]=nd[0]->at[1];
v[90]=nd[0]->at[0];
v[85]=nd[0]->X[1];
v[102]=nd[2]->X[1]-v[85];
v[101]=nd[1]->X[1]-v[85];
v[84]=nd[0]->X[0];
v[100]=nd[2]->X[0]-v[84];
v[99]=nd[1]->X[0]-v[84];
v[103]=-(v[100]*v[101])+v[102]*v[99];
v[146]=v[103]*v[90];
v[145]=v[103]*v[91];
v[107]=(v[100]-v[99])/v[103];
v[115]=(v[107]*v[145]-v[100]*v[93]+v[95]*v[99])/v[103];
v[106]=(v[101]-v[102])/v[103];
v[113]=(v[106]*v[145]+v[107]*v[146]-v[100]*v[92]+v[102]*v[93]-v[101]*v[95]+v[94]*v[99])/(2e0*v[103]
 );
v[112]=(v[106]*v[146]+v[102]*v[92]-v[101]*v[94])/v[103];
v[78]=es->Data[1];
v[147]=es->Data[0]/(1e0+v[78]);
v[124]=v[113]*v[147];
v[126]=((v[112]+v[115])*v[147]*v[78])/(1e0-2e0*v[78]);
v[127]=v[126]+v[115]*v[147];
v[123]=v[126]+v[112]*v[147];
i72=es->id.NoIntPoints;
v[73]=0e0;
v[74]=0e0;
v[75]=0e0;
for(i76=1;i76<=i72;i76++){
 v[148]=es->IntPoints[3+4*(-1+i76)]*v[103];
 v[73]=v[123]*v[148]+v[73];
 v[74]=v[127]*v[148]+v[74];
 v[75]=v[124]*v[148]+v[75];
 gpost[i76-1][0]=v[112];
 gpost[i76-1][1]=v[113];
 gpost[i76-1][2]=v[115];
 gpost[i76-1][3]=v[123];
 gpost[i76-1][4]=v[124];
 gpost[i76-1][5]=v[127];
};/* end for */
ed->Data[0]=v[73];
ed->Data[1]=v[74];
ed->Data[2]=v[75];
npost[0][0]=v[90];
npost[1][0]=v[92];
npost[2][0]=v[94];
npost[0][1]=v[91];
npost[1][1]=v[93];
npost[2][1]=v[95];
npost[0][2]=v[90];
npost[1][2]=v[92];
npost[2][2]=v[94];
npost[0][3]=v[91];
npost[1][3]=v[93];
npost[2][3]=v[95];
};
