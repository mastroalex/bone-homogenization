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
## Full code

Open `bone_imm_processing.m` (matlab file)[https://github.com/mastroalex/bone-homogenization/blob/main/image_processing/bone_imm_processing.m].

## Mathematica

It's also possibile to do volume rendering in Mathematica and mesh it.

```mathematica
files = FileNames["*.png", "C:\\Users\\bigba\\OneDrive\\Documenti\\GitHub\\bone\homogenization\\image_processing\\file_raw\\slices600-699\\"];
DDD = Table[Import[files[[n]]], {n, 1, 900}];
Do[DDD[[n]] = Binarize[ColorConvert[DDD[[n]], "Grayscale"], 0.8], {n, 1, 900}];
A = Image3D[DDD]
res = Timing[MESH = ImageMesh[A]];
Export[FileNameJoin[{NotebookDirectory[], "mesh.png"}], MESH]
res[[1]]/60 (* to obtain meshing time*)
```

## More info 

[More info on my website..](https://alessandromastrofini.it/2021/11/26/image-volumetric-bone/)
