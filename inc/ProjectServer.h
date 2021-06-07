#pragma once
#include <vector>

#include "SteelData.h"
#include "zBeamSeg.h"
#include "zColumnSeg.h"

template <typename T>
class Singleton
{
  struct object_creator
  {
    object_creator()
    {
      Singleton<T> :: instance();
    }
    inline void do_nothing() const {};
  };
  static object_creator create_object;

public:
  typedef T object_type;
  static T & instance()
  {
    static T obj;
    create_object.do_nothing();
    return obj;
  }
};
template<typename T> typename Singleton <T>::object_creator Singleton <T> :: create_object;

class STEELDATA_API ProjectServer
{
public:
  static ProjectServer *getInctance()
  {
    if (!mdata) mdata = new ProjectServer();
    return mdata;
  }
  static void Delete();


  std::vector<zBeamSeg> beamSegs;
  std::vector<zColumnSeg> colSegs;

private:
  static ProjectServer *mdata;
  ProjectServer();
  ~ProjectServer();

};
