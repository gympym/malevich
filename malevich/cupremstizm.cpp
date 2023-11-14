#include <iostream>
#include <fstream>

struct Figure
{
	Figure(std::string fill) {
		m_fill = fill;
	}
	std::string m_fill = "black";
};
struct Rect:Figure
{
	Rect(double x, double y, double rotate, double width, double height, std::string fill): m_x(x), m_y(y), m_rotate(rotate), m_width(width), m_height(height), Figure(fill)
	{}
	double m_x = 0;
	double m_y = 0;
	double m_rotate = 0;
	double m_width = 0;
	double m_height = 0;
};
std::ostream& operator<<(std::ostream& os, const Rect& r)
{
	return os << "<rect x=\"" << r.m_x << "\" y=\"" << r.m_y << "\" transform=\"rotate(" << r.m_rotate << " 0 0)" << "\" width=\"" << r.m_width << "\" height=\"" << r.m_height << "\" fill=\"" << r.m_fill << "\"/>" << "\n";
}

int main()
{
	Rect r1(0, 0, 0, 155, 155, "#d8cecc");
	Rect r2(55, -17, 18, 20, 126, "#595a79");
	Rect r3(60, 50, -8, 10, 79, "#bf4b38");
	Rect r4(0, 30, 2, 150, 25, "#2e2b36");
	Rect r5(31, 50, -23, 31, 25, "#31353e");
	Rect r6(35, 80, -4, 50, 9, "#2e2b36");
	Rect r7(59, 93, -6, 54, 14, "#31334a");
	Rect r8(59, 109, -7, 24, 3, "#2a409a");
	Rect r9(69, 35, -9, 3, 101, "#2c418c");
	Rect r10(19, 30, -50, 3, 100, "#dda52c");
	Rect r11(40, -37, 45, 2, 24, "#dda52c");

	std::ofstream svg("suprematism.svg");
	if (svg.is_open()) {
		svg << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"400\" height=\"400\" viewBox=\"0 0 124 124\" fill=\"none\">" << std::endl;
		svg << r1;
		svg << r2;
		svg << r3;
		svg << r4;
		svg << r5;
		svg << r6;
		svg << r7;
		svg << r8;
		svg << r9;
		svg << r10;
		svg << r11;

		svg << "</svg>" << std::endl;
		svg.close();
	}
	//std::cout << r1;
	//std::cout << r2;
	return 0;
}