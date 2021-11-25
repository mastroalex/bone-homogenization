%%
clear all
file=dir('ESA*.png');
xlsfiles={file.name};
xlsfiles=sort(xlsfiles); %sort by name ascending

file1=imread(file(1).name);
imm=[zeros(numel(file1(1,:)),numel(file1(:,1)))];  
   
for i=1:length(file)
imm(:,:,i)=0;
end
imload=imm;
imbin=imm;
parfor i=1:length(file)
imload(:,:,i)=mat2gray(imread(xlsfiles{i}));
end
%% algoritmo ottimo contrasto
%% algoritmo soglia per bin

%% contrasto su best imm
%% filtraggio
%% binarization 
% non fare così ma riassegnare !!

parfor i=1:length(file)
imbin(:,:,i)=imbinarize(imload(:,:,i),0.7);
end
%%
figure()
volshow(imbin)
figure
%volshow(imbin,config) %generare il config dall'app e slavrlo
% quindi caricarlo a inizio scritp
