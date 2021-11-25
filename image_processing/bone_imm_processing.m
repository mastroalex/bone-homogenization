%%
%%
clear all
selpath = uigetdir; %select image processing folder
folderpath=strcat(selpath,'/file_raw/slice*');
folderlist=dir(folderpath);
%%
tic
for k=1:length(folderlist)
    temp_list=dir(strcat(selpath,'/file_raw/',folderlist(k).name,'/ESA*.png'));
     if k==1
         file_list=append(strcat(selpath,'/file_raw/',folderlist(k).name,'/'),{temp_list.name});
     else
    file_list=[file_list, append(strcat(selpath,'/file_raw/',folderlist(k).name,'/'),{temp_list.name})];
    end
end

xlsfiles=sort(file_list); %sort by name ascending

file1=imread(xlsfiles{1});
imm=[zeros(numel(file1(1,:)),numel(file1(:,1)))];  
   
for i=1:length(xlsfiles)
imm(:,:,i)=0;
end
imload=imm;
parfor i=1:length(xlsfiles)
imload(:,:,i)=mat2gray(imread(xlsfiles{i}));
end 
toc
%% video w
video=VideoWriter(strcat(selpath,'/flow.mp4'),'MPEG-4'); %default 30 fps
open(video); %open the file for writing
tic
for i=1:length(imload(1,1,:))
    writeVideo(video,imload(:,:,i));
    i
end
close(video);
toc
%% contrast index

for k=1:length(imload(1,1,:))
[CI1(k),CI2(k),CI3(k)]=my_contrast_index(imload(:,:,k));
mu(k)=mean2(imload(:,:,k));
subplot(4,1,1);
plot(CI1(1:k));
ylabel('CI1');
subplot(4,1,2);
plot(CI2(1:k));
ylabel('CI2');
subplot(4,1,3);
plot(CI3(1:k));
ylabel('CI3');
subplot(4,1,4);
imhist(imload(:,:,k)); hold on;
line([mu(k) mu(k)],[0 max(imhist(imload(:,:,k)))],'color','r','linewidth',2);
drawnow;
k
end
best_contrast_index=find(CI2==max(CI2));
%%
ima=imload(:,:,best_contrast_index);
m=quantile(ima(:),0.10);
M=quantile(ima(:),0.96);
%A=imadjust(ima,stretchlim(ima))
%%
A=imadjust(ima,[m M],[0 1],2);
figure;
imshowpair(imload(:,:,best_contrast_index),A,'montage')
[CI1,CI2,CI3]=my_contrast_index(imload(:,:,best_contrast_index))
[CI1,CI2,CI3]=my_contrast_index(A)
%% test best contrast
clear CII2 row col val val_g gamma m M MAT val_g val_g_i
tic
gamma=1.2:0.2:2;
m=1:2:40;
M=97:1:99;
CII2=zeros(m(end),M(end),10*gamma(end));
for i=1:length(m)
    for j=1:length(M)
        for k=1:length(gamma)
    ima_c=imadjust(ima,[m(i)/100 M(j)/100],[0 1],gamma(k));
    CII2(m(i),M(j),k)=std(ima_c(:))/std(ima(:));
        end
    end
end
for k=1:length(gamma)
    MAT=CII2(:,:,k);
    [row(k),col(k)]=find(MAT==max(max(MAT)));
end 

for k=1:length(gamma)
val_g(k)=CII2(row(k),col(k),k);
end

val_g_i=find(val_g==(max(val_g)));
val1=row(val_g_i)
val2=col(val_g_i)
val3=gamma(val_g_i)

contrastim=imadjust(ima,[row(val_g_i)/100 col(val_g_i)/100],[0 1],gamma(val_g_i));
figure;
imshowpair(imload(:,:,best_contrast_index),contrastim,'montage')
mex=strcat('m=',string(val1),', M=',string(val2),', gamma=',string(val3));
title(mex)
toc
%%  contrasto su best imm
tic
imcontr=imm;
for k=1:length(imm(1,1,:))
imcontr(:,:,k)=imadjust(imload(:,:,k),[row(val_g_i)/100 col(val_g_i)/100],[0 1],gamma(val_g_i));
k
end
toc
%% filtraggio
   
L=6;
mask1=fspecial('average',L);
mask2=fspecial('gaussian',L,(L-1)/6);
ima_f1=imfilter(ima,mask1);
figure;
imshowpair(ima,ima_f1,'montage')
ima_f2=imfilter(ima,mask2);
figure;
imshowpair(ima,ima_f2,'montage')

%% filtering
tic
imfilt=imm;

for k=1:length(imm(1,1,:))
imfilt(:,:,k)=imfilter(imcontr(:,:,k),mask1);
k
end
toc

%% bin test

bintest=imbinarize(imfilt(:,:,best_contrast_index),0.46);
imshow(bintest);
%%
figure()
imshow(imfilt(:,:,best_contrast_index));
taglio=drawfreehand(gca);
%%
BW=createMask(taglio);
figure;
imshow(BW);
save BW
%% binarization
%insert imwrite in loop
tic
%imbin=imm;

for i=1:length(imbin(1,1,:))
imbin(:,:,i)=imbinarize(imfilt(:,:,i),0.46).*BW;
%imbin(:,:,i)=imbin(:,:,i).*BW;
imwrite(imbin(:,:,i),strcat(selpath,'\binarized\',string(i),'.png'))
i
end
save imbin
toc
%%
tic
figure()
volshow(imbin)
toc
%figure
%volshow(imbin,config) %generare il config dall'app e slavrlo
% quindi caricarlo a inizio scritp

%%

function [CI1,CI2,CI3]=my_contrast_index(I)
CI1=max(I(:))-min(I(:));
CI2=std(I(:));
CI3=(max(I(:))-min(I(:)))/(max(I(:))+min(I(:)));
end

%% rifai usando un contrasto molto esagerato e passa al binarize (solo su 1 imm per esempio) 