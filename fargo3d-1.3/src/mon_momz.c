//<FLAGS>
//#define __GPU
//#define __NOPROTO
//<\FLAGS>

//<INCLUDES>
#include "fargo3d.h"
//<\INCLUDES>

void mon_momz_cpu () {

//<USER_DEFINED>
  INPUT(Density);
  INPUT(Vz);
  OUTPUT(Slope);
//<\USER_DEFINED>


//<EXTERNAL>
  real* dens = Density->field_cpu;
  real* vz   = Vz->field_cpu;
  real* mom  = Slope->field_cpu;
  int pitch  = Pitch_cpu;
  int stride = Stride_cpu;
  int size_x = Nx+2*NGHX;
  int size_y = Ny+2*NGHY;
  int size_z = Nz+2*NGHZ-1;
//<\EXTERNAL>

//<INTERNAL>
  int i;
  int j;
  int k;
  int ll;
//<\INTERNAL>

//<CONSTANT>
// real Syk(Nz+2*NGHZ);
// real InvVj(Ny+2*NGHY);
// real ymin(Ny+2*NGHY+1);
//<\CONSTANT>

//<MAIN_LOOP>

  i = j = k = 0;

#ifdef Z
  for (k=0; k<size_z; k++) {
#endif
#ifdef Y
    for (j=0; j<size_y; j++) {
#endif
#ifdef X
      for (i=0; i<size_x; i++ ) {
#endif
//<#>
	ll = l;
	mom[ll] = dens[ll]*.5*(vz[ll]+vz[lzp])*Vol(j,k);
#ifdef SPHERICAL
	mom[ll] *= ymed(j);
#endif
//<\#>
#ifdef X
      }
#endif
#ifdef Y
    }
#endif
#ifdef Z
  }
#endif
//<\MAIN_LOOP>
}
