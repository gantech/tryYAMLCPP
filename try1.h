#ifndef try1
#define try1


// yaml for parsing..
#include <yaml-cpp/yaml.h>
#include <iostream>

namespace blah {
  // our data types
  struct Velocity {
    double ux_, uy_, uz_;
  Velocity()
  : ux_(0.0), uy_(0.0), uz_(0.0)
    {}
    
    /* // equality comparison. doesn't modify object. therefore const. */
    /* bool operator==(const Velocity& a) const */
    /* { */
    /*   return ((ux_ == a.ux_) && (uy_ == a.uy_) && (uz_ == a.uz_)) ; */
    /* } */
  };
  
  
  struct Turbine {
    int procNo;
    std::vector<double>  TurbinePos;
    int numScOutputs;
    int numScInputs;
    std::string restartFileName;
    std::string FASTInputFileName;
    int TurbID;
    
    
    Turbine() {
      TurbinePos.resize(3);
    }
    
    void printData() {
      std::cout << "procNo = " << procNo << std::endl;
      std::cout << "TurbinePos = " << TurbinePos[0] << " " << TurbinePos[1] << " " << TurbinePos[2] << std::endl ;
      std::cout << "numScOutputs = " << numScOutputs << std::endl;
      std::cout << "numScInputs = " << numScInputs << std::endl;
      std::cout << "restartFileName = " << restartFileName << std::endl;
      std::cout << "FASTInputFileName = " << FASTInputFileName << std::endl ;
      std::cout << "TurbID = " << TurbID << std::endl;
    }
  };


/// Set @param result if the @param key is present in the @param node, else set it to the given default value
template<typename T>
void get_if_present(const YAML::Node & node, const std::string& key, T& result, const T& default_if_not_present = T())
{
  if (node[key]) {
    const YAML::Node value = node[key];
    result = value.as<T>();
  }
  else {
    result = default_if_not_present;
  }
}


/// these can be used to check and ensure a type of yaml node is as expected
const YAML::Node
expect_type(const YAML::Node& node, const std::string& key, YAML::NodeType::value type, bool optional=false);

const YAML::Node
expect_null(const YAML::Node& node, const std::string& key, bool optional=false);

const YAML::Node
expect_scalar(const YAML::Node& node, const std::string& key, bool optional=false);

const YAML::Node
expect_sequence(const YAML::Node& node, const std::string& key, bool optional=false);

const YAML::Node
expect_map(const YAML::Node& node, const std::string& key, bool optional=false);

void loadTurbines(YAML::Node & node) ;

}

namespace YAML {
  
  template<> struct convert<blah::Velocity> {
    static bool decode(const Node& node, blah::Velocity& v) ;
  };
  
  template<> struct convert<blah::Turbine> {
    static bool decode(const Node& node, blah::Turbine& t) ;
  };
  
}


#endif
