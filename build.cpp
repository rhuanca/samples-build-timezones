#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/date_time/local_time/tz_database.hpp"
#include "boost/date_time/local_time/local_time_types.hpp"

#include <iostream>
#include <sstream>

int main() {

  using namespace boost::local_time;
 
  tz_database tz_db;
  tz_db.load_from_file("./date_time_zonespec.csv");
  std::cout << "[" << std::endl;
  std::vector<std::string> myvector = tz_db.region_list(); 
  for(int i=0; i<myvector.size(); i++) {
    time_zone_ptr tz = tz_db.time_zone_from_region(myvector.at(i));
    std::cout << "{" << std::endl;
    std::cout << "\"tz\":\""  << myvector.at(i) << "\"," << std::endl;
    
    std::cout << "\"posix\":\""  << tz->to_posix_string() << "\"" << std::endl;
    std::cout << "}" << std::endl;
    
    if(i<myvector.size()-1) {
      std::cout << "," << std::endl;
    }
  } 
  std::cout << "]" << std::endl;
}
