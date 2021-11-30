%% parto dal volume e trovo i pori
L=2500;
rp=250/2;
%
AT=L^2;
APT=0.8*AT;
AP=pi*(rp^2);
N=APT/AP
%% parto dal numero di pori a trovo il volume di interesse
N=25
rp=250/2;
AP=pi*(rp^2);
APT=N*AP;
AT=APT/0.8;
L=sqrt(AT)

%% parto dal numero di pori a trovo il volume di interesse
N=11+(8/2)+(4/4)
rp=250/2;
AP=pi*(rp^2);
APT=N*AP;
AT=APT/0.8;
L=sqrt(AT)

%% parto dal volume e trovo i pori
L=2000;
rp=250;
%
AT=L^2;
APT=0.8*AT;
AP=pi*(rp^2);
N=APT/AP

%% calcolo fraction
N=11+(8/2)+(4/4)
rp=250/2;
AP=pi*(rp^2);
APT=N*AP;
AT=APT/0.8;
L=sqrt(AT)

%% parto dal volume 
L=2500;
rp=250/2;
%
VT=L^2*rp;
VPT=0.8*VT;
VP=pi*(rp^3)*(4/3);
N=VPT/VP

%% parto dal numero di pori a trovo il volume di interesse
N=25
rp=250/2;
VP=(4/3)*pi*(rp^3);
VPT=N*VP;
VT=VPT/0.8;

%% parto dal numero di pori a trovo il volume di interesse
N=5^3
rp=250/2;
VP=(4/3)*pi*(rp^3);
VPT=N*VP;
VT=VPT/0.8;
VT=VPT/0.7;
L=VT^(1/3)