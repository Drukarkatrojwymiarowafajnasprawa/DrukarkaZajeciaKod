starea = round(sin(0)*400);
stareb = round(sin(0+2*pi/3)*400);
starec = round(sin(0+4*pi/3)*400);
ile = 0;
    
for t = 0:0.1:4*pi
    
    a = round(sin(t)*400);
    b = round(sin(t+2*pi/3)*400);
    c = round(sin(t+4*pi/3)*400);
    
    fprintf(drukarka, 'a %d b %d c %d\n', [a-starea,b-stareb,c-starec]);
    
    while(drukarka.BytesAvailable == 0)
        ;
    end
    while(drukarka.BytesAvailable > 0)
        fscanf(drukarka)
    end
%     
%     fprintf(drukarka, 'a -2000 b -2000 c -2000')
%     
%     while(drukarka.BytesAvailable == 0)
%         ;
%     end
%     while(drukarka.BytesAvailable > 0)
%         fscanf(drukarka)
%     end

starea = a;
stareb = b;
starec = c;
ile = ile + 1;
end