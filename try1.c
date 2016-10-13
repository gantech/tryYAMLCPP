#include "try1.h"

namespace YAML {
  
  bool convert<blah::Velocity>::decode(const Node& node, blah::Velocity& v) {
    if(!node.IsSequence() || node.size() != 3) {
      return false;
    }
    
    v.ux_ = node[0].as<double>();
    v.uy_ = node[1].as<double>();
    if ( node.size() > 2 )
      v.uz_ = node[2].as<double>();

    return true;
  }

  bool convert<blah::Turbine>::decode(const Node& node, blah::Turbine& t) {
    
    blah::get_if_present(node, "procNo", t.procNo, t.procNo);
    blah::get_if_present(node, "TurbinePos", t.TurbinePos, t.TurbinePos);
    blah::get_if_present(node, "restartFileName", t.restartFileName, t.restartFileName);
    blah::get_if_present(node, "FASTInputFileName", t.FASTInputFileName, t.FASTInputFileName);
    blah::get_if_present(node, "numScOutputs", t.numScOutputs, t.numScOutputs);
    blah::get_if_present(node, "numScInputs", t.numScInputs, t.numScInputs);
    blah::get_if_present(node, "TurbID", t.TurbID, t.TurbID);

    /* t.procNo = node["procNo"].as<int>(); */
    /* t.TurbinePos = node["TurbinePos"].as<std::vector<double> >(); */
    /* t.restartFileName = node["restartFileName"].as<std::string>(); */
    /* t.FASTInputFileName = node["FASTInputFileName"].as<std::string>(); */
    /* t.numScOutputs = node["numScOutputs"].as<int>(); */
    /* t.numScInputs = node["numScInputs"].as<int>(); */
    /* t.TurbID = node["TurbID"].as<int>(); */

    return true;
  }

}


namespace blah {

  const YAML::Node
    expect_type(const YAML::Node& node, const std::string& key, YAML::NodeType::value type, bool optional)
  {
    static std::string types[] = {"Null", "Scalar", "Sequence", "Map"};
    const YAML::Node value = node[key];
    return value;
  }
  
  const YAML::Node
    expect_null(const YAML::Node& node, const std::string& key, bool optional)
  {
    return expect_type(node, key, YAML::NodeType::Null, optional);
  }
  const YAML::Node
    expect_scalar(const YAML::Node& node, const std::string& key, bool optional)
  {
    return expect_type(node, key, YAML::NodeType::Scalar, optional);
  }
  const YAML::Node
    expect_sequence(const YAML::Node& node, const std::string& key, bool optional)
  {
    return expect_type(node, key, YAML::NodeType::Sequence, optional);
  }
  const YAML::Node
    expect_map(const YAML::Node& node, const std::string& key, bool optional)
  {
    return expect_type(node, key, YAML::NodeType::Map, optional);
  }
  
  void loadTurbines(YAML::Node & node) {

    const YAML::Node y_specs = expect_sequence(node, "TurbineData", false);
    if (y_specs) {
      const int nTurbines = y_specs.size() ;
      std::cout << "nTurbines = " << nTurbines << std::endl ;

      /* Doesn't work
      /* for (size_t ispec = 0; ispec < y_specs.size(); ++ispec) { */
      /* 	YAML::Node & ti = y_specs[ispec] ; */
      /* 	Turbine t =  ti.as<Turbine>() ; */
      /* 	t.printData(); */
      /* } */

      for (YAML::const_iterator ispec = y_specs.begin(); ispec != y_specs.end(); ++ispec) {
      	std::cout << "Working on " << ispec->first.as<std::string>() << std::endl ;
      	YAML::Node ti = ispec->second ;
      	Turbine t =  ti.as<Turbine>() ;
      	t.printData();
      }

    }
    
  }  

} //namespace blah
