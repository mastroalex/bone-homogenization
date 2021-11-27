%% first test
A=imread('ESA29-99-L3-Byte.0681.png')
imshow(A)
B=imadjust(A)
figure()
imshow(B)
%vedere indice di contrasto per quale immagine scegliere
C=imbinarize(B,0.6)
figure()
% vedere indice per la binarizzazione
imshow(C)
D=imcomplement(C)

figure()
imshow(D)
