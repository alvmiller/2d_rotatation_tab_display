
// Image Processing in C
// Second Edition
// Dwayne Phillips

/*******************************************
*
* geometry(..
*
* This routine performs geometric
* transformations on the pixels in an
* image array. It performs basic
* displacement, stretching, and rotation.
*
* The basic equations are:
*
* new x = x.cos(a) + y.sin(a) + x_displace
* + x.x_stretch +x.y.x_cross
*
* new y = y.cos(a) - x.sin(a) + y_displace
* + y.y_stretch +x.y.y_cross
*
*******************************************/
geometry(the_image, out_image,
x_angle,
x_stretch, y_stretch,
x_displace, y_displace,
x_cross, y_cross,
bilinear,
rows,
cols)
float x_angle, x_stretch, y_stretch,
x_cross, y_cross;
int bilinear;
long cols, rows;
short **the_image,
**out_image,
x_displace, y_displace;
{
double cosa, sina, radian_angle, tmpx, tmpy;
float fi, fj, x_div, y_div, x_num, y_num;
int i, j, new_i, new_j;
/******************************
*
* Load the terms array with
* the correct parameters.
*
*******************************/
/* the following magic number is from
180 degrees divided by pi */
radian_angle = x_angle/57.29577951;
cosa = cos(radian_angle);
sina = sin(radian_angle);
/************************************
*
* NOTE: You divide by the
* stretching factors. Therefore, if
* they are zero, you divide by 1.
* You do this with the x_div y_div
* variables. You also need a
* numerator term to create a zero
* product. You do this with the
* x_num and y_num variables.
*
*************************************/
if(x_stretch < 0.00001){
x_div = 1.0;
x_num = 0.0;
}
else{
x_div = x_stretch;
x_num = 1.0;
}
if(y_stretch < 0.00001){
y_div = 1.0;
y_num = 0.0;
}
else{
y_div = y_stretch;
y_num = 1.0;
}
/**************************
*
* Loop over image array
*
**************************/
printf("\n");
for(i=0; i<rows; i++){
if( (i%10) == 0) printf("%d ", i);
for(j=0; j<cols; j++){
fi = i;
fj = j;
tmpx = (double)(j)*cosa +
(double)(i)*sina +
(double)(x_displace) +
(double)(x_num*fj/x_div) +
(double)(x_cross*i*j);
tmpy = (double)(i)*cosa -
(double)(j)*sina +
(double)(y_displace) +
(double)(y_num*fi/y_div) +
(double)(y_cross*i*j);
if(x_stretch != 0.0)
tmpx = tmpx - (double)(fj*cosa + fi*sina);
if(y_stretch != 0.0)
tmpy = tmpy - (double)(fi*cosa - fj*sina);
new_j = tmpx;
new_i = tmpy;
if(bilinear == 0){
if(new_j < 0 ||
new_j >= cols ||
new_i < 0 ||
new_i >= rows)
out_image[i][j] = FILL;
else
out_image[i][j] =
the_image[new_i][new_j];
} /* ends if bilinear */
else{
out_image[i][j] =
bilinear_interpolate(the_image,
tmpx, tmpy,
rows, cols);
} /* ends bilinear if */
} /* ends loop over j */
} /* ends loop over i */
} /* ends geometry */
/*******************************************
*
* arotate(..
*
* This routine performs rotation about
* any point m,n.
*
* The basic equations are:
*
* new x = x.cos(a) - y.sin(a)
* -m.cos(a) + m + n.sin(a)
*
* new y = y.cos(a) + x.sin(a)
* -m.sin(a) - n.cos(a) + n
*
*******************************************/
arotate(the_image, out_image,
angle,
m, n, bilinear,
rows, cols)
float angle;
int bilinear;
long cols, rows;
short **the_image,
**out_image,
m, n;
{
double cosa, sina, radian_angle, tmpx, tmpy;
int i, j, new_i, new_j;
/* the following magic number is from
180 degrees divided by pi */
radian_angle = angle/57.29577951;
cosa = cos(radian_angle);
sina = sin(radian_angle);
/**************************
*
* Loop over image array
*
**************************/
printf("\n");
for(i=0; i<rows; i++){
if( (i%10) == 0) printf("%d ", i);
for(j=0; j<cols; j++){
/******************************************
*
* new x = x.cos(a) - y.sin(a)
* -m.cos(a) + m + n.sin(a)
*
* new y = y.cos(a) + x.sin(a)
* -m.sin(a) - n.cos(a) + n
*
*******************************************/
tmpx = (double)(j)*cosa -
(double)(i)*sina -
(double)(m)*cosa +
(double)(m) +
(double)(n)*sina;
tmpy = (double)(i)*cosa +
(double)(j)*sina -
(double)(m)*sina -
(double)(n)*cosa +
(double)(n);
new_j = tmpx;
new_i = tmpy;
if(bilinear == 0){
if(new_j < 0 ||
new_j >= cols ||
new_i < 0 ||
new_i >= rows)
out_image[i][j] = FILL;
else
out_image[i][j] =
the_image[new_i][new_j];
} /* ends if bilinear */
else{
out_image[i][j] =
bilinear_interpolate(the_image,
tmpx, tmpy,
rows, cols);
} /* ends bilinear if */
} /* ends loop over j */
} /* ends loop over i */
} /* ends arotate */
