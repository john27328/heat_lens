//
// 1. Create the spline
nx0 = 7;
ny0 = 15;
x0 = linspace(0,2*%pi,nx0); 
y0 = linspace(%pi/2,4*%pi,ny0); 
z0 = cos(x0')*cos(y0);
C0 = splin2d(x0, y0, z0, "periodic");
//
// 2. Evaluate the spline on a grid
mx0 = 50;
my0 = 20;
xx0 = linspace(0,2*%pi,mx0);
yy0 = linspace(%pi/2,4*%pi,my0);
[XX0,YY0] = ndgrid(xx0,yy0);
zz0 = interp2d(XX0,YY0, x0, y0, C0);
//
// 3. Plot the interpolated values
scf();
plot3d(xx0, yy0, zz0)
scf();
plot3d(x0, y0, z0)
