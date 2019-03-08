//
// 1. Create the spline
//nx = 7;
//ny = 15;
//data = read("/media/D/Qt/teplovay linza/saveFile.csv", -1, 40); 
//y = linspace(%pi/2,4*%pi,ny); 
//z = cos(x')*cos(y);
//C = splin2d(x, y, z, "periodic");
//
// 2. Evaluate the spline on a grid
//mx = 50;
//my = 20;
//xx = linspace(%pi,1.5*%pi,mx);
//yy = linspace(%pi,2*%pi,my);
//[XX,YY] = ndgrid(xx,yy);
//zz = interp2d(XX,YY, x, y, C);
//
// 3. Plot the interpolated values
//scf();
//plot3d(xx, yy, zz)
z = read("/media/D/Qt/teplovay linza/saveFile.csv", -1, 40)-300;
y = linspace(0,4,40);
x = linspace(0,20,200);
C = splin2d(x, y, z, "not_a_knot");
yy = linspace(0,4,400);
xx = linspace(0,20,200);
[XX,YY] = ndgrid(xx,yy);
zz = interp2d(XX,YY, x, y, C);
scf();
plot3d(xx, yy, zz)
