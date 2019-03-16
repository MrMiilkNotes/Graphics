#include "Recorder.h"

typename Recorder::record_t Recorder::records = {};

Recorder::Recorder()
{
}

void Recorder::record(std::string shape_, int idx, float x, float y)
{
	point_t p(x, y);
	if (Drawer::is_two_point_shape(shape_)) {
		if (idx == 1) {
			records[shape_].push_back(shape(1, p));
		}
		else if (idx == 2) {
			records[shape_].back().push_back(p);
		}
	}
}

Recorder::record_t Recorder::get_records()
{
	return records;
}

void Recorder::clear()
{
	records.clear();
}
