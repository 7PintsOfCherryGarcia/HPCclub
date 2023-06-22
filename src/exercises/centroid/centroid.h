
//Compute euclidean distance between two dim dimensional pints.
float euc_s(float *p1, float *p2, unsigned int dim);

//Compute the centroid of N dim dimensional points
float *centroid(float *m, unsigned int dim, unsigned int n);

//Compute all distances between N dim dimensional points and their centroid
float *s2center(float *m, unsigned int dim, unsigned int n);
