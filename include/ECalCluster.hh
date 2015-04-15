#include "EVENT/Cluster.h"
#include <EVENT/CalorimeterHit.h>

class TH2;
class TF1;
class TH2D;
class TCanvas;
class TMarker;

class ECalCluster
{
  
public:
  ECalCluster();
  ECalCluster(EVENT::Cluster *);

  void SetLCIOCluster(EVENT::Cluster *);
  void Analyze();
  void Reset();

  double Tmin() const {return t_min;};
  double Tmax() const {return t_max;};

  double Emin() const {return E_min;};
  double Emax() const {return E_max;};
  int Size() const {return size;};
  double GetX() const {return x;};
  double GetY() const {return y;};
  double GetZ() const {return z;};

  ECalCluster operator=(const ECalCluster);
  //  void DrawCluster();
  //  void DrawCluster(ECalCluster); // Draw two cluster hits and their centers
  void Reset_clust_Hist(); // Just clears the histogram
  
  //
  void InitHistCanvas();
  void Fill_dE_dt(TH2*);

  //========== Return the CalorimeterHit (i) of the cluster
  EVENT::CalorimeterHit* GetHit(int ind) const { return hits_vec[ind]; };

  //===== This method returns shower Moment w.r.t. the line "y = a + b*x" =====
  double GetShowerMoment(double a, double b) const;
  
private:
  EVENT::CalorimeterHitVec hits_vec;
  EVENT::Cluster *LCIO_clust;

  bool Analyzed;
  double t_min, t_max; // times of blocks having lowest and highest time in a cluster
  
  double E_min, E_max; // Lowest and highest energies of blocks in the cluster
  int size; // number of blocks in the cluster
  
  double x, y, z; // x, y and z coordinates of the cluster
  double E;
  // static TH2D h_clust1("h_clust1", "", 42, -283.762, 368.81772, 10, -96.62689, 96.2 );
  // static TCanvas c1("c1", "", 750, 750);
  // static TMarker mark1;

  // A histogram that will depict cluster hit blocks
  static TH2D h_clust1;
  static TCanvas c2;
  static TMarker mark1;
  static TF1 f_lin1;
  
  // some indexes of blocks
  int ind_tmin, ind_tmax;
  int ind_Emin, ind_Emax;
};
