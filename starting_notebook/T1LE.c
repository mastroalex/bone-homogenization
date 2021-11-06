/*************************************************************
* AceGen    7.205 MacOSX (15 Jan 21)                         *
*           Co. J. Korelc  2020           27 Oct 21 18:34:38 *
**************************************************************
User     : Full professional version
Notebook : project1_start
Evaluation time                 : 2 s     Mode  : Optimal
Number of formulae              : 76      Method: Automatic
Subroutine                      : SKR size: 781
Subroutine                      : SPP size: 548
Total size of Mathematica  code : 1329 subexpressions
Total size of C code            : 3657 bytes */
#include "sms.h"

void SKR(double v[313],ElementSpec *es,ElementData *ed,NodeSpec **ns,NodeData **nd,double *rdata,int *idata,double *p,double **s);
void SPP(double v[313],ElementSpec *es,ElementData *ed,NodeSpec **ns,NodeData **nd,double *rdata,int *idata,double **gpost,double **npost);

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
  static double version[3]={7.205,7.205,12.1};
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
  es->id.NoCharSwitch=0;es->id.WorkingVectorSize=313;es->CharSwitch=cswitch;
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

  es->id.DefaultIntegrationCode=2;
  if(ic==-1){intc=2;} else {intc=ic;};
  es->id.IntCode=intc;
  SMTMultiIntPoints(&intc,idata,&es->id.NoIntPoints,
      &es->id.NoIntPointsA,&es->id.NoIntPointsB,&es->id.NoIntPointsC,0);
  es->id.NoAdditionalData=(int)(0);
  es->id.NoTimeStorage=(int)(0);
  es->id.NoElementData=(int)(0);


  es->NoNodeStorage=nsto;es->NoNodeData=ndat;
  
  es->ExtraSensitivityData=esdat;
  if(1){
   return 0;
  }else{
   return 1;
  };
};


/******************* S U B R O U T I N E *********************/
void SKR(double v[313],ElementSpec *es,ElementData *ed,NodeSpec **ns
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
v[134]=v[29]/2e0;
v[130]=nd[0]->at[0]*v[29];
v[129]=nd[0]->at[1]*v[29];
v[63]=v[27]/v[29];
v[62]=-(v[28]/v[29]);
v[60]=-(v[25]/v[29]);
v[59]=v[26]/v[29];
v[33]=v[59]+v[60];
v[190]=0e0;
v[191]=v[33];
v[192]=0e0;
v[193]=-v[59];
v[194]=0e0;
v[195]=-v[60];
v[41]=(v[21]*v[25]-v[19]*v[26]+v[129]*v[33])/v[29];
v[32]=v[62]+v[63];
v[208]=v[134]*v[33];
v[209]=v[134]*v[32];
v[210]=-v[26]/2e0;
v[211]=v[28]/2e0;
v[212]=v[25]/2e0;
v[213]=-v[27]/2e0;
v[196]=v[32];
v[197]=0e0;
v[198]=-v[62];
v[199]=0e0;
v[200]=-v[63];
v[201]=0e0;
v[180]=2e0*v[33];
v[181]=2e0*v[32];
v[182]=-2e0*v[59];
v[183]=-2e0*v[62];
v[184]=-2e0*v[60];
v[185]=-2e0*v[63];
v[39]=(v[20]*v[25]-v[18]*v[26]-v[21]*v[27]+v[19]*v[28]+v[129]*v[32]+v[130]*v[33])/(2e0*v[29]);
v[38]=(-(v[20]*v[27])+v[18]*v[28]+v[130]*v[32])/v[29];
v[4]=es->Data[1];
v[46]=es->Data[0]/(2e0*(1e0+v[4]));
v[131]=2e0*v[46];
v[44]=(v[131]*v[4])/(1e0-2e0*v[4]);
v[52]=(v[38]+v[41])*v[44];
v[51]=v[131]*v[38]+v[52];
v[53]=v[131]*v[41]+v[52];
v[168]=v[32]*v[51];
v[169]=v[33]*v[53];
v[170]=-(v[51]*v[62]);
v[171]=-(v[53]*v[59]);
v[172]=-(v[51]*v[63]);
v[173]=-(v[53]*v[60]);
i1=es->id.NoIntPoints;
for(i2=1;i2<=i1;i2++){
 v[9]=es->IntPoints[3+4*(-1+i2)];
 v[132]=v[29]*v[9];
 for(i48=1;i48<=6;i48++){
  v[133]=v[179+i48]*v[46];
  v[61]=v[132]*v[189+i48];
  v[64]=v[132]*v[195+i48];
  v[67]=v[44]*(v[61]+v[64]);
  v[66]=v[131]*v[64]+v[67];
  v[68]=v[131]*v[61]+v[67];
  v[202]=v[32]*v[66];
  v[203]=v[33]*v[68];
  v[204]=-(v[62]*v[66]);
  v[205]=-(v[59]*v[68]);
  v[206]=-(v[63]*v[66]);
  v[207]=-(v[60]*v[68]);
  p[i48-1]+=v[132]*(v[167+i48]+v[133]*v[39]);
  for(i56=i48;i56<=6;i56++){
   s[i48-1][i56-1]+=v[201+i56]+v[133]*v[207+i56]*v[9];
  };/* end for */
 };/* end for */
};/* end for */
};

