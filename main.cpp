#include <algorithm>
#include <iostream>
#include <nav_file.h>


int main() {
	try {
		nav_mesh::nav_file map_nav(".nav");

		nav_mesh::vec3_t start_point = { -1917, 11169, -127 };
		nav_mesh::vec3_t end_point = { 1276, 1775, -156 };
		
		auto path_opt = map_nav.find_path(start_point, end_point);

		if (path_opt) {
			const auto& path = *path_opt;
			for (const auto& point : path) {
				std::cout << "find_path point: (" << point.x << ", " << point.y << ", " << point.z << ")\n";
			}
		} else {
			std::cout << "No path found.\n";
		}

		auto path_opt_detail = map_nav.find_path_detailed(start_point, end_point);

		if (path_opt_detail) {
			const auto& path_dt = *path_opt_detail;
			for (const auto& point_dt : path_dt) {
				std::cout << "find_path_detail point: (" << point_dt.pos.x << ", " << point_dt.pos.y << ", " << point_dt.pos.z << ")\n";
			}
		}


	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
