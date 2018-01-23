rr=0,gg=0,bb=0;
vid=webcam();
vid.resolution='320x240';
preview(vid);
img=snapshot(vid);
imshow(img);
[row col d]=size(img)
for i=[1:row];
    for j=[1:col];
        
         R=img(i,j,1);
         G=img(i,j,2);
         B=img(i,j,3);
         if((R>G)&&(R>B))
         rr=rr+1;
         end
         
         if((R<G)&&(G>B))
         gg=gg+1;
         end
         
         if((B>G)&&(R<B))
         bb=bb+1;
         end
    end
end
display(rr);
display(gg);
display(bb);


s=serial('COM6','Baudrate',9600);
fopen(s);

fwrite(s,rr);
fwrite(s,',');
fwrite(s,gg);
fwrite(s,',');
fwrite(s,bb);

fclose(s);

clear all;