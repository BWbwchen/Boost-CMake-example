#include <boost/geometry.hpp>
#include <boost/geometry/index/rtree.hpp>

#include <random>
#include <vector>

#include <exception>
#include <iostream>

namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;
using coordinate_type = int;
const size_t dimension = 2;
using coordinate_system_type = bg::cs::cartesian;
using point_t =
    bg::model::point<coordinate_type, dimension, coordinate_system_type>;
using box_t = bg::model::box<point_t>;
using rtree_box = bg::index::rtree<box_t, bg::index::linear<10>>;

std::string to_string(const box_t &box) {
  std::string ret = "";
  ret += "From (" + std::to_string(box.min_corner().get<0>()) + ", " +
         std::to_string(box.min_corner().get<1>()) + ") ";
  ret += "To (" + std::to_string(box.max_corner().get<0>()) + ", " +
         std::to_string(box.max_corner().get<1>()) + ")";
  return ret;
}

int main() {

  std::mt19937_64 random_engine;
  std::uniform_int_distribution<coordinate_type> random_distribution_coordinate(
      0, 100);
  auto random_box = [&]() -> box_t {
    std::vector<int> x(2, 0);
    std::vector<int> y(2, 0);
    for (auto &v : x) {
      v = random_distribution_coordinate(random_engine);
    }
    for (auto &v : y) {
      v = random_distribution_coordinate(random_engine);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    return box_t(point_t(x[0], y[0]), point_t(x[1], y[1]));
  };

  rtree_box r;

  box_t bb;
  for (auto n = 0; n < 10; ++n) {
    auto to_insert = random_box();
    r.insert(to_insert);
    std::cout << to_string(to_insert) << std::endl;
    if (n == 5) {
      bb = to_insert;
    }
  }

  bb = box_t(point_t(25, 25), point_t(75, 75));
  std::cout << to_string(bb) << " in r-tree?" << std::endl;

  std::vector<box_t> result;

  std::cout << bgi::query(r, bgi::intersects(bb), std::back_inserter(result))
            << std::endl;

  for (auto &v : result) {
    std::cout << to_string(v) << std::endl;
  }

  return 0;
}
