%imm=imread('mesh_100.png');
%imm=imread('risorsa.png');
imm=imread('test_fisico.png');
imm2=im2gray(imm);
immbin=imbinarize(imm2);
figure;
imshow(immbin)
% COMPLETA ISTRUZIONE
%%
imdistline(gca);
pause();

rmin=input('Minimum radius: '); %95
rmax=input('Maximum radius: ');% 360
%%
close all
[centers,radii,metric] = imfindcircles(immbin,[rmin,rmax],'ObjectPolarity','bright','Sensitivity',0.94);
figure();imshow(immbin);
hold on; 
viscircles(centers, radii,'EdgeColor','b');
hold on;
%text(centers(:,1),centers(:,2),num2str(metric));
%%
clear raggi centri
for i=1:length(centers(:,1))
centri(i,2)=length(imm(:,2))-centers(i,2);
centri(i,1)=centers(i,1);
end
centri=round((centri.*(length(imm(:,2))/1000))./length(imm(:,2)),2);
raggi=round(radii.*(length(imm(:,2))/1000)./length(imm(:,2)),2);
save('radii.mat','raggi');
save('centers.mat','centri');