/******************* S U B R O U T I N E *********************/
void SPP(double v[313],ElementSpec *es,ElementData *ed,NodeSpec **ns
     ,NodeData **nd,double *rdata,int *idata,double **gpost,double **npost)
{
int i72,i73;
v[92]=nd[2]->at[1];
v[91]=nd[2]->at[0];
v[90]=nd[1]->at[1];
v[89]=nd[1]->at[0];
v[88]=nd[0]->at[1];
v[87]=nd[0]->at[0];
v[82]=nd[0]->X[1];
v[99]=nd[2]->X[1]-v[82];
v[98]=nd[1]->X[1]-v[82];
v[81]=nd[0]->X[0];
v[97]=nd[2]->X[0]-v[81];
v[96]=nd[1]->X[0]-v[81];
v[100]=-(v[97]*v[98])+v[96]*v[99];
v[142]=v[100]*v[87];
v[141]=v[100]*v[88];
v[104]=(-v[96]+v[97])/v[100];
v[112]=(v[104]*v[141]+v[92]*v[96]-v[90]*v[97])/v[100];
v[103]=(v[98]-v[99])/v[100];
v[110]=(v[103]*v[141]+v[104]*v[142]+v[91]*v[96]-v[89]*v[97]-v[92]*v[98]+v[90]*v[99])/(2e0*v[100]);
v[109]=(v[103]*v[142]-v[91]*v[98]+v[89]*v[99])/v[100];
v[75]=es->Data[1];
v[143]=es->Data[0]/(1e0+v[75]);
v[121]=v[110]*v[143];
v[123]=((v[109]+v[112])*v[143]*v[75])/(1e0-2e0*v[75]);
v[124]=v[123]+v[112]*v[143];
v[120]=v[123]+v[109]*v[143];
i72=es->id.NoIntPoints;
for(i73=1;i73<=i72;i73++){
 gpost[i73-1][0]=v[109];
 gpost[i73-1][1]=v[110];
 gpost[i73-1][2]=v[112];
 gpost[i73-1][3]=v[120];
 gpost[i73-1][4]=v[121];
 gpost[i73-1][5]=v[124];
};/* end for */
npost[0][0]=v[87];
npost[1][0]=v[89];
npost[2][0]=v[91];
npost[0][1]=v[88];
npost[1][1]=v[90];
npost[2][1]=v[92];
npost[0][2]=v[87];
npost[1][2]=v[89];
npost[2][2]=v[91];
npost[0][3]=v[88];
npost[1][3]=v[90];
npost[2][3]=v[92];
};
