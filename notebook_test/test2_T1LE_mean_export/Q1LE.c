/*************************************************************
* AceGen    7.114 MacOSX (14 Jul 20)                         *
*           Co. J. Korelc  2020           27 Oct 20 11:52:52 *
**************************************************************
User     : Full professional version
Notebook : Intro_AceFEM_2020
Evaluation time                 : 2 s     Mode  : Optimal
Number of formulae              : 155     Method: Automatic
Subroutine                      : SKR size: 1091
Subroutine                      : SPP size: 961
Total size of Mathematica  code : 2052 subexpressions
Total size of C code            : 5804 bytes */
#include "sms.h"

void SKR(double v[392],ElementSpec *es,ElementData *ed,NodeSpec **ns,NodeData **nd,double *rdata,int *idata,double *p,double **s);
void SPP(double v[392],ElementSpec *es,ElementData *ed,NodeSpec **ns,NodeData **nd,double *rdata,int *idata,double **gpost,double **npost);

int MMAInitialisationCode[]={
0,24,123,72,111,108,100,91,78,117,108,108,93,44,32,72,111,108,100,91,78,117,108,108,93,125
};



DLLEXPORT int SMTSetElSpec(ElementSpec *es,int *idata,int ic,int ng)
{ int intc,nd,i;FILE *SMSFile;
  static int pn[11]={1, 2, 3, 4, 0, 1, 2, 3, 4, -1, 0};
  static int dof[4]={2, 2, 2, 2};
  static int nsto[4]={0, 0, 0, 0};

  static int ndat[4]={0, 0, 0, 0};

  static int esdat[1]={0};

  static char *nid[]={"D","D","D","D"};
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
  static int nspecs[4];
  static double version[3]={7.114,7.114,12.};
  static double pnweights[4]={1e0,1e0,1e0,1e0};
  static double rnodes[12]={-1e0,-1e0,0e0,1e0,-1e0,0e0,
  1e0,1e0,0e0,-1e0,1e0,0e0};
  es->ReferenceNodes=rnodes;
  if(ng==-1) es->Data=defd;
  es->id.NoDomainData=2;
  es->Code="Q1LE";es->Version=version;
  es->MainTitle="";
  es->SubTitle="";
  es->SubSubTitle="";
  es->Bibliography="";
  es->id.NoDimensions=2;es->id.NoDOFGlobal=8;es->id.NoDOFCondense=0;es->id.NoNodes=4;
  es->id.NoSegmentPoints=10;es->Segments=pn;es->PostNodeWeights=pnweights;
  es->id.NoIntSwitch=0;es->IntSwitch=iswitch;es->id.LocalReKe=0;
  es->id.NoDoubleSwitch=0;es->DoubleSwitch=dswitch;
  es->id.NoCharSwitch=0;es->id.WorkingVectorSize=392;es->CharSwitch=cswitch;
  es->DOFGlobal=dof;es->NodeID=nid;es->id.NoGPostData=6;es->id.NoNPostData=4;
  es->id.SymmetricTangent=1;es->id.PostIterationCall=0;es->id.DOFScaling=0;
  es->Topology="Q1";es->DomainDataNames=gdcs;es->GPostNames=gpcs;es->NPostNames=npcs;
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
void SKR(double v[392],ElementSpec *es,ElementData *ed,NodeSpec **ns
     ,NodeData **nd,double *rdata,int *idata,double *p,double **s)
{
int i1,i2,i6,i81,i89;
v[25]=nd[3]->at[1];
v[24]=nd[3]->at[0];
v[23]=nd[2]->at[1];
v[22]=nd[2]->at[0];
v[21]=nd[1]->at[1];
v[20]=nd[1]->at[0];
v[19]=nd[0]->at[1];
v[18]=nd[0]->at[0];
v[17]=nd[3]->X[1];
v[16]=nd[3]->X[0];
v[15]=nd[2]->X[1];
v[199]=v[15]-v[17];
v[14]=nd[2]->X[0];
v[201]=v[14]-v[16];
v[13]=nd[1]->X[1];
v[195]=v[13]-v[15];
v[12]=nd[1]->X[0];
v[197]=v[12]-v[14];
v[11]=nd[0]->X[1];
v[198]=v[11]-v[13];
v[194]=v[11]-v[17];
v[10]=nd[0]->X[0];
v[200]=v[10]-v[12];
v[196]=v[10]-v[16];
v[4]=es->Data[1];
v[79]=es->Data[0]/(2e0*(1e0+v[4]));
v[77]=(2e0*v[4]*v[79])/(1e0-2e0*v[4]);
i1=es->id.NoIntPoints;
for(i2=1;i2<=i1;i2++){
 i6=4*(-1+i2);
 v[5]=es->IntPoints[i6];
 v[31]=1e0-v[5];
 v[37]=-v[31]/4e0;
 v[29]=1e0+v[5];
 v[38]=-v[29]/4e0;
 v[43]=v[194]*v[37]+v[195]*v[38];
 v[41]=v[196]*v[37]+v[197]*v[38];
 v[7]=es->IntPoints[1+i6];
 v[32]=1e0+v[7];
 v[39]=v[32]/4e0;
 v[27]=1e0-v[7];
 v[36]=-v[27]/4e0;
 v[42]=v[198]*v[36]+v[199]*v[39];
 v[40]=v[200]*v[36]+v[201]*v[39];
 v[44]=-(v[41]*v[42])+v[40]*v[43];
 v[192]=es->IntPoints[3+i6]*v[44];
 v[47]=-(v[43]/v[44]);
 v[61]=-(v[32]*v[47])/4e0;
 v[53]=(v[27]*v[47])/4e0;
 v[48]=v[41]/v[44];
 v[64]=-(v[32]*v[48])/4e0;
 v[55]=(v[27]*v[48])/4e0;
 v[49]=-(v[42]/v[44]);
 v[62]=-(v[31]*v[49])/4e0;
 v[57]=-(v[29]*v[49])/4e0;
 v[50]=v[40]/v[44];
 v[65]=-(v[31]*v[50])/4e0;
 v[59]=-(v[29]*v[50])/4e0;
 v[51]=v[53]+v[62];
 v[52]=v[55]+v[65];
 v[54]=-v[53]+v[57];
 v[56]=-v[55]+v[59];
 v[58]=-v[57]+v[61];
 v[60]=-v[59]+v[64];
 v[63]=-v[61]-v[62];
 v[269]=v[51];
 v[270]=0e0;
 v[271]=v[54];
 v[272]=0e0;
 v[273]=v[58];
 v[274]=0e0;
 v[275]=v[63];
 v[276]=0e0;
 v[66]=-v[64]-v[65];
 v[277]=0e0;
 v[278]=v[52];
 v[279]=0e0;
 v[280]=v[56];
 v[281]=0e0;
 v[282]=v[60];
 v[283]=0e0;
 v[284]=v[66];
 v[257]=v[52];
 v[258]=v[51];
 v[259]=v[56];
 v[260]=v[54];
 v[261]=v[60];
 v[262]=v[58];
 v[263]=v[66];
 v[264]=v[63];
 v[71]=v[18]*v[51]+v[20]*v[54]+v[22]*v[58]+v[24]*v[63];
 v[72]=(v[19]*v[51]+v[18]*v[52]+v[21]*v[54]+v[20]*v[56]+v[23]*v[58]+v[22]*v[60]+v[25]*v[63]
  +v[24]*v[66])/2e0;
 v[74]=v[19]*v[52]+v[21]*v[56]+v[23]*v[60]+v[25]*v[66];
 v[85]=(v[71]+v[74])*v[77];
 v[84]=2e0*v[74]*v[79]+v[85];
 v[86]=2e0*v[71]*v[79]+v[85];
 v[241]=v[51]*v[86];
 v[242]=v[52]*v[84];
 v[243]=v[54]*v[86];
 v[244]=v[56]*v[84];
 v[245]=v[58]*v[86];
 v[246]=v[60]*v[84];
 v[247]=v[63]*v[86];
 v[248]=v[66]*v[84];
 for(i81=1;i81<=8;i81++){
  v[193]=v[256+i81]*v[79];
  v[92]=v[192]*v[268+i81];
  v[93]=v[192]*v[276+i81];
  v[96]=v[77]*(v[92]+v[93]);
  v[95]=2e0*v[79]*v[93]+v[96];
  v[97]=2e0*v[79]*v[92]+v[96];
  v[285]=v[51]*v[97];
  v[286]=v[52]*v[95];
  v[287]=v[54]*v[97];
  v[288]=v[56]*v[95];
  v[289]=v[58]*v[97];
  v[290]=v[60]*v[95];
  v[291]=v[63]*v[97];
  v[292]=v[66]*v[95];
  p[i81-1]+=v[192]*(v[240+i81]+2e0*v[193]*v[72]);
  for(i89=i81;i89<=8;i89++){
   s[i81-1][i89-1]+=v[192]*v[193]*v[256+i89]+v[284+i89];
  };/* end for */
 };/* end for */
};/* end for */
};

/******************* S U B R O U T I N E *********************/
void SPP(double v[392],ElementSpec *es,ElementData *ed,NodeSpec **ns
     ,NodeData **nd,double *rdata,int *idata,double **gpost,double **npost)
{
int i102,i103,i107;
v[126]=nd[3]->at[1];
v[125]=nd[3]->at[0];
v[124]=nd[2]->at[1];
v[123]=nd[2]->at[0];
v[122]=nd[1]->at[1];
v[121]=nd[1]->at[0];
v[120]=nd[0]->at[1];
v[119]=nd[0]->at[0];
v[118]=nd[3]->X[1];
v[117]=nd[3]->X[0];
v[116]=nd[2]->X[1];
v[212]=v[116]-v[118];
v[115]=nd[2]->X[0];
v[214]=v[115]-v[117];
v[114]=nd[1]->X[1];
v[208]=v[114]-v[116];
v[113]=nd[1]->X[0];
v[210]=v[113]-v[115];
v[112]=nd[0]->X[1];
v[211]=v[112]-v[114];
v[207]=v[112]-v[118];
v[111]=nd[0]->X[0];
v[213]=v[111]-v[113];
v[209]=v[111]-v[117];
v[105]=es->Data[1];
v[180]=es->Data[0]/(2e0*(1e0+v[105]));
v[206]=2e0*v[180];
v[178]=(2e0*v[105]*v[180])/(1e0-2e0*v[105]);
i102=es->id.NoIntPoints;
for(i103=1;i103<=i102;i103++){
 i107=4*(-1+i103);
 v[106]=es->IntPoints[i107];
 v[132]=1e0-v[106];
 v[138]=-v[132]/4e0;
 v[130]=1e0+v[106];
 v[139]=-v[130]/4e0;
 v[144]=v[138]*v[207]+v[139]*v[208];
 v[142]=v[138]*v[209]+v[139]*v[210];
 v[108]=es->IntPoints[1+i107];
 v[133]=1e0+v[108];
 v[140]=v[133]/4e0;
 v[128]=1e0-v[108];
 v[137]=-v[128]/4e0;
 v[143]=v[137]*v[211]+v[140]*v[212];
 v[141]=v[137]*v[213]+v[140]*v[214];
 v[145]=-(v[142]*v[143])+v[141]*v[144];
 v[148]=-(v[144]/v[145]);
 v[162]=-(v[133]*v[148])/4e0;
 v[154]=(v[128]*v[148])/4e0;
 v[149]=v[142]/v[145];
 v[165]=-(v[133]*v[149])/4e0;
 v[156]=(v[128]*v[149])/4e0;
 v[150]=-(v[143]/v[145]);
 v[163]=-(v[132]*v[150])/4e0;
 v[158]=-(v[130]*v[150])/4e0;
 v[151]=v[141]/v[145];
 v[166]=-(v[132]*v[151])/4e0;
 v[160]=-(v[130]*v[151])/4e0;
 v[152]=v[154]+v[163];
 v[153]=v[156]+v[166];
 v[155]=-v[154]+v[158];
 v[157]=-v[156]+v[160];
 v[159]=-v[158]+v[162];
 v[161]=-v[160]+v[165];
 v[164]=-v[162]-v[163];
 v[167]=-v[165]-v[166];
 v[172]=v[119]*v[152]+v[121]*v[155]+v[123]*v[159]+v[125]*v[164];
 v[173]=(v[120]*v[152]+v[119]*v[153]+v[122]*v[155]+v[121]*v[157]+v[124]*v[159]+v[123]*v[161]
  +v[126]*v[164]+v[125]*v[167])/2e0;
 v[175]=v[120]*v[153]+v[122]*v[157]+v[124]*v[161]+v[126]*v[167];
 v[186]=(v[172]+v[175])*v[178];
 gpost[i103-1][0]=v[172];
 gpost[i103-1][1]=v[173];
 gpost[i103-1][2]=v[175];
 gpost[i103-1][3]=v[186]+v[172]*v[206];
 gpost[i103-1][4]=2e0*v[173]*v[180];
 gpost[i103-1][5]=v[186]+v[175]*v[206];
};/* end for */
npost[0][0]=v[119];
npost[1][0]=v[121];
npost[2][0]=v[123];
npost[3][0]=v[125];
npost[0][1]=v[120];
npost[1][1]=v[122];
npost[2][1]=v[124];
npost[3][1]=v[126];
npost[0][2]=v[119];
npost[1][2]=v[121];
npost[2][2]=v[123];
npost[3][2]=v[125];
npost[0][3]=v[120];
npost[1][3]=v[122];
npost[2][3]=v[124];
npost[3][3]=v[126];
};
