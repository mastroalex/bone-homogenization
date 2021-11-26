# Image processing section

![schema](https://github.com/mastroalex/bone-homogenization/blob/main/image_processing/images/Risorsa%203.png)

## To create 3D volume rendering

Filter and binarize image.
Than render 3D with the image into one 3-dimensional matrix `I[x,y,z]=I[imm(i),z]`.

Use `VolumeViewr`toolbox and:
```matlab
figure()
volshow(imbin,config)
```

[More info..](https://alessandromastrofini.it/2021/11/26/image-volumetric-bone/)